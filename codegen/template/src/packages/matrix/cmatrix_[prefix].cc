/* cmatrix_{{prefix}}.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * {{notice}}
 */

#include "packages/matrix/matrix_{{prefix}}.h"

#include <stdio.h>
#include <stdlib.h>

  status_t cmat_{{prefix}}_init(CMatrix_{{prefix}}_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_{{prefix}}_t*>(calloc(1,sizeof(XMatrix_{{prefix}}_t)));
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<{{ctype}} *>(calloc(n, sizeof({{ctype}})));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_use(CMatrix_{{prefix}}_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<{{ctype}} *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

/* *EOF* */
