/* matrix_z.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_z_h
#define matrix_z_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_z_s
  {
    Complex_Double_t       *data;
    MatrixInfo_t  info;
  } XMatrix_z_t;

  typedef XMatrix_z_t * CMatrix_z_t;
  typedef XMatrix_z_t * FMatrix_z_t;
  typedef void        *  Matrix_z_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */