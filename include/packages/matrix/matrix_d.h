/* matrix_d.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_d_h
#define matrix_d_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_d_s
  {
    double       *data;
    MatrixInfo_t  info;
  } XMatrix_d_t;

  typedef XMatrix_d_t * CMatrix_d_t;
  typedef XMatrix_d_t * FMatrix_d_t;
  typedef void        *  Matrix_d_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */