# 1 "qrc_decoder/src/modules.c"
# 1 "qrc_decoder/src/modules.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 300 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "qrc_decoder/src/modules.c" 2
# 19 "qrc_decoder/src/modules.c"
# 1 "qrc_decoder/src/modules.h" 1
# 22 "qrc_decoder/src/modules.h"
# 1 "qrc_decoder/src/scanner.h" 1
# 22 "qrc_decoder/src/scanner.h"
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sys/types.h" 1 3
# 13 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sys/types.h" 3
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 10 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
# 10 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 277 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3
# 13 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 674 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 674 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3

# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 675 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 13 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 102 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
#pragma pack(pop)
# 277 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 370 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long size_t;
# 380 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ssize_t;
# 392 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long intptr_t;
# 405 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long uintptr_t;
# 418 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ptrdiff_t;
# 428 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;







typedef __time64_t time_t;
# 607 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;







const char *__mingw_get_crt_info (void);





#pragma pack(pop)
# 13 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sys/types.h" 2 3
# 43 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sys/types.h" 3
typedef unsigned short _ino_t;

typedef unsigned short ino_t;





typedef unsigned int _dev_t;

typedef unsigned int dev_t;
# 62 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sys/types.h" 3
__extension__
typedef long long _pid_t;



typedef _pid_t pid_t;





typedef unsigned short _mode_t;


typedef _mode_t mode_t;







typedef long _off_t;

typedef long off_t;






__extension__
typedef long long _off64_t;

__extension__
typedef long long off64_t;




typedef unsigned int useconds_t;




struct timespec {
  time_t tv_sec;
  long tv_nsec;
};

struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
};





__extension__
typedef unsigned long long _sigset_t;
# 23 "qrc_decoder/src/scanner.h" 2

typedef unsigned char byte;
typedef struct scanner scanner_t;



struct scanner
{
 byte* d;
 size_t s;
 int v;
 int c;
 int m;


 size_t i;
 size_t j;


 size_t block_cur;
 size_t block_dataw;


 byte block_data[163];
 size_t block_curbyte;
 size_t block_curbit;


 char verbosity;
};
# 23 "qrc_decoder/src/modules.h" 2

void next_bit (scanner_t* scanner);
void skip_bits(scanner_t* scanner, size_t n);

byte mask (byte m, size_t i, size_t j);
int mask_grade(scanner_t* scanner, byte m);
void mask_apply(scanner_t* scanner, byte m);

byte get_codeword(scanner_t* scanner);
void put_codeword(scanner_t* scanner, byte w);
# 20 "qrc_decoder/src/modules.c" 2

# 1 "qrc_decoder/src/data.h" 1
# 24 "qrc_decoder/src/data.h"
extern const unsigned char pattern_finder[7][7];



extern const unsigned char pattern_alignment[5][5];



extern const char* charset_alpha;


extern const unsigned char version_range[41];




extern const unsigned char code_to_ecl[4];
extern const unsigned char ecl_to_code[4];


extern const unsigned char lenbits[5][3];


extern const unsigned long bch_format_gen;
extern const unsigned long bch_format_mask;
extern const unsigned long bch_version_gen;
extern const unsigned long bch_version_mask;





extern const unsigned char pattern_alignment_pos[41][8];
# 67 "qrc_decoder/src/data.h"
extern const unsigned char block_sizes[164][6];
# 22 "qrc_decoder/src/modules.c" 2







static int is_data(scanner_t* scanner, byte i, byte j);

static int is_data(scanner_t* scanner, byte i, byte j)
{
 size_t s = scanner->s;


 if (i <= 8 && j <= 8) return 0;
 if (i <= 8 && j >= s-8) return 0;
 if (j <= 8 && i >= s-8) return 0;

 if (scanner->v >= 7)
 {

  if (i < 6 && j >= s-11) return 0;
  if (j < 6 && i >= s-11) return 0;
 }


 if (i == 6) return 0;
 if (j == 6) return 0;


 if (i <= 8 && j >= s-10) return 1;
 if (j <= 8 && i >= s-10) return 1;
 int coll_x = 0;
 for (const byte* a = pattern_alignment_pos[scanner->v]; *a && !coll_x; a++)
  coll_x = (*a-2 <= i && i <= *a+2);
 int coll_y = 0;
 for (a = pattern_alignment_pos[scanner->v]; *a && !coll_y; a++)
  coll_y = (*a-2 <= j && j <= *a+2);

 return !(coll_x && coll_y);
}

void next_bit(scanner_t* scanner)
{
 size_t i = scanner->i;
 size_t j = scanner->j;


 do
 {
  if ((j/2) % 2 == 0)
  {
   if (j % 2 == (j<6) || i >= scanner->s-1)
   {
    j--;
   }
   else
   {
    i++;
    j++;
   }
  }
  else
  {
   if (j % 2 == (j<6) || i <= 0)
   {
    j--;
   }
   else
   {
    i--;
    j++;
   }
  }
 }
 while (!is_data(scanner,i,j));

 scanner->i = i;
 scanner->j = j;
}

void skip_bits(scanner_t* scanner, size_t n)
{
 while (n--)
  next_bit(scanner);
}

