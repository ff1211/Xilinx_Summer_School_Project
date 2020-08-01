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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int bch_check(signed int llvm_cbe_g, signed int llvm_cbe_code);
static signed int aesl_internal_leading_bit(signed int llvm_cbe_x);
signed int bch_encode(signed int llvm_cbe_g, signed int llvm_cbe_code);
signed int bch_decode(signed int llvm_cbe_g, signed int llvm_cbe_code);
static signed int aesl_internal_hamming_weight(signed int llvm_cbe_code);


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

signed int bch_check(signed int llvm_cbe_g, signed int llvm_cbe_code) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__5;
  unsigned int llvm_cbe_tmp__5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__6;
  unsigned int llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  unsigned int llvm_cbe_tmp__7;
  unsigned int llvm_cbe_tmp__7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned int llvm_cbe_tmp__11;
  unsigned int llvm_cbe_tmp__11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @bch_check\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call fastcc i32 @aesl_internal_leading_bit(i32 %%code), !dbg !4 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__1 = (unsigned int ) /*tail*/ aesl_internal_leading_bit(llvm_cbe_code);
if (AESL_DEBUG_TRACE) {
printf("\nArgument code = 0x%X",llvm_cbe_code);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call fastcc i32 @aesl_internal_leading_bit(i32 %%g), !dbg !4 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__2 = (unsigned int ) /*tail*/ aesl_internal_leading_bit(llvm_cbe_g);
if (AESL_DEBUG_TRACE) {
printf("\nArgument g = 0x%X",llvm_cbe_g);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i32 1, %%1, !dbg !5 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_15_count);
  llvm_cbe_tmp__3 = (unsigned int )1u << llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sub nsw i32 %%1, %%2, !dbg !5 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__4) > ((signed int )4294967295u))) {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )llvm_cbe_code;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    llvm_cbe_tmp__7__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__4;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_code;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i32 [ %%15, %%14 ], [ %%code, %%0  for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__5 = (unsigned int )llvm_cbe_tmp__5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__5);
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\ncode = 0x%X",llvm_cbe_code);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi i32 [ %%17, %%14 ], [ %%3, %%0  for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__6 = (unsigned int )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__6);
printf("\n = 0x%X",llvm_cbe_tmp__13);
printf("\n = 0x%X",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = phi i32 [ %%16, %%14 ], [ %%4, %%0  for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__7 = (unsigned int )llvm_cbe_tmp__7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__7);
printf("\n = 0x%X",llvm_cbe_tmp__12);
printf("\n = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = and i32 %%6, %%7, !dbg !5 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__8 = (unsigned int )llvm_cbe_tmp__5 & llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
  if (((llvm_cbe_tmp__8&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__11__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe_tmp__14;
  } else {
    goto llvm_cbe_tmp__15;
  }

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi i32 [ %%13, %%11 ], [ %%6, %%.lr.ph  for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__11 = (unsigned int )llvm_cbe_tmp__11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",llvm_cbe_tmp__10);
printf("\n = 0x%X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%8, -1, !dbg !5 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__7&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = ashr i32 %%7, 1, !dbg !5 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__13 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__6) >> ((signed int )1u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__13));
  if ((((signed int )llvm_cbe_tmp__7) > ((signed int )0u))) {
    llvm_cbe_tmp__5__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__13;   /* for PHI node */
    llvm_cbe_tmp__7__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__12;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__11;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl i32 %%g, %%8, !dbg !4 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__9 = (unsigned int )llvm_cbe_g << llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = xor i32 %%6, %%12, !dbg !4 for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__10 = (unsigned int )llvm_cbe_tmp__5 ^ llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
  llvm_cbe_tmp__11__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__10;   /* for PHI node */
  goto llvm_cbe_tmp__14;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ %%code, %%0 ], [ %%15, %%14  for 0x%I64xth hint within @bch_check  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\ncode = 0x%X",llvm_cbe_code);
printf("\n = 0x%X",llvm_cbe_tmp__11);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @bch_check}\n");
  return llvm_cbe__2e_lcssa;
}


static signed int aesl_internal_leading_bit(signed int llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_sh_count = 0;
  unsigned int llvm_cbe_ctlz_2e_sh;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_step_count = 0;
  unsigned int llvm_cbe_ctlz_2e_step;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_sh1_count = 0;
  unsigned int llvm_cbe_ctlz_2e_sh1;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_step2_count = 0;
  unsigned int llvm_cbe_ctlz_2e_step2;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_sh3_count = 0;
  unsigned int llvm_cbe_ctlz_2e_sh3;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_step4_count = 0;
  unsigned int llvm_cbe_ctlz_2e_step4;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_sh5_count = 0;
  unsigned int llvm_cbe_ctlz_2e_sh5;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_step6_count = 0;
  unsigned int llvm_cbe_ctlz_2e_step6;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_sh7_count = 0;
  unsigned int llvm_cbe_ctlz_2e_sh7;
  static  unsigned long long aesl_llvm_cbe_ctlz_2e_step8_count = 0;
  unsigned int llvm_cbe_ctlz_2e_step8;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and1_count = 0;
  unsigned int llvm_cbe_cppop_2e_and1;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and2_count = 0;
  unsigned int llvm_cbe_cppop_2e_and2;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and19_count = 0;
  unsigned int llvm_cbe_cppop_2e_and19;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh10_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh10;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and211_count = 0;
  unsigned int llvm_cbe_cppop_2e_and211;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step12_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step12;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and113_count = 0;
  unsigned int llvm_cbe_cppop_2e_and113;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh14_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh14;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and215_count = 0;
  unsigned int llvm_cbe_cppop_2e_and215;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step16_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step16;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and117_count = 0;
  unsigned int llvm_cbe_cppop_2e_and117;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh18_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh18;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and219_count = 0;
  unsigned int llvm_cbe_cppop_2e_and219;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step20_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step20;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and121_count = 0;
  unsigned int llvm_cbe_cppop_2e_and121;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh22_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh22;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and223_count = 0;
  unsigned int llvm_cbe_cppop_2e_and223;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step24_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step24;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_part_count = 0;
  unsigned int llvm_cbe_ctpop_2e_part;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_leading_bit\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.sh = lshr i32 %%x,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_sh_count);
  llvm_cbe_ctlz_2e_sh = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_x&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctlz.sh = 0x%X\n", ((unsigned int )(llvm_cbe_ctlz_2e_sh&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.step = or i32 %%x, %%ctlz.s for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_step_count);
  llvm_cbe_ctlz_2e_step = (unsigned int )llvm_cbe_x | llvm_cbe_ctlz_2e_sh;
if (AESL_DEBUG_TRACE)
printf("\nctlz.step = 0x%X\n", llvm_cbe_ctlz_2e_step);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.sh1 = lshr i32 %%ctlz.step,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_sh1_count);
  llvm_cbe_ctlz_2e_sh1 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctlz_2e_step&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctlz.sh1 = 0x%X\n", ((unsigned int )(llvm_cbe_ctlz_2e_sh1&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.step2 = or i32 %%ctlz.step, %%ctlz.sh for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_step2_count);
  llvm_cbe_ctlz_2e_step2 = (unsigned int )llvm_cbe_ctlz_2e_step | llvm_cbe_ctlz_2e_sh1;
if (AESL_DEBUG_TRACE)
printf("\nctlz.step2 = 0x%X\n", llvm_cbe_ctlz_2e_step2);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.sh3 = lshr i32 %%ctlz.step2,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_sh3_count);
  llvm_cbe_ctlz_2e_sh3 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctlz_2e_step2&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctlz.sh3 = 0x%X\n", ((unsigned int )(llvm_cbe_ctlz_2e_sh3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.step4 = or i32 %%ctlz.step2, %%ctlz.sh for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_step4_count);
  llvm_cbe_ctlz_2e_step4 = (unsigned int )llvm_cbe_ctlz_2e_step2 | llvm_cbe_ctlz_2e_sh3;
if (AESL_DEBUG_TRACE)
printf("\nctlz.step4 = 0x%X\n", llvm_cbe_ctlz_2e_step4);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.sh5 = lshr i32 %%ctlz.step4,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_sh5_count);
  llvm_cbe_ctlz_2e_sh5 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctlz_2e_step4&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctlz.sh5 = 0x%X\n", ((unsigned int )(llvm_cbe_ctlz_2e_sh5&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.step6 = or i32 %%ctlz.step4, %%ctlz.sh for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_step6_count);
  llvm_cbe_ctlz_2e_step6 = (unsigned int )llvm_cbe_ctlz_2e_step4 | llvm_cbe_ctlz_2e_sh5;
if (AESL_DEBUG_TRACE)
printf("\nctlz.step6 = 0x%X\n", llvm_cbe_ctlz_2e_step6);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.sh7 = lshr i32 %%ctlz.step6, 1 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_sh7_count);
  llvm_cbe_ctlz_2e_sh7 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctlz_2e_step6&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctlz.sh7 = 0x%X\n", ((unsigned int )(llvm_cbe_ctlz_2e_sh7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctlz.step8 = or i32 %%ctlz.step6, %%ctlz.sh for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctlz_2e_step8_count);
  llvm_cbe_ctlz_2e_step8 = (unsigned int )llvm_cbe_ctlz_2e_step6 | llvm_cbe_ctlz_2e_sh7;
if (AESL_DEBUG_TRACE)
printf("\nctlz.step8 = 0x%X\n", llvm_cbe_ctlz_2e_step8);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = xor i32 %%ctlz.step8, - for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_ctlz_2e_step8 ^ 4294967295u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and1 = and i32 %%1, 143165576 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and1_count);
  llvm_cbe_cppop_2e_and1 = (unsigned int )llvm_cbe_tmp__16 & 1431655765u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and1 = 0x%X\n", llvm_cbe_cppop_2e_and1);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh = lshr i32 %%1,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh_count);
  llvm_cbe_ctpop_2e_sh = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and2 = and i32 %%ctpop.sh, 143165576 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and2_count);
  llvm_cbe_cppop_2e_and2 = (unsigned int )llvm_cbe_ctpop_2e_sh & 1431655765u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and2 = 0x%X\n", llvm_cbe_cppop_2e_and2);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step = add i32 %%cppop.and1, %%cppop.and for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_step_count);
  llvm_cbe_ctpop_2e_step = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and1&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and19 = and i32 %%ctpop.step, 85899345 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and19_count);
  llvm_cbe_cppop_2e_and19 = (unsigned int )llvm_cbe_ctpop_2e_step & 858993459u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and19 = 0x%X\n", llvm_cbe_cppop_2e_and19);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh10 = lshr i32 %%ctpop.step,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh10_count);
  llvm_cbe_ctpop_2e_sh10 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh10 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and211 = and i32 %%ctpop.sh10, 85899345 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and211_count);
  llvm_cbe_cppop_2e_and211 = (unsigned int )llvm_cbe_ctpop_2e_sh10 & 858993459u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and211 = 0x%X\n", llvm_cbe_cppop_2e_and211);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step12 = add i32 %%cppop.and19, %%cppop.and21 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_step12_count);
  llvm_cbe_ctpop_2e_step12 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and19&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and211&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step12 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and113 = and i32 %%ctpop.step12, 25264513 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and113_count);
  llvm_cbe_cppop_2e_and113 = (unsigned int )llvm_cbe_ctpop_2e_step12 & 252645135u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and113 = 0x%X\n", llvm_cbe_cppop_2e_and113);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh14 = lshr i32 %%ctpop.step12,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh14_count);
  llvm_cbe_ctpop_2e_sh14 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step12&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh14 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and215 = and i32 %%ctpop.sh14, 25264513 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and215_count);
  llvm_cbe_cppop_2e_and215 = (unsigned int )llvm_cbe_ctpop_2e_sh14 & 252645135u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and215 = 0x%X\n", llvm_cbe_cppop_2e_and215);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step16 = add i32 %%cppop.and113, %%cppop.and21 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_step16_count);
  llvm_cbe_ctpop_2e_step16 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and113&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and215&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step16 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and117 = and i32 %%ctpop.step16, 1671193 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and117_count);
  llvm_cbe_cppop_2e_and117 = (unsigned int )llvm_cbe_ctpop_2e_step16 & 16711935u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and117 = 0x%X\n", llvm_cbe_cppop_2e_and117);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh18 = lshr i32 %%ctpop.step16,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh18_count);
  llvm_cbe_ctpop_2e_sh18 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step16&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh18 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and219 = and i32 %%ctpop.sh18, 1671193 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and219_count);
  llvm_cbe_cppop_2e_and219 = (unsigned int )llvm_cbe_ctpop_2e_sh18 & 16711935u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and219 = 0x%X\n", llvm_cbe_cppop_2e_and219);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step20 = add i32 %%cppop.and117, %%cppop.and21 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_step20_count);
  llvm_cbe_ctpop_2e_step20 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and117&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and219&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step20 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step20&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and121 = and i32 %%ctpop.step20, 6553 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and121_count);
  llvm_cbe_cppop_2e_and121 = (unsigned int )llvm_cbe_ctpop_2e_step20 & 65535u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and121 = 0x%X\n", llvm_cbe_cppop_2e_and121);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh22 = lshr i32 %%ctpop.step20, 1 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh22_count);
  llvm_cbe_ctpop_2e_sh22 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step20&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh22 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and223 = and i32 %%ctpop.sh22, 6553 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_cppop_2e_and223_count);
  llvm_cbe_cppop_2e_and223 = (unsigned int )llvm_cbe_ctpop_2e_sh22 & 65535u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and223 = 0x%X\n", llvm_cbe_cppop_2e_and223);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step24 = add i32 %%cppop.and121, %%cppop.and22 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_step24_count);
  llvm_cbe_ctpop_2e_step24 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and121&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and223&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step24 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.part = add i32 %%ctpop.step24,  for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_ctpop_2e_part_count);
  llvm_cbe_ctpop_2e_part = (unsigned int )((unsigned int )(llvm_cbe_ctpop_2e_step24&4294967295ull)) + ((unsigned int )(0u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.part = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_part&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = xor i32 %%ctpop.part, 31, !dbg !4 for 0x%I64xth hint within @aesl_internal_leading_bit  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__17 = (unsigned int )llvm_cbe_ctpop_2e_part ^ 31u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_leading_bit}\n");
  return llvm_cbe_tmp__17;
}


signed int bch_encode(signed int llvm_cbe_g, signed int llvm_cbe_code) {
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @bch_encode\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call fastcc i32 @aesl_internal_leading_bit(i32 %%g), !dbg !4 for 0x%I64xth hint within @bch_encode  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__18 = (unsigned int ) /*tail*/ aesl_internal_leading_bit(llvm_cbe_g);
if (AESL_DEBUG_TRACE) {
printf("\nArgument g = 0x%X",llvm_cbe_g);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl i32 %%code, %%1, !dbg !4 for 0x%I64xth hint within @bch_encode  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_code << llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call i32 @bch_check(i32 %%g, i32 %%2), !dbg !4 for 0x%I64xth hint within @bch_encode  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__20 = (unsigned int ) /*tail*/ bch_check(llvm_cbe_g, llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nArgument g = 0x%X",llvm_cbe_g);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__19);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i32 %%2, %%3, !dbg !4 for 0x%I64xth hint within @bch_encode  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__21 = (unsigned int )llvm_cbe_tmp__19 ^ llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @bch_encode}\n");
  return llvm_cbe_tmp__21;
}


signed int bch_decode(signed int llvm_cbe_g, signed int llvm_cbe_code) {
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__25;
  unsigned int llvm_cbe_tmp__25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__26;
  unsigned int llvm_cbe_tmp__26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned int llvm_cbe_tmp__29;
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
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned int llvm_cbe_tmp__30;
  unsigned int llvm_cbe_tmp__30__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__31;
  unsigned int llvm_cbe_tmp__31__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @bch_decode\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call fastcc i32 @aesl_internal_leading_bit(i32 %%code), !dbg !4 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__22 = (unsigned int ) /*tail*/ aesl_internal_leading_bit(llvm_cbe_code);
if (AESL_DEBUG_TRACE) {
printf("\nArgument code = 0x%X",llvm_cbe_code);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sdiv i32 %%1, 2, !dbg !4 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__23 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__22) / ((signed int )2u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__23));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i32 1, %%2, !dbg !5 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__24 = (unsigned int )1u << llvm_cbe_tmp__23;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if ((((signed int )llvm_cbe_tmp__24) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )64u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%16, %%13 ], [ 0, %%0  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__32);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = phi i32 [ %%15, %%13 ], [ -1, %%0  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__25 = (unsigned int )llvm_cbe_tmp__25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\n = 0x%X",4294967295u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i32 [ %%14, %%13 ], [ 64, %%0  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__26 = (unsigned int )llvm_cbe_tmp__26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__26);
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",64u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call i32 @bch_encode(i32 %%g, i32 %%storemerge1), !dbg !4 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__27 = (unsigned int ) /*tail*/ bch_encode(llvm_cbe_g, llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument g = 0x%X",llvm_cbe_g);
printf("\nArgument storemerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = xor i32 %%7, %%code, !dbg !5 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__28 = (unsigned int )llvm_cbe_tmp__27 ^ llvm_cbe_code;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = tail call fastcc i32 @aesl_internal_hamming_weight(i32 %%8), !dbg !5 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__29 = (unsigned int ) /*tail*/ aesl_internal_hamming_weight(llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__28);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
  if ((((signed int )llvm_cbe_tmp__29) < ((signed int )llvm_cbe_tmp__26))) {
    llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned int )llvm_cbe_storemerge1;   /* for PHI node */
    goto llvm_cbe_tmp__33;
  } else {
    goto llvm_cbe_tmp__34;
  }

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi i32 [ %%9, %%.lr.ph ], [ %%6, %%11  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__30 = (unsigned int )llvm_cbe_tmp__30__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__30);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi i32 [ %%storemerge1, %%.lr.ph ], [ %%., %%11  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__31 = (unsigned int )llvm_cbe_tmp__31__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
  if (((llvm_cbe_tmp__32&4294967295U) == (llvm_cbe_tmp__24&4294967295U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__32;   /* for PHI node */
    llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__30;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%12, i32 -1, i32 %%5, !dbg !6 for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )((((llvm_cbe_tmp__29&4294967295U) == (llvm_cbe_tmp__26&4294967295U))) ? ((unsigned int )4294967295u) : ((unsigned int )llvm_cbe_tmp__25));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  llvm_cbe_tmp__30__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__26;   /* for PHI node */
  llvm_cbe_tmp__31__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
  goto llvm_cbe_tmp__33;

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ -1, %%0 ], [ %%15, %%13  for 0x%I64xth hint within @bch_decode  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",llvm_cbe_tmp__31);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @bch_decode}\n");
  return llvm_cbe__2e_lcssa;
}


static signed int aesl_internal_hamming_weight(signed int llvm_cbe_code) {
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and1_count = 0;
  unsigned int llvm_cbe_cppop_2e_and1;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and2_count = 0;
  unsigned int llvm_cbe_cppop_2e_and2;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and11_count = 0;
  unsigned int llvm_cbe_cppop_2e_and11;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh2_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh2;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and23_count = 0;
  unsigned int llvm_cbe_cppop_2e_and23;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step4_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step4;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and15_count = 0;
  unsigned int llvm_cbe_cppop_2e_and15;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh6_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh6;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and27_count = 0;
  unsigned int llvm_cbe_cppop_2e_and27;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step8_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step8;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and19_count = 0;
  unsigned int llvm_cbe_cppop_2e_and19;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh10_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh10;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and211_count = 0;
  unsigned int llvm_cbe_cppop_2e_and211;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step12_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step12;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and113_count = 0;
  unsigned int llvm_cbe_cppop_2e_and113;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_sh14_count = 0;
  unsigned int llvm_cbe_ctpop_2e_sh14;
  static  unsigned long long aesl_llvm_cbe_cppop_2e_and215_count = 0;
  unsigned int llvm_cbe_cppop_2e_and215;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_step16_count = 0;
  unsigned int llvm_cbe_ctpop_2e_step16;
  static  unsigned long long aesl_llvm_cbe_ctpop_2e_part_count = 0;
  unsigned int llvm_cbe_ctpop_2e_part;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_hamming_weight\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and1 = and i32 %%code, 143165576 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and1_count);
  llvm_cbe_cppop_2e_and1 = (unsigned int )llvm_cbe_code & 1431655765u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and1 = 0x%X\n", llvm_cbe_cppop_2e_and1);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh = lshr i32 %%code,  for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh_count);
  llvm_cbe_ctpop_2e_sh = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_code&4294967295ull)) >> ((unsigned int )(1u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and2 = and i32 %%ctpop.sh, 143165576 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and2_count);
  llvm_cbe_cppop_2e_and2 = (unsigned int )llvm_cbe_ctpop_2e_sh & 1431655765u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and2 = 0x%X\n", llvm_cbe_cppop_2e_and2);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step = add i32 %%cppop.and1, %%cppop.and for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_step_count);
  llvm_cbe_ctpop_2e_step = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and1&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and11 = and i32 %%ctpop.step, 85899345 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and11_count);
  llvm_cbe_cppop_2e_and11 = (unsigned int )llvm_cbe_ctpop_2e_step & 858993459u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and11 = 0x%X\n", llvm_cbe_cppop_2e_and11);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh2 = lshr i32 %%ctpop.step,  for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh2_count);
  llvm_cbe_ctpop_2e_sh2 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step&4294967295ull)) >> ((unsigned int )(2u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh2 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and23 = and i32 %%ctpop.sh2, 85899345 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and23_count);
  llvm_cbe_cppop_2e_and23 = (unsigned int )llvm_cbe_ctpop_2e_sh2 & 858993459u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and23 = 0x%X\n", llvm_cbe_cppop_2e_and23);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step4 = add i32 %%cppop.and11, %%cppop.and2 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_step4_count);
  llvm_cbe_ctpop_2e_step4 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and11&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and23&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step4 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and15 = and i32 %%ctpop.step4, 25264513 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and15_count);
  llvm_cbe_cppop_2e_and15 = (unsigned int )llvm_cbe_ctpop_2e_step4 & 252645135u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and15 = 0x%X\n", llvm_cbe_cppop_2e_and15);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh6 = lshr i32 %%ctpop.step4,  for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh6_count);
  llvm_cbe_ctpop_2e_sh6 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step4&4294967295ull)) >> ((unsigned int )(4u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh6 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh6&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and27 = and i32 %%ctpop.sh6, 25264513 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and27_count);
  llvm_cbe_cppop_2e_and27 = (unsigned int )llvm_cbe_ctpop_2e_sh6 & 252645135u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and27 = 0x%X\n", llvm_cbe_cppop_2e_and27);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step8 = add i32 %%cppop.and15, %%cppop.and2 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_step8_count);
  llvm_cbe_ctpop_2e_step8 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and15&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and27&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step8 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step8&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and19 = and i32 %%ctpop.step8, 1671193 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and19_count);
  llvm_cbe_cppop_2e_and19 = (unsigned int )llvm_cbe_ctpop_2e_step8 & 16711935u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and19 = 0x%X\n", llvm_cbe_cppop_2e_and19);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh10 = lshr i32 %%ctpop.step8,  for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh10_count);
  llvm_cbe_ctpop_2e_sh10 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step8&4294967295ull)) >> ((unsigned int )(8u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh10 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and211 = and i32 %%ctpop.sh10, 1671193 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and211_count);
  llvm_cbe_cppop_2e_and211 = (unsigned int )llvm_cbe_ctpop_2e_sh10 & 16711935u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and211 = 0x%X\n", llvm_cbe_cppop_2e_and211);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step12 = add i32 %%cppop.and19, %%cppop.and21 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_step12_count);
  llvm_cbe_ctpop_2e_step12 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and19&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and211&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step12 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and113 = and i32 %%ctpop.step12, 6553 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and113_count);
  llvm_cbe_cppop_2e_and113 = (unsigned int )llvm_cbe_ctpop_2e_step12 & 65535u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and113 = 0x%X\n", llvm_cbe_cppop_2e_and113);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.sh14 = lshr i32 %%ctpop.step12, 1 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_sh14_count);
  llvm_cbe_ctpop_2e_sh14 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_ctpop_2e_step12&4294967295ull)) >> ((unsigned int )(16u&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\nctpop.sh14 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_sh14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%cppop.and215 = and i32 %%ctpop.sh14, 6553 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_cppop_2e_and215_count);
  llvm_cbe_cppop_2e_and215 = (unsigned int )llvm_cbe_ctpop_2e_sh14 & 65535u;
if (AESL_DEBUG_TRACE)
printf("\ncppop.and215 = 0x%X\n", llvm_cbe_cppop_2e_and215);
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.step16 = add i32 %%cppop.and113, %%cppop.and21 for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_step16_count);
  llvm_cbe_ctpop_2e_step16 = (unsigned int )((unsigned int )(llvm_cbe_cppop_2e_and113&4294967295ull)) + ((unsigned int )(llvm_cbe_cppop_2e_and215&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.step16 = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_step16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%ctpop.part = add i32 %%ctpop.step16,  for 0x%I64xth hint within @aesl_internal_hamming_weight  --> \n", ++aesl_llvm_cbe_ctpop_2e_part_count);
  llvm_cbe_ctpop_2e_part = (unsigned int )((unsigned int )(llvm_cbe_ctpop_2e_step16&4294967295ull)) + ((unsigned int )(0u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nctpop.part = 0x%X\n", ((unsigned int )(llvm_cbe_ctpop_2e_part&4294967295ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_hamming_weight}\n");
  return llvm_cbe_ctpop_2e_part;
}

