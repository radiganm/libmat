/* matrix_s.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_s_h
#define matrix_s_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_s_s
  {
    float       *data;
    MatrixInfo_t  info;
  } XMatrix_s_t;

  typedef XMatrix_s_t * CMatrix_s_t;
  typedef XMatrix_s_t * FMatrix_s_t;
  typedef void        *  Matrix_s_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */