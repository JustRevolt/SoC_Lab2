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
void multiply_matrices(signed short llvm_cbe_n, signed short *llvm_cbe_a, signed short *llvm_cbe_b, signed short *llvm_cbe_c);


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

void multiply_matrices(signed short llvm_cbe_n, signed short *llvm_cbe_a, signed short *llvm_cbe_b, signed short *llvm_cbe_c) {
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
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  unsigned short llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  signed short *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned short llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__9;
  unsigned int llvm_cbe_tmp__9__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_2e_us_count = 0;
  unsigned short llvm_cbe_storemerge15_2e_us_2e_us;
  unsigned short llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__10;
  unsigned int llvm_cbe_tmp__10__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge23_2e_us_2e_us_count = 0;
  unsigned short llvm_cbe_storemerge23_2e_us_2e_us;
  unsigned short llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned short llvm_cbe_tmp__11;
  unsigned short llvm_cbe_tmp__11__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  signed short *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned short llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  signed short *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned short llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned short llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned short llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned short llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__25;
  unsigned int llvm_cbe_tmp__25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_storemerge8_2e_us_count = 0;
  unsigned short llvm_cbe_storemerge8_2e_us;
  unsigned short llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @multiply_matrices\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%1, %%2, !dbg !2 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((signed short )llvm_cbe_n) > ((signed short )((unsigned short )4))) & (((signed short )llvm_cbe_n) < ((signed short )((unsigned short )11))))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe__2e_preheader7;
  } else {
    goto llvm_cbe_tmp__27;
  }

llvm_cbe__2e_preheader7:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i16 %%n to i32, !dbg !2 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__1 = (unsigned int )((signed int )(signed short )llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
  if ((((signed short )llvm_cbe_n) > ((signed short )((unsigned short )0)))) {
    llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned short )((unsigned short )0);   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '.preheader.lr.ph.split.us.us' to make GCC happy */
llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = phi i32 [ %%6, %%._crit_edge6.us-lcssa.us.us ], [ 0, %%.preheader7  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__25 = (unsigned int )llvm_cbe_tmp__25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",llvm_cbe_tmp__3);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge8.us = phi i16 [ %%5, %%._crit_edge6.us-lcssa.us.us ], [ 0, %%.preheader7  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_storemerge8_2e_us_count);
  llvm_cbe_storemerge8_2e_us = (unsigned short )llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge8.us = 0x%X",llvm_cbe_storemerge8_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__2);
printf("\n = 0x%X",((unsigned short )0));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = mul nsw i32 %%33, %%3, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_tmp__25&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
  llvm_cbe_tmp__9__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY = (unsigned short )((unsigned short )0);   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;

llvm_cbe__2e__crit_edge6_2e_us_2d_lcssa_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add i16 %%storemerge8.us, 1, !dbg !4 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__2 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_storemerge8_2e_us&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__2&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i16 %%5 to i32, !dbg !2 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(unsigned short )llvm_cbe_tmp__2&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
  if ((((signed int )llvm_cbe_tmp__3) < ((signed int )llvm_cbe_tmp__1))) {
    llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    llvm_cbe_storemerge8_2e_us__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__2;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_lr_2e_ph_2e_split_2e_us_2e_us;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '.lr.ph.us.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = phi i32 [ 0, %%.preheader.lr.ph.split.us.us ], [ %%13, %%8  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__9 = (unsigned int )llvm_cbe_tmp__9__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__9);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us.us = phi i16 [ 0, %%.preheader.lr.ph.split.us.us ], [ %%12, %%8  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_2e_us_count);
  llvm_cbe_storemerge15_2e_us_2e_us = (unsigned short )llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us.us = 0x%X",llvm_cbe_storemerge15_2e_us_2e_us);
printf("\n = 0x%X",((unsigned short )0));
printf("\n = 0x%X",llvm_cbe_tmp__7);
}
  llvm_cbe_tmp__10__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned short )((unsigned short )0);   /* for PHI node */
  llvm_cbe_tmp__11__PHI_TEMPORARY = (unsigned short )((unsigned short )0);   /* for PHI node */
  goto llvm_cbe_tmp__28;

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%15, %%34, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_tmp__9&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__26&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i32 %%9 to i64, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__5 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i16* %%c, i64 %%10, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__6 = (signed short *)(&llvm_cbe_c[(((signed long long )llvm_cbe_tmp__5))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__5));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i16 %%29, i16* %%11, align 2, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__6 = llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i16 %%storemerge15.us.us, 1, !dbg !4 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__7 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_storemerge15_2e_us_2e_us&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__7&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i16 %%12 to i32, !dbg !2 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(unsigned short )llvm_cbe_tmp__7&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
  if ((((signed int )llvm_cbe_tmp__8) < ((signed int )llvm_cbe_tmp__1))) {
    llvm_cbe_tmp__9__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__8;   /* for PHI node */
    llvm_cbe_storemerge15_2e_us_2e_us__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__7;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge6_2e_us_2d_lcssa_2e_us_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__28:
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = phi i32 [ 0, %%.lr.ph.us.us ], [ %%31, %%16  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__10 = (unsigned int )llvm_cbe_tmp__10__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__10);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge23.us.us = phi i16 [ 0, %%.lr.ph.us.us ], [ %%30, %%16  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_storemerge23_2e_us_2e_us_count);
  llvm_cbe_storemerge23_2e_us_2e_us = (unsigned short )llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge23.us.us = 0x%X",llvm_cbe_storemerge23_2e_us_2e_us);
printf("\n = 0x%X",((unsigned short )0));
printf("\n = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = phi i16 [ 0, %%.lr.ph.us.us ], [ %%29, %%16  for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__11 = (unsigned short )llvm_cbe_tmp__11__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__11);
printf("\n = 0x%X",((unsigned short )0));
printf("\n = 0x%X",llvm_cbe_tmp__22);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add nsw i32 %%17, %%34, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__12 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__26&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__12&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = sext i32 %%19 to i64, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__13 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds i16* %%a, i64 %%20, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__14 = (signed short *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__13))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__13));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i16* %%21, align 2, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__15 = (unsigned short )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = mul nsw i32 %%17, %%3, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%23, %%15, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__9&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%24 to i64, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds i16* %%b, i64 %%25, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__19 = (signed short *)(&llvm_cbe_b[(((signed long long )llvm_cbe_tmp__18))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i16* %%26, align 2, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__20 = (unsigned short )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = mul i16 %%27, %%22, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__21 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__20&65535ull)) * ((unsigned short )(llvm_cbe_tmp__15&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__21&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add i16 %%28, %%18, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__22 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_tmp__21&65535ull)) + ((unsigned short )(llvm_cbe_tmp__11&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__22&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = add i16 %%storemerge23.us.us, 1, !dbg !5 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__23 = (unsigned short )((unsigned short )(((unsigned short )(llvm_cbe_storemerge23_2e_us_2e_us&65535ull)) + ((unsigned short )(((unsigned short )1)&65535ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned short )(llvm_cbe_tmp__23&65535ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i16 %%30 to i32, !dbg !3 for 0x%I64xth hint within @multiply_matrices  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(unsigned short )llvm_cbe_tmp__23&65535U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
  if ((((signed int )llvm_cbe_tmp__24) < ((signed int )llvm_cbe_tmp__1))) {
    llvm_cbe_tmp__10__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    llvm_cbe_storemerge23_2e_us_2e_us__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__23;   /* for PHI node */
    llvm_cbe_tmp__11__PHI_TEMPORARY = (unsigned short )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__28;
  } else {
    goto llvm_cbe_tmp__29;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us.us' */
  } while (1); /* end of syntactic loop '.preheader.lr.ph.split.us.us' */
llvm_cbe__2e_loopexit:
  goto llvm_cbe_tmp__27;

llvm_cbe_tmp__27:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @multiply_matrices}\n");
  return;
}

