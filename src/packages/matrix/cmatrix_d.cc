/* cmatrix_d.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "packages/matrix/matrix_d.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

  status_t cmat_d_init(CMatrix_d_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_d_t*>(calloc(1,sizeof(XMatrix_d_t)));
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<double *>(calloc(n, sizeof(double)));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_d_use(CMatrix_d_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<double *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_d_bind(CMatrix_d_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_d_t*>(buffer);
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(*mat);
    x.data = reinterpret_cast<double *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_d_submat(CMatrix_d_t submat, CMatrix_d_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_d_t &full = *reinterpret_cast<XMatrix_d_t *>(mat);
    XMatrix_d_t &sub = *reinterpret_cast<XMatrix_d_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<double *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_d_serialize(CMatrix_d_t mat, void *buffer)
  {
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(double) * n + sizeof(XMatrix_d_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_d_deserialize(CMatrix_d_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_d_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(double) * n;
    x.data = reinterpret_cast<double *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_d_read(CMatrix_d_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_d_t));
      if(n_bytes != sizeof(XMatrix_d_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(double) * n;
    x.data = reinterpret_cast<double *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_d_write(CMatrix_d_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_d_t &x = *reinterpret_cast<XMatrix_d_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_d_t));
      if(n_bytes != sizeof(XMatrix_d_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(double) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */