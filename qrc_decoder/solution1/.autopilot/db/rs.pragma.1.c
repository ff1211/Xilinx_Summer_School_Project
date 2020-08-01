# 1 "qrc_decoder/src/rs.c"
# 1 "qrc_decoder/src/rs.c" 1
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
# 1 "qrc_decoder/src/rs.c" 2
# 19 "qrc_decoder/src/rs.c"
# 1 "qrc_decoder/src/rs.h" 1
# 22 "qrc_decoder/src/rs.h"
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
# 23 "qrc_decoder/src/rs.h" 2

typedef struct poly poly_t;




struct poly
{
 size_t d;
 byte c[512];
};

void rs_encode(size_t n_data, byte* data, byte n_sym);
byte rs_decode(size_t n_data, byte* data, byte n_sym);
# 20 "qrc_decoder/src/rs.c" 2

# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3








# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 9 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 36 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 3
  __attribute__ ((__dllimport__)) void * _memccpy(void *_Dst,const void *_Src,int _Val,size_t _MaxCount);
                void * memchr(const void *_Buf ,int _Val,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  __attribute__ ((__dllimport__)) int _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  int memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void * memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size) ;
  void * memset(void *_Dst,int _Val,size_t _Size);

  void * memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size) ;
  int memicmp(const void *_Buf1,const void *_Buf2,size_t _Size) ;


  char * _strset(char *_Str,int _Val) ;
  char * _strset_l(char *_Str,int _Val,_locale_t _Locale) ;
  char * strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
  char * strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
  int strcmp(const char *_Str1,const char *_Str2);
  size_t strlen(const char *_Str);
  size_t strnlen(const char *_Str,size_t _MaxCount);
  void * memmove(void *_Dst,const void *_Src,size_t _Size) ;
  __attribute__ ((__dllimport__)) char * _strdup(const char *_Src);
                char * strchr(const char *_Str,int _Val);
  __attribute__ ((__dllimport__)) int _stricmp(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int _strcmpi(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  int strcoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _stricoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t strcspn(const char *_Str,const char *_Control);
  __attribute__ ((__dllimport__)) char * _strerror(const char *_ErrMsg) ;
  char * strerror(int) ;
  __attribute__ ((__dllimport__)) char * _strlwr(char *_String) ;
  char *strlwr_l(char *_String,_locale_t _Locale) ;
  char * strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  int strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  __attribute__ ((__dllimport__)) char * _strnset(char *_Str,int _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) char * _strnset_l(char *str,int c,size_t count,_locale_t _Locale) ;
                char * strpbrk(const char *_Str,const char *_Control);
                char * strrchr(const char *_Str,int _Ch);
  __attribute__ ((__dllimport__)) char * _strrev(char *_Str);
  size_t strspn(const char *_Str,const char *_Control);
                char * strstr(const char *_Str,const char *_SubStr);
  char * strtok(char * __restrict__ _Str,const char * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) char * _strupr(char *_String) ;
  __attribute__ ((__dllimport__)) char *_strupr_l(char *_String,_locale_t _Locale) ;
  size_t strxfrm(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t _strxfrm_l(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);


  char * strdup(const char *_Src) ;
  int strcmpi(const char *_Str1,const char *_Str2) ;
  int stricmp(const char *_Str1,const char *_Str2) ;
  char * strlwr(char *_Str) ;
  int strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount) ;
  int strncasecmp (const char *, const char *, size_t);
  int strcasecmp (const char *, const char *);







  char * strnset(char *_Str,int _Val,size_t _MaxCount) ;
  char * strrev(char *_Str) ;
  char * strset(char *_Str,int _Val) ;
  char * strupr(char *_Str) ;





  __attribute__ ((__dllimport__)) wchar_t * _wcsdup(const wchar_t *_Str);
  wchar_t * wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
                wchar_t * wcschr(const wchar_t *_Str,wchar_t _Ch);
  int wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t * wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
  size_t wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t wcslen(const wchar_t *_Str);
  size_t wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  int wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  wchar_t * _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) ;
                wchar_t * wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t * wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t wcsspn(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t * wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t * wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) wchar_t * _wcserror(int _ErrNum) ;
  __attribute__ ((__dllimport__)) wchar_t * __wcserror(const wchar_t *_Str) ;
  __attribute__ ((__dllimport__)) int _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) wchar_t * _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) wchar_t * _wcsrev(wchar_t *_Str);
  __attribute__ ((__dllimport__)) wchar_t * _wcsset(wchar_t *_Str,wchar_t _Val) ;
  __attribute__ ((__dllimport__)) wchar_t * _wcslwr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) ;
  __attribute__ ((__dllimport__)) wchar_t * _wcsupr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) ;
  size_t wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  int wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);


  wchar_t * wcsdup(const wchar_t *_Str) ;

  int wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) ;
  int wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) ;
  wchar_t * wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  wchar_t * wcsrev(wchar_t *_Str) ;
  wchar_t * wcsset(wchar_t *_Str,wchar_t _Val) ;
  wchar_t * wcslwr(wchar_t *_Str) ;
  wchar_t * wcsupr(wchar_t *_Str) ;
  int wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) ;








# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 1 3








# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3
# 9 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 2 3
# 175 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 22 "qrc_decoder/src/rs.c" 2
# 34 "qrc_decoder/src/rs.c"
static byte max(byte a, byte b);





static void gf_init();

static byte gf_mul(byte x, byte y);
static byte gf_div(byte x, byte y);

static void gf_poly_scale(poly_t* r, poly_t* p, byte x);
static void gf_poly_add (poly_t* dest, poly_t* p, poly_t* q);
static void gf_poly_mul (poly_t* dest, poly_t* p, poly_t* q);
static byte gf_poly_eval (poly_t* p, byte x);




static byte rs_calc_syndromes (poly_t* msg, poly_t* synd);
static void rs_forney_syndromes(poly_t* msg, poly_t* synd, poly_t* pos, poly_t* fsynd);
static byte rs_find_error (poly_t* msg, poly_t* synd, poly_t* pos);
static void rs_fderivative (poly_t* r, poly_t* p);
static void rs_correct_errata (poly_t* msg, poly_t* synd, poly_t* pos);






static byte gf_exp[512] = {0};
static byte gf_log[256] = {0};

static byte max(byte a, byte b)
{
 return a >= b ? a : b;
}

static void gf_init()
{
 static char done = 0;
 if (done) return;
 done = 1;
 for (size_t i = 0, x = 1; i < 255; i++, x<<=1)
 {
  if (x & 0x100)
   x ^= 0x11d;
  gf_exp[i] = x;
  gf_log[x] = i;
 }
 for ( i = 255; i < 512; i++)
  gf_exp[i] = gf_exp[i-255];
}

static byte gf_mul(byte x, byte y)
{
 if (!x || !y) return 0;
 return gf_exp[gf_log[x] + gf_log[y]];
}

static byte gf_div(byte x, byte y)
{
 if (x == 0) return 0;
 if (y == 0) return 0;
 return gf_exp[gf_log[x] + 255 - gf_log[y]];
}

static void gf_poly_scale(poly_t* r, poly_t* p, byte x)
{
 for (size_t i = 0; i <= p->d; i++)
  r->c[i] = gf_mul(p->c[i], x);
 r->d = p->d;
}

static void gf_poly_add(poly_t* dest, poly_t* p, poly_t* q)
{
 poly_t r;

 size_t d = max(p->d, q->d);
 for (size_t i = 0; i <= p->d; i++)
  r.c[i+d-p->d] = p->c[i];
 for ( i = 0; i <= q->d; i++)
  r.c[i+d-q->d] ^= q->c[i];
 r.d = d;
 for(i=0;i<sizeof(poly_t);i++){
  (* dest).c[i]=r.c[i];
 }
 (* dest).d=r.d;

}

static void gf_poly_mul(poly_t* dest, poly_t* p, poly_t* q)
{
 poly_t r = { p->d + q->d, {0} };
 for (size_t i = 0; i <= p->d; i++)
  for (size_t j = 0; j <= q->d; j++)
   r.c[i+j] ^= gf_mul(p->c[i], q->c[j]);
 for(i=0;i<sizeof(poly_t);i++){
     (* dest).c[i]=r.c[i];
 }
 (* dest).d=r.d;

}

static byte gf_poly_eval(poly_t* p, byte x)
{
 byte y = p->c[0];
 for (size_t i = 1; i <= p->d; i++)
  y = gf_mul(y, x) ^ p->c[i];
 return y;
}

static void rs_generator_poly(poly_t* g, byte n_sym)
{
 gf_init();
 g->d = 0;
 g->c[0] = 1;
 for (size_t i = 0; i < n_sym; i++)
 {
  poly_t tmp = { 1, {1, gf_exp[i]} };
  gf_poly_mul(g, g, &tmp);
 }
}

void rs_encode(size_t n_data, byte* data, byte n_sym)
{
 poly_t gen;
 rs_generator_poly(&gen, n_sym);
 byte old[512];
    int i;
 for(i=0;i<n_data;i++){
      old[i]=data[i];
     }
 for(i=0;i<n_sym;i++){
     data[n_data+i]=0;
    }

 for ( i = 0; i < n_data; i++)
 {
  byte coef = data[i];
  if (coef)
   for (size_t j = 0; j <= gen.d; j++)
    data[i+j] ^= gf_mul(gen.c[j], coef);
 }
 for(i=0;i<n_data;i++){
  data[i]=old[i];
 }
}

static byte rs_calc_syndromes(poly_t* msg, poly_t* synd)
{
 gf_init();
 byte ret = 0;
 for (size_t i = 0; i < synd->d; i++)
  if ((synd->c[i] = gf_poly_eval(msg, gf_exp[i])) != 0)
   ret = 1;
 return ret;
}

static void rs_forney_syndromes(poly_t* msg, poly_t* synd, poly_t* pos, poly_t* fsynd)
{
 int i;
 for(i=0;i<sizeof(poly_t);i++){
      (* fsynd).c[i]=(*synd).c[i];
 } (* fsynd).d=(*synd).d;

 for ( i = 0; i < pos->d; i++)
 {
  byte x = gf_exp[msg->d - pos->c[i]];
  for (size_t i = 0; i < fsynd->d; i++)
   fsynd->c[i] = gf_mul(fsynd->c[i], x) ^ fsynd->c[i+1];
  fsynd->d--;
 }
}

static byte rs_find_error(poly_t* msg, poly_t* synd, poly_t* pos)
{

 poly_t err = { 0, {1} };
 poly_t old = { 0, {1} };
 for (size_t i = 0; i < synd->d; i++)
 {
  old.d++;
  old.c[old.d] = 0;
  byte delta = synd->c[i];
  for (size_t j = 1; j <= err.d; j++)
   delta ^= gf_mul(err.c[err.d-j], synd->c[i-j]);
  if (delta)
  {
   poly_t new;
   if (old.d > err.d)
   {
    gf_poly_scale(&new, &old, delta);
    gf_poly_scale(&old, &err, gf_div(1,delta));
    for(size_t k=0;k<sizeof(poly_t);k++){
         err.c[k]=new.c[k];
    }err.d=new.d;

   }
   gf_poly_scale(&new, &old, delta);
   gf_poly_add(&err, &err, &new);
  }
 }
 if (err.d > synd->d/2)
  return 1;


 size_t found = 0;
 for ( i = 0; i <= msg->d; i++)
  if (gf_poly_eval(&err, gf_exp[255-i]) == 0)
  {
   pos->c[pos->d++] = msg->d - i;
   found++;
  }

 if (found < err.d)
  return 1;

 return 0;
}

static void rs_fderivative(poly_t* r, poly_t* p)
{
 size_t i = p->d&1 ? 0 : 1;
 for (; i < p->d; i+=2)
  r->c[i/2] = p->c[i];
 r->d = p->d/2;
}

static void rs_correct_errata(poly_t* msg, poly_t* synd, poly_t* pos)
{

 poly_t q = { 0, {1} };
 poly_t tmp;tmp.d=1;tmp.c[1]=1;
 for (size_t i = 0; i < pos->d; i++)
 {
  byte x = gf_exp[msg->d - pos->c[i]];

  tmp.c[2]=x;
  gf_poly_mul(&q, &q, &tmp);
 }



 poly_t p;
 p.d= pos->d-1;
 for ( i = 0; i <= p.d; i++)
  p.c[i] = synd->c[p.d-i];

 gf_poly_mul(&p, &p, &q);


 for ( i = 0; i < pos->d; i++)
 {
         p.c[i]=p.c[i+ p.d-pos->d+1];
 }
 p.d = pos->d-1;


 poly_t qprime;
 rs_fderivative(&qprime, &q);


 for ( i = 0; i < pos->d; i++)
 {
  byte x = gf_exp[pos->c[i] + 255 - msg->d];
  byte y = gf_poly_eval(&p, x);
  byte z = gf_poly_eval(&qprime, gf_mul(x,x));
  msg->c[pos->c[i]] ^= gf_div(y, gf_mul(x,z));
 }
}

byte rs_decode(size_t n_data, byte* data, byte n_sym)
{
 poly_t msg ;
 msg.d= n_data-1;
 for(size_t k=0;k<n_data;k++){
                    msg.c[k]=data[k];
                }


 poly_t synd ;
 synd.d = n_sym;
 if (rs_calc_syndromes(&msg, &synd) == 0)
  return 0;


 poly_t pos = { 0, {0} };



 poly_t fsynd;
 rs_forney_syndromes(&msg, &synd, &pos, &fsynd);


 if (rs_find_error(&msg, &fsynd, &pos) != 0)
  return 1;


 rs_correct_errata(&msg, &synd, &pos);
 if (rs_calc_syndromes(&msg, &synd) != 0)
  return 1;

 for( k=0;k<n_data;k++){
                   data[k]= msg.c[k];
                }
 return 0;
}
