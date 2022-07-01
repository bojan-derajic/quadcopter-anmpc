/*
 * computeConstraintsAndUserJacobian_.c
 *
 * Code generation for function 'computeConstraintsAndUserJacobian_'
 *
 */

/* Include files */
#include "computeConstraintsAndUserJacobian_.h"
#include "checkVectorNonFinite.h"
#include "nlmpcmoveCodeGeneration.h"
#include "nlmpcmoveCodeGeneration_data.h"
#include "nlmpcmoveCodeGeneration_types.h"
#include "rt_nonfinite.h"
#include "xcopy.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tc_emlrtRSI = { 1,  /* lineNo */
  "computeConstraintsAndUserJacobian_",/* fcnName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeConstraintsAndUserJacobian_.p"/* pathName */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "checkMatrixNonFinite",              /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\+internal\\checkMatrixNonFinite.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { 1,  /* iFirst */
  240,                                 /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "checkMatrixNonFinite",              /* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\+internal\\checkMatrixNonFinite.p",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1,                                   /* lineNo */
  1,                                   /* colNo */
  "",                                  /* aName */
  "computeConstraintsAndUserJacobian_",/* fName */
  "C:\\Program Files\\Polyspace\\R2020b\\toolbox\\optim\\+optim\\+coder\\+utils\\+ObjNonlinEvaluator\\computeConstraintsAndUserJacobian_.p",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
int32_T c_computeConstraintsAndUserJaco(c_nlmpcmoveCodeGenerationStackD *SD,
  const emlrtStack *sp, const real_T c_obj_nonlcon_tunableEnvironmen[12], const
  real_T d_obj_nonlcon_tunableEnvironmen[80], const real_T
  e_obj_nonlcon_tunableEnvironmen[80], int32_T obj_mCineq, const real_T x[321],
  real_T Cineq_workspace_data[], const int32_T Cineq_workspace_size[1], int32_T
  ineq0, real_T Ceq_workspace[240], real_T JacIneqTrans_workspace_data[], const
  int32_T JacIneqTrans_workspace_size[2], int32_T iJI_col, real_T
  JacEqTrans_workspace_data[], const int32_T JacEqTrans_workspace_size[2])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T varargout_2[240];
  real_T varargout_1_data[160];
  real_T b_x;
  int32_T varargout_1_size[2];
  int32_T varargout_3_size[2];
  int32_T col;
  int32_T col_end;
  int32_T i;
  int32_T i1;
  int32_T idx_col;
  int32_T row;
  int32_T status;
  boolean_T allFinite;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (obj_mCineq > 0) {
    st.site = &tc_emlrtRSI;
    b_st.site = &lb_emlrtRSI;
    anon(SD, &b_st, c_obj_nonlcon_tunableEnvironmen,
         d_obj_nonlcon_tunableEnvironmen, e_obj_nonlcon_tunableEnvironmen, x,
         varargout_1_data, varargout_1_size, varargout_2,
         SD->u3.f8.varargout_3_data, varargout_3_size, SD->u3.f8.varargout_4);
    st.site = &tc_emlrtRSI;
    b_xcopy(obj_mCineq, varargout_1_data, Cineq_workspace_data, ineq0);
    st.site = &tc_emlrtRSI;
    memcpy(&Ceq_workspace[0], &varargout_2[0], 240U * sizeof(real_T));
    col_end = varargout_3_size[0];
    st.site = &tc_emlrtRSI;
    for (col = 0; col < col_end; col++) {
      row = varargout_3_size[1];
      st.site = &tc_emlrtRSI;
      for (idx_col = 0; idx_col < row; idx_col++) {
        if ((col + 1 < 1) || (col + 1 > varargout_3_size[0])) {
          emlrtDynamicBoundsCheckR2012b(col + 1, 1, varargout_3_size[0],
            &qb_emlrtBCI, sp);
        }

        if ((idx_col + 1 < 1) || (idx_col + 1 > varargout_3_size[1])) {
          emlrtDynamicBoundsCheckR2012b(idx_col + 1, 1, varargout_3_size[1],
            &qb_emlrtBCI, sp);
        }

        i = JacIneqTrans_workspace_size[0];
        if ((col + 1 < 1) || (col + 1 > i)) {
          emlrtDynamicBoundsCheckR2012b(col + 1, 1, i, &qb_emlrtBCI, sp);
        }

        i = JacIneqTrans_workspace_size[1];
        i1 = iJI_col + idx_col;
        if ((i1 < 1) || (i1 > i)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, i, &qb_emlrtBCI, sp);
        }

        JacIneqTrans_workspace_data[col + JacIneqTrans_workspace_size[0] * (i1 -
          1)] = SD->u3.f8.varargout_3_data[col + varargout_3_size[0] * idx_col];
      }
    }

    for (col = 0; col < 321; col++) {
      for (idx_col = 0; idx_col < 240; idx_col++) {
        JacEqTrans_workspace_data[col + JacEqTrans_workspace_size[0] * idx_col] =
          SD->u3.f8.varargout_4[col + 321 * idx_col];
      }
    }
  } else {
    st.site = &tc_emlrtRSI;
    b_st.site = &lb_emlrtRSI;
    anon(SD, &b_st, c_obj_nonlcon_tunableEnvironmen,
         d_obj_nonlcon_tunableEnvironmen, e_obj_nonlcon_tunableEnvironmen, x,
         varargout_1_data, varargout_1_size, varargout_2,
         SD->u3.f8.varargout_3_data, varargout_3_size, SD->u3.f8.varargout_4);
    st.site = &tc_emlrtRSI;
    memcpy(&Ceq_workspace[0], &varargout_2[0], 240U * sizeof(real_T));
    for (col = 0; col < 321; col++) {
      for (idx_col = 0; idx_col < 240; idx_col++) {
        JacEqTrans_workspace_data[col + JacEqTrans_workspace_size[0] * idx_col] =
          SD->u3.f8.varargout_4[col + 321 * idx_col];
      }
    }
  }

  st.site = &tc_emlrtRSI;
  status = checkVectorNonFinite(&st, obj_mCineq, Cineq_workspace_data,
    Cineq_workspace_size, ineq0);
  if (status == 1) {
    st.site = &tc_emlrtRSI;
    status = b_checkVectorNonFinite(&st, Ceq_workspace);
    if (status == 1) {
      st.site = &tc_emlrtRSI;
      allFinite = true;
      row = 1;
      col = iJI_col;
      col_end = (iJI_col + obj_mCineq) - 1;
      while (allFinite && (col <= col_end)) {
        row = 1;
        while (allFinite && (row <= 321)) {
          i = JacIneqTrans_workspace_size[0];
          if (row > i) {
            emlrtDynamicBoundsCheckR2012b(row, 1, i, &ob_emlrtBCI, &st);
          }

          i = JacIneqTrans_workspace_size[1];
          if ((col < 1) || (col > i)) {
            emlrtDynamicBoundsCheckR2012b(col, 1, i, &ob_emlrtBCI, &st);
          }

          b_x = JacIneqTrans_workspace_data[(row + JacIneqTrans_workspace_size[0]
            * (col - 1)) - 1];
          allFinite = ((!muDoubleScalarIsInf(b_x)) && (!muDoubleScalarIsNaN(b_x)));
          row++;
        }

        col++;
      }

      if (!allFinite) {
        col--;
        row--;
        i = JacIneqTrans_workspace_size[0];
        if ((row < 1) || (row > i)) {
          emlrtDynamicBoundsCheckR2012b(row, 1, i, &ob_emlrtBCI, &st);
        }

        i = JacIneqTrans_workspace_size[1];
        if ((col < 1) || (col > i)) {
          emlrtDynamicBoundsCheckR2012b(col, 1, i, &ob_emlrtBCI, &st);
        }

        i = JacIneqTrans_workspace_size[0] * (col - 1);
        if (muDoubleScalarIsNaN(JacIneqTrans_workspace_data[(row + i) - 1])) {
          status = -3;
        } else {
          i1 = JacIneqTrans_workspace_size[0];
          if (row > i1) {
            emlrtDynamicBoundsCheckR2012b(row, 1, i1, &ob_emlrtBCI, &st);
          }

          i1 = JacIneqTrans_workspace_size[1];
          if (col > i1) {
            emlrtDynamicBoundsCheckR2012b(col, 1, i1, &ob_emlrtBCI, &st);
          }

          if (JacIneqTrans_workspace_data[(row + i) - 1] < 0.0) {
            status = -1;
          } else {
            status = -2;
          }
        }
      }

      if (status == 1) {
        st.site = &tc_emlrtRSI;
        allFinite = true;
        row = -1;
        col = -1;
        while (allFinite && (col + 2 <= 240)) {
          row = -1;
          while (allFinite && (row + 2 <= 321)) {
            b_x = JacEqTrans_workspace_data[(row + JacEqTrans_workspace_size[0] *
              (col + 1)) + 1];
            allFinite = ((!muDoubleScalarIsInf(b_x)) && (!muDoubleScalarIsNaN
              (b_x)));
            row++;
          }

          col++;
        }

        if (!allFinite) {
          i = JacEqTrans_workspace_size[0];
          if ((row + 1 < 1) || (row + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(row + 1, 1, i, &ob_emlrtBCI, &st);
          }

          if ((col + 1 < 1) || (col + 1 > 240)) {
            emlrtDynamicBoundsCheckR2012b(col + 1, 1, 240, &pb_emlrtBCI, &st);
          }

          b_x = JacEqTrans_workspace_data[row + JacEqTrans_workspace_size[0] *
            col];
          if (muDoubleScalarIsNaN(b_x)) {
            status = -3;
          } else if (b_x < 0.0) {
            status = -1;
          } else {
            status = -2;
          }
        }
      }
    }
  }

  return status;
}

/* End of code generation (computeConstraintsAndUserJacobian_.c) */
