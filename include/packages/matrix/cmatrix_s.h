/* cmatrix_s.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_s.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_s_h
#define cmatrix_s_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_s_MOD_add(CMatrix_s_t y, CMatrix_s_t x1, CMatrix_s_t x2);

  extern void __cmat_s_MOD_axby(CMatrix_s_t y, float *a1, CMatrix_s_t x1, float *a2, CMatrix_s_t x2);

  extern void __cmat_s_MOD_mul(CMatrix_s_t y, CMatrix_s_t x1, CMatrix_s_t x2);

  extern void __cmat_s_MOD_dot(float *y, CMatrix_s_t x1, CMatrix_s_t x2);

  extern void __cmat_s_MOD_transpose_in_place(CMatrix_s_t x);

  extern void __cmat_s_MOD_reshape(CMatrix_s_t x, uint64_t *n1, uint64_t *n2);

  extern void __cmat_s_MOD_trace(CMatrix_s_t x, float *y);

  extern void __cmat_s_MOD_c2f(CMatrix_s_t x, Matrix_s_t *fmat);

  extern void __cmat_s_MOD_show_named2(Matrix_s_t x, size_t n, char *name);

  extern void __cmat_s_MOD_eye(CMatrix_s_t x);

  extern void __cmat_s_MOD_show_named(CMatrix_s_t x, size_t n, char *name);


  extern void __cmat_s_MOD_svd(CMatrix_s_t x, CMatrix_s_t s, CMatrix_s_t vt);


#ifdef __cplusplus
}
#endif

  status_t cmat_s_init(CMatrix_s_t *mat, int64_t n1, int64_t n2);

  status_t cmat_s_use(CMatrix_s_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */