/* matrix_c.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_c_h
#define matrix_c_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_c_s
  {
    Complex_Single_t       *data;
    MatrixInfo_t  info;
  } XMatrix_c_t;

  typedef XMatrix_c_t * CMatrix_c_t;
  typedef XMatrix_c_t * FMatrix_c_t;
  typedef void        *  Matrix_c_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */