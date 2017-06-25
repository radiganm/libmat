/* cmatrix_z.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_z.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_z_h
#define cmatrix_z_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_z_MOD_add(CMatrix_z_t y, CMatrix_z_t x1, CMatrix_z_t x2);
  extern void __cmat_z_MOD_axby(CMatrix_z_t y, Complex_Double_t *a1, CMatrix_z_t x1, Complex_Double_t *a2, CMatrix_z_t x2);
  extern void __cmat_z_MOD_c2f(CMatrix_z_t x, Matrix_z_t *fmat);
  extern void __cmat_z_MOD_dot(Complex_Double_t *y, CMatrix_z_t x1, CMatrix_z_t x2);
  extern void __cmat_z_MOD_eye(CMatrix_z_t x);
  extern void __cmat_z_MOD_fill(CMatrix_z_t x, Complex_Double_t *val, uint64_t *r1, uint64_t *r2, uint64_t *c1, uint64_t *c2);
  extern void __cmat_z_MOD_mul(CMatrix_z_t y, CMatrix_z_t x1, CMatrix_z_t x2);
  extern void __cmat_z_MOD_pow(CMatrix_z_t y, CMatrix_z_t x, Complex_Double_t *n);
  extern void __cmat_z_MOD_reshape(CMatrix_z_t x, uint64_t *n1, uint64_t *n2);
  extern void __cmat_z_MOD_show_named(CMatrix_z_t x, size_t n, char *name);
  extern void __cmat_z_MOD_show_named2(Matrix_z_t x, size_t n, char *name);
  extern void __cmat_z_MOD_trace(CMatrix_z_t x, Complex_Double_t *y);
  extern void __cmat_z_MOD_transpose_in_place(CMatrix_z_t x);


  extern void __cmat_z_MOD_svd(CMatrix_z_t x, CMatrix_z_t s, CMatrix_z_t vt);


#ifdef __cplusplus
}
#endif

  status_t cmat_z_init(CMatrix_z_t *mat, int64_t n1, int64_t n2);

  status_t cmat_z_use(CMatrix_z_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */