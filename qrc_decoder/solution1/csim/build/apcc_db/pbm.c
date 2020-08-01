/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;
typedef struct l_struct_OC_scanner l_struct_OC_scanner;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};

struct l_struct_OC_scanner {
   char *field0;
  unsigned long long field1;
  unsigned int field2;
  unsigned int field3;
  unsigned int field4;
  unsigned long long field5;
  unsigned long long field6;
  unsigned long long field7;
  unsigned long long field8;
   char field9[163];
  unsigned long long field10;
  unsigned long long field11;
  unsigned char field12;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void data_write( char llvm_cbe_dataout);
void load_pbm2( char *llvm_cbe_pdata, l_struct_OC__iobuf *llvm_cbe_f);
static unsigned char aesl_internal_nextint(l_struct_OC__iobuf *llvm_cbe_f);
static unsigned char aesl_internal_nextbit(l_struct_OC__iobuf *llvm_cbe_f,  char *llvm_cbe_buf, signed long long *llvm_cbe_buf_avail);
void load_pbm(l_struct_OC_scanner *llvm_cbe_scanner, l_struct_OC__iobuf *llvm_cbe_f);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[21] = "test_data/output.dat";
static  char aesl_internal__OC_str1[2] = "w";
static  char aesl_internal__OC_str3[29] = "I only handle square images\n";
static  char aesl_internal__OC_str4[27] = "Could not allocate memory\n";
static  char aesl_internal__OC_str5[25] = "Unsupported format '%c'\n";
static  char aesl_internal__OC_str6[24] = "Unexpected end of file\n";
static  char aesl_internal__OC_str7[35] = "Unexpected end of file in comment\n";
static  char aesl_internal__OC_str8[4] = " \n\r";
static  char aesl_internal__OC_str9[27] = "Unexpected character '%c'\n";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void data_write( char llvm_cbe_dataout) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_1_count = 0;
  unsigned int llvm_cbe_fputc_2e_1;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_2_count = 0;
  unsigned int llvm_cbe_fputc_2e_2;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_3_count = 0;
  unsigned int llvm_cbe_fputc_2e_3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_4_count = 0;
  unsigned int llvm_cbe_fputc_2e_4;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_5_count = 0;
  unsigned int llvm_cbe_fputc_2e_5;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_6_count = 0;
  unsigned int llvm_cbe_fputc_2e_6;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_7_count = 0;
  unsigned int llvm_cbe_fputc_2e_7;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_8_count = 0;
  unsigned int llvm_cbe_fputc_2e_8;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_9_count = 0;
  unsigned int llvm_cbe_fputc_2e_9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_10_count = 0;
  unsigned int llvm_cbe_fputc_2e_10;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_11_count = 0;
  unsigned int llvm_cbe_fputc_2e_11;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @data_write\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !10 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_3_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *) /*tail*/ aesl_fopen(( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i8 %%dataout to i32, !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_dataout&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.1 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_1_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.1 = 0x%X",llvm_cbe_fputc_2e_1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.2 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_2_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.2 = 0x%X",llvm_cbe_fputc_2e_2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.3 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_3_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.3 = 0x%X",llvm_cbe_fputc_2e_3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.4 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_4_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.4 = 0x%X",llvm_cbe_fputc_2e_4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.5 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_5_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.5 = 0x%X",llvm_cbe_fputc_2e_5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.6 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_6_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.6 = 0x%X",llvm_cbe_fputc_2e_6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.7 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_7_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.7 = 0x%X",llvm_cbe_fputc_2e_7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.8 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_8_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.8 = 0x%X",llvm_cbe_fputc_2e_8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.9 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_9_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.9 = 0x%X",llvm_cbe_fputc_2e_9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.10 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_10_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.10 = 0x%X",llvm_cbe_fputc_2e_10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.11 = tail call i32 @fputc(i32 %%2, %%struct._iobuf* %%1), !dbg !9 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_fputc_2e_11_count);
   /*tail*/ fputc(llvm_cbe_tmp__2, (l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__2);
printf("\nReturn fputc.11 = 0x%X",llvm_cbe_fputc_2e_11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !10 for 0x%I64xth hint within @data_write  --> \n", ++aesl_llvm_cbe_47_count);
   /*tail*/ fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @data_write}\n");
  return;
}


void load_pbm2( char *llvm_cbe_pdata, l_struct_OC__iobuf *llvm_cbe_f) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_buf_avail_count = 0;
  signed long long llvm_cbe_buf_avail;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned char llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned char llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned char llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond13_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge37_2e_us;
  unsigned long long llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned char llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge212_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge212_2e_us;
  unsigned long long llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond15_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge14_2e_us;
  unsigned long long llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned char llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond14_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge5_2e_us;
  unsigned long long llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_count = 0;
  unsigned long long llvm_cbe_storemerge5;
  unsigned long long llvm_cbe_storemerge5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond16_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_pbm2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !11 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_59_count);
  fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !11 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__5 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i32 %%2 to i8, !dbg !11 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__6 = (unsigned char )((unsigned char )llvm_cbe_tmp__5&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !11 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__7 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !11 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__8 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__8);
}
  if (((llvm_cbe_tmp__6&255U) == (((unsigned char )49)&255U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__26;
  }

llvm_cbe__2e_preheader10:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%5 to i64, !dbg !12 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__9 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__8&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
  if (((llvm_cbe_tmp__8&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader6_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__7&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge;
  } else {
    goto llvm_cbe__2e_preheader6_2e_lr_2e_ph_2e_split_2e_us;
  }

llvm_cbe__2e_preheader6_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i8 %%4 to i6 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__10 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__7&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
  llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph8_2e_us;

  do {     /* Syntactic loop '.lr.ph8.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph8_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge212.us = phi i64 [ 0, %%.preheader6.lr.ph.split.us ], [ %%12, %%11  for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_storemerge212_2e_us_count);
  llvm_cbe_storemerge212_2e_us = (unsigned long long )llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge212.us = 0x%I64X",llvm_cbe_storemerge212_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__11);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = mul i64 %%storemerge212.us, %%7, !dbg !9 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge212_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__9&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull)));
  llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%storemerge212.us, 1, !dbg !12 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge212_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
  if (((llvm_cbe_tmp__11&18446744073709551615ULL) == (llvm_cbe_tmp__9&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit11_crit_edge;
  } else {
    llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__11;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph8_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37.us = phi i64 [ 0, %%.lr.ph8.us ], [ %%17, %%13  for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_storemerge37_2e_us_count);
  llvm_cbe_storemerge37_2e_us = (unsigned long long )llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37.us = 0x%I64X",llvm_cbe_storemerge37_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !9 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__12 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge37.us, %%18, !dbg !9 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge37_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__16&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds i8* %%pdata, i64 %%15, !dbg !9 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__14 = ( char *)(&llvm_cbe_pdata[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%14, i8* %%16, align 1, !dbg !9 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_96_count);
  *llvm_cbe_tmp__14 = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%storemerge37.us, 1, !dbg !12 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__15 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge37_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__15&18446744073709551615ull)));
  if (((llvm_cbe_tmp__15&18446744073709551615ULL) == (llvm_cbe_tmp__10&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__28;
  } else {
    llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__15;   /* for PHI node */
    goto llvm_cbe_tmp__27;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph8.us' */
llvm_cbe_tmp__26:
  if (((llvm_cbe_tmp__6&255U) == (((unsigned char )52)&255U))) {
    goto llvm_cbe_tmp__29;
  } else {
    goto llvm_cbe_tmp__30;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%buf, align 1, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_117_count);
  *(&llvm_cbe_buf) = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%buf_avail, align 8, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_125_count);
  *(&llvm_cbe_buf_avail) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i8 %%5 to i64, !dbg !12 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__8&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__17);
  if (((llvm_cbe_tmp__8&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph:
  if (((llvm_cbe_tmp__7&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__31;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = zext i8 %%4 to i6 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__7&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
  llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5.us = phi i64 [ 0, %%.preheader.lr.ph.split.us ], [ %%27, %%26  for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_storemerge5_2e_us_count);
  llvm_cbe_storemerge5_2e_us = (unsigned long long )llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5.us = 0x%I64X",llvm_cbe_storemerge5_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = mul i64 %%storemerge5.us, %%22, !dbg !10 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__24 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5_2e_us&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull)));
  llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%buf_avail, align 8, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_143_count);
  *(&llvm_cbe_buf_avail) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%storemerge5.us, 1, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
  if (((llvm_cbe_tmp__19&18446744073709551615ULL) == (llvm_cbe_tmp__17&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit_crit_edge;
  } else {
    llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__19;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.us = phi i64 [ 0, %%.lr.ph.us ], [ %%32, %%28  for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_storemerge14_2e_us_count);
  llvm_cbe_storemerge14_2e_us = (unsigned long long )llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us = 0x%I64X",llvm_cbe_storemerge14_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call fastcc zeroext i8 @aesl_internal_nextbit(%%struct._iobuf* %%f, i8* %%buf, i64* %%buf_avail), !dbg !10 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__20 = (unsigned char )aesl_internal_nextbit((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)(&llvm_cbe_buf), (signed long long *)(&llvm_cbe_buf_avail));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%storemerge14.us, %%33, !dbg !10 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__21 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__24&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%pdata, i64 %%30, !dbg !10 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__22 = ( char *)(&llvm_cbe_pdata[(((signed long long )llvm_cbe_tmp__21))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__21));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%29, i8* %%31, align 1, !dbg !10 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_153_count);
  *llvm_cbe_tmp__22 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%storemerge14.us, 1, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__23 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__23&18446744073709551615ull)));
  if (((llvm_cbe_tmp__23&18446744073709551615ULL) == (llvm_cbe_tmp__18&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__33;
  } else {
    llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__23;   /* for PHI node */
    goto llvm_cbe_tmp__32;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5 = phi i64 [ %%35, %%34 ], [ 0, %%.preheader.lr.ph  for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_storemerge5_count);
  llvm_cbe_storemerge5 = (unsigned long long )llvm_cbe_storemerge5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5 = 0x%I64X",llvm_cbe_storemerge5);
printf("\n = 0x%I64X",llvm_cbe_tmp__25);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%buf_avail, align 8, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_174_count);
  *(&llvm_cbe_buf_avail) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i64 %%storemerge5, 1, !dbg !13 for 0x%I64xth hint within @load_pbm2  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__25 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__25&18446744073709551615ull)));
  if (((llvm_cbe_tmp__25&18446744073709551615ULL) == (llvm_cbe_tmp__17&18446744073709551615ULL))) {
    goto llvm_cbe__2e__2e_loopexit_crit_edge;
  } else {
    llvm_cbe_storemerge5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe_tmp__31;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__2e_loopexit_crit_edge:
  goto llvm_cbe__2e_loopexit;

llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__30;

llvm_cbe_tmp__30:
  goto llvm_cbe_tmp__34;

llvm_cbe__2e__2e_loopexit11_crit_edge:
  goto llvm_cbe__2e_loopexit11;

llvm_cbe__2e_loopexit11:
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__34:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_pbm2}\n");
  return;
}


static unsigned char aesl_internal_nextint(l_struct_OC__iobuf *llvm_cbe_f) {
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned char llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned char llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned char llvm_cbe_tmp__47;
  unsigned char llvm_cbe_tmp__47__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_memchr_count = 0;
   char *llvm_cbe_memchr;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  unsigned char llvm_cbe_tmp__52;
  unsigned char llvm_cbe_tmp__52__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  unsigned char llvm_cbe_tmp__53;
  unsigned char llvm_cbe_tmp__53__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond3_count = 0;
  bool llvm_cbe_or_2e_cond3;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned char llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned char llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned char llvm_cbe_tmp__60;
  unsigned char llvm_cbe_tmp__60__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_nextint\n");
  goto llvm_cbe_tmp__61;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__61:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call i32 @feof(%%struct._iobuf* %%f) nounwind, !dbg !9 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__35 = (unsigned int ) /*tail*/ feof((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
  if (((llvm_cbe_tmp__35&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__62;
  } else {
    goto llvm_cbe_tmp__63;
  }

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i8 [ %%10, %%8 ], [ 10, %%18  for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__47 = (unsigned char )llvm_cbe_tmp__47__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__47);
printf("\n = 0x%X",llvm_cbe_tmp__40);
printf("\n = 0x%X",((unsigned char )10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = sext i8 %%22 to i32, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__48 = (unsigned int )((signed int )( char )llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%memchr = tail call i8* @memchr(i8* getelementptr inbounds ([4 x i8]* @aesl_internal_.str8, i64 0, i64 0), i32 %%23, i64 4), !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_memchr_count);
  llvm_cbe_memchr = ( char *) /*tail*/ ( char *)memchr(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 4
#endif
])), llvm_cbe_tmp__48, 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__48);
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn memchr = 0x%X",llvm_cbe_memchr);
}
  if (((llvm_cbe_memchr) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__64;
  } else {
    goto llvm_cbe_tmp__61;
  }

llvm_cbe_tmp__62:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__39 = (unsigned int ) /*tail*/ fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i32 %%9 to i8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__40 = (unsigned char )((unsigned char )llvm_cbe_tmp__39&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
  if (((llvm_cbe_tmp__40&255U) == (((unsigned char )35)&255U))) {
    goto llvm_cbe__2e_preheader4;
  } else {
    llvm_cbe_tmp__47__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = tail call i32 @feof(%%struct._iobuf* %%f) nounwind, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__41 = (unsigned int ) /*tail*/ feof((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__41);
}
  if (((llvm_cbe_tmp__41&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__65;
  } else {
    goto llvm_cbe_tmp__66;
  }

llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_225_count);
  llvm_cbe_tmp__45 = (unsigned int ) /*tail*/ fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = trunc i32 %%19 to i8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__46 = (unsigned char )((unsigned char )llvm_cbe_tmp__45&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
  if (((llvm_cbe_tmp__46&255U) == (((unsigned char )10)&255U))) {
    llvm_cbe_tmp__47__PHI_TEMPORARY = (unsigned char )((unsigned char )10);   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    goto llvm_cbe__2e_preheader4;
  }

  } while (1); /* end of syntactic loop '.preheader4' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__36 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct._iobuf* %%5, i64 2, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__37 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__36[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i64 @fwrite(i8* getelementptr inbounds ([24 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 23, i64 1, %%struct._iobuf* %%6), !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_200_count);
   /*tail*/ fwrite(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 24
#endif
])), 23ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",23ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 1) noreturn nounwind, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_201_count);
   /*tail*/ exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__66:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__42 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct._iobuf* %%15, i64 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__42[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = tail call i64 @fwrite(i8* getelementptr inbounds ([35 x i8]* @aesl_internal_.str7, i64 0, i64 0), i64 34, i64 1, %%struct._iobuf* %%16), !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_222_count);
   /*tail*/ fwrite(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 35
#endif
])), 34ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",34ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 1) noreturn nounwind, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_223_count);
   /*tail*/ exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__64:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%26, %%27, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((( char )llvm_cbe_tmp__47) > (( char )((unsigned char )47))) & ((( char )llvm_cbe_tmp__47) < (( char )((unsigned char )58))))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__52__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    llvm_cbe_tmp__53__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__47;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__67;
  }

llvm_cbe_tmp__67:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__49 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__49);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct._iobuf* %%29, i64 2, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__50 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__49[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%30, i8* getelementptr inbounds ([27 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32 %%23) nounwind, !dbg !11 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_248_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__50, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])), llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__48);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__51);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @exit(i32 1) noreturn nounwind, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_249_count);
   /*tail*/ exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i8 [ %%39, %%42 ], [ 0, %%25  for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__52 = (unsigned char )llvm_cbe_tmp__52__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__56);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = phi i8 [ %%44, %%42 ], [ %%22, %%25  for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__53 = (unsigned char )llvm_cbe_tmp__53__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__53);
printf("\n = 0x%X",llvm_cbe_tmp__59);
printf("\n = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond3 = and i1 %%34, %%3 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_or_2e_cond3_count);
  llvm_cbe_or_2e_cond3 = (bool )((((( char )llvm_cbe_tmp__53) > (( char )((unsigned char )47))) & ((( char )llvm_cbe_tmp__53) < (( char )((unsigned char )58))))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond3 = 0x%X\n", llvm_cbe_or_2e_cond3);
  if (llvm_cbe_or_2e_cond3) {
    goto llvm_cbe_tmp__68;
  } else {
    llvm_cbe_tmp__60__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__52;   /* for PHI node */
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__69:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__58 = (unsigned int ) /*tail*/ fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = trunc i32 %%43 to i8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__59 = (unsigned char )((unsigned char )llvm_cbe_tmp__58&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
  llvm_cbe_tmp__52__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__56;   /* for PHI node */
  llvm_cbe_tmp__53__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__59;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__68:
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = mul i8 %%32, 10, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__54 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__52&255ull)) * ((unsigned char )(((unsigned char )10)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__54&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i8 %%37, -48, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__55 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__54&255ull)) + ((unsigned char )(((unsigned char )-48)&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__55&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i8 %%38, %%33, !dbg !12 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__56 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__55&255ull)) + ((unsigned char )(llvm_cbe_tmp__53&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__56&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = tail call i32 @feof(%%struct._iobuf* %%f) nounwind, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__57 = (unsigned int ) /*tail*/ feof((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__57);
}
  if (((llvm_cbe_tmp__57&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__69;
  } else {
    llvm_cbe_tmp__60__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__56;   /* for PHI node */
    goto llvm_cbe__2e_critedge;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = phi i8 [ %%32, %%.preheader ], [ %%39, %%36  for 0x%I64xth hint within @aesl_internal_nextint  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__60 = (unsigned char )llvm_cbe_tmp__60__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__60);
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__56);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_nextint}\n");
  return llvm_cbe_tmp__60;
}


static unsigned char aesl_internal_nextbit(l_struct_OC__iobuf *llvm_cbe_f,  char *llvm_cbe_buf, signed long long *llvm_cbe_buf_avail) {
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  unsigned long long llvm_cbe_tmp__72__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned char llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  unsigned char llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  unsigned char llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_nextbit\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i64* %%buf_avail, align 8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__70 = (unsigned long long )*llvm_cbe_buf_avail;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__70);
  if (((llvm_cbe_tmp__70&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__80;
  } else {
    llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__70;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i64 @fread(i8* %%buf, i64 1, i64 1, %%struct._iobuf* %%f) nounwind, !dbg !9 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_297_count);
   /*tail*/ fread(( char *)llvm_cbe_buf, 1ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",1ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__71);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 8, i64* %%buf_avail, align 8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_298_count);
  *llvm_cbe_buf_avail = 8ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 8ull);
  llvm_cbe_tmp__72__PHI_TEMPORARY = (unsigned long long )8ull;   /* for PHI node */
  goto llvm_cbe_tmp__81;

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i64 [ %%1, %%0 ], [ 8, %%3  for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__72 = (unsigned long long )llvm_cbe_tmp__72__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__72);
printf("\n = 0x%I64X",llvm_cbe_tmp__70);
printf("\n = 0x%I64X",8ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%buf, align 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__73 = (unsigned char )*llvm_cbe_buf;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%7 to i32, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__73&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__74);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add i64 %%6, -1, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__75 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%9, i64* %%buf_avail, align 8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_304_count);
  *llvm_cbe_buf_avail = llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i64 %%9 to i32, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__76 = (unsigned int )((unsigned int )llvm_cbe_tmp__75&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = lshr i32 %%8, %%10, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_306_count);
  llvm_cbe_tmp__77 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__74&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__76&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__77&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = trunc i32 %%11 to i8, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__78 = (unsigned char )((unsigned char )llvm_cbe_tmp__77&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = and i8 %%12, 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_nextbit  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__79 = (unsigned char )((unsigned char )(llvm_cbe_tmp__78 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__79);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_nextbit}\n");
  return llvm_cbe_tmp__79;
}


void load_pbm(l_struct_OC_scanner *llvm_cbe_scanner, l_struct_OC__iobuf *llvm_cbe_f) {
  static  unsigned long long aesl_llvm_cbe_buf_count = 0;
   char llvm_cbe_buf;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_buf_avail_count = 0;
  signed long long llvm_cbe_buf_avail;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned char llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned char llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  unsigned char llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
   char *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned long long llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
   char **llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  signed long long *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond13_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge37_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge37_2e_us;
  unsigned long long llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  unsigned char llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
   char *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
   char *llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge212_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge212_2e_us;
  unsigned long long llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond15_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge14_2e_us;
  unsigned long long llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  unsigned char llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
   char *llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond14_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge5_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge5_2e_us;
  unsigned long long llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  unsigned int llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_pbm\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !11 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_324_count);
  fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__82);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i32 @fgetc(%%struct._iobuf* %%f) nounwind, !dbg !11 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__83 = (unsigned int )fgetc((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i32 %%2 to i8, !dbg !11 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__84 = (unsigned char )((unsigned char )llvm_cbe_tmp__83&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !11 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__85 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__85);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !11 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__86 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__86);
}
  if (((llvm_cbe_tmp__85&255U) == (llvm_cbe_tmp__86&255U))) {
    goto llvm_cbe_tmp__118;
  } else {
    goto llvm_cbe_tmp__119;
  }

llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__87 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct._iobuf* %%8, i64 2, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__88 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__87[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i64 @fwrite(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str3, i64 0, i64 0), i64 28, i64 1, %%struct._iobuf* %%9), !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_348_count);
  fwrite(( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])), 28ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",28ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_349_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i8 %%4 to i64, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__90 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__85&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul i64 %%12, %%12, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__90&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call i8* @malloc(i64 %%13), !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__92 = ( char *)( char *)malloc(llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__91);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__92);
}
  if (((llvm_cbe_tmp__92) == ((( char *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__120;
  } else {
    goto llvm_cbe_tmp__121;
  }

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__93 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct._iobuf* %%17, i64 2, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__94 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__93[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = call i64 @fwrite(i8* getelementptr inbounds ([27 x i8]* @aesl_internal_.str4, i64 0, i64 0), i64 26, i64 1, %%struct._iobuf* %%18), !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_361_count);
  fwrite(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 27
#endif
])), 26ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",26ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__95);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !13 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_362_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe_tmp__121:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !9 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__96 = ( char **)(&llvm_cbe_scanner->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8* %%14, i8** %%21, align 8, !dbg !9 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_365_count);
  *llvm_cbe_tmp__96 = ( char *)llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_366_count);
  llvm_cbe_tmp__97 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%12, i64* %%22, align 8, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_367_count);
  *llvm_cbe_tmp__97 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
  if (((llvm_cbe_tmp__84&255U) == (((unsigned char )49)&255U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__122;
  }

llvm_cbe__2e_preheader10:
  if (((llvm_cbe_tmp__85&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph8_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph8.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph8_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge212.us = phi i64 [ %%26, %%25 ], [ 0, %%.preheader10  for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_storemerge212_2e_us_count);
  llvm_cbe_storemerge212_2e_us = (unsigned long long )llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge212.us = 0x%I64X",llvm_cbe_storemerge212_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__98);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__123;

llvm_cbe_tmp__124:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%storemerge212.us, 1, !dbg !14 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__98 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge212_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__98&18446744073709551615ull)));
  if (((llvm_cbe_tmp__98&18446744073709551615ULL) == (llvm_cbe_tmp__90&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit11;
  } else {
    llvm_cbe_storemerge212_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__98;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph8_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__123:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge37.us = phi i64 [ 0, %%.lr.ph8.us ], [ %%34, %%27  for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_storemerge37_2e_us_count);
  llvm_cbe_storemerge37_2e_us = (unsigned long long )llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge37.us = 0x%I64X",llvm_cbe_storemerge37_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__105);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call fastcc zeroext i8 @aesl_internal_nextint(%%struct._iobuf* %%f), !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__99 = (unsigned char )aesl_internal_nextint((l_struct_OC__iobuf *)llvm_cbe_f);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__99);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%22, align 8, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__100 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = mul i64 %%29, %%storemerge212.us, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__101 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__100&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge212_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%30, %%storemerge37.us, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_384_count);
  llvm_cbe_tmp__102 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__101&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge37_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__102&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i8** %%21, align 8, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__103 = ( char *)*llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds i8* %%32, i64 %%31, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__104 = ( char *)(&llvm_cbe_tmp__103[(((signed long long )llvm_cbe_tmp__102))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__102));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%33, align 1, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_387_count);
  *llvm_cbe_tmp__104 = llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%storemerge37.us, 1, !dbg !14 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__105 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge37_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)));
  if (((llvm_cbe_tmp__105&18446744073709551615ULL) == (llvm_cbe_tmp__90&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__124;
  } else {
    llvm_cbe_storemerge37_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__105;   /* for PHI node */
    goto llvm_cbe_tmp__123;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph8.us' */
llvm_cbe_tmp__122:
  if (((llvm_cbe_tmp__84&255U) == (((unsigned char )52)&255U))) {
    goto llvm_cbe_tmp__125;
  } else {
    goto llvm_cbe_tmp__126;
  }

llvm_cbe_tmp__125:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%buf, align 1, !dbg !14 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_407_count);
  *(&llvm_cbe_buf) = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%buf_avail, align 8, !dbg !14 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_415_count);
  *(&llvm_cbe_buf_avail) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  if (((llvm_cbe_tmp__85&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge5.us = phi i64 [ %%40, %%39 ], [ 0, %%37  for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_storemerge5_2e_us_count);
  llvm_cbe_storemerge5_2e_us = (unsigned long long )llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge5.us = 0x%I64X",llvm_cbe_storemerge5_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__106);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__127;

llvm_cbe_tmp__128:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%buf_avail, align 8, !dbg !15 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_428_count);
  *(&llvm_cbe_buf_avail) = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%storemerge5.us, 1, !dbg !15 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_429_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge5_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
  if (((llvm_cbe_tmp__106&18446744073709551615ULL) == (llvm_cbe_tmp__90&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge5_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__106;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14.us = phi i64 [ 0, %%.lr.ph.us ], [ %%48, %%41  for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_storemerge14_2e_us_count);
  llvm_cbe_storemerge14_2e_us = (unsigned long long )llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14.us = 0x%I64X",llvm_cbe_storemerge14_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__113);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call fastcc zeroext i8 @aesl_internal_nextbit(%%struct._iobuf* %%f, i8* %%buf, i64* %%buf_avail), !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_435_count);
  llvm_cbe_tmp__107 = (unsigned char )aesl_internal_nextbit((l_struct_OC__iobuf *)llvm_cbe_f, ( char *)(&llvm_cbe_buf), (signed long long *)(&llvm_cbe_buf_avail));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__107);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%22, align 8, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__108 = (unsigned long long )*llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul i64 %%43, %%storemerge5.us, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge5_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i64 %%44, %%storemerge14.us, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__110 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__110&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8** %%21, align 8, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__111 = ( char *)*llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds i8* %%46, i64 %%45, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__112 = ( char *)(&llvm_cbe_tmp__111[(((signed long long )llvm_cbe_tmp__110))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__110));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%42, i8* %%47, align 1, !dbg !10 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_441_count);
  *llvm_cbe_tmp__112 = llvm_cbe_tmp__107;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i64 %%storemerge14.us, 1, !dbg !15 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__113 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__113&18446744073709551615ull)));
  if (((llvm_cbe_tmp__113&18446744073709551615ULL) == (llvm_cbe_tmp__90&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__128;
  } else {
    llvm_cbe_storemerge14_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__113;   /* for PHI node */
    goto llvm_cbe_tmp__127;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe_tmp__126:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__114 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__114);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds %%struct._iobuf* %%50, i64 2, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__115 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__114[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = sext i8 %%3 to i32, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__116 = (unsigned int )((signed int )( char )llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%51, i8* getelementptr inbounds ([25 x i8]* @aesl_internal_.str5, i64 0, i64 0), i32 %%52) nounwind, !dbg !12 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_455_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__115, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 25
#endif
])), llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__116);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__117);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @exit(i32 1) noreturn nounwind, !dbg !15 for 0x%I64xth hint within @load_pbm  --> \n", ++aesl_llvm_cbe_456_count);
  exit(1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",1u);
}
  /*UNREACHABLE*/;
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__129;

llvm_cbe__2e_loopexit11:
  goto llvm_cbe_tmp__129;

llvm_cbe_tmp__129:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_pbm}\n");
  return;
}

