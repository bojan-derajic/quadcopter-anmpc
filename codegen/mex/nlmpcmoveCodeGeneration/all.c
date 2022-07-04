/*
 * all.c
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "all.h"
#include "rt_nonfinite.h"

/* Function Definitions */
boolean_T all(const boolean_T x_data[], const int32_T x_size[1])
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x_size[0])) {
    if (!x_data[ix - 1]) {
      y = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  return y;
}

void b_all(const boolean_T x[60], boolean_T y[4])
{
  int32_T ix;
  boolean_T exitg1;
  y[0] = true;
  y[1] = true;
  y[2] = true;
  y[3] = true;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= 15)) {
    if (!x[ix - 1]) {
      y[0] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 16;
  exitg1 = false;
  while ((!exitg1) && (ix <= 30)) {
    if (!x[ix - 1]) {
      y[1] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 31;
  exitg1 = false;
  while ((!exitg1) && (ix <= 45)) {
    if (!x[ix - 1]) {
      y[2] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }

  ix = 46;
  exitg1 = false;
  while ((!exitg1) && (ix <= 60)) {
    if (!x[ix - 1]) {
      y[3] = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
}

/* End of code generation (all.c) */
