/* cmatrix_c.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "packages/matrix/matrix_c.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

  status_t cmat_c_init(CMatrix_c_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_c_t*>(calloc(1,sizeof(XMatrix_c_t)));
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<Complex_Single_t *>(calloc(n, sizeof(Complex_Single_t)));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_c_use(CMatrix_c_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<Complex_Single_t *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_c_bind(CMatrix_c_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_c_t*>(buffer);
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(*mat);
    x.data = reinterpret_cast<Complex_Single_t *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_c_submat(CMatrix_c_t submat, CMatrix_c_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_c_t &full = *reinterpret_cast<XMatrix_c_t *>(mat);
    XMatrix_c_t &sub = *reinterpret_cast<XMatrix_c_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<Complex_Single_t *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_c_serialize(CMatrix_c_t mat, void *buffer)
  {
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Single_t) * n + sizeof(XMatrix_c_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_c_deserialize(CMatrix_c_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_c_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Single_t) * n;
    x.data = reinterpret_cast<Complex_Single_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_c_read(CMatrix_c_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_c_t));
      if(n_bytes != sizeof(XMatrix_c_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Single_t) * n;
    x.data = reinterpret_cast<Complex_Single_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_c_write(CMatrix_c_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_c_t &x = *reinterpret_cast<XMatrix_c_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_c_t));
      if(n_bytes != sizeof(XMatrix_c_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Single_t) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */