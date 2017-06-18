/* cmatrix_u16.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_u16.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_u16_h
#define cmatrix_u16_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_u16_MOD_add(CMatrix_u16_t y, CMatrix_u16_t x1, CMatrix_u16_t x2);

  extern void __cmat_u16_MOD_axby(CMatrix_u16_t y, uint16_t *a1, CMatrix_u16_t x1, uint16_t *a2, CMatrix_u16_t x2);

  extern void __cmat_u16_MOD_mul(CMatrix_u16_t y, CMatrix_u16_t x1, CMatrix_u16_t x2);

  extern void __cmat_u16_MOD_dot(uint16_t *y, CMatrix_u16_t x1, CMatrix_u16_t x2);

  extern void __cmat_u16_MOD_transpose_in_place(CMatrix_u16_t x);

  extern void __cmat_u16_MOD_reshape(CMatrix_u16_t x, uint64_t *n1, uint64_t *n2);

  extern void __cmat_u16_MOD_trace(CMatrix_u16_t x, uint16_t *y);

  extern void __cmat_u16_MOD_c2f(CMatrix_u16_t x, Matrix_u16_t *fmat);

  extern void __cmat_u16_MOD_show_named2(Matrix_u16_t x, size_t n, char *name);

  extern void __cmat_u16_MOD_eye(CMatrix_u16_t x);

  extern void __cmat_u16_MOD_show_named(CMatrix_u16_t x, size_t n, char *name);



#ifdef __cplusplus
}
#endif

  status_t cmat_u16_init(CMatrix_u16_t *mat, int64_t n1, int64_t n2);

  status_t cmat_u16_use(CMatrix_u16_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */