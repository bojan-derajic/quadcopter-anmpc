/*
 * xgeqp3.c
 *
 * Code generation for function 'xgeqp3'
 *
 */

/* Include files */
#include "xgeqp3.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qd_emlrtRSI = { 63, /* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo rd_emlrtRSI = { 158,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo sd_emlrtRSI = { 154,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo td_emlrtRSI = { 151,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo ud_emlrtRSI = { 148,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo vd_emlrtRSI = { 143,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 141,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 138,/* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo yd_emlrtRSI = { 98, /* lineNo */
  "ceval_xgeqp3",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

/* Function Definitions */
void xgeqp3(const emlrtStack *sp, real_T A_data[], const int32_T A_size[2],
            int32_T m, int32_T n, int32_T jpvt_data[], const int32_T jpvt_size[1],
            real_T tau_data[], int32_T tau_size[1])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'p', '3' };

  ptrdiff_t jpvt_t_data[2323];
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T ma;
  int32_T minmana;
  int32_T minmn;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  ma = A_size[0];
  minmana = muIntScalarMin_sint32(ma, A_size[1]);
  tau_size[0] = minmana;
  if (n < 1) {
    tau_size[0] = minmana;
    if (0 <= minmana - 1) {
      memset(&tau_data[0], 0, minmana * sizeof(real_T));
    }

    b_st.site = &yd_emlrtRSI;
    for (ma = 0; ma < n; ma++) {
      jpvt_data[ma] = ma + 1;
    }
  } else {
    minmn = jpvt_size[0];
    for (i = 0; i < minmn; i++) {
      jpvt_t_data[i] = (ptrdiff_t)jpvt_data[i];
    }

    info_t = LAPACKE_dgeqp3(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
      (ptrdiff_t)A_size[0], &jpvt_t_data[0], &tau_data[0]);
    b_st.site = &xd_emlrtRSI;
    minmn = (int32_T)info_t;
    if (minmn != 0) {
      p = true;
      if (minmn != -4) {
        if (minmn == -1010) {
          emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI, "MATLAB:nomem",
            "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&b_st, &o_emlrtRTEI,
            "Coder:toolbox:LAPACKCallErrorInfo",
            "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, minmn);
        }
      }
    } else {
      p = false;
    }

    if (p) {
      b_st.site = &wd_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (minmn = 0; minmn < n; minmn++) {
        b_st.site = &vd_emlrtRSI;
        if ((1 <= m) && (m > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (i = 0; i < m; i++) {
          A_data[minmn * ma + i] = rtNaN;
        }
      }

      minmn = muIntScalarMin_sint32(m, n);
      b_st.site = &ud_emlrtRSI;
      for (ma = 0; ma < minmn; ma++) {
        tau_data[ma] = rtNaN;
      }

      minmn++;
      b_st.site = &td_emlrtRSI;
      if (minmn <= minmana) {
        memset(&tau_data[minmn + -1], 0, ((minmana - minmn) + 1) * sizeof(real_T));
      }

      b_st.site = &sd_emlrtRSI;
      for (ma = 0; ma < n; ma++) {
        jpvt_data[ma] = ma + 1;
      }
    } else {
      b_st.site = &rd_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (ma = 0; ma < n; ma++) {
        jpvt_data[ma] = (int32_T)jpvt_t_data[ma];
      }
    }
  }
}

/* End of code generation (xgeqp3.c) */
