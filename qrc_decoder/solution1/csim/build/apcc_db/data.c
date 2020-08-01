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

/* External Global Variable Declarations */
extern  char pattern_finder[7][7];
extern  char pattern_alignment[5][5];
extern  char *charset_alpha;
extern  char version_range[41];
extern  char code_to_ecl[4];
extern  char ecl_to_code[4];
extern  char lenbits[5][3];
extern unsigned int bch_format_gen;
extern unsigned int bch_format_mask;
extern unsigned int bch_version_gen;
extern unsigned int bch_version_mask;
extern  char pattern_alignment_pos[41][8];
extern  char block_sizes[164][6];

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[46] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
 char pattern_alignment[5][5] = { { ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )1), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1) } };
 char pattern_finder[7][7] = { { ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )1) }, { ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1) } };
 char code_to_ecl[4] = { ((unsigned char )1), ((unsigned char )0), ((unsigned char )3), ((unsigned char )2) };
 char ecl_to_code[4] = { ((unsigned char )1), ((unsigned char )0), ((unsigned char )3), ((unsigned char )2) };
 char lenbits[5][3] = { { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )10), ((unsigned char )12), ((unsigned char )14) }, { ((unsigned char )9), ((unsigned char )11), ((unsigned char )13) }, { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )8), ((unsigned char )16), ((unsigned char )16) } };
 char *charset_alpha = ((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 46
#endif
]));
 char version_range[41] = { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )1), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2), ((unsigned char )2) };
unsigned int bch_version_gen = 7973u;
unsigned int bch_format_gen = 1335u;
unsigned int bch_format_mask = 21522u;
unsigned int bch_version_mask;
 char pattern_alignment_pos[41][8] = { { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, "\x06\x12\x00\x00\x00\x00\x00", "\x06\x16\x00\x00\x00\x00\x00", "\x06\x1A\x00\x00\x00\x00\x00", "\x06\x1E\x00\x00\x00\x00\x00", "\x06\"\x00\x00\x00\x00\x00", "\x06\x16&\x00\x00\x00\x00", "\x06\x18*\x00\x00\x00\x00", "\x06\x1A.\x00\x00\x00\x00", "\x06\x1C\x32\x00\x00\x00\x00", "\x06\x1E\x36\x00\x00\x00\x00", "\x06 :\x00\x00\x00\x00", "\x06\">\x00\x00\x00\x00", "\x06\x1A.B\x00\x00\x00", "\x06\x1A\x30\x46\x00\x00\x00", "\x06\x1A\x32J\x00\x00\x00", "\x06\x1E\x36N\x00\x00\x00", "\x06\x1E\x38R\x00\x00\x00", "\x06\x1E:V\x00\x00\x00", "\x06\"RZ\x00\x00\x00", "\x06\x1C\x32H^\x00\x00", "\x06\x1A\x32Jb\x00\x00", "\x06\x1E\x36Nf\x00\x00", "\x06\x1C\x36Pj\x00\x00", "\x06 :Tn\x00\x00", "\x06\x1E:Vr\x00\x00", "\x06\">Zv\x00\x00", "\x06\x1A\x32Jbz\x00", "\x06\x1E\x36Nf~\x00", "\x06\x1A\x34Nh\x82\x00", "\x06\x1E\x38Rl\x86\x00", "\x06\"<Vp\x8A\x00", "\x06\x1E:Vr\x8E\x00", "\x06\">Zv\x92\x00", "\x06\x1E\x36Nf~\x96", "\x06\x18\x32Lf\x80\x9A", "\x06\x1C\x36Pj\x84\x9E", "\x06 :Tn\x88\xA2", "\x06\x1A\x36Rn\x8A\xA6", "\x06\x1E:Vr\x8E\xAA" };
 char block_sizes[164][6] = { { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, { ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0), ((unsigned char )0) }, "\x01\x1A\x13\x00\x00", "\x01\x1A\x10\x00\x00", "\x01\x1A\r\x00\x00", "\x01\x1A\t\x00\x00", "\x01,\"\x00\x00", "\x01,\x1C\x00\x00", "\x01,\x16\x00\x00", "\x01,\x10\x00\x00", "\x01\x46\x37\x00\x00", "\x01\x46,\x00\x00", "\x02#\x11\x00\x00", "\x02#\r\x00\x00", "\x01\x64P\x00\x00", "\x02\x32 \x00\x00", "\x02\x32\x18\x00\x00", "\x04\x19\t\x00\x00", "\x01\x86l\x00\x00", "\x02\x43+\x00\x00", { ((unsigned char )2), ((unsigned char )33), ((unsigned char )15), ((unsigned char )2), ((unsigned char )33), ((unsigned char )16) }, { ((unsigned char )2), ((unsigned char )33), ((unsigned char )11), ((unsigned char )2), ((unsigned char )34), ((unsigned char )12) }, "\x02VD\x00\x00", "\x04+\x1B\x00\x00", "\x04+\x13\x00\x00", "\x04+\x0F\x00\x00", "\x02\x62N\x00\x00", "\x04\x31)\x00\x00", { ((unsigned char )2), ((unsigned char )32), ((unsigned char )14), ((unsigned char )4), ((unsigned char )33), ((unsigned char )15) }, { ((unsigned char )4), ((unsigned char )39), ((unsigned char )13), ((unsigned char )1), ((unsigned char )40), ((unsigned char )14) }, "\x02ya\x00\x00", { ((unsigned char )2), ((unsigned char )60), ((unsigned char )38), ((unsigned char )2), ((unsigned char )61), ((unsigned char )39) }, { ((unsigned char )4), ((unsigned char )40), ((unsigned char )18), ((unsigned char )2), ((unsigned char )41), ((unsigned char )19) }, { ((unsigned char )4), ((unsigned char )40), ((unsigned char )14), ((unsigned char )2), ((unsigned char )41), ((unsigned char )15) }, "\x02\x92t\x00\x00", { ((unsigned char )3), ((unsigned char )58), ((unsigned char )36), ((unsigned char )2), ((unsigned char )59), ((unsigned char )37) }, { ((unsigned char )4), ((unsigned char )36), ((unsigned char )16), ((unsigned char )4), ((unsigned char )37), ((unsigned char )17) }, { ((unsigned char )4), ((unsigned char )36), ((unsigned char )12), ((unsigned char )4), ((unsigned char )37), ((unsigned char )13) }, { ((unsigned char )2), ((unsigned char )86), ((unsigned char )68), ((unsigned char )2), ((unsigned char )87), ((unsigned char )69) }, { ((unsigned char )4), ((unsigned char )69), ((unsigned char )43), ((unsigned char )1), ((unsigned char )70), ((unsigned char )44) }, { ((unsigned char )6), ((unsigned char )43), ((unsigned char )19), ((unsigned char )2), ((unsigned char )44), ((unsigned char )20) }, { ((unsigned char )6), ((unsigned char )43), ((unsigned char )15), ((unsigned char )2), ((unsigned char )44), ((unsigned char )16) }, "\x04\x65Q\x00\x00", { ((unsigned char )1), ((unsigned char )80), ((unsigned char )50), ((unsigned char )4), ((unsigned char )81), ((unsigned char )51) }, { ((unsigned char )4), ((unsigned char )50), ((unsigned char )22), ((unsigned char )4), ((unsigned char )51), ((unsigned char )23) }, { ((unsigned char )3), ((unsigned char )36), ((unsigned char )12), ((unsigned char )8), ((unsigned char )37), ((unsigned char )13) }, { ((unsigned char )2), ((unsigned char )116), ((unsigned char )92), ((unsigned char )2), ((unsigned char )117), ((unsigned char )93) }, { ((unsigned char )6), ((unsigned char )58), ((unsigned char )36), ((unsigned char )2), ((unsigned char )59), ((unsigned char )37) }, { ((unsigned char )4), ((unsigned char )46), ((unsigned char )20), ((unsigned char )6), ((unsigned char )47), ((unsigned char )21) }, { ((unsigned char )7), ((unsigned char )42), ((unsigned char )14), ((unsigned char )4), ((unsigned char )43), ((unsigned char )15) }, "\x04\x85k\x00\x00", { ((unsigned char )8), ((unsigned char )59), ((unsigned char )37), ((unsigned char )1), ((unsigned char )60), ((unsigned char )38) }, { ((unsigned char )8), ((unsigned char )44), ((unsigned char )20), ((unsigned char )4), ((unsigned char )45), ((unsigned char )21) }, { ((unsigned char )12), ((unsigned char )33), ((unsigned char )11), ((unsigned char )4), ((unsigned char )34), ((unsigned char )12) }, { ((unsigned char )3), ((unsigned char )-111), ((unsigned char )115), ((unsigned char )1), ((unsigned char )-110), ((unsigned char )116) }, { ((unsigned char )4), ((unsigned char )64), ((unsigned char )40), ((unsigned char )5), ((unsigned char )65), ((unsigned char )41) }, { ((unsigned char )11), ((unsigned char )36), ((unsigned char )16), ((unsigned char )5), ((unsigned char )37), ((unsigned char )17) }, { ((unsigned char )11), ((unsigned char )36), ((unsigned char )12), ((unsigned char )5), ((unsigned char )37), ((unsigned char )13) }, { ((unsigned char )5), ((unsigned char )109), ((unsigned char )87), ((unsigned char )1), ((unsigned char )110), ((unsigned char )88) }, { ((unsigned char )5), ((unsigned char )65), ((unsigned char )41), ((unsigned char )5), ((unsigned char )66), ((unsigned char )42) }, { ((unsigned char )5), ((unsigned char )54), ((unsigned char )24), ((unsigned char )7), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )11), ((unsigned char )36), ((unsigned char )12), ((unsigned char )7), ((unsigned char )37), ((unsigned char )13) }, { ((unsigned char )5), ((unsigned char )122), ((unsigned char )98), ((unsigned char )1), ((unsigned char )123), ((unsigned char )99) }, { ((unsigned char )7), ((unsigned char )73), ((unsigned char )45), ((unsigned char )3), ((unsigned char )74), ((unsigned char )46) }, { ((unsigned char )15), ((unsigned char )43), ((unsigned char )19), ((unsigned char )2), ((unsigned char )44), ((unsigned char )20) }, { ((unsigned char )3), ((unsigned char )45), ((unsigned char )15), ((unsigned char )13), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )1), ((unsigned char )-121), ((unsigned char )107), ((unsigned char )5), ((unsigned char )-120), ((unsigned char )108) }, { ((unsigned char )10), ((unsigned char )74), ((unsigned char )46), ((unsigned char )1), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )1), ((unsigned char )50), ((unsigned char )22), ((unsigned char )15), ((unsigned char )51), ((unsigned char )23) }, { ((unsigned char )2), ((unsigned char )42), ((unsigned char )14), ((unsigned char )17), ((unsigned char )43), ((unsigned char )15) }, { ((unsigned char )5), ((unsigned char )-106), ((unsigned char )120), ((unsigned char )1), ((unsigned char )-105), ((unsigned char )121) }, { ((unsigned char )9), ((unsigned char )69), ((unsigned char )43), ((unsigned char )4), ((unsigned char )70), ((unsigned char )44) }, { ((unsigned char )17), ((unsigned char )50), ((unsigned char )22), ((unsigned char )1), ((unsigned char )51), ((unsigned char )23) }, { ((unsigned char )2), ((unsigned char )42), ((unsigned char )14), ((unsigned char )19), ((unsigned char )43), ((unsigned char )15) }, { ((unsigned char )3), ((unsigned char )-115), ((unsigned char )113), ((unsigned char )4), ((unsigned char )-114), ((unsigned char )114) }, { ((unsigned char )3), ((unsigned char )70), ((unsigned char )44), ((unsigned char )11), ((unsigned char )71), ((unsigned char )45) }, { ((unsigned char )17), ((unsigned char )47), ((unsigned char )21), ((unsigned char )4), ((unsigned char )48), ((unsigned char )22) }, { ((unsigned char )9), ((unsigned char )39), ((unsigned char )13), ((unsigned char )16), ((unsigned char )40), ((unsigned char )14) }, { ((unsigned char )3), ((unsigned char )-121), ((unsigned char )107), ((unsigned char )5), ((unsigned char )-120), ((unsigned char )108) }, { ((unsigned char )3), ((unsigned char )67), ((unsigned char )41), ((unsigned char )13), ((unsigned char )68), ((unsigned char )42) }, { ((unsigned char )15), ((unsigned char )54), ((unsigned char )24), ((unsigned char )5), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )15), ((unsigned char )43), ((unsigned char )15), ((unsigned char )10), ((unsigned char )44), ((unsigned char )15) }, { ((unsigned char )4), ((unsigned char )-112), ((unsigned char )116), ((unsigned char )4), ((unsigned char )-111), ((unsigned char )117) }, "\x11\x44*\x00\x00", { ((unsigned char )17), ((unsigned char )50), ((unsigned char )22), ((unsigned char )6), ((unsigned char )51), ((unsigned char )23) }, { ((unsigned char )19), ((unsigned char )46), ((unsigned char )16), ((unsigned char )6), ((unsigned char )47), ((unsigned char )17) }, { ((unsigned char )2), ((unsigned char )-117), ((unsigned char )111), ((unsigned char )7), ((unsigned char )-116), ((unsigned char )112) }, "\x11J.\x00\x00", { ((unsigned char )7), ((unsigned char )54), ((unsigned char )24), ((unsigned char )16), ((unsigned char )55), ((unsigned char )25) }, "\"%\r\x00\x00", { ((unsigned char )4), ((unsigned char )-105), ((unsigned char )121), ((unsigned char )5), ((unsigned char )-104), ((unsigned char )122) }, { ((unsigned char )4), ((unsigned char )75), ((unsigned char )47), ((unsigned char )14), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )11), ((unsigned char )54), ((unsigned char )24), ((unsigned char )14), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )16), ((unsigned char )45), ((unsigned char )15), ((unsigned char )14), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )6), ((unsigned char )-109), ((unsigned char )117), ((unsigned char )4), ((unsigned char )-108), ((unsigned char )118) }, { ((unsigned char )6), ((unsigned char )73), ((unsigned char )45), ((unsigned char )14), ((unsigned char )74), ((unsigned char )46) }, { ((unsigned char )11), ((unsigned char )54), ((unsigned char )24), ((unsigned char )16), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )30), ((unsigned char )46), ((unsigned char )16), ((unsigned char )2), ((unsigned char )47), ((unsigned char )17) }, { ((unsigned char )8), ((unsigned char )-124), ((unsigned char )106), ((unsigned char )4), ((unsigned char )-123), ((unsigned char )107) }, { ((unsigned char )8), ((unsigned char )64), ((unsigned char )47), ((unsigned char )13), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )7), ((unsigned char )54), ((unsigned char )24), ((unsigned char )22), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )22), ((unsigned char )45), ((unsigned char )15), ((unsigned char )13), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )10), ((unsigned char )-114), ((unsigned char )114), ((unsigned char )2), ((unsigned char )-113), ((unsigned char )115) }, { ((unsigned char )19), ((unsigned char )74), ((unsigned char )46), ((unsigned char )4), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )28), ((unsigned char )50), ((unsigned char )22), ((unsigned char )6), ((unsigned char )51), ((unsigned char )23) }, { ((unsigned char )33), ((unsigned char )46), ((unsigned char )16), ((unsigned char )4), ((unsigned char )47), ((unsigned char )17) }, { ((unsigned char )8), ((unsigned char )-104), ((unsigned char )122), ((unsigned char )4), ((unsigned char )-103), ((unsigned char )123) }, { ((unsigned char )22), ((unsigned char )73), ((unsigned char )45), ((unsigned char )3), ((unsigned char )74), ((unsigned char )46) }, { ((unsigned char )8), ((unsigned char )53), ((unsigned char )23), ((unsigned char )26), ((unsigned char )54), ((unsigned char )24) }, { ((unsigned char )12), ((unsigned char )45), ((unsigned char )15), ((unsigned char )28), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )3), ((unsigned char )-109), ((unsigned char )117), ((unsigned char )10), ((unsigned char )-108), ((unsigned char )118) }, { ((unsigned char )3), ((unsigned char )73), ((unsigned char )45), ((unsigned char )23), ((unsigned char )74), ((unsigned char )46) }, { ((unsigned char )4), ((unsigned char )54), ((unsigned char )24), ((unsigned char )31), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )11), ((unsigned char )45), ((unsigned char )15), ((unsigned char )31), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )7), ((unsigned char )-110), ((unsigned char )116), ((unsigned char )7), ((unsigned char )-109), ((unsigned char )117) }, { ((unsigned char )21), ((unsigned char )73), ((unsigned char )45), ((unsigned char )7), ((unsigned char )74), ((unsigned char )46) }, { ((unsigned char )1), ((unsigned char )53), ((unsigned char )23), ((unsigned char )37), ((unsigned char )54), ((unsigned char )24) }, { ((unsigned char )19), ((unsigned char )45), ((unsigned char )15), ((unsigned char )26), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )5), ((unsigned char )-111), ((unsigned char )115), ((unsigned char )10), ((unsigned char )-110), ((unsigned char )116) }, { ((unsigned char )19), ((unsigned char )75), ((unsigned char )47), ((unsigned char )10), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )15), ((unsigned char )54), ((unsigned char )24), ((unsigned char )25), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )23), ((unsigned char )45), ((unsigned char )15), ((unsigned char )25), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )13), ((unsigned char )-111), ((unsigned char )115), ((unsigned char )3), ((unsigned char )-110), ((unsigned char )116) }, { ((unsigned char )2), ((unsigned char )74), ((unsigned char )46), ((unsigned char )29), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )42), ((unsigned char )54), ((unsigned char )24), ((unsigned char )1), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )23), ((unsigned char )45), ((unsigned char )15), ((unsigned char )28), ((unsigned char )46), ((unsigned char )16) }, "\x11\x91s\x00\x00", { ((unsigned char )10), ((unsigned char )74), ((unsigned char )46), ((unsigned char )23), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )10), ((unsigned char )54), ((unsigned char )24), ((unsigned char )35), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )19), ((unsigned char )45), ((unsigned char )15), ((unsigned char )35), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )17), ((unsigned char )-111), ((unsigned char )116), ((unsigned char )1), ((unsigned char )-110), ((unsigned char )116) }, { ((unsigned char )14), ((unsigned char )73), ((unsigned char )46), ((unsigned char )21), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )29), ((unsigned char )54), ((unsigned char )24), ((unsigned char )19), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )11), ((unsigned char )45), ((unsigned char )15), ((unsigned char )46), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )13), ((unsigned char )-111), ((unsigned char )115), ((unsigned char )6), ((unsigned char )-110), ((unsigned char )116) }, { ((unsigned char )14), ((unsigned char )74), ((unsigned char )46), ((unsigned char )23), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )44), ((unsigned char )54), ((unsigned char )24), ((unsigned char )7), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )59), ((unsigned char )46), ((unsigned char )16), ((unsigned char )1), ((unsigned char )47), ((unsigned char )17) }, { ((unsigned char )12), ((unsigned char )-105), ((unsigned char )121), ((unsigned char )7), ((unsigned char )-104), ((unsigned char )122) }, { ((unsigned char )12), ((unsigned char )75), ((unsigned char )47), ((unsigned char )26), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )39), ((unsigned char )54), ((unsigned char )24), ((unsigned char )14), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )22), ((unsigned char )45), ((unsigned char )15), ((unsigned char )41), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )6), ((unsigned char )-105), ((unsigned char )121), ((unsigned char )14), ((unsigned char )-104), ((unsigned char )122) }, { ((unsigned char )6), ((unsigned char )75), ((unsigned char )47), ((unsigned char )34), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )46), ((unsigned char )54), ((unsigned char )24), ((unsigned char )10), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )2), ((unsigned char )45), ((unsigned char )15), ((unsigned char )64), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )17), ((unsigned char )-104), ((unsigned char )122), ((unsigned char )4), ((unsigned char )-103), ((unsigned char )123) }, { ((unsigned char )29), ((unsigned char )74), ((unsigned char )46), ((unsigned char )14), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )49), ((unsigned char )54), ((unsigned char )24), ((unsigned char )10), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )24), ((unsigned char )45), ((unsigned char )15), ((unsigned char )46), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )4), ((unsigned char )-104), ((unsigned char )122), ((unsigned char )18), ((unsigned char )-93), ((unsigned char )123) }, { ((unsigned char )13), ((unsigned char )74), ((unsigned char )46), ((unsigned char )32), ((unsigned char )75), ((unsigned char )47) }, { ((unsigned char )48), ((unsigned char )54), ((unsigned char )24), ((unsigned char )14), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )42), ((unsigned char )45), ((unsigned char )15), ((unsigned char )32), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )20), ((unsigned char )-109), ((unsigned char )117), ((unsigned char )4), ((unsigned char )-108), ((unsigned char )118) }, { ((unsigned char )40), ((unsigned char )74), ((unsigned char )47), ((unsigned char )7), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )43), ((unsigned char )54), ((unsigned char )24), ((unsigned char )22), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )10), ((unsigned char )45), ((unsigned char )15), ((unsigned char )67), ((unsigned char )46), ((unsigned char )16) }, { ((unsigned char )19), ((unsigned char )-108), ((unsigned char )118), ((unsigned char )6), ((unsigned char )-107), ((unsigned char )119) }, { ((unsigned char )18), ((unsigned char )75), ((unsigned char )47), ((unsigned char )31), ((unsigned char )76), ((unsigned char )48) }, { ((unsigned char )34), ((unsigned char )54), ((unsigned char )24), ((unsigned char )34), ((unsigned char )55), ((unsigned char )25) }, { ((unsigned char )20), ((unsigned char )45), ((unsigned char )25), ((unsigned char )61), ((unsigned char )46), ((unsigned char )16) } };


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
