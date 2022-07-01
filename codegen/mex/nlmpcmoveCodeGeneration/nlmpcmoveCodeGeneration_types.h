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
  real_T X0[240];
  real_T MV0[80];
  real_T Slack0;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T MVopt[84];
  real_T Xopt[252];
  real_T Yopt[84];
  real_T Topt[21];
  real_T Slack;
  real_T ExitFlag;
  real_T Iterations;
  real_T Cost;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef struct_emxArray_real_T_480
#define struct_emxArray_real_T_480

struct emxArray_real_T_480
{
  real_T data[480];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_480*/

#ifndef typedef_emxArray_real_T_480
#define typedef_emxArray_real_T_480

typedef struct emxArray_real_T_480 emxArray_real_T_480;

#endif                                 /*typedef_emxArray_real_T_480*/

#ifndef struct_emxArray_real_T_1282
#define struct_emxArray_real_T_1282

struct emxArray_real_T_1282
{
  real_T data[1282];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_1282*/

#ifndef typedef_emxArray_real_T_1282
#define typedef_emxArray_real_T_1282

typedef struct emxArray_real_T_1282 emxArray_real_T_1282;

#endif                                 /*typedef_emxArray_real_T_1282*/

#ifndef struct_emxArray_real_T_2323
#define struct_emxArray_real_T_2323

struct emxArray_real_T_2323
{
  real_T data[2323];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_2323*/

#ifndef typedef_emxArray_real_T_2323
#define typedef_emxArray_real_T_2323

typedef struct emxArray_real_T_2323 emxArray_real_T_2323;

#endif                                 /*typedef_emxArray_real_T_2323*/

#ifndef struct_emxArray_int32_T_2323
#define struct_emxArray_int32_T_2323

struct emxArray_int32_T_2323
{
  int32_T data[2323];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_int32_T_2323*/

#ifndef typedef_emxArray_int32_T_2323
#define typedef_emxArray_int32_T_2323

typedef struct emxArray_int32_T_2323 emxArray_int32_T_2323;

#endif                                 /*typedef_emxArray_int32_T_2323*/

#ifndef struct_emxArray_real_T_2323x2323
#define struct_emxArray_real_T_2323x2323

struct emxArray_real_T_2323x2323
{
  real_T data[5396329];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_2323x2323*/

#ifndef typedef_emxArray_real_T_2323x2323
#define typedef_emxArray_real_T_2323x2323

typedef struct emxArray_real_T_2323x2323 emxArray_real_T_2323x2323;

#endif                                 /*typedef_emxArray_real_T_2323x2323*/

#ifndef struct_emxArray_real_T_1282x240
#define struct_emxArray_real_T_1282x240

struct emxArray_real_T_1282x240
{
  real_T data[307680];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1282x240*/

#ifndef typedef_emxArray_real_T_1282x240
#define typedef_emxArray_real_T_1282x240

typedef struct emxArray_real_T_1282x240 emxArray_real_T_1282x240;

#endif                                 /*typedef_emxArray_real_T_1282x240*/

#ifndef struct_emxArray_real_T_2323x1282
#define struct_emxArray_real_T_2323x1282

struct emxArray_real_T_2323x1282
{
  real_T data[2978086];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_2323x1282*/

#ifndef typedef_emxArray_real_T_2323x1282
#define typedef_emxArray_real_T_2323x1282

typedef struct emxArray_real_T_2323x1282 emxArray_real_T_2323x1282;

#endif                                 /*typedef_emxArray_real_T_2323x1282*/

#ifndef typedef_d_struct_T
#define typedef_d_struct_T

typedef struct {
  emxArray_real_T_2323x1282 workspace_double;
  emxArray_int32_T_2323 workspace_int;
  emxArray_int32_T_2323 workspace_sort;
} d_struct_T;

#endif                                 /*typedef_d_struct_T*/

#ifndef struct_emxArray_real_T_1282x480
#define struct_emxArray_real_T_1282x480

struct emxArray_real_T_1282x480
{
  real_T data[615360];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1282x480*/

#ifndef typedef_emxArray_real_T_1282x480
#define typedef_emxArray_real_T_1282x480

typedef struct emxArray_real_T_1282x480 emxArray_real_T_1282x480;

#endif                                 /*typedef_emxArray_real_T_1282x480*/

#ifndef struct_emxArray_real_T_480x1
#define struct_emxArray_real_T_480x1

struct emxArray_real_T_480x1
{
  real_T data[480];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_480x1*/

#ifndef typedef_emxArray_real_T_480x1
#define typedef_emxArray_real_T_480x1

typedef struct emxArray_real_T_480x1 emxArray_real_T_480x1;

#endif                                 /*typedef_emxArray_real_T_480x1*/

#ifndef struct_emxArray_int32_T_1282
#define struct_emxArray_int32_T_1282

struct emxArray_int32_T_1282
{
  int32_T data[1282];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_int32_T_1282*/

#ifndef typedef_emxArray_int32_T_1282
#define typedef_emxArray_int32_T_1282

typedef struct emxArray_int32_T_1282 emxArray_int32_T_1282;

#endif                                 /*typedef_emxArray_int32_T_1282*/

#ifndef struct_emxArray_boolean_T_2323
#define struct_emxArray_boolean_T_2323

struct emxArray_boolean_T_2323
{
  boolean_T data[2323];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_boolean_T_2323*/

#ifndef typedef_emxArray_boolean_T_2323
#define typedef_emxArray_boolean_T_2323

typedef struct emxArray_boolean_T_2323 emxArray_boolean_T_2323;

#endif                                 /*typedef_emxArray_boolean_T_2323*/

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
  real_T xstarsqp[321];
  real_T xstarsqp_old[321];
  emxArray_real_T_480 cIneq;
  emxArray_real_T_480 cIneq_old;
  real_T cEq[240];
  real_T cEq_old[240];
  emxArray_real_T_1282 grad;
  emxArray_real_T_1282 grad_old;
  int32_T FunctionEvaluations;
  int32_T sqpIterations;
  int32_T sqpExitFlag;
  emxArray_real_T_2323 lambdasqp;
  emxArray_real_T_2323 lambdasqp_old;
  real_T steplength;
  emxArray_real_T_1282 delta_x;
  emxArray_real_T_1282 socDirection;
  emxArray_real_T_2323 lambda_old;
  emxArray_int32_T_2323 workingset_old;
  emxArray_real_T_2323x2323 JacCineqTrans_old;
  emxArray_real_T_1282x240 JacCeqTrans_old;
  emxArray_real_T_1282 gradLag;
  emxArray_real_T_1282 delta_gradLag;
  emxArray_real_T_1282 xstar;
  real_T fstar;
  real_T firstorderopt;
  emxArray_real_T_2323 lambda;
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  emxArray_real_T_1282 searchDir;
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
  emxArray_real_T_1282x480 Aineq;
  emxArray_real_T_480x1 bineq;
  emxArray_real_T_1282x240 Aeq;
  real_T beq[240];
  emxArray_real_T_1282 lb;
  emxArray_real_T_1282 ub;
  emxArray_int32_T_1282 indexLB;
  emxArray_int32_T_1282 indexUB;
  emxArray_int32_T_1282 indexFixed;
  int32_T mEqRemoved;
  int32_T indexEqRemoved[240];
  emxArray_real_T_2323x2323 ATwset;
  emxArray_real_T_2323 bwset;
  int32_T nActiveConstr;
  emxArray_real_T_2323 maxConstrWorkspace;
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
  emxArray_boolean_T_2323 isActiveConstr;
  emxArray_int32_T_2323 Wid;
  emxArray_int32_T_2323 Wlocalidx;
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
} j_struct_T;

#endif                                 /*typedef_j_struct_T*/

#ifndef typedef_l_struct_T
#define typedef_l_struct_T

typedef struct {
  int32_T ldq;
  emxArray_real_T_2323x2323 QR;
  emxArray_real_T_2323x2323 Q;
  emxArray_int32_T_2323 jpvt;
  int32_T mrows;
  int32_T ncols;
  emxArray_real_T_2323 tau;
  int32_T minRowCol;
  boolean_T usedPivoting;
} l_struct_T;

#endif                                 /*typedef_l_struct_T*/

#ifndef typedef_m_struct_T
#define typedef_m_struct_T

typedef struct {
  emxArray_real_T_2323x2323 FMat;
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
      real_T tmp_data[25600];
      real_T y_data[25600];
      real_T varargin_2_data[12800];
      int8_T Jx[38400];
    } f0;

