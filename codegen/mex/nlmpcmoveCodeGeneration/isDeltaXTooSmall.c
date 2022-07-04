/*
 * isDeltaXTooSmall.c
 *
 * Code generation for function 'isDeltaXTooSmall'
 *
 */

/* Include files */
#include "isDeltaXTooSmall.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = { 1,  /* lineNo */
  "isDeltaXTooSmall",                  /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\isDeltaXTooSmall.p"/* pathName */
};

static emlrtBCInfo mb_emlrtBCI = { 1,  /* iFirst */
  321,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "isDeltaXTooSmall",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\isDeltaXTooSmall.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "isDeltaXTooSmall",                  /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+fminconsqp\\+stopping\\isDeltaXTooSmall.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
boolean_T isDeltaXTooSmall(const emlrtStack *sp, const real_T xCurrent[321],
  const real_T delta_x_data[], const int32_T delta_x_size[1], int32_T nVar)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  boolean_T exitg1;
  boolean_T tf;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tf = true;
  st.site = &nd_emlrtRSI;
  if ((1 <= nVar) && (nVar > 2147483646)) {
    b_st.site = &db_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx <= nVar - 1)) {
    if ((idx + 1 < 1) || (idx + 1 > 321)) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, 321, &mb_emlrtBCI, sp);
    }

    if ((idx + 1 < 1) || (idx + 1 > delta_x_size[0])) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, delta_x_size[0], &nb_emlrtBCI,
        sp);
    }

    if (1.0E-6 * muDoubleScalarMax(1.0, muDoubleScalarAbs(xCurrent[idx])) <=
        muDoubleScalarAbs(delta_x_data[idx])) {
      tf = false;
      exitg1 = true;
    } else {
      idx++;
    }
  }

  return tf;
}

/* End of code generation (isDeltaXTooSmall.c) */
