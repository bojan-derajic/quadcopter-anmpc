/*
 * nlmpcmoveCodeGeneration_internal_types.h
 *
 * Code generation for function 'nlmpcmoveCodeGeneration'
 *
 */

#pragma once

/* Include files */
#include "nlmpcmoveCodeGeneration_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T gradOK;
  boolean_T fevalOK;
  boolean_T done;
  boolean_T stepAccepted;
  boolean_T failedLineSearch;
  int32_T stepType;
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T iterations;
  real_T funcCount;
  char_T algorithm[3];
  real_T constrviolation;
  real_T stepsize;
  real_T lssteplength;
  real_T firstorderopt;
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct {
  char_T SolverName[7];
  int32_T MaxIterations;
  real_T StepTolerance;
  real_T OptimalityTolerance;
  real_T ConstraintTolerance;
  real_T ObjectiveLimit;
  real_T PricingTolerance;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
  boolean_T IterDisplayQP;
} c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef struct_emxArray_real_T_961
#define struct_emxArray_real_T_961

struct emxArray_real_T_961
{
  real_T data[961];
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_961*/

#ifndef typedef_emxArray_real_T_961
#define typedef_emxArray_real_T_961

typedef struct emxArray_real_T_961 emxArray_real_T_961;

#endif                                 /*typedef_emxArray_real_T_961*/

#ifndef typedef_e_struct_T
#define typedef_e_struct_T

typedef struct {
  real_T Ts;
  real_T CurrentStates[12];
  real_T LastMV[4];
  real_T References[60];
  real_T MVTarget[60];
  real_T PredictionHorizon;
  real_T NumOfStates;
  real_T NumOfOutputs;
  real_T NumOfInputs;
  real_T MVIndex[4];
} e_struct_T;

#endif                                 /*typedef_e_struct_T*/

#ifndef typedef_f_struct_T
#define typedef_f_struct_T

typedef struct {
  real_T x[12];
  real_T lastMV[4];
  real_T ref[60];
  real_T OutputWeights[60];
  real_T MVWeights[60];
  real_T MVRateWeights[60];
  real_T ECRWeight;
  real_T OutputMin[60];
  real_T OutputMax[60];
  real_T StateMin[180];
  real_T StateMax[180];
  real_T MVMin[60];
  real_T MVMax[60];
  real_T MVRateMin[60];
  real_T MVRateMax[60];
  real_T MVScaledTarget[60];
} f_struct_T;

#endif                                 /*typedef_f_struct_T*/

#ifndef typedef_cell_2
#define typedef_cell_2

typedef struct {
  f_struct_T f1;
  e_struct_T f2;
} cell_2;

#endif                                 /*typedef_cell_2*/

#ifndef typedef_anonymous_function
#define typedef_anonymous_function

typedef struct {
  cell_2 tunableEnvironment;
} anonymous_function;

#endif                                 /*typedef_anonymous_function*/

#ifndef typedef_h_struct_T
#define typedef_h_struct_T

typedef struct {
  anonymous_function objfun;
  anonymous_function nonlcon;
  int32_T nVar;
  int32_T mCineq;
  int32_T mCeq;
  boolean_T NonFiniteSupport;
  boolean_T SpecifyObjectiveGradient;
  boolean_T SpecifyConstraintGradient;
  boolean_T ScaleProblem;
} h_struct_T;

#endif                                 /*typedef_h_struct_T*/

#ifndef typedef_i_struct_T
#define typedef_i_struct_T

typedef struct {
  emxArray_real_T_962 grad;
  emxArray_real_T_961 Hx;
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
} i_struct_T;

#endif                                 /*typedef_i_struct_T*/

#ifndef typedef_k_struct_T
#define typedef_k_struct_T

typedef struct {
  real_T penaltyParam;
  real_T threshold;
  int32_T nPenaltyDecreases;
  real_T linearizedConstrViol;
  real_T initFval;
  real_T initConstrViolationEq;
  real_T initConstrViolationIneq;
  real_T phi;
  real_T phiPrimePlus;
  real_T phiFullStep;
  real_T feasRelativeFactor;
  real_T nlpPrimalFeasError;
  real_T nlpDualFeasError;
  real_T nlpComplError;
  real_T firstOrderOpt;
  boolean_T hasObjective;
} k_struct_T;

#endif                                 /*typedef_k_struct_T*/

/* End of code generation (nlmpcmoveCodeGeneration_internal_types.h) */