    struct {
      real_T Jx[57600];
      real_T Jmv[19200];
      real_T y[19200];
    } f1;

    struct {
      real_T workspace_data[2978086];
    } f2;

    struct {
      real_T y_data[2978086];
    } f3;

    struct {
      boolean_T tmp_data[102720];
    } f4;

    struct {
      real_T Auf_data[25600];
      real_T y_data[25600];
    } f5;
  } u1;

  union
  {
    struct {
      real_T Jc_data[51360];
    } f6;

    struct {
      real_T Jceq[77040];
      real_T Jc_data[51360];
    } f7;
  } u2;

  union
  {
    struct {
      real_T varargout_4[77040];
      real_T varargout_3_data[51360];
    } f8;

    struct {
      real_T varargout_4[77040];
      real_T varargout_3_data[51360];
    } f9;
  } u3;

  struct {
    l_struct_T obj;
    j_struct_T WorkingSet;
    g_struct_T TrialState;
    m_struct_T b_obj;
    d_struct_T memspace;
    real_T Hessian[103041];
  } f10;

  struct {
    real_T A_data[102720];
  } f11;
} c_nlmpcmoveCodeGenerationStackD;

#endif                                 /*typedef_c_nlmpcmoveCodeGenerationStackD*/

/* End of code generation (nlmpcmoveCodeGeneration_types.h) */
