/*
 * revertSolution.c
 *
 * Code generation for function 'revertSolution'
 *
 */

/* Include files */
#include "revertSolution.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>
#include <string.h>

/* Function Definitions */
void revertSolution(g_struct_T *obj)
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  real_T y_data[1743];
  int32_T loop_ub;
  int32_T y_size_idx_0;
  obj->sqpFval = obj->sqpFval_old;
  memcpy(&obj->xstarsqp[0], &obj->xstarsqp_old[0], 241U * sizeof(real_T));
  y_size_idx_0 = obj->cIneq.size[0];
  loop_ub = obj->cIneq.size[0];
  if (0 <= loop_ub - 1) {
    memcpy(&y_data[0], &obj->cIneq.data[0], loop_ub * sizeof(real_T));
  }

  if (obj->mIneq >= 1) {
    n_t = (ptrdiff_t)obj->mIneq;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    dcopy(&n_t, &obj->cIneq_old.data[0], &incx_t, &y_data[0], &incy_t);
  }

  obj->cIneq.size[0] = y_size_idx_0;
  if (0 <= y_size_idx_0 - 1) {
    memcpy(&obj->cIneq.data[0], &y_data[0], y_size_idx_0 * sizeof(real_T));
  }

  memcpy(&obj->cEq[0], &obj->cEq_old[0], 180U * sizeof(real_T));
}

/* End of code generation (revertSolution.c) */
