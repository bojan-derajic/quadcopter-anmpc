/*
 * xgeqrf.c
 *
 * Code generation for function 'xgeqrf'
 *
 */

/* Include files */
#include "xgeqrf.h"
#include "eml_int_forloop_overflow_check.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ff_emlrtRSI = { 27, /* lineNo */
  "xgeqrf",                            /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 102,/* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 99, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 94, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 93, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 91, /* lineNo */
  "ceval_xgeqrf",                      /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqrf.m"/* pathName */
};

/* Function Definitions */
void xgeqrf(const emlrtStack *sp, real_T A_data[], const int32_T A_size[2],
            int32_T m, int32_T n, real_T tau_data[], int32_T tau_size[1])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd',
    'g', 'e', 'q', 'r', 'f' };

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
  st.site = &ff_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  ma = A_size[0];
  minmana = muIntScalarMin_sint32(ma, A_size[1]);
  tau_size[0] = minmana;
  if (n == 0) {
    tau_size[0] = minmana;
    if (0 <= minmana - 1) {
      memset(&tau_data[0], 0, minmana * sizeof(real_T));
    }
  } else {
    info_t = LAPACKE_dgeqrf(102, (ptrdiff_t)m, (ptrdiff_t)n, &A_data[0],
      (ptrdiff_t)A_size[0], &tau_data[0]);
    b_st.site = &kf_emlrtRSI;
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
      b_st.site = &jf_emlrtRSI;
      if ((1 <= n) && (n > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (minmn = 0; minmn < n; minmn++) {
        b_st.site = &if_emlrtRSI;
        if ((1 <= m) && (m > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (i = 0; i < m; i++) {
          A_data[minmn * ma + i] = rtNaN;
        }
      }

      minmn = muIntScalarMin_sint32(m, n);
      b_st.site = &hf_emlrtRSI;
      for (i = 0; i < minmn; i++) {
        tau_data[i] = rtNaN;
      }

      minmn++;
      b_st.site = &gf_emlrtRSI;
      if (minmn <= minmana) {
        memset(&tau_data[minmn + -1], 0, ((minmana - minmn) + 1) * sizeof(real_T));
      }
    }
  }
}

/* End of code generation (xgeqrf.c) */
