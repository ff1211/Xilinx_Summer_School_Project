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
extern unsigned int bch_format_gen;
extern unsigned int bch_format_mask;
extern  char code_to_ecl[4];
extern  char version_range[41];
extern  char lenbits[5][3];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void qrc_decoder( char *llvm_cbe_pdata,  char llvm_cbe_dataout);
signed int bch_decode(signed int , signed int );
signed int get_bits(l_struct_OC_scanner *, signed long long );


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

void qrc_decoder( char *llvm_cbe_pdata,  char llvm_cbe_dataout) {
  static  unsigned long long aesl_llvm_cbe_scanner_count = 0;
  l_struct_OC_scanner llvm_cbe_scanner;    /* Address-exposed local */
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
   char **llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge26_count = 0;
  unsigned int llvm_cbe_storemerge26;
  unsigned int llvm_cbe_storemerge26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge625_count = 0;
  unsigned int llvm_cbe_storemerge625;
  unsigned int llvm_cbe_storemerge625__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  unsigned char llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond34_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_exitcond35_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  signed long long *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  signed int *llvm_cbe_tmp__12;
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
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned char llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_count = 0;
  unsigned int llvm_cbe_phitmp;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned char llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_2e_1_count = 0;
  unsigned int llvm_cbe_phitmp_2e_1;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned char llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_2e_2_count = 0;
  unsigned int llvm_cbe_phitmp_2e_2;
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
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_2e_3_count = 0;
  unsigned int llvm_cbe_phitmp_2e_3;
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
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned char llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned int llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_phitmp_2e_4_count = 0;
  unsigned int llvm_cbe_phitmp_2e_4;
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
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  unsigned char llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  unsigned int llvm_cbe_tmp__35;
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
  static  unsigned long long aesl_llvm_cbe_phitmp_2e_5_count = 0;
  unsigned int llvm_cbe_phitmp_2e_5;
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
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  unsigned char llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned char llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned char llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
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
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  unsigned char llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
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
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
   char *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned char llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
  unsigned int llvm_cbe_tmp__59;
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
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  unsigned char llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  unsigned int llvm_cbe_tmp__64;
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
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
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
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
   char *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  unsigned char llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  unsigned int llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  unsigned int llvm_cbe_tmp__69;
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
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
   char *llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  unsigned char llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_484_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_485_count = 0;
  unsigned int llvm_cbe_tmp__74;
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
  static  unsigned long long aesl_llvm_cbe_498_count = 0;
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
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_513_count = 0;
   char *llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_514_count = 0;
  unsigned char llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_515_count = 0;
  unsigned int llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_516_count = 0;
  unsigned int llvm_cbe_tmp__79;
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
  static  unsigned long long aesl_llvm_cbe_535_count = 0;
  static  unsigned long long aesl_llvm_cbe_536_count = 0;
  static  unsigned long long aesl_llvm_cbe_537_count = 0;
  static  unsigned long long aesl_llvm_cbe_538_count = 0;
  static  unsigned long long aesl_llvm_cbe_539_count = 0;
  static  unsigned long long aesl_llvm_cbe_540_count = 0;
  static  unsigned long long aesl_llvm_cbe_541_count = 0;
  static  unsigned long long aesl_llvm_cbe_542_count = 0;
  static  unsigned long long aesl_llvm_cbe_543_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_544_count = 0;
  unsigned int llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_545_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_546_count = 0;
  unsigned int llvm_cbe_tmp__83;
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
  static  unsigned long long aesl_llvm_cbe_566_count = 0;
  static  unsigned long long aesl_llvm_cbe_567_count = 0;
  static  unsigned long long aesl_llvm_cbe_568_count = 0;
  static  unsigned long long aesl_llvm_cbe_569_count = 0;
  static  unsigned long long aesl_llvm_cbe_570_count = 0;
  static  unsigned long long aesl_llvm_cbe_571_count = 0;
  static  unsigned long long aesl_llvm_cbe_572_count = 0;
  static  unsigned long long aesl_llvm_cbe_573_count = 0;
  static  unsigned long long aesl_llvm_cbe_574_count = 0;
  static  unsigned long long aesl_llvm_cbe_575_count = 0;
  static  unsigned long long aesl_llvm_cbe_576_count = 0;
  static  unsigned long long aesl_llvm_cbe_577_count = 0;
   char *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_578_count = 0;
  unsigned char llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_579_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_580_count = 0;
  static  unsigned long long aesl_llvm_cbe_581_count = 0;
  static  unsigned long long aesl_llvm_cbe_582_count = 0;
  static  unsigned long long aesl_llvm_cbe_583_count = 0;
  static  unsigned long long aesl_llvm_cbe_584_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_595_count = 0;
  static  unsigned long long aesl_llvm_cbe_596_count = 0;
  static  unsigned long long aesl_llvm_cbe_597_count = 0;
  static  unsigned long long aesl_llvm_cbe_598_count = 0;
  static  unsigned long long aesl_llvm_cbe_599_count = 0;
  static  unsigned long long aesl_llvm_cbe_600_count = 0;
  static  unsigned long long aesl_llvm_cbe_601_count = 0;
  unsigned int llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_602_count = 0;
   char *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_603_count = 0;
  unsigned char llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_604_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_605_count = 0;
  unsigned int llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_606_count = 0;
  static  unsigned long long aesl_llvm_cbe_607_count = 0;
  static  unsigned long long aesl_llvm_cbe_608_count = 0;
  static  unsigned long long aesl_llvm_cbe_609_count = 0;
  static  unsigned long long aesl_llvm_cbe_610_count = 0;
  static  unsigned long long aesl_llvm_cbe_611_count = 0;
  static  unsigned long long aesl_llvm_cbe_612_count = 0;
  static  unsigned long long aesl_llvm_cbe_613_count = 0;
  static  unsigned long long aesl_llvm_cbe_614_count = 0;
  static  unsigned long long aesl_llvm_cbe_615_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_626_count = 0;
  static  unsigned long long aesl_llvm_cbe_627_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_628_count = 0;
   char *llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_629_count = 0;
  unsigned char llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_630_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_631_count = 0;
  unsigned int llvm_cbe_tmp__96;
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
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_654_count = 0;
   char *llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_655_count = 0;
  unsigned char llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_656_count = 0;
  unsigned int llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_657_count = 0;
  unsigned int llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_658_count = 0;
  static  unsigned long long aesl_llvm_cbe_659_count = 0;
  static  unsigned long long aesl_llvm_cbe_660_count = 0;
  static  unsigned long long aesl_llvm_cbe_661_count = 0;
  static  unsigned long long aesl_llvm_cbe_662_count = 0;
  static  unsigned long long aesl_llvm_cbe_663_count = 0;
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
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_680_count = 0;
   char *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_681_count = 0;
  unsigned char llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_682_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_683_count = 0;
  unsigned int llvm_cbe_tmp__106;
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
  static  unsigned long long aesl_llvm_cbe_699_count = 0;
  static  unsigned long long aesl_llvm_cbe_700_count = 0;
  static  unsigned long long aesl_llvm_cbe_701_count = 0;
  static  unsigned long long aesl_llvm_cbe_702_count = 0;
  static  unsigned long long aesl_llvm_cbe_703_count = 0;
  static  unsigned long long aesl_llvm_cbe_704_count = 0;
  static  unsigned long long aesl_llvm_cbe_705_count = 0;
  unsigned int llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_706_count = 0;
   char *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_707_count = 0;
  unsigned char llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_708_count = 0;
  unsigned int llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_709_count = 0;
  unsigned int llvm_cbe_tmp__111;
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
  static  unsigned long long aesl_llvm_cbe_727_count = 0;
  static  unsigned long long aesl_llvm_cbe_728_count = 0;
  static  unsigned long long aesl_llvm_cbe_729_count = 0;
  static  unsigned long long aesl_llvm_cbe_730_count = 0;
  static  unsigned long long aesl_llvm_cbe_731_count = 0;
  unsigned int llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_732_count = 0;
   char *llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_733_count = 0;
  unsigned char llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_734_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_735_count = 0;
  unsigned int llvm_cbe_tmp__116;
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
  static  unsigned long long aesl_llvm_cbe_763_count = 0;
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
  unsigned int llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_774_count = 0;
   char *llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_775_count = 0;
  unsigned char llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_776_count = 0;
  unsigned int llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_777_count = 0;
  unsigned int llvm_cbe_tmp__121;
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
  static  unsigned long long aesl_llvm_cbe_796_count = 0;
  static  unsigned long long aesl_llvm_cbe_797_count = 0;
  static  unsigned long long aesl_llvm_cbe_798_count = 0;
  static  unsigned long long aesl_llvm_cbe_799_count = 0;
  unsigned int llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_800_count = 0;
   char *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_801_count = 0;
  unsigned char llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_802_count = 0;
  unsigned int llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_803_count = 0;
  unsigned int llvm_cbe_tmp__126;
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
  unsigned int llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_826_count = 0;
   char *llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_827_count = 0;
  unsigned char llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_828_count = 0;
  unsigned int llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_829_count = 0;
  unsigned int llvm_cbe_tmp__131;
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
  unsigned int llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_852_count = 0;
   char *llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_853_count = 0;
  unsigned char llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_854_count = 0;
  unsigned int llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_855_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_856_count = 0;
  static  unsigned long long aesl_llvm_cbe_857_count = 0;
  static  unsigned long long aesl_llvm_cbe_858_count = 0;
  static  unsigned long long aesl_llvm_cbe_859_count = 0;
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
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_878_count = 0;
   char *llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_879_count = 0;
  unsigned char llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_880_count = 0;
  unsigned int llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_881_count = 0;
  unsigned int llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_882_count = 0;
  static  unsigned long long aesl_llvm_cbe_883_count = 0;
  static  unsigned long long aesl_llvm_cbe_884_count = 0;
  static  unsigned long long aesl_llvm_cbe_885_count = 0;
  static  unsigned long long aesl_llvm_cbe_886_count = 0;
  static  unsigned long long aesl_llvm_cbe_887_count = 0;
  static  unsigned long long aesl_llvm_cbe_888_count = 0;
  static  unsigned long long aesl_llvm_cbe_889_count = 0;
  static  unsigned long long aesl_llvm_cbe_890_count = 0;
  static  unsigned long long aesl_llvm_cbe_891_count = 0;
  static  unsigned long long aesl_llvm_cbe_892_count = 0;
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
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_904_count = 0;
   char *llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_905_count = 0;
  unsigned char llvm_cbe_tmp__144;
  static  unsigned long long aesl_llvm_cbe_906_count = 0;
  unsigned int llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_907_count = 0;
  unsigned int llvm_cbe_tmp__146;
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
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_930_count = 0;
   char *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_931_count = 0;
  unsigned char llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_932_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_933_count = 0;
  unsigned int llvm_cbe_tmp__151;
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
  unsigned int llvm_cbe_tmp__152;
  static  unsigned long long aesl_llvm_cbe_956_count = 0;
   char *llvm_cbe_tmp__153;
  static  unsigned long long aesl_llvm_cbe_957_count = 0;
  unsigned char llvm_cbe_tmp__154;
  static  unsigned long long aesl_llvm_cbe_958_count = 0;
  unsigned int llvm_cbe_tmp__155;
  static  unsigned long long aesl_llvm_cbe_959_count = 0;
  unsigned int llvm_cbe_tmp__156;
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
  unsigned int llvm_cbe_tmp__157;
  static  unsigned long long aesl_llvm_cbe_982_count = 0;
  unsigned int llvm_cbe_tmp__158;
  static  unsigned long long aesl_llvm_cbe_983_count = 0;
  static  unsigned long long aesl_llvm_cbe_984_count = 0;
  static  unsigned long long aesl_llvm_cbe_985_count = 0;
  static  unsigned long long aesl_llvm_cbe_986_count = 0;
  static  unsigned long long aesl_llvm_cbe_987_count = 0;
  unsigned int llvm_cbe_tmp__159;
  static  unsigned long long aesl_llvm_cbe_988_count = 0;
  signed int *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_989_count = 0;
  static  unsigned long long aesl_llvm_cbe_990_count = 0;
  unsigned int llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_991_count = 0;
  unsigned long long llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_992_count = 0;
   char *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_993_count = 0;
  unsigned char llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_994_count = 0;
  unsigned int llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_995_count = 0;
  signed int *llvm_cbe_tmp__166;
  static  unsigned long long aesl_llvm_cbe_996_count = 0;
  static  unsigned long long aesl_llvm_cbe_997_count = 0;
  signed long long *llvm_cbe_tmp__167;
  static  unsigned long long aesl_llvm_cbe_998_count = 0;
  static  unsigned long long aesl_llvm_cbe_999_count = 0;
  unsigned int llvm_cbe_tmp__168;
  static  unsigned long long aesl_llvm_cbe_1000_count = 0;
  unsigned char llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_1001_count = 0;
  static  unsigned long long aesl_llvm_cbe_1002_count = 0;
  static  unsigned long long aesl_llvm_cbe_1003_count = 0;
  static  unsigned long long aesl_llvm_cbe_1004_count = 0;
  static  unsigned long long aesl_llvm_cbe_1005_count = 0;
  static  unsigned long long aesl_llvm_cbe_1006_count = 0;
  unsigned char llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_1007_count = 0;
  unsigned long long llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_1008_count = 0;
  unsigned long long llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_1009_count = 0;
   char *llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_1010_count = 0;
  unsigned char llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_1011_count = 0;
  unsigned long long llvm_cbe_tmp__175;
  static  unsigned long long aesl_llvm_cbe_1012_count = 0;
  unsigned int llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_1013_count = 0;
  unsigned long long llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_1014_count = 0;
  static  unsigned long long aesl_llvm_cbe_1015_count = 0;
  static  unsigned long long aesl_llvm_cbe_1016_count = 0;
  static  unsigned long long aesl_llvm_cbe_1017_count = 0;
  static  unsigned long long aesl_llvm_cbe_1018_count = 0;
  static  unsigned long long aesl_llvm_cbe_1019_count = 0;
  static  unsigned long long aesl_llvm_cbe_1020_count = 0;
  static  unsigned long long aesl_llvm_cbe_1021_count = 0;
  static  unsigned long long aesl_llvm_cbe_1022_count = 0;
  static  unsigned long long aesl_llvm_cbe_1023_count = 0;
  static  unsigned long long aesl_llvm_cbe_1024_count = 0;
  static  unsigned long long aesl_llvm_cbe_1025_count = 0;
  static  unsigned long long aesl_llvm_cbe_1026_count = 0;
  static  unsigned long long aesl_llvm_cbe_1027_count = 0;
  unsigned long long llvm_cbe_tmp__178;
  unsigned long long llvm_cbe_tmp__178__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1028_count = 0;
  unsigned int llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_1029_count = 0;
  static  unsigned long long aesl_llvm_cbe_1030_count = 0;
  static  unsigned long long aesl_llvm_cbe_1031_count = 0;
  static  unsigned long long aesl_llvm_cbe_1032_count = 0;
  static  unsigned long long aesl_llvm_cbe_1033_count = 0;
  unsigned long long llvm_cbe_tmp__180;
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
  static  unsigned long long aesl_llvm_cbe__2e_lcssa11_count = 0;
  unsigned long long llvm_cbe__2e_lcssa11;
  unsigned long long llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1045_count = 0;
  static  unsigned long long aesl_llvm_cbe_1046_count = 0;
  static  unsigned long long aesl_llvm_cbe_1047_count = 0;
  unsigned int llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_1048_count = 0;
  static  unsigned long long aesl_llvm_cbe_1049_count = 0;
  static  unsigned long long aesl_llvm_cbe_1050_count = 0;
  static  unsigned long long aesl_llvm_cbe_1051_count = 0;
  static  unsigned long long aesl_llvm_cbe_1052_count = 0;
  static  unsigned long long aesl_llvm_cbe_1053_count = 0;
  static  unsigned long long aesl_llvm_cbe_1054_count = 0;
  unsigned int llvm_cbe_tmp__182;
  static  unsigned long long aesl_llvm_cbe_1055_count = 0;
  static  unsigned long long aesl_llvm_cbe_1056_count = 0;
  static  unsigned long long aesl_llvm_cbe_1057_count = 0;
  static  unsigned long long aesl_llvm_cbe_1058_count = 0;
  static  unsigned long long aesl_llvm_cbe_1059_count = 0;
  static  unsigned long long aesl_llvm_cbe_1060_count = 0;
  static  unsigned long long aesl_llvm_cbe_1061_count = 0;
  static  unsigned long long aesl_llvm_cbe_1062_count = 0;
  static  unsigned long long aesl_llvm_cbe_1063_count = 0;
  static  unsigned long long aesl_llvm_cbe_1064_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  unsigned long long llvm_cbe_tmp__183__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1065_count = 0;
  unsigned int llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_1066_count = 0;
  static  unsigned long long aesl_llvm_cbe_1067_count = 0;
  static  unsigned long long aesl_llvm_cbe_1068_count = 0;
  static  unsigned long long aesl_llvm_cbe_1069_count = 0;
  unsigned long long llvm_cbe_tmp__185;
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
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1081_count = 0;
  static  unsigned long long aesl_llvm_cbe_1082_count = 0;
  static  unsigned long long aesl_llvm_cbe_1083_count = 0;
  unsigned int llvm_cbe_tmp__186;
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
  static  unsigned long long aesl_llvm_cbe_storemerge57_count = 0;
  unsigned long long llvm_cbe_storemerge57;
  unsigned long long llvm_cbe_storemerge57__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_1094_count = 0;
  unsigned int llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_1095_count = 0;
  static  unsigned long long aesl_llvm_cbe_1096_count = 0;
  unsigned long long llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_1097_count = 0;
  static  unsigned long long aesl_llvm_cbe_1098_count = 0;
  static  unsigned long long aesl_llvm_cbe_1099_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_1100_count = 0;
  static  unsigned long long aesl_llvm_cbe_1101_count = 0;
  static  unsigned long long aesl_llvm_cbe_1102_count = 0;
  static  unsigned long long aesl_llvm_cbe_1103_count = 0;
  static  unsigned long long aesl_llvm_cbe_1104_count = 0;
  static  unsigned long long aesl_llvm_cbe_1105_count = 0;
  static  unsigned long long aesl_llvm_cbe_1106_count = 0;
  static  unsigned long long aesl_llvm_cbe_1107_count = 0;
  static  unsigned long long aesl_llvm_cbe_1108_count = 0;
  static  unsigned long long aesl_llvm_cbe_1109_count = 0;
  static  unsigned long long aesl_llvm_cbe_1110_count = 0;
  static  unsigned long long aesl_llvm_cbe_1111_count = 0;
  static  unsigned long long aesl_llvm_cbe_1112_count = 0;
  static  unsigned long long aesl_llvm_cbe_1113_count = 0;
  static  unsigned long long aesl_llvm_cbe_1114_count = 0;
  static  unsigned long long aesl_llvm_cbe_1115_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @qrc_decoder\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 0, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__1 = ( char **)(&llvm_cbe_scanner.field0);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader24;

  do {     /* Syntactic loop '.preheader24' to make GCC happy */
llvm_cbe__2e_preheader24:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge26 = phi i32 [ 0, %%0 ], [ %%12, %%11  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_storemerge26_count);
  llvm_cbe_storemerge26 = (unsigned int )llvm_cbe_storemerge26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge26 = 0x%X",llvm_cbe_storemerge26);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = mul nsw i32 %%storemerge26, 21, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) * ((unsigned int )(21u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
  llvm_cbe_storemerge625__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__189;

llvm_cbe_tmp__190:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge26, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge26&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
  if (((llvm_cbe_tmp__10&4294967295U) == (21u&4294967295U))) {
    goto llvm_cbe__2e_preheader15;
  } else {
    llvm_cbe_storemerge26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe__2e_preheader24;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__189:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge625 = phi i32 [ 0, %%.preheader24 ], [ %%10, %%3  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_storemerge625_count);
  llvm_cbe_storemerge625 = (unsigned int )llvm_cbe_storemerge625__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge625 = 0x%X",llvm_cbe_storemerge625);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__9);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge625, %%2, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge625&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = sext i32 %%4 to i64, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__4 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%pdata, i64 %%5, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__5 = ( char *)(&llvm_cbe_pdata[(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = load i8* %%6, align 1, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_51_count);
  llvm_cbe_tmp__6 = (unsigned char )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i8** %%1, align 8, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__7 = ( char *)*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%8, i64 %%5, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_53_count);
  llvm_cbe_tmp__8 = ( char *)(&llvm_cbe_tmp__7[(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%7, i8* %%9, align 1, !dbg !5 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_54_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge625, 1, !dbg !13 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge625&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
  if (((llvm_cbe_tmp__9&4294967295U) == (21u&4294967295U))) {
    goto llvm_cbe_tmp__190;
  } else {
    llvm_cbe_storemerge625__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__9;   /* for PHI node */
    goto llvm_cbe_tmp__189;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader24' */
llvm_cbe__2e_preheader15:
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 1, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__11 = (signed long long *)(&llvm_cbe_scanner.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 21, i64* %%13, align 8, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_86_count);
  *llvm_cbe_tmp__11 = 21ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 21ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 2, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_scanner.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%14, align 8, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_93_count);
  *llvm_cbe_tmp__12 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds i8* %%pdata, i64 168, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_pdata[(((signed long long )168ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i8* %%15, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__14 = (unsigned char )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i8 %%16 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__14&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp = shl nuw nsw i32 %%17, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_count);
  llvm_cbe_phitmp = (unsigned int )llvm_cbe_tmp__15 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp = 0x%X\n", llvm_cbe_phitmp);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds i8* %%pdata, i64 169, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_pdata[(((signed long long )169ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i8* %%18, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_150_count);
  llvm_cbe_tmp__17 = (unsigned char )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i8 %%19 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__17&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%20, %%phitmp, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__19 = (unsigned int )((unsigned int )(llvm_cbe_tmp__18&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__19&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp.1 = shl nuw nsw i32 %%21, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_2e_1_count);
  llvm_cbe_phitmp_2e_1 = (unsigned int )llvm_cbe_tmp__19 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp.1 = 0x%X\n", llvm_cbe_phitmp_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds i8* %%pdata, i64 170, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__20 = ( char *)(&llvm_cbe_pdata[(((signed long long )170ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i8* %%22, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__21 = (unsigned char )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i8 %%23 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__21&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%24, %%phitmp.1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__23 = (unsigned int )((unsigned int )(llvm_cbe_tmp__22&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp_2e_1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__23&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp.2 = shl nsw i32 %%25, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_2e_2_count);
  llvm_cbe_phitmp_2e_2 = (unsigned int )llvm_cbe_tmp__23 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp.2 = 0x%X\n", llvm_cbe_phitmp_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i8* %%pdata, i64 171, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__24 = ( char *)(&llvm_cbe_pdata[(((signed long long )171ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i8* %%26, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__25 = (unsigned char )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = zext i8 %%27 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%28, %%phitmp.2, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_tmp__26&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp_2e_2&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp.3 = shl i32 %%29, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_2e_3_count);
  llvm_cbe_phitmp_2e_3 = (unsigned int )llvm_cbe_tmp__27 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp.3 = 0x%X\n", llvm_cbe_phitmp_2e_3);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds i8* %%pdata, i64 172, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_pdata[(((signed long long )172ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i8* %%30, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_240_count);
  llvm_cbe_tmp__29 = (unsigned char )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = zext i8 %%31 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__30 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__29&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%32, %%phitmp.3, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_242_count);
  llvm_cbe_tmp__31 = (unsigned int )((unsigned int )(llvm_cbe_tmp__30&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp_2e_3&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__31&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp.4 = shl i32 %%33, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_2e_4_count);
  llvm_cbe_phitmp_2e_4 = (unsigned int )llvm_cbe_tmp__31 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp.4 = 0x%X\n", llvm_cbe_phitmp_2e_4);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%pdata, i64 173, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_269_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_pdata[(((signed long long )173ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_270_count);
  llvm_cbe_tmp__33 = (unsigned char )*llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i8 %%35 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_271_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__33&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = add nsw i32 %%36, %%phitmp.4, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_272_count);
  llvm_cbe_tmp__35 = (unsigned int )((unsigned int )(llvm_cbe_tmp__34&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp_2e_4&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__35&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%phitmp.5 = shl i32 %%37, 1, !dbg !12 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_phitmp_2e_5_count);
  llvm_cbe_phitmp_2e_5 = (unsigned int )llvm_cbe_tmp__35 << 1u;
if (AESL_DEBUG_TRACE)
printf("\nphitmp.5 = 0x%X\n", llvm_cbe_phitmp_2e_5);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds i8* %%pdata, i64 175, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_pdata[(((signed long long )175ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = load i8* %%38, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__37 = (unsigned char )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = zext i8 %%39 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__37&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add nsw i32 %%40, %%phitmp.5, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_tmp__38&4294967295ull)) + ((unsigned int )(llvm_cbe_phitmp_2e_5&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = shl i32 %%41, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_312_count);
  llvm_cbe_tmp__40 = (unsigned int )llvm_cbe_tmp__39 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds i8* %%pdata, i64 176, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__41 = ( char *)(&llvm_cbe_pdata[(((signed long long )176ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = load i8* %%43, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__42 = (unsigned char )*llvm_cbe_tmp__41;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = zext i8 %%44 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__43 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__42&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = add nsw i32 %%42, %%45, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_316_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__40&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__43&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = shl i32 %%46, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__45 = (unsigned int )llvm_cbe_tmp__44 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds i8* %%pdata, i64 155, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__46 = ( char *)(&llvm_cbe_pdata[(((signed long long )155ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i8* %%48, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__47 = (unsigned char )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = zext i8 %%49 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__47&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add nsw i32 %%47, %%50, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__49 = (unsigned int )((unsigned int )(llvm_cbe_tmp__45&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__48&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__49&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = shl i32 %%51, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__50 = (unsigned int )llvm_cbe_tmp__49 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = getelementptr inbounds i8* %%pdata, i64 113, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__51 = ( char *)(&llvm_cbe_pdata[(((signed long long )113ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = load i8* %%53, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_359_count);
  llvm_cbe_tmp__52 = (unsigned char )*llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = zext i8 %%54 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__53 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__52&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add nsw i32 %%55, %%52, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_361_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_tmp__53&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__50&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = shl i32 %%56, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__55 = (unsigned int )llvm_cbe_tmp__54 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i8* %%pdata, i64 92, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__56 = ( char *)(&llvm_cbe_pdata[(((signed long long )92ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i8* %%58, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__57 = (unsigned char )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = zext i8 %%59 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__57&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = add nsw i32 %%60, %%57, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_392_count);
  llvm_cbe_tmp__59 = (unsigned int )((unsigned int )(llvm_cbe_tmp__58&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__55&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = shl i32 %%61, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__60 = (unsigned int )llvm_cbe_tmp__59 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = getelementptr inbounds i8* %%pdata, i64 71, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_420_count);
  llvm_cbe_tmp__61 = ( char *)(&llvm_cbe_pdata[(((signed long long )71ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = load i8* %%63, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__62 = (unsigned char )*llvm_cbe_tmp__61;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = zext i8 %%64 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_422_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__62&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add nsw i32 %%65, %%62, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_423_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(llvm_cbe_tmp__63&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__60&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__64&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = shl i32 %%66, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_450_count);
  llvm_cbe_tmp__65 = (unsigned int )llvm_cbe_tmp__64 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds i8* %%pdata, i64 50, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_451_count);
  llvm_cbe_tmp__66 = ( char *)(&llvm_cbe_pdata[(((signed long long )50ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i8* %%68, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_452_count);
  llvm_cbe_tmp__67 = (unsigned char )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = zext i8 %%69 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_453_count);
  llvm_cbe_tmp__68 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__67&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = add nsw i32 %%70, %%67, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_454_count);
  llvm_cbe_tmp__69 = (unsigned int )((unsigned int )(llvm_cbe_tmp__68&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__65&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__69&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = shl i32 %%71, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_481_count);
  llvm_cbe_tmp__70 = (unsigned int )llvm_cbe_tmp__69 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = getelementptr inbounds i8* %%pdata, i64 29, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_482_count);
  llvm_cbe_tmp__71 = ( char *)(&llvm_cbe_pdata[(((signed long long )29ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%74 = load i8* %%73, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_483_count);
  llvm_cbe_tmp__72 = (unsigned char )*llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = zext i8 %%74 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_484_count);
  llvm_cbe_tmp__73 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__72&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = add nsw i32 %%75, %%72, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_485_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_tmp__73&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__70&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = shl i32 %%76, 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_512_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_tmp__74 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = getelementptr inbounds i8* %%pdata, i64 8, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_513_count);
  llvm_cbe_tmp__76 = ( char *)(&llvm_cbe_pdata[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = load i8* %%78, align 1, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_514_count);
  llvm_cbe_tmp__77 = (unsigned char )*llvm_cbe_tmp__76;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = zext i8 %%79 to i32, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_515_count);
  llvm_cbe_tmp__78 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__77&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__78);
if (AESL_DEBUG_TRACE)
printf("\n  %%81 = add nsw i32 %%80, %%77, !dbg !6 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_516_count);
  llvm_cbe_tmp__79 = (unsigned int )((unsigned int )(llvm_cbe_tmp__78&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__75&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__79&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%82 = load i32* @bch_format_gen, align 4, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_543_count);
  llvm_cbe_tmp__80 = (unsigned int )*(&bch_format_gen);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = load i32* @bch_format_mask, align 4, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_544_count);
  llvm_cbe_tmp__81 = (unsigned int )*(&bch_format_mask);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%84 = xor i32 %%83, %%81, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_545_count);
  llvm_cbe_tmp__82 = (unsigned int )llvm_cbe_tmp__81 ^ llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = call i32 @bch_decode(i32 %%82, i32 %%84) nounwind, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_546_count);
  llvm_cbe_tmp__83 = (unsigned int )bch_decode(llvm_cbe_tmp__80, llvm_cbe_tmp__82);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__80);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__82);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__83);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = getelementptr inbounds i8* %%pdata, i64 428, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_577_count);
  llvm_cbe_tmp__84 = ( char *)(&llvm_cbe_pdata[(((signed long long )428ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%87 = load i8* %%86, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_578_count);
  llvm_cbe_tmp__85 = (unsigned char )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = zext i8 %%87 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_579_count);
  llvm_cbe_tmp__86 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__85&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = shl nuw nsw i32 %%88, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_601_count);
  llvm_cbe_tmp__87 = (unsigned int )llvm_cbe_tmp__86 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__87);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = getelementptr inbounds i8* %%pdata, i64 407, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_602_count);
  llvm_cbe_tmp__88 = ( char *)(&llvm_cbe_pdata[(((signed long long )407ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = load i8* %%90, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_603_count);
  llvm_cbe_tmp__89 = (unsigned char )*llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = zext i8 %%91 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_604_count);
  llvm_cbe_tmp__90 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__89&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = add nsw i32 %%92, %%89, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_605_count);
  llvm_cbe_tmp__91 = (unsigned int )((unsigned int )(llvm_cbe_tmp__90&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__87&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__91&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = shl nuw nsw i32 %%93, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_627_count);
  llvm_cbe_tmp__92 = (unsigned int )llvm_cbe_tmp__91 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE)
printf("\n  %%95 = getelementptr inbounds i8* %%pdata, i64 386, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_628_count);
  llvm_cbe_tmp__93 = ( char *)(&llvm_cbe_pdata[(((signed long long )386ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%96 = load i8* %%95, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_629_count);
  llvm_cbe_tmp__94 = (unsigned char )*llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = zext i8 %%96 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_630_count);
  llvm_cbe_tmp__95 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__94&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%98 = add nsw i32 %%97, %%94, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_631_count);
  llvm_cbe_tmp__96 = (unsigned int )((unsigned int )(llvm_cbe_tmp__95&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__92&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__96&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = shl nsw i32 %%98, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_653_count);
  llvm_cbe_tmp__97 = (unsigned int )llvm_cbe_tmp__96 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%100 = getelementptr inbounds i8* %%pdata, i64 365, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_654_count);
  llvm_cbe_tmp__98 = ( char *)(&llvm_cbe_pdata[(((signed long long )365ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%101 = load i8* %%100, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_655_count);
  llvm_cbe_tmp__99 = (unsigned char )*llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = zext i8 %%101 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_656_count);
  llvm_cbe_tmp__100 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__99&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%103 = add nsw i32 %%102, %%99, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_657_count);
  llvm_cbe_tmp__101 = (unsigned int )((unsigned int )(llvm_cbe_tmp__100&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__97&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__101&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = shl i32 %%103, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_679_count);
  llvm_cbe_tmp__102 = (unsigned int )llvm_cbe_tmp__101 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%105 = getelementptr inbounds i8* %%pdata, i64 344, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_680_count);
  llvm_cbe_tmp__103 = ( char *)(&llvm_cbe_pdata[(((signed long long )344ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = load i8* %%105, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_681_count);
  llvm_cbe_tmp__104 = (unsigned char )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%107 = zext i8 %%106 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_682_count);
  llvm_cbe_tmp__105 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__104&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = add nsw i32 %%107, %%104, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_683_count);
  llvm_cbe_tmp__106 = (unsigned int )((unsigned int )(llvm_cbe_tmp__105&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__102&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__106&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = shl i32 %%108, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_705_count);
  llvm_cbe_tmp__107 = (unsigned int )llvm_cbe_tmp__106 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%110 = getelementptr inbounds i8* %%pdata, i64 323, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_706_count);
  llvm_cbe_tmp__108 = ( char *)(&llvm_cbe_pdata[(((signed long long )323ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = load i8* %%110, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_707_count);
  llvm_cbe_tmp__109 = (unsigned char )*llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%112 = zext i8 %%111 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_708_count);
  llvm_cbe_tmp__110 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__109&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%113 = add nsw i32 %%112, %%109, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_709_count);
  llvm_cbe_tmp__111 = (unsigned int )((unsigned int )(llvm_cbe_tmp__110&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__107&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__111&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%114 = shl i32 %%113, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_731_count);
  llvm_cbe_tmp__112 = (unsigned int )llvm_cbe_tmp__111 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%115 = getelementptr inbounds i8* %%pdata, i64 302, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_732_count);
  llvm_cbe_tmp__113 = ( char *)(&llvm_cbe_pdata[(((signed long long )302ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%116 = load i8* %%115, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_733_count);
  llvm_cbe_tmp__114 = (unsigned char )*llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%117 = zext i8 %%116 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_734_count);
  llvm_cbe_tmp__115 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__114&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%118 = add nsw i32 %%117, %%114, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_735_count);
  llvm_cbe_tmp__116 = (unsigned int )((unsigned int )(llvm_cbe_tmp__115&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__112&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__116&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%119 = shl i32 %%118, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_773_count);
  llvm_cbe_tmp__117 = (unsigned int )llvm_cbe_tmp__116 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__117);
if (AESL_DEBUG_TRACE)
printf("\n  %%120 = getelementptr inbounds i8* %%pdata, i64 181, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_774_count);
  llvm_cbe_tmp__118 = ( char *)(&llvm_cbe_pdata[(((signed long long )181ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%121 = load i8* %%120, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_775_count);
  llvm_cbe_tmp__119 = (unsigned char )*llvm_cbe_tmp__118;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%122 = zext i8 %%121 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_776_count);
  llvm_cbe_tmp__120 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__119&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%123 = add nsw i32 %%122, %%119, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_777_count);
  llvm_cbe_tmp__121 = (unsigned int )((unsigned int )(llvm_cbe_tmp__120&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__117&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__121&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%124 = shl i32 %%123, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_799_count);
  llvm_cbe_tmp__122 = (unsigned int )llvm_cbe_tmp__121 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__122);
if (AESL_DEBUG_TRACE)
printf("\n  %%125 = getelementptr inbounds i8* %%pdata, i64 182, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_800_count);
  llvm_cbe_tmp__123 = ( char *)(&llvm_cbe_pdata[(((signed long long )182ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%126 = load i8* %%125, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_801_count);
  llvm_cbe_tmp__124 = (unsigned char )*llvm_cbe_tmp__123;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%127 = zext i8 %%126 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_802_count);
  llvm_cbe_tmp__125 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__124&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__125);
if (AESL_DEBUG_TRACE)
printf("\n  %%128 = add nsw i32 %%127, %%124, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_803_count);
  llvm_cbe_tmp__126 = (unsigned int )((unsigned int )(llvm_cbe_tmp__125&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__122&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__126&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%129 = shl i32 %%128, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_825_count);
  llvm_cbe_tmp__127 = (unsigned int )llvm_cbe_tmp__126 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%130 = getelementptr inbounds i8* %%pdata, i64 183, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_826_count);
  llvm_cbe_tmp__128 = ( char *)(&llvm_cbe_pdata[(((signed long long )183ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%131 = load i8* %%130, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_827_count);
  llvm_cbe_tmp__129 = (unsigned char )*llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__129);
if (AESL_DEBUG_TRACE)
printf("\n  %%132 = zext i8 %%131 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_828_count);
  llvm_cbe_tmp__130 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__129&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE)
printf("\n  %%133 = add nsw i32 %%132, %%129, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_829_count);
  llvm_cbe_tmp__131 = (unsigned int )((unsigned int )(llvm_cbe_tmp__130&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__127&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__131&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%134 = shl i32 %%133, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_851_count);
  llvm_cbe_tmp__132 = (unsigned int )llvm_cbe_tmp__131 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%135 = getelementptr inbounds i8* %%pdata, i64 184, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_852_count);
  llvm_cbe_tmp__133 = ( char *)(&llvm_cbe_pdata[(((signed long long )184ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%136 = load i8* %%135, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_853_count);
  llvm_cbe_tmp__134 = (unsigned char )*llvm_cbe_tmp__133;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__134);
if (AESL_DEBUG_TRACE)
printf("\n  %%137 = zext i8 %%136 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_854_count);
  llvm_cbe_tmp__135 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__134&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%138 = add nsw i32 %%137, %%134, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_855_count);
  llvm_cbe_tmp__136 = (unsigned int )((unsigned int )(llvm_cbe_tmp__135&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__132&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__136&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%139 = shl i32 %%138, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_877_count);
  llvm_cbe_tmp__137 = (unsigned int )llvm_cbe_tmp__136 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__137);
if (AESL_DEBUG_TRACE)
printf("\n  %%140 = getelementptr inbounds i8* %%pdata, i64 185, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_878_count);
  llvm_cbe_tmp__138 = ( char *)(&llvm_cbe_pdata[(((signed long long )185ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%141 = load i8* %%140, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_879_count);
  llvm_cbe_tmp__139 = (unsigned char )*llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%142 = zext i8 %%141 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_880_count);
  llvm_cbe_tmp__140 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__139&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%143 = add nsw i32 %%142, %%139, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_881_count);
  llvm_cbe_tmp__141 = (unsigned int )((unsigned int )(llvm_cbe_tmp__140&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__137&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__141&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%144 = shl i32 %%143, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_903_count);
  llvm_cbe_tmp__142 = (unsigned int )llvm_cbe_tmp__141 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%145 = getelementptr inbounds i8* %%pdata, i64 186, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_904_count);
  llvm_cbe_tmp__143 = ( char *)(&llvm_cbe_pdata[(((signed long long )186ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%146 = load i8* %%145, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_905_count);
  llvm_cbe_tmp__144 = (unsigned char )*llvm_cbe_tmp__143;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__144);
if (AESL_DEBUG_TRACE)
printf("\n  %%147 = zext i8 %%146 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_906_count);
  llvm_cbe_tmp__145 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__144&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%148 = add nsw i32 %%147, %%144, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_907_count);
  llvm_cbe_tmp__146 = (unsigned int )((unsigned int )(llvm_cbe_tmp__145&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__142&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__146&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%149 = shl i32 %%148, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_929_count);
  llvm_cbe_tmp__147 = (unsigned int )llvm_cbe_tmp__146 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%150 = getelementptr inbounds i8* %%pdata, i64 187, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_930_count);
  llvm_cbe_tmp__148 = ( char *)(&llvm_cbe_pdata[(((signed long long )187ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%151 = load i8* %%150, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_931_count);
  llvm_cbe_tmp__149 = (unsigned char )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%152 = zext i8 %%151 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_932_count);
  llvm_cbe_tmp__150 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__149&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__150);
if (AESL_DEBUG_TRACE)
printf("\n  %%153 = add nsw i32 %%152, %%149, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_933_count);
  llvm_cbe_tmp__151 = (unsigned int )((unsigned int )(llvm_cbe_tmp__150&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__147&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__151&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%154 = shl i32 %%153, 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_955_count);
  llvm_cbe_tmp__152 = (unsigned int )llvm_cbe_tmp__151 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__152);
if (AESL_DEBUG_TRACE)
printf("\n  %%155 = getelementptr inbounds i8* %%pdata, i64 188, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_956_count);
  llvm_cbe_tmp__153 = ( char *)(&llvm_cbe_pdata[(((signed long long )188ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%156 = load i8* %%155, align 1, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_957_count);
  llvm_cbe_tmp__154 = (unsigned char )*llvm_cbe_tmp__153;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__154);
if (AESL_DEBUG_TRACE)
printf("\n  %%157 = zext i8 %%156 to i32, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_958_count);
  llvm_cbe_tmp__155 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__154&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__155);
if (AESL_DEBUG_TRACE)
printf("\n  %%158 = add nsw i32 %%157, %%154, !dbg !7 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_959_count);
  llvm_cbe_tmp__156 = (unsigned int )((unsigned int )(llvm_cbe_tmp__155&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__152&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__156&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%159 = xor i32 %%83, %%158, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_981_count);
  llvm_cbe_tmp__157 = (unsigned int )llvm_cbe_tmp__81 ^ llvm_cbe_tmp__156;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE)
printf("\n  %%160 = call i32 @bch_decode(i32 %%82, i32 %%159) nounwind, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_982_count);
  bch_decode(llvm_cbe_tmp__80, llvm_cbe_tmp__157);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__80);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__157);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__158);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%161 = and i32 %%85, 7, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_987_count);
  llvm_cbe_tmp__159 = (unsigned int )llvm_cbe_tmp__83 & 7u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%162 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 4, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_988_count);
  llvm_cbe_tmp__160 = (signed int *)(&llvm_cbe_scanner.field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%161, i32* %%162, align 8, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_989_count);
  *llvm_cbe_tmp__160 = llvm_cbe_tmp__159;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__159);
if (AESL_DEBUG_TRACE)
printf("\n  %%163 = ashr i32 %%85, 3, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_990_count);
  llvm_cbe_tmp__161 = (unsigned int )((signed int )(((signed int )llvm_cbe_tmp__83) >> ((signed int )3u)));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((signed int )llvm_cbe_tmp__161));
if (AESL_DEBUG_TRACE)
printf("\n  %%164 = sext i32 %%163 to i64, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_991_count);
  llvm_cbe_tmp__162 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__161);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__162);
if (AESL_DEBUG_TRACE)
printf("\n  %%165 = getelementptr inbounds [4 x i8]* @code_to_ecl, i64 0, i64 %%164, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_992_count);
  llvm_cbe_tmp__163 = ( char *)(&code_to_ecl[(((signed long long )llvm_cbe_tmp__162))
#ifdef AESL_BC_SIM
 % 4
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__162));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__162) < 4)) fprintf(stderr, "%s:%d: warning: Read access out of array 'code_to_ecl' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%166 = load i8* %%165, align 1, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_993_count);
  llvm_cbe_tmp__164 = (unsigned char )*llvm_cbe_tmp__163;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__164);
if (AESL_DEBUG_TRACE)
printf("\n  %%167 = zext i8 %%166 to i32, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_994_count);
  llvm_cbe_tmp__165 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__164&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__165);
if (AESL_DEBUG_TRACE)
printf("\n  %%168 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 3, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_995_count);
  llvm_cbe_tmp__166 = (signed int *)(&llvm_cbe_scanner.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%167, i32* %%168, align 4, !dbg !15 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_996_count);
  *llvm_cbe_tmp__166 = llvm_cbe_tmp__165;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__165);
if (AESL_DEBUG_TRACE)
printf("\n  %%169 = getelementptr inbounds %%struct.scanner* %%scanner, i64 0, i32 7, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_997_count);
  llvm_cbe_tmp__167 = (signed long long *)(&llvm_cbe_scanner.field7);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 0, i64* %%169, align 8, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_998_count);
  *llvm_cbe_tmp__167 = 0ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 0ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%170 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 4) nounwind, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_999_count);
  llvm_cbe_tmp__168 = (unsigned int )get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__168);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%171 = trunc i32 %%170 to i8, !dbg !16 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1000_count);
  llvm_cbe_tmp__169 = (unsigned char )((unsigned char )llvm_cbe_tmp__168&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%172 = load i8* getelementptr inbounds ([41 x i8]* @version_range, i64 0, i64 1), align 1, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1006_count);
  llvm_cbe_tmp__170 = (unsigned char )*((&version_range[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 41
#endif
]));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__170);
if (AESL_DEBUG_TRACE)
printf("\n  %%173 = zext i8 %%172 to i64, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1007_count);
  llvm_cbe_tmp__171 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__170&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%174 = zext i8 %%171 to i64, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1008_count);
  llvm_cbe_tmp__172 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__169&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__172);
if (AESL_DEBUG_TRACE)
printf("\n  %%175 = getelementptr inbounds [5 x [3 x i8]]* @lenbits, i64 0, i64 %%174, i64 %%173, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1009_count);
  llvm_cbe_tmp__173 = ( char *)(&lenbits[(((signed long long )llvm_cbe_tmp__172))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__171))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__172));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__171));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__172) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'lenbits' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__171) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'lenbits' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%176 = load i8* %%175, align 1, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1010_count);
  llvm_cbe_tmp__174 = (unsigned char )*llvm_cbe_tmp__173;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__174);
if (AESL_DEBUG_TRACE)
printf("\n  %%177 = zext i8 %%176 to i64, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1011_count);
  llvm_cbe_tmp__175 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__174&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE)
printf("\n  %%178 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 %%177) nounwind, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1012_count);
  llvm_cbe_tmp__176 = (unsigned int )get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), llvm_cbe_tmp__175);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__175);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__176);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%179 = zext i32 %%178 to i64, !dbg !14 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1013_count);
  llvm_cbe_tmp__177 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__176&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__177);
  if (((llvm_cbe_tmp__169&255U) == (((unsigned char )1)&255U))) {
    goto llvm_cbe__2e_preheader10;
  } else {
    goto llvm_cbe_tmp__191;
  }

llvm_cbe__2e_preheader10:
  if ((((unsigned int )llvm_cbe_tmp__176&4294967295U) > ((unsigned int )2u&4294967295U))) {
    llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__177;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  } else {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__177;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge13;
  }

  do {     /* Syntactic loop '.lr.ph12' to make GCC happy */
llvm_cbe__2e_lr_2e_ph12:
if (AESL_DEBUG_TRACE)
printf("\n  %%182 = phi i64 [ %%184, %%.lr.ph12 ], [ %%179, %%.preheader10  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1027_count);
  llvm_cbe_tmp__178 = (unsigned long long )llvm_cbe_tmp__178__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__178);
printf("\n = 0x%I64X",llvm_cbe_tmp__180);
printf("\n = 0x%I64X",llvm_cbe_tmp__177);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%183 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 10) nounwind, !dbg !18 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1028_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 10ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",10ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__179);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%184 = add i64 %%182, -3, !dbg !17 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1033_count);
  llvm_cbe_tmp__180 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__178&18446744073709551615ull)) + ((unsigned long long )(18446744073709551613ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__180&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__180&18446744073709551615ULL) > ((unsigned long long )2ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__178__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__180;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph12;
  } else {
    llvm_cbe__2e_lcssa11__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__180;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge13;
  }

  } while (1); /* end of syntactic loop '.lr.ph12' */
llvm_cbe__2e__crit_edge13:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa11 = phi i64 [ %%179, %%.preheader10 ], [ %%184, %%.lr.ph12  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe__2e_lcssa11_count);
  llvm_cbe__2e_lcssa11 = (unsigned long long )llvm_cbe__2e_lcssa11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa11 = 0x%I64X",llvm_cbe__2e_lcssa11);
printf("\n = 0x%I64X",llvm_cbe_tmp__177);
printf("\n = 0x%I64X",llvm_cbe_tmp__180);
}
  if (((llvm_cbe__2e_lcssa11&18446744073709551615ULL) == (2ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__192;
  } else {
    goto llvm_cbe_tmp__193;
  }

llvm_cbe_tmp__192:
if (AESL_DEBUG_TRACE)
printf("\n  %%188 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 7) nounwind, !dbg !18 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1047_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 7ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",7ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__181);
}
  goto llvm_cbe_tmp__194;

llvm_cbe_tmp__193:
  if (((llvm_cbe__2e_lcssa11&18446744073709551615ULL) == (1ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__195;
  } else {
    goto llvm_cbe_tmp__196;
  }

llvm_cbe_tmp__195:
if (AESL_DEBUG_TRACE)
printf("\n  %%192 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 4) nounwind, !dbg !19 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1054_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 4ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",4ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__182);
}
  goto llvm_cbe_tmp__196;

llvm_cbe_tmp__196:
  goto llvm_cbe_tmp__194;

llvm_cbe_tmp__194:
  goto llvm_cbe_tmp__197;

llvm_cbe_tmp__191:
  if (((llvm_cbe_tmp__169&255U) == (((unsigned char )2)&255U))) {
    goto llvm_cbe__2e_preheader8;
  } else {
    goto llvm_cbe_tmp__198;
  }

llvm_cbe__2e_preheader8:
  if ((((unsigned int )llvm_cbe_tmp__176&4294967295U) > ((unsigned int )1u&4294967295U))) {
    llvm_cbe_tmp__183__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__177;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__177;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph9' to make GCC happy */
llvm_cbe__2e_lr_2e_ph9:
if (AESL_DEBUG_TRACE)
printf("\n  %%198 = phi i64 [ %%200, %%.lr.ph9 ], [ %%179, %%.preheader8  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1064_count);
  llvm_cbe_tmp__183 = (unsigned long long )llvm_cbe_tmp__183__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__183);
printf("\n = 0x%I64X",llvm_cbe_tmp__185);
printf("\n = 0x%I64X",llvm_cbe_tmp__177);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%199 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 11) nounwind, !dbg !19 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1065_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 11ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",11ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__184);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%200 = add i64 %%198, -2, !dbg !17 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1069_count);
  llvm_cbe_tmp__185 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__183&18446744073709551615ull)) + ((unsigned long long )(18446744073709551614ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__185&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__185&18446744073709551615ULL) > ((unsigned long long )1ull&18446744073709551615ULL))) {
    llvm_cbe_tmp__183__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__185;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph9;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__185;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph9' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ %%179, %%.preheader8 ], [ %%200, %%.lr.ph9  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",llvm_cbe_tmp__177);
printf("\n = 0x%I64X",llvm_cbe_tmp__185);
}
  if (((llvm_cbe__2e_lcssa&18446744073709551615ULL) == (1ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__199;
  } else {
    goto llvm_cbe_tmp__200;
  }

llvm_cbe_tmp__199:
if (AESL_DEBUG_TRACE)
printf("\n  %%204 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 6) nounwind, !dbg !20 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1083_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 6ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",6ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__186);
}
  goto llvm_cbe_tmp__200;

llvm_cbe_tmp__200:
  goto llvm_cbe_tmp__201;

llvm_cbe_tmp__198:
  if (((llvm_cbe_tmp__169&255U) == (((unsigned char )4)&255U))) {
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__202;
  }

llvm_cbe__2e_preheader:
  if (((llvm_cbe_tmp__176&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge57__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge57 = phi i64 [ %%210, %%.lr.ph ], [ 0, %%.preheader  for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_storemerge57_count);
  llvm_cbe_storemerge57 = (unsigned long long )llvm_cbe_storemerge57__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge57 = 0x%I64X",llvm_cbe_storemerge57);
printf("\n = 0x%I64X",llvm_cbe_tmp__188);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%209 = call i32 @get_bits(%%struct.scanner* %%scanner, i64 8) nounwind, !dbg !20 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1094_count);
  get_bits((l_struct_OC_scanner *)(&llvm_cbe_scanner), 8ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",8ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__187);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%210 = add i64 %%storemerge57, 1, !dbg !20 for 0x%I64xth hint within @qrc_decoder  --> \n", ++aesl_llvm_cbe_1096_count);
  llvm_cbe_tmp__188 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge57&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__188&18446744073709551615ull)));
  if (((llvm_cbe_tmp__188&18446744073709551615ULL) == (llvm_cbe_tmp__177&18446744073709551615ULL))) {
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge57__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__188;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__202;

llvm_cbe_tmp__202:
  goto llvm_cbe_tmp__201;

llvm_cbe_tmp__201:
  goto llvm_cbe_tmp__197;

llvm_cbe_tmp__197:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @qrc_decoder}\n");
  return;
}

