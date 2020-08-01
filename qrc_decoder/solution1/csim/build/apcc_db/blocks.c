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
extern  char block_sizes[164][6];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int get_bits(l_struct_OC_scanner *llvm_cbe_scanner, signed long long llvm_cbe_n);
static void aesl_internal_get_block(l_struct_OC_scanner *llvm_cbe_scanner);
void skip_bits(l_struct_OC_scanner *, signed long long );
unsigned char get_codeword(l_struct_OC_scanner *);


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

signed int get_bits(l_struct_OC_scanner *llvm_cbe_scanner, signed long long llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  signed long long *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
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
  signed long long *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  signed long long *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  signed long long *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned long long llvm_cbe__2e_in;
  unsigned long long llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__6;
  unsigned int llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  unsigned char llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned long long llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned int llvm_cbe__2e_lcssa;
  unsigned int llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @get_bits\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 7, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_16_count);
  llvm_cbe_tmp__1 = (signed long long *)(&llvm_cbe_scanner->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (unsigned long long )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
  if (((llvm_cbe_tmp__2&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__23;
  } else {
    goto llvm_cbe_tmp__24;
  }

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_get_block(%%struct.scanner* %%scanner), !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_20_count);
   /*tail*/ aesl_internal_get_block((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__24;

llvm_cbe_tmp__24:
  if (((llvm_cbe_n&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 10, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__3 = (signed long long *)(&llvm_cbe_scanner->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 8, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__4 = (signed long long *)(&llvm_cbe_scanner->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 11, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__5 = (signed long long *)(&llvm_cbe_scanner->field11);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned long long )llvm_cbe_n;   /* for PHI node */
  llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__25;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__25:
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i64 [ %%n, %%.lr.ph ], [ %%12, %%33  for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned long long )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%I64X",llvm_cbe__2e_in);
printf("\nn = 0x%I64X",llvm_cbe_n);
printf("\n = 0x%I64X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i32 [ 0, %%.lr.ph ], [ %%28, %%33  for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__6 = (unsigned int )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__6);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%.in, -1, !dbg !8 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__7 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_in&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__7&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%7, align 8, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__8 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%8, align 8, !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__9 = (unsigned long long )*llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
  if ((((unsigned long long )llvm_cbe_tmp__8&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__9&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__26;
  } else {
    goto llvm_cbe_tmp__27;
  }

llvm_cbe_tmp__28:
  if (((llvm_cbe_tmp__7&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__7;   /* for PHI node */
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe_tmp__25;
  }

llvm_cbe_tmp__26:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%7, align 8, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__10 = (unsigned long long )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (unsigned long long )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = shl i32 %%11, 1, !dbg !8 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__12 = (unsigned int )llvm_cbe_tmp__6 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 9, i64 %%18, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_scanner->field9[(((signed long long )llvm_cbe_tmp__10))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__14 = (unsigned char )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = zext i8 %%22 to i32, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__14&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = trunc i64 %%19 to i32, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )llvm_cbe_tmp__11&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sub i32 7, %%24, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(7u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__16&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = lshr i32 %%23, %%25, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) >> ((unsigned int )(llvm_cbe_tmp__17&4294967295ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = and i32 %%26, 1, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__19 = (unsigned int )llvm_cbe_tmp__18 & 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i32 %%27, %%20, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__20 = (unsigned int )llvm_cbe_tmp__19 | llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%19, 1, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__21 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__11&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__21&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%29, i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__5 = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
  if ((((unsigned long long )llvm_cbe_tmp__21&18446744073709551615ULL) > ((unsigned long long )7ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__29;
  } else {
    goto llvm_cbe_tmp__28;
  }

llvm_cbe_tmp__27:
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_get_block(%%struct.scanner* %%scanner), !dbg !6 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_39_count);
   /*tail*/ aesl_internal_get_block((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__26;

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%18, 1, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__22 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__10&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__22&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%32, i64* %%7, align 8, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_69_count);
  *llvm_cbe_tmp__3 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%9, align 8, !dbg !7 for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe_70_count);
  *llvm_cbe_tmp__5 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  goto llvm_cbe_tmp__28;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i32 [ 0, %%5 ], [ %%28, %%33  for 0x%I64xth hint within @get_bits  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned int )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @get_bits}\n");
  return llvm_cbe__2e_lcssa;
}


static void aesl_internal_get_block(l_struct_OC_scanner *llvm_cbe_scanner) {
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  signed int *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  signed int *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
   char *llvm_cbe_tmp__37;
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
  signed long long *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned char llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned char llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned char llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned char llvm_cbe__2e_in;
  unsigned char llvm_cbe__2e_in__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  signed long long *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  signed long long *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  signed long long *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  signed long long *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned char llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned char llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned char llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned long long llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge4_count = 0;
  unsigned long long llvm_cbe_storemerge4;
  unsigned long long llvm_cbe_storemerge4__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned char llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__66;
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
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  unsigned long long llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned char llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned long long llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned long long llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
   char *llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  unsigned char llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  unsigned int llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned long long llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned long long llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned char llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
   char *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
   char *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
   char *llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_get_block\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 2, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__30 = (signed int *)(&llvm_cbe_scanner->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i32* %%1, align 4, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__31 = (unsigned int )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i32 %%2, 2, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__32 = (unsigned int )llvm_cbe_tmp__31 << 2u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 3, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__33 = (signed int *)(&llvm_cbe_scanner->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i32* %%4, align 4, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__34 = (unsigned int )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%3, %%5, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_tmp__32&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__34&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__36 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 0, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__37 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 7, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__38 = (signed long long *)(&llvm_cbe_scanner->field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i64* %%9, align 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__39 = (unsigned long long )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )0ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%8, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__40 = (unsigned char )*llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i8 %%11 to i64, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__40&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__41);
  if ((((unsigned long long )llvm_cbe_tmp__39&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__41&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__98;
  } else {
    goto llvm_cbe_tmp__99;
  }

llvm_cbe_tmp__98:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 2, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__42 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__43 = (unsigned char )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__43;   /* for PHI node */
  goto llvm_cbe_tmp__100;

llvm_cbe_tmp__99:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 5, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__44 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )5ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__45 = (unsigned char )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
  llvm_cbe__2e_in__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__45;   /* for PHI node */
  goto llvm_cbe_tmp__100;

llvm_cbe_tmp__100:
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = phi i8 [ %%16, %%14 ], [ %%19, %%17 ], !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned char )llvm_cbe__2e_in__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.in = 0x%X",llvm_cbe__2e_in);
printf("\n = 0x%X",llvm_cbe_tmp__43);
printf("\n = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i8 %%.in to i64, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__46 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe__2e_in&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__47 = (signed long long *)(&llvm_cbe_scanner->field8);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%21, i64* %%22, align 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_148_count);
  *llvm_cbe_tmp__47 = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__48 = (signed long long *)(&llvm_cbe_scanner->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%23, align 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__49 = (unsigned long long )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%24, -1, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__49&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__50&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 5, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__51 = (signed long long *)(&llvm_cbe_scanner->field5);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%25, i64* %%26, align 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_153_count);
  *llvm_cbe_tmp__51 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 6, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__52 = (signed long long *)(&llvm_cbe_scanner->field6);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%25, i64* %%27, align 8, !dbg !6 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_155_count);
  *llvm_cbe_tmp__52 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 3, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__53 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )3ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i8* %%28, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__54 = (unsigned char )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i8 %%29, %%11, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__55 = (unsigned char )((unsigned char )(((unsigned char )(llvm_cbe_tmp__54&255ull)) + ((unsigned char )(llvm_cbe_tmp__40&255ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )(llvm_cbe_tmp__55&255ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 2, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__56 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )2ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i8* %%31, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__57 = (unsigned char )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
  if (((llvm_cbe_tmp__57&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e__crit_edge7;
  } else {
    goto llvm_cbe__2e_lr_2e_ph6;
  }

llvm_cbe__2e_lr_2e_ph6:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = shl i64 %%10, 3, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__58 = (unsigned long long )llvm_cbe_tmp__39 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = zext i8 %%30 to i64, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__59 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__55&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sub i64 %%35, %%10, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__60 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__60&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = shl i64 %%36, 3, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__61 = (unsigned long long )llvm_cbe_tmp__60 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i64 %%37, -8, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__62 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__61&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__62&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i8 %%32 to i64, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__63 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__57&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__63);
  llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__101;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__101:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge4 = phi i64 [ 0, %%.lr.ph6 ], [ %%43, %%40  for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_storemerge4_count);
  llvm_cbe_storemerge4 = (unsigned long long )llvm_cbe_storemerge4__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",llvm_cbe_storemerge4);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__66);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%34) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_181_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = tail call zeroext i8 @get_codeword(%%struct.scanner* %%scanner) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__64 = (unsigned char ) /*tail*/ get_codeword((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__64);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 9, i64 %%storemerge4, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_scanner->field9[(((signed long long )llvm_cbe_storemerge4))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge4 = 0x%I64X",((signed long long )llvm_cbe_storemerge4));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%41, i8* %%42, align 1, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_184_count);
  *llvm_cbe_tmp__65 = llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%38) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_185_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%storemerge4, 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__66 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge4&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__66&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__66&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__63&18446744073709551615ULL))) {
    llvm_cbe_storemerge4__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__66;   /* for PHI node */
    goto llvm_cbe_tmp__101;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge7:
  if (((llvm_cbe_tmp__57&255U) == (llvm_cbe__2e_in&255U))) {
    goto llvm_cbe_tmp__102;
  } else {
    goto llvm_cbe_tmp__103;
  }

llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i8 %%29 to i32, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__54&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = shl nuw nsw i32 %%47, 3, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_199_count);
  llvm_cbe_tmp__68 = (unsigned int )llvm_cbe_tmp__67 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = zext i32 %%48 to i64, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__69 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__68&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%49) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_201_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__69);
}
  goto llvm_cbe_tmp__104;

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = sub i64 %%10, %%12, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__70 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__41&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__70&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = shl i64 %%51, 3, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__71 = (unsigned long long )llvm_cbe_tmp__70 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%52) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_205_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__71);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = tail call zeroext i8 @get_codeword(%%struct.scanner* %%scanner) nounwind, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__72 = (unsigned char ) /*tail*/ get_codeword((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__72);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = add i64 %%21, -1, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__73 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__46&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__73&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 9, i64 %%54, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__74 = ( char *)(&llvm_cbe_scanner->field9[(((signed long long )llvm_cbe_tmp__73))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__73));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%53, i8* %%55, align 1, !dbg !7 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_209_count);
  *llvm_cbe_tmp__74 = llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = zext i8 %%30 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__75 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__55&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = sub i64 %%56, %%10, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__76 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__75&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__76&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = shl i64 %%57, 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__77 = (unsigned long long )llvm_cbe_tmp__76 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%58, -8, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%59) nounwind, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_214_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__78);
}
  goto llvm_cbe_tmp__104;

llvm_cbe_tmp__104:
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = getelementptr inbounds [164 x [6 x i8]]* @block_sizes, i64 0, i64 %%7, i64 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__79 = ( char *)(&block_sizes[(((signed long long )llvm_cbe_tmp__36))
#ifdef AESL_BC_SIM
 % 164
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 6
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__36));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__36) < 164)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )1ull) < 6)) fprintf(stderr, "%s:%d: warning: Read access out of array 'block_sizes' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = load i8* %%61, align 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__80 = (unsigned char )*llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = zext i8 %%62 to i32, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__81 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__80&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i8 %%32 to i32, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__82 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__57&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = sub nsw i32 %%63, %%64, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_220_count);
  llvm_cbe_tmp__83 = (unsigned int )((unsigned int )(llvm_cbe_tmp__81&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__82&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__83&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = sext i32 %%65 to i64, !dbg !9 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__84 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__84);
  if (((llvm_cbe_tmp__80&255U) == (llvm_cbe_tmp__57&255U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = shl i64 %%10, 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__85 = (unsigned long long )llvm_cbe_tmp__39 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = zext i8 %%30 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_234_count);
  llvm_cbe_tmp__86 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__55&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = sub i64 %%69, %%10, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__86&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__87&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = shl i64 %%70, 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_236_count);
  llvm_cbe_tmp__88 = (unsigned long long )llvm_cbe_tmp__87 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%71, -8, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__89 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__88&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__89&18446744073709551615ull)));
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__105;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__105:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph ], [ %%77, %%73  for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%68) nounwind, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_239_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__85);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = tail call zeroext i8 @get_codeword(%%struct.scanner* %%scanner) nounwind, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__90 = (unsigned char ) /*tail*/ get_codeword((l_struct_OC_scanner *)llvm_cbe_scanner);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__90);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = add i64 %%storemerge12, %%21, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__46&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 9, i64 %%75, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__92 = ( char *)(&llvm_cbe_scanner->field9[(((signed long long )llvm_cbe_tmp__91))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__91));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%74, i8* %%76, align 1, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_243_count);
  *llvm_cbe_tmp__92 = llvm_cbe_tmp__90;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @skip_bits(%%struct.scanner* %%scanner, i64 %%72) nounwind, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_244_count);
   /*tail*/ skip_bits((l_struct_OC_scanner *)llvm_cbe_scanner, llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i64 %%storemerge12, 1, !dbg !10 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__93 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__93&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__93&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__84&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__93;   /* for PHI node */
    goto llvm_cbe_tmp__105;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = add i64 %%10, 1, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__39&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%79, i64* %%9, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_256_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 10, !dbg !8 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_scanner->field10);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = bitcast i64* %%80 to i8*, !dbg !10 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__96 = ( char *)(( char *)llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = call i8* @memset(i8* %%81, i32 0, i64 16 for 0x%I64xth hint within @aesl_internal_get_block  --> \n", ++aesl_llvm_cbe_259_count);
  ( char *)memset(( char *)llvm_cbe_tmp__96, 0u, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",16ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__97);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_get_block}\n");
  return;
}

