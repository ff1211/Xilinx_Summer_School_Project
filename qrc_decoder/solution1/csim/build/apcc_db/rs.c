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
typedef struct l_struct_OC_poly l_struct_OC_poly;

/* Structure contents */
struct l_struct_OC_poly {
  unsigned long long field0;
   char field1[512];
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void rs_encode(signed long long llvm_cbe_n_data,  char *llvm_cbe_data,  char llvm_cbe_n_sym);
static void aesl_internal_rs_generator_poly(l_struct_OC_poly *llvm_cbe_g,  char llvm_cbe_n_sym);
static unsigned char aesl_internal_gf_mul( char llvm_cbe_x,  char llvm_cbe_y);
unsigned char rs_decode(signed long long llvm_cbe_n_data,  char *llvm_cbe_data,  char llvm_cbe_n_sym);
static unsigned char aesl_internal_rs_calc_syndromes(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd);
static void aesl_internal_rs_forney_syndromes(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos, l_struct_OC_poly *llvm_cbe_fsynd);
static unsigned char aesl_internal_rs_find_error(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos);
static void aesl_internal_rs_correct_errata(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos);
static void aesl_internal_gf_poly_mul(l_struct_OC_poly *llvm_cbe_dest, l_struct_OC_poly *llvm_cbe_p, l_struct_OC_poly *llvm_cbe_q);
static void aesl_internal_rs_fderivative(l_struct_OC_poly *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_p);
static unsigned char aesl_internal_gf_poly_eval(l_struct_OC_poly *llvm_cbe_p,  char llvm_cbe_x);
static unsigned char aesl_internal_gf_div( char llvm_cbe_x,  char llvm_cbe_y);
static void aesl_internal_gf_poly_scale(l_struct_OC_poly *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_p,  char llvm_cbe_x);
static void aesl_internal_gf_poly_add(l_struct_OC_poly *llvm_cbe_dest, l_struct_OC_poly *llvm_cbe_p, l_struct_OC_poly *llvm_cbe_q);
static unsigned char aesl_internal_max( char llvm_cbe_a,  char llvm_cbe_b);
static void aesl_internal_gf_init(void);


/* Global Variable Definitions and Initialization */
static  char aesl_internal_gf_exp[512];
static  char aesl_internal_gf_log[256];
static l_struct_OC_poly aesl_internal_rs_find_error_OC_old = { 0ull, "\x01\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" };
static unsigned char aesl_internal_gf_init_OC_done;


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

void rs_encode(signed long long llvm_cbe_n_data,  char *llvm_cbe_data,  char llvm_cbe_n_sym) {
  static  unsigned long long aesl_llvm_cbe_gen_count = 0;
  l_struct_OC_poly llvm_cbe_gen;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_old_count = 0;
   char llvm_cbe_old[512];    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_scevgep_count = 0;
   char *llvm_cbe_scevgep;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_op_count = 0;
  unsigned int llvm_cbe__2e_op;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  unsigned long long llvm_cbe_tmp__6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned char llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned long long llvm_cbe_tmp__11;
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
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  signed long long *llvm_cbe_tmp__12;
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
  unsigned long long llvm_cbe_tmp__13;
  unsigned long long llvm_cbe_tmp__13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge29_count = 0;
  unsigned int llvm_cbe_storemerge29;
  unsigned int llvm_cbe_storemerge29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned char llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge47_count = 0;
  unsigned long long llvm_cbe_storemerge47;
  unsigned long long llvm_cbe_storemerge47__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned char llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned char llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned char llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  unsigned long long llvm_cbe_tmp__27__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge35_count = 0;
  unsigned int llvm_cbe_storemerge35;
  unsigned int llvm_cbe_storemerge35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned char llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @rs_encode\n");
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_rs_generator_poly(%%struct.poly* %%gen, i8 zeroext %%n_sym), !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_16_count);
  aesl_internal_rs_generator_poly((l_struct_OC_poly *)(&llvm_cbe_gen), llvm_cbe_n_sym);
if (AESL_DEBUG_TRACE) {
printf("\nArgument n_sym = 0x%X",llvm_cbe_n_sym);
}
  if (((llvm_cbe_n_data&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_preheader11;
  } else {
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  }

llvm_cbe__2e_preheader11:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i8 %%n_sym to i32, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_n_sym&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
  if (((llvm_cbe_n_sym&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_preheader8;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13;
  }

llvm_cbe__2e_lr_2e_ph13:
if (AESL_DEBUG_TRACE)
printf("\n  %%scevgep = getelementptr i8* %%data, i64 %%n_dat for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_scevgep_count);
  llvm_cbe_scevgep = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_n_data))]);
if (AESL_DEBUG_TRACE) {
printf("\nn_data = 0x%I64X",((signed long long )llvm_cbe_n_data));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.op = add i32 %%2, -1, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe__2e_op_count);
  llvm_cbe__2e_op = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n.op = 0x%X\n", ((unsigned int )(llvm_cbe__2e_op&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = select i1 %%4, i32 %%.op, i32 0, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__2 = (unsigned int )(((((unsigned char )llvm_cbe_n_sym&255U) > ((unsigned char )((unsigned char )1)&255U))) ? ((unsigned int )llvm_cbe__2e_op) : ((unsigned int )0u));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%5 to i6 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__3 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__2&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%6, 1, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__4 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__4&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memset(i8* %%scevgep, i32 0, i64 %%7 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_58_count);
  ( char *)memset(( char *)llvm_cbe_scevgep, 0u, llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__4);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__5);
}
  goto llvm_cbe__2e_preheader8;

  do {     /* Syntactic loop '.lr.ph16' to make GCC happy */
llvm_cbe__2e_lr_2e_ph16:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = phi i64 [ %%14, %%.lr.ph16 ], [ 0, %%0  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__6 = (unsigned long long )llvm_cbe_tmp__6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__6);
printf("\n = 0x%I64X",llvm_cbe_tmp__11);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ %%13, %%.lr.ph16 ], [ 0, %%0  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",llvm_cbe_tmp__10);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i8* %%data, i64 %%9, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__6))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__8 = (unsigned char )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [512 x i8]* %%old, i64 0, i64 %%9, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_old[(((signed long long )llvm_cbe_tmp__6))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__6));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__6) < 512 && "Write access out of array 'old' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%12, align 1, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_64_count);
  *llvm_cbe_tmp__9 = llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = add nsw i32 %%storemerge14, 1, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !12 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
  if ((((unsigned long long )llvm_cbe_tmp__11&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_n_data&18446744073709551615ULL))) {
    llvm_cbe_tmp__6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__11;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph16;
  } else {
    goto llvm_cbe__2e_preheader11;
  }

  } while (1); /* end of syntactic loop '.lr.ph16' */
llvm_cbe__2e_preheader8:
  if (((llvm_cbe_n_data&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph10;
  }

llvm_cbe__2e_lr_2e_ph10:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.poly* %%gen, i64 0, i32 0, !dbg !16 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__12 = (signed long long *)(&llvm_cbe_gen.field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__13__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__33;

llvm_cbe__2e_preheader:
  if (((llvm_cbe_n_data&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_tmp__27__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i64 [ 0, %%.lr.ph10 ], [ %%33, %%.loopexit  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__13 = (unsigned long long )llvm_cbe_tmp__13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__13);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge29 = phi i32 [ 0, %%.lr.ph10 ], [ %%32, %%.loopexit  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_storemerge29_count);
  llvm_cbe_storemerge29 = (unsigned int )llvm_cbe_storemerge29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge29 = 0x%X",llvm_cbe_storemerge29);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%data, i64 %%18, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__14 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__15 = (unsigned char )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
  if (((llvm_cbe_tmp__15&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add nsw i32 %%storemerge29, 1, !dbg !15 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_storemerge29&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = sext i32 %%32 to i64, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__26 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
  if ((((unsigned long long )llvm_cbe_tmp__26&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_n_data&18446744073709551615ULL))) {
    llvm_cbe_tmp__13__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__26;   /* for PHI node */
    llvm_cbe_storemerge29__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__25;   /* for PHI node */
    goto llvm_cbe_tmp__33;
  } else {
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '.preheader6' to make GCC happy */
llvm_cbe__2e_preheader6:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge47 = phi i64 [ %%29, %%.preheader6 ], [ 0, %%17  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_storemerge47_count);
  llvm_cbe_storemerge47 = (unsigned long long )llvm_cbe_storemerge47__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge47 = 0x%I64X",llvm_cbe_storemerge47);
printf("\n = 0x%I64X",llvm_cbe_tmp__23);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds %%struct.poly* %%gen, i64 0, i32 1, i64 %%storemerge47, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_gen.field1[(((signed long long )llvm_cbe_storemerge47))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge47 = 0x%I64X",((signed long long )llvm_cbe_storemerge47));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__17 = (unsigned char )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%23, i8 zeroext %%20), !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__18 = (unsigned char )aesl_internal_gf_mul(llvm_cbe_tmp__17, llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__17);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__15);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__18);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge47, %%18, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__19 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__13&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__19&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%data, i64 %%25, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__20 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__21 = (unsigned char )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = xor i8 %%27, %%24, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__22 = (unsigned char )((unsigned char )(llvm_cbe_tmp__21 ^ llvm_cbe_tmp__18));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%28, i8* %%26, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_134_count);
  *llvm_cbe_tmp__20 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%storemerge47, 1, !dbg !16 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__23 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge47&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__23&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i64* %%16, align 8, !dbg !16 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__24 = (unsigned long long )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__24);
  if ((((unsigned long long )llvm_cbe_tmp__23&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__24&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge47__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__23;   /* for PHI node */
    goto llvm_cbe__2e_preheader6;
  }

  } while (1); /* end of syntactic loop '.preheader6' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = phi i64 [ %%40, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__27 = (unsigned long long )llvm_cbe_tmp__27__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__27);
printf("\n = 0x%I64X",llvm_cbe_tmp__32);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge35 = phi i32 [ %%39, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_storemerge35_count);
  llvm_cbe_storemerge35 = (unsigned int )llvm_cbe_storemerge35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35 = 0x%X",llvm_cbe_storemerge35);
printf("\n = 0x%X",llvm_cbe_tmp__31);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds [512 x i8]* %%old, i64 0, i64 %%35, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_old[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__27) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'old' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i8* %%36, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__29 = (unsigned char )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%data, i64 %%35, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_tmp__27))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%37, i8* %%38, align 1, !dbg !14 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_168_count);
  *llvm_cbe_tmp__30 = llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add nsw i32 %%storemerge35, 1, !dbg !16 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_storemerge35&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sext i32 %%39 to i64, !dbg !13 for 0x%I64xth hint within @rs_encode  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__32 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
  if ((((unsigned long long )llvm_cbe_tmp__32&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_n_data&18446744073709551615ULL))) {
    llvm_cbe_tmp__27__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__32;   /* for PHI node */
    llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__31;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @rs_encode}\n");
  return;
}


static void aesl_internal_rs_generator_poly(l_struct_OC_poly *llvm_cbe_g,  char llvm_cbe_n_sym) {
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  l_struct_OC_poly llvm_cbe_tmp;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  signed long long *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
   char *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  signed long long *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
   char *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned char llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_generator_poly\n");
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_init(), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_197_count);
  aesl_internal_gf_init();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%g, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_198_count);
  llvm_cbe_tmp__34 = (signed long long *)(&llvm_cbe_g->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%1, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_199_count);
  *llvm_cbe_tmp__34 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.poly* %%g, i64 0, i32 1, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__35 = ( char *)(&llvm_cbe_g->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%2, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_201_count);
  *llvm_cbe_tmp__35 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  if (((llvm_cbe_n_sym&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__36 = (signed long long *)(&llvm_cbe_tmp.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 1, i64 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__37 = ( char *)(&llvm_cbe_tmp.field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 1, i64 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_tmp.field1[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%n_sym to i6 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__39 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_n_sym&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__44;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__44:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%.lr.ph ], [ %%12, %%8  for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%4, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_214_count);
  *llvm_cbe_tmp__36 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memset(i8* %%5, i32 0, i64 512 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_215_count);
  ( char *)memset(( char *)llvm_cbe_tmp__37, 0u, 512ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",512ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%5, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_216_count);
  *llvm_cbe_tmp__37 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%storemerge1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__41 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_storemerge1))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge1) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_218_count);
  llvm_cbe_tmp__42 = (unsigned char )*llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%6, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_219_count);
  *llvm_cbe_tmp__38 = llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_mul(%%struct.poly* %%g, %%struct.poly* %%g, %%struct.poly* %%tmp), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_220_count);
  aesl_internal_gf_poly_mul((l_struct_OC_poly *)llvm_cbe_g, (l_struct_OC_poly *)llvm_cbe_g, (l_struct_OC_poly *)(&llvm_cbe_tmp));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_generator_poly  --> \n", ++aesl_llvm_cbe_221_count);
  llvm_cbe_tmp__43 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__43&18446744073709551615ull)));
  if (((llvm_cbe_tmp__43&18446744073709551615ULL) == (llvm_cbe_tmp__39&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__43;   /* for PHI node */
    goto llvm_cbe_tmp__44;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_generator_poly}\n");
  return;
}


static unsigned char aesl_internal_gf_mul( char llvm_cbe_x,  char llvm_cbe_y) {
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned char llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned char llvm_cbe_storemerge;
  unsigned char llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_mul\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%1, %%2, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_x&255U) == (((unsigned char )0)&255U)) | ((llvm_cbe_y&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe_tmp__57;
  } else {
    goto llvm_cbe_tmp__58;
  }

llvm_cbe_tmp__58:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i8 %%x to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__45 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_x&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [256 x i8]* @aesl_internal_gf_log, i64 0, i64 %%4, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__46 = ( char *)(&aesl_internal_gf_log[(((signed long long )llvm_cbe_tmp__45))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__45));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__45) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_log' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__47 = (unsigned char )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%6 to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__47&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%y to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__49 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_y&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [256 x i8]* @aesl_internal_gf_log, i64 0, i64 %%8, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__50 = ( char *)(&aesl_internal_gf_log[(((signed long long )llvm_cbe_tmp__49))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__49));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__49) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_log' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_243_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_244_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__51&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%11, %%7, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_245_count);
  llvm_cbe_tmp__53 = (unsigned int )((unsigned int )(llvm_cbe_tmp__52&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__48&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__53&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_246_count);
  llvm_cbe_tmp__54 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%13, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_247_count);
  llvm_cbe_tmp__55 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__54))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__54));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__54) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_248_count);
  llvm_cbe_tmp__56 = (unsigned char )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__56;   /* for PHI node */
  goto llvm_cbe_tmp__57;

llvm_cbe_tmp__57:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i8 [ %%15, %%3 ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_gf_mul  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned char )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__56);
printf("\n = 0x%X",((unsigned char )0));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_mul}\n");
  return llvm_cbe_storemerge;
}


unsigned char rs_decode(signed long long llvm_cbe_n_data,  char *llvm_cbe_data,  char llvm_cbe_n_sym) {
  static  unsigned long long aesl_llvm_cbe_msg_count = 0;
  l_struct_OC_poly llvm_cbe_msg;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_synd_count = 0;
  l_struct_OC_poly llvm_cbe_synd;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_pos_count = 0;
  l_struct_OC_poly llvm_cbe_pos;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_fsynd_count = 0;
  l_struct_OC_poly llvm_cbe_fsynd;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  signed long long *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned long long llvm_cbe_storemerge3;
  unsigned long long llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  unsigned char llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
   char *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  signed long long *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  unsigned char llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  signed long long *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned int llvm_cbe_tmp__69;
  unsigned int llvm_cbe_tmp__69__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
   char *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  unsigned char llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned char llvm_cbe_tmp__74;
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
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
   char *llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  unsigned char llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
   char *llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned char llvm_cbe_tmp__79;
  unsigned char llvm_cbe_tmp__79__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @rs_decode\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add i64 %%n_data, -1, !dbg !12 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_261_count);
  llvm_cbe_tmp__59 = (unsigned long long )((unsigned long long )(llvm_cbe_n_data&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_262_count);
  llvm_cbe_tmp__60 = (signed long long *)(&llvm_cbe_msg.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%1, i64* %%2, align 8, !dbg !12 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_263_count);
  *llvm_cbe_tmp__60 = llvm_cbe_tmp__59;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__59);
  if (((llvm_cbe_n_data&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph4;
  }

  do {     /* Syntactic loop '.lr.ph4' to make GCC happy */
llvm_cbe__2e_lr_2e_ph4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i64 [ %%7, %%.lr.ph4 ], [ 0, %%0  for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned long long )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",llvm_cbe_storemerge3);
printf("\n = 0x%I64X",llvm_cbe_tmp__64);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%data, i64 %%storemerge3, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_275_count);
  llvm_cbe_tmp__61 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__62 = (unsigned char )*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 1, i64 %%storemerge3, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__63 = ( char *)(&llvm_cbe_msg.field1[(((signed long long )llvm_cbe_storemerge3))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%I64X",((signed long long )llvm_cbe_storemerge3));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%6, align 1, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_278_count);
  *llvm_cbe_tmp__63 = llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge3, 1, !dbg !14 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__64 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge3&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__64&18446744073709551615ull)));
  if (((llvm_cbe_tmp__64&18446744073709551615ULL) == (llvm_cbe_n_data&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__64;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph4;
  }

  } while (1); /* end of syntactic loop '.lr.ph4' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%n_sym to i64, !dbg !14 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_291_count);
  llvm_cbe_tmp__65 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_n_sym&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_292_count);
  llvm_cbe_tmp__66 = (signed long long *)(&llvm_cbe_synd.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%9, align 8, !dbg !14 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_293_count);
  *llvm_cbe_tmp__66 = llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call fastcc zeroext i8 @aesl_internal_rs_calc_syndromes(%%struct.poly* %%msg, %%struct.poly* %%synd), !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_294_count);
  llvm_cbe_tmp__67 = (unsigned char )aesl_internal_rs_calc_syndromes((l_struct_OC_poly *)(&llvm_cbe_msg), (l_struct_OC_poly *)(&llvm_cbe_synd));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__67);
}
  if (((llvm_cbe_tmp__67&255U) == (((unsigned char )0)&255U))) {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe_tmp__80;
  } else {
    goto llvm_cbe_tmp__81;
  }

llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 0, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__68 = (signed long long *)(&llvm_cbe_pos.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%13, align 8, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_299_count);
  *llvm_cbe_tmp__68 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe_tmp__69__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = phi i32 [ 0, %%12 ], [ %%15, %%memcpy ], !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__69 = (unsigned int )llvm_cbe_tmp__69__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__69);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__70);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i32 %%14, 1, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(llvm_cbe_tmp__69&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__70&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i32 %%14 to i64, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__71 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 1, i64 %%16, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__72 = ( char *)(&llvm_cbe_pos.field1[(((signed long long )llvm_cbe_tmp__71))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__71));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%17, align 1, !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_305_count);
  *llvm_cbe_tmp__72 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
  if (((llvm_cbe_tmp__69&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe_tmp__82;
  } else {
    llvm_cbe_tmp__69__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__70;   /* for PHI node */
    goto llvm_cbe_memcpy;
  }

  } while (1); /* end of syntactic loop 'memcpy' */
llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_rs_forney_syndromes(%%struct.poly* %%msg, %%struct.poly* %%synd, %%struct.poly* %%pos, %%struct.poly* %%fsynd), !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_309_count);
  aesl_internal_rs_forney_syndromes((l_struct_OC_poly *)(&llvm_cbe_msg), (l_struct_OC_poly *)(&llvm_cbe_synd), (l_struct_OC_poly *)(&llvm_cbe_pos), (l_struct_OC_poly *)(&llvm_cbe_fsynd));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = call fastcc zeroext i8 @aesl_internal_rs_find_error(%%struct.poly* %%msg, %%struct.poly* %%fsynd, %%struct.poly* %%pos), !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_310_count);
  llvm_cbe_tmp__73 = (unsigned char )aesl_internal_rs_find_error((l_struct_OC_poly *)(&llvm_cbe_msg), (l_struct_OC_poly *)(&llvm_cbe_fsynd), (l_struct_OC_poly *)(&llvm_cbe_pos));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__73);
}
  if (((llvm_cbe_tmp__73&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__83;
  } else {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__83:
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_rs_correct_errata(%%struct.poly* %%msg, %%struct.poly* %%synd, %%struct.poly* %%pos), !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_313_count);
  aesl_internal_rs_correct_errata((l_struct_OC_poly *)(&llvm_cbe_msg), (l_struct_OC_poly *)(&llvm_cbe_synd), (l_struct_OC_poly *)(&llvm_cbe_pos));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call fastcc zeroext i8 @aesl_internal_rs_calc_syndromes(%%struct.poly* %%msg, %%struct.poly* %%synd), !dbg !15 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__74 = (unsigned char )aesl_internal_rs_calc_syndromes((l_struct_OC_poly *)(&llvm_cbe_msg), (l_struct_OC_poly *)(&llvm_cbe_synd));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__74);
}
  if (((llvm_cbe_tmp__74&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned char )((unsigned char )1);   /* for PHI node */
    goto llvm_cbe_tmp__80;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_n_data&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ %%28, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",llvm_cbe_tmp__78);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 1, i64 %%storemerge12, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__75 = ( char *)(&llvm_cbe_msg.field1[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8* %%25, align 1, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__76 = (unsigned char )*llvm_cbe_tmp__75;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds i8* %%data, i64 %%storemerge12, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__77 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%26, i8* %%27, align 1, !dbg !13 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_329_count);
  *llvm_cbe_tmp__77 = llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%storemerge12, 1, !dbg !14 for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
  if (((llvm_cbe_tmp__78&18446744073709551615ULL) == (llvm_cbe_n_data&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__78;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  llvm_cbe_tmp__79__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
  goto llvm_cbe_tmp__80;

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i8 [ 0, %%._crit_edge ], [ 1, %%19 ], [ 1, %%22 ], [ 0, %%.loopexit  for 0x%I64xth hint within @rs_decode  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__79 = (unsigned char )llvm_cbe_tmp__79__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__79);
printf("\n = 0x%X",((unsigned char )0));
printf("\n = 0x%X",((unsigned char )1));
printf("\n = 0x%X",((unsigned char )1));
printf("\n = 0x%X",((unsigned char )0));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @rs_decode}\n");
  return llvm_cbe_tmp__79;
}


static unsigned char aesl_internal_rs_calc_syndromes(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd) {
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  signed long long *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned char llvm_cbe_tmp__86;
  unsigned char llvm_cbe_tmp__86__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned char llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  unsigned char llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
   char *llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned char llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned long long llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned char llvm_cbe__2e_lcssa;
  unsigned char llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_calc_syndromes\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_gf_init(), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_349_count);
   /*tail*/ aesl_internal_gf_init();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__84 = (signed long long *)(&llvm_cbe_synd->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__85 = (unsigned long long )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__85);
  if (((llvm_cbe_tmp__85&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__86__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%10, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__91);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = phi i8 [ %%., %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__86 = (unsigned char )llvm_cbe_tmp__86__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__86);
printf("\n. = 0x%X",llvm_cbe__2e_);
printf("\n = 0x%X",((unsigned char )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__87 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_storemerge1))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_storemerge1) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__88 = (unsigned char )*llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call fastcc zeroext i8 @aesl_internal_gf_poly_eval(%%struct.poly* %%msg, i8 zeroext %%6), !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_364_count);
  llvm_cbe_tmp__89 = (unsigned char ) /*tail*/ aesl_internal_gf_poly_eval((l_struct_OC_poly *)llvm_cbe_msg, llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__88);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 1, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__90 = ( char *)(&llvm_cbe_synd->field1[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%8, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_366_count);
  *llvm_cbe_tmp__90 = llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%9, i8 %%4, i8 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned char )((((llvm_cbe_tmp__89&255U) == (((unsigned char )0)&255U))) ? ((unsigned char )llvm_cbe_tmp__86) : ((unsigned char )((unsigned char )1)));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add i64 %%storemerge1, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__91 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__91&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__92 = (unsigned long long )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__92);
  if ((((unsigned long long )llvm_cbe_tmp__91&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__92&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__91;   /* for PHI node */
    llvm_cbe_tmp__86__PHI_TEMPORARY = (unsigned char )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned char )llvm_cbe__2e_;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i8 [ 0, %%0 ], [ %%., %%.lr.ph  for 0x%I64xth hint within @aesl_internal_rs_calc_syndromes  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned char )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",((unsigned char )0));
printf("\n. = 0x%X",llvm_cbe__2e_);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_calc_syndromes}\n");
  return llvm_cbe__2e_lcssa;
}


static void aesl_internal_rs_forney_syndromes(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos, l_struct_OC_poly *llvm_cbe_fsynd) {
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge8_count = 0;
  unsigned int llvm_cbe_storemerge8;
  unsigned int llvm_cbe_storemerge8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
   char *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  unsigned char llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
   char *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  signed long long *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  signed long long *llvm_cbe_tmp__100;
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
  signed long long *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  signed long long *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  unsigned long long llvm_cbe_tmp__104__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned int llvm_cbe_storemerge14;
  unsigned int llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
   char *llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  unsigned char llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
   char *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  unsigned char llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned long long llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge23_count = 0;
  unsigned long long llvm_cbe_storemerge23;
  unsigned long long llvm_cbe_storemerge23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  unsigned char llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  unsigned char llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
   char *llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  unsigned char llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  unsigned char llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned long long llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  static  unsigned long long aesl_llvm_cbe_486_count = 0;
  static  unsigned long long aesl_llvm_cbe_487_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_forney_syndromes\n");
  llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__125;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__125:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8 = phi i32 [ 0, %%0 ], [ %%6, %%1  for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_storemerge8_count);
  llvm_cbe_storemerge8 = (unsigned int )llvm_cbe_storemerge8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8 = 0x%X",llvm_cbe_storemerge8);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__97);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = sext i32 %%storemerge8 to i64, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__93 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 1, i64 %%2, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__94 = ( char *)(&llvm_cbe_synd->field1[(((signed long long )llvm_cbe_tmp__93))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__93));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_405_count);
  llvm_cbe_tmp__95 = (unsigned char )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%fsynd, i64 0, i32 1, i64 %%2, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_406_count);
  llvm_cbe_tmp__96 = ( char *)(&llvm_cbe_fsynd->field1[(((signed long long )llvm_cbe_tmp__93))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__93));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%4, i8* %%5, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_407_count);
  *llvm_cbe_tmp__96 = llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge8, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_408_count);
  llvm_cbe_tmp__97 = (unsigned int )((unsigned int )(llvm_cbe_storemerge8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__97&4294967295ull)));
  if (((llvm_cbe_tmp__97&4294967295U) == (520u&4294967295U))) {
    goto llvm_cbe_tmp__126;
  } else {
    llvm_cbe_storemerge8__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__97;   /* for PHI node */
    goto llvm_cbe_tmp__125;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__126:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__98 = (signed long long *)(&llvm_cbe_synd->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__99 = (unsigned long long )*llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%fsynd, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__100 = (signed long long *)(&llvm_cbe_fsynd->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%9, i64* %%10, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_421_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__99;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_430_count);
  llvm_cbe_tmp__101 = (signed long long *)(&llvm_cbe_pos->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_431_count);
  llvm_cbe_tmp__102 = (unsigned long long )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
  if (((llvm_cbe_tmp__102&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge7;
  } else {
    goto llvm_cbe__2e_lr_2e_ph6;
  }

llvm_cbe__2e_lr_2e_ph6:
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_434_count);
  llvm_cbe_tmp__103 = (signed long long *)(&llvm_cbe_msg->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__104__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__127;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__127:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = phi i64 [ 0, %%.lr.ph6 ], [ %%37, %%._crit_edge  for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_436_count);
  llvm_cbe_tmp__104 = (unsigned long long )llvm_cbe_tmp__104__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__104);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i32 [ 0, %%.lr.ph6 ], [ %%36, %%._crit_edge  for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned int )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%X",llvm_cbe_storemerge14);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__122);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i64* %%14, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_437_count);
  llvm_cbe_tmp__105 = (unsigned long long )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 1, i64 %%16, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_438_count);
  llvm_cbe_tmp__106 = ( char *)(&llvm_cbe_pos->field1[(((signed long long )llvm_cbe_tmp__104))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__104));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_439_count);
  llvm_cbe_tmp__107 = (unsigned char )*llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i8 %%19 to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__108 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__107&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = sub i64 %%17, %%20, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__109 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__105&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__108&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__109&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%21, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__110 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__109))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__109));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__109) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__111 = (unsigned char )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i64* %%10, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__112 = (unsigned long long )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__112);
  if (((llvm_cbe_tmp__112&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ 0, %%15 ], [ %%33, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__120);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i64 %%.lcssa, -1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_472_count);
  llvm_cbe_tmp__121 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__121&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%35, i64* %%10, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_473_count);
  *llvm_cbe_tmp__100 = llvm_cbe_tmp__121;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__121);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add nsw i32 %%storemerge14, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_474_count);
  llvm_cbe_tmp__122 = (unsigned int )((unsigned int )(llvm_cbe_storemerge14&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__122&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = sext i32 %%36 to i64, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__123 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__124 = (unsigned long long )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__124);
  if ((((unsigned long long )llvm_cbe_tmp__123&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__124&18446744073709551615ULL))) {
    llvm_cbe_tmp__104__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__123;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__122;   /* for PHI node */
    goto llvm_cbe_tmp__127;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23 = phi i64 [ %%29, %%.lr.ph ], [ 0, %%15  for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_storemerge23_count);
  llvm_cbe_storemerge23 = (unsigned long long )llvm_cbe_storemerge23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",llvm_cbe_storemerge23);
printf("\n = 0x%I64X",llvm_cbe_tmp__116);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.poly* %%fsynd, i64 0, i32 1, i64 %%storemerge23, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_455_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_fsynd->field1[(((signed long long )llvm_cbe_storemerge23))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23 = 0x%I64X",((signed long long )llvm_cbe_storemerge23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_456_count);
  llvm_cbe_tmp__114 = (unsigned char )*llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = tail call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%27, i8 zeroext %%23), !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_457_count);
  llvm_cbe_tmp__115 = (unsigned char ) /*tail*/ aesl_internal_gf_mul(llvm_cbe_tmp__114, llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__114);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__111);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__115);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i64 %%storemerge23, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_458_count);
  llvm_cbe_tmp__116 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__116&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.poly* %%fsynd, i64 0, i32 1, i64 %%29, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_459_count);
  llvm_cbe_tmp__117 = ( char *)(&llvm_cbe_fsynd->field1[(((signed long long )llvm_cbe_tmp__116))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__116));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_460_count);
  llvm_cbe_tmp__118 = (unsigned char )*llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__118);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = xor i8 %%31, %%28, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_461_count);
  llvm_cbe_tmp__119 = (unsigned char )((unsigned char )(llvm_cbe_tmp__118 ^ llvm_cbe_tmp__115));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%32, i8* %%26, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_462_count);
  *llvm_cbe_tmp__113 = llvm_cbe_tmp__119;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i64* %%10, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_forney_syndromes  --> \n", ++aesl_llvm_cbe_469_count);
  llvm_cbe_tmp__120 = (unsigned long long )*llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__120);
  if ((((unsigned long long )llvm_cbe_tmp__116&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__120&18446744073709551615ULL))) {
    llvm_cbe_storemerge23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__116;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__120;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge7:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_forney_syndromes}\n");
  return;
}


static unsigned char aesl_internal_rs_find_error(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos) {
  static  unsigned long long aesl_llvm_cbe_err_count = 0;
  l_struct_OC_poly llvm_cbe_err;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_old_count = 0;
  l_struct_OC_poly llvm_cbe_old;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_new_count = 0;
  l_struct_OC_poly llvm_cbe_new;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
  static  unsigned long long aesl_llvm_cbe_499_count = 0;
  static  unsigned long long aesl_llvm_cbe_500_count = 0;
  signed long long *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_501_count = 0;
  static  unsigned long long aesl_llvm_cbe_502_count = 0;
  static  unsigned long long aesl_llvm_cbe_503_count = 0;
  unsigned int llvm_cbe_tmp__129;
  unsigned int llvm_cbe_tmp__129__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_504_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_505_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_506_count = 0;
   char *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_507_count = 0;
   char *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_508_count = 0;
  unsigned char llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_509_count = 0;
  static  unsigned long long aesl_llvm_cbe_510_count = 0;
  static  unsigned long long aesl_llvm_cbe_511_count = 0;
  static  unsigned long long aesl_llvm_cbe_512_count = 0;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
  signed long long *llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  unsigned int llvm_cbe_tmp__136;
  unsigned int llvm_cbe_tmp__136__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_517_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_518_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_519_count = 0;
   char *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_520_count = 0;
   char *llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_521_count = 0;
  unsigned char llvm_cbe_tmp__141;
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
  signed long long *llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_534_count = 0;
  unsigned long long llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  signed long long *llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  unsigned long long llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
   char *llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  unsigned char llvm_cbe_tmp__149;
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
  unsigned long long llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_558_count = 0;
  static  unsigned long long aesl_llvm_cbe_559_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge28_count = 0;
  unsigned long long llvm_cbe_storemerge28;
  unsigned long long llvm_cbe_storemerge28__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_560_count = 0;
  unsigned char llvm_cbe_tmp__151;
  unsigned char llvm_cbe_tmp__151__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_561_count = 0;
  unsigned long long llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_562_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_563_count = 0;
  unsigned char llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_564_count = 0;
  unsigned long long llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_565_count = 0;
   char *llvm_cbe_tmp__156;
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  unsigned char llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  unsigned char llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  unsigned char llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  unsigned long long llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa6_count = 0;
  unsigned char llvm_cbe__2e_lcssa6;
  unsigned char llvm_cbe__2e_lcssa6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
  static  unsigned long long aesl_llvm_cbe_585_count = 0;
  static  unsigned long long aesl_llvm_cbe_586_count = 0;
  unsigned long long llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_587_count = 0;
  static  unsigned long long aesl_llvm_cbe_588_count = 0;
  static  unsigned long long aesl_llvm_cbe_589_count = 0;
  static  unsigned long long aesl_llvm_cbe_590_count = 0;
  unsigned char llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_591_count = 0;
  static  unsigned long long aesl_llvm_cbe_592_count = 0;
  static  unsigned long long aesl_llvm_cbe_593_count = 0;
  static  unsigned long long aesl_llvm_cbe_594_count = 0;
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge35_count = 0;
  unsigned long long llvm_cbe_storemerge35;
  unsigned long long llvm_cbe_storemerge35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
   char *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  unsigned char llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
   char *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
  unsigned long long llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  unsigned long long llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
  unsigned long long llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_616_count = 0;
  static  unsigned long long aesl_llvm_cbe_617_count = 0;
  static  unsigned long long aesl_llvm_cbe_618_count = 0;
  static  unsigned long long aesl_llvm_cbe_619_count = 0;
  static  unsigned long long aesl_llvm_cbe_620_count = 0;
  static  unsigned long long aesl_llvm_cbe_621_count = 0;
  static  unsigned long long aesl_llvm_cbe_622_count = 0;
  static  unsigned long long aesl_llvm_cbe_623_count = 0;
  static  unsigned long long aesl_llvm_cbe_624_count = 0;
  static  unsigned long long aesl_llvm_cbe_625_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa11_count = 0;
  unsigned long long llvm_cbe__2e_lcssa11;
  unsigned long long llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
  unsigned long long llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  static  unsigned long long aesl_llvm_cbe_632_count = 0;
  static  unsigned long long aesl_llvm_cbe_633_count = 0;
  static  unsigned long long aesl_llvm_cbe_634_count = 0;
  static  unsigned long long aesl_llvm_cbe_635_count = 0;
  static  unsigned long long aesl_llvm_cbe_636_count = 0;
  static  unsigned long long aesl_llvm_cbe_637_count = 0;
  static  unsigned long long aesl_llvm_cbe_638_count = 0;
  static  unsigned long long aesl_llvm_cbe_639_count = 0;
  static  unsigned long long aesl_llvm_cbe_640_count = 0;
  signed long long *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_641_count = 0;
  unsigned long long llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_642_count = 0;
  signed long long *llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_643_count = 0;
  static  unsigned long long aesl_llvm_cbe_644_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  unsigned long long llvm_cbe_tmp__175__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_645_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  unsigned long long llvm_cbe_tmp__176__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_646_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_647_count = 0;
   char *llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_648_count = 0;
  unsigned char llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_649_count = 0;
  unsigned char llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_650_count = 0;
  static  unsigned long long aesl_llvm_cbe_651_count = 0;
  static  unsigned long long aesl_llvm_cbe_652_count = 0;
  unsigned long long llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_653_count = 0;
  unsigned char llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  unsigned long long llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
   char *llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  unsigned long long llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
  static  unsigned long long aesl_llvm_cbe_664_count = 0;
  unsigned long long llvm_cbe_tmp__187;
  unsigned long long llvm_cbe_tmp__187__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_665_count = 0;
  unsigned long long llvm_cbe_tmp__188;
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
  unsigned long long llvm_cbe_tmp__189;
  static  unsigned long long aesl_llvm_cbe_676_count = 0;
  static  unsigned long long aesl_llvm_cbe_677_count = 0;
  static  unsigned long long aesl_llvm_cbe_678_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned char llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_679_count = 0;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_find_error\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%err, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_500_count);
  llvm_cbe_tmp__128 = (signed long long *)(&llvm_cbe_err.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%1, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_501_count);
  *llvm_cbe_tmp__128 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%3, %%memcpy ], !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_503_count);
  llvm_cbe_tmp__129 = (unsigned int )llvm_cbe_tmp__129__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__129);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__130);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i32 %%2, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_504_count);
  llvm_cbe_tmp__130 = (unsigned int )((unsigned int )(llvm_cbe_tmp__129&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__130&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%2 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_505_count);
  llvm_cbe_tmp__131 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%err, i64 0, i32 1, i64 %%4, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_506_count);
  llvm_cbe_tmp__132 = ( char *)(&llvm_cbe_err.field1[(((signed long long )llvm_cbe_tmp__131))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* @aesl_internal_rs_find_error.old, i64 0, i32 1, i64 %%4, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_507_count);
  llvm_cbe_tmp__133 = ( char *)(&aesl_internal_rs_find_error_OC_old.field1[(((signed long long )llvm_cbe_tmp__131))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_508_count);
  llvm_cbe_tmp__134 = (unsigned char )*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%5, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_509_count);
  *llvm_cbe_tmp__132 = llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__134);
  if (((llvm_cbe_tmp__129&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe_tmp__190;
  } else {
    llvm_cbe_tmp__129__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__130;   /* for PHI node */
    goto llvm_cbe_memcpy;
  }

  } while (1); /* end of syntactic loop 'memcpy' */
llvm_cbe_tmp__190:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%old, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__135 = (signed long long *)(&llvm_cbe_old.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%10, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_514_count);
  *llvm_cbe_tmp__135 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe_tmp__136__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy1;

  do {     /* Syntactic loop 'memcpy1' to make GCC happy */
llvm_cbe_memcpy1:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi i32 [ 0, %%9 ], [ %%12, %%memcpy1 ], !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__136 = (unsigned int )llvm_cbe_tmp__136__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__136);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__137);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%11, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_517_count);
  llvm_cbe_tmp__137 = (unsigned int )((unsigned int )(llvm_cbe_tmp__136&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__137&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%11 to i64, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_518_count);
  llvm_cbe_tmp__138 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.poly* %%old, i64 0, i32 1, i64 %%13, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_519_count);
  llvm_cbe_tmp__139 = ( char *)(&llvm_cbe_old.field1[(((signed long long )llvm_cbe_tmp__138))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.poly* @aesl_internal_rs_find_error.old, i64 0, i32 1, i64 %%13, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_520_count);
  llvm_cbe_tmp__140 = ( char *)(&aesl_internal_rs_find_error_OC_old.field1[(((signed long long )llvm_cbe_tmp__138))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_521_count);
  llvm_cbe_tmp__141 = (unsigned char )*llvm_cbe_tmp__140;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__141);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%14, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_522_count);
  *llvm_cbe_tmp__139 = llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__141);
  if (((llvm_cbe_tmp__136&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    llvm_cbe_tmp__136__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__137;   /* for PHI node */
    goto llvm_cbe_memcpy1;
  }

  } while (1); /* end of syntactic loop 'memcpy1' */
llvm_cbe__2e_preheader10:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_533_count);
  llvm_cbe_tmp__142 = (signed long long *)(&llvm_cbe_synd->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i64* %%18, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_534_count);
  llvm_cbe_tmp__143 = (unsigned long long )*llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__143);
  if (((llvm_cbe_tmp__143&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge14;
  } else {
    goto llvm_cbe__2e_lr_2e_ph13;
  }

llvm_cbe__2e_lr_2e_ph13:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.poly* %%new, i64 0, i32 0, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_537_count);
  llvm_cbe_tmp__144 = (signed long long *)(&llvm_cbe_new.field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__191;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__191:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph13 ], [ %%56, %%55  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__168);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i64* %%10, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_539_count);
  llvm_cbe_tmp__145 = (unsigned long long )*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%23, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_540_count);
  llvm_cbe_tmp__146 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__145&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__146&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%24, i64* %%10, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_541_count);
  *llvm_cbe_tmp__135 = llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__146);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds %%struct.poly* %%old, i64 0, i32 1, i64 %%24, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_542_count);
  llvm_cbe_tmp__147 = ( char *)(&llvm_cbe_old.field1[(((signed long long )llvm_cbe_tmp__146))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__146));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%25, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_543_count);
  *llvm_cbe_tmp__147 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 1, i64 %%storemerge12, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_synd->field1[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = load i64* %%1, align 8, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_557_count);
  llvm_cbe_tmp__150 = (unsigned long long )*llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__150);
  if (((llvm_cbe_tmp__150&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa6__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__149;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    llvm_cbe_tmp__151__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__149;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe_tmp__192:
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add i64 %%storemerge12, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_615_count);
  llvm_cbe_tmp__168 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__168&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = load i64* %%18, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_625_count);
  llvm_cbe_tmp__169 = (unsigned long long )*llvm_cbe_tmp__142;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
  if ((((unsigned long long )llvm_cbe_tmp__168&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__169&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__168;   /* for PHI node */
    goto llvm_cbe_tmp__191;
  } else {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__169;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge14;
  }

llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa6 = phi i8 [ %%27, %%22 ], [ %%38, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe__2e_lcssa6_count);
  llvm_cbe__2e_lcssa6 = (unsigned char )llvm_cbe__2e_lcssa6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa6 = 0x%X",llvm_cbe__2e_lcssa6);
printf("\n = 0x%X",llvm_cbe_tmp__149);
printf("\n = 0x%X",llvm_cbe_tmp__159);
}
  if (((llvm_cbe__2e_lcssa6&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__192;
  } else {
    goto llvm_cbe_tmp__193;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge28 = phi i64 [ %%39, %%.lr.ph ], [ 1, %%22  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_storemerge28_count);
  llvm_cbe_storemerge28 = (unsigned long long )llvm_cbe_storemerge28__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge28 = 0x%I64X",llvm_cbe_storemerge28);
printf("\n = 0x%I64X",llvm_cbe_tmp__160);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = phi i8 [ %%38, %%.lr.ph ], [ %%27, %%22  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_560_count);
  llvm_cbe_tmp__151 = (unsigned char )llvm_cbe_tmp__151__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__151);
printf("\n = 0x%X",llvm_cbe_tmp__159);
printf("\n = 0x%X",llvm_cbe_tmp__149);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sub i64 %%28, %%storemerge28, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_561_count);
  llvm_cbe_tmp__152 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__150&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__152&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct.poly* %%err, i64 0, i32 1, i64 %%31, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_562_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_err.field1[(((signed long long )llvm_cbe_tmp__152))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__152));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = load i8* %%32, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_563_count);
  llvm_cbe_tmp__154 = (unsigned char )*llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = sub i64 %%storemerge12, %%storemerge28, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_564_count);
  llvm_cbe_tmp__155 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__155&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 1, i64 %%34, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_565_count);
  llvm_cbe_tmp__156 = ( char *)(&llvm_cbe_synd->field1[(((signed long long )llvm_cbe_tmp__155))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__155));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i8* %%35, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_566_count);
  llvm_cbe_tmp__157 = (unsigned char )*llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%33, i8 zeroext %%36), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_567_count);
  llvm_cbe_tmp__158 = (unsigned char )aesl_internal_gf_mul(llvm_cbe_tmp__154, llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__154);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__157);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__158);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = xor i8 %%37, %%30, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_568_count);
  llvm_cbe_tmp__159 = (unsigned char )((unsigned char )(llvm_cbe_tmp__158 ^ llvm_cbe_tmp__151));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add i64 %%storemerge28, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_575_count);
  llvm_cbe_tmp__160 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge28&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__160&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__160&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__150&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa6__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__159;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge28__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__160;   /* for PHI node */
    llvm_cbe_tmp__151__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__159;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe_tmp__194:
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_scale(%%struct.poly* %%new, %%struct.poly* %%old, i8 zeroext %%.lcssa6), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_612_count);
  aesl_internal_gf_poly_scale((l_struct_OC_poly *)(&llvm_cbe_new), (l_struct_OC_poly *)(&llvm_cbe_old), llvm_cbe__2e_lcssa6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument .lcssa6 = 0x%X",llvm_cbe__2e_lcssa6);
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_add(%%struct.poly* %%err, %%struct.poly* %%err, %%struct.poly* %%new), !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_613_count);
  aesl_internal_gf_poly_add((l_struct_OC_poly *)(&llvm_cbe_err), (l_struct_OC_poly *)(&llvm_cbe_err), (l_struct_OC_poly *)(&llvm_cbe_new));
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__192;

llvm_cbe_tmp__193:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%10, align 8, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_586_count);
  llvm_cbe_tmp__161 = (unsigned long long )*llvm_cbe_tmp__135;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__161);
  if ((((unsigned long long )llvm_cbe_tmp__161&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__150&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__195;
  } else {
    goto llvm_cbe_tmp__194;
  }

llvm_cbe_tmp__196:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i64* %%21, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_609_count);
  llvm_cbe_tmp__167 = (unsigned long long )*llvm_cbe_tmp__144;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__167);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%53, i64* %%1, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_610_count);
  *llvm_cbe_tmp__128 = llvm_cbe_tmp__167;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__167);
  goto llvm_cbe_tmp__194;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__197:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge35 = phi i64 [ 0, %%45 ], [ %%51, %%47  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_storemerge35_count);
  llvm_cbe_storemerge35 = (unsigned long long )llvm_cbe_storemerge35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35 = 0x%I64X",llvm_cbe_storemerge35);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__166);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.poly* %%new, i64 0, i32 1, i64 %%storemerge35, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_598_count);
  llvm_cbe_tmp__163 = ( char *)(&llvm_cbe_new.field1[(((signed long long )llvm_cbe_storemerge35))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35 = 0x%I64X",((signed long long )llvm_cbe_storemerge35));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i8* %%48, align 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_599_count);
  llvm_cbe_tmp__164 = (unsigned char )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = getelementptr inbounds %%struct.poly* %%err, i64 0, i32 1, i64 %%storemerge35, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_600_count);
  llvm_cbe_tmp__165 = ( char *)(&llvm_cbe_err.field1[(((signed long long )llvm_cbe_storemerge35))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge35 = 0x%I64X",((signed long long )llvm_cbe_storemerge35));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%49, i8* %%50, align 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_601_count);
  *llvm_cbe_tmp__165 = llvm_cbe_tmp__164;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add i64 %%storemerge35, 1, !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__166 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge35&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__166&18446744073709551615ull)));
  if (((llvm_cbe_tmp__166&18446744073709551615ULL) == (520ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__196;
  } else {
    llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__166;   /* for PHI node */
    goto llvm_cbe_tmp__197;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__195:
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_scale(%%struct.poly* %%new, %%struct.poly* %%old, i8 zeroext %%.lcssa6), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_589_count);
  aesl_internal_gf_poly_scale((l_struct_OC_poly *)(&llvm_cbe_new), (l_struct_OC_poly *)(&llvm_cbe_old), llvm_cbe__2e_lcssa6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument .lcssa6 = 0x%X",llvm_cbe__2e_lcssa6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = call fastcc zeroext i8 @aesl_internal_gf_div(i8 zeroext 1, i8 zeroext %%.lcssa6), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_590_count);
  llvm_cbe_tmp__162 = (unsigned char )aesl_internal_gf_div(((unsigned char )1), llvm_cbe__2e_lcssa6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )1));
printf("\nArgument .lcssa6 = 0x%X",llvm_cbe__2e_lcssa6);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__162);
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_scale(%%struct.poly* %%old, %%struct.poly* %%err, i8 zeroext %%46), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_591_count);
  aesl_internal_gf_poly_scale((l_struct_OC_poly *)(&llvm_cbe_old), (l_struct_OC_poly *)(&llvm_cbe_err), llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__162);
}
  llvm_cbe_storemerge35__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__197;

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge14:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa11 = phi i64 [ 0, %%.preheader10 ], [ %%57, %%55  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe__2e_lcssa11_count);
  llvm_cbe__2e_lcssa11 = (unsigned long long )llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa11 = 0x%I64X",llvm_cbe__2e_lcssa11);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__169);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i64* %%1, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__170 = (unsigned long long )*llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = lshr i64 %%.lcssa11, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe__2e_lcssa11&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__171&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__170&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__171&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__198;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_640_count);
  llvm_cbe_tmp__172 = (signed long long *)(&llvm_cbe_msg->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%62, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_641_count);
  llvm_cbe_tmp__173 = (unsigned long long )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_642_count);
  llvm_cbe_tmp__174 = (signed long long *)(&llvm_cbe_pos->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__173;   /* for PHI node */
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__176__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__199;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__199:
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = phi i64 [ %%63, %%.preheader ], [ %%83, %%80  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_644_count);
  llvm_cbe_tmp__175 = (unsigned long long )llvm_cbe_tmp__175__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__175);
printf("\n = 0x%I64X",llvm_cbe_tmp__173);
printf("\n = 0x%I64X",llvm_cbe_tmp__189);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ 0, %%.preheader ], [ %%82, %%80  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__188);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = phi i64 [ 0, %%.preheader ], [ %%81, %%80  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_645_count);
  llvm_cbe_tmp__176 = (unsigned long long )llvm_cbe_tmp__176__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__176);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__187);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = sub i64 255, %%storemerge14, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_646_count);
  llvm_cbe_tmp__177 = (unsigned long long )((unsigned long long )(255ull&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__177&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%68, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_647_count);
  llvm_cbe_tmp__178 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__177))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__177));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__177) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = load i8* %%69, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_648_count);
  llvm_cbe_tmp__179 = (unsigned char )*llvm_cbe_tmp__178;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = call fastcc zeroext i8 @aesl_internal_gf_poly_eval(%%struct.poly* %%err, i8 zeroext %%70), !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_649_count);
  llvm_cbe_tmp__180 = (unsigned char )aesl_internal_gf_poly_eval((l_struct_OC_poly *)(&llvm_cbe_err), llvm_cbe_tmp__179);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__179);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__180);
}
  if (((llvm_cbe_tmp__180&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__200;
  } else {
    llvm_cbe_tmp__187__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__176;   /* for PHI node */
    goto llvm_cbe_tmp__201;
  }

llvm_cbe_tmp__201:
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = phi i64 [ %%67, %%65 ], [ %%79, %%73  for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_664_count);
  llvm_cbe_tmp__187 = (unsigned long long )llvm_cbe_tmp__187__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__187);
printf("\n = 0x%I64X",llvm_cbe_tmp__176);
printf("\n = 0x%I64X",llvm_cbe_tmp__186);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = add i64 %%storemerge14, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_665_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load i64* %%62, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_675_count);
  llvm_cbe_tmp__189 = (unsigned long long )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__189);
  if ((((unsigned long long )llvm_cbe_tmp__188&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__189&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__202;
  } else {
    llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__189;   /* for PHI node */
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__188;   /* for PHI node */
    llvm_cbe_tmp__176__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__187;   /* for PHI node */
    goto llvm_cbe_tmp__199;
  }

llvm_cbe_tmp__200:
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = sub i64 %%66, %%storemerge14, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_652_count);
  llvm_cbe_tmp__181 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__175&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__181&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = trunc i64 %%74 to i8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_653_count);
  llvm_cbe_tmp__182 = (unsigned char )((unsigned char )llvm_cbe_tmp__181&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i64* %%64, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_654_count);
  llvm_cbe_tmp__183 = (unsigned long long )*llvm_cbe_tmp__174;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = add i64 %%76, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__184 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__184&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%77, i64* %%64, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_656_count);
  *llvm_cbe_tmp__174 = llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__184);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 1, i64 %%76, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_657_count);
  llvm_cbe_tmp__185 = ( char *)(&llvm_cbe_pos->field1[(((signed long long )llvm_cbe_tmp__183))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%75, i8* %%78, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_658_count);
  *llvm_cbe_tmp__185 = llvm_cbe_tmp__182;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__182);
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = add i64 %%67, 1, !dbg !18 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe_659_count);
  llvm_cbe_tmp__186 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__176&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__186&18446744073709551615ull)));
  llvm_cbe_tmp__187__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__186;   /* for PHI node */
  goto llvm_cbe_tmp__201;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__202:
if (AESL_DEBUG_TRACE)
printf("\n  %%. = zext i1 %%86 to i8, !dbg !18 for 0x%I64xth hint within @aesl_internal_rs_find_error  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned char )((unsigned char )(bool )(((unsigned long long )llvm_cbe_tmp__187&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__170&18446744073709551615ULL))&1U);
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_find_error}\n");
  return llvm_cbe__2e_;
llvm_cbe_tmp__198:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_find_error}\n");
  return ((unsigned char )1);
}


static void aesl_internal_rs_correct_errata(l_struct_OC_poly *llvm_cbe_msg, l_struct_OC_poly *llvm_cbe_synd, l_struct_OC_poly *llvm_cbe_pos) {
  static  unsigned long long aesl_llvm_cbe_q_count = 0;
  l_struct_OC_poly llvm_cbe_q;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_tmp_count = 0;
  l_struct_OC_poly llvm_cbe_tmp;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_p_count = 0;
  l_struct_OC_poly llvm_cbe_p;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_qprime_count = 0;
  l_struct_OC_poly llvm_cbe_qprime;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_695_count = 0;
  static  unsigned long long aesl_llvm_cbe_696_count = 0;
  static  unsigned long long aesl_llvm_cbe_697_count = 0;
  static  unsigned long long aesl_llvm_cbe_698_count = 0;
  signed long long *llvm_cbe_tmp__203;
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  unsigned int llvm_cbe_tmp__204;
  unsigned int llvm_cbe_tmp__204__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  unsigned int llvm_cbe_tmp__205;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  unsigned long long llvm_cbe_tmp__206;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
   char *llvm_cbe_tmp__207;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
   char *llvm_cbe_tmp__208;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
  unsigned char llvm_cbe_tmp__209;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  static  unsigned long long aesl_llvm_cbe_710_count = 0;
  static  unsigned long long aesl_llvm_cbe_711_count = 0;
  signed long long *llvm_cbe_tmp__210;
  static  unsigned long long aesl_llvm_cbe_712_count = 0;
  static  unsigned long long aesl_llvm_cbe_713_count = 0;
   char *llvm_cbe_tmp__211;
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
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  signed long long *llvm_cbe_tmp__212;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
  unsigned long long llvm_cbe_tmp__213;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  signed long long *llvm_cbe_tmp__214;
  static  unsigned long long aesl_llvm_cbe_736_count = 0;
   char *llvm_cbe_tmp__215;
  static  unsigned long long aesl_llvm_cbe_737_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned long long llvm_cbe_storemerge12;
  unsigned long long llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_738_count = 0;
  unsigned long long llvm_cbe_tmp__216;
  static  unsigned long long aesl_llvm_cbe_739_count = 0;
   char *llvm_cbe_tmp__217;
  static  unsigned long long aesl_llvm_cbe_740_count = 0;
  unsigned char llvm_cbe_tmp__218;
  static  unsigned long long aesl_llvm_cbe_741_count = 0;
  unsigned long long llvm_cbe_tmp__219;
  static  unsigned long long aesl_llvm_cbe_742_count = 0;
  unsigned long long llvm_cbe_tmp__220;
  static  unsigned long long aesl_llvm_cbe_743_count = 0;
   char *llvm_cbe_tmp__221;
  static  unsigned long long aesl_llvm_cbe_744_count = 0;
  unsigned char llvm_cbe_tmp__222;
  static  unsigned long long aesl_llvm_cbe_745_count = 0;
  static  unsigned long long aesl_llvm_cbe_746_count = 0;
  static  unsigned long long aesl_llvm_cbe_747_count = 0;
  static  unsigned long long aesl_llvm_cbe_748_count = 0;
  static  unsigned long long aesl_llvm_cbe_749_count = 0;
  unsigned long long llvm_cbe_tmp__223;
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
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
  static  unsigned long long aesl_llvm_cbe_764_count = 0;
  static  unsigned long long aesl_llvm_cbe_765_count = 0;
  static  unsigned long long aesl_llvm_cbe_766_count = 0;
  unsigned long long llvm_cbe_tmp__224;
  static  unsigned long long aesl_llvm_cbe_767_count = 0;
  static  unsigned long long aesl_llvm_cbe_768_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa11_count = 0;
  unsigned long long llvm_cbe__2e_lcssa11;
  unsigned long long llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_769_count = 0;
  static  unsigned long long aesl_llvm_cbe_770_count = 0;
  unsigned long long llvm_cbe_tmp__225;
  static  unsigned long long aesl_llvm_cbe_771_count = 0;
  signed long long *llvm_cbe_tmp__226;
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
  unsigned long long llvm_cbe_tmp__227;
  unsigned long long llvm_cbe_tmp__227__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned long long llvm_cbe_storemerge19;
  unsigned long long llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_791_count = 0;
  unsigned long long llvm_cbe_tmp__228;
  static  unsigned long long aesl_llvm_cbe_792_count = 0;
   char *llvm_cbe_tmp__229;
  static  unsigned long long aesl_llvm_cbe_793_count = 0;
  unsigned char llvm_cbe_tmp__230;
  static  unsigned long long aesl_llvm_cbe_794_count = 0;
   char *llvm_cbe_tmp__231;
  static  unsigned long long aesl_llvm_cbe_795_count = 0;
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  unsigned long long llvm_cbe_tmp__232;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  static  unsigned long long aesl_llvm_cbe_804_count = 0;
  static  unsigned long long aesl_llvm_cbe_805_count = 0;
  static  unsigned long long aesl_llvm_cbe_806_count = 0;
  static  unsigned long long aesl_llvm_cbe_807_count = 0;
  static  unsigned long long aesl_llvm_cbe_808_count = 0;
  static  unsigned long long aesl_llvm_cbe_809_count = 0;
  static  unsigned long long aesl_llvm_cbe_810_count = 0;
  static  unsigned long long aesl_llvm_cbe_811_count = 0;
  static  unsigned long long aesl_llvm_cbe_812_count = 0;
  static  unsigned long long aesl_llvm_cbe_813_count = 0;
  unsigned long long llvm_cbe_tmp__233;
  static  unsigned long long aesl_llvm_cbe_814_count = 0;
  static  unsigned long long aesl_llvm_cbe_815_count = 0;
  static  unsigned long long aesl_llvm_cbe_816_count = 0;
  static  unsigned long long aesl_llvm_cbe_817_count = 0;
  static  unsigned long long aesl_llvm_cbe_818_count = 0;
  static  unsigned long long aesl_llvm_cbe_819_count = 0;
  static  unsigned long long aesl_llvm_cbe_820_count = 0;
  static  unsigned long long aesl_llvm_cbe_821_count = 0;
  static  unsigned long long aesl_llvm_cbe_822_count = 0;
  static  unsigned long long aesl_llvm_cbe_823_count = 0;
  static  unsigned long long aesl_llvm_cbe_824_count = 0;
  static  unsigned long long aesl_llvm_cbe_825_count = 0;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  static  unsigned long long aesl_llvm_cbe_830_count = 0;
  static  unsigned long long aesl_llvm_cbe_831_count = 0;
  static  unsigned long long aesl_llvm_cbe_832_count = 0;
  static  unsigned long long aesl_llvm_cbe_833_count = 0;
  unsigned long long llvm_cbe_tmp__234;
  static  unsigned long long aesl_llvm_cbe_834_count = 0;
  static  unsigned long long aesl_llvm_cbe_835_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned long long llvm_cbe_storemerge25;
  unsigned long long llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_836_count = 0;
  unsigned long long llvm_cbe_tmp__235;
  static  unsigned long long aesl_llvm_cbe_837_count = 0;
  unsigned long long llvm_cbe_tmp__236;
  static  unsigned long long aesl_llvm_cbe_838_count = 0;
  unsigned long long llvm_cbe_tmp__237;
  static  unsigned long long aesl_llvm_cbe_839_count = 0;
  unsigned long long llvm_cbe_tmp__238;
  static  unsigned long long aesl_llvm_cbe_840_count = 0;
   char *llvm_cbe_tmp__239;
  static  unsigned long long aesl_llvm_cbe_841_count = 0;
  unsigned char llvm_cbe_tmp__240;
  static  unsigned long long aesl_llvm_cbe_842_count = 0;
   char *llvm_cbe_tmp__241;
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
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
  static  unsigned long long aesl_llvm_cbe_860_count = 0;
  static  unsigned long long aesl_llvm_cbe_861_count = 0;
  static  unsigned long long aesl_llvm_cbe_862_count = 0;
  unsigned long long llvm_cbe_tmp__242;
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
  unsigned long long llvm_cbe_tmp__243;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  signed long long *llvm_cbe_tmp__244;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge34_count = 0;
  unsigned long long llvm_cbe_storemerge34;
  unsigned long long llvm_cbe_storemerge34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
   char *llvm_cbe_tmp__245;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  unsigned char llvm_cbe_tmp__246;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  unsigned int llvm_cbe_tmp__247;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  unsigned int llvm_cbe_tmp__248;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  unsigned long long llvm_cbe_tmp__249;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
  unsigned long long llvm_cbe_tmp__250;
  static  unsigned long long aesl_llvm_cbe_893_count = 0;
  unsigned long long llvm_cbe_tmp__251;
  static  unsigned long long aesl_llvm_cbe_894_count = 0;
   char *llvm_cbe_tmp__252;
  static  unsigned long long aesl_llvm_cbe_895_count = 0;
  unsigned char llvm_cbe_tmp__253;
  static  unsigned long long aesl_llvm_cbe_896_count = 0;
  static  unsigned long long aesl_llvm_cbe_897_count = 0;
  static  unsigned long long aesl_llvm_cbe_898_count = 0;
  static  unsigned long long aesl_llvm_cbe_899_count = 0;
  static  unsigned long long aesl_llvm_cbe_900_count = 0;
  static  unsigned long long aesl_llvm_cbe_901_count = 0;
  unsigned char llvm_cbe_tmp__254;
  static  unsigned long long aesl_llvm_cbe_902_count = 0;
  static  unsigned long long aesl_llvm_cbe_903_count = 0;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
  unsigned char llvm_cbe_tmp__255;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  unsigned char llvm_cbe_tmp__256;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  static  unsigned long long aesl_llvm_cbe_908_count = 0;
  unsigned char llvm_cbe_tmp__257;
  static  unsigned long long aesl_llvm_cbe_909_count = 0;
  unsigned char llvm_cbe_tmp__258;
  static  unsigned long long aesl_llvm_cbe_910_count = 0;
  unsigned long long llvm_cbe_tmp__259;
  static  unsigned long long aesl_llvm_cbe_911_count = 0;
   char *llvm_cbe_tmp__260;
  static  unsigned long long aesl_llvm_cbe_912_count = 0;
  unsigned char llvm_cbe_tmp__261;
  static  unsigned long long aesl_llvm_cbe_913_count = 0;
  unsigned char llvm_cbe_tmp__262;
  static  unsigned long long aesl_llvm_cbe_914_count = 0;
  static  unsigned long long aesl_llvm_cbe_915_count = 0;
  unsigned long long llvm_cbe_tmp__263;
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
  unsigned long long llvm_cbe_tmp__264;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  static  unsigned long long aesl_llvm_cbe_934_count = 0;
  static  unsigned long long aesl_llvm_cbe_935_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_correct_errata\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 0, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_698_count);
  llvm_cbe_tmp__203 = (signed long long *)(&llvm_cbe_q.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%1, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_699_count);
  *llvm_cbe_tmp__203 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
  llvm_cbe_tmp__204__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_memcpy;

  do {     /* Syntactic loop 'memcpy' to make GCC happy */
llvm_cbe_memcpy:
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i32 [ 0, %%0 ], [ %%3, %%memcpy ], !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_701_count);
  llvm_cbe_tmp__204 = (unsigned int )llvm_cbe_tmp__204__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__204);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__205);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i32 %%2, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_702_count);
  llvm_cbe_tmp__205 = (unsigned int )((unsigned int )(llvm_cbe_tmp__204&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__205&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%2 to i64, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_703_count);
  llvm_cbe_tmp__206 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__204);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__206);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 1, i64 %%4, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_704_count);
  llvm_cbe_tmp__207 = ( char *)(&llvm_cbe_q.field1[(((signed long long )llvm_cbe_tmp__206))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__206));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* @aesl_internal_rs_find_error.old, i64 0, i32 1, i64 %%4, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__208 = ( char *)(&aesl_internal_rs_find_error_OC_old.field1[(((signed long long )llvm_cbe_tmp__206))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__206));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__209 = (unsigned char )*llvm_cbe_tmp__208;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%5, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_707_count);
  *llvm_cbe_tmp__207 = llvm_cbe_tmp__209;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__209);
  if (((llvm_cbe_tmp__204&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe_tmp__265;
  } else {
    llvm_cbe_tmp__204__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__205;   /* for PHI node */
    goto llvm_cbe_memcpy;
  }

  } while (1); /* end of syntactic loop 'memcpy' */
llvm_cbe_tmp__265:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 0, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_711_count);
  llvm_cbe_tmp__210 = (signed long long *)(&llvm_cbe_tmp.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%10, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_712_count);
  *llvm_cbe_tmp__210 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 1, i64 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_713_count);
  llvm_cbe_tmp__211 = ( char *)(&llvm_cbe_tmp.field1[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%11, align 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_714_count);
  *llvm_cbe_tmp__211 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__212 = (signed long long *)(&llvm_cbe_pos->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__213 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__213);
  if (((llvm_cbe_tmp__213&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge15;
  } else {
    goto llvm_cbe__2e_lr_2e_ph14;
  }

llvm_cbe__2e_lr_2e_ph14:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_735_count);
  llvm_cbe_tmp__214 = (signed long long *)(&llvm_cbe_msg->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.poly* %%tmp, i64 0, i32 1, i64 2, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_736_count);
  llvm_cbe_tmp__215 = ( char *)(&llvm_cbe_tmp.field1[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__266;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__266:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i64 [ 0, %%.lr.ph14 ], [ %%25, %%17  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned long long )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",llvm_cbe_storemerge12);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__223);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i64* %%15, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_738_count);
  llvm_cbe_tmp__216 = (unsigned long long )*llvm_cbe_tmp__214;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__216);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 1, i64 %%storemerge12, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_739_count);
  llvm_cbe_tmp__217 = ( char *)(&llvm_cbe_pos->field1[(((signed long long )llvm_cbe_storemerge12))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%I64X",((signed long long )llvm_cbe_storemerge12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_740_count);
  llvm_cbe_tmp__218 = (unsigned char )*llvm_cbe_tmp__217;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__218);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i8 %%20 to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_741_count);
  llvm_cbe_tmp__219 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__218&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__219);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = sub i64 %%18, %%21, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_742_count);
  llvm_cbe_tmp__220 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__216&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__219&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__220&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%22, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_743_count);
  llvm_cbe_tmp__221 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__220))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__220));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__220) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = load i8* %%23, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_744_count);
  llvm_cbe_tmp__222 = (unsigned char )*llvm_cbe_tmp__221;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%24, i8* %%16, align 2, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_747_count);
  *llvm_cbe_tmp__215 = llvm_cbe_tmp__222;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__222);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_mul(%%struct.poly* %%q, %%struct.poly* %%q, %%struct.poly* %%tmp), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_748_count);
  aesl_internal_gf_poly_mul((l_struct_OC_poly *)(&llvm_cbe_q), (l_struct_OC_poly *)(&llvm_cbe_q), (l_struct_OC_poly *)(&llvm_cbe_tmp));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge12, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_749_count);
  llvm_cbe_tmp__223 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__223&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_766_count);
  llvm_cbe_tmp__224 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__224);
  if ((((unsigned long long )llvm_cbe_tmp__223&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__224&18446744073709551615ULL))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__223;   /* for PHI node */
    goto llvm_cbe_tmp__266;
  } else {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__224;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge15;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge15:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa11 = phi i64 [ 0, %%9 ], [ %%26, %%17  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe__2e_lcssa11_count);
  llvm_cbe__2e_lcssa11 = (unsigned long long )llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa11 = 0x%I64X",llvm_cbe__2e_lcssa11);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__224);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add i64 %%.lcssa11, -1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_770_count);
  llvm_cbe_tmp__225 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa11&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__225&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_771_count);
  llvm_cbe_tmp__226 = (signed long long *)(&llvm_cbe_p.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%28, i64* %%29, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_772_count);
  *llvm_cbe_tmp__226 = llvm_cbe_tmp__225;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__225);
  llvm_cbe_tmp__227__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__225;   /* for PHI node */
  llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__267;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__267:
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = phi i64 [ %%28, %%._crit_edge15 ], [ %%37, %%30  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_790_count);
  llvm_cbe_tmp__227 = (unsigned long long )llvm_cbe_tmp__227__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__227);
printf("\n = 0x%I64X",llvm_cbe_tmp__225);
printf("\n = 0x%I64X",llvm_cbe_tmp__233);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i64 [ 0, %%._crit_edge15 ], [ %%36, %%30  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned long long )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%I64X",llvm_cbe_storemerge19);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__232);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sub i64 %%31, %%storemerge19, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_791_count);
  llvm_cbe_tmp__228 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__227&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_storemerge19&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__228&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct.poly* %%synd, i64 0, i32 1, i64 %%32, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_792_count);
  llvm_cbe_tmp__229 = ( char *)(&llvm_cbe_synd->field1[(((signed long long )llvm_cbe_tmp__228))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__228));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i8* %%33, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_793_count);
  llvm_cbe_tmp__230 = (unsigned char )*llvm_cbe_tmp__229;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge19, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_794_count);
  llvm_cbe_tmp__231 = ( char *)(&llvm_cbe_p.field1[(((signed long long )llvm_cbe_storemerge19))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%I64X",((signed long long )llvm_cbe_storemerge19));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%34, i8* %%35, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_795_count);
  *llvm_cbe_tmp__231 = llvm_cbe_tmp__230;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__230);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = add i64 %%storemerge19, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_796_count);
  llvm_cbe_tmp__232 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge19&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__232&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i64* %%29, align 8, !dbg !15 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_813_count);
  llvm_cbe_tmp__233 = (unsigned long long )*llvm_cbe_tmp__226;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__233);
  if ((((unsigned long long )llvm_cbe_tmp__232&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__233&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__268;
  } else {
    llvm_cbe_tmp__227__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__233;   /* for PHI node */
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__232;   /* for PHI node */
    goto llvm_cbe_tmp__267;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__268:
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_gf_poly_mul(%%struct.poly* %%p, %%struct.poly* %%p, %%struct.poly* %%q), !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_816_count);
  aesl_internal_gf_poly_mul((l_struct_OC_poly *)(&llvm_cbe_p), (l_struct_OC_poly *)(&llvm_cbe_p), (l_struct_OC_poly *)(&llvm_cbe_q));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_833_count);
  llvm_cbe_tmp__234 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__234);
  if (((llvm_cbe_tmp__234&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge8;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  }

  do {     /* Syntactic loop '.lr.ph7' to make GCC happy */
llvm_cbe__2e_lr_2e_ph7:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i64 [ %%43, %%.lr.ph7 ], [ 0, %%39  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned long long )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",llvm_cbe_storemerge25);
printf("\n = 0x%I64X",llvm_cbe_tmp__236);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = load i64* %%29, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_836_count);
  llvm_cbe_tmp__235 = (unsigned long long )*llvm_cbe_tmp__226;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__235);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%storemerge25, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_837_count);
  llvm_cbe_tmp__236 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge25&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__236&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sub i64 %%43, %%40, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_838_count);
  llvm_cbe_tmp__237 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__236&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__234&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__237&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add i64 %%44, %%42, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_839_count);
  llvm_cbe_tmp__238 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__237&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__235&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__238&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%45, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_840_count);
  llvm_cbe_tmp__239 = ( char *)(&llvm_cbe_p.field1[(((signed long long )llvm_cbe_tmp__238))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__238));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i8* %%46, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_841_count);
  llvm_cbe_tmp__240 = (unsigned char )*llvm_cbe_tmp__239;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__240);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge25, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_842_count);
  llvm_cbe_tmp__241 = ( char *)(&llvm_cbe_p.field1[(((signed long long )llvm_cbe_storemerge25))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",((signed long long )llvm_cbe_storemerge25));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%47, i8* %%48, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_843_count);
  *llvm_cbe_tmp__241 = llvm_cbe_tmp__240;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__240);
  if ((((unsigned long long )llvm_cbe_tmp__236&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__234&18446744073709551615ULL))) {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__236;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  } else {
    goto llvm_cbe__2e__crit_edge8;
  }

  } while (1); /* end of syntactic loop '.lr.ph7' */
llvm_cbe__2e__crit_edge8:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = add i64 %%40, -1, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_862_count);
  llvm_cbe_tmp__242 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__234&18446744073709551615ull)) + ((unsigned long long )(18446744073709551615ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__242&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%50, i64* %%29, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_863_count);
  *llvm_cbe_tmp__226 = llvm_cbe_tmp__242;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__242);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_rs_fderivative(%%struct.poly* %%qprime, %%struct.poly* %%q), !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_865_count);
  aesl_internal_rs_fderivative((l_struct_OC_poly *)(&llvm_cbe_qprime), (l_struct_OC_poly *)(&llvm_cbe_q));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_882_count);
  llvm_cbe_tmp__243 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__243);
  if (((llvm_cbe_tmp__243&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    goto llvm_cbe__2e_lr_2e_ph;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_885_count);
  llvm_cbe_tmp__244 = (signed long long *)(&llvm_cbe_msg->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__269;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__269:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge34 = phi i64 [ 0, %%.lr.ph ], [ %%73, %%54  for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_storemerge34_count);
  llvm_cbe_storemerge34 = (unsigned long long )llvm_cbe_storemerge34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%I64X",llvm_cbe_storemerge34);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__263);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds %%struct.poly* %%pos, i64 0, i32 1, i64 %%storemerge34, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_887_count);
  llvm_cbe_tmp__245 = ( char *)(&llvm_cbe_pos->field1[(((signed long long )llvm_cbe_storemerge34))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge34 = 0x%I64X",((signed long long )llvm_cbe_storemerge34));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i8* %%55, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_888_count);
  llvm_cbe_tmp__246 = (unsigned char )*llvm_cbe_tmp__245;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__246);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i8 %%56 to i32, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_889_count);
  llvm_cbe_tmp__247 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__246&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__247);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add nsw i32 %%57, 255, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_890_count);
  llvm_cbe_tmp__248 = (unsigned int )((unsigned int )(llvm_cbe_tmp__247&4294967295ull)) + ((unsigned int )(255u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__248&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = zext i32 %%58 to i64, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_891_count);
  llvm_cbe_tmp__249 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__248&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__249);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = load i64* %%53, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_892_count);
  llvm_cbe_tmp__250 = (unsigned long long )*llvm_cbe_tmp__244;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__250);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = sub i64 %%59, %%60, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_893_count);
  llvm_cbe_tmp__251 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__249&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__250&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__251&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%61, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_894_count);
  llvm_cbe_tmp__252 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__251))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__251));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__251) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i8* %%62, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_895_count);
  llvm_cbe_tmp__253 = (unsigned char )*llvm_cbe_tmp__252;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = call fastcc zeroext i8 @aesl_internal_gf_poly_eval(%%struct.poly* %%p, i8 zeroext %%63), !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_901_count);
  llvm_cbe_tmp__254 = (unsigned char )aesl_internal_gf_poly_eval((l_struct_OC_poly *)(&llvm_cbe_p), llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__253);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__254);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%63, i8 zeroext %%63), !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__255 = (unsigned char )aesl_internal_gf_mul(llvm_cbe_tmp__253, llvm_cbe_tmp__253);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__253);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__253);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__255);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = call fastcc zeroext i8 @aesl_internal_gf_poly_eval(%%struct.poly* %%qprime, i8 zeroext %%65), !dbg !17 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__256 = (unsigned char )aesl_internal_gf_poly_eval((l_struct_OC_poly *)(&llvm_cbe_qprime), llvm_cbe_tmp__255);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__255);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__256);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%63, i8 zeroext %%66), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_908_count);
  llvm_cbe_tmp__257 = (unsigned char )aesl_internal_gf_mul(llvm_cbe_tmp__253, llvm_cbe_tmp__256);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__253);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__256);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__257);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = call fastcc zeroext i8 @aesl_internal_gf_div(i8 zeroext %%64, i8 zeroext %%67), !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_909_count);
  llvm_cbe_tmp__258 = (unsigned char )aesl_internal_gf_div(llvm_cbe_tmp__254, llvm_cbe_tmp__257);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__254);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__257);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__258);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = zext i8 %%56 to i64, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_910_count);
  llvm_cbe_tmp__259 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__246&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__259);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = getelementptr inbounds %%struct.poly* %%msg, i64 0, i32 1, i64 %%69, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_911_count);
  llvm_cbe_tmp__260 = ( char *)(&llvm_cbe_msg->field1[(((signed long long )llvm_cbe_tmp__259))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__259));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = load i8* %%70, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_912_count);
  llvm_cbe_tmp__261 = (unsigned char )*llvm_cbe_tmp__260;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__261);
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = xor i8 %%71, %%68, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_913_count);
  llvm_cbe_tmp__262 = (unsigned char )((unsigned char )(llvm_cbe_tmp__261 ^ llvm_cbe_tmp__258));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%72, i8* %%70, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_914_count);
  *llvm_cbe_tmp__260 = llvm_cbe_tmp__262;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__262);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = add i64 %%storemerge34, 1, !dbg !16 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_915_count);
  llvm_cbe_tmp__263 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge34&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__263&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_rs_correct_errata  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__264 = (unsigned long long )*llvm_cbe_tmp__212;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__264);
  if ((((unsigned long long )llvm_cbe_tmp__263&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__264&18446744073709551615ULL))) {
    llvm_cbe_storemerge34__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__263;   /* for PHI node */
    goto llvm_cbe_tmp__269;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_correct_errata}\n");
  return;
}


static void aesl_internal_gf_poly_mul(l_struct_OC_poly *llvm_cbe_dest, l_struct_OC_poly *llvm_cbe_p, l_struct_OC_poly *llvm_cbe_q) {
  static  unsigned long long aesl_llvm_cbe_r_count = 0;
  l_struct_OC_poly llvm_cbe_r;    /* Address-exposed local */
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
  signed long long *llvm_cbe_tmp__270;
  static  unsigned long long aesl_llvm_cbe_949_count = 0;
  signed long long *llvm_cbe_tmp__271;
  static  unsigned long long aesl_llvm_cbe_950_count = 0;
  unsigned long long llvm_cbe_tmp__272;
  static  unsigned long long aesl_llvm_cbe_951_count = 0;
  signed long long *llvm_cbe_tmp__273;
  static  unsigned long long aesl_llvm_cbe_952_count = 0;
  unsigned long long llvm_cbe_tmp__274;
  static  unsigned long long aesl_llvm_cbe_953_count = 0;
  unsigned long long llvm_cbe_tmp__275;
  static  unsigned long long aesl_llvm_cbe_954_count = 0;
  static  unsigned long long aesl_llvm_cbe_955_count = 0;
   char *llvm_cbe_tmp__276;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  static  unsigned long long aesl_llvm_cbe_960_count = 0;
  static  unsigned long long aesl_llvm_cbe_961_count = 0;
  static  unsigned long long aesl_llvm_cbe_962_count = 0;
  static  unsigned long long aesl_llvm_cbe_963_count = 0;
  static  unsigned long long aesl_llvm_cbe_964_count = 0;
  static  unsigned long long aesl_llvm_cbe_965_count = 0;
   char *llvm_cbe_tmp__277;
  static  unsigned long long aesl_llvm_cbe_966_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned long long llvm_cbe_storemerge6;
  unsigned long long llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_967_count = 0;
  static  unsigned long long aesl_llvm_cbe_968_count = 0;
  static  unsigned long long aesl_llvm_cbe_969_count = 0;
  static  unsigned long long aesl_llvm_cbe_970_count = 0;
  static  unsigned long long aesl_llvm_cbe_971_count = 0;
   char *llvm_cbe_tmp__278;
  static  unsigned long long aesl_llvm_cbe_972_count = 0;
  unsigned char llvm_cbe_tmp__279;
  static  unsigned long long aesl_llvm_cbe_973_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge25_count = 0;
  unsigned long long llvm_cbe_storemerge25;
  unsigned long long llvm_cbe_storemerge25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_974_count = 0;
   char *llvm_cbe_tmp__280;
  static  unsigned long long aesl_llvm_cbe_975_count = 0;
  unsigned char llvm_cbe_tmp__281;
  static  unsigned long long aesl_llvm_cbe_976_count = 0;
  unsigned char llvm_cbe_tmp__282;
  static  unsigned long long aesl_llvm_cbe_977_count = 0;
  unsigned long long llvm_cbe_tmp__283;
  static  unsigned long long aesl_llvm_cbe_978_count = 0;
   char *llvm_cbe_tmp__284;
  static  unsigned long long aesl_llvm_cbe_979_count = 0;
  unsigned char llvm_cbe_tmp__285;
  static  unsigned long long aesl_llvm_cbe_980_count = 0;
  unsigned char llvm_cbe_tmp__286;
  static  unsigned long long aesl_llvm_cbe_981_count = 0;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  unsigned long long llvm_cbe_tmp__287;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned long long llvm_cbe_tmp__288;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge13_count = 0;
  unsigned long long llvm_cbe_storemerge13;
  unsigned long long llvm_cbe_storemerge13__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
   char *llvm_cbe_tmp__289;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  unsigned char llvm_cbe_tmp__290;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
   char *llvm_cbe_tmp__291;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  unsigned long long llvm_cbe_tmp__292;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  unsigned long long llvm_cbe_tmp__293;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  signed long long *llvm_cbe_tmp__294;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_poly_mul\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_948_count);
  llvm_cbe_tmp__270 = (signed long long *)(&llvm_cbe_r.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_949_count);
  llvm_cbe_tmp__271 = (signed long long *)(&llvm_cbe_p->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_950_count);
  llvm_cbe_tmp__272 = (unsigned long long )*llvm_cbe_tmp__271;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__272);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_951_count);
  llvm_cbe_tmp__273 = (signed long long *)(&llvm_cbe_q->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_952_count);
  llvm_cbe_tmp__274 = (unsigned long long )*llvm_cbe_tmp__273;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__274);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%5, %%3, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_953_count);
  llvm_cbe_tmp__275 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__274&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__272&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__275&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%6, i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_954_count);
  *llvm_cbe_tmp__270 = llvm_cbe_tmp__275;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__275);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_955_count);
  llvm_cbe_tmp__276 = ( char *)(&llvm_cbe_r.field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i8* @memset(i8* %%7, i32 0, i64 512 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_965_count);
  ( char *)memset(( char *)llvm_cbe_tmp__276, 0u, 512ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",512ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__277);
}
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader4;

  do {     /* Syntactic loop '.preheader4' to make GCC happy */
llvm_cbe__2e_preheader4:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i64 [ 0, %%0 ], [ %%22, %%21  for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned long long )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%I64X",llvm_cbe_storemerge6);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__288);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge6, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_971_count);
  llvm_cbe_tmp__278 = ( char *)(&llvm_cbe_p->field1[(((signed long long )llvm_cbe_storemerge6))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%I64X",((signed long long )llvm_cbe_storemerge6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_972_count);
  llvm_cbe_tmp__279 = (unsigned char )*llvm_cbe_tmp__278;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__279);
  llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__295;

llvm_cbe_tmp__296:
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = add i64 %%storemerge6, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__288 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge6&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__288&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__288&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__272&18446744073709551615ULL))) {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__288;   /* for PHI node */
    goto llvm_cbe__2e_preheader4;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__295:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge25 = phi i64 [ 0, %%.preheader4 ], [ %%19, %%11  for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_storemerge25_count);
  llvm_cbe_storemerge25 = (unsigned long long )llvm_cbe_storemerge25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",llvm_cbe_storemerge25);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__287);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 1, i64 %%storemerge25, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_974_count);
  llvm_cbe_tmp__280 = ( char *)(&llvm_cbe_q->field1[(((signed long long )llvm_cbe_storemerge25))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge25 = 0x%I64X",((signed long long )llvm_cbe_storemerge25));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i8* %%12, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_975_count);
  llvm_cbe_tmp__281 = (unsigned char )*llvm_cbe_tmp__280;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%10, i8 zeroext %%13), !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_976_count);
  llvm_cbe_tmp__282 = (unsigned char )aesl_internal_gf_mul(llvm_cbe_tmp__279, llvm_cbe_tmp__281);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__279);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__281);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__282);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge25, %%storemerge6, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_977_count);
  llvm_cbe_tmp__283 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge25&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_storemerge6&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__283&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%15, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_978_count);
  llvm_cbe_tmp__284 = ( char *)(&llvm_cbe_r.field1[(((signed long long )llvm_cbe_tmp__283))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__283));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = load i8* %%16, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_979_count);
  llvm_cbe_tmp__285 = (unsigned char )*llvm_cbe_tmp__284;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__285);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = xor i8 %%17, %%14, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_980_count);
  llvm_cbe_tmp__286 = (unsigned char )((unsigned char )(llvm_cbe_tmp__285 ^ llvm_cbe_tmp__282));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%18, i8* %%16, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_981_count);
  *llvm_cbe_tmp__284 = llvm_cbe_tmp__286;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__286);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge25, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_982_count);
  llvm_cbe_tmp__287 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge25&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__287&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__287&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__274&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__296;
  } else {
    llvm_cbe_storemerge25__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__287;   /* for PHI node */
    goto llvm_cbe_tmp__295;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader4' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge13 = phi i64 [ %%27, %%.preheader ], [ 0, %%21  for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_storemerge13_count);
  llvm_cbe_storemerge13 = (unsigned long long )llvm_cbe_storemerge13__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",llvm_cbe_storemerge13);
printf("\n = 0x%I64X",llvm_cbe_tmp__292);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%storemerge13, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1002_count);
  llvm_cbe_tmp__289 = ( char *)(&llvm_cbe_r.field1[(((signed long long )llvm_cbe_storemerge13))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",((signed long long )llvm_cbe_storemerge13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8* %%24, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1003_count);
  llvm_cbe_tmp__290 = (unsigned char )*llvm_cbe_tmp__289;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds %%struct.poly* %%dest, i64 0, i32 1, i64 %%storemerge13, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1004_count);
  llvm_cbe_tmp__291 = ( char *)(&llvm_cbe_dest->field1[(((signed long long )llvm_cbe_storemerge13))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge13 = 0x%I64X",((signed long long )llvm_cbe_storemerge13));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%25, i8* %%26, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1005_count);
  *llvm_cbe_tmp__291 = llvm_cbe_tmp__290;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__290);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = add i64 %%storemerge13, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1006_count);
  llvm_cbe_tmp__292 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge13&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__292&18446744073709551615ull)));
  if (((llvm_cbe_tmp__292&18446744073709551615ULL) == (520ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__297;
  } else {
    llvm_cbe_storemerge13__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__292;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__297:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1017_count);
  llvm_cbe_tmp__293 = (unsigned long long )*llvm_cbe_tmp__270;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__293);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct.poly* %%dest, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1018_count);
  llvm_cbe_tmp__294 = (signed long long *)(&llvm_cbe_dest->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%29, i64* %%30, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_mul  --> \n", ++aesl_llvm_cbe_1019_count);
  *llvm_cbe_tmp__294 = llvm_cbe_tmp__293;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__293);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_poly_mul}\n");
  return;
}


static void aesl_internal_rs_fderivative(l_struct_OC_poly *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_p) {
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  signed long long *llvm_cbe_tmp__298;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  unsigned long long llvm_cbe_tmp__299;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  unsigned long long llvm_cbe_tmp__300;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  unsigned long long llvm_cbe_tmp__301;
  static  unsigned long long aesl_llvm_cbe_1034_count = 0;
  static  unsigned long long aesl_llvm_cbe_1035_count = 0;
  static  unsigned long long aesl_llvm_cbe_1036_count = 0;
  static  unsigned long long aesl_llvm_cbe_1037_count = 0;
  static  unsigned long long aesl_llvm_cbe_1038_count = 0;
  static  unsigned long long aesl_llvm_cbe_1039_count = 0;
  static  unsigned long long aesl_llvm_cbe_1040_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1041_count = 0;
   char *llvm_cbe_tmp__302;
  static  unsigned long long aesl_llvm_cbe_1042_count = 0;
  unsigned char llvm_cbe_tmp__303;
  static  unsigned long long aesl_llvm_cbe_1043_count = 0;
  unsigned long long llvm_cbe_tmp__304;
  static  unsigned long long aesl_llvm_cbe_1044_count = 0;
   char *llvm_cbe_tmp__305;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  unsigned long long llvm_cbe_tmp__306;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  unsigned long long llvm_cbe_tmp__307;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  unsigned long long llvm_cbe_tmp__308;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  signed long long *llvm_cbe_tmp__309;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_rs_fderivative\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1029_count);
  llvm_cbe_tmp__298 = (signed long long *)(&llvm_cbe_p->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1030_count);
  llvm_cbe_tmp__299 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__299);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = and i64 %%2, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1031_count);
  llvm_cbe_tmp__300 = (unsigned long long )llvm_cbe_tmp__299 & 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__300);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = select i1 %%4, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1033_count);
  llvm_cbe_tmp__301 = (unsigned long long )((((llvm_cbe_tmp__300&18446744073709551615ULL) != (0ull&18446744073709551615ULL))) ? ((unsigned long long )0ull) : ((unsigned long long )1ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__301);
  if ((((unsigned long long )llvm_cbe_tmp__301&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__299&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__301;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__299;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%11, %%.lr.ph ], [ %%5, %%0  for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__306);
printf("\n = 0x%I64X",llvm_cbe_tmp__301);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1041_count);
  llvm_cbe_tmp__302 = ( char *)(&llvm_cbe_p->field1[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8* %%7, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1042_count);
  llvm_cbe_tmp__303 = (unsigned char )*llvm_cbe_tmp__302;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = lshr i64 %%storemerge1, 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1043_count);
  llvm_cbe_tmp__304 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__304&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%9, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1044_count);
  llvm_cbe_tmp__305 = ( char *)(&llvm_cbe_r->field1[(((signed long long )llvm_cbe_tmp__304))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__304));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%10, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1045_count);
  *llvm_cbe_tmp__305 = llvm_cbe_tmp__303;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__303);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge1, 2, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1046_count);
  llvm_cbe_tmp__306 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(2ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__306&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1052_count);
  llvm_cbe_tmp__307 = (unsigned long long )*llvm_cbe_tmp__298;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__307);
  if ((((unsigned long long )llvm_cbe_tmp__306&18446744073709551615ULL) < ((unsigned long long )llvm_cbe_tmp__307&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__306;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__307;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ %%2, %%0 ], [ %%12, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",llvm_cbe_tmp__299);
printf("\n = 0x%I64X",llvm_cbe_tmp__307);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = lshr i64 %%.lcssa, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1055_count);
  llvm_cbe_tmp__308 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) >> ((unsigned long long )(1ull&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__308&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1056_count);
  llvm_cbe_tmp__309 = (signed long long *)(&llvm_cbe_r->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%14, i64* %%15, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_rs_fderivative  --> \n", ++aesl_llvm_cbe_1057_count);
  *llvm_cbe_tmp__309 = llvm_cbe_tmp__308;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__308);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_rs_fderivative}\n");
  return;
}


static unsigned char aesl_internal_gf_poly_eval(l_struct_OC_poly *llvm_cbe_p,  char llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
   char *llvm_cbe_tmp__310;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  unsigned char llvm_cbe_tmp__311;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  static  unsigned long long aesl_llvm_cbe_1070_count = 0;
  static  unsigned long long aesl_llvm_cbe_1071_count = 0;
  static  unsigned long long aesl_llvm_cbe_1072_count = 0;
  static  unsigned long long aesl_llvm_cbe_1073_count = 0;
  static  unsigned long long aesl_llvm_cbe_1074_count = 0;
  signed long long *llvm_cbe_tmp__312;
  static  unsigned long long aesl_llvm_cbe_1075_count = 0;
  unsigned long long llvm_cbe_tmp__313;
  static  unsigned long long aesl_llvm_cbe_1076_count = 0;
  static  unsigned long long aesl_llvm_cbe_1077_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1078_count = 0;
  unsigned char llvm_cbe_tmp__314;
  unsigned char llvm_cbe_tmp__314__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1079_count = 0;
  unsigned char llvm_cbe_tmp__315;
  static  unsigned long long aesl_llvm_cbe_1080_count = 0;
   char *llvm_cbe_tmp__316;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  unsigned char llvm_cbe_tmp__317;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  unsigned char llvm_cbe_tmp__318;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  static  unsigned long long aesl_llvm_cbe_1084_count = 0;
  static  unsigned long long aesl_llvm_cbe_1085_count = 0;
  static  unsigned long long aesl_llvm_cbe_1086_count = 0;
  unsigned long long llvm_cbe_tmp__319;
  static  unsigned long long aesl_llvm_cbe_1087_count = 0;
  static  unsigned long long aesl_llvm_cbe_1088_count = 0;
  static  unsigned long long aesl_llvm_cbe_1089_count = 0;
  static  unsigned long long aesl_llvm_cbe_1090_count = 0;
  static  unsigned long long aesl_llvm_cbe_1091_count = 0;
  static  unsigned long long aesl_llvm_cbe_1092_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned char llvm_cbe__2e_lcssa;
  unsigned char llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1093_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_poly_eval\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1065_count);
  llvm_cbe_tmp__310 = ( char *)(&llvm_cbe_p->field1[(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i8* %%1, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1066_count);
  llvm_cbe_tmp__311 = (unsigned char )*llvm_cbe_tmp__310;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__311);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1074_count);
  llvm_cbe_tmp__312 = (signed long long *)(&llvm_cbe_p->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i64* %%3, align 8, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1075_count);
  llvm_cbe_tmp__313 = (unsigned long long )*llvm_cbe_tmp__312;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__313);
  if (((llvm_cbe_tmp__313&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__311;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
    llvm_cbe_tmp__314__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__311;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%11, %%.lr.ph ], [ 1, %%0  for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__319);
printf("\n = 0x%I64X",1ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = phi i8 [ %%10, %%.lr.ph ], [ %%2, %%0  for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1078_count);
  llvm_cbe_tmp__314 = (unsigned char )llvm_cbe_tmp__314__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__314);
printf("\n = 0x%X",llvm_cbe_tmp__318);
printf("\n = 0x%X",llvm_cbe_tmp__311);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = tail call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%6, i8 zeroext %%x), !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1079_count);
  llvm_cbe_tmp__315 = (unsigned char ) /*tail*/ aesl_internal_gf_mul(llvm_cbe_tmp__314, llvm_cbe_x);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__314);
