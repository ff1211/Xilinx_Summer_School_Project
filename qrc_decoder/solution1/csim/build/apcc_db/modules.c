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
typedef struct l_struct_OC_scanner l_struct_OC_scanner;

/* Structure contents */
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
extern  char pattern_alignment_pos[41][8];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void next_bit(l_struct_OC_scanner *llvm_cbe_scanner);
static signed int aesl_internal_is_data(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_i,  char llvm_cbe_j);
void skip_bits(l_struct_OC_scanner *llvm_cbe_scanner, signed long long llvm_cbe_n);
unsigned char mask( char llvm_cbe_m, signed long long llvm_cbe_i, signed long long llvm_cbe_j);
unsigned char mask_if_content(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m, signed long long llvm_cbe_i, signed long long llvm_cbe_j);
signed int mask_grade(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m);
void mask_apply(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m);
unsigned char get_codeword(l_struct_OC_scanner *llvm_cbe_scanner);
void put_codeword(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_w);


/* Global Variable Definitions and Initialization */


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

void next_bit(l_struct_OC_scanner *llvm_cbe_scanner) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  signed long long *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  signed long long *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  unsigned long long llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  unsigned long long llvm_cbe_tmp__20__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned long long llvm_cbe_storemerge2;
  unsigned long long llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned char llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @next_bit\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 5, !dbg !9 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_scanner->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 6, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__3 = (signed long long *)(&llvm_cbe_scanner->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__4 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__5 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__4;   /* for PHI node */
  llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__2;   /* for PHI node */
  goto llvm_cbe_tmp__24;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__24:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%storemerge2, %%35 ], [ %%4, %%0  for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\nstoremerge2 = 0x%I64X",llvm_cbe_storemerge2);
printf("\n = 0x%I64X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = phi i64 [ %%36, %%35 ], [ %%2, %%0  for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__6 = (unsigned long long )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
printf("\n = 0x%I64X",llvm_cbe_tmp__20);
printf("\n = 0x%I64X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = and i64 %%storemerge23, 2, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__7 = (unsigned long long )llvm_cbe_storemerge23 & 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__25;
  } else {
    goto llvm_cbe_tmp__26;
  }

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = phi i64 [ %%22, %%21 ], [ %%7, %%19 ], [ %%33, %%32 ], [ %%7, %%30  for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__20 = (unsigned long long )llvm_cbe_tmp__20__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__20);
printf("\n = 0x%I64X",llvm_cbe_tmp__13);
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
printf("\n = 0x%I64X",llvm_cbe_tmp__18);
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i64 [ %%23, %%21 ], [ %%20, %%19 ], [ %%34, %%32 ], [ %%31, %%30  for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned long long )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%I64X",llvm_cbe_storemerge2);
printf("\n = 0x%I64X",llvm_cbe_tmp__14);
printf("\n = 0x%I64X",llvm_cbe_tmp__12);
printf("\n = 0x%I64X",llvm_cbe_tmp__19);
printf("\n = 0x%I64X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = trunc i64 %%36 to i8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__21 = (unsigned char )((unsigned char )llvm_cbe_tmp__20&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = trunc i64 %%storemerge2 to i8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__22 = (unsigned char )((unsigned char )llvm_cbe_storemerge2&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call fastcc i32 @aesl_internal_is_data(%%struct.scanner* %%scanner, i8 zeroext %%37, i8 zeroext %%38), !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__23 = (unsigned int ) /*tail*/ aesl_internal_is_data((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__21, llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__21);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__22);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
  if (((llvm_cbe_tmp__23&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_storemerge2;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe_tmp__24;
  } else {
    goto llvm_cbe_tmp__28;
  }

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i64 %%storemerge23, -1, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__12 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__12&18446744073709551615ull)));
  llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__6;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__12;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = and i64 %%storemerge23, 1, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__8 = (unsigned long long )llvm_cbe_storemerge23 & 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i1 %%12 to i64, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__9 = (unsigned long long )((unsigned long long )(bool )(((unsigned long long )llvm_cbe_storemerge23&18446744073709551615ULL) < ((unsigned long long )6ull&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
  if (((llvm_cbe_tmp__8&18446744073709551615ULL) == (llvm_cbe_tmp__9&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__29;
  } else {
    goto llvm_cbe_tmp__30;
  }

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%5, align 8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__10 = (unsigned long long )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%16, -1, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__6&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__11&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__31;
  } else {
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%7, 1, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__13 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%storemerge23, 1, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__14 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__14&18446744073709551615ull)));
  llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__13;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__14;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add i64 %%storemerge23, -1, !dbg !12 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__17 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)));
  llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__6;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__17;   /* for PHI node */
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__26:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = and i64 %%storemerge23, 1, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__15 = (unsigned long long )llvm_cbe_storemerge23 & 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i1 %%26 to i64, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__16 = (unsigned long long )((unsigned long long )(bool )(((unsigned long long )llvm_cbe_storemerge23&18446744073709551615ULL) < ((unsigned long long )6ull&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%28, %%29, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_tmp__15&18446744073709551615ULL) == (llvm_cbe_tmp__16&18446744073709551615ULL)) | ((llvm_cbe_tmp__6&18446744073709551615ULL) == (0ull&18446744073709551615ULL)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe_tmp__32;
  } else {
    goto llvm_cbe_tmp__33;
  }

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add i64 %%7, -1, !dbg !11 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__18 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__6&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__18&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%storemerge23, 1, !dbg !12 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
  llvm_cbe_tmp__20__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__18;   /* for PHI node */
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__19;   /* for PHI node */
  goto llvm_cbe_tmp__27;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%36, i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_97_count);
  *llvm_cbe_tmp__1 = llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%storemerge2, i64* %%3, align 8, !dbg !10 for 0x%I64xth hint within @next_bit  --> \n", ++aesl_llvm_cbe_98_count);
  *llvm_cbe_tmp__3 = llvm_cbe_storemerge2;
if (AESL_DEBUG_TRACE)
printf("\nstoremerge2 = 0x%I64X\n", llvm_cbe_storemerge2);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @next_bit}\n");
  return;
}


static signed int aesl_internal_is_data(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_i,  char llvm_cbe_j) {
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
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
  signed long long *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  signed int *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned char llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned char llvm_cbe_tmp__54;
  unsigned char llvm_cbe_tmp__54__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge10_2e_rec_count = 0;
  unsigned long long llvm_cbe_storemerge10_2e_rec;
  unsigned long long llvm_cbe_storemerge10_2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_phitmp7_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  bool llvm_cbe_tmp__58;
  bool llvm_cbe_tmp__58__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec15_count = 0;
  unsigned long long llvm_cbe__2e_rec15;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
   char *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  unsigned char llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond3_count = 0;
  bool llvm_cbe_or_2e_cond3;
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
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned char llvm_cbe_tmp__62;
  unsigned char llvm_cbe_tmp__62__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge18_2e_rec_count = 0;
  unsigned long long llvm_cbe_storemerge18_2e_rec;
  unsigned long long llvm_cbe_storemerge18_2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_phitmp_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  bool llvm_cbe_tmp__66;
  bool llvm_cbe_tmp__66__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
   char *llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  unsigned char llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond4_count = 0;
  bool llvm_cbe_or_2e_cond4;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa916_count = 0;
  bool llvm_cbe__2e_lcssa916;
  bool llvm_cbe__2e_lcssa916__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  bool llvm_cbe__2e_lcssa;
  bool llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_phitmp_count = 0;
  bool llvm_cbe__2e_phitmp;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  unsigned int llvm_cbe_tmp__70;
  unsigned int llvm_cbe_tmp__70__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_is_data\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__34 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__35 = (unsigned long long )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
  if ((((unsigned char )llvm_cbe_i&255U) < ((unsigned char )((unsigned char )9)&255U))) {
    goto llvm_cbe_tmp__71;
  } else {
    goto llvm_cbe_tmp__72;
  }

llvm_cbe_tmp__71:
  if ((((unsigned char )llvm_cbe_j&255U) < ((unsigned char )((unsigned char )9)&255U))) {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  } else {
    goto llvm_cbe_tmp__74;
  }

llvm_cbe_tmp__74:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%j to i64, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__36 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_j&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%2, -8, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__37 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__37&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__36&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__37&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__72;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__72:
  if ((((unsigned char )llvm_cbe_j&255U) < ((unsigned char )((unsigned char )9)&255U))) {
    goto llvm_cbe_tmp__75;
  } else {
    goto llvm_cbe_tmp__76;
  }

llvm_cbe_tmp__75:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i8 %%i to i64, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__38 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%2, -8, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__39 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__38&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__39&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__76;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 2, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__40 = (signed int *)(&llvm_cbe_scanner->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i32* %%17, align 4, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__41 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
  if ((((signed int )llvm_cbe_tmp__41) > ((signed int )6u))) {
    goto llvm_cbe_tmp__77;
  } else {
    goto llvm_cbe_tmp__78;
  }

llvm_cbe_tmp__77:
  if ((((unsigned char )llvm_cbe_i&255U) < ((unsigned char )((unsigned char )6)&255U))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__79:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i8 %%j to i64, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_j&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%2, -11, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__43 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551605ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__43&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__42&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__43&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__80;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__80:
  if ((((unsigned char )llvm_cbe_j&255U) < ((unsigned char )((unsigned char )6)&255U))) {
    goto llvm_cbe_tmp__81;
  } else {
    goto llvm_cbe_tmp__82;
  }

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = zext i8 %%i to i64, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__44 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%2, -11, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__45 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551605ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__45&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__44&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__45&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__82;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__82:
  goto llvm_cbe_tmp__78;

llvm_cbe_tmp__78:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%34, %%35, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_i&255U) == (((unsigned char )6)&255U)) | ((llvm_cbe_j&255U) == (((unsigned char )6)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  } else {
    goto llvm_cbe_tmp__83;
  }

llvm_cbe_tmp__83:
  if ((((unsigned char )llvm_cbe_i&255U) < ((unsigned char )((unsigned char )9)&255U))) {
    goto llvm_cbe_tmp__84;
  } else {
    goto llvm_cbe_tmp__85;
  }

llvm_cbe_tmp__84:
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = zext i8 %%j to i64, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_j&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%2, -10, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__47 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551606ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__47&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__46&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__47&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__85;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__85:
  if ((((unsigned char )llvm_cbe_j&255U) < ((unsigned char )((unsigned char )9)&255U))) {
    goto llvm_cbe_tmp__86;
  } else {
    goto llvm_cbe_tmp__87;
  }

llvm_cbe_tmp__86:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = zext i8 %%i to i64, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__48 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%2, -10, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__35&18446744073709551615ull)) + ((unsigned long long )(18446744073709551606ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__48&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__49&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__87;
  } else {
    llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe_tmp__73;
  }

llvm_cbe_tmp__87:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = sext i32 %%18 to i64, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__50 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [41 x [8 x i8]]* @pattern_alignment_pos, i64 0, i64 %%47, i64 0, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__51 = ( char *)(&pattern_alignment_pos[(((signed long long )llvm_cbe_tmp__50))
#ifdef AESL_BC_SIM
 % 41
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__50) < 41)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i8* %%48, align 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__52 = (unsigned char )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
  if (((llvm_cbe_tmp__52&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa916__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    goto llvm_cbe__2e_critedge2;
  } else {
    goto llvm_cbe__2e_lr_2e_ph11;
  }

llvm_cbe__2e_lr_2e_ph11:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = zext i8 %%i to i32, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__53 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
  llvm_cbe_tmp__54__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__52;   /* for PHI node */
  llvm_cbe_storemerge10_2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__88;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__88:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = phi i8 [ %%49, %%.lr.ph11 ], [ %%62, %%59  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__54 = (unsigned char )llvm_cbe_tmp__54__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__54);
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__60);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge10.rec = phi i64 [ 0, %%.lr.ph11 ], [ %%.rec15, %%59  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_storemerge10_2e_rec_count);
  llvm_cbe_storemerge10_2e_rec = (unsigned long long )llvm_cbe_storemerge10_2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10.rec = 0x%I64X",llvm_cbe_storemerge10_2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec15 = 0x%I64X",llvm_cbe__2e_rec15);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = zext i8 %%53 to i32, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__54&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add nsw i32 %%54, -2, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) + ((unsigned int )(4294967294u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__56) > ((signed int )llvm_cbe_tmp__53))) {
    llvm_cbe_tmp__58__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    goto llvm_cbe_tmp__89;
  } else {
    goto llvm_cbe_tmp__90;
  }

