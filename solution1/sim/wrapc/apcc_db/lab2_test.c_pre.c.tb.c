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


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void get_matrix(l_struct_OC__iobuf *llvm_cbe_input, signed short llvm_cbe_n, signed short *llvm_cbe_a);
void print_matrix(l_struct_OC__iobuf *llvm_cbe_output, signed short llvm_cbe_n, signed short *llvm_cbe_a);
signed int main(void);
void AESL_WRAP_multiply_matrices(signed short , signed short *, signed short *, signed short *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[5] = "%hi ";
static  char aesl_internal__OC_str1[2] = "\n";
static  char aesl_internal__OC_str2[7] = "in.dat";
static  char aesl_internal__OC_str3[2] = "r";
static  char aesl_internal__OC_str4[8] = "out.dat";
static  char aesl_internal__OC_str11[47] = "FAIL: Output DOES NOT match the golden output\n";
static  char aesl_internal__OC_str5[2] = "w";
static  char aesl_internal__OC_str6[3] = "%d";
static  char aesl_internal__OC_str7[6] = "\n%hi\n";
static  char aesl_internal__OC_str9[29] = "diff -w out.dat out.gold.dat";
static  char aesl_internal__OC_str10[45] = "*******************************************\n";
static  char aesl_internal__OC_str12[45] = "PASS: The output matches the golden output!\n";
static  char aesl_internal_str[31] = "Comparing against output data ";


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

void get_matrix(l_struct_OC__iobuf *llvm_cbe_input, signed short llvm_cbe_n, signed short *llvm_cbe_a) {
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
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond5_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge12_2e_us;
  unsigned int llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  signed short *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge3_2e_us;
  unsigned int llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @get_matrix\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i16 %%n to i32, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__1 = (unsigned int )((signed int )(signed short )llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
  if ((((signed short )llvm_cbe_n) > ((signed short )((unsigned short )0)))) {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge4;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3.us = phi i32 [ %%5, %%3 ], [ 0, %%0  for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_storemerge3_2e_us_count);
  llvm_cbe_storemerge3_2e_us = (unsigned int )llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3.us = 0x%X",llvm_cbe_storemerge3_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__3);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = mul nsw i32 %%storemerge3.us, %%1, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
  llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__10;

llvm_cbe_tmp__11:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%input, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_17_count);
   /*tail*/ fscanf((l_struct_OC__iobuf *)llvm_cbe_input, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = add nsw i32 %%storemerge3.us, 1, !dbg !7 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
  if (((llvm_cbe_tmp__3&4294967295U) == (llvm_cbe_tmp__1&4294967295U))) {
    goto llvm_cbe__2e__crit_edge4;
  } else {
    llvm_cbe_storemerge3_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__3;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__10:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12.us = phi i32 [ 0, %%.lr.ph.us ], [ %%11, %%6  for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_storemerge12_2e_us_count);
  llvm_cbe_storemerge12_2e_us = (unsigned int )llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12.us = 0x%X",llvm_cbe_storemerge12_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__8);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add nsw i32 %%storemerge12.us, %%12, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__9&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%7 to i64, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__5 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i16* %%a, i64 %%8, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__6 = (signed short *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__5))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__5));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%input, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str, i64 0, i64 0), i16* %%9) nounwind, !dbg !6 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_27_count);
   /*tail*/ fscanf((l_struct_OC__iobuf *)llvm_cbe_input, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), (signed short *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = add nsw i32 %%storemerge12.us, 1, !dbg !7 for 0x%I64xth hint within @get_matrix  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__8&4294967295ull)));
  if (((llvm_cbe_tmp__8&4294967295U) == (llvm_cbe_tmp__1&4294967295U))) {
    goto llvm_cbe_tmp__11;
  } else {
    llvm_cbe_storemerge12_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__8;   /* for PHI node */
    goto llvm_cbe_tmp__10;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @get_matrix}\n");
  return;
}


void print_matrix(l_struct_OC__iobuf *llvm_cbe_output, signed short llvm_cbe_n, signed short *llvm_cbe_a) {
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
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_us_count = 0;
  unsigned int llvm_cbe_fputc_2e_us;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge15_2e_us;
  unsigned int llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  signed short *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned short llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_2e_us_count = 0;
  unsigned int llvm_cbe_storemerge6_2e_us;
  unsigned int llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc4_count = 0;
  unsigned int llvm_cbe_fputc4;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @print_matrix\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i16 %%n to i32, !dbg !7 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_54_count);
  llvm_cbe_tmp__12 = (unsigned int )((signed int )(signed short )llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
  if ((((signed short )llvm_cbe_n) > ((signed short )((unsigned short )0)))) {
    llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  } else {
    goto llvm_cbe__2e__crit_edge7;
  }

  do {     /* Syntactic loop '.lr.ph.us' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_us:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6.us = phi i32 [ %%4, %%3 ], [ 0, %%0  for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_storemerge6_2e_us_count);
  llvm_cbe_storemerge6_2e_us = (unsigned int )llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6.us = 0x%X",llvm_cbe_storemerge6_2e_us);
printf("\n = 0x%X",llvm_cbe_tmp__13);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = mul nsw i32 %%storemerge6.us, %%1, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6_2e_us&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__12&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__21&4294967295ull)));
  llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__22;

llvm_cbe_tmp__23:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.us = tail call i32 @fputc(i32 10, %%struct._iobuf* %%output), !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_fputc_2e_us_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_output);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.us = 0x%X",llvm_cbe_fputc_2e_us);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add nsw i32 %%storemerge6.us, 1, !dbg !7 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__13 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__13&4294967295ull)));
  if (((llvm_cbe_tmp__13&4294967295U) == (llvm_cbe_tmp__12&4294967295U))) {
    goto llvm_cbe__2e__crit_edge7;
  } else {
    llvm_cbe_storemerge6_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__13;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_us;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__22:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15.us = phi i32 [ 0, %%.lr.ph.us ], [ %%12, %%5  for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_storemerge15_2e_us_count);
  llvm_cbe_storemerge15_2e_us = (unsigned int )llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15.us = 0x%X",llvm_cbe_storemerge15_2e_us);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add nsw i32 %%storemerge15.us, %%13, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%6 to i64, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__15 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i16* %%a, i64 %%7, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__16 = (signed short *)(&llvm_cbe_a[(((signed long long )llvm_cbe_tmp__15))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i16* %%8, align 2, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__17 = (unsigned short )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = sext i16 %%9 to i32, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__18 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%output, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%10) nounwind, !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_68_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_output, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__18);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge15.us, 1, !dbg !7 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__20 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15_2e_us&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__20&4294967295ull)));
  if (((llvm_cbe_tmp__20&4294967295U) == (llvm_cbe_tmp__12&4294967295U))) {
    goto llvm_cbe_tmp__23;
  } else {
    llvm_cbe_storemerge15_2e_us__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__20;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.lr.ph.us' */
llvm_cbe__2e__crit_edge7:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc4 = tail call i32 @fputc(i32 10, %%struct._iobuf* %%output), !dbg !6 for 0x%I64xth hint within @print_matrix  --> \n", ++aesl_llvm_cbe_fputc4_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_output);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc4 = 0x%X",llvm_cbe_fputc4);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @print_matrix}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_test_count_count = 0;
  signed int llvm_cbe_test_count;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_n_count = 0;
  signed short llvm_cbe_n;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_a_count = 0;
  signed short llvm_cbe_a[100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_b_count = 0;
  signed short llvm_cbe_b[100];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_c_count = 0;
  signed short llvm_cbe_c[100];    /* Address-exposed local */
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
  l_struct_OC__iobuf *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  signed short *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  signed short *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  signed short *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned short llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  unsigned short llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  unsigned short llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned short llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned short llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  unsigned short llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned short llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned int llvm_cbe_tmp__42;
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
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  store i32 0, i32* %%test_count, align 4, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_92_count);
  *(&llvm_cbe_test_count) = 0u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 0u);
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str2, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str3, i64 0, i64 0)) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__24 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call %%struct._iobuf* @fopen(i8* getelementptr inbounds ([8 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str5, i64 0, i64 0)) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__25 = (l_struct_OC__iobuf *)aesl_fopen(( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 8
#endif
])), ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([3 x i8]* @aesl_internal_.str6, i64 0, i64 0), i32* %%test_count) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_108_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__24, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
])), (signed int *)(&llvm_cbe_test_count));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = load i32* %%test_count, align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__27 = (unsigned int )*(&llvm_cbe_test_count);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__27);
  if ((((signed int )llvm_cbe_tmp__27) > ((signed int )0u))) {
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [100 x i16]* %%a, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__28 = (signed short *)(&llvm_cbe_a[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [100 x i16]* %%b, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__29 = (signed short *)(&llvm_cbe_b[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [100 x i16]* %%c, i64 0, i64 0, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__30 = (signed short *)(&llvm_cbe_c[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 100
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__65;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__65:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ 0, %%.lr.ph ], [ %%21, %%9  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str7, i64 0, i64 0), i16* %%n) nounwind, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_123_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__24, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), (signed short *)(&llvm_cbe_n));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i16* %%n, align 2, !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__32 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  call void @get_matrix(%%struct._iobuf* %%1, i16 signext %%11, i16* %%6), !dbg !7 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_131_count);
  get_matrix((l_struct_OC__iobuf *)llvm_cbe_tmp__24, llvm_cbe_tmp__32, (signed short *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = call i32 (%%struct._iobuf*, i8*, ...)* @fscanf(%%struct._iobuf* %%1, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str1, i64 0, i64 0)) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_132_count);
  fscanf((l_struct_OC__iobuf *)llvm_cbe_tmp__24, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i16* %%n, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__34 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  call void @get_matrix(%%struct._iobuf* %%1, i16 signext %%13, i16* %%7), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_140_count);
  get_matrix((l_struct_OC__iobuf *)llvm_cbe_tmp__24, llvm_cbe_tmp__34, (signed short *)llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__34);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i16* %%n, align 2, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_147_count);
  llvm_cbe_tmp__35 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_multiply_matrices(i16 signext %%14, i16* %%6, i16* %%7, i16* %%8) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_148_count);
  AESL_WRAP_multiply_matrices(llvm_cbe_tmp__35, (signed short *)llvm_cbe_tmp__28, (signed short *)llvm_cbe_tmp__29, (signed short *)llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i16* %%n, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__36 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = sext i16 %%15 to i32, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__37 = (unsigned int )((signed int )(signed short )llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%2, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str7, i64 0, i64 0), i32 %%16) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_157_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__25, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__37);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = load i16* %%n, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__39 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_matrix(%%struct._iobuf* %%2, i16 signext %%18, i16* %%6), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_165_count);
  print_matrix((l_struct_OC__iobuf *)llvm_cbe_tmp__25, llvm_cbe_tmp__39, (signed short *)llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = load i16* %%n, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_172_count);
  llvm_cbe_tmp__40 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_matrix(%%struct._iobuf* %%2, i16 signext %%19, i16* %%7), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_173_count);
  print_matrix((l_struct_OC__iobuf *)llvm_cbe_tmp__25, llvm_cbe_tmp__40, (signed short *)llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i16* %%n, align 2, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__41 = (unsigned short )*(&llvm_cbe_n);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  call void @print_matrix(%%struct._iobuf* %%2, i16 signext %%20, i16* %%8), !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_181_count);
  print_matrix((l_struct_OC__iobuf *)llvm_cbe_tmp__25, llvm_cbe_tmp__41, (signed short *)llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = add nsw i32 %%storemerge2, 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_storemerge2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i32* %%test_count, align 4, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_192_count);
  llvm_cbe_tmp__43 = (unsigned int )*(&llvm_cbe_test_count);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
  if ((((signed int )llvm_cbe_tmp__42) < ((signed int )llvm_cbe_tmp__43))) {
    llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__42;   /* for PHI node */
    goto llvm_cbe_tmp__65;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = call i32 @fclose(%%struct._iobuf* %%1) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_195_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call i32 @fclose(%%struct._iobuf* %%2) nounwind, !dbg !8 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_196_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__45);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([31 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 31
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 @system(i8* getelementptr inbounds ([29 x i8]* @aesl_internal_.str9, i64 0, i64 0)) nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__46 = (unsigned int )system(( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 29
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__46);
}
  if (((llvm_cbe_tmp__46&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__66;
  } else {
    goto llvm_cbe_tmp__67;
  }

llvm_cbe_tmp__67:
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_200_count);
  llvm_cbe_tmp__47 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct._iobuf* %%29, i64 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_201_count);
  llvm_cbe_tmp__48 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__47[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%30), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_202_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__49);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__50 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct._iobuf* %%32, i64 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__51 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__50[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i64 @fwrite(i8* getelementptr inbounds ([47 x i8]* @aesl_internal_.str11, i64 0, i64 0), i64 46, i64 1, %%struct._iobuf* %%33), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_205_count);
  fwrite(( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 47
#endif
])), 46ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",46ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__52);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__53 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 1, !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__54 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__53[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%36), !dbg !9 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_208_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__55);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__68;

llvm_cbe_tmp__66:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__56 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds %%struct._iobuf* %%39, i64 1, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__57 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__56[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%40), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_212_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__59 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__59);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds %%struct._iobuf* %%42, i64 1, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__60 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__59[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str12, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%43), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_215_count);
  fwrite(( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__61);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_216_count);
  llvm_cbe_tmp__62 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__62);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds %%struct._iobuf* %%45, i64 1, !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_217_count);
  llvm_cbe_tmp__63 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__62[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = call i64 @fwrite(i8* getelementptr inbounds ([45 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 44, i64 1, %%struct._iobuf* %%46), !dbg !10 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_218_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 45
#endif
])), 44ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",44ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__64);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__68;

llvm_cbe_tmp__68:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ 1, %%28 ], [ 0, %%38  for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_storemerge1;
}

