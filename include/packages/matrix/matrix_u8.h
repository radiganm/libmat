/* matrix_u8.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_u8_h
#define matrix_u8_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_u8_s
  {
    uint8_t       *data;
    MatrixInfo_t  info;
  } XMatrix_u8_t;

  typedef XMatrix_u8_t * CMatrix_u8_t;
  typedef XMatrix_u8_t * FMatrix_u8_t;
  typedef void        *  Matrix_u8_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */