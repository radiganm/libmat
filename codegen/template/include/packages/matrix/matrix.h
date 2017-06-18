/* matrix.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * {{notice}}
 */

#include "../common/status.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_h
#define matrix_h

  #define MAT_MAX_DIMS (7)

  enum Type : uint32_t
  {
    COMPLEX_DOUBLE = 0,
    COMPLEX_SINGLE = 1,
    REAL_DOUBLE    = 3,
    REAL_SINGLE    = 4,
    UNSIGNED_8     = 5,
    UNSIGNED_16    = 6
  };

#ifdef __cplusplus
extern "C" {
#endif

  typedef Status status_t;

  typedef struct __attribute__((packed)) Complex_Double_s
  {
    double real;
    double imag;
  } Complex_Double_t;

  typedef struct __attribute__((packed)) Complex_Single_s
  {
    float real;
    float imag;
  } Complex_Single_t;

  typedef struct __attribute__((packed)) MatrixInfo_s
  {
    Type    type;
    int32_t n_dims;
    int64_t dims[MAT_MAX_DIMS];
  } MatrixInfo_t;

#ifdef __cplusplus
}
#endif

  size_t sizeof_type(Type x);

#endif

/* *EOF* */