llvm_cbe_tmp__89:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = phi i1 [ true, %%52 ], [ %%phitmp7, %%57 ], !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__58 = (bool )((llvm_cbe_tmp__58__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__58);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec15 = add i64 %%storemerge10.rec, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe__2e_rec15_count);
  llvm_cbe__2e_rec15 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge10_2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec15 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec15&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds [41 x [8 x i8]]* @pattern_alignment_pos, i64 0, i64 %%47, i64 %%.rec15, !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__59 = ( char *)(&pattern_alignment_pos[(((signed long long )llvm_cbe_tmp__50))
#ifdef AESL_BC_SIM
 % 41
#endif
][(((signed long long )llvm_cbe__2e_rec15))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
printf("\n.rec15 = 0x%I64X",((signed long long )llvm_cbe__2e_rec15));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__50) < 41)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe__2e_rec15) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i8* %%61, align 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_226_count);
  llvm_cbe_tmp__60 = (unsigned char )*llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond3 = and i1 %%63, %%6 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_or_2e_cond3_count);
  llvm_cbe_or_2e_cond3 = (bool )((((llvm_cbe_tmp__60&255U) != (((unsigned char )0)&255U)) & llvm_cbe_tmp__58)&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond3 = 0x%X\n", llvm_cbe_or_2e_cond3);
  if (llvm_cbe_or_2e_cond3) {
    llvm_cbe_tmp__54__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__60;   /* for PHI node */
    llvm_cbe_storemerge10_2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec15;   /* for PHI node */
    goto llvm_cbe_tmp__88;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__90:
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%54, 2, !dbg !11 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
  llvm_cbe_tmp__58__PHI_TEMPORARY = (bool )(((unsigned int )llvm_cbe_tmp__53&4294967295U) > ((unsigned int )llvm_cbe_tmp__57&4294967295U));   /* for PHI node */
  goto llvm_cbe_tmp__89;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_critedge:
  if (((llvm_cbe_tmp__52&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe__2e_lcssa916__PHI_TEMPORARY = (bool )llvm_cbe_tmp__58;   /* for PHI node */
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    goto llvm_cbe__2e_critedge2;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i8 %%j to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__61 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_j&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
  llvm_cbe_tmp__62__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__52;   /* for PHI node */
  llvm_cbe_storemerge18_2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__91;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__91:
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = phi i8 [ %%49, %%.lr.ph ], [ %%75, %%72  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__62 = (unsigned char )llvm_cbe_tmp__62__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__62);
printf("\n = 0x%X",llvm_cbe_tmp__52);
printf("\n = 0x%X",llvm_cbe_tmp__68);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge18.rec = phi i64 [ 0, %%.lr.ph ], [ %%.rec, %%72  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_storemerge18_2e_rec_count);
  llvm_cbe_storemerge18_2e_rec = (unsigned long long )llvm_cbe_storemerge18_2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge18.rec = 0x%I64X",llvm_cbe_storemerge18_2e_rec);
printf("\n = 0x%I64X",0ull);
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = zext i8 %%66 to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__62&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = add nsw i32 %%67, -2, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(4294967294u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
  if ((((signed int )llvm_cbe_tmp__64) > ((signed int )llvm_cbe_tmp__61))) {
    llvm_cbe_tmp__66__PHI_TEMPORARY = (bool )1;   /* for PHI node */
    goto llvm_cbe_tmp__92;
  } else {
    goto llvm_cbe_tmp__93;
  }

llvm_cbe_tmp__92:
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = phi i1 [ true, %%65 ], [ %%phitmp, %%70 ], !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_251_count);
  llvm_cbe_tmp__66 = (bool )((llvm_cbe_tmp__66__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__66);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = add i64 %%storemerge18.rec, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge18_2e_rec&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds [41 x [8 x i8]]* @pattern_alignment_pos, i64 0, i64 %%47, i64 %%.rec, !dbg !13 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_252_count);
  llvm_cbe_tmp__67 = ( char *)(&pattern_alignment_pos[(((signed long long )llvm_cbe_tmp__50))
#ifdef AESL_BC_SIM
 % 41
#endif
][(((signed long long )llvm_cbe__2e_rec))
#ifdef AESL_BC_SIM
 % 8
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__50));
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__50) < 41)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe__2e_rec) < 8)) fprintf(stderr, "%s:%d: warning: Read access out of array 'pattern_alignment_pos' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = load i8* %%74, align 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__68 = (unsigned char )*llvm_cbe_tmp__67;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond4 = and i1 %%76, %%7 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_or_2e_cond4_count);
  llvm_cbe_or_2e_cond4 = (bool )((((llvm_cbe_tmp__68&255U) != (((unsigned char )0)&255U)) & llvm_cbe_tmp__66)&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond4 = 0x%X\n", llvm_cbe_or_2e_cond4);
  if (llvm_cbe_or_2e_cond4) {
    llvm_cbe_tmp__62__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__68;   /* for PHI node */
    llvm_cbe_storemerge18_2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec;   /* for PHI node */
    goto llvm_cbe_tmp__91;
  } else {
    llvm_cbe__2e_lcssa916__PHI_TEMPORARY = (bool )llvm_cbe_tmp__58;   /* for PHI node */
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (bool )llvm_cbe_tmp__66;   /* for PHI node */
    goto llvm_cbe__2e_critedge2;
  }

llvm_cbe_tmp__93:
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add nsw i32 %%67, 2, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_249_count);
  llvm_cbe_tmp__65 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__65&4294967295ull)));
  llvm_cbe_tmp__66__PHI_TEMPORARY = (bool )(((unsigned int )llvm_cbe_tmp__61&4294967295U) > ((unsigned int )llvm_cbe_tmp__65&4294967295U));   /* for PHI node */
  goto llvm_cbe_tmp__92;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_critedge2:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa916 = phi i1 [ %%60, %%.critedge ], [ %%60, %%72 ], [ true, %%46  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe__2e_lcssa916_count);
  llvm_cbe__2e_lcssa916 = (bool )((llvm_cbe__2e_lcssa916__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa916 = 0x%X",llvm_cbe__2e_lcssa916);
printf("\n = 0x%X",llvm_cbe_tmp__58);
printf("\n = 0x%X",llvm_cbe_tmp__58);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i1 [ true, %%.critedge ], [ %%73, %%72 ], [ true, %%46  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (bool )((llvm_cbe__2e_lcssa__PHI_TEMPORARY)&1);
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",1);
printf("\n = 0x%X",llvm_cbe_tmp__66);
printf("\n = 0x%X",1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.phitmp = or i1 %%.lcssa916, %%.lcssa, !dbg !12 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe__2e_phitmp_count);
  llvm_cbe__2e_phitmp = (bool )((llvm_cbe__2e_lcssa916 | llvm_cbe__2e_lcssa)&1);
if (AESL_DEBUG_TRACE)
printf("\n.phitmp = 0x%X\n", llvm_cbe__2e_phitmp);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = zext i1 %%.phitmp to i3 for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_265_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(bool )llvm_cbe__2e_phitmp&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
  llvm_cbe_tmp__70__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__69;   /* for PHI node */
  goto llvm_cbe_tmp__73;

llvm_cbe_tmp__73:
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = phi i32 [ %%77, %%.critedge2 ], [ 0, %%4 ], [ 0, %%6 ], [ 0, %%12 ], [ 0, %%22 ], [ 0, %%28 ], [ 0, %%33 ], [ 1, %%37 ], [ 1, %%42  for 0x%I64xth hint within @aesl_internal_is_data  --> \n", ++aesl_llvm_cbe_267_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__70__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__70);
printf("\n = 0x%X",llvm_cbe_tmp__69);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",1u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_is_data}\n");
  return llvm_cbe_tmp__70;
}


void skip_bits(l_struct_OC_scanner *llvm_cbe_scanner, signed long long llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned long long llvm_cbe__2e_in;
  unsigned long long llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @skip_bits\n");
  if (((llvm_cbe_n&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned long long )llvm_cbe_n;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i64 [ %%2, %%.lr.ph ], [ %%n, %%0  for 0x%I64xth hint within @skip_bits  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned long long )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%I64X",llvm_cbe__2e_in);
printf("\n = 0x%I64X",llvm_cbe_tmp__94);
printf("\nn = 0x%I64X",llvm_cbe_n);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i64 %%.in, -1, !dbg !10 for 0x%I64xth hint within @skip_bits  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_in&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !9 for 0x%I64xth hint within @skip_bits  --> \n", ++aesl_llvm_cbe_277_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
  if (((llvm_cbe_tmp__94&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__94;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @skip_bits}\n");
  return;
}


unsigned char mask( char llvm_cbe_m, signed long long llvm_cbe_i, signed long long llvm_cbe_j) {
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  unsigned char llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  unsigned char llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  unsigned char llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned char llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  unsigned char llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned char llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned long long llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  unsigned char llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned char llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  unsigned char llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  unsigned char llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned char llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  unsigned long long llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned char llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  unsigned char llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  unsigned char llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  unsigned long long llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  unsigned char llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned char llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned char llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned char llvm_cbe_tmp__132;
  unsigned char llvm_cbe_tmp__132__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mask\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i8 %%m to i32, !dbg !11 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__95 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_m&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
  switch (((unsigned int )(llvm_cbe_tmp__95&4294967295ull))) {
  default:
    llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe_tmp__133;
;
  case ((unsigned int )(0u&4294967295ull)):
    goto llvm_cbe_tmp__134;
    break;
  case ((unsigned int )(1u&4294967295ull)):
    goto llvm_cbe_tmp__135;
  case ((unsigned int )(2u&4294967295ull)):
    goto llvm_cbe_tmp__136;
  case ((unsigned int )(3u&4294967295ull)):
    goto llvm_cbe_tmp__137;
  case ((unsigned int )(4u&4294967295ull)):
    goto llvm_cbe_tmp__138;
  case ((unsigned int )(5u&4294967295ull)):
    goto llvm_cbe_tmp__139;
  case ((unsigned int )(6u&4294967295ull)):
    goto llvm_cbe_tmp__140;
  case ((unsigned int )(7u&4294967295ull)):
    goto llvm_cbe_tmp__141;
  }
llvm_cbe_tmp__134:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_307_count);
  llvm_cbe_tmp__96 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = trunc i64 %%3 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_308_count);
  llvm_cbe_tmp__97 = (unsigned char )((unsigned char )llvm_cbe_tmp__96&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = and i8 %%4, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_309_count);
  llvm_cbe_tmp__98 = (unsigned char )((unsigned char )(llvm_cbe_tmp__97 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = xor i8 %%5, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_310_count);
  llvm_cbe_tmp__99 = (unsigned char )((unsigned char )(llvm_cbe_tmp__98 ^ ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__99;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__135:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = trunc i64 %%i to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__100 = (unsigned char )((unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = and i8 %%8, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__101 = (unsigned char )((unsigned char )(llvm_cbe_tmp__100 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = xor i8 %%9, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__102 = (unsigned char )((unsigned char )(llvm_cbe_tmp__101 ^ ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__102;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__136:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = urem i64 %%j, 3, !dbg !11 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__103 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) % ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__103&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = zext i1 %%13 to i8, !dbg !11 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_318_count);
  llvm_cbe_tmp__104 = (unsigned char )((unsigned char )(bool )((llvm_cbe_tmp__103&18446744073709551615ULL) == (0ull&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__104;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__137:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = add i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_320_count);
  llvm_cbe_tmp__105 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = urem i64 %%16, 3, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_321_count);
  llvm_cbe_tmp__106 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)) % ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__106&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = zext i1 %%18 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__107 = (unsigned char )((unsigned char )(bool )((llvm_cbe_tmp__106&18446744073709551615ULL) == (0ull&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__107;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__138:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = lshr i64 %%i, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__108 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_i&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = udiv i64 %%j, 3, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) / ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i64 %%22, %%21, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__110 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__110&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = trunc i64 %%23 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__111 = (unsigned char )((unsigned char )llvm_cbe_tmp__110&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = and i8 %%24, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__112 = (unsigned char )((unsigned char )(llvm_cbe_tmp__111 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = xor i8 %%25, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__113 = (unsigned char )((unsigned char )(llvm_cbe_tmp__112 ^ ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__113);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__113;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__139:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = mul i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_332_count);
  llvm_cbe_tmp__114 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = and i64 %%28, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_333_count);
  llvm_cbe_tmp__115 = (unsigned long long )llvm_cbe_tmp__114 & 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = urem i64 %%28, 3, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_334_count);
  llvm_cbe_tmp__116 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__114&18446744073709551615ull)) % ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__116&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sub i64 0, %%30, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__117 = (unsigned long long )-(llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__117&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = zext i1 %%32 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__118 = (unsigned char )((unsigned char )(bool )((llvm_cbe_tmp__115&18446744073709551615ULL) == (llvm_cbe_tmp__117&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__118);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__118;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__140:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = mul i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__119 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = urem i64 %%35, 3, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__120 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull)) % ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__120&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%36, %%35, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__120&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__119&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__121&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = trunc i64 %%37 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__122 = (unsigned char )((unsigned char )llvm_cbe_tmp__121&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = and i8 %%38, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__123 = (unsigned char )((unsigned char )(llvm_cbe_tmp__122 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = xor i8 %%39, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_344_count);
  llvm_cbe_tmp__124 = (unsigned char )((unsigned char )(llvm_cbe_tmp__123 ^ ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__124;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__141:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = mul i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__125 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__125&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = urem i64 %%42, 3, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__126 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__125&18446744073709551615ull)) % ((unsigned long long )(3ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__126&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = add i64 %%j, %%i, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__127 = (unsigned long long )((unsigned long long )(llvm_cbe_j&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__127&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i64 %%44, %%43, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__128 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__127&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__126&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__128&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = trunc i64 %%45 to i8, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__129 = (unsigned char )((unsigned char )llvm_cbe_tmp__128&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = and i8 %%46, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__130 = (unsigned char )((unsigned char )(llvm_cbe_tmp__129 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = xor i8 %%47, 1, !dbg !10 for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__131 = (unsigned char )((unsigned char )(llvm_cbe_tmp__130 ^ ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__131);
  llvm_cbe_tmp__132__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__131;   /* for PHI node */
  goto llvm_cbe_tmp__133;

llvm_cbe_tmp__133:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = phi i8 [ %%48, %%41 ], [ %%40, %%34 ], [ %%33, %%27 ], [ %%26, %%20 ], [ %%19, %%15 ], [ %%14, %%11 ], [ %%10, %%7 ], [ %%6, %%2 ], [ 0, %%0  for 0x%I64xth hint within @mask  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__132 = (unsigned char )llvm_cbe_tmp__132__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__132);
printf("\n = 0x%X",llvm_cbe_tmp__131);
printf("\n = 0x%X",llvm_cbe_tmp__124);
printf("\n = 0x%X",llvm_cbe_tmp__118);
printf("\n = 0x%X",llvm_cbe_tmp__113);
printf("\n = 0x%X",llvm_cbe_tmp__107);
printf("\n = 0x%X",llvm_cbe_tmp__104);
printf("\n = 0x%X",llvm_cbe_tmp__102);
printf("\n = 0x%X",llvm_cbe_tmp__99);
printf("\n = 0x%X",((unsigned char )0));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mask}\n");
  return llvm_cbe_tmp__132;
}


unsigned char mask_if_content(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m, signed long long llvm_cbe_i, signed long long llvm_cbe_j) {
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  signed long long *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
   char **llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
   char *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  unsigned char llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  unsigned char llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned char llvm_cbe_tmp__151;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned int llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  unsigned char llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  unsigned char llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  unsigned char llvm_cbe_tmp__155;
  unsigned char llvm_cbe_tmp__155__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mask_if_content\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__142 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__143 = (unsigned long long )*llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__143);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = mul i64 %%2, %%i, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__144 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__143&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_i&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%3, %%j, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__145 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__144&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_j&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__145&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__146 = ( char **)(&llvm_cbe_scanner->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8** %%5, align 8, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__147 = ( char *)*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i8* %%6, i64 %%4, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_376_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_tmp__147[(((signed long long )llvm_cbe_tmp__145))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !9 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = trunc i64 %%i to i8, !dbg !10 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_381_count);
  llvm_cbe_tmp__150 = (unsigned char )((unsigned char )llvm_cbe_i&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i64 %%j to i8, !dbg !10 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__151 = (unsigned char )((unsigned char )llvm_cbe_j&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call fastcc i32 @aesl_internal_is_data(%%struct.scanner* %%scanner, i8 zeroext %%9, i8 zeroext %%10), !dbg !10 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__152 = (unsigned int ) /*tail*/ aesl_internal_is_data((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__150, llvm_cbe_tmp__151);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__150);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__151);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__152);
}
  if (((llvm_cbe_tmp__152&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__149;   /* for PHI node */
    goto llvm_cbe_tmp__156;
  } else {
    goto llvm_cbe_tmp__157;
  }

llvm_cbe_tmp__157:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call zeroext i8 @mask(i8 zeroext %%m, i64 %%i, i64 %%j), !dbg !10 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_386_count);
  llvm_cbe_tmp__153 = (unsigned char ) /*tail*/ mask(llvm_cbe_m, llvm_cbe_i, llvm_cbe_j);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument i = 0x%I64X",llvm_cbe_i);
printf("\nArgument j = 0x%I64X",llvm_cbe_j);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__153);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = xor i8 %%14, %%8, !dbg !10 for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_387_count);
  llvm_cbe_tmp__154 = (unsigned char )((unsigned char )(llvm_cbe_tmp__153 ^ llvm_cbe_tmp__149));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
  llvm_cbe_tmp__155__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__154;   /* for PHI node */
  goto llvm_cbe_tmp__156;

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i8 [ %%8, %%0 ], [ %%15, %%13  for 0x%I64xth hint within @mask_if_content  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__155 = (unsigned char )llvm_cbe_tmp__155__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__155);
printf("\n = 0x%X",llvm_cbe_tmp__149);
printf("\n = 0x%X",llvm_cbe_tmp__154);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mask_if_content}\n");
  return llvm_cbe_tmp__155;
}


signed int mask_grade(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m) {
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
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  signed long long *llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;
  static  unsigned long long aesl_llvm_cbe_488_count = 0;
  static  unsigned long long aesl_llvm_cbe_489_count = 0;
  static  unsigned long long aesl_llvm_cbe_490_count = 0;
  static  unsigned long long aesl_llvm_cbe_491_count = 0;
  static  unsigned long long aesl_llvm_cbe_492_count = 0;
  static  unsigned long long aesl_llvm_cbe_493_count = 0;
  static  unsigned long long aesl_llvm_cbe_494_count = 0;
  static  unsigned long long aesl_llvm_cbe_495_count = 0;
  static  unsigned long long aesl_llvm_cbe_496_count = 0;
  static  unsigned long long aesl_llvm_cbe_497_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge86_count = 0;
  unsigned long long llvm_cbe_storemerge86;
  unsigned long long llvm_cbe_storemerge86__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  unsigned int llvm_cbe_tmp__160;
  unsigned int llvm_cbe_tmp__160__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  static  unsigned long long aesl_llvm_cbe_522_count = 0;
  static  unsigned long long aesl_llvm_cbe_523_count = 0;
  static  unsigned long long aesl_llvm_cbe_524_count = 0;
  static  unsigned long long aesl_llvm_cbe_525_count = 0;
  static  unsigned long long aesl_llvm_cbe_526_count = 0;
  static  unsigned long long aesl_llvm_cbe_527_count = 0;
  static  unsigned long long aesl_llvm_cbe_528_count = 0;
  static  unsigned long long aesl_llvm_cbe_529_count = 0;
  static  unsigned long long aesl_llvm_cbe_530_count = 0;
  static  unsigned long long aesl_llvm_cbe_531_count = 0;
  static  unsigned long long aesl_llvm_cbe_532_count = 0;
  static  unsigned long long aesl_llvm_cbe_533_count = 0;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  static  unsigned long long aesl_llvm_cbe_547_count = 0;
  static  unsigned long long aesl_llvm_cbe_548_count = 0;
  static  unsigned long long aesl_llvm_cbe_549_count = 0;
  static  unsigned long long aesl_llvm_cbe_550_count = 0;
  static  unsigned long long aesl_llvm_cbe_551_count = 0;
  static  unsigned long long aesl_llvm_cbe_552_count = 0;
  static  unsigned long long aesl_llvm_cbe_553_count = 0;
  static  unsigned long long aesl_llvm_cbe_554_count = 0;
  static  unsigned long long aesl_llvm_cbe_555_count = 0;
  static  unsigned long long aesl_llvm_cbe_556_count = 0;
  static  unsigned long long aesl_llvm_cbe_557_count = 0;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond89_count = 0;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1071_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge1071_2e_us;
  unsigned long long llvm_cbe_storemerge1071_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  unsigned long long llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge177_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge177_2e_us;
  unsigned long long llvm_cbe_storemerge177_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1181_count = 0;
  unsigned long long llvm_cbe_storemerge1181;
  unsigned long long llvm_cbe_storemerge1181__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  unsigned int llvm_cbe_tmp__163;
  unsigned int llvm_cbe_tmp__163__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  unsigned char llvm_cbe_tmp__164;
  unsigned char llvm_cbe_tmp__164__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  unsigned long long llvm_cbe_tmp__165;
  unsigned long long llvm_cbe_tmp__165__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  unsigned char llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  unsigned int llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  unsigned long long llvm_cbe_tmp__169__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  unsigned char llvm_cbe_tmp__170;
  unsigned char llvm_cbe_tmp__170__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  unsigned int llvm_cbe_tmp__171;
  unsigned int llvm_cbe_tmp__171__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond102_count = 0;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned long long llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond103_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa76_2e_ph_count = 0;
  unsigned int llvm_cbe__2e_lcssa76_2e_ph;
  unsigned int llvm_cbe__2e_lcssa76_2e_ph__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  static  unsigned long long aesl_llvm_cbe_666_count = 0;
  static  unsigned long long aesl_llvm_cbe_667_count = 0;
  static  unsigned long long aesl_llvm_cbe_668_count = 0;
  static  unsigned long long aesl_llvm_cbe_669_count = 0;
  static  unsigned long long aesl_llvm_cbe_670_count = 0;
  static  unsigned long long aesl_llvm_cbe_671_count = 0;
  static  unsigned long long aesl_llvm_cbe_672_count = 0;
  static  unsigned long long aesl_llvm_cbe_673_count = 0;
  static  unsigned long long aesl_llvm_cbe_674_count = 0;
  static  unsigned long long aesl_llvm_cbe_675_count = 0;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  static  unsigned long long aesl_llvm_cbe_684_count = 0;
  static  unsigned long long aesl_llvm_cbe_685_count = 0;
  static  unsigned long long aesl_llvm_cbe_686_count = 0;
  static  unsigned long long aesl_llvm_cbe_687_count = 0;
  static  unsigned long long aesl_llvm_cbe_688_count = 0;
  static  unsigned long long aesl_llvm_cbe_689_count = 0;
  static  unsigned long long aesl_llvm_cbe_690_count = 0;
  static  unsigned long long aesl_llvm_cbe_691_count = 0;
  static  unsigned long long aesl_llvm_cbe_692_count = 0;
  static  unsigned long long aesl_llvm_cbe_693_count = 0;
  static  unsigned long long aesl_llvm_cbe_694_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
  static  unsigned long long aesl_llvm_cbe_714_count = 0;
  static  unsigned long long aesl_llvm_cbe_715_count = 0;
  static  unsigned long long aesl_llvm_cbe_716_count = 0;
  static  unsigned long long aesl_llvm_cbe_717_count = 0;
  static  unsigned long long aesl_llvm_cbe_718_count = 0;
  static  unsigned long long aesl_llvm_cbe_719_count = 0;
  static  unsigned long long aesl_llvm_cbe_720_count = 0;
  static  unsigned long long aesl_llvm_cbe_721_count = 0;
  static  unsigned long long aesl_llvm_cbe_722_count = 0;
  static  unsigned long long aesl_llvm_cbe_723_count = 0;
  static  unsigned long long aesl_llvm_cbe_724_count = 0;
  static  unsigned long long aesl_llvm_cbe_725_count = 0;
  static  unsigned long long aesl_llvm_cbe_726_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  unsigned long long llvm_cbe_tmp__177__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa76104_count = 0;
  unsigned int llvm_cbe__2e_lcssa76104;
  unsigned int llvm_cbe__2e_lcssa76104__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge267_count = 0;
  unsigned long long llvm_cbe_storemerge267;
  unsigned long long llvm_cbe_storemerge267__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  unsigned int llvm_cbe_tmp__178;
  unsigned int llvm_cbe_tmp__178__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  static  unsigned long long aesl_llvm_cbe_750_count = 0;
  static  unsigned long long aesl_llvm_cbe_751_count = 0;
  static  unsigned long long aesl_llvm_cbe_752_count = 0;
  static  unsigned long long aesl_llvm_cbe_753_count = 0;
  static  unsigned long long aesl_llvm_cbe_754_count = 0;
  static  unsigned long long aesl_llvm_cbe_755_count = 0;
  static  unsigned long long aesl_llvm_cbe_756_count = 0;
  static  unsigned long long aesl_llvm_cbe_757_count = 0;
  static  unsigned long long aesl_llvm_cbe_758_count = 0;
  static  unsigned long long aesl_llvm_cbe_759_count = 0;
  static  unsigned long long aesl_llvm_cbe_760_count = 0;
  static  unsigned long long aesl_llvm_cbe_761_count = 0;
  static  unsigned long long aesl_llvm_cbe_762_count = 0;
  unsigned long long llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa66_count = 0;
  unsigned int llvm_cbe__2e_lcssa66;
  unsigned int llvm_cbe__2e_lcssa66__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  static  unsigned long long aesl_llvm_cbe_772_count = 0;
  static  unsigned long long aesl_llvm_cbe_773_count = 0;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  static  unsigned long long aesl_llvm_cbe_778_count = 0;
  static  unsigned long long aesl_llvm_cbe_779_count = 0;
  static  unsigned long long aesl_llvm_cbe_780_count = 0;
  static  unsigned long long aesl_llvm_cbe_781_count = 0;
  static  unsigned long long aesl_llvm_cbe_782_count = 0;
  static  unsigned long long aesl_llvm_cbe_783_count = 0;
  static  unsigned long long aesl_llvm_cbe_784_count = 0;
  static  unsigned long long aesl_llvm_cbe_785_count = 0;
  static  unsigned long long aesl_llvm_cbe_786_count = 0;
  static  unsigned long long aesl_llvm_cbe_787_count = 0;
  static  unsigned long long aesl_llvm_cbe_788_count = 0;
  static  unsigned long long aesl_llvm_cbe_789_count = 0;
  static  unsigned long long aesl_llvm_cbe_790_count = 0;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  unsigned long long llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge961_count = 0;
  unsigned long long llvm_cbe_storemerge961;
  unsigned long long llvm_cbe_storemerge961__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  unsigned int llvm_cbe_tmp__181;
  unsigned int llvm_cbe_tmp__181__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  unsigned char llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  unsigned char llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  unsigned char llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  unsigned char llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond13_count = 0;
  bool llvm_cbe_or_2e_cond13;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  unsigned int llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_27_count = 0;
  unsigned int llvm_cbe__2e_27;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
  static  unsigned long long aesl_llvm_cbe_843_count = 0;
  static  unsigned long long aesl_llvm_cbe_844_count = 0;
  static  unsigned long long aesl_llvm_cbe_845_count = 0;
  static  unsigned long long aesl_llvm_cbe_846_count = 0;
  static  unsigned long long aesl_llvm_cbe_847_count = 0;
  static  unsigned long long aesl_llvm_cbe_848_count = 0;
  static  unsigned long long aesl_llvm_cbe_849_count = 0;
  static  unsigned long long aesl_llvm_cbe_850_count = 0;
  static  unsigned long long aesl_llvm_cbe_851_count = 0;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond98_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  static  unsigned long long aesl_llvm_cbe_863_count = 0;
  static  unsigned long long aesl_llvm_cbe_864_count = 0;
  static  unsigned long long aesl_llvm_cbe_865_count = 0;
  static  unsigned long long aesl_llvm_cbe_866_count = 0;
  static  unsigned long long aesl_llvm_cbe_867_count = 0;
  static  unsigned long long aesl_llvm_cbe_868_count = 0;
  static  unsigned long long aesl_llvm_cbe_869_count = 0;
  static  unsigned long long aesl_llvm_cbe_870_count = 0;
  static  unsigned long long aesl_llvm_cbe_871_count = 0;
  static  unsigned long long aesl_llvm_cbe_872_count = 0;
  static  unsigned long long aesl_llvm_cbe_873_count = 0;
  static  unsigned long long aesl_llvm_cbe_874_count = 0;
  static  unsigned long long aesl_llvm_cbe_875_count = 0;
  static  unsigned long long aesl_llvm_cbe_876_count = 0;
  static  unsigned long long aesl_llvm_cbe_877_count = 0;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond99_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge357_count = 0;
  unsigned long long llvm_cbe_storemerge357;
  unsigned long long llvm_cbe_storemerge357__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  unsigned int llvm_cbe_tmp__189;
  unsigned int llvm_cbe_tmp__189__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  static  unsigned long long aesl_llvm_cbe_916_count = 0;
  static  unsigned long long aesl_llvm_cbe_917_count = 0;
  static  unsigned long long aesl_llvm_cbe_918_count = 0;
  static  unsigned long long aesl_llvm_cbe_919_count = 0;
  static  unsigned long long aesl_llvm_cbe_920_count = 0;
  static  unsigned long long aesl_llvm_cbe_921_count = 0;
  static  unsigned long long aesl_llvm_cbe_922_count = 0;
  static  unsigned long long aesl_llvm_cbe_923_count = 0;
  static  unsigned long long aesl_llvm_cbe_924_count = 0;
  static  unsigned long long aesl_llvm_cbe_925_count = 0;
  static  unsigned long long aesl_llvm_cbe_926_count = 0;
  static  unsigned long long aesl_llvm_cbe_927_count = 0;
  static  unsigned long long aesl_llvm_cbe_928_count = 0;
  static  unsigned long long aesl_llvm_cbe_929_count = 0;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;
  static  unsigned long long aesl_llvm_cbe_936_count = 0;
  static  unsigned long long aesl_llvm_cbe_937_count = 0;
  static  unsigned long long aesl_llvm_cbe_938_count = 0;
  static  unsigned long long aesl_llvm_cbe_939_count = 0;
  static  unsigned long long aesl_llvm_cbe_940_count = 0;
  static  unsigned long long aesl_llvm_cbe_941_count = 0;
  static  unsigned long long aesl_llvm_cbe_942_count = 0;
  static  unsigned long long aesl_llvm_cbe_943_count = 0;
  static  unsigned long long aesl_llvm_cbe_944_count = 0;
  static  unsigned long long aesl_llvm_cbe_945_count = 0;
  static  unsigned long long aesl_llvm_cbe_946_count = 0;
  static  unsigned long long aesl_llvm_cbe_947_count = 0;
  static  unsigned long long aesl_llvm_cbe_948_count = 0;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
  unsigned long long llvm_cbe_tmp__190;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  unsigned long long llvm_cbe_tmp__191;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond91_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge741_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge741_2e_us;
  unsigned long long llvm_cbe_storemerge741_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  unsigned int llvm_cbe_tmp__192;
  unsigned int llvm_cbe_tmp__192__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  unsigned char llvm_cbe_tmp__193;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  unsigned long long llvm_cbe_tmp__194;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  unsigned char llvm_cbe_tmp__195;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  unsigned long long llvm_cbe_tmp__196;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  unsigned char llvm_cbe_tmp__197;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  unsigned long long llvm_cbe_tmp__198;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  unsigned char llvm_cbe_tmp__199;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  unsigned long long llvm_cbe_tmp__200;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  unsigned char llvm_cbe_tmp__201;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  unsigned long long llvm_cbe_tmp__202;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned char llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  unsigned long long llvm_cbe_tmp__204;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  unsigned char llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_notlhs_2e_us_count = 0;
  static  unsigned long long aesl_llvm_cbe_notrhs_2e_us_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond20_2e_not_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond20_2e_not_2e_us;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond21_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond21_2e_us;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond22_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond22_2e_us;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond23_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond23_2e_us;
  static  unsigned long long aesl_llvm_cbe__2e_not_2e_us_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond24_2e_not_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond24_2e_not_2e_us;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond25_2e_us_count = 0;
  bool llvm_cbe_or_2e_cond25_2e_us;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  unsigned int llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_29_2e_us_count = 0;
  unsigned int llvm_cbe__2e_29_2e_us;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond90_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge447_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge447_2e_us;
  unsigned long long llvm_cbe_storemerge447_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  unsigned int llvm_cbe_tmp__207;
  unsigned int llvm_cbe_tmp__207__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge851_count = 0;
  unsigned long long llvm_cbe_storemerge851;
  unsigned long long llvm_cbe_storemerge851__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  unsigned int llvm_cbe_tmp__208;
  unsigned int llvm_cbe_tmp__208__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  unsigned char llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  unsigned long long llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  unsigned char llvm_cbe_tmp__211;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  unsigned long long llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  unsigned char llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  unsigned long long llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  unsigned char llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  unsigned long long llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  unsigned char llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;
  unsigned long long llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  unsigned char llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  unsigned long long llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  unsigned char llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_notlhs30_count = 0;
  static  unsigned long long aesl_llvm_cbe_notrhs31_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond14_2e_not_count = 0;
  bool llvm_cbe_or_2e_cond14_2e_not;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond15_count = 0;
  bool llvm_cbe_or_2e_cond15;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond16_count = 0;
  bool llvm_cbe_or_2e_cond16;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond17_count = 0;
  bool llvm_cbe_or_2e_cond17;
  static  unsigned long long aesl_llvm_cbe__2e_not32_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond18_2e_not_count = 0;
  bool llvm_cbe_or_2e_cond18_2e_not;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond19_count = 0;
  bool llvm_cbe_or_2e_cond19;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  unsigned int llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_28_count = 0;
  unsigned int llvm_cbe__2e_28;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;
  static  unsigned long long aesl_llvm_cbe_1152_count = 0;
  static  unsigned long long aesl_llvm_cbe_1153_count = 0;
  static  unsigned long long aesl_llvm_cbe_1154_count = 0;
  static  unsigned long long aesl_llvm_cbe_1155_count = 0;
  static  unsigned long long aesl_llvm_cbe_1156_count = 0;
  static  unsigned long long aesl_llvm_cbe_1157_count = 0;
  static  unsigned long long aesl_llvm_cbe_1158_count = 0;
  static  unsigned long long aesl_llvm_cbe_1159_count = 0;
  static  unsigned long long aesl_llvm_cbe_1160_count = 0;
  static  unsigned long long aesl_llvm_cbe_1161_count = 0;
  static  unsigned long long aesl_llvm_cbe_1162_count = 0;
  static  unsigned long long aesl_llvm_cbe_1163_count = 0;
  static  unsigned long long aesl_llvm_cbe_1164_count = 0;
  static  unsigned long long aesl_llvm_cbe_1165_count = 0;
  static  unsigned long long aesl_llvm_cbe_1166_count = 0;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond96_count = 0;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa50_count = 0;
  unsigned int llvm_cbe__2e_lcssa50;
  unsigned int llvm_cbe__2e_lcssa50__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned long long llvm_cbe_tmp__223;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  static  unsigned long long aesl_llvm_cbe_1174_count = 0;
  static  unsigned long long aesl_llvm_cbe_1175_count = 0;
  static  unsigned long long aesl_llvm_cbe_1176_count = 0;
  static  unsigned long long aesl_llvm_cbe_1177_count = 0;
  static  unsigned long long aesl_llvm_cbe_1178_count = 0;
  static  unsigned long long aesl_llvm_cbe_1179_count = 0;
  static  unsigned long long aesl_llvm_cbe_1180_count = 0;
  static  unsigned long long aesl_llvm_cbe_1181_count = 0;
  static  unsigned long long aesl_llvm_cbe_1182_count = 0;
  static  unsigned long long aesl_llvm_cbe_1183_count = 0;
  static  unsigned long long aesl_llvm_cbe_1184_count = 0;
  static  unsigned long long aesl_llvm_cbe_1185_count = 0;
  static  unsigned long long aesl_llvm_cbe_1186_count = 0;
  static  unsigned long long aesl_llvm_cbe_1187_count = 0;
  static  unsigned long long aesl_llvm_cbe_1188_count = 0;
  static  unsigned long long aesl_llvm_cbe_1189_count = 0;
  static  unsigned long long aesl_llvm_cbe_1190_count = 0;
  static  unsigned long long aesl_llvm_cbe_1191_count = 0;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond97_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa46_count = 0;
  unsigned int llvm_cbe__2e_lcssa46;
  unsigned int llvm_cbe__2e_lcssa46__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1204_count = 0;
  static  unsigned long long aesl_llvm_cbe_1205_count = 0;
  static  unsigned long long aesl_llvm_cbe_1206_count = 0;
  static  unsigned long long aesl_llvm_cbe_1207_count = 0;
  static  unsigned long long aesl_llvm_cbe_1208_count = 0;
  static  unsigned long long aesl_llvm_cbe_1209_count = 0;
  static  unsigned long long aesl_llvm_cbe_1210_count = 0;
  static  unsigned long long aesl_llvm_cbe_1211_count = 0;
  static  unsigned long long aesl_llvm_cbe_1212_count = 0;
  static  unsigned long long aesl_llvm_cbe_1213_count = 0;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  static  unsigned long long aesl_llvm_cbe_1223_count = 0;
  static  unsigned long long aesl_llvm_cbe_1224_count = 0;
  static  unsigned long long aesl_llvm_cbe_1225_count = 0;
  static  unsigned long long aesl_llvm_cbe_1226_count = 0;
  static  unsigned long long aesl_llvm_cbe_1227_count = 0;
  static  unsigned long long aesl_llvm_cbe_1228_count = 0;
  static  unsigned long long aesl_llvm_cbe_1229_count = 0;
  static  unsigned long long aesl_llvm_cbe_1230_count = 0;
  static  unsigned long long aesl_llvm_cbe_1231_count = 0;
  static  unsigned long long aesl_llvm_cbe_1232_count = 0;
  static  unsigned long long aesl_llvm_cbe_1233_count = 0;
  static  unsigned long long aesl_llvm_cbe_1234_count = 0;
  static  unsigned long long aesl_llvm_cbe_1235_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  static  unsigned long long aesl_llvm_cbe_1239_count = 0;
  static  unsigned long long aesl_llvm_cbe_1240_count = 0;
  static  unsigned long long aesl_llvm_cbe_1241_count = 0;
  static  unsigned long long aesl_llvm_cbe_1242_count = 0;
  static  unsigned long long aesl_llvm_cbe_1243_count = 0;
  static  unsigned long long aesl_llvm_cbe_1244_count = 0;
  static  unsigned long long aesl_llvm_cbe_1245_count = 0;
  static  unsigned long long aesl_llvm_cbe_1246_count = 0;
  static  unsigned long long aesl_llvm_cbe_1247_count = 0;
  static  unsigned long long aesl_llvm_cbe_1248_count = 0;
  static  unsigned long long aesl_llvm_cbe_1249_count = 0;
  static  unsigned long long aesl_llvm_cbe_1250_count = 0;
  static  unsigned long long aesl_llvm_cbe_1251_count = 0;
  static  unsigned long long aesl_llvm_cbe_1252_count = 0;
  static  unsigned long long aesl_llvm_cbe_1253_count = 0;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond93_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge633_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge633_2e_us;
  unsigned long long llvm_cbe_storemerge633_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  unsigned long long llvm_cbe_tmp__225;
  unsigned long long llvm_cbe_tmp__225__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  unsigned char llvm_cbe_tmp__226;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  unsigned long long llvm_cbe_tmp__227;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_26_2e_us_count = 0;
  unsigned long long llvm_cbe__2e_26_2e_us;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  static  unsigned long long aesl_llvm_cbe_1285_count = 0;
  static  unsigned long long aesl_llvm_cbe_1286_count = 0;
  static  unsigned long long aesl_llvm_cbe_1287_count = 0;
  static  unsigned long long aesl_llvm_cbe_1288_count = 0;
  static  unsigned long long aesl_llvm_cbe_1289_count = 0;
  static  unsigned long long aesl_llvm_cbe_1290_count = 0;
  static  unsigned long long aesl_llvm_cbe_1291_count = 0;
  static  unsigned long long aesl_llvm_cbe_1292_count = 0;
  static  unsigned long long aesl_llvm_cbe_1293_count = 0;
  static  unsigned long long aesl_llvm_cbe_1294_count = 0;
  static  unsigned long long aesl_llvm_cbe_1295_count = 0;
  static  unsigned long long aesl_llvm_cbe_1296_count = 0;
  static  unsigned long long aesl_llvm_cbe_1297_count = 0;
  static  unsigned long long aesl_llvm_cbe_1298_count = 0;
  static  unsigned long long aesl_llvm_cbe_1299_count = 0;
  static  unsigned long long aesl_llvm_cbe_1300_count = 0;
  static  unsigned long long aesl_llvm_cbe_1301_count = 0;
  static  unsigned long long aesl_llvm_cbe_1302_count = 0;
  static  unsigned long long aesl_llvm_cbe_1303_count = 0;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond92_count = 0;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge536_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge536_2e_us;
  unsigned long long llvm_cbe_storemerge536_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  unsigned long long llvm_cbe_tmp__229;
  unsigned long long llvm_cbe_tmp__229__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  static  unsigned long long aesl_llvm_cbe_1320_count = 0;
  static  unsigned long long aesl_llvm_cbe_1321_count = 0;
  static  unsigned long long aesl_llvm_cbe_1322_count = 0;
  static  unsigned long long aesl_llvm_cbe_1323_count = 0;
  static  unsigned long long aesl_llvm_cbe_1324_count = 0;
  static  unsigned long long aesl_llvm_cbe_1325_count = 0;
  static  unsigned long long aesl_llvm_cbe_1326_count = 0;
  static  unsigned long long aesl_llvm_cbe_1327_count = 0;
  static  unsigned long long aesl_llvm_cbe_1328_count = 0;
  static  unsigned long long aesl_llvm_cbe_1329_count = 0;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge447_count = 0;
  unsigned long long llvm_cbe_storemerge447;
  unsigned long long llvm_cbe_storemerge447__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;
  static  unsigned long long aesl_llvm_cbe_1354_count = 0;
  static  unsigned long long aesl_llvm_cbe_1355_count = 0;
  static  unsigned long long aesl_llvm_cbe_1356_count = 0;
  static  unsigned long long aesl_llvm_cbe_1357_count = 0;
  static  unsigned long long aesl_llvm_cbe_1358_count = 0;
  static  unsigned long long aesl_llvm_cbe_1359_count = 0;
  static  unsigned long long aesl_llvm_cbe_1360_count = 0;
  static  unsigned long long aesl_llvm_cbe_1361_count = 0;
  static  unsigned long long aesl_llvm_cbe_1362_count = 0;
  static  unsigned long long aesl_llvm_cbe_1363_count = 0;
  static  unsigned long long aesl_llvm_cbe_1364_count = 0;
  static  unsigned long long aesl_llvm_cbe_1365_count = 0;
  static  unsigned long long aesl_llvm_cbe_1366_count = 0;
  static  unsigned long long aesl_llvm_cbe_1367_count = 0;
  static  unsigned long long aesl_llvm_cbe_1368_count = 0;
  static  unsigned long long aesl_llvm_cbe_1369_count = 0;
  static  unsigned long long aesl_llvm_cbe_1370_count = 0;
  unsigned long long llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_1371_count = 0;
  static  unsigned long long aesl_llvm_cbe_1372_count = 0;
  static  unsigned long long aesl_llvm_cbe_1373_count = 0;
  static  unsigned long long aesl_llvm_cbe_1374_count = 0;
  static  unsigned long long aesl_llvm_cbe_1375_count = 0;
  static  unsigned long long aesl_llvm_cbe_1376_count = 0;
  static  unsigned long long aesl_llvm_cbe_1377_count = 0;
  static  unsigned long long aesl_llvm_cbe_1378_count = 0;
  static  unsigned long long aesl_llvm_cbe_1379_count = 0;
  static  unsigned long long aesl_llvm_cbe_1380_count = 0;
  static  unsigned long long aesl_llvm_cbe_1381_count = 0;
  static  unsigned long long aesl_llvm_cbe_1382_count = 0;
  static  unsigned long long aesl_llvm_cbe_1383_count = 0;
  static  unsigned long long aesl_llvm_cbe_1384_count = 0;
  static  unsigned long long aesl_llvm_cbe_1385_count = 0;
  static  unsigned long long aesl_llvm_cbe_1386_count = 0;
  static  unsigned long long aesl_llvm_cbe_1387_count = 0;
  static  unsigned long long aesl_llvm_cbe_1388_count = 0;
  static  unsigned long long aesl_llvm_cbe_1389_count = 0;
  static  unsigned long long aesl_llvm_cbe_1390_count = 0;
  static  unsigned long long aesl_llvm_cbe_1391_count = 0;
  static  unsigned long long aesl_llvm_cbe_1392_count = 0;
  static  unsigned long long aesl_llvm_cbe_1393_count = 0;
  static  unsigned long long aesl_llvm_cbe_1394_count = 0;
  static  unsigned long long aesl_llvm_cbe_1395_count = 0;
  static  unsigned long long aesl_llvm_cbe_1396_count = 0;
  static  unsigned long long aesl_llvm_cbe_1397_count = 0;
  static  unsigned long long aesl_llvm_cbe_1398_count = 0;
  static  unsigned long long aesl_llvm_cbe_1399_count = 0;
  static  unsigned long long aesl_llvm_cbe_1400_count = 0;
  static  unsigned long long aesl_llvm_cbe_1401_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond95_count = 0;
  static  unsigned long long aesl_llvm_cbe_1402_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa46105_count = 0;
  unsigned int llvm_cbe__2e_lcssa46105;
  unsigned int llvm_cbe__2e_lcssa46105__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa35_count = 0;
  unsigned long long llvm_cbe__2e_lcssa35;
  unsigned long long llvm_cbe__2e_lcssa35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1403_count = 0;
  unsigned long long llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_1404_count = 0;
  unsigned long long llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_1405_count = 0;
  unsigned long long llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_1406_count = 0;
  unsigned int llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_1407_count = 0;
  static  unsigned long long aesl_llvm_cbe_1408_count = 0;
  static  unsigned long long aesl_llvm_cbe_1409_count = 0;
  unsigned int llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_1410_count = 0;
  static  unsigned long long aesl_llvm_cbe_1411_count = 0;
  static  unsigned long long aesl_llvm_cbe_1412_count = 0;
  static  unsigned long long aesl_llvm_cbe_1413_count = 0;
  static  unsigned long long aesl_llvm_cbe_1414_count = 0;
  static  unsigned long long aesl_llvm_cbe_1415_count = 0;
  unsigned int llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_1416_count = 0;
  static  unsigned long long aesl_llvm_cbe_1417_count = 0;
  static  unsigned long long aesl_llvm_cbe_1418_count = 0;
  static  unsigned long long aesl_llvm_cbe_1419_count = 0;
  static  unsigned long long aesl_llvm_cbe_1420_count = 0;
  unsigned int llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_1421_count = 0;
  static  unsigned long long aesl_llvm_cbe_1422_count = 0;
  unsigned int llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_1423_count = 0;
  unsigned int llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_1424_count = 0;
  static  unsigned long long aesl_llvm_cbe_1425_count = 0;
  static  unsigned long long aesl_llvm_cbe_1426_count = 0;
  static  unsigned long long aesl_llvm_cbe_1427_count = 0;
  static  unsigned long long aesl_llvm_cbe_1428_count = 0;
  static  unsigned long long aesl_llvm_cbe_1429_count = 0;
  static  unsigned long long aesl_llvm_cbe_1430_count = 0;
  static  unsigned long long aesl_llvm_cbe_1431_count = 0;
  static  unsigned long long aesl_llvm_cbe_1432_count = 0;
  static  unsigned long long aesl_llvm_cbe_1433_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mask_grade\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__158 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__159 = (unsigned long long )*llvm_cbe_tmp__158;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__159);
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa76_2e_ph__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader65_2e_thread;
  } else {
    llvm_cbe_storemerge86__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__160__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph82;
  }

  do {     /* Syntactic loop '.lr.ph82' to make GCC happy */
llvm_cbe__2e_lr_2e_ph82:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge86 = phi i64 [ %%28, %%._crit_edge83 ], [ 0, %%0  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge86_count);
  llvm_cbe_storemerge86 = (unsigned long long )llvm_cbe_storemerge86__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge86 = 0x%I64X",llvm_cbe_storemerge86);
printf("\n = 0x%I64X",llvm_cbe_tmp__174);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i32 [ %%25, %%._crit_edge83 ], [ 0, %%0  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_498_count);
  llvm_cbe_tmp__160 = (unsigned int )llvm_cbe_tmp__160__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__160);
printf("\n = 0x%X",llvm_cbe_tmp__171);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1181__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__163__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__160;   /* for PHI node */
  llvm_cbe_tmp__164__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__240;

llvm_cbe__2e__crit_edge83:
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge86, 1, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__174 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge86&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__174&18446744073709551615ull)));
  if (((llvm_cbe_tmp__174&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader75;
  } else {
    llvm_cbe_storemerge86__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__174;   /* for PHI node */
    llvm_cbe_tmp__160__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__171;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph82;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__240:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1181 = phi i64 [ 0, %%.lr.ph82 ], [ %%27, %%22  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge1181_count);
  llvm_cbe_storemerge1181 = (unsigned long long )llvm_cbe_storemerge1181__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1181 = 0x%I64X",llvm_cbe_storemerge1181);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__173);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = phi i32 [ %%4, %%.lr.ph82 ], [ %%25, %%22  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_581_count);
  llvm_cbe_tmp__163 = (unsigned int )llvm_cbe_tmp__163__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__163);
printf("\n = 0x%X",llvm_cbe_tmp__160);
printf("\n = 0x%X",llvm_cbe_tmp__171);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i8 [ 0, %%.lr.ph82 ], [ %%24, %%22  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_582_count);
  llvm_cbe_tmp__164 = (unsigned char )llvm_cbe_tmp__164__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__164);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__170);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = phi i64 [ 0, %%.lr.ph82 ], [ %%26, %%22  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_583_count);
  llvm_cbe_tmp__165 = (unsigned long long )llvm_cbe_tmp__165__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__165);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__172);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge86, i64 %%storemerge1181), !dbg !10 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_584_count);
  llvm_cbe_tmp__166 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge86, llvm_cbe_storemerge1181);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge86 = 0x%I64X",llvm_cbe_storemerge86);
printf("\nArgument storemerge1181 = 0x%I64X",llvm_cbe_storemerge1181);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__166);
}
  if (((llvm_cbe_tmp__166&255U) == (llvm_cbe_tmp__164&255U))) {
    goto llvm_cbe_tmp__241;
  } else {
    llvm_cbe_tmp__169__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__170__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__166;   /* for PHI node */
    llvm_cbe_tmp__171__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__163;   /* for PHI node */
    goto llvm_cbe_tmp__242;
  }

llvm_cbe_tmp__242:
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i64 [ 0, %%9 ], [ 5, %%17 ], [ %%12, %%19 ], !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_617_count);
  llvm_cbe_tmp__169 = (unsigned long long )llvm_cbe_tmp__169__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__169);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",5ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = phi i8 [ %%13, %%9 ], [ %%11, %%17 ], [ %%11, %%19  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_618_count);
  llvm_cbe_tmp__170 = (unsigned char )llvm_cbe_tmp__170__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__170);
printf("\n = 0x%X",llvm_cbe_tmp__166);
printf("\n = 0x%X",llvm_cbe_tmp__164);
printf("\n = 0x%X",llvm_cbe_tmp__164);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = phi i32 [ %%10, %%9 ], [ %%18, %%17 ], [ %%., %%19  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_619_count);
  llvm_cbe_tmp__171 = (unsigned int )llvm_cbe_tmp__171__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__171);
printf("\n = 0x%X",llvm_cbe_tmp__163);
printf("\n = 0x%X",llvm_cbe_tmp__167);
printf("\n. = 0x%X",llvm_cbe__2e_);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add i64 %%23, 1, !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_620_count);
  llvm_cbe_tmp__172 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__169&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__172&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%storemerge1181, 1, !dbg !17 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__173 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1181&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__173&18446744073709551615ull)));
  if (((llvm_cbe_tmp__173&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge83;
  } else {
    llvm_cbe_storemerge1181__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__173;   /* for PHI node */
    llvm_cbe_tmp__163__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__171;   /* for PHI node */
    llvm_cbe_tmp__164__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__170;   /* for PHI node */
    llvm_cbe_tmp__165__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__172;   /* for PHI node */
    goto llvm_cbe_tmp__240;
  }

llvm_cbe_tmp__243:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%10, 3, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_594_count);
  llvm_cbe_tmp__167 = (unsigned int )((unsigned int )(llvm_cbe_tmp__163&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__167&4294967295ull)));
  llvm_cbe_tmp__169__PHI_TEMPORARY = (unsigned long long )5ull;   /* for PHI node */
  llvm_cbe_tmp__170__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__164;   /* for PHI node */
  llvm_cbe_tmp__171__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__167;   /* for PHI node */
  goto llvm_cbe_tmp__242;

llvm_cbe_tmp__241:
  if (((llvm_cbe_tmp__165&18446744073709551615ULL) == (5ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__243;
  } else {
    goto llvm_cbe_tmp__244;
  }

llvm_cbe_tmp__244:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%10, 1, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_606_count);
  llvm_cbe_tmp__168 = (unsigned int )((unsigned int )(llvm_cbe_tmp__163&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__168&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%20, i32 %%21, i32 %%10, !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )(((((unsigned long long )llvm_cbe_tmp__165&18446744073709551615ULL) > ((unsigned long long )5ull&18446744073709551615ULL))) ? ((unsigned int )llvm_cbe_tmp__168) : ((unsigned int )llvm_cbe_tmp__163));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  llvm_cbe_tmp__169__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__165;   /* for PHI node */
  llvm_cbe_tmp__170__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__164;   /* for PHI node */
  llvm_cbe_tmp__171__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_;   /* for PHI node */
  goto llvm_cbe_tmp__242;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph82' */
llvm_cbe__2e_preheader75:
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa76_2e_ph__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__171;   /* for PHI node */
    goto llvm_cbe__2e_preheader65_2e_thread;
  } else {
    llvm_cbe_storemerge177_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph72_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph72.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph72_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge177.us = phi i64 [ %%6, %%5 ], [ 0, %%.preheader75  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge177_2e_us_count);
  llvm_cbe_storemerge177_2e_us = (unsigned long long )llvm_cbe_storemerge177_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge177.us = 0x%I64X",llvm_cbe_storemerge177_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__161);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge1071_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__245;

llvm_cbe_tmp__246:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge177.us, 1, !dbg !17 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__161 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge177_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__161&18446744073709551615ull)));
  if (((llvm_cbe_tmp__161&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader65;
  } else {
    llvm_cbe_storemerge177_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__161;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph72_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__245:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1071.us = phi i64 [ 0, %%.lr.ph72.us ], [ %%8, %%7  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge1071_2e_us_count);
  llvm_cbe_storemerge1071_2e_us = (unsigned long long )llvm_cbe_storemerge1071_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1071.us = 0x%I64X",llvm_cbe_storemerge1071_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__162);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%storemerge1071.us, 1, !dbg !18 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_571_count);
  llvm_cbe_tmp__162 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1071_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__162&18446744073709551615ull)));
  if (((llvm_cbe_tmp__162&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__246;
  } else {
    llvm_cbe_storemerge1071_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__162;   /* for PHI node */
    goto llvm_cbe_tmp__245;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph72.us' */
llvm_cbe__2e_preheader65_2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa76.ph = phi i32 [ %%25, %%.preheader75 ], [ 0, %%0  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa76_2e_ph_count);
  llvm_cbe__2e_lcssa76_2e_ph = (unsigned int )llvm_cbe__2e_lcssa76_2e_ph__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa76.ph = 0x%X",llvm_cbe__2e_lcssa76_2e_ph);
printf("\n = 0x%X",llvm_cbe_tmp__171);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%2, -1, !dbg !14 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_694_count);
  llvm_cbe_tmp__175 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__175&18446744073709551615ull)));
  llvm_cbe_tmp__177__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__175;   /* for PHI node */
  llvm_cbe__2e_lcssa76104__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa76_2e_ph;   /* for PHI node */
  goto llvm_cbe__2e_preheader59_2e_lr_2e_ph;

llvm_cbe__2e_preheader65:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i64 %%2, -1, !dbg !14 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_726_count);
  llvm_cbe_tmp__176 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull)));
  if (((llvm_cbe_tmp__176&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa66__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__171;   /* for PHI node */
    goto llvm_cbe__2e_preheader55;
  } else {
    llvm_cbe_tmp__177__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__176;   /* for PHI node */
    llvm_cbe__2e_lcssa76104__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__171;   /* for PHI node */
    goto llvm_cbe__2e_preheader59_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader59_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i64 [ %%29, %%.preheader65.thread ], [ %%30, %%.preheader65  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_729_count);
  llvm_cbe_tmp__177 = (unsigned long long )llvm_cbe_tmp__177__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__177);
printf("\n = 0x%I64X",llvm_cbe_tmp__175);
printf("\n = 0x%I64X",llvm_cbe_tmp__176);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa76104 = phi i32 [ %%.lcssa76.ph, %%.preheader65.thread ], [ %%25, %%.preheader65  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa76104_count);
  llvm_cbe__2e_lcssa76104 = (unsigned int )llvm_cbe__2e_lcssa76104__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa76104 = 0x%X",llvm_cbe__2e_lcssa76104);
printf("\n.lcssa76.ph = 0x%X",llvm_cbe__2e_lcssa76_2e_ph);
printf("\n = 0x%X",llvm_cbe_tmp__171);
}
  llvm_cbe_storemerge267__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa76104;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph62;

  do {     /* Syntactic loop '.lr.ph62' to make GCC happy */
llvm_cbe__2e_lr_2e_ph62:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge267 = phi i64 [ 0, %%.preheader59.lr.ph ], [ %%48, %%._crit_edge63  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge267_count);
  llvm_cbe_storemerge267 = (unsigned long long )llvm_cbe_storemerge267__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge267 = 0x%I64X",llvm_cbe_storemerge267);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__188);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = phi i32 [ %%.lcssa76104, %%.preheader59.lr.ph ], [ %%.27, %%._crit_edge63  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__178 = (unsigned int )llvm_cbe_tmp__178__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__178);
printf("\n.lcssa76104 = 0x%X",llvm_cbe__2e_lcssa76104);
printf("\n.27 = 0x%X",llvm_cbe__2e_27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%storemerge267, 1, !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_762_count);
  llvm_cbe_tmp__179 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge267&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__179&18446744073709551615ull)));
  llvm_cbe_storemerge961__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__181__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__178;   /* for PHI node */
  goto llvm_cbe_tmp__247;

llvm_cbe__2e__crit_edge63:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = add i64 %%storemerge267, 1, !dbg !17 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_859_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge267&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)));
  if (((llvm_cbe_tmp__188&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa66__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_27;   /* for PHI node */
    goto llvm_cbe__2e_preheader55;
  } else {
    llvm_cbe_storemerge267__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__188;   /* for PHI node */
    llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_27;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph62;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__247:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge961 = phi i64 [ 0, %%.lr.ph62 ], [ %%40, %%37  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge961_count);
  llvm_cbe_storemerge961 = (unsigned long long )llvm_cbe_storemerge961__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge961 = 0x%I64X",llvm_cbe_storemerge961);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__183);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = phi i32 [ %%33, %%.lr.ph62 ], [ %%.27, %%37  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_798_count);
  llvm_cbe_tmp__181 = (unsigned int )llvm_cbe_tmp__181__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__181);
printf("\n = 0x%X",llvm_cbe_tmp__178);
printf("\n.27 = 0x%X",llvm_cbe__2e_27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge267, i64 %%storemerge961), !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__182 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge267, llvm_cbe_storemerge961);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge267 = 0x%I64X",llvm_cbe_storemerge267);
printf("\nArgument storemerge961 = 0x%I64X",llvm_cbe_storemerge961);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__182);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = add i64 %%storemerge961, 1, !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__183 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge961&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge267, i64 %%40), !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_805_count);
  llvm_cbe_tmp__184 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge267, llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge267 = 0x%I64X",llvm_cbe_storemerge267);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__183);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__184);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%34, i64 %%storemerge961), !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_808_count);
  llvm_cbe_tmp__185 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__179, llvm_cbe_storemerge961);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__179);
printf("\nArgument storemerge961 = 0x%I64X",llvm_cbe_storemerge961);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__185);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%34, i64 %%40), !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_812_count);
  llvm_cbe_tmp__186 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__179, llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__179);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__183);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__186);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%44, %%45, !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_tmp__182&255U) == (llvm_cbe_tmp__184&255U)) & ((llvm_cbe_tmp__185&255U) == (llvm_cbe_tmp__186&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond13 = and i1 %%or.cond, %%46, !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond13_count);
  llvm_cbe_or_2e_cond13 = (bool )((llvm_cbe_or_2e_cond & ((llvm_cbe_tmp__182&255U) == (llvm_cbe_tmp__185&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond13 = 0x%X\n", llvm_cbe_or_2e_cond13);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add nsw i32 %%38, 3, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_818_count);
  llvm_cbe_tmp__187 = (unsigned int )((unsigned int )(llvm_cbe_tmp__181&4294967295ull)) + ((unsigned int )(3u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__187&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.27 = select i1 %%or.cond13, i32 %%47, i32 %%38, !dbg !19 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_27_count);
  llvm_cbe__2e_27 = (unsigned int )((llvm_cbe_or_2e_cond13) ? ((unsigned int )llvm_cbe_tmp__187) : ((unsigned int )llvm_cbe_tmp__181));
if (AESL_DEBUG_TRACE)
printf("\n.27 = 0x%X\n", llvm_cbe__2e_27);
  if (((llvm_cbe_tmp__183&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge63;
  } else {
    llvm_cbe_storemerge961__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__183;   /* for PHI node */
    llvm_cbe_tmp__181__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_27;   /* for PHI node */
    goto llvm_cbe_tmp__247;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph62' */
llvm_cbe__2e_preheader55:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa66 = phi i32 [ %%25, %%.preheader65 ], [ %%.27, %%._crit_edge63  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa66_count);
  llvm_cbe__2e_lcssa66 = (unsigned int )llvm_cbe__2e_lcssa66__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa66 = 0x%X",llvm_cbe__2e_lcssa66);
printf("\n = 0x%X",llvm_cbe_tmp__171);
printf("\n.27 = 0x%X",llvm_cbe__2e_27);
}
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46105__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa66;   /* for PHI node */
    llvm_cbe__2e_lcssa35__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge37;
  } else {
    goto llvm_cbe__2e_preheader49_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader49_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i64 %%2, -6, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_795_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) + ((unsigned long long )(18446744073709551610ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)));
  llvm_cbe_storemerge357__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__189__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa66;   /* for PHI node */
  goto llvm_cbe__2e_preheader49;

  do {     /* Syntactic loop '.preheader49' to make GCC happy */
llvm_cbe__2e_preheader49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge357 = phi i64 [ 0, %%.preheader49.lr.ph ], [ %%94, %%._crit_edge53  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge357_count);
  llvm_cbe_storemerge357 = (unsigned long long )llvm_cbe_storemerge357__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__223);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = phi i32 [ %%.lcssa66, %%.preheader49.lr.ph ], [ %%.lcssa50, %%._crit_edge53  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_892_count);
  llvm_cbe_tmp__189 = (unsigned int )llvm_cbe_tmp__189__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__189);
printf("\n.lcssa66 = 0x%X",llvm_cbe__2e_lcssa66);
printf("\n.lcssa50 = 0x%X",llvm_cbe__2e_lcssa50);
}
  if (((llvm_cbe_tmp__180&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa50__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__189;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge53;
  } else {
    llvm_cbe_storemerge851__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__208__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__189;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph52;
  }

llvm_cbe__2e__crit_edge53:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa50 = phi i32 [ %%49, %%.preheader49 ], [ %%.28, %%.lr.ph52  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa50_count);
  llvm_cbe__2e_lcssa50 = (unsigned int )llvm_cbe__2e_lcssa50__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa50 = 0x%X",llvm_cbe__2e_lcssa50);
printf("\n = 0x%X",llvm_cbe_tmp__189);
printf("\n.28 = 0x%X",llvm_cbe__2e_28);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = add i64 %%storemerge357, 1, !dbg !17 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__223 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge357&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__223&18446744073709551615ull)));
  if (((llvm_cbe_tmp__223&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader45;
  } else {
    llvm_cbe_storemerge357__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__223;   /* for PHI node */
    llvm_cbe_tmp__189__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa50;   /* for PHI node */
    goto llvm_cbe__2e_preheader49;
  }

  do {     /* Syntactic loop '.lr.ph52' to make GCC happy */
llvm_cbe__2e_lr_2e_ph52:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge851 = phi i64 [ %%77, %%.lr.ph52 ], [ 0, %%.preheader49  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge851_count);
  llvm_cbe_storemerge851 = (unsigned long long )llvm_cbe_storemerge851__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge851 = 0x%I64X",llvm_cbe_storemerge851);
printf("\n = 0x%I64X",llvm_cbe_tmp__210);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = phi i32 [ %%.28, %%.lr.ph52 ], [ %%49, %%.preheader49  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1097_count);
  llvm_cbe_tmp__208 = (unsigned int )llvm_cbe_tmp__208__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__208);
printf("\n.28 = 0x%X",llvm_cbe__2e_28);
printf("\n = 0x%X",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%storemerge851), !dbg !11 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1098_count);
  llvm_cbe_tmp__209 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_storemerge851);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument storemerge851 = 0x%I64X",llvm_cbe_storemerge851);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__209);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i64 %%storemerge851, 1, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1101_count);
  llvm_cbe_tmp__210 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__210&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%77), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1103_count);
  llvm_cbe_tmp__211 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__210);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__210);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__211);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = add i64 %%storemerge851, 2, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1106_count);
  llvm_cbe_tmp__212 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__212&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%79), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1107_count);
  llvm_cbe_tmp__213 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__212);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__212);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__213);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = add i64 %%storemerge851, 3, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1110_count);
  llvm_cbe_tmp__214 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__214&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%81), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1111_count);
  llvm_cbe_tmp__215 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__214);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__214);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__215);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = add i64 %%storemerge851, 4, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__216 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(4ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__216&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%83), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__217 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__216);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__216);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__217);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = add i64 %%storemerge851, 5, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1118_count);
  llvm_cbe_tmp__218 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(5ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__218&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%85), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1119_count);
  llvm_cbe_tmp__219 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__218);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__219);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = add i64 %%storemerge851, 6, !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1122_count);
  llvm_cbe_tmp__220 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge851&18446744073709551615ull)) + ((unsigned long long )(6ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__220&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge357, i64 %%87), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1123_count);
  llvm_cbe_tmp__221 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge357, llvm_cbe_tmp__220);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge357 = 0x%I64X",llvm_cbe_storemerge357);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__220);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__221);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond14.not = or i1 %%notrhs31, %%notlhs30, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond14_2e_not_count);
  llvm_cbe_or_2e_cond14_2e_not = (bool )((((llvm_cbe_tmp__211&255U) != (((unsigned char )0)&255U)) | ((llvm_cbe_tmp__209&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond14.not = 0x%X\n", llvm_cbe_or_2e_cond14_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond15 = or i1 %%or.cond14.not, %%89, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond15_count);
  llvm_cbe_or_2e_cond15 = (bool )((llvm_cbe_or_2e_cond14_2e_not | ((llvm_cbe_tmp__213&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond15 = 0x%X\n", llvm_cbe_or_2e_cond15);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond16 = or i1 %%or.cond15, %%90, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond16_count);
  llvm_cbe_or_2e_cond16 = (bool )((llvm_cbe_or_2e_cond15 | ((llvm_cbe_tmp__215&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond16 = 0x%X\n", llvm_cbe_or_2e_cond16);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond17 = or i1 %%or.cond16, %%91, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond17_count);
  llvm_cbe_or_2e_cond17 = (bool )((llvm_cbe_or_2e_cond16 | ((llvm_cbe_tmp__217&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond17 = 0x%X\n", llvm_cbe_or_2e_cond17);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond18.not = or i1 %%or.cond17, %%.not32, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond18_2e_not_count);
  llvm_cbe_or_2e_cond18_2e_not = (bool )((llvm_cbe_or_2e_cond17 | ((llvm_cbe_tmp__219&255U) != (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond18.not = 0x%X\n", llvm_cbe_or_2e_cond18_2e_not);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond19 = or i1 %%or.cond18.not, %%92, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond19_count);
  llvm_cbe_or_2e_cond19 = (bool )((llvm_cbe_or_2e_cond18_2e_not | ((llvm_cbe_tmp__221&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond19 = 0x%X\n", llvm_cbe_or_2e_cond19);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add nsw i32 %%75, 40, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1130_count);
  llvm_cbe_tmp__222 = (unsigned int )((unsigned int )(llvm_cbe_tmp__208&4294967295ull)) + ((unsigned int )(40u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__222&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.28 = select i1 %%or.cond19, i32 %%75, i32 %%93, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_28_count);
  llvm_cbe__2e_28 = (unsigned int )((llvm_cbe_or_2e_cond19) ? ((unsigned int )llvm_cbe_tmp__208) : ((unsigned int )llvm_cbe_tmp__222));
if (AESL_DEBUG_TRACE)
printf("\n.28 = 0x%X\n", llvm_cbe__2e_28);
  if (((llvm_cbe_tmp__210&18446744073709551615ULL) == (llvm_cbe_tmp__180&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa50__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_28;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge53;
  } else {
    llvm_cbe_storemerge851__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__210;   /* for PHI node */
    llvm_cbe_tmp__208__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_28;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph52;
  }

  } while (1); /* end of syntactic loop '.lr.ph52' */
  } while (1); /* end of syntactic loop '.preheader49' */
llvm_cbe__2e_preheader45:
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46105__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa50;   /* for PHI node */
    llvm_cbe__2e_lcssa35__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge37;
  } else {
    goto llvm_cbe__2e_preheader39_2e_lr_2e_ph;
  }

llvm_cbe__2e_preheader39_2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i64 %%2, -6, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_955_count);
  llvm_cbe_tmp__190 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) + ((unsigned long long )(18446744073709551610ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__190&18446744073709551615ull)));
  if (((llvm_cbe_tmp__190&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge447__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe_tmp__248;
  } else {
    llvm_cbe_storemerge447_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__207__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa50;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph42_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph42.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph42_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge447.us = phi i64 [ %%53, %%52 ], [ 0, %%.preheader39.lr.ph  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge447_2e_us_count);
  llvm_cbe_storemerge447_2e_us = (unsigned long long )llvm_cbe_storemerge447_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__191);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = phi i32 [ %%.29.us, %%52 ], [ %%.lcssa50, %%.preheader39.lr.ph  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__207 = (unsigned int )llvm_cbe_tmp__207__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__207);
printf("\n.29.us = 0x%X",llvm_cbe__2e_29_2e_us);
printf("\n.lcssa50 = 0x%X",llvm_cbe__2e_lcssa50);
}
  llvm_cbe_storemerge741_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__192__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__207;   /* for PHI node */
  goto llvm_cbe_tmp__249;

llvm_cbe_tmp__250:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = add i64 %%storemerge447.us, 1, !dbg !18 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__191 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge447_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__191&18446744073709551615ull)));
  if (((llvm_cbe_tmp__191&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_29_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_preheader34;
  } else {
    llvm_cbe_storemerge447_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__191;   /* for PHI node */
    llvm_cbe_tmp__207__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_29_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph42_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__249:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge741.us = phi i64 [ 0, %%.lr.ph42.us ], [ %%57, %%54  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge741_2e_us_count);
  llvm_cbe_storemerge741_2e_us = (unsigned long long )llvm_cbe_storemerge741_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge741.us = 0x%I64X",llvm_cbe_storemerge741_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__194);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = phi i32 [ %%74, %%.lr.ph42.us ], [ %%.29.us, %%54  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__192 = (unsigned int )llvm_cbe_tmp__192__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__192);
printf("\n = 0x%X",llvm_cbe_tmp__207);
printf("\n.29.us = 0x%X",llvm_cbe__2e_29_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge741.us, i64 %%storemerge447.us), !dbg !12 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__193 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge741_2e_us, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge741.us = 0x%I64X",llvm_cbe_storemerge741_2e_us);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__193);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add i64 %%storemerge741.us, 1, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_995_count);
  llvm_cbe_tmp__194 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__194&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%57, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_997_count);
  llvm_cbe_tmp__195 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__194, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__194);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__195);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%storemerge741.us, 2, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__196 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__196&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%59, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1001_count);
  llvm_cbe_tmp__197 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__196, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__196);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__197);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add i64 %%storemerge741.us, 3, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1004_count);
  llvm_cbe_tmp__198 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(3ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__198&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%61, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1005_count);
  llvm_cbe_tmp__199 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__198, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__198);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__199);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add i64 %%storemerge741.us, 4, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1008_count);
  llvm_cbe_tmp__200 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(4ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__200&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%63, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1009_count);
  llvm_cbe_tmp__201 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__200, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__200);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__201);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add i64 %%storemerge741.us, 5, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1012_count);
  llvm_cbe_tmp__202 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(5ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__202&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%65, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__203 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__202, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__202);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__203);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = add i64 %%storemerge741.us, 6, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1016_count);
  llvm_cbe_tmp__204 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge741_2e_us&18446744073709551615ull)) + ((unsigned long long )(6ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__204&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%67, i64 %%storemerge447.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1017_count);
  llvm_cbe_tmp__205 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_tmp__204, llvm_cbe_storemerge447_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__204);
printf("\nArgument storemerge447.us = 0x%I64X",llvm_cbe_storemerge447_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__205);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond20.not.us = or i1 %%notrhs.us, %%notlhs.us, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond20_2e_not_2e_us_count);
  llvm_cbe_or_2e_cond20_2e_not_2e_us = (bool )((((llvm_cbe_tmp__195&255U) != (((unsigned char )0)&255U)) | ((llvm_cbe_tmp__193&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond20.not.us = 0x%X\n", llvm_cbe_or_2e_cond20_2e_not_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond21.us = or i1 %%or.cond20.not.us, %%69, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond21_2e_us_count);
  llvm_cbe_or_2e_cond21_2e_us = (bool )((llvm_cbe_or_2e_cond20_2e_not_2e_us | ((llvm_cbe_tmp__197&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond21.us = 0x%X\n", llvm_cbe_or_2e_cond21_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond22.us = or i1 %%or.cond21.us, %%70, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond22_2e_us_count);
  llvm_cbe_or_2e_cond22_2e_us = (bool )((llvm_cbe_or_2e_cond21_2e_us | ((llvm_cbe_tmp__199&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond22.us = 0x%X\n", llvm_cbe_or_2e_cond22_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond23.us = or i1 %%or.cond22.us, %%71, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond23_2e_us_count);
  llvm_cbe_or_2e_cond23_2e_us = (bool )((llvm_cbe_or_2e_cond22_2e_us | ((llvm_cbe_tmp__201&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond23.us = 0x%X\n", llvm_cbe_or_2e_cond23_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond24.not.us = or i1 %%or.cond23.us, %%.not.us, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond24_2e_not_2e_us_count);
  llvm_cbe_or_2e_cond24_2e_not_2e_us = (bool )((llvm_cbe_or_2e_cond23_2e_us | ((llvm_cbe_tmp__203&255U) != (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond24.not.us = 0x%X\n", llvm_cbe_or_2e_cond24_2e_not_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond25.us = or i1 %%or.cond24.not.us, %%72, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_or_2e_cond25_2e_us_count);
  llvm_cbe_or_2e_cond25_2e_us = (bool )((llvm_cbe_or_2e_cond24_2e_not_2e_us | ((llvm_cbe_tmp__205&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond25.us = 0x%X\n", llvm_cbe_or_2e_cond25_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add nsw i32 %%55, 40, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1024_count);
  llvm_cbe_tmp__206 = (unsigned int )((unsigned int )(llvm_cbe_tmp__192&4294967295ull)) + ((unsigned int )(40u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__206&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.29.us = select i1 %%or.cond25.us, i32 %%55, i32 %%73, !dbg !20 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_29_2e_us_count);
  llvm_cbe__2e_29_2e_us = (unsigned int )((llvm_cbe_or_2e_cond25_2e_us) ? ((unsigned int )llvm_cbe_tmp__192) : ((unsigned int )llvm_cbe_tmp__206));
if (AESL_DEBUG_TRACE)
printf("\n.29.us = 0x%X\n", llvm_cbe__2e_29_2e_us);
  if (((llvm_cbe_tmp__194&18446744073709551615ULL) == (llvm_cbe_tmp__190&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__250;
  } else {
    llvm_cbe_storemerge741_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__194;   /* for PHI node */
    llvm_cbe_tmp__192__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_29_2e_us;   /* for PHI node */
    goto llvm_cbe_tmp__249;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph42.us' */
llvm_cbe__2e_preheader34:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa46 = phi i32 [ %%.29.us, %%52 ], [ %%.lcssa50, %%104  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa46_count);
  llvm_cbe__2e_lcssa46 = (unsigned int )llvm_cbe__2e_lcssa46__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa46 = 0x%X",llvm_cbe__2e_lcssa46);
printf("\n.29.us = 0x%X",llvm_cbe__2e_29_2e_us);
printf("\n.lcssa50 = 0x%X",llvm_cbe__2e_lcssa50);
}
  if (((llvm_cbe_tmp__159&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46105__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa46;   /* for PHI node */
    llvm_cbe__2e_lcssa35__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge37;
  } else {
    llvm_cbe_storemerge536_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__229__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge536.us = phi i64 [ %%96, %%95 ], [ 0, %%.preheader34  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge536_2e_us_count);
  llvm_cbe_storemerge536_2e_us = (unsigned long long )llvm_cbe_storemerge536_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge536.us = 0x%I64X",llvm_cbe_storemerge536_2e_us);
printf("\n = 0x%I64X",llvm_cbe_tmp__224);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = phi i64 [ %%.26.us, %%95 ], [ 0, %%.preheader34  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1308_count);
  llvm_cbe_tmp__229 = (unsigned long long )llvm_cbe_tmp__229__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__229);
printf("\n.26.us = 0x%I64X",llvm_cbe__2e_26_2e_us);
printf("\n = 0x%I64X",0ull);
}
  llvm_cbe_storemerge633_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__225__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__229;   /* for PHI node */
  goto llvm_cbe_tmp__251;

llvm_cbe_tmp__252:
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = add i64 %%storemerge536.us, 1, !dbg !17 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1235_count);
  llvm_cbe_tmp__224 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge536_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__224&18446744073709551615ull)));
  if (((llvm_cbe_tmp__224&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46105__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa46;   /* for PHI node */
    llvm_cbe__2e_lcssa35__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_26_2e_us;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge37;
  } else {
    llvm_cbe_storemerge536_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__224;   /* for PHI node */
    llvm_cbe_tmp__229__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_26_2e_us;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__251:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge633.us = phi i64 [ 0, %%.lr.ph.us ], [ %%102, %%97  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge633_2e_us_count);
  llvm_cbe_storemerge633_2e_us = (unsigned long long )llvm_cbe_storemerge633_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge633.us = 0x%I64X",llvm_cbe_storemerge633_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__228);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = phi i64 [ %%103, %%.lr.ph.us ], [ %%.26.us, %%97  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1268_count);
  llvm_cbe_tmp__225 = (unsigned long long )llvm_cbe_tmp__225__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__225);
printf("\n = 0x%I64X",llvm_cbe_tmp__229);
printf("\n.26.us = 0x%I64X",llvm_cbe__2e_26_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = tail call zeroext i8 @mask_if_content(%%struct.scanner* %%scanner, i8 zeroext %%m, i64 %%storemerge536.us, i64 %%storemerge633.us), !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1269_count);
  llvm_cbe_tmp__226 = (unsigned char ) /*tail*/ mask_if_content((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_m, llvm_cbe_storemerge536_2e_us, llvm_cbe_storemerge633_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge536.us = 0x%I64X",llvm_cbe_storemerge536_2e_us);
printf("\nArgument storemerge633.us = 0x%I64X",llvm_cbe_storemerge633_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__226);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = add i64 %%98, 1, !dbg !21 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1271_count);
  llvm_cbe_tmp__227 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__225&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__227&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%.26.us = select i1 %%100, i64 %%98, i64 %%101, !dbg !13 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_26_2e_us_count);
  llvm_cbe__2e_26_2e_us = (unsigned long long )((((llvm_cbe_tmp__226&255U) == (((unsigned char )0)&255U))) ? ((unsigned long long )llvm_cbe_tmp__225) : ((unsigned long long )llvm_cbe_tmp__227));
if (AESL_DEBUG_TRACE)
printf("\n.26.us = 0x%I64X\n", llvm_cbe__2e_26_2e_us);
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = add i64 %%storemerge633.us, 1, !dbg !18 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1275_count);
  llvm_cbe_tmp__228 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge633_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)));
  if (((llvm_cbe_tmp__228&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__252;
  } else {
    llvm_cbe_storemerge633_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__228;   /* for PHI node */
    llvm_cbe_tmp__225__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_26_2e_us;   /* for PHI node */
    goto llvm_cbe_tmp__251;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__248:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge447 = phi i64 [ %%105, %%104 ], [ 0, %%.preheader39.lr.ph  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_storemerge447_count);
  llvm_cbe_storemerge447 = (unsigned long long )llvm_cbe_storemerge447__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge447 = 0x%I64X",llvm_cbe_storemerge447);
printf("\n = 0x%I64X",llvm_cbe_tmp__230);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = add i64 %%storemerge447, 1, !dbg !18 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1370_count);
  llvm_cbe_tmp__230 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge447&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__230&18446744073709551615ull)));
  if (((llvm_cbe_tmp__230&18446744073709551615ULL) == (llvm_cbe_tmp__159&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa46__PHI_TEMPORARY = (unsigned int )llvm_cbe__2e_lcssa50;   /* for PHI node */
    goto llvm_cbe__2e_preheader34;
  } else {
    llvm_cbe_storemerge447__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__230;   /* for PHI node */
    goto llvm_cbe_tmp__248;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge37:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa46105 = phi i32 [ %%.lcssa46, %%.preheader34 ], [ %%.lcssa46, %%95 ], [ %%.lcssa50, %%.preheader45 ], [ %%.lcssa66, %%.preheader55  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa46105_count);
  llvm_cbe__2e_lcssa46105 = (unsigned int )llvm_cbe__2e_lcssa46105__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa46105 = 0x%X",llvm_cbe__2e_lcssa46105);
printf("\n.lcssa46 = 0x%X",llvm_cbe__2e_lcssa46);
printf("\n.lcssa46 = 0x%X",llvm_cbe__2e_lcssa46);
printf("\n.lcssa50 = 0x%X",llvm_cbe__2e_lcssa50);
printf("\n.lcssa66 = 0x%X",llvm_cbe__2e_lcssa66);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa35 = phi i64 [ 0, %%.preheader34 ], [ %%.26.us, %%95 ], [ 0, %%.preheader45 ], [ 0, %%.preheader55  for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe__2e_lcssa35_count);
  llvm_cbe__2e_lcssa35 = (unsigned long long )llvm_cbe__2e_lcssa35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa35 = 0x%I64X",llvm_cbe__2e_lcssa35);
printf("\n = 0x%I64X",0ull);
printf("\n.26.us = 0x%I64X",llvm_cbe__2e_26_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = mul i64 %%.lcssa35, 20, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1403_count);
  llvm_cbe_tmp__231 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa35&18446744073709551615ull)) * ((unsigned long long )(20ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__231&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = mul i64 %%2, %%2, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1404_count);
  llvm_cbe_tmp__232 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__159&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__232&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = udiv i64 %%106, %%107, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1405_count);
  llvm_cbe_tmp__233 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_tmp__231&18446744073709551615ull)) / ((unsigned long long )(llvm_cbe_tmp__232&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__233&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = trunc i64 %%108 to i32, !dbg !15 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1406_count);
  llvm_cbe_tmp__234 = (unsigned int )((unsigned int )llvm_cbe_tmp__233&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__234);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = add nsw i32 %%109, -10, !dbg !22 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1409_count);
  llvm_cbe_tmp__235 = (unsigned int )((unsigned int )(llvm_cbe_tmp__234&4294967295ull)) + ((unsigned int )(4294967286u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__235&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = sub i32 10, %%109, !dbg !22 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1415_count);
  llvm_cbe_tmp__236 = (unsigned int )((unsigned int )(10u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__234&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__236&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = select i1 %%111, i32 %%112, i32 %%110, !dbg !22 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1420_count);
  llvm_cbe_tmp__237 = (unsigned int )(((((signed int )llvm_cbe_tmp__235) < ((signed int )0u))) ? ((unsigned int )llvm_cbe_tmp__236) : ((unsigned int )llvm_cbe_tmp__235));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__237);
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = mul nsw i32 %%113, 10, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1422_count);
  llvm_cbe_tmp__238 = (unsigned int )((unsigned int )(llvm_cbe_tmp__237&4294967295ull)) * ((unsigned int )(10u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__238&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = add nsw i32 %%114, %%.lcssa46105, !dbg !16 for 0x%I64xth hint within @mask_grade  --> \n", ++aesl_llvm_cbe_1423_count);
  llvm_cbe_tmp__239 = (unsigned int )((unsigned int )(llvm_cbe_tmp__238&4294967295ull)) + ((unsigned int )(llvm_cbe__2e_lcssa46105&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__239&4294967295ull)));
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mask_grade}\n");
  return llvm_cbe_tmp__239;
}


void mask_apply(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_m) {
  static  unsigned long long aesl_llvm_cbe_1434_count = 0;
  static  unsigned long long aesl_llvm_cbe_1435_count = 0;
  static  unsigned long long aesl_llvm_cbe_1436_count = 0;
  static  unsigned long long aesl_llvm_cbe_1437_count = 0;
  static  unsigned long long aesl_llvm_cbe_1438_count = 0;
  static  unsigned long long aesl_llvm_cbe_1439_count = 0;
  static  unsigned long long aesl_llvm_cbe_1440_count = 0;
  static  unsigned long long aesl_llvm_cbe_1441_count = 0;
  signed long long *llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_1442_count = 0;
  unsigned long long llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_1443_count = 0;
  static  unsigned long long aesl_llvm_cbe_1444_count = 0;
  static  unsigned long long aesl_llvm_cbe_1445_count = 0;
  static  unsigned long long aesl_llvm_cbe_1446_count = 0;
  static  unsigned long long aesl_llvm_cbe_1447_count = 0;
  static  unsigned long long aesl_llvm_cbe_1448_count = 0;
  static  unsigned long long aesl_llvm_cbe_1449_count = 0;
  static  unsigned long long aesl_llvm_cbe_1450_count = 0;
  static  unsigned long long aesl_llvm_cbe_1451_count = 0;
  static  unsigned long long aesl_llvm_cbe_1452_count = 0;
  static  unsigned long long aesl_llvm_cbe_1453_count = 0;
  static  unsigned long long aesl_llvm_cbe_1454_count = 0;
   char **llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_1455_count = 0;
  static  unsigned long long aesl_llvm_cbe_1456_count = 0;
  unsigned long long llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_1457_count = 0;
  static  unsigned long long aesl_llvm_cbe_1458_count = 0;
  static  unsigned long long aesl_llvm_cbe_1459_count = 0;
  static  unsigned long long aesl_llvm_cbe_1460_count = 0;
  static  unsigned long long aesl_llvm_cbe_1461_count = 0;
  static  unsigned long long aesl_llvm_cbe_1462_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_1463_count = 0;
  static  unsigned long long aesl_llvm_cbe_1464_count = 0;
  unsigned long long llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_1465_count = 0;
  static  unsigned long long aesl_llvm_cbe_1466_count = 0;
  static  unsigned long long aesl_llvm_cbe_1467_count = 0;
  static  unsigned long long aesl_llvm_cbe_1468_count = 0;
  static  unsigned long long aesl_llvm_cbe_1469_count = 0;
  static  unsigned long long aesl_llvm_cbe_1470_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1471_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge12_2e_us;
  unsigned long long llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1472_count = 0;
  unsigned char llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_1473_count = 0;
  unsigned int llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_1474_count = 0;
  static  unsigned long long aesl_llvm_cbe_1475_count = 0;
  static  unsigned long long aesl_llvm_cbe_1476_count = 0;
  unsigned char llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_1477_count = 0;
  unsigned long long llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_1478_count = 0;
  unsigned long long llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_1479_count = 0;
  unsigned long long llvm_cbe_tmp__263;
  static  unsigned long long aesl_llvm_cbe_1480_count = 0;
   char *llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_1481_count = 0;
   char *llvm_cbe_tmp__265;
  static  unsigned long long aesl_llvm_cbe_1482_count = 0;
  unsigned char llvm_cbe_tmp__266;
  static  unsigned long long aesl_llvm_cbe_1483_count = 0;
  unsigned char llvm_cbe_tmp__267;
  static  unsigned long long aesl_llvm_cbe_1484_count = 0;
  static  unsigned long long aesl_llvm_cbe_1485_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned long long llvm_cbe_storemerge3_2e_us;
  unsigned long long llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1486_count = 0;
  static  unsigned long long aesl_llvm_cbe_1487_count = 0;
  static  unsigned long long aesl_llvm_cbe_1488_count = 0;
  static  unsigned long long aesl_llvm_cbe_1489_count = 0;
  static  unsigned long long aesl_llvm_cbe_1490_count = 0;
  static  unsigned long long aesl_llvm_cbe_1491_count = 0;
  unsigned char llvm_cbe_tmp__268;
  static  unsigned long long aesl_llvm_cbe_1492_count = 0;
  static  unsigned long long aesl_llvm_cbe_1493_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @mask_apply\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1441_count);
  llvm_cbe_tmp__253 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1442_count);
  llvm_cbe_tmp__254 = (unsigned long long )*llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__254);
  if (((llvm_cbe_tmp__254&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us;
  }

llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1454_count);
  llvm_cbe_tmp__255 = ( char **)(&llvm_cbe_scanner->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us;

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i64 [ 0, %%.preheader.lr.ph.split.us ], [ %%6, %%5  for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned long long )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%I64X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__256);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = trunc i64 %%storemerge3.us to i8, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1491_count);
  llvm_cbe_tmp__268 = (unsigned char )((unsigned char )llvm_cbe_storemerge3_2e_us&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__268);
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__269;

llvm_cbe_tmp__270:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge3.us, 1, !dbg !11 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1456_count);
  llvm_cbe_tmp__256 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__256&18446744073709551615ull)));
  if (((llvm_cbe_tmp__256&18446744073709551615ULL) == (llvm_cbe_tmp__254&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__256;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__269:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i64 [ 0, %%.lr.ph.us ], [ %%8, %%7  for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned long long )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%I64X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__257);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i64 %%storemerge12.us to i8, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1472_count);
  llvm_cbe_tmp__258 = (unsigned char )((unsigned char )llvm_cbe_storemerge12_2e_us&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__258);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call fastcc i32 @aesl_internal_is_data(%%struct.scanner* %%scanner, i8 zeroext %%22, i8 zeroext %%10), !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1473_count);
  llvm_cbe_tmp__259 = (unsigned int ) /*tail*/ aesl_internal_is_data((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__268, llvm_cbe_tmp__258);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__268);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__258);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__259);
}
  if (((llvm_cbe_tmp__259&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__271;
  } else {
    goto llvm_cbe_tmp__272;
  }

llvm_cbe_tmp__271:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = add i64 %%storemerge12.us, 1, !dbg !11 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1464_count);
  llvm_cbe_tmp__257 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__257&18446744073709551615ull)));
  if (((llvm_cbe_tmp__257&18446744073709551615ULL) == (llvm_cbe_tmp__254&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__270;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__257;   /* for PHI node */
    goto llvm_cbe_tmp__269;
  }

llvm_cbe_tmp__272:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = tail call zeroext i8 @mask(i8 zeroext %%m, i64 %%storemerge3.us, i64 %%storemerge12.us), !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1476_count);
  llvm_cbe_tmp__260 = (unsigned char ) /*tail*/ mask(llvm_cbe_m, llvm_cbe_storemerge3_2e_us, llvm_cbe_storemerge12_2e_us);
if (AESL_DEBUG_TRACE) {
printf("\nArgument m = 0x%X",llvm_cbe_m);
printf("\nArgument storemerge3.us = 0x%I64X",llvm_cbe_storemerge3_2e_us);
printf("\nArgument storemerge12.us = 0x%I64X",llvm_cbe_storemerge12_2e_us);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__260);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%1, align 8, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1477_count);
  llvm_cbe_tmp__261 = (unsigned long long )*llvm_cbe_tmp__253;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul i64 %%15, %%storemerge3.us, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1478_count);
  llvm_cbe_tmp__262 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__261&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_storemerge3_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add i64 %%16, %%storemerge12.us, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1479_count);
  llvm_cbe_tmp__263 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__262&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge12_2e_us&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8** %%4, align 8, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1480_count);
  llvm_cbe_tmp__264 = ( char *)*llvm_cbe_tmp__255;
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%18, i64 %%17, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1481_count);
  llvm_cbe_tmp__265 = ( char *)(&llvm_cbe_tmp__264[(((signed long long )llvm_cbe_tmp__263))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__263));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1482_count);
  llvm_cbe_tmp__266 = (unsigned char )*llvm_cbe_tmp__265;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__266);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = xor i8 %%20, %%14, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1483_count);
  llvm_cbe_tmp__267 = (unsigned char )((unsigned char )(llvm_cbe_tmp__266 ^ llvm_cbe_tmp__260));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__267);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%21, i8* %%19, align 1, !dbg !10 for 0x%I64xth hint within @mask_apply  --> \n", ++aesl_llvm_cbe_1484_count);
  *llvm_cbe_tmp__265 = llvm_cbe_tmp__267;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__267);
  goto llvm_cbe_tmp__271;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @mask_apply}\n");
  return;
}


unsigned char get_codeword(l_struct_OC_scanner *llvm_cbe_scanner) {
  static  unsigned long long aesl_llvm_cbe_1494_count = 0;
  static  unsigned long long aesl_llvm_cbe_1495_count = 0;
  static  unsigned long long aesl_llvm_cbe_1496_count = 0;
  static  unsigned long long aesl_llvm_cbe_1497_count = 0;
  static  unsigned long long aesl_llvm_cbe_1498_count = 0;
  static  unsigned long long aesl_llvm_cbe_1499_count = 0;
  static  unsigned long long aesl_llvm_cbe_1500_count = 0;
  static  unsigned long long aesl_llvm_cbe_1501_count = 0;
  static  unsigned long long aesl_llvm_cbe_1502_count = 0;
  static  unsigned long long aesl_llvm_cbe_1503_count = 0;
  static  unsigned long long aesl_llvm_cbe_1504_count = 0;
  static  unsigned long long aesl_llvm_cbe_1505_count = 0;
  signed int *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_1506_count = 0;
  unsigned int llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_1507_count = 0;
  unsigned char llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_1508_count = 0;
  static  unsigned long long aesl_llvm_cbe_1509_count = 0;
  static  unsigned long long aesl_llvm_cbe_1510_count = 0;
  static  unsigned long long aesl_llvm_cbe_1511_count = 0;
  static  unsigned long long aesl_llvm_cbe_1512_count = 0;
  static  unsigned long long aesl_llvm_cbe_1513_count = 0;
  signed long long *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_1514_count = 0;
  signed long long *llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_1515_count = 0;
  signed long long *llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_1516_count = 0;
   char **llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_1517_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1518_count = 0;
  unsigned char llvm_cbe_tmp__280;
  unsigned char llvm_cbe_tmp__280__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1519_count = 0;
  unsigned long long llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_1520_count = 0;
  static  unsigned long long aesl_llvm_cbe_1521_count = 0;
  static  unsigned long long aesl_llvm_cbe_1522_count = 0;
  static  unsigned long long aesl_llvm_cbe_1523_count = 0;
  unsigned long long llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_1524_count = 0;
  static  unsigned long long aesl_llvm_cbe_1525_count = 0;
  static  unsigned long long aesl_llvm_cbe_1526_count = 0;
  static  unsigned long long aesl_llvm_cbe_1527_count = 0;
  unsigned char llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_1528_count = 0;
  static  unsigned long long aesl_llvm_cbe_1529_count = 0;
  static  unsigned long long aesl_llvm_cbe_1530_count = 0;
  static  unsigned long long aesl_llvm_cbe_1531_count = 0;
  static  unsigned long long aesl_llvm_cbe_1532_count = 0;
  unsigned long long llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_1533_count = 0;
  unsigned long long llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_1534_count = 0;
  unsigned long long llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_1535_count = 0;
   char *llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_1536_count = 0;
   char *llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_1537_count = 0;
  unsigned char llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_1538_count = 0;
  unsigned char llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_1539_count = 0;
  unsigned char llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_1540_count = 0;
  unsigned char llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_1541_count = 0;
  static  unsigned long long aesl_llvm_cbe_1542_count = 0;
  static  unsigned long long aesl_llvm_cbe_1543_count = 0;
  static  unsigned long long aesl_llvm_cbe_1544_count = 0;
  static  unsigned long long aesl_llvm_cbe_1545_count = 0;
  static  unsigned long long aesl_llvm_cbe_1546_count = 0;
  unsigned int llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_1547_count = 0;
  static  unsigned long long aesl_llvm_cbe_1548_count = 0;
  static  unsigned long long aesl_llvm_cbe_1549_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1550_count = 0;
  static  unsigned long long aesl_llvm_cbe_1551_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @get_codeword\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 4, !dbg !9 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1505_count);
  llvm_cbe_tmp__273 = (signed int *)(&llvm_cbe_scanner->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !9 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1506_count);
  llvm_cbe_tmp__274 = (unsigned int )*llvm_cbe_tmp__273;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i32 %%2 to i8, !dbg !9 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1507_count);
  llvm_cbe_tmp__275 = (unsigned char )((unsigned char )llvm_cbe_tmp__274&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 5, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1513_count);
  llvm_cbe_tmp__276 = (signed long long *)(&llvm_cbe_scanner->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 6, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1514_count);
  llvm_cbe_tmp__277 = (signed long long *)(&llvm_cbe_scanner->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1515_count);
  llvm_cbe_tmp__278 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1516_count);
  llvm_cbe_tmp__279 = ( char **)(&llvm_cbe_scanner->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_tmp__280__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__294;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__294:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 0, %%0 ], [ %%22, %%8  for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__293);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i8 [ 0, %%0 ], [ %%21, %%8  for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1518_count);
  llvm_cbe_tmp__280 = (unsigned char )llvm_cbe_tmp__280__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__280);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",llvm_cbe_tmp__292);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%4, align 8, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1519_count);
  llvm_cbe_tmp__281 = (unsigned long long )*llvm_cbe_tmp__276;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%5, align 8, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1523_count);
  llvm_cbe_tmp__282 = (unsigned long long )*llvm_cbe_tmp__277;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__282);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl i8 %%9, 1, !dbg !11 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1527_count);
  llvm_cbe_tmp__283 = (unsigned char )((unsigned char )(llvm_cbe_tmp__280 << ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__283);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%6, align 8, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1532_count);
  llvm_cbe_tmp__284 = (unsigned long long )*llvm_cbe_tmp__278;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__284);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = mul i64 %%13, %%10, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1533_count);
  llvm_cbe_tmp__285 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__284&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__281&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%14, %%11, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1534_count);
  llvm_cbe_tmp__286 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__285&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__282&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__286&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8** %%7, align 8, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1535_count);
  llvm_cbe_tmp__287 = ( char *)*llvm_cbe_tmp__279;
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds i8* %%16, i64 %%15, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1536_count);
  llvm_cbe_tmp__288 = ( char *)(&llvm_cbe_tmp__287[(((signed long long )llvm_cbe_tmp__286))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__286));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 1, !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1537_count);
  llvm_cbe_tmp__289 = (unsigned char )*llvm_cbe_tmp__288;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__289);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = tail call zeroext i8 @mask(i8 zeroext %%3, i64 %%10, i64 %%11), !dbg !11 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1538_count);
  llvm_cbe_tmp__290 = (unsigned char ) /*tail*/ mask(llvm_cbe_tmp__275, llvm_cbe_tmp__281, llvm_cbe_tmp__282);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__275);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__281);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__282);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__290);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = xor i8 %%19, %%18, !dbg !11 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1539_count);
  llvm_cbe_tmp__291 = (unsigned char )((unsigned char )(llvm_cbe_tmp__290 ^ llvm_cbe_tmp__289));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__291);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add i8 %%20, %%12, !dbg !11 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1540_count);
  llvm_cbe_tmp__292 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__291&255ull)) + ((unsigned char )(llvm_cbe_tmp__283&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__292&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1545_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add nsw i32 %%storemerge1, 1, !dbg !11 for 0x%I64xth hint within @get_codeword  --> \n", ++aesl_llvm_cbe_1546_count);
  llvm_cbe_tmp__293 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__293&4294967295ull)));
  if (((llvm_cbe_tmp__293&4294967295U) == (8u&4294967295U))) {
    goto llvm_cbe_tmp__295;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__293;   /* for PHI node */
    llvm_cbe_tmp__280__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__292;   /* for PHI node */
    goto llvm_cbe_tmp__294;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__295:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @get_codeword}\n");
  return llvm_cbe_tmp__292;
}


void put_codeword(l_struct_OC_scanner *llvm_cbe_scanner,  char llvm_cbe_w) {
  static  unsigned long long aesl_llvm_cbe_1552_count = 0;
  static  unsigned long long aesl_llvm_cbe_1553_count = 0;
  static  unsigned long long aesl_llvm_cbe_1554_count = 0;
  static  unsigned long long aesl_llvm_cbe_1555_count = 0;
  static  unsigned long long aesl_llvm_cbe_1556_count = 0;
  static  unsigned long long aesl_llvm_cbe_1557_count = 0;
  static  unsigned long long aesl_llvm_cbe_1558_count = 0;
  static  unsigned long long aesl_llvm_cbe_1559_count = 0;
  static  unsigned long long aesl_llvm_cbe_1560_count = 0;
  static  unsigned long long aesl_llvm_cbe_1561_count = 0;
  static  unsigned long long aesl_llvm_cbe_1562_count = 0;
  static  unsigned long long aesl_llvm_cbe_1563_count = 0;
  static  unsigned long long aesl_llvm_cbe_1564_count = 0;
  signed long long *llvm_cbe_tmp__296;
  static  unsigned long long aesl_llvm_cbe_1565_count = 0;
  signed long long *llvm_cbe_tmp__297;
  static  unsigned long long aesl_llvm_cbe_1566_count = 0;
  signed long long *llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_1567_count = 0;
   char **llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_1568_count = 0;
  unsigned char llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_1569_count = 0;
  static  unsigned long long aesl_llvm_cbe_1570_count = 0;
  static  unsigned long long aesl_llvm_cbe_1571_count = 0;
  unsigned long long llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_1572_count = 0;
  unsigned long long llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1573_count = 0;
  unsigned long long llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1574_count = 0;
  unsigned long long llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_1575_count = 0;
  unsigned long long llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_1576_count = 0;
   char *llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_1577_count = 0;
   char *llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_1578_count = 0;
  static  unsigned long long aesl_llvm_cbe_1579_count = 0;
  static  unsigned long long aesl_llvm_cbe_1580_count = 0;
  static  unsigned long long aesl_llvm_cbe_1581_count = 0;
  static  unsigned long long aesl_llvm_cbe_1582_count = 0;
  static  unsigned long long aesl_llvm_cbe_1583_count = 0;
  static  unsigned long long aesl_llvm_cbe_1584_count = 0;
  unsigned char llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_1585_count = 0;
  unsigned char llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_1586_count = 0;
  static  unsigned long long aesl_llvm_cbe_1587_count = 0;
  static  unsigned long long aesl_llvm_cbe_1588_count = 0;
  unsigned long long llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1589_count = 0;
  unsigned long long llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_1590_count = 0;
  unsigned long long llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1591_count = 0;
  unsigned long long llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1592_count = 0;
  unsigned long long llvm_cbe_tmp__314;
  static  unsigned long long aesl_llvm_cbe_1593_count = 0;
   char *llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1594_count = 0;
   char *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1595_count = 0;
  static  unsigned long long aesl_llvm_cbe_1596_count = 0;
  static  unsigned long long aesl_llvm_cbe_1597_count = 0;
  static  unsigned long long aesl_llvm_cbe_1598_count = 0;
  static  unsigned long long aesl_llvm_cbe_1599_count = 0;
  static  unsigned long long aesl_llvm_cbe_1600_count = 0;
  static  unsigned long long aesl_llvm_cbe_1601_count = 0;
  unsigned char llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1602_count = 0;
  unsigned char llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1603_count = 0;
  static  unsigned long long aesl_llvm_cbe_1604_count = 0;
  static  unsigned long long aesl_llvm_cbe_1605_count = 0;
  unsigned long long llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1606_count = 0;
  unsigned long long llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1607_count = 0;
  unsigned long long llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1608_count = 0;
  unsigned long long llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1609_count = 0;
  unsigned long long llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1610_count = 0;
   char *llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1611_count = 0;
   char *llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1612_count = 0;
  static  unsigned long long aesl_llvm_cbe_1613_count = 0;
  static  unsigned long long aesl_llvm_cbe_1614_count = 0;
  static  unsigned long long aesl_llvm_cbe_1615_count = 0;
  static  unsigned long long aesl_llvm_cbe_1616_count = 0;
  static  unsigned long long aesl_llvm_cbe_1617_count = 0;
  static  unsigned long long aesl_llvm_cbe_1618_count = 0;
  unsigned char llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1619_count = 0;
  unsigned char llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1620_count = 0;
  static  unsigned long long aesl_llvm_cbe_1621_count = 0;
  static  unsigned long long aesl_llvm_cbe_1622_count = 0;
  unsigned long long llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1623_count = 0;
  unsigned long long llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1624_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1625_count = 0;
  unsigned long long llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1626_count = 0;
  unsigned long long llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1627_count = 0;
   char *llvm_cbe_tmp__333;
  static  unsigned long long aesl_llvm_cbe_1628_count = 0;
   char *llvm_cbe_tmp__334;
  static  unsigned long long aesl_llvm_cbe_1629_count = 0;
  static  unsigned long long aesl_llvm_cbe_1630_count = 0;
  static  unsigned long long aesl_llvm_cbe_1631_count = 0;
  static  unsigned long long aesl_llvm_cbe_1632_count = 0;
  static  unsigned long long aesl_llvm_cbe_1633_count = 0;
  static  unsigned long long aesl_llvm_cbe_1634_count = 0;
  static  unsigned long long aesl_llvm_cbe_1635_count = 0;
  unsigned char llvm_cbe_tmp__335;
  static  unsigned long long aesl_llvm_cbe_1636_count = 0;
  unsigned char llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1637_count = 0;
  static  unsigned long long aesl_llvm_cbe_1638_count = 0;
  static  unsigned long long aesl_llvm_cbe_1639_count = 0;
  unsigned long long llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1640_count = 0;
  unsigned long long llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1641_count = 0;
  unsigned long long llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1642_count = 0;
  unsigned long long llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1643_count = 0;
  unsigned long long llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1644_count = 0;
   char *llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1645_count = 0;
   char *llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1646_count = 0;
  static  unsigned long long aesl_llvm_cbe_1647_count = 0;
  static  unsigned long long aesl_llvm_cbe_1648_count = 0;
  static  unsigned long long aesl_llvm_cbe_1649_count = 0;
  static  unsigned long long aesl_llvm_cbe_1650_count = 0;
  static  unsigned long long aesl_llvm_cbe_1651_count = 0;
  static  unsigned long long aesl_llvm_cbe_1652_count = 0;
  unsigned char llvm_cbe_tmp__344;
  static  unsigned long long aesl_llvm_cbe_1653_count = 0;
  unsigned char llvm_cbe_tmp__345;
  static  unsigned long long aesl_llvm_cbe_1654_count = 0;
  static  unsigned long long aesl_llvm_cbe_1655_count = 0;
  static  unsigned long long aesl_llvm_cbe_1656_count = 0;
  unsigned long long llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1657_count = 0;
  unsigned long long llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1658_count = 0;
  unsigned long long llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1659_count = 0;
  unsigned long long llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1660_count = 0;
  unsigned long long llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1661_count = 0;
   char *llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1662_count = 0;
   char *llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1663_count = 0;
  static  unsigned long long aesl_llvm_cbe_1664_count = 0;
  static  unsigned long long aesl_llvm_cbe_1665_count = 0;
  static  unsigned long long aesl_llvm_cbe_1666_count = 0;
  static  unsigned long long aesl_llvm_cbe_1667_count = 0;
  static  unsigned long long aesl_llvm_cbe_1668_count = 0;
  static  unsigned long long aesl_llvm_cbe_1669_count = 0;
  unsigned char llvm_cbe_tmp__353;
  static  unsigned long long aesl_llvm_cbe_1670_count = 0;
  unsigned char llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1671_count = 0;
  static  unsigned long long aesl_llvm_cbe_1672_count = 0;
  static  unsigned long long aesl_llvm_cbe_1673_count = 0;
  unsigned long long llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1674_count = 0;
  unsigned long long llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1675_count = 0;
  unsigned long long llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1676_count = 0;
  unsigned long long llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1677_count = 0;
  unsigned long long llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1678_count = 0;
   char *llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1679_count = 0;
   char *llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1680_count = 0;
  static  unsigned long long aesl_llvm_cbe_1681_count = 0;
  static  unsigned long long aesl_llvm_cbe_1682_count = 0;
  static  unsigned long long aesl_llvm_cbe_1683_count = 0;
  static  unsigned long long aesl_llvm_cbe_1684_count = 0;
  static  unsigned long long aesl_llvm_cbe_1685_count = 0;
  static  unsigned long long aesl_llvm_cbe_1686_count = 0;
  unsigned char llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1687_count = 0;
  static  unsigned long long aesl_llvm_cbe_1688_count = 0;
  static  unsigned long long aesl_llvm_cbe_1689_count = 0;
  unsigned long long llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1690_count = 0;
  unsigned long long llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1691_count = 0;
  unsigned long long llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1692_count = 0;
  unsigned long long llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1693_count = 0;
  unsigned long long llvm_cbe_tmp__367;
  static  unsigned long long aesl_llvm_cbe_1694_count = 0;
   char *llvm_cbe_tmp__368;
  static  unsigned long long aesl_llvm_cbe_1695_count = 0;
   char *llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1696_count = 0;
  static  unsigned long long aesl_llvm_cbe_1697_count = 0;
  static  unsigned long long aesl_llvm_cbe_1698_count = 0;
  static  unsigned long long aesl_llvm_cbe_1699_count = 0;
  static  unsigned long long aesl_llvm_cbe_1700_count = 0;
  static  unsigned long long aesl_llvm_cbe_1701_count = 0;
  static  unsigned long long aesl_llvm_cbe_1702_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @put_codeword\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 5, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1564_count);
  llvm_cbe_tmp__296 = (signed long long *)(&llvm_cbe_scanner->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1565_count);
  llvm_cbe_tmp__297 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 6, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1566_count);
  llvm_cbe_tmp__298 = (signed long long *)(&llvm_cbe_scanner->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1567_count);
  llvm_cbe_tmp__299 = ( char **)(&llvm_cbe_scanner->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i8 %%w, 7, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1568_count);
  llvm_cbe_tmp__300 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )7)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__300&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1571_count);
  llvm_cbe_tmp__301 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__301);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1572_count);
  llvm_cbe_tmp__302 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__302);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = mul i64 %%7, %%6, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1573_count);
  llvm_cbe_tmp__303 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__302&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__301&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1574_count);
  llvm_cbe_tmp__304 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__304);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%8, %%9, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1575_count);
  llvm_cbe_tmp__305 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__303&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__304&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__305&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1576_count);
  llvm_cbe_tmp__306 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds i8* %%11, i64 %%10, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1577_count);
  llvm_cbe_tmp__307 = ( char *)(&llvm_cbe_tmp__306[(((signed long long )llvm_cbe_tmp__305))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__305));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%12, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1578_count);
  *llvm_cbe_tmp__307 = llvm_cbe_tmp__300;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__300);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1579_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = lshr i8 %%w, 6, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1584_count);
  llvm_cbe_tmp__308 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )6)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__308&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = and i8 %%13, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1585_count);
  llvm_cbe_tmp__309 = (unsigned char )((unsigned char )(llvm_cbe_tmp__308 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1588_count);
  llvm_cbe_tmp__310 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__310);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1589_count);
  llvm_cbe_tmp__311 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__311);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = mul i64 %%16, %%15, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1590_count);
  llvm_cbe_tmp__312 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__311&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__310&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__312&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1591_count);
  llvm_cbe_tmp__313 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__313);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%17, %%18, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1592_count);
  llvm_cbe_tmp__314 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__312&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__313&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__314&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1593_count);
  llvm_cbe_tmp__315 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i8* %%20, i64 %%19, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1594_count);
  llvm_cbe_tmp__316 = ( char *)(&llvm_cbe_tmp__315[(((signed long long )llvm_cbe_tmp__314))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__314));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%14, i8* %%21, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1595_count);
  *llvm_cbe_tmp__316 = llvm_cbe_tmp__309;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__309);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1596_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = lshr i8 %%w, 5, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1601_count);
  llvm_cbe_tmp__317 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )5)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__317&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = and i8 %%22, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1602_count);
  llvm_cbe_tmp__318 = (unsigned char )((unsigned char )(llvm_cbe_tmp__317 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1605_count);
  llvm_cbe_tmp__319 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__319);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1606_count);
  llvm_cbe_tmp__320 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = mul i64 %%25, %%24, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1607_count);
  llvm_cbe_tmp__321 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__320&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__319&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__321&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1608_count);
  llvm_cbe_tmp__322 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%26, %%27, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1609_count);
  llvm_cbe_tmp__323 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__321&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__322&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__323&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1610_count);
  llvm_cbe_tmp__324 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%29, i64 %%28, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1611_count);
  llvm_cbe_tmp__325 = ( char *)(&llvm_cbe_tmp__324[(((signed long long )llvm_cbe_tmp__323))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__323));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* %%30, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1612_count);
  *llvm_cbe_tmp__325 = llvm_cbe_tmp__318;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1613_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = lshr i8 %%w, 4, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1618_count);
  llvm_cbe_tmp__326 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )4)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__326&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = and i8 %%31, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1619_count);
  llvm_cbe_tmp__327 = (unsigned char )((unsigned char )(llvm_cbe_tmp__326 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1622_count);
  llvm_cbe_tmp__328 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__328);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1623_count);
  llvm_cbe_tmp__329 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = mul i64 %%34, %%33, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1624_count);
  llvm_cbe_tmp__330 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__329&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__328&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__330&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1625_count);
  llvm_cbe_tmp__331 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__331);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add i64 %%35, %%36, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1626_count);
  llvm_cbe_tmp__332 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__330&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__331&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__332&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1627_count);
  llvm_cbe_tmp__333 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds i8* %%38, i64 %%37, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1628_count);
  llvm_cbe_tmp__334 = ( char *)(&llvm_cbe_tmp__333[(((signed long long )llvm_cbe_tmp__332))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__332));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%32, i8* %%39, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1629_count);
  *llvm_cbe_tmp__334 = llvm_cbe_tmp__327;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1630_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = lshr i8 %%w, 3, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1635_count);
  llvm_cbe_tmp__335 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )3)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__335&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = and i8 %%40, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1636_count);
  llvm_cbe_tmp__336 = (unsigned char )((unsigned char )(llvm_cbe_tmp__335 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1639_count);
  llvm_cbe_tmp__337 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__337);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1640_count);
  llvm_cbe_tmp__338 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul i64 %%43, %%42, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1641_count);
  llvm_cbe_tmp__339 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__338&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__337&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__339&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1642_count);
  llvm_cbe_tmp__340 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__340);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add i64 %%44, %%45, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1643_count);
  llvm_cbe_tmp__341 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__339&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__340&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__341&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1644_count);
  llvm_cbe_tmp__342 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds i8* %%47, i64 %%46, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1645_count);
  llvm_cbe_tmp__343 = ( char *)(&llvm_cbe_tmp__342[(((signed long long )llvm_cbe_tmp__341))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__341));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%41, i8* %%48, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1646_count);
  *llvm_cbe_tmp__343 = llvm_cbe_tmp__336;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__336);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1647_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = lshr i8 %%w, 2, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1652_count);
  llvm_cbe_tmp__344 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )2)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__344&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = and i8 %%49, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1653_count);
  llvm_cbe_tmp__345 = (unsigned char )((unsigned char )(llvm_cbe_tmp__344 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1656_count);
  llvm_cbe_tmp__346 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__346);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1657_count);
  llvm_cbe_tmp__347 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__347);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = mul i64 %%52, %%51, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1658_count);
  llvm_cbe_tmp__348 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__347&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__346&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__348&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1659_count);
  llvm_cbe_tmp__349 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__349);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = add i64 %%53, %%54, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1660_count);
  llvm_cbe_tmp__350 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__348&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__349&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__350&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1661_count);
  llvm_cbe_tmp__351 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = getelementptr inbounds i8* %%56, i64 %%55, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1662_count);
  llvm_cbe_tmp__352 = ( char *)(&llvm_cbe_tmp__351[(((signed long long )llvm_cbe_tmp__350))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__350));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%50, i8* %%57, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1663_count);
  *llvm_cbe_tmp__352 = llvm_cbe_tmp__345;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__345);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1664_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = lshr i8 %%w, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1669_count);
  llvm_cbe_tmp__353 = (unsigned char )((unsigned char )(((unsigned char )(((unsigned char )(llvm_cbe_w&255ull)) >> ((unsigned char )(((unsigned char )1)&255ull))))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__353&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = and i8 %%58, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1670_count);
  llvm_cbe_tmp__354 = (unsigned char )((unsigned char )(llvm_cbe_tmp__353 & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1673_count);
  llvm_cbe_tmp__355 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1674_count);
  llvm_cbe_tmp__356 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__356);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = mul i64 %%61, %%60, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1675_count);
  llvm_cbe_tmp__357 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__356&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__355&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__357&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1676_count);
  llvm_cbe_tmp__358 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__358);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = add i64 %%62, %%63, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1677_count);
  llvm_cbe_tmp__359 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__357&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__358&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__359&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1678_count);
  llvm_cbe_tmp__360 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = getelementptr inbounds i8* %%65, i64 %%64, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1679_count);
  llvm_cbe_tmp__361 = ( char *)(&llvm_cbe_tmp__360[(((signed long long )llvm_cbe_tmp__359))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__359));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%59, i8* %%66, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1680_count);
  *llvm_cbe_tmp__361 = llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__354);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1681_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = and i8 %%w, 1, !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1686_count);
  llvm_cbe_tmp__362 = (unsigned char )((unsigned char )(llvm_cbe_w & ((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i64* %%1, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1689_count);
  llvm_cbe_tmp__363 = (unsigned long long )*llvm_cbe_tmp__296;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__363);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1690_count);
  llvm_cbe_tmp__364 = (unsigned long long )*llvm_cbe_tmp__297;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__364);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = mul i64 %%69, %%68, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1691_count);
  llvm_cbe_tmp__365 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__364&18446744073709551615ull)) * ((unsigned long long )(llvm_cbe_tmp__363&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__365&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i64* %%3, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1692_count);
  llvm_cbe_tmp__366 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%70, %%71, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1693_count);
  llvm_cbe_tmp__367 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__365&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__366&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__367&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = load i8** %%4, align 8, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1694_count);
  llvm_cbe_tmp__368 = ( char *)*llvm_cbe_tmp__299;
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = getelementptr inbounds i8* %%73, i64 %%72, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1695_count);
  llvm_cbe_tmp__369 = ( char *)(&llvm_cbe_tmp__368[(((signed long long )llvm_cbe_tmp__367))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__367));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%67, i8* %%74, align 1, !dbg !9 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1696_count);
  *llvm_cbe_tmp__369 = llvm_cbe_tmp__362;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__362);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @next_bit(%%struct.scanner* %%scanner), !dbg !10 for 0x%I64xth hint within @put_codeword  --> \n", ++aesl_llvm_cbe_1697_count);
   /*tail*/ next_bit((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @put_codeword}\n");
  return;
}

