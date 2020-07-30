1   #ifndef OTSU_THRESHOLD_H
2   #define OTSU_THRESHOLD_H
3   
4   #include "hls_math.h"
5   #include "hls_video.h"
6   
7   namespace hls {
8   
9   template<int SRC_T, int DST_T,int ROW, int COL>
10  void Threshold(
11      Mat<ROW, COL, SRC_T>    &_src,
12      Mat<ROW, COL, DST_T>    &_dst,
13      ap_uint<8> &threshold)
14  {
15      const int NUM_STATES=4;
16      Window<1,NUM_STATES,ap_uint<8> > addr_win;
17  
18      ap_uint<BitWidth<ROW*COL>::Value> hist_out[256];
19      Window<1,NUM_STATES,ap_uint<BitWidth<ROW*COL>::Value> > hist_win;
20  
21      ap_uint<BitWidth<ROW*COL>::Value> hist;
22      ap_uint<8> addr;
23      ap_uint<8> addr_last;
24      ap_uint<BitWidth<ROW*COL>::Value> hist_last;
25      ap_uint<8> addr_flag;
26      ap_uint<BitWidth<ROW*COL>::Value> hist_flag;
27      ap_uint<8> addr_w;
28      ap_uint<BitWidth<ROW*COL>::Value> hist_w;
29  
30      ap_uint<BitWidth<ROW*COL>::Value> tmp=0;
31  
32      float pixel_probability[256];
33      for(int i=0;i<NUM_STATES;i++) {
34      #pragma HLS UNROLL
35          addr_win(0,i)=i;
36          hist_win(0,i)=0;
37      }
38  
39      for(int i=0;i<256;i++) {
40          hist_out[i]=0;
41          pixel_probability[i] = 0.0f;
42      }
43  
44      int cols=_src.cols;
45      int rows=_src.rows;
46      assert(rows<=ROW);
47      assert(cols<=COL);
48   loop_height: for(int i=0;i<rows;i++)
49      {
50      loop_width: for(int j=0;j<cols;j++)
51          {
52  #pragma HLS PIPELINE
53  #pragma HLS LOOP_FLATTEN OFF
54  #pragma HLS DEPENDENCE array inter false
55              ap_uint<4> flag=NUM_STATES;
56              HLS_TNAME(SRC_T) tempsrc=0;
57              HLS_TNAME(DST_T) tempdst=0;
58              _src.data_stream[0].read(tempsrc);
59              tempdst=tempsrc > threshold ? 255 : 0;
60              _dst.data_stream[0]<<tempdst;
61  
62              for (int m=0; m<NUM_STATES; m++) {
63                  if (tempsrc==addr_win(0,m)) {
64                      flag = m;
65                      break;
66                  }
67              }
68  
69              latency_region:{
70              #pragma HLS latency min=0 max=1
71              addr_last = addr_win(0,NUM_STATES-1);
72              hist_last = hist_win(0,NUM_STATES-1)+1;
73              for (int m=NUM_STATES-1; m>0; m--) {
74                  addr = addr_win(0,m-1);
75                  hist = hist_win(0,m-1);
76                  if (m==NUM_STATES/2) {
77                      addr_w = addr;
78                      if (m==flag+1) {
79                          hist_w = hist+1;
80                      } else {
81                          hist_w = hist;
82                      }
83                  }
84                  if (m==flag+1) {
85                      addr_flag = addr;
86                      hist_flag = hist+1;
87                      addr_win(0,m) = addr_flag;
88                      hist_win(0,m) = hist_flag;
89                  } else {
90                      addr_win(0,m) = addr;
91                      hist_win(0,m) = hist;
92                  }
93              }
94              if (flag==NUM_STATES) {
95                  hist_win(0,0) = hist_out[tempsrc]+1;
96                  addr_win(0,0) = tempsrc;
97              } else if (flag==NUM_STATES-1) {
98                  addr_win(0,0) = addr_last;
99                  hist_win(0,0) = hist_last;
100             } else if (flag>=NUM_STATES/2) {
101                 addr_win(0,0) = addr_flag;
102                 hist_win(0,0) = hist_flag;
103             } else {
104                 addr_win(0,0) = addr_w;
105                 hist_win(0,0) = hist_w;
106             }
107             hist_out[addr_w] = hist_w;
108             }
109         }
110     }
111 
112     for (int m=0; m<NUM_STATES/2; m++) {
113     #pragma HLS PIPELINE
114         hist_out[addr_win(0,m)]=hist_win(0,m);
115     }
116 
117     int         front_pixel_count;          //前景图像像素个数
118     int         back_pixel_count;           //背景图像像素个数
119     float       front_pixel_probability;    //前景图像像素出现的概率
120     float       back_pixel_probability;     //背景图像像素出现的概率
121     int         front_gray_count;           //前景灰度总和
122     int         back_gray_count;            //背景灰度总和
123     int         total_gray;                 //整幅图像灰度总和
124     float       front_gray_average;         //前景平均灰度
125     float       back_gray_average;          //背景平均灰度
126     float       total_gray_average;         //整幅图像的平均灰度
127     int         threshold_tmp;              //临时阈值
128     float       interclass_variance_tmp;    //临时类间方差
129     float       interclass_variance_max;    //最大类间方差
130     for(threshold_tmp = 0; threshold_tmp < 256; threshold_tmp++){
131 
132         front_pixel_count = 0;
133         back_pixel_count = 0;
134         front_pixel_probability = 0;
135         back_pixel_probability = 0;
136         front_gray_count = 0;
137         back_gray_count = 0;
138         front_gray_average = 0;
139         back_gray_average = 0;
140         total_gray_average = 0;
141 
142         for(int j = 0; j < 256; j++){
143             //前景部分
144             if(j <= threshold_tmp){
145                 //以threshold_tmp为阈值分类，计算前景图像像素出现的个数和灰度总和
146                 front_pixel_count += hist_out[j];
147                 front_gray_count += j * hist_out[j];
148             }
149             //背景部分
150             else{
151                 //以threshold_tmp为阈值分类，计算背景图像像素出现的个数和灰度总和
152                 back_pixel_count += hist_out[j];
153                 back_gray_count += j * hist_out[j];
154             }
155         }
156 
157         //前景图像像素出现的概率
158         front_pixel_probability = (float)front_pixel_count / (rows*cols);
159         //背景图像像素出现的概率
160         back_pixel_probability = (float)back_pixel_count / (rows*cols);
161         //整幅图像灰度总和
162         total_gray = front_gray_count + back_gray_count;
163         //前景平均灰度
164         front_gray_average = (float)front_gray_count / front_pixel_count;
165         //背景平均灰度
166         back_gray_average = (float)back_gray_count / back_pixel_count;
167         //整幅图像平均灰度
168         total_gray_average = (float)total_gray / (rows*cols);
169 
170         //计算类间方差
171         interclass_variance_tmp = front_pixel_probability * 
172                                   (front_gray_average - total_gray_average) * 
173                                   (front_gray_average - total_gray_average)
174                                 + back_pixel_probability * 
175                                   (back_gray_average - total_gray_average) * 
176                                   (back_gray_average - total_gray_average);
177         //找出最大类间方差以及对应的阈值
178         if (interclass_variance_tmp > interclass_variance_max){
179             interclass_variance_max = interclass_variance_tmp;
180             threshold = threshold_tmp;
181         }
182     }
183 }
184 
185 //otsu自适应二值化函数
186 static  ap_uint<8> threshold;
187 template<int SRC_T, int DST_T,int ROW, int COL>
188 void Otsu_threshold(
189         Mat<ROW, COL, SRC_T>    &_src,
190         Mat<ROW, COL, DST_T>    &_dst)
191     {
192     #pragma HLS INLINE
193         Threshold(_src, _dst, threshold);
194     }
195 }
196 
197 #define MAX_HEIGHT 800 //图像最大高度
198 #define MAX_WIDTH 1024 //图像最大宽度
199 typedef hls::stream<ap_axiu<24,1,1,1> > AXI_STREAM;
200 typedef hls::Mat<MAX_HEIGHT,MAX_WIDTH,HLS_8UC3> RGB_IMAGE;
201 typedef hls::Mat<MAX_HEIGHT,MAX_WIDTH,HLS_8UC1> GRAY_IMAGE;
202 
203 void ov5640_otsu_threshold(AXI_STREAM & INPUT_STREAM,
204                            AXI_STREAM & OUTPUT_STREAM,
205                            int rows,
206                            int cols
207 );
208 
209 #endif