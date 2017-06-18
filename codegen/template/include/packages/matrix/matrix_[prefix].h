/* matrix_{{prefix}}.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * {{notice}}
 */

#include "../common/status.h"
#include "../matrix/matrix.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef matrix_{{prefix}}_h
#define matrix_{{prefix}}_h

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct __attribute__((packed)) Matrix_{{prefix}}_s
  {
    {{ctype}}       *data;
    MatrixInfo_t  info;
  } XMatrix_{{prefix}}_t;

  typedef XMatrix_{{prefix}}_t * CMatrix_{{prefix}}_t;
  typedef XMatrix_{{prefix}}_t * FMatrix_{{prefix}}_t;
  typedef void        *  Matrix_{{prefix}}_t;

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */
