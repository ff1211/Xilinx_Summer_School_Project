 #include "hls_opencv.h"
#include "otsu_threshold.h"

using namespace cv;

int otsu(IplImage* image)
{
	int width = image->width;
	int height = image->height;
	int pixel_count[256];

    int 		front_pixel_count;			//前景图像像素个数
    int 		back_pixel_count;			//背景图像像素个数
	float 		front_pixel_probability;	//前景图像像素出现的概率
	float 		back_pixel_probability;		//背景图像像素出现的概率
	int 		front_gray_count;			//前景灰度总和
	int 		back_gray_count;			//背景灰度总和
	int 		total_gray;					//整幅图像灰度总和
	float 		front_gray_average;			//前景平均灰度
	float 		back_gray_average;			//背景平均灰度
	float 		total_gray_average;			//整幅图像的平均灰度
	int 		threshold_tmp;				//临时阈值
	int 		threshold = 0;				//类间方差最大的阈值
	float 		interclass_variance_tmp; 	//临时类间方差
	float 		interclass_variance_max; 	//最大类间方差

	uchar* data = (uchar*)image->imageData;

	//初始化每个灰度级出现个数
	for(int i = 0; i < 256; i++){
		pixel_count[i] = 0;
	}

	//统计灰度级中每个像素在整幅图像中的个数
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			pixel_count[data[i * image->widthStep + j]]++;
		}
	}

	//经典otsu算法，得到前景和背景的分割
	//遍历灰度级[0，255]，计算出方差最大的灰度值为最佳阈值

	 for(threshold_tmp = 0; threshold_tmp < 256; threshold_tmp++){

		front_pixel_count = back_pixel_count = 0;
		front_pixel_probability = back_pixel_probability = 0;
		front_gray_count = back_gray_count = 0;
		front_gray_average = back_gray_average = total_gray_average = 0;

		for(int j = 0; j < 256; j++){
			//前景部分
			if(j <= threshold_tmp){
				//以threshold_tmp为阈值分类，计算前景图像像素出现的个数和灰度总和
				front_pixel_count += pixel_count[j];
				front_gray_count += j * pixel_count[j];
			}
			//背景部分
			else{
				//以threshold_tmp为阈值分类，计算背景图像像素出现的个数和灰度总和
				back_pixel_count += pixel_count[j];
				back_gray_count += j * pixel_count[j];
			}
		}

		//前景图像像素出现的概率
		front_pixel_probability = (float)front_pixel_count / (width*height);
		//背景图像像素出现的概率
		back_pixel_probability = (float)back_pixel_count / (width*height);
		//整幅图像灰度总和
		total_gray = front_gray_count + back_gray_count;
		//前景平均灰度
		front_gray_average = (float)front_gray_count / front_pixel_count;
		//背景平均灰度
		back_gray_average = (float)back_gray_count / back_pixel_count;
		//整幅图像平均灰度
		total_gray_average = (float)total_gray / (width*height);

		//计算类间方差
		interclass_variance_tmp = front_pixel_probability * (front_gray_average - total_gray_average) * (front_gray_average - total_gray_average)
								+ back_pixel_probability * (back_gray_average - total_gray_average) * (back_gray_average - total_gray_average);
		//找出最大类间方差以及对应的阈值
		if (interclass_variance_tmp > interclass_variance_max){
			interclass_variance_max = interclass_variance_tmp;
			threshold = threshold_tmp;
		}
	}
	//返回最佳阈值;
	return threshold;
}

int main(int argc, char* argv[])
{
	for (int i = 0; i< 2; i++){

		IplImage* src = cvLoadImage("lena.jpg");
		IplImage* src_lena = cvLoadImage("lena.jpg",0);
		IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
		IplImage* threshold_Image = cvCreateImage(cvGetSize(src), 8, 1);

		AXI_STREAM  src_axi;
		AXI_STREAM 	dst_axi;
		IplImage2AXIvideo(src, src_axi);
		ov5640_otsu_threshold(src_axi, dst_axi, src->height, src->width);
		AXIvideo2IplImage(dst_axi, dst);
		cvThreshold(src_lena, threshold_Image, 100, 255, CV_THRESH_BINARY);
		cvShowImage("lena", src_lena);
		cvShowImage("lena_threshold", threshold_Image);
		cvShowImage("lena_otsu_threshold", dst);

		if(i == 1)
			waitKey(0);

		cvReleaseImage(&src);
		cvReleaseImage(&dst);
	}
}