byte mask(byte m, size_t i, size_t j)
{
 switch (m)
 {
 case 0: return 0 == (i+j)%2;
 case 1: return 0 == i%2;
 case 2: return 0 == j%3;
 case 3: return 0 == (i+j)%3;
 case 4: return 0 == (i/2+j/3)%2;
 case 5: return 0 == (i*j)%2 + (i*j)%3;
 case 6: return 0 == ((i*j)%2+(i*j)%3)%2;
 case 7: return 0 == ((i*j)%3+(i+j)%2)%2;
 default: return 0;
 }
}

byte mask_if_content(scanner_t* scanner, byte m, size_t i, size_t j)
{
 byte bit = (scanner->d[(i)*scanner->s + (j)]);
 if (is_data(scanner, i, j))
  bit ^= mask(m, i, j);
 return bit;
}

int mask_grade(scanner_t* scanner, byte m)
{


 size_t s = scanner->s;
 int score = 0;



 for (size_t i = 0; i < s; i++)
 {
  byte cur_color = 0;
  size_t n_cons = 0;
  for (size_t j = 0; j < s; j++)
  {
   byte bit = mask_if_content(scanner, m, i, j);

   if (bit != cur_color)
   {
    n_cons = 0;
    cur_color = bit;
   }
   else if (n_cons == 5)
    score += 3;
   else if (n_cons > 5)
    score++;
   n_cons++;
  }
 }

 for (size_t j = 0; j < s; j++)
 {
  byte cur_color = 0;
  size_t n_cons = 0;
  for (size_t i = 0; i < s; i++)
  {
   byte bit = mask_if_content(scanner, m, i, j);

   if (bit != cur_color)
   {
    n_cons = 0;
    cur_color = bit;
   }
   else if (n_cons == 5)
    score += 3;
   else if (n_cons > 5)
   n_cons++;
  }
 }



 for ( i = 0; i < s-1; i++)
  for ( j = 0; j < s-1; j++)
  {
   byte bit00 = mask_if_content(scanner, m, i+0, j+0);
   byte bit01 = mask_if_content(scanner, m, i+0, j+1);
   byte bit10 = mask_if_content(scanner, m, i+1, j+0);
   byte bit11 = mask_if_content(scanner, m, i+1, j+1);
   if (bit00 == bit01 && bit10 == bit11 && bit00 == bit10)
    score += 3;
  }



 for ( i = 0; i < s; i++)
  for ( j = 0; j < s-6; j++)
  {
   byte bit0 = mask_if_content(scanner, m, i, j+0);
   byte bit1 = mask_if_content(scanner, m, i, j+1);
   byte bit2 = mask_if_content(scanner, m, i, j+2);
   byte bit3 = mask_if_content(scanner, m, i, j+3);
   byte bit4 = mask_if_content(scanner, m, i, j+4);
   byte bit5 = mask_if_content(scanner, m, i, j+5);
   byte bit6 = mask_if_content(scanner, m, i, j+6);
   if (bit0 && !bit1 && bit2 && bit3 && bit4 && !bit5 && bit6)
    score += 40;
  }
 for ( j = 0; j < s; j++)
  for ( i = 0; i < s-6; i++)
  {
   byte bit0 = mask_if_content(scanner, m, i+0, j);
   byte bit1 = mask_if_content(scanner, m, i+1, j);
   byte bit2 = mask_if_content(scanner, m, i+2, j);
   byte bit3 = mask_if_content(scanner, m, i+3, j);
   byte bit4 = mask_if_content(scanner, m, i+4, j);
   byte bit5 = mask_if_content(scanner, m, i+5, j);
   byte bit6 = mask_if_content(scanner, m, i+6, j);
   if (bit0 && !bit1 && bit2 && bit3 && bit4 && !bit5 && bit6)
    score += 40;
  }




 size_t n_dark = 0;
 for ( i = 0; i < s; i++)
  for ( j = 0; j < s; j++)
   if (mask_if_content(scanner, m, i, j))
    n_dark++;
 int ratio = (20 * n_dark) / (s*s);
 int k = ratio - 10;
 if (k < 0)
  k = -k;
 score += 10 * k;

 return score;
}

void mask_apply(scanner_t* scanner, byte m)
{
 size_t s = scanner->s;
 for (size_t i = 0; i < s; i++)
  for (size_t j = 0; j < s; j++)
   if (is_data(scanner, i, j))
    (scanner->d[(i)*scanner->s + (j)]) ^= mask(m, i, j);
}

byte get_codeword(scanner_t* scanner)
{
 byte res = 0;
 byte m = scanner->m;
 for (int i = 0; i < 8; i++)
 {
  size_t i = scanner->i;
  size_t j = scanner->j;

  res *= 2;
  res += (scanner->d[(i)*scanner->s + (j)]) ^ mask(m, i, j);
  next_bit(scanner);
 }

 return res;
}

void put_codeword(scanner_t* scanner, byte w)
{
 for (int i = 7; i >= 0; i--)
 {
  byte bit = (w>>i) & 1;

  (scanner->d[(scanner->i)*scanner->s + (scanner->j)]) = bit;
  next_bit(scanner);
 }
}
