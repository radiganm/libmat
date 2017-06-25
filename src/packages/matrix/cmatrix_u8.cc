/* cmatrix_u8.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "packages/matrix/matrix_u8.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

  status_t cmat_u8_bind(CMatrix_u8_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_u8_t*>(buffer);
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(*mat);
    x.data = reinterpret_cast<uint8_t *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_u8_submat(CMatrix_u8_t submat, CMatrix_u8_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_u8_t &full = *reinterpret_cast<XMatrix_u8_t *>(mat);
    XMatrix_u8_t &sub = *reinterpret_cast<XMatrix_u8_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<uint8_t *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_u8_serialize(CMatrix_u8_t mat, void *buffer)
  {
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(uint8_t) * n + sizeof(XMatrix_u8_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_u8_deserialize(CMatrix_u8_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_u8_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(uint8_t) * n;
    x.data = reinterpret_cast<uint8_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_u8_read(CMatrix_u8_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_u8_t));
      if(n_bytes != sizeof(XMatrix_u8_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(uint8_t) * n;
    x.data = reinterpret_cast<uint8_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_u8_write(CMatrix_u8_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_u8_t &x = *reinterpret_cast<XMatrix_u8_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_u8_t));
      if(n_bytes != sizeof(XMatrix_u8_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(uint8_t) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */