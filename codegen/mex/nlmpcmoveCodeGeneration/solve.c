/*
 * solve.c
 *
 * Code generation for function 'solve'
 *
 */

/* Include files */
#include "solve.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xtrsv.h"

/* Function Definitions */
void b_solve(const m_struct_T *obj, real_T rhs_data[])
{
  c_xtrsv(obj->ndims, obj->FMat.data, obj->ldm, rhs_data);
  xtrsv(obj->ndims, obj->FMat.data, obj->ldm, rhs_data);
}

void solve(const m_struct_T *obj, real_T rhs_data[])
{
  b_xtrsv(obj->ndims, obj->FMat.data, obj->ldm, rhs_data);
  xtrsv(obj->ndims, obj->FMat.data, obj->ldm, rhs_data);
}

/* End of code generation (solve.c) */
