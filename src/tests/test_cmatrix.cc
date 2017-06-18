/* test_cmatrix.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "./packages/matrix/cmatrix_z.h"
#include "./packages/matrix/cmatrix_d.h"
#include <stdio.h>
#include <cstdlib>
#include <string.h>

  int main(int argc, char *argv[])
  {
    status_t status = Status::SUCCESS;
    int64_t n = 2;
    int64_t n1 = 2;
    int64_t n2 = 2;
    const char *nx1 = "X1";
    const char *nx2 = "X2";
    char ny[256];
    double a1 = 2;
    double a2 = 3;
    CMatrix_d_t y;
    CMatrix_d_t x1;
    CMatrix_d_t x2;
    status = cmat_d_init(&x1, n1, n2);
    status = cmat_d_init(&x2, n1, n2);
    status = cmat_d_init(&y, n1, n2);
    __cmat_d_MOD_eye(x1);
    __cmat_d_MOD_eye(x2);
    __cmat_d_MOD_eye(y);
    __cmat_d_MOD_show_named(x1, strlen(nx1), const_cast<char *>(nx1));
#if 0
    __cmat_d_MOD_show_named(x2, strlen(nx2), const_cast<char *>(nx2));
    strcpy(ny, "Y = X1 + X2");
    __cmat_d_MOD_add(y, x1, x2);
    __cmat_d_MOD_show_named(y,  strlen(ny),  const_cast<char *>(ny));
    strcpy(ny, "Y = X1 * X2");
    __cmat_d_MOD_mul(y, x1, x2);
    __cmat_d_MOD_show_named(y,  strlen(ny),  const_cast<char *>(ny));
    strcpy(ny, "Y = a2*X1 + a2*X2");
    __cmat_d_MOD_axby(y, &a1, x1, &a2, x2);
    __cmat_d_MOD_show_named(y,  strlen(ny),  const_cast<char *>(ny));

    CMatrix_d_t u;
    CMatrix_d_t vt;
    status = cmat_d_init(&y, n1, n2);
    status = cmat_d_init(&vt, n1, n2);
    __cmat_d_MOD_svd(y, u, vt);
    strcpy(ny, "Y = SVD(x1)");
    __cmat_d_MOD_show_named(y,  strlen(ny),  const_cast<char *>(ny));
#endif

    return status;
  }

/* *EOF* */
