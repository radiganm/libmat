/* cmatrix_d.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_d.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_d_h
#define cmatrix_d_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_d_MOD_add(CMatrix_d_t y, CMatrix_d_t x1, CMatrix_d_t x2);
  extern void __cmat_d_MOD_axby(CMatrix_d_t y, double *a1, CMatrix_d_t x1, double *a2, CMatrix_d_t x2);
  extern void __cmat_d_MOD_c2f(CMatrix_d_t x, Matrix_d_t *fmat);
  extern void __cmat_d_MOD_dot(double *y, CMatrix_d_t x1, CMatrix_d_t x2);
  extern void __cmat_d_MOD_eye(CMatrix_d_t x);
  extern void __cmat_d_MOD_fill(CMatrix_d_t x, double *val, uint64_t *r1, uint64_t *r2, uint64_t *c1, uint64_t *c2);
  extern void __cmat_d_MOD_mul(CMatrix_d_t y, CMatrix_d_t x1, CMatrix_d_t x2);
  extern void __cmat_d_MOD_pow(CMatrix_d_t y, CMatrix_d_t x, double *n);
  extern void __cmat_d_MOD_reshape(CMatrix_d_t x, uint64_t *n1, uint64_t *n2);
  extern void __cmat_d_MOD_show_named(CMatrix_d_t x, size_t n, char *name);
  extern void __cmat_d_MOD_show_named2(Matrix_d_t x, size_t n, char *name);
  extern void __cmat_d_MOD_trace(CMatrix_d_t x, double *y);
  extern void __cmat_d_MOD_transpose_in_place(CMatrix_d_t x);


  extern void __cmat_d_MOD_svd(CMatrix_d_t x, CMatrix_d_t s, CMatrix_d_t vt);


#ifdef __cplusplus
}
#endif

  status_t cmat_d_init(CMatrix_d_t *mat, int64_t n1, int64_t n2);

  status_t cmat_d_use(CMatrix_d_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */