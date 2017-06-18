/* cmatrix_s.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "packages/matrix/matrix_s.h"

#include <stdio.h>
#include <stdlib.h>

  status_t cmat_s_init(CMatrix_s_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_s_t*>(calloc(1,sizeof(XMatrix_s_t)));
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<float *>(calloc(n, sizeof(float)));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_s_use(CMatrix_s_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<float *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

/* *EOF* */