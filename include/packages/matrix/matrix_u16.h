/* matrix_u16.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_u16_h
#define matrix_u16_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_u16_s
  {
    uint16_t       *data;
    MatrixInfo_t  info;
  } XMatrix_u16_t;

  typedef XMatrix_u16_t * CMatrix_u16_t;
  typedef XMatrix_u16_t * FMatrix_u16_t;
  typedef void        *  Matrix_u16_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */