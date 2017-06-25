/* cmatrix_{{prefix}}.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * {{notice}}
 */

#include "packages/matrix/matrix_{{prefix}}.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

  status_t cmat_{{prefix}}_bind(CMatrix_{{prefix}}_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_{{prefix}}_t*>(buffer);
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(*mat);
    x.data = reinterpret_cast<{{ctype}} *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_submat(CMatrix_{{prefix}}_t submat, CMatrix_{{prefix}}_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_{{prefix}}_t &full = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    XMatrix_{{prefix}}_t &sub = *reinterpret_cast<XMatrix_{{prefix}}_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<{{ctype}} *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_serialize(CMatrix_{{prefix}}_t mat, void *buffer)
  {
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof({{ctype}}) * n + sizeof(XMatrix_{{prefix}}_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_deserialize(CMatrix_{{prefix}}_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_{{prefix}}_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof({{ctype}}) * n;
    x.data = reinterpret_cast<{{ctype}} *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_read(CMatrix_{{prefix}}_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_{{prefix}}_t));
      if(n_bytes != sizeof(XMatrix_{{prefix}}_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof({{ctype}}) * n;
    x.data = reinterpret_cast<{{ctype}} *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_{{prefix}}_write(CMatrix_{{prefix}}_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_{{prefix}}_t &x = *reinterpret_cast<XMatrix_{{prefix}}_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_{{prefix}}_t));
      if(n_bytes != sizeof(XMatrix_{{prefix}}_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof({{ctype}}) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */
