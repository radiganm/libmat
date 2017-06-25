/* cmatrix_s.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "packages/matrix/matrix_s.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

  status_t cmat_s_bind(CMatrix_s_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_s_t*>(buffer);
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(*mat);
    x.data = reinterpret_cast<float *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_s_submat(CMatrix_s_t submat, CMatrix_s_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_s_t &full = *reinterpret_cast<XMatrix_s_t *>(mat);
    XMatrix_s_t &sub = *reinterpret_cast<XMatrix_s_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<float *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_s_serialize(CMatrix_s_t mat, void *buffer)
  {
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(float) * n + sizeof(XMatrix_s_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_s_deserialize(CMatrix_s_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_s_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(float) * n;
    x.data = reinterpret_cast<float *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_s_read(CMatrix_s_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_s_t));
      if(n_bytes != sizeof(XMatrix_s_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(float) * n;
    x.data = reinterpret_cast<float *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_s_write(CMatrix_s_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_s_t &x = *reinterpret_cast<XMatrix_s_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_s_t));
      if(n_bytes != sizeof(XMatrix_s_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(float) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */