/*
 * _coder_nlmpcmoveCodeGeneration_api.c
 *
 * Code generation for function '_coder_nlmpcmoveCodeGeneration_api'
 *
 */

/* Include files */
#include "_coder_nlmpcmoveCodeGeneration_api.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[12];
static const mxArray *b_emlrt_marshallOut(const struct1_T *u);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12];
static const mxArray *c_emlrt_marshallOut(const real_T u[60]);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lastMV,
  const char_T *identifier))[4];
static const mxArray *d_emlrt_marshallOut(const struct2_T *u);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4];
static const mxArray *e_emlrt_marshallOut(const real_T u[64]);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *emlrt_marshallOut(const real_T u[4]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *onlinedata,
  const char_T *identifier, struct1_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[60]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[180]);
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12];
static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4];
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[60]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[180]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier))[12]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[12];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(x), &thisId);
  emlrtDestroyArray(&x);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const struct1_T *u)
{
  static const int32_T iv[2] = { 1, 4 };

  static const int32_T iv1[2] = { 15, 12 };

  static const char_T *sv[5] = { "ref", "MVTarget", "X0", "MV0", "Slack0" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 5, sv));
  emlrtSetFieldR2017b(y, 0, "ref", c_emlrt_marshallOut(u->ref), 0);
  b_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u->MVTarget[0];
  pData[1] = u->MVTarget[1];
  pData[2] = u->MVTarget[2];
  pData[3] = u->MVTarget[3];
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "MVTarget", b_y, 1);
  c_y = NULL;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 12; b_i++) {
    for (c_i = 0; c_i < 15; c_i++) {
      pData[i] = u->X0[c_i + 15 * b_i];
      i++;
    }
  }

  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "X0", c_y, 2);
  emlrtSetFieldR2017b(y, 0, "MV0", c_emlrt_marshallOut(u->MV0), 3);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->Slack0);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "Slack0", d_y, 4);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[12]
{
  real_T (*y)[12];
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *c_emlrt_marshallOut(const real_T u[60])
{
  static const int32_T iv[2] = { 15, 4 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 4; b_i++) {
    for (c_i = 0; c_i < 15; c_i++) {
      pData[i] = u[c_i + 15 * b_i];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *lastMV,
  const char_T *identifier))[4]
{
  emlrtMsgIdentifier thisId;
  real_T (*y)[4];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(sp, emlrtAlias(lastMV), &thisId);
  emlrtDestroyArray(&lastMV);
  return y;
}
  static const mxArray *d_emlrt_marshallOut(const struct2_T *u)
{
  static const int32_T iv[2] = { 16, 12 };

  static const int32_T iv1[1] = { 16 };

  static const char_T *sv[8] = { "MVopt", "Xopt", "Yopt", "Topt", "Slack",
    "ExitFlag", "Iterations", "Cost" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 8, sv));
  emlrtSetFieldR2017b(y, 0, "MVopt", e_emlrt_marshallOut(u->MVopt), 0);
  b_y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 12; b_i++) {
    for (c_i = 0; c_i < 16; c_i++) {
      pData[i] = u->Xopt[c_i + (b_i << 4)];
      i++;
    }
  }

  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "Xopt", b_y, 1);
  emlrtSetFieldR2017b(y, 0, "Yopt", e_emlrt_marshallOut(u->Yopt), 2);
  c_y = NULL;
  m = emlrtCreateNumericArray(1, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 16; b_i++) {
    pData[i] = u->Topt[b_i];
    i++;
  }

  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "Topt", c_y, 3);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u->Slack);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "Slack", d_y, 4);
  e_y = NULL;
  m = emlrtCreateDoubleScalar(u->ExitFlag);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "ExitFlag", e_y, 5);
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u->Iterations);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "Iterations", f_y, 6);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u->Cost);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(y, 0, "Cost", g_y, 7);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[4]
{
  real_T (*y)[4];
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *e_emlrt_marshallOut(const real_T u[64])
{
  static const int32_T iv[2] = { 16, 4 };

  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 4; b_i++) {
    for (c_i = 0; c_i < 16; c_i++) {
      pData[i] = u[c_i + (b_i << 4)];
      i++;
    }
  }

  emlrtAssign(&y, m);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[4])
{
  static const int32_T iv[1] = { 0 };

  static const int32_T iv1[1] = { 4 };

  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, iv1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *onlinedata,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  g_emlrt_marshallIn(sp, emlrtAlias(onlinedata), &thisId, y);
  emlrtDestroyArray(&onlinedata);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = { "ref", "MVTarget", "X0", "MV0",
    "Slack0" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "ref";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "ref")),
                     &thisId, y->ref);
  thisId.fIdentifier = "MVTarget";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "MVTarget")),
                     &thisId, y->MVTarget);
  thisId.fIdentifier = "X0";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "X0")),
                     &thisId, y->X0);
  thisId.fIdentifier = "MV0";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "MV0")),
                     &thisId, y->MV0);
  thisId.fIdentifier = "Slack0";
  y->Slack0 = emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "Slack0")), &thisId);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[60])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[180])
{
  p_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12]
{
  static const int32_T dims[1] = { 12 };

  real_T (*ret)[12];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[12])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[4]
{
  static const int32_T dims[1] = { 4 };

  real_T (*ret)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[4])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[60])
{
  static const int32_T dims[2] = { 15, 4 };

  real_T (*r)[60];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[60])emlrtMxGetData(src);
  for (i = 0; i < 60; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  ret[3] = (*r)[3];
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[180])
{
  static const int32_T dims[2] = { 15, 12 };

  real_T (*r)[180];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[180])emlrtMxGetData(src);
  for (i = 0; i < 180; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

void nlmpcmoveCodeGeneration_api(c_nlmpcmoveCodeGenerationStackD *SD, const
  mxArray * const prhs[4], int32_T nlhs, const mxArray *plhs[3])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  struct1_T onlinedata;
  struct2_T info;
  real_T (*x)[12];
  real_T (*lastMV)[4];
  real_T (*mv)[4];
  st.tls = emlrtRootTLSGlobal;
  mv = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));

  /* Marshall function inputs */
  x = b_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "x");
  lastMV = d_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "lastMV");
  f_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "onlinedata", &onlinedata);

  /* Invoke the target function */
  nlmpcmoveCodeGeneration(SD, &st, *x, *lastMV, &onlinedata, *mv, &info);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*mv);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(&onlinedata);
  }

  if (nlhs > 2) {
    plhs[2] = d_emlrt_marshallOut(&info);
  }
}

/* End of code generation (_coder_nlmpcmoveCodeGeneration_api.c) */
