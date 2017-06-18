/* cmatrix_u8.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_u8.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_u8_h
#define cmatrix_u8_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_u8_MOD_add(CMatrix_u8_t y, CMatrix_u8_t x1, CMatrix_u8_t x2);

  extern void __cmat_u8_MOD_axby(CMatrix_u8_t y, uint8_t *a1, CMatrix_u8_t x1, uint8_t *a2, CMatrix_u8_t x2);

  extern void __cmat_u8_MOD_mul(CMatrix_u8_t y, CMatrix_u8_t x1, CMatrix_u8_t x2);

  extern void __cmat_u8_MOD_dot(uint8_t *y, CMatrix_u8_t x1, CMatrix_u8_t x2);

  extern void __cmat_u8_MOD_transpose_in_place(CMatrix_u8_t x);

  extern void __cmat_u8_MOD_reshape(CMatrix_u8_t x, uint64_t *n1, uint64_t *n2);

  extern void __cmat_u8_MOD_trace(CMatrix_u8_t x, uint8_t *y);

  extern void __cmat_u8_MOD_c2f(CMatrix_u8_t x, Matrix_u8_t *fmat);

  extern void __cmat_u8_MOD_show_named2(Matrix_u8_t x, size_t n, char *name);

  extern void __cmat_u8_MOD_eye(CMatrix_u8_t x);

  extern void __cmat_u8_MOD_show_named(CMatrix_u8_t x, size_t n, char *name);



#ifdef __cplusplus
}
#endif

  status_t cmat_u8_init(CMatrix_u8_t *mat, int64_t n1, int64_t n2);

  status_t cmat_u8_use(CMatrix_u8_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */