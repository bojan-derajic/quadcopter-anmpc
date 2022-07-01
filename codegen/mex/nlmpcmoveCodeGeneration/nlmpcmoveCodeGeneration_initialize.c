/*
 * nlmpcmoveCodeGeneration_initialize.c
 *
 * Code generation for function 'nlmpcmoveCodeGeneration_initialize'
 *
 */

/* Include files */
#include "nlmpcmoveCodeGeneration_initialize.h"
#include "_coder_nlmpcmoveCodeGeneration_mex.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

/* Function Definitions */
void nlmpcmoveCodeGeneration_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2012b(&st, "optimization_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (nlmpcmoveCodeGeneration_initialize.c) */
