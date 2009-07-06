/* constants */
#define EAH_GENERIC 0

#define EAH_OPTIMIZATION_ALTIVEC     2
#define EAH_OPTIMIZATION_SSE         3

#define EAH_SINCOS_ROUND_FLOOR       EAH_GENERIC
#define EAH_SINCOS_ROUND_MODF        1
#define EAH_SINCOS_ROUND_PLUS2       2
#define EAH_SINCOS_ROUND_INT4        4
#define EAH_SINCOS_ROUND_INT8        8

#define EAH_SINCOS_F2IBITS_UNION     EAH_GENERIC
#define EAH_SINCOS_F2IBITS_MEMCPY    1

#define EAH_SINCOS_VARIANT_LAL       EAH_GENERIC
#define EAH_SINCOS_VARIANT_LINEAR    9

#define EAH_HOTLOOP_VARIANT_LAL      EAH_GENERIC
#define EAH_HOTLOOP_VARIANT_AUTOVECT 1
#define EAH_HOTLOOP_VARIANT_ALTIVEC  2
#define EAH_HOTLOOP_VARIANT_SSE      3
#define EAH_HOTLOOP_VARIANT_SSE_AKOS08 4
#define EAH_HOTLOOP_VARIANT_x87      EAH_GENERIC

#define EAH_HOTLOOP_DIVS_MULTIPLE    EAH_GENERIC
#define EAH_HOTLOOP_DIVS_RECIPROCAL  1

#define EAH_HOUGH_PREFETCH_NONE      EAH_GENERIC
#define EAH_HOUGH_PREFETCH_DIRECT    1 /* prefetching using compiler directives */
#define EAH_HOUGH_PREFETCH_AMD64     6
#define EAH_HOUGH_PREFETCH_X87       7 /* prefetch commands inlined in x87 assembler */

/* this is the default batch size for prefetching, which should be ok for SSE and PPC.
   there _may_ be systems for which you want to change this */
/* #define EAH_HOUGH_BATCHSIZE_LOG2 2 */

#ifndef EAH_OPTIMIZATION
#define EAH_OPTIMIZATION EAH_GENERIC
#endif

#if   EAH_OPTIMIZATION == 1 /* fastest portable code */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_PLUS2
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_LAL
#define EAH_HOTLOOP_DIVS    EAH_HOTLOOP_DIVS_RECIPROCAL
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_NONE

#elif EAH_OPTIMIZATION == 2 /* AltiVec Code */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_FLOOR
#define EAH_SINCOS_F2IBITS  EAH_SINCOS_F2IBITS_UNION
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_ALTIVEC
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_DIRECT

#elif EAH_OPTIMIZATION == 3 /* SSE code, contains assembler */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_PLUS2
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_SSE
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_X87

#elif EAH_OPTIMIZATION == 4 /* contains x87 assembler, but no SSE instructions */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_PLUS2
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_x87 
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_NONE

#elif EAH_OPTIMIZATION == 5 /* see ==1, with ROUND_FLOOR for PPC */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_FLOOR
#define EAH_HOTLOOP_DIVS    EAH_HOTLOOP_DIVS_RECIPROCAL
#define EAH_SINCOS_F2IBITS  EAH_SINCOS_F2IBITS_UNION

#elif EAH_OPTIMIZATION == 6 /* SSE code, contains assembler, Akos reciprocal estimate, lo/hi precision */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_PLUS2
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_SSE_AKOS08
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_X87
#define EAH_HOTLOOP_INTERLEAVED 1

#elif EAH_OPTIMIZATION == 9 /* experimental */
#define EAH_SINCOS_VARIANT  EAH_SINCOS_VARIANT_LINEAR
#define EAH_SINCOS_ROUND    EAH_SINCOS_ROUND_PLUS2
#define EAH_HOTLOOP_VARIANT EAH_HOTLOOP_VARIANT_AUTOVECT
#define EAH_HOUGH_PREFETCH  EAH_HOUGH_PREFETCH_X87

#endif /* EAH_OPTIMIZATION == */

/* defaults - if they haven't been set special, set them to GENERIC */

#ifndef EAH_SINCOS_VARIANT
#define EAH_SINCOS_VARIANT  EAH_GENERIC
#endif
#ifndef EAH_SINCOS_ROUND
#define EAH_SINCOS_ROUND    EAH_GENERIC
#endif

#ifndef EAH_HOTLOOP_VARIANT
#define EAH_HOTLOOP_VARIANT EAH_GENERIC
#endif
#ifndef EAH_HOTLOOP_DIVS
#define EAH_HOTLOOP_DIVS    EAH_GENERIC
#endif

#ifndef EAH_HOUGH_PREFETCH
#define EAH_HOUGH_PREFETCH  EAH_GENERIC
#endif

#ifndef EAH_HOUGH_BATCHSIZE_LOG2
#define EAH_HOUGH_BATCHSIZE_LOG2 2
#endif

/* it looks like for most compilers this is actually faster... */
#ifndef EAH_SINCOS_F2IBITS
#define EAH_SINCOS_F2IBITS  EAH_SINCOS_F2IBITS_MEMCPY
#endif

#define EAH_OPTIMIZATION_REVISION "$Revision"
