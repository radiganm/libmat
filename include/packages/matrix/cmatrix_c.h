/* cmatrix_c.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "../common/status.h"
#include "../matrix/matrix_c.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_c_h
#define cmatrix_c_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_c_MOD_add(CMatrix_c_t y, CMatrix_c_t x1, CMatrix_c_t x2);

  extern void __cmat_c_MOD_axby(CMatrix_c_t y, Complex_Single_t *a1, CMatrix_c_t x1, Complex_Single_t *a2, CMatrix_c_t x2);

  extern void __cmat_c_MOD_mul(CMatrix_c_t y, CMatrix_c_t x1, CMatrix_c_t x2);

  extern void __cmat_c_MOD_dot(Complex_Single_t *y, CMatrix_c_t x1, CMatrix_c_t x2);

  extern void __cmat_c_MOD_transpose_in_place(CMatrix_c_t x);

  extern void __cmat_c_MOD_reshape(CMatrix_c_t x, uint64_t *n1, uint64_t *n2);

  extern void __cmat_c_MOD_trace(CMatrix_c_t x, Complex_Single_t *y);

  extern void __cmat_c_MOD_c2f(CMatrix_c_t x, Matrix_c_t *fmat);

  extern void __cmat_c_MOD_show_named2(Matrix_c_t x, size_t n, char *name);

  extern void __cmat_c_MOD_eye(CMatrix_c_t x);

  extern void __cmat_c_MOD_show_named(CMatrix_c_t x, size_t n, char *name);


  extern void __cmat_c_MOD_svd(CMatrix_c_t x, CMatrix_c_t s, CMatrix_c_t vt);


#ifdef __cplusplus
}
#endif

  status_t cmat_c_init(CMatrix_c_t *mat, int64_t n1, int64_t n2);

  status_t cmat_c_use(CMatrix_c_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */