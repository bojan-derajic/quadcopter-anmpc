/*
 * checkLinearInputs.c
 *
 * Code generation for function 'checkLinearInputs'
 *
 */

/* Include files */
#include "checkLinearInputs.h"
#include "all.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 1,  /* lineNo */
  "checkLinearInputs",                 /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+validate\\checkLinearInputs.p"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "checkLinearInputs",                 /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+validate\\checkLinearInputs.p"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "checkX0",                           /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+validate\\checkX0.p"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "checkBounds",                       /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+validate\\checkBounds.p"/* pName */
};

/* Function Definitions */
void checkLinearInputs(c_nlmpcmoveCodeGenerationStackD *SD, const emlrtStack *sp,
  const real_T x0[241], const real_T Aineq_data[], const int32_T Aineq_size[2],
  const real_T bineq_data[], const int32_T bineq_size[1], const real_T lb[241],
  const real_T ub[241])
{
  emlrtStack st;
  real_T d;
  int32_T tmp_size[1];
  int32_T b_i;
  int32_T i;
  boolean_T tmp_data[57840];
  boolean_T b[241];
  boolean_T b_b[241];
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  if ((Aineq_size[0] != 0) && (Aineq_size[1] != 0)) {
    i = Aineq_size[0] * Aineq_size[1];
    tmp_size[0] = i;
    for (b_i = 0; b_i < i; b_i++) {
      SD->u1.f4.tmp_data[b_i] = muDoubleScalarIsInf(Aineq_data[b_i]);
    }

    for (b_i = 0; b_i < i; b_i++) {
      tmp_data[b_i] = muDoubleScalarIsNaN(Aineq_data[b_i]);
    }

    for (b_i = 0; b_i < i; b_i++) {
      SD->u1.f4.tmp_data[b_i] = ((!SD->u1.f4.tmp_data[b_i]) && (!tmp_data[b_i]));
    }

    if (!all(SD->u1.f4.tmp_data, tmp_size)) {
      emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
        "optim_codegen:common:InfNaNComplexDetected",
        "optim_codegen:common:InfNaNComplexDetected", 3, 4, 1, "A");
    }
  }

  if (bineq_size[0] != 0) {
    tmp_size[0] = bineq_size[0];
    i = bineq_size[0];
    for (b_i = 0; b_i < i; b_i++) {
      SD->u1.f4.tmp_data[b_i] = muDoubleScalarIsInf(bineq_data[b_i]);
    }

    i = bineq_size[0];
    for (b_i = 0; b_i < i; b_i++) {
      tmp_data[b_i] = muDoubleScalarIsNaN(bineq_data[b_i]);
    }

    i = bineq_size[0];
    for (b_i = 0; b_i < i; b_i++) {
      SD->u1.f4.tmp_data[b_i] = ((!SD->u1.f4.tmp_data[b_i]) && (!tmp_data[b_i]));
    }

    if (!all(SD->u1.f4.tmp_data, tmp_size)) {
      emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
        "optim_codegen:common:InfNaNComplexDetected",
        "optim_codegen:common:InfNaNComplexDetected", 3, 4, 1, "B");
    }
  }

  st.site = &hb_emlrtRSI;
  for (i = 0; i < 241; i++) {
    d = x0[i];
    b[i] = muDoubleScalarIsInf(d);
    b_b[i] = muDoubleScalarIsNaN(d);
  }

  y = true;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 241)) {
    if (b[i] || b_b[i]) {
      y = false;
      exitg1 = true;
    } else {
      i++;
    }
  }

  if (!y) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetected",
      "optim_codegen:common:InfNaNComplexDetected", 3, 4, 2, "x0");
  }

  st.site = &hb_emlrtRSI;
  for (b_i = 0; b_i < 241; b_i++) {
    b[b_i] = (lb[b_i] == rtInf);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= 240)) {
    if (!b[i]) {
      i++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    for (i = 0; i < 241; i++) {
      b[i] = muDoubleScalarIsNaN(lb[i]);
    }

    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= 240)) {
      if (!b[i]) {
        i++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    if (y) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetectedLB",
      "optim_codegen:common:InfNaNComplexDetectedLB", 0);
  }

  for (b_i = 0; b_i < 241; b_i++) {
    b[b_i] = (ub[b_i] == rtMinusInf);
  }

  y = false;
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i <= 240)) {
    if (!b[i]) {
      i++;
    } else {
      y = true;
      exitg1 = true;
    }
  }

  guard1 = false;
  if (y) {
    guard1 = true;
  } else {
    for (i = 0; i < 241; i++) {
      b[i] = muDoubleScalarIsNaN(ub[i]);
    }

    y = false;
    i = 0;
    exitg1 = false;
    while ((!exitg1) && (i <= 240)) {
      if (!b[i]) {
        i++;
      } else {
        y = true;
        exitg1 = true;
      }
    }

    if (y) {
      guard1 = true;
    }
  }

  if (guard1) {
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "optim_codegen:common:InfNaNComplexDetectedUB",
      "optim_codegen:common:InfNaNComplexDetectedUB", 0);
  }

  if ((Aineq_size[0] != 0) && (Aineq_size[1] != 0) && (Aineq_size[1] != 241)) {
    emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
      "optim_codegen:common:WrongNumberOfColumnsInA",
      "optim_codegen:common:WrongNumberOfColumnsInA", 2, 6, 241.0);
  }

  if ((Aineq_size[0] != 0) && (Aineq_size[1] != 0) && (Aineq_size[0] !=
       bineq_size[0])) {
    emlrtErrorWithMessageIdR2018a(sp, &g_emlrtRTEI,
      "optim_codegen:common:AAndBinInconsistent",
      "optim_codegen:common:AAndBinInconsistent", 0);
  }
}

/* End of code generation (checkLinearInputs.c) */
