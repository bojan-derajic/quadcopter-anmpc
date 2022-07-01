/*
 * xscal.c
 *
 * Code generation for function 'xscal'
 *
 */

/* Include files */
#include "xscal.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Function Definitions */
void xscal(int32_T n, real_T a, real_T x_data[], int32_T ix0)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  if (n >= 1) {
    n_t = (ptrdiff_t)n;
    incx_t = (ptrdiff_t)1;
    dscal(&n_t, &a, &x_data[ix0 - 1], &incx_t);
  }
}

/* End of code generation (xscal.c) */
