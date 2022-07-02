/*
 * nlmpcmoveCodeGeneration_types.h
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T ref[4];
  real_T MVTarget[4];
  real_T X0[180];
  real_T MV0[60];
  real_T Slack0;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T MVopt[64];
  real_T Xopt[192];
  real_T Yopt[64];
  real_T Topt[16];
  real_T Slack;
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef struct_emxArray_real_T_360
#define struct_emxArray_real_T_360

struct emxArray_real_T_360
{
  real_T data[360];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_360*/

#ifndef typedef_emxArray_real_T_360
#define typedef_emxArray_real_T_360

typedef struct emxArray_real_T_360 emxArray_real_T_360;

#endif                                 /*typedef_emxArray_real_T_360*/

#ifndef struct_emxArray_real_T_962
#define struct_emxArray_real_T_962

struct emxArray_real_T_962
{
  real_T data[962];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_962*/

#ifndef typedef_emxArray_real_T_962
#define typedef_emxArray_real_T_962

typedef struct emxArray_real_T_962 emxArray_real_T_962;

#endif                                 /*typedef_emxArray_real_T_962*/

#ifndef struct_emxArray_real_T_1743
#define struct_emxArray_real_T_1743

struct emxArray_real_T_1743
{
  real_T data[1743];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_1743*/

#ifndef typedef_emxArray_real_T_1743
#define typedef_emxArray_real_T_1743

typedef struct emxArray_real_T_1743 emxArray_real_T_1743;

#endif                                 /*typedef_emxArray_real_T_1743*/

#ifndef struct_emxArray_int32_T_1743
#define struct_emxArray_int32_T_1743

struct emxArray_int32_T_1743
{
  int32_T data[1743];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_int32_T_1743*/

#ifndef typedef_emxArray_int32_T_1743
#define typedef_emxArray_int32_T_1743

typedef struct emxArray_int32_T_1743 emxArray_int32_T_1743;

#endif                                 /*typedef_emxArray_int32_T_1743*/

#ifndef struct_emxArray_real_T_1743x1743
#define struct_emxArray_real_T_1743x1743

struct emxArray_real_T_1743x1743
{
  real_T data[3038049];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1743x1743*/

#ifndef typedef_emxArray_real_T_1743x1743
#define typedef_emxArray_real_T_1743x1743

typedef struct emxArray_real_T_1743x1743 emxArray_real_T_1743x1743;

#endif                                 /*typedef_emxArray_real_T_1743x1743*/

#ifndef struct_emxArray_real_T_962x180
#define struct_emxArray_real_T_962x180

struct emxArray_real_T_962x180
{
  real_T data[173160];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_962x180*/

#ifndef typedef_emxArray_real_T_962x180
#define typedef_emxArray_real_T_962x180

typedef struct emxArray_real_T_962x180 emxArray_real_T_962x180;

#endif                                 /*typedef_emxArray_real_T_962x180*/

#ifndef struct_emxArray_real_T_1743x962
#define struct_emxArray_real_T_1743x962

struct emxArray_real_T_1743x962
{
  real_T data[1676766];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1743x962*/

#ifndef typedef_emxArray_real_T_1743x962
#define typedef_emxArray_real_T_1743x962

typedef struct emxArray_real_T_1743x962 emxArray_real_T_1743x962;

#endif                                 /*typedef_emxArray_real_T_1743x962*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  emxArray_real_T_1743x962 workspace_double;
  emxArray_int32_T_1743 workspace_int;
  emxArray_int32_T_1743 workspace_sort;
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef struct_emxArray_real_T_962x360
#define struct_emxArray_real_T_962x360

struct emxArray_real_T_962x360
{
  real_T data[346320];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_962x360*/

#ifndef typedef_emxArray_real_T_962x360
#define typedef_emxArray_real_T_962x360

typedef struct emxArray_real_T_962x360 emxArray_real_T_962x360;

#endif                                 /*typedef_emxArray_real_T_962x360*/

#ifndef struct_emxArray_real_T_360x1
#define struct_emxArray_real_T_360x1

struct emxArray_real_T_360x1
{
  real_T data[360];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_360x1*/

#ifndef typedef_emxArray_real_T_360x1
#define typedef_emxArray_real_T_360x1

typedef struct emxArray_real_T_360x1 emxArray_real_T_360x1;

#endif                                 /*typedef_emxArray_real_T_360x1*/

#ifndef struct_emxArray_int32_T_962
#define struct_emxArray_int32_T_962

struct emxArray_int32_T_962
{
  int32_T data[962];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_int32_T_962*/

#ifndef typedef_emxArray_int32_T_962
#define typedef_emxArray_int32_T_962

typedef struct emxArray_int32_T_962 emxArray_int32_T_962;

#endif                                 /*typedef_emxArray_int32_T_962*/

#ifndef struct_emxArray_boolean_T_1743
#define struct_emxArray_boolean_T_1743

struct emxArray_boolean_T_1743
{
  boolean_T data[1743];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_boolean_T_1743*/

#ifndef typedef_emxArray_boolean_T_1743
#define typedef_emxArray_boolean_T_1743

typedef struct emxArray_boolean_T_1743 emxArray_boolean_T_1743;

#endif                                 /*typedef_emxArray_boolean_T_1743*/

#ifndef typedef_g_struct_T
#define typedef_g_struct_T

typedef struct {
  int32_T nVarMax;
  int32_T mNonlinIneq;
  int32_T mNonlinEq;
  int32_T mIneq;
  int32_T mEq;
  int32_T iNonIneq0;
  int32_T iNonEq0;
  real_T sqpFval;
  real_T sqpFval_old;
  real_T xstarsqp[241];
  real_T xstarsqp_old[241];
  emxArray_real_T_360 cIneq;
  emxArray_real_T_360 cIneq_old;
  real_T cEq[180];
  real_T cEq_old[180];
  emxArray_real_T_962 grad;
  emxArray_real_T_962 grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_1743 lambdasqp;
  emxArray_real_T_1743 lambdasqp_old;
  real_T steplength;
  emxArray_real_T_962 delta_x;
  emxArray_real_T_962 socDirection;
  emxArray_real_T_1743 lambda_old;
  emxArray_int32_T_1743 workingset_old;
  emxArray_real_T_1743x1743 JacCineqTrans_old;
  emxArray_real_T_962x180 JacCeqTrans_old;
  emxArray_real_T_962 gradLag;
  emxArray_real_T_962 delta_gradLag;
  emxArray_real_T_962 xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_1743 lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_962 searchDir;
} g_struct_T;

#endif                                 /*typedef_g_struct_T*/

#ifndef typedef_j_struct_T
#define typedef_j_struct_T

typedef struct {
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  emxArray_real_T_962x360 Aineq;
  emxArray_real_T_360x1 bineq;
  emxArray_real_T_962x180 Aeq;
  real_T beq[180];
  emxArray_real_T_962 lb;
  emxArray_real_T_962 ub;
  emxArray_int32_T_962 indexLB;
  emxArray_int32_T_962 indexUB;
  emxArray_int32_T_962 indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[180];
  emxArray_real_T_1743x1743 ATwset;
  emxArray_real_T_1743 bwset;
  int32_T nActiveConstr;
  emxArray_real_T_1743 maxConstrWorkspace;
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  emxArray_boolean_T_1743 isActiveConstr;
  emxArray_int32_T_1743 Wid;
  emxArray_int32_T_1743 Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
} j_struct_T;

#endif                                 /*typedef_j_struct_T*/

#ifndef typedef_l_struct_T
#define typedef_l_struct_T

typedef struct {
  int32_T ldq;
  emxArray_real_T_1743x1743 QR;
  emxArray_real_T_1743x1743 Q;
  emxArray_int32_T_1743 jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_1743 tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
} l_struct_T;

#endif                                 /*typedef_l_struct_T*/

#ifndef typedef_m_struct_T
#define typedef_m_struct_T

typedef struct {
  emxArray_real_T_1743x1743 FMat;
  int32_T ldm;
  int32_T ndims;
  int32_T info;
} m_struct_T;

#endif                                 /*typedef_m_struct_T*/

#ifndef typedef_c_nlmpcmoveCodeGenerationStackD
#define typedef_c_nlmpcmoveCodeGenerationStackD

typedef struct {
  union
  {
    struct {
      real_T tmp_data[14400];
      real_T y_data[14400];
      real_T varargin_2_data[7200];
    } f0;

    struct {
      real_T Jx[32400];
      real_T Jmv[10800];
      real_T y[10800];
    } f1;

    struct {
      real_T workspace_data[1676766];
    } f2;

    struct {
      real_T y_data[1676766];
    } f3;

    struct {
      boolean_T tmp_data[57840];
    } f4;
  } u1;

  union
  {
    struct {
      real_T Jc_data[28920];
    } f5;

    struct {
      real_T Jceq[43380];
      real_T Jc_data[28920];
    } f6;
  } u2;

  union
  {
    struct {
      real_T varargout_4[43380];
      real_T varargout_3_data[28920];
    } f7;

    struct {
      real_T varargout_4[43380];
      real_T varargout_3_data[28920];
    } f8;
  } u3;

  struct {
    l_struct_T obj;
    j_struct_T WorkingSet;
    g_struct_T TrialState;
    m_struct_T b_obj;
    d_struct_T memspace;
    real_T unusedExpr[58081];
  } f9;

  struct {
    real_T A_data[57840];
    real_T Auf_data[14400];
    real_T y_data[14400];
  } f10;
} c_nlmpcmoveCodeGenerationStackD;

#endif                                 /*typedef_c_nlmpcmoveCodeGenerationStackD*/

/* End of code generation (nlmpcmoveCodeGeneration_types.h) */
