/* tmat_s.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 * NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.
 */

#include "./packages/tmatrix/tmat.h"

#include "./packages/matrix/matrix_s.h"
#include "./packages/matrix/cmatrix_s.h"
#include "./packages/allocate/allocate.h"

#include <cmath>
#include <mutex>
#include <string.h>

#ifndef tmat_s_h
#define tmat_s_h

  template<>
  class TMat<float>
  {
    public:
      
      TMat(const uint64_t n1, const uint64_t n2) 
      {
        const size_t n = n1 * n2;
        const size_t size = n * sizeof(float) + sizeof(XMatrix_s_t);
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
        __cmat_s_MOD_show_named(mat, strlen(name), const_cast<char *>(name));
      }
      
      inline static TMat<float> &eye(const uint64_t n)
      {
        TMat<float> *p;
        p = new TMat<float>(n, n);
        __cmat_s_MOD_eye(p->mat);
        return *p;
      }
      
      inline status_t use(void* buffer, const uint64_t n1, const uint64_t n2)
      {
        mat = reinterpret_cast<CMatrix_s_t>(buffer);
        mat->data = reinterpret_cast<float *>(reinterpret_cast<unsigned char *>(buffer) + sizeof(XMatrix_s_t));
        mat->info.n_dims  = 2;
        mat->info.dims[0] = n1;
        mat->info.dims[1] = n2;
        index = reinterpret_cast<float**>(malloc(n2 * sizeof(float**)));
        for(int k=0; k<n2; ++k) index[k] = &mat->data[k * n1];
      }

    protected:
      

    private:
      
      float            *data;
      float           **index;
      CMatrix_s_t  mat;

  };

  void tmat_s__FORCE_IMPL()
  {
    const uint64_t n1 = 2;
    const uint64_t n2 = 2;
    TMat<double> x(n1, n2);
  }

#endif