/* cmatrix_{{prefix}}.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * {{notice}}
 */

#include "../common/status.h"
#include "../matrix/matrix_{{prefix}}.h"
#include <stdlib.h>
#include <inttypes.h>

#ifndef cmatrix_{{prefix}}_h
#define cmatrix_{{prefix}}_h

#ifdef __cplusplus
extern "C" {
#endif

  extern void __cmat_{{prefix}}_MOD_add(CMatrix_{{prefix}}_t y, CMatrix_{{prefix}}_t x1, CMatrix_{{prefix}}_t x2);
  extern void __cmat_{{prefix}}_MOD_axby(CMatrix_{{prefix}}_t y, {{ctype}} *a1, CMatrix_{{prefix}}_t x1, {{ctype}} *a2, CMatrix_{{prefix}}_t x2);
  extern void __cmat_{{prefix}}_MOD_c2f(CMatrix_{{prefix}}_t x, Matrix_{{prefix}}_t *fmat);
  extern void __cmat_{{prefix}}_MOD_dot({{ctype}} *y, CMatrix_{{prefix}}_t x1, CMatrix_{{prefix}}_t x2);
  extern void __cmat_{{prefix}}_MOD_eye(CMatrix_{{prefix}}_t x);
  extern void __cmat_{{prefix}}_MOD_fill(CMatrix_{{prefix}}_t x, {{ctype}} *val, uint64_t *r1, uint64_t *r2, uint64_t *c1, uint64_t *c2);
  extern void __cmat_{{prefix}}_MOD_mul(CMatrix_{{prefix}}_t y, CMatrix_{{prefix}}_t x1, CMatrix_{{prefix}}_t x2);
  extern void __cmat_{{prefix}}_MOD_pow(CMatrix_{{prefix}}_t y, CMatrix_{{prefix}}_t x, {{ctype}} *n);
  extern void __cmat_{{prefix}}_MOD_reshape(CMatrix_{{prefix}}_t x, uint64_t *n1, uint64_t *n2);
  extern void __cmat_{{prefix}}_MOD_show_named(CMatrix_{{prefix}}_t x, size_t n, char *name);
  extern void __cmat_{{prefix}}_MOD_show_named2(Matrix_{{prefix}}_t x, size_t n, char *name);
  extern void __cmat_{{prefix}}_MOD_trace(CMatrix_{{prefix}}_t x, {{ctype}} *y);
  extern void __cmat_{{prefix}}_MOD_transpose_in_place(CMatrix_{{prefix}}_t x);

{% if fclass[:3] != 'int' %}
  extern void __cmat_{{prefix}}_MOD_svd(CMatrix_{{prefix}}_t x, CMatrix_{{prefix}}_t s, CMatrix_{{prefix}}_t vt);
{% endif %}

#ifdef __cplusplus
}
#endif

  status_t cmat_{{prefix}}_init(CMatrix_{{prefix}}_t *mat, int64_t n1, int64_t n2);

  status_t cmat_{{prefix}}_use(CMatrix_{{prefix}}_t mat, int64_t n1, int64_t n2, void *buffer);

#endif

/* *EOF* */
