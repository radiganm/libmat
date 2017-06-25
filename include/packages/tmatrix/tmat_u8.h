/* tmat_u8.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "./packages/tmatrix/tmat.h"

#include "./packages/matrix/matrix_u8.h"
#include "./packages/matrix/cmatrix_u8.h"
#include "./packages/allocate/allocate.h"

#include <cmath>
#include <mutex>
#include <string.h>

#ifndef tmat_u8_h
#define tmat_u8_h

  template<>
  class TMat<uint8_t>
  {
    public:
      
      TMat(const uint64_t n1, const uint64_t n2) 
      {
        const size_t n = n1 * n2;
        const size_t size = n * sizeof(uint8_t) + sizeof(XMatrix_u8_t);
        //fn_alloc_t fn_malloc = malloc;
        //void *p = fn_malloc(size);
        void *p = malloc(size);
        memset(p, 0, size);
        use(p, n1, n2);
      };
      
      virtual ~TMat() {};
      
      inline uint64_t dims(const uint64_t id) { return mat->info.dims[id]; };
      
      inline uint64_t numel()
      {
        return mat->info.dims[0] * mat->info.dims[1];
      }
      
      inline void disp(const char *name)
      {
        __cmat_u8_MOD_show_named(mat, strlen(name), const_cast<char *>(name));
      }
      
      inline static TMat<uint8_t> &eye(const uint64_t n)
      {
        TMat<uint8_t> *p;
        p = new TMat<uint8_t>(n, n);
        __cmat_u8_MOD_eye(p->mat);
        return *p;
      }
      
      inline status_t use(void* buffer, const uint64_t n1, const uint64_t n2)
      {
        mat = reinterpret_cast<CMatrix_u8_t>(buffer);
        mat->data = reinterpret_cast<uint8_t *>(reinterpret_cast<unsigned char *>(buffer) + sizeof(XMatrix_u8_t));
        mat->info.n_dims  = 2;
        mat->info.dims[0] = n1;
        mat->info.dims[1] = n2;
        index = reinterpret_cast<uint8_t**>(malloc(n2 * sizeof(uint8_t**)));
        for(int k=0; k<n2; ++k) index[k] = &mat->data[k * n1];
      }

    protected:
      

    private:
      
      uint8_t            *data;
      uint8_t           **index;
      CMatrix_u8_t  mat;

  };

  void tmat_u8__FORCE_IMPL()
  {
    const uint64_t n1 = 2;
    const uint64_t n2 = 2;
    TMat<double> x(n1, n2);
  }

#endif