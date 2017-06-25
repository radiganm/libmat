/* cmatrix_z.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "packages/matrix/matrix_z.h"

#include "packages/allocate/allocate.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

  status_t cmat_z_init(CMatrix_z_t *mat, int64_t n1, int64_t n2)
  {
    *mat = reinterpret_cast<XMatrix_z_t*>(calloc(1,sizeof(XMatrix_z_t)));
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(*mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<Complex_Double_t *>(calloc(n, sizeof(Complex_Double_t)));
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_z_use(CMatrix_z_t mat, int64_t n1, int64_t n2, void *buffer)
  {
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(mat);
    const size_t n = n1 * n2;
    x.data = reinterpret_cast<Complex_Double_t *>(buffer);
    x.info.n_dims = 2;
    x.info.dims[0] = n1;
    x.info.dims[1] = n2;
    return Status::SUCCESS;
  }

  status_t cmat_z_bind(CMatrix_z_t *mat, void *buffer)
  {
    *mat = reinterpret_cast<XMatrix_z_t*>(buffer);
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(*mat);
    x.data = reinterpret_cast<Complex_Double_t *>(*mat+1);
    return Status::SUCCESS;
  }

  status_t cmat_z_submat(CMatrix_z_t submat, CMatrix_z_t mat, uint64_t r1, uint64_t r2, uint64_t c1, uint64_t c2)
  {
    XMatrix_z_t &full = *reinterpret_cast<XMatrix_z_t *>(mat);
    XMatrix_z_t &sub = *reinterpret_cast<XMatrix_z_t *>(submat);
    const size_t off = full.info.dims[1] * c1 + r1;
    sub.data = reinterpret_cast<Complex_Double_t *>(full.data) + off;
    sub.info.n_dims = 2;
    sub.info.dims[0] = r2 - r1;
    sub.info.dims[1] = c2 - c1;
    return Status::SUCCESS;
  }

  status_t cmat_z_serialize(CMatrix_z_t mat, void *buffer)
  {
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(mat);
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Double_t) * n + sizeof(XMatrix_z_t);
    memcpy(buffer, reinterpret_cast<void *>(mat), size);
    return Status::SUCCESS;
  }

  status_t cmat_z_deserialize(CMatrix_z_t mat, void *buffer, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(mat);
    memcpy(reinterpret_cast<void *>(mat), buffer, sizeof(XMatrix_z_t));
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Double_t) * n;
    x.data = reinterpret_cast<Complex_Double_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    memcpy(reinterpret_cast<void *>(x.data), buffer, size);
    return Status::SUCCESS;
  }

  status_t cmat_z_read(CMatrix_z_t mat, int fd, fn_alloc_t alloc)
  {
    ssize_t n_bytes;
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(mat);
    n_bytes = read(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_z_t));
      if(n_bytes != sizeof(XMatrix_z_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Double_t) * n;
    x.data = reinterpret_cast<Complex_Double_t *>(alloc(size));
      if(NULL == x.data) return Status::FAILURE;
    n_bytes = read(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

  status_t cmat_z_write(CMatrix_z_t mat, int fd)
  {
    ssize_t n_bytes;
    XMatrix_z_t &x = *reinterpret_cast<XMatrix_z_t *>(mat);
    n_bytes = write(fd, reinterpret_cast<void *>(mat), sizeof(XMatrix_z_t));
      if(n_bytes != sizeof(XMatrix_z_t)) return Status::FAILURE;
    const size_t n = x.info.dims[0] * x.info.dims[1];
    const size_t size = sizeof(Complex_Double_t) * n;
    n_bytes = write(fd, reinterpret_cast<void *>(x.data), size);
      if(n_bytes != size) return Status::FAILURE;
    return Status::SUCCESS;
  }

/* *EOF* */