/* cmatrix_u8.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-18 00:39:00 by dox.
 */

#include "packages/matrix/matrix_u8.h"

#include <stdio.h>
#include <stdlib.h>

  status_t cmat_u8_init(CMatrix_u8_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_u8_t*>(calloc(1,sizeof(XMatrix_u8_t)));
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<uint8_t *>(calloc(n, sizeof(uint8_t)));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_u8_use(CMatrix_u8_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<uint8_t *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

/* *EOF* */