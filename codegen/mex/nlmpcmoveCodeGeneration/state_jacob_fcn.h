/*
 * state_jacob_fcn.h
 *
 * Code generation for function 'state_jacob_fcn'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void state_jacob_fcn(const real_T in1[12], const real_T in2[4], real_T A[144],
                     real_T B[48]);

/* End of code generation (state_jacob_fcn.h) */
