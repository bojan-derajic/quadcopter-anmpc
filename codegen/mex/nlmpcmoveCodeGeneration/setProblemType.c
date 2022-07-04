/*
 * setProblemType.c
 *
 * Code generation for function 'setProblemType'
 *
 */

/* Include files */
#include "setProblemType.h"
#include "eml_int_forloop_overflow_check.h"
#include "modifyOverheadPhaseOne_.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cd_emlrtRSI = { 1,  /* lineNo */
  "setProblemType",                    /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\setProblemType.p"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 1,  /* lineNo */
  "modifyOverheadRegularized_",        /* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadRegularized_.p"/* pathName */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "modifyOverheadRegularized_",        /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+qpactiveset\\+WorkingSet\\modifyOverheadRegularized_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void setProblemType(const emlrtStack *sp, j_struct_T *obj, int32_T PROBLEM_TYPE)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T a;
  int32_T b;
  int32_T b_a;
  int32_T b_b;
  int32_T b_tmp;
  int32_T i;
  int32_T idxGlobalColStart;
  int32_T idx_col;
  int32_T idx_lb;
  int32_T idx_row;
  int32_T mIneq;
  int32_T offsetEq1;
  int32_T offsetEq2;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 321;
    obj->mConstr = obj->mConstrOrig;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesNormal[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxNormal[i];
    }
    break;

   case 1:
    obj->nVar = 322;
    obj->mConstr = obj->mConstrOrig + 1;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxPhaseOne[i];
    }

    st.site = &cd_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;

   case 2:
    obj->nVar = obj->nVarMax - 1;
    obj->mConstr = obj->mConstrMax - 1;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegularized[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegularized[i];
    }

    if (obj->probType != 4) {
      st.site = &cd_emlrtRSI;
      mIneq = obj->sizes[2] + 321;
      offsetEq1 = obj->sizes[2] + 321;
      offsetEq2 = obj->sizes[2] + 561;
      b = obj->sizes[0];
      b_st.site = &ed_emlrtRSI;
      if ((1 <= obj->sizes[0]) && (obj->sizes[0] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx_col = 0; idx_col < b; idx_col++) {
        b_b = obj->nVar;
        b_st.site = &ed_emlrtRSI;
        if ((322 <= obj->nVar) && (obj->nVar > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = 322; idx_row <= b_b; idx_row++) {
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * idx_col) - 1] = 0.0;
        }
      }

      b_st.site = &ed_emlrtRSI;
      if ((1 <= obj->sizes[2]) && (obj->sizes[2] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx_col = 0; idx_col <= mIneq - 322; idx_col++) {
        idx_lb = idx_col + 321;
        b_st.site = &ed_emlrtRSI;
        if ((322 <= idx_col + 321) && (idx_col + 321 > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = 322; idx_row <= idx_lb; idx_row++) {
          i = obj->Aineq.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->Aineq.size[1];
          if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aineq.data[(idx_row + obj->Aineq.size[0] * idx_col) - 1] = 0.0;
        }

        i = obj->Aineq.size[0];
        if ((idx_col + 322 < 1) || (idx_col + 322 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 322, 1, i, &tb_emlrtBCI, &st);
        }

        i = obj->Aineq.size[1];
        if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &tb_emlrtBCI, &st);
        }

        obj->Aineq.data[(idx_col + obj->Aineq.size[0] * idx_col) + 321] = -1.0;
        a = idx_col + 323;
        b = obj->nVar;
        b_st.site = &ed_emlrtRSI;
        if ((idx_col + 323 <= obj->nVar) && (obj->nVar > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = a; idx_row <= b; idx_row++) {
          i = obj->Aineq.size[0];
          if ((idx_row < 1) || (idx_row > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->Aineq.size[1];
          if ((idx_col + 1 < 1) || (idx_col + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aineq.data[(idx_row + obj->Aineq.size[0] * idx_col) - 1] = 0.0;
        }
      }

      idxGlobalColStart = obj->isActiveIdx[1];
      b_st.site = &ed_emlrtRSI;
      overflow = ((322 <= mIneq) && (mIneq > 2147483646));
      a = mIneq + 1;
      b_a = mIneq + 241;
      for (idx_col = 0; idx_col < 240; idx_col++) {
        b_st.site = &ed_emlrtRSI;
        if (overflow) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = 322; idx_row <= offsetEq1; idx_row++) {
          obj->Aeq.data[(idx_row + obj->Aeq.size[0] * idx_col) - 1] = 0.0;
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          b_b = idxGlobalColStart + idx_col;
          if ((b_b < 1) || (b_b > i)) {
            emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (b_b - 1)) - 1] =
            0.0;
        }

        b_tmp = mIneq + idx_col;
        b_st.site = &ed_emlrtRSI;
        if ((offsetEq1 + 1 <= b_tmp) && (b_tmp > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = a; idx_row <= b_tmp; idx_row++) {
          i = obj->Aeq.size[0];
          if ((idx_row < 1) || (idx_row > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aeq.data[(idx_row + obj->Aeq.size[0] * idx_col) - 1] = 0.0;
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          b_b = idxGlobalColStart + idx_col;
          if ((b_b < 1) || (b_b > i)) {
            emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (b_b - 1)) - 1] =
            0.0;
        }

        i = obj->Aeq.size[0];
        if ((b_tmp + 1 < 1) || (b_tmp + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(b_tmp + 1, 1, i, &tb_emlrtBCI, &st);
        }

        obj->Aeq.data[b_tmp + obj->Aeq.size[0] * idx_col] = -1.0;
        i = obj->ATwset.size[0];
        b_b = (mIneq + idx_col) + 1;
        if ((b_b < 1) || (b_b > i)) {
          emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
        }

        i = obj->ATwset.size[1];
        idx_lb = idxGlobalColStart + idx_col;
        if ((idx_lb < 1) || (idx_lb > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_lb, 1, i, &tb_emlrtBCI, &st);
        }

        obj->ATwset.data[(b_b + obj->ATwset.size[0] * (idx_lb - 1)) - 1] = -1.0;
        idx_lb = b_tmp + 2;
        b_st.site = &ed_emlrtRSI;
        if ((b_tmp + 2 <= mIneq + 240) && (mIneq + 240 > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = idx_lb; idx_row <= offsetEq2; idx_row++) {
          i = obj->Aeq.size[0];
          if ((idx_row < 1) || (idx_row > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aeq.data[(idx_row + obj->Aeq.size[0] * idx_col) - 1] = 0.0;
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          b_b = idxGlobalColStart + idx_col;
          if ((b_b < 1) || (b_b > i)) {
            emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (b_b - 1)) - 1] =
            0.0;
        }

        b = b_tmp + 240;
        b_st.site = &ed_emlrtRSI;
        if ((offsetEq2 + 1 <= b_tmp + 240) && (b_tmp + 240 > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = b_a; idx_row <= b; idx_row++) {
          i = obj->Aeq.size[0];
          if ((idx_row < 1) || (idx_row > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aeq.data[(idx_row + obj->Aeq.size[0] * idx_col) - 1] = 0.0;
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          b_b = idxGlobalColStart + idx_col;
          if ((b_b < 1) || (b_b > i)) {
            emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (b_b - 1)) - 1] =
            0.0;
        }

        i = obj->Aeq.size[0];
        if ((b_tmp + 241 < 1) || (b_tmp + 241 > i)) {
          emlrtDynamicBoundsCheckR2012b(b_tmp + 241, 1, i, &tb_emlrtBCI, &st);
        }

        obj->Aeq.data[(b_tmp + obj->Aeq.size[0] * idx_col) + 240] = 1.0;
        i = obj->ATwset.size[0];
        b_b = (mIneq + idx_col) + 241;
        if ((b_b < 1) || (b_b > i)) {
          emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
        }

        i = obj->ATwset.size[1];
        idx_lb = idxGlobalColStart + idx_col;
        if ((idx_lb < 1) || (idx_lb > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_lb, 1, i, &tb_emlrtBCI, &st);
        }

        obj->ATwset.data[(b_b + obj->ATwset.size[0] * (idx_lb - 1)) - 1] = 1.0;
        idx_lb = b_tmp + 242;
        b = obj->nVar;
        b_st.site = &ed_emlrtRSI;
        if ((b_tmp + 242 <= obj->nVar) && (obj->nVar > 2147483646)) {
          c_st.site = &db_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (idx_row = idx_lb; idx_row <= b; idx_row++) {
          i = obj->Aeq.size[0];
          if ((idx_row < 1) || (idx_row > i)) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          obj->Aeq.data[(idx_row + obj->Aeq.size[0] * idx_col) - 1] = 0.0;
          i = obj->ATwset.size[0];
          if (idx_row > i) {
            emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          b_b = idxGlobalColStart + idx_col;
          if ((b_b < 1) || (b_b > i)) {
            emlrtDynamicBoundsCheckR2012b(b_b, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (b_b - 1)) - 1] =
            0.0;
        }
      }

      idx_lb = 321;
      a = obj->sizesNormal[3] + 1;
      b = obj->sizesRegularized[3];
      b_st.site = &ed_emlrtRSI;
      if ((obj->sizesNormal[3] + 1 <= obj->sizesRegularized[3]) &&
          (obj->sizesRegularized[3] > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (b_a = a; b_a <= b; b_a++) {
        idx_lb++;
        i = obj->indexLB.size[0];
        if ((b_a < 1) || (b_a > i)) {
          emlrtDynamicBoundsCheckR2012b(b_a, 1, i, &tb_emlrtBCI, &st);
        }

        obj->indexLB.data[b_a - 1] = idx_lb;
      }

      b = obj->sizes[2] + 801;
      b_st.site = &ed_emlrtRSI;
      if ((322 <= obj->sizes[2] + 801) && (obj->sizes[2] + 801 > 2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (b_a = 322; b_a <= b; b_a++) {
        i = obj->lb.size[0];
        if (b_a > i) {
          emlrtDynamicBoundsCheckR2012b(b_a, 1, i, &tb_emlrtBCI, &st);
        }

        obj->lb.data[b_a - 1] = 0.0;
      }

      idx_lb = obj->isActiveIdx[2];
      b = obj->nActiveConstr;
      b_st.site = &ed_emlrtRSI;
      if ((obj->isActiveIdx[2] <= obj->nActiveConstr) && (obj->nActiveConstr >
           2147483646)) {
        c_st.site = &db_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (idx_col = idx_lb; idx_col <= b; idx_col++) {
        i = obj->Wid.size[0];
        if ((idx_col < 1) || (idx_col > i)) {
          emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
        }

        switch (obj->Wid.data[idx_col - 1]) {
         case 3:
          i = obj->Wlocalidx.size[0];
          if (idx_col > i) {
            emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
          }

          b_a = obj->Wlocalidx.data[idx_col - 1];
          idxGlobalColStart = b_a + 322;
          b_b = b_a + 320;
          b_st.site = &ed_emlrtRSI;
          i = obj->Wlocalidx.data[idx_col - 1] + 320;
          overflow = ((322 <= i) && (i > 2147483646));
          if (overflow) {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_row = 322; idx_row <= b_b; idx_row++) {
            i = obj->ATwset.size[0];
            if (idx_row > i) {
              emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
            }

            i = obj->ATwset.size[1];
            if (idx_col > i) {
              emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
            }

            obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (idx_col - 1)) - 1]
              = 0.0;
          }

          i = obj->ATwset.size[0];
          if ((b_a + 321 < 1) || (b_a + 321 > i)) {
            emlrtDynamicBoundsCheckR2012b(b_a + 321, 1, i, &tb_emlrtBCI, &st);
          }

          i = obj->ATwset.size[1];
          if (idx_col > i) {
            emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
          }

          obj->ATwset.data[(b_a + obj->ATwset.size[0] * (idx_col - 1)) + 320] =
            -1.0;
          b_b = obj->nVar;
          b_st.site = &ed_emlrtRSI;
          if ((b_a + 322 <= obj->nVar) && (obj->nVar > 2147483646)) {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_row = idxGlobalColStart; idx_row <= b_b; idx_row++) {
            i = obj->ATwset.size[0];
            if ((idx_row < 1) || (idx_row > i)) {
              emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
            }

            i = obj->ATwset.size[1];
            if (idx_col > i) {
              emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
            }

            obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (idx_col - 1)) - 1]
              = 0.0;
          }
          break;

         default:
          b_b = obj->nVar;
          b_st.site = &ed_emlrtRSI;
          if ((322 <= obj->nVar) && (obj->nVar > 2147483646)) {
            c_st.site = &db_emlrtRSI;
            check_forloop_overflow_error(&c_st);
          }

          for (idx_row = 322; idx_row <= b_b; idx_row++) {
            i = obj->ATwset.size[0];
            if (idx_row > i) {
              emlrtDynamicBoundsCheckR2012b(idx_row, 1, i, &tb_emlrtBCI, &st);
            }

            i = obj->ATwset.size[1];
            if (idx_col > i) {
              emlrtDynamicBoundsCheckR2012b(idx_col, 1, i, &tb_emlrtBCI, &st);
            }

            obj->ATwset.data[(idx_row + obj->ATwset.size[0] * (idx_col - 1)) - 1]
              = 0.0;
          }
          break;
        }
      }
    }
    break;

   default:
    obj->nVar = obj->nVarMax;
    obj->mConstr = obj->mConstrMax;
    for (i = 0; i < 5; i++) {
      obj->sizes[i] = obj->sizesRegPhaseOne[i];
    }

    for (i = 0; i < 6; i++) {
      obj->isActiveIdx[i] = obj->isActiveIdxRegPhaseOne[i];
    }

    st.site = &cd_emlrtRSI;
    modifyOverheadPhaseOne_(&st, obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

/* End of code generation (setProblemType.c) */