printf("\nArgument x = 0x%X",llvm_cbe_x);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__315);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1080_count);
  llvm_cbe_tmp__316 = ( char *)(&llvm_cbe_p->field1[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i8* %%8, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1081_count);
  llvm_cbe_tmp__317 = (unsigned char )*llvm_cbe_tmp__316;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__317);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = xor i8 %%9, %%7, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1082_count);
  llvm_cbe_tmp__318 = (unsigned char )((unsigned char )(llvm_cbe_tmp__317 ^ llvm_cbe_tmp__315));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__318);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add i64 %%storemerge1, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe_1086_count);
  llvm_cbe_tmp__319 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__319&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__319&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__313&18446744073709551615ULL))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__318;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__319;   /* for PHI node */
    llvm_cbe_tmp__314__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__318;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i8 [ %%2, %%0 ], [ %%10, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_gf_poly_eval  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned char )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%X",llvm_cbe__2e_lcssa);
printf("\n = 0x%X",llvm_cbe_tmp__311);
printf("\n = 0x%X",llvm_cbe_tmp__318);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_poly_eval}\n");
  return llvm_cbe__2e_lcssa;
}


static unsigned char aesl_internal_gf_div( char llvm_cbe_x,  char llvm_cbe_y) {
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  unsigned long long llvm_cbe_tmp__320;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
   char *llvm_cbe_tmp__321;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  unsigned char llvm_cbe_tmp__322;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  unsigned int llvm_cbe_tmp__323;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  unsigned long long llvm_cbe_tmp__324;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
   char *llvm_cbe_tmp__325;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  unsigned char llvm_cbe_tmp__326;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  unsigned int llvm_cbe_tmp__327;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  unsigned int llvm_cbe_tmp__328;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  unsigned int llvm_cbe_tmp__329;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  unsigned long long llvm_cbe_tmp__330;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
   char *llvm_cbe_tmp__331;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;
  unsigned char llvm_cbe_tmp__332;
  static  unsigned long long aesl_llvm_cbe_1116_count = 0;
  static  unsigned long long aesl_llvm_cbe_1117_count = 0;
  unsigned char llvm_cbe_tmp__333;
  unsigned char llvm_cbe_tmp__333__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1118_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_div\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%1, %%2, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )((((llvm_cbe_x&255U) == (((unsigned char )0)&255U)) | ((llvm_cbe_y&255U) == (((unsigned char )0)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_tmp__333__PHI_TEMPORARY = (unsigned char )((unsigned char )0);   /* for PHI node */
    goto llvm_cbe_tmp__334;
  } else {
    goto llvm_cbe_tmp__335;
  }

llvm_cbe_tmp__335:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i8 %%x to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1103_count);
  llvm_cbe_tmp__320 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_x&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__320);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [256 x i8]* @aesl_internal_gf_log, i64 0, i64 %%4, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1104_count);
  llvm_cbe_tmp__321 = ( char *)(&aesl_internal_gf_log[(((signed long long )llvm_cbe_tmp__320))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__320));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__320) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_log' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i8* %%5, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1105_count);
  llvm_cbe_tmp__322 = (unsigned char )*llvm_cbe_tmp__321;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__322);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = zext i8 %%6 to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1106_count);
  llvm_cbe_tmp__323 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__322&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__323);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%y to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1107_count);
  llvm_cbe_tmp__324 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_y&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__324);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [256 x i8]* @aesl_internal_gf_log, i64 0, i64 %%8, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1108_count);
  llvm_cbe_tmp__325 = ( char *)(&aesl_internal_gf_log[(((signed long long )llvm_cbe_tmp__324))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__324));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__324) < 256)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_log' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1109_count);
  llvm_cbe_tmp__326 = (unsigned char )*llvm_cbe_tmp__325;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__326);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1110_count);
  llvm_cbe_tmp__327 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__326&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__327);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%7, 255, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1111_count);
  llvm_cbe_tmp__328 = (unsigned int )((unsigned int )(llvm_cbe_tmp__323&4294967295ull)) + ((unsigned int )(255u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__328&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub i32 %%12, %%11, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1112_count);
  llvm_cbe_tmp__329 = (unsigned int )((unsigned int )(llvm_cbe_tmp__328&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__327&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__329&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sext i32 %%13 to i64, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1113_count);
  llvm_cbe_tmp__330 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__329);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__330);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%14, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1114_count);
  llvm_cbe_tmp__331 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__330))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__330));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__330) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1115_count);
  llvm_cbe_tmp__332 = (unsigned char )*llvm_cbe_tmp__331;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__332);
  llvm_cbe_tmp__333__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__332;   /* for PHI node */
  goto llvm_cbe_tmp__334;

llvm_cbe_tmp__334:
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i8 [ %%16, %%3 ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_gf_div  --> \n", ++aesl_llvm_cbe_1117_count);
  llvm_cbe_tmp__333 = (unsigned char )llvm_cbe_tmp__333__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__333);
printf("\n = 0x%X",llvm_cbe_tmp__332);
printf("\n = 0x%X",((unsigned char )0));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_div}\n");
  return llvm_cbe_tmp__333;
}


static void aesl_internal_gf_poly_scale(l_struct_OC_poly *llvm_cbe_r, l_struct_OC_poly *llvm_cbe_p,  char llvm_cbe_x) {
  static  unsigned long long aesl_llvm_cbe_1119_count = 0;
  static  unsigned long long aesl_llvm_cbe_1120_count = 0;
  static  unsigned long long aesl_llvm_cbe_1121_count = 0;
  static  unsigned long long aesl_llvm_cbe_1122_count = 0;
  static  unsigned long long aesl_llvm_cbe_1123_count = 0;
  static  unsigned long long aesl_llvm_cbe_1124_count = 0;
  static  unsigned long long aesl_llvm_cbe_1125_count = 0;
  static  unsigned long long aesl_llvm_cbe_1126_count = 0;
  static  unsigned long long aesl_llvm_cbe_1127_count = 0;
  static  unsigned long long aesl_llvm_cbe_1128_count = 0;
  static  unsigned long long aesl_llvm_cbe_1129_count = 0;
  static  unsigned long long aesl_llvm_cbe_1130_count = 0;
  static  unsigned long long aesl_llvm_cbe_1131_count = 0;
  static  unsigned long long aesl_llvm_cbe_1132_count = 0;
  static  unsigned long long aesl_llvm_cbe_1133_count = 0;
  signed long long *llvm_cbe_tmp__336;
  static  unsigned long long aesl_llvm_cbe_1134_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1135_count = 0;
   char *llvm_cbe_tmp__337;
  static  unsigned long long aesl_llvm_cbe_1136_count = 0;
  unsigned char llvm_cbe_tmp__338;
  static  unsigned long long aesl_llvm_cbe_1137_count = 0;
  unsigned char llvm_cbe_tmp__339;
  static  unsigned long long aesl_llvm_cbe_1138_count = 0;
   char *llvm_cbe_tmp__340;
  static  unsigned long long aesl_llvm_cbe_1139_count = 0;
  static  unsigned long long aesl_llvm_cbe_1140_count = 0;
  unsigned long long llvm_cbe_tmp__341;
  static  unsigned long long aesl_llvm_cbe_1141_count = 0;
  static  unsigned long long aesl_llvm_cbe_1142_count = 0;
  static  unsigned long long aesl_llvm_cbe_1143_count = 0;
  static  unsigned long long aesl_llvm_cbe_1144_count = 0;
  static  unsigned long long aesl_llvm_cbe_1145_count = 0;
  static  unsigned long long aesl_llvm_cbe_1146_count = 0;
  unsigned long long llvm_cbe_tmp__342;
  static  unsigned long long aesl_llvm_cbe_1147_count = 0;
  static  unsigned long long aesl_llvm_cbe_1148_count = 0;
  static  unsigned long long aesl_llvm_cbe_1149_count = 0;
  signed long long *llvm_cbe_tmp__343;
  static  unsigned long long aesl_llvm_cbe_1150_count = 0;
  static  unsigned long long aesl_llvm_cbe_1151_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_poly_scale\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1133_count);
  llvm_cbe_tmp__336 = (signed long long *)(&llvm_cbe_p->field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__344;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__344:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ 0, %%0 ], [ %%7, %%2  for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__341);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1135_count);
  llvm_cbe_tmp__337 = ( char *)(&llvm_cbe_p->field1[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i8* %%3, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1136_count);
  llvm_cbe_tmp__338 = (unsigned char )*llvm_cbe_tmp__337;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__338);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call fastcc zeroext i8 @aesl_internal_gf_mul(i8 zeroext %%4, i8 zeroext %%x), !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1137_count);
  llvm_cbe_tmp__339 = (unsigned char ) /*tail*/ aesl_internal_gf_mul(llvm_cbe_tmp__338, llvm_cbe_x);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__338);
printf("\nArgument x = 0x%X",llvm_cbe_x);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__339);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%storemerge1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1138_count);
  llvm_cbe_tmp__340 = ( char *)(&llvm_cbe_r->field1[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%5, i8* %%6, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1139_count);
  *llvm_cbe_tmp__340 = llvm_cbe_tmp__339;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__339);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i64 %%storemerge1, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1140_count);
  llvm_cbe_tmp__341 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__341&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1146_count);
  llvm_cbe_tmp__342 = (unsigned long long )*llvm_cbe_tmp__336;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__342);
  if ((((unsigned long long )llvm_cbe_tmp__341&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__342&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__345;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__341;   /* for PHI node */
    goto llvm_cbe_tmp__344;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__345:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1149_count);
  llvm_cbe_tmp__343 = (signed long long *)(&llvm_cbe_r->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_scale  --> \n", ++aesl_llvm_cbe_1150_count);
  *llvm_cbe_tmp__343 = llvm_cbe_tmp__342;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__342);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_poly_scale}\n");
  return;
}


static void aesl_internal_gf_poly_add(l_struct_OC_poly *llvm_cbe_dest, l_struct_OC_poly *llvm_cbe_p, l_struct_OC_poly *llvm_cbe_q) {
  static  unsigned long long aesl_llvm_cbe_r_count = 0;
  l_struct_OC_poly llvm_cbe_r;    /* Address-exposed local */
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
  signed long long *llvm_cbe_tmp__346;
  static  unsigned long long aesl_llvm_cbe_1167_count = 0;
  unsigned long long llvm_cbe_tmp__347;
  static  unsigned long long aesl_llvm_cbe_1168_count = 0;
  unsigned char llvm_cbe_tmp__348;
  static  unsigned long long aesl_llvm_cbe_1169_count = 0;
  signed long long *llvm_cbe_tmp__349;
  static  unsigned long long aesl_llvm_cbe_1170_count = 0;
  unsigned long long llvm_cbe_tmp__350;
  static  unsigned long long aesl_llvm_cbe_1171_count = 0;
  unsigned char llvm_cbe_tmp__351;
  static  unsigned long long aesl_llvm_cbe_1172_count = 0;
  unsigned char llvm_cbe_tmp__352;
  static  unsigned long long aesl_llvm_cbe_1173_count = 0;
  unsigned long long llvm_cbe_tmp__353;
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
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned long long llvm_cbe_storemerge6;
  unsigned long long llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1192_count = 0;
   char *llvm_cbe_tmp__354;
  static  unsigned long long aesl_llvm_cbe_1193_count = 0;
  unsigned char llvm_cbe_tmp__355;
  static  unsigned long long aesl_llvm_cbe_1194_count = 0;
  unsigned long long llvm_cbe_tmp__356;
  static  unsigned long long aesl_llvm_cbe_1195_count = 0;
  unsigned long long llvm_cbe_tmp__357;
  static  unsigned long long aesl_llvm_cbe_1196_count = 0;
   char *llvm_cbe_tmp__358;
  static  unsigned long long aesl_llvm_cbe_1197_count = 0;
  static  unsigned long long aesl_llvm_cbe_1198_count = 0;
  unsigned long long llvm_cbe_tmp__359;
  static  unsigned long long aesl_llvm_cbe_1199_count = 0;
  static  unsigned long long aesl_llvm_cbe_1200_count = 0;
  static  unsigned long long aesl_llvm_cbe_1201_count = 0;
  static  unsigned long long aesl_llvm_cbe_1202_count = 0;
  static  unsigned long long aesl_llvm_cbe_1203_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned long long llvm_cbe_storemerge15;
  unsigned long long llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1214_count = 0;
   char *llvm_cbe_tmp__360;
  static  unsigned long long aesl_llvm_cbe_1215_count = 0;
  unsigned char llvm_cbe_tmp__361;
  static  unsigned long long aesl_llvm_cbe_1216_count = 0;
  unsigned long long llvm_cbe_tmp__362;
  static  unsigned long long aesl_llvm_cbe_1217_count = 0;
  unsigned long long llvm_cbe_tmp__363;
  static  unsigned long long aesl_llvm_cbe_1218_count = 0;
   char *llvm_cbe_tmp__364;
  static  unsigned long long aesl_llvm_cbe_1219_count = 0;
  unsigned char llvm_cbe_tmp__365;
  static  unsigned long long aesl_llvm_cbe_1220_count = 0;
  unsigned char llvm_cbe_tmp__366;
  static  unsigned long long aesl_llvm_cbe_1221_count = 0;
  static  unsigned long long aesl_llvm_cbe_1222_count = 0;
  unsigned long long llvm_cbe_tmp__367;
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
  static  unsigned long long aesl_llvm_cbe_1236_count = 0;
  static  unsigned long long aesl_llvm_cbe_1237_count = 0;
  static  unsigned long long aesl_llvm_cbe_1238_count = 0;
  signed long long *llvm_cbe_tmp__368;
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
  static  unsigned long long aesl_llvm_cbe_storemerge24_count = 0;
  unsigned long long llvm_cbe_storemerge24;
  unsigned long long llvm_cbe_storemerge24__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1254_count = 0;
   char *llvm_cbe_tmp__369;
  static  unsigned long long aesl_llvm_cbe_1255_count = 0;
  unsigned char llvm_cbe_tmp__370;
  static  unsigned long long aesl_llvm_cbe_1256_count = 0;
   char *llvm_cbe_tmp__371;
  static  unsigned long long aesl_llvm_cbe_1257_count = 0;
  static  unsigned long long aesl_llvm_cbe_1258_count = 0;
  unsigned long long llvm_cbe_tmp__372;
  static  unsigned long long aesl_llvm_cbe_1259_count = 0;
  static  unsigned long long aesl_llvm_cbe_1260_count = 0;
  static  unsigned long long aesl_llvm_cbe_1261_count = 0;
  static  unsigned long long aesl_llvm_cbe_1262_count = 0;
  static  unsigned long long aesl_llvm_cbe_1263_count = 0;
  static  unsigned long long aesl_llvm_cbe_1264_count = 0;
  static  unsigned long long aesl_llvm_cbe_1265_count = 0;
  static  unsigned long long aesl_llvm_cbe_1266_count = 0;
  static  unsigned long long aesl_llvm_cbe_1267_count = 0;
  static  unsigned long long aesl_llvm_cbe_1268_count = 0;
  static  unsigned long long aesl_llvm_cbe_1269_count = 0;
  static  unsigned long long aesl_llvm_cbe_1270_count = 0;
  static  unsigned long long aesl_llvm_cbe_1271_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1272_count = 0;
  static  unsigned long long aesl_llvm_cbe_1273_count = 0;
  signed long long *llvm_cbe_tmp__373;
  static  unsigned long long aesl_llvm_cbe_1274_count = 0;
  static  unsigned long long aesl_llvm_cbe_1275_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_poly_add\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1166_count);
  llvm_cbe_tmp__346 = (signed long long *)(&llvm_cbe_p->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = load i64* %%1, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1167_count);
  llvm_cbe_tmp__347 = (unsigned long long )*llvm_cbe_tmp__346;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__347);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = trunc i64 %%2 to i8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1168_count);
  llvm_cbe_tmp__348 = (unsigned char )((unsigned char )llvm_cbe_tmp__347&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__348);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1169_count);
  llvm_cbe_tmp__349 = (signed long long *)(&llvm_cbe_q->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i64* %%4, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1170_count);
  llvm_cbe_tmp__350 = (unsigned long long )*llvm_cbe_tmp__349;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__350);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i64 %%5 to i8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1171_count);
  llvm_cbe_tmp__351 = (unsigned char )((unsigned char )llvm_cbe_tmp__350&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call fastcc zeroext i8 @aesl_internal_max(i8 zeroext %%3, i8 zeroext %%6), !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1172_count);
  llvm_cbe_tmp__352 = (unsigned char )aesl_internal_max(llvm_cbe_tmp__348, llvm_cbe_tmp__351);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__348);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__351);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__352);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = zext i8 %%7 to i64, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1173_count);
  llvm_cbe_tmp__353 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__352&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__353);
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__374;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__374:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i64 [ 0, %%0 ], [ %%15, %%9  for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned long long )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%I64X",llvm_cbe_storemerge6);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__359);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.poly* %%p, i64 0, i32 1, i64 %%storemerge6, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1192_count);
  llvm_cbe_tmp__354 = ( char *)(&llvm_cbe_p->field1[(((signed long long )llvm_cbe_storemerge6))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%I64X",((signed long long )llvm_cbe_storemerge6));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i8* %%10, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1193_count);
  llvm_cbe_tmp__355 = (unsigned char )*llvm_cbe_tmp__354;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%storemerge6, %%8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1194_count);
  llvm_cbe_tmp__356 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge6&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__353&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__356&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sub i64 %%12, %%2, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1195_count);
  llvm_cbe_tmp__357 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__356&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__347&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__357&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%13, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1196_count);
  llvm_cbe_tmp__358 = ( char *)(&llvm_cbe_r.field1[(((signed long long )llvm_cbe_tmp__357))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__357));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%11, i8* %%14, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1197_count);
  *llvm_cbe_tmp__358 = llvm_cbe_tmp__355;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__355);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = add i64 %%storemerge6, 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1198_count);
  llvm_cbe_tmp__359 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge6&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__359&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__359&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__347&18446744073709551615ULL))) {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__359;   /* for PHI node */
    goto llvm_cbe_tmp__374;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i64 [ %%24, %%.preheader ], [ 0, %%9  for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned long long )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",llvm_cbe_storemerge15);
printf("\n = 0x%I64X",llvm_cbe_tmp__367);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct.poly* %%q, i64 0, i32 1, i64 %%storemerge15, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1214_count);
  llvm_cbe_tmp__360 = ( char *)(&llvm_cbe_q->field1[(((signed long long )llvm_cbe_storemerge15))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%I64X",((signed long long )llvm_cbe_storemerge15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i8* %%17, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1215_count);
  llvm_cbe_tmp__361 = (unsigned char )*llvm_cbe_tmp__360;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__361);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i64 %%storemerge15, %%8, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1216_count);
  llvm_cbe_tmp__362 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(llvm_cbe_tmp__353&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__362&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sub i64 %%19, %%5, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1217_count);
  llvm_cbe_tmp__363 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__362&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__350&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__363&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%20, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1218_count);
  llvm_cbe_tmp__364 = ( char *)(&llvm_cbe_r.field1[(((signed long long )llvm_cbe_tmp__363))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__363));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i8* %%21, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1219_count);
  llvm_cbe_tmp__365 = (unsigned char )*llvm_cbe_tmp__364;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__365);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = xor i8 %%22, %%18, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1220_count);
  llvm_cbe_tmp__366 = (unsigned char )((unsigned char )(llvm_cbe_tmp__365 ^ llvm_cbe_tmp__361));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%23, i8* %%21, align 1, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1221_count);
  *llvm_cbe_tmp__364 = llvm_cbe_tmp__366;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__366);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add i64 %%storemerge15, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1222_count);
  llvm_cbe_tmp__367 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge15&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__367&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__367&18446744073709551615ULL) > ((unsigned long long )llvm_cbe_tmp__350&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__375;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__367;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__375:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1238_count);
  llvm_cbe_tmp__368 = (signed long long *)(&llvm_cbe_r.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%27, align 8, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1239_count);
  *llvm_cbe_tmp__368 = llvm_cbe_tmp__353;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__353);
  llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__376;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__376:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge24 = phi i64 [ 0, %%26 ], [ %%32, %%28  for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_storemerge24_count);
  llvm_cbe_storemerge24 = (unsigned long long )llvm_cbe_storemerge24__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%I64X",llvm_cbe_storemerge24);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__372);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds %%struct.poly* %%r, i64 0, i32 1, i64 %%storemerge24, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1254_count);
  llvm_cbe_tmp__369 = ( char *)(&llvm_cbe_r.field1[(((signed long long )llvm_cbe_storemerge24))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%I64X",((signed long long )llvm_cbe_storemerge24));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1255_count);
  llvm_cbe_tmp__370 = (unsigned char )*llvm_cbe_tmp__369;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds %%struct.poly* %%dest, i64 0, i32 1, i64 %%storemerge24, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1256_count);
  llvm_cbe_tmp__371 = ( char *)(&llvm_cbe_dest->field1[(((signed long long )llvm_cbe_storemerge24))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge24 = 0x%I64X",((signed long long )llvm_cbe_storemerge24));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%30, i8* %%31, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1257_count);
  *llvm_cbe_tmp__371 = llvm_cbe_tmp__370;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__370);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = add i64 %%storemerge24, 1, !dbg !15 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1258_count);
  llvm_cbe_tmp__372 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge24&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__372&18446744073709551615ull)));
  if (((llvm_cbe_tmp__372&18446744073709551615ULL) == (520ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__377;
  } else {
    llvm_cbe_storemerge24__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__372;   /* for PHI node */
    goto llvm_cbe_tmp__376;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__377:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds %%struct.poly* %%dest, i64 0, i32 0, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1273_count);
  llvm_cbe_tmp__373 = (signed long long *)(&llvm_cbe_dest->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%8, i64* %%34, align 8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_poly_add  --> \n", ++aesl_llvm_cbe_1274_count);
  *llvm_cbe_tmp__373 = llvm_cbe_tmp__353;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__353);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_poly_add}\n");
  return;
}


static unsigned char aesl_internal_max( char llvm_cbe_a,  char llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_1276_count = 0;
  static  unsigned long long aesl_llvm_cbe_1277_count = 0;
  static  unsigned long long aesl_llvm_cbe_1278_count = 0;
  static  unsigned long long aesl_llvm_cbe_1279_count = 0;
  static  unsigned long long aesl_llvm_cbe_1280_count = 0;
  static  unsigned long long aesl_llvm_cbe_1281_count = 0;
  static  unsigned long long aesl_llvm_cbe_1282_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_in_count = 0;
  unsigned char llvm_cbe__2e_in;
  static  unsigned long long aesl_llvm_cbe_1283_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_max\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%.in = select i1 %%1, i8 %%b, i8 %%a, !dbg !12 for 0x%I64xth hint within @aesl_internal_max  --> \n", ++aesl_llvm_cbe__2e_in_count);
  llvm_cbe__2e_in = (unsigned char )(((((unsigned char )llvm_cbe_a&255U) < ((unsigned char )llvm_cbe_b&255U))) ? ((unsigned char )llvm_cbe_b) : ((unsigned char )llvm_cbe_a));
if (AESL_DEBUG_TRACE)
printf("\n.in = 0x%X\n", llvm_cbe__2e_in);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_max}\n");
  return llvm_cbe__2e_in;
}


static void aesl_internal_gf_init(void) {
  static  unsigned long long aesl_llvm_cbe_1284_count = 0;
  unsigned char llvm_cbe_tmp__378;
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
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned long long llvm_cbe_storemerge6;
  unsigned long long llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge125_count = 0;
  unsigned long long llvm_cbe_storemerge125;
  unsigned long long llvm_cbe_storemerge125__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1304_count = 0;
  unsigned long long llvm_cbe_tmp__379;
  static  unsigned long long aesl_llvm_cbe_1305_count = 0;
  static  unsigned long long aesl_llvm_cbe_1306_count = 0;
  unsigned long long llvm_cbe_tmp__380;
  static  unsigned long long aesl_llvm_cbe_1307_count = 0;
  static  unsigned long long aesl_llvm_cbe_1308_count = 0;
  static  unsigned long long aesl_llvm_cbe_1309_count = 0;
  static  unsigned long long aesl_llvm_cbe_1310_count = 0;
  static  unsigned long long aesl_llvm_cbe_1311_count = 0;
  static  unsigned long long aesl_llvm_cbe_1312_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_2e__count = 0;
  unsigned long long llvm_cbe_storemerge_2e_;
  static  unsigned long long aesl_llvm_cbe_1313_count = 0;
  unsigned char llvm_cbe_tmp__381;
  static  unsigned long long aesl_llvm_cbe_1314_count = 0;
   char *llvm_cbe_tmp__382;
  static  unsigned long long aesl_llvm_cbe_1315_count = 0;
  static  unsigned long long aesl_llvm_cbe_1316_count = 0;
  unsigned char llvm_cbe_tmp__383;
  static  unsigned long long aesl_llvm_cbe_1317_count = 0;
   char *llvm_cbe_tmp__384;
  static  unsigned long long aesl_llvm_cbe_1318_count = 0;
  static  unsigned long long aesl_llvm_cbe_1319_count = 0;
  unsigned long long llvm_cbe_tmp__385;
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
  unsigned long long llvm_cbe_tmp__386;
  static  unsigned long long aesl_llvm_cbe_1330_count = 0;
  static  unsigned long long aesl_llvm_cbe_1331_count = 0;
  static  unsigned long long aesl_llvm_cbe_1332_count = 0;
  static  unsigned long long aesl_llvm_cbe_1333_count = 0;
  static  unsigned long long aesl_llvm_cbe_1334_count = 0;
  static  unsigned long long aesl_llvm_cbe_1335_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond7_count = 0;
  static  unsigned long long aesl_llvm_cbe_1336_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1337_count = 0;
  unsigned long long llvm_cbe_tmp__387;
  static  unsigned long long aesl_llvm_cbe_1338_count = 0;
   char *llvm_cbe_tmp__388;
  static  unsigned long long aesl_llvm_cbe_1339_count = 0;
  unsigned char llvm_cbe_tmp__389;
  static  unsigned long long aesl_llvm_cbe_1340_count = 0;
   char *llvm_cbe_tmp__390;
  static  unsigned long long aesl_llvm_cbe_1341_count = 0;
  static  unsigned long long aesl_llvm_cbe_1342_count = 0;
  unsigned long long llvm_cbe_tmp__391;
  static  unsigned long long aesl_llvm_cbe_1343_count = 0;
  static  unsigned long long aesl_llvm_cbe_1344_count = 0;
  static  unsigned long long aesl_llvm_cbe_1345_count = 0;
  static  unsigned long long aesl_llvm_cbe_1346_count = 0;
  static  unsigned long long aesl_llvm_cbe_1347_count = 0;
  static  unsigned long long aesl_llvm_cbe_1348_count = 0;
  static  unsigned long long aesl_llvm_cbe_1349_count = 0;
  static  unsigned long long aesl_llvm_cbe_1350_count = 0;
  static  unsigned long long aesl_llvm_cbe_1351_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1352_count = 0;
  static  unsigned long long aesl_llvm_cbe_1353_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_gf_init\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* @aesl_internal_gf_init.done, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1284_count);
  llvm_cbe_tmp__378 = (unsigned char )*(&aesl_internal_gf_init_OC_done);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__378);
  if (((llvm_cbe_tmp__378&255U) == (((unsigned char )0)&255U))) {
    goto llvm_cbe_tmp__392;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__392:
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* @aesl_internal_gf_init.done, align 1, !dbg !12 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1287_count);
  *(&aesl_internal_gf_init_OC_done) = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )1ull;   /* for PHI node */
  llvm_cbe_storemerge125__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__393;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__393:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i64 [ 1, %%3 ], [ %%13, %%4  for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned long long )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%I64X",llvm_cbe_storemerge6);
printf("\n = 0x%I64X",1ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__386);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge125 = phi i64 [ 0, %%3 ], [ %%12, %%4  for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_storemerge125_count);
  llvm_cbe_storemerge125 = (unsigned long long )llvm_cbe_storemerge125__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge125 = 0x%I64X",llvm_cbe_storemerge125);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__385);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = and i64 %%storemerge6, 256, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1304_count);
  llvm_cbe_tmp__379 = (unsigned long long )llvm_cbe_storemerge6 & 256ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__379);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = xor i64 %%storemerge6, 285, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1306_count);
  llvm_cbe_tmp__380 = (unsigned long long )llvm_cbe_storemerge6 ^ 285ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__380);
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge. = select i1 %%6, i64 %%storemerge6, i64 %%7, !dbg !14 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_storemerge_2e__count);
  llvm_cbe_storemerge_2e_ = (unsigned long long )((((llvm_cbe_tmp__379&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) ? ((unsigned long long )llvm_cbe_storemerge6) : ((unsigned long long )llvm_cbe_tmp__380));
if (AESL_DEBUG_TRACE)
printf("\nstoremerge. = 0x%I64X\n", llvm_cbe_storemerge_2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = trunc i64 %%storemerge. to i8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1313_count);
  llvm_cbe_tmp__381 = (unsigned char )((unsigned char )llvm_cbe_storemerge_2e_&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__381);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%storemerge125, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1314_count);
  llvm_cbe_tmp__382 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_storemerge125))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge125 = 0x%I64X",((signed long long )llvm_cbe_storemerge125));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge125) < 512 && "Write access out of array 'aesl_internal_gf_exp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%8, i8* %%9, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1315_count);
  *llvm_cbe_tmp__382 = llvm_cbe_tmp__381;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__381);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = trunc i64 %%storemerge125 to i8, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1316_count);
  llvm_cbe_tmp__383 = (unsigned char )((unsigned char )llvm_cbe_storemerge125&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [256 x i8]* @aesl_internal_gf_log, i64 0, i64 %%storemerge., !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1317_count);
  llvm_cbe_tmp__384 = ( char *)(&aesl_internal_gf_log[(((signed long long )llvm_cbe_storemerge_2e_))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge. = 0x%I64X",((signed long long )llvm_cbe_storemerge_2e_));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge_2e_) < 256 && "Write access out of array 'aesl_internal_gf_log' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%10, i8* %%11, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1318_count);
  *llvm_cbe_tmp__384 = llvm_cbe_tmp__383;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__383);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i64 %%storemerge125, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1319_count);
  llvm_cbe_tmp__385 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge125&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__385&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = shl i64 %%storemerge., 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1329_count);
  llvm_cbe_tmp__386 = (unsigned long long )llvm_cbe_storemerge_2e_ << 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__386);
  if (((llvm_cbe_tmp__385&18446744073709551615ULL) == (255ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )255ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__386;   /* for PHI node */
    llvm_cbe_storemerge125__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__385;   /* for PHI node */
    goto llvm_cbe_tmp__393;
  }

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ %%18, %%.preheader ], [ 255, %%4  for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",llvm_cbe_tmp__391);
printf("\n = 0x%I64X",255ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = add i64 %%storemerge14, -255, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1337_count);
  llvm_cbe_tmp__387 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(18446744073709551361ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__387&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%14, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1338_count);
  llvm_cbe_tmp__388 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_tmp__387))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__387));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__387) < 512)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_gf_exp' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1339_count);
  llvm_cbe_tmp__389 = (unsigned char )*llvm_cbe_tmp__388;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [512 x i8]* @aesl_internal_gf_exp, i64 0, i64 %%storemerge14, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1340_count);
  llvm_cbe_tmp__390 = ( char *)(&aesl_internal_gf_exp[(((signed long long )llvm_cbe_storemerge14))
#ifdef AESL_BC_SIM
 % 512
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",((signed long long )llvm_cbe_storemerge14));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_storemerge14) < 512 && "Write access out of array 'aesl_internal_gf_exp' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%16, i8* %%17, align 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1341_count);
  *llvm_cbe_tmp__390 = llvm_cbe_tmp__389;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__389);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i64 %%storemerge14, 1, !dbg !13 for 0x%I64xth hint within @aesl_internal_gf_init  --> \n", ++aesl_llvm_cbe_1342_count);
  llvm_cbe_tmp__391 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__391&18446744073709551615ull)));
  if (((llvm_cbe_tmp__391&18446744073709551615ULL) == (512ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__391;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_gf_init}\n");
  return;
}

