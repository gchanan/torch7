#ifndef TH_HALF_H
#define TH_HALF_H

#include "THGeneral.h"
#include <stdint.h>

# if defined (TH_HALF_TYPE)
# else
/* Neither built-in nor included from Cutorch, use our definition lifted from CUDA */
#if defined(__GNUC__)
#define __align__(n) __attribute__((aligned(n)))
#elif defined(_WIN32)
#define __align__(n) __declspec(align(n))
#else
#define __align__(n)
#endif

typedef struct __align__(2){
  unsigned short x;
} __half;

typedef struct __align__(4) {
    unsigned int x;
} __half2;

typedef __half half;
typedef __half2 half2;
# endif

/* numeric limits */


TH_API half TH_float2half(float a);
TH_API float TH_half2float(half a);

#ifndef TH_HALF_BITS_TO_LITERAL
# define TH_HALF_BITS_TO_LITERAL(n) { n }
#endif

#define TH_HALF_MAX TH_HALF_BITS_TO_LITERAL(0x7BFF)

#endif
