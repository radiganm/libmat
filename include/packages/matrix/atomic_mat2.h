/* atomic_mat2.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "./packages/matrix/cmatrix_z.h"

#include <cmath>
#include <mutex>
#include <string.h>

#ifndef atomic_mat2_h
#define atomic_mat2_h

  #define CLIP_HI(x) ( (x < 255) ? x : 255 )
  #define CLIP_LO(x) ( (x >   0) ? x :   0 )
  #define EPS (2e-16)

  template<typename T>
  class Atomic_Mat2
  {
    public:

      Atomic_Mat2(T *mat, uint64_t n1, uint64_t n2);

      Atomic_Mat2();

      virtual ~Atomic_Mat2();

      inline uint64_t dims(uint64_t id) { return dim[id]; };

      inline uint64_t numel()
      {
        return dim[0] * dim[1];
      }

      inline status_t fill(T value)
      {
        std::lock_guard<std::mutex>(this->lock);
        for(int k=0; k<numel(); ++k)
        {
          data[k] = value;
        }
        return Status::SUCCESS;
      }

      inline status_t write_col(uint64_t col, T *buffer, size_t n)
      {
        std::lock_guard<std::mutex>(this->lock);
        memcpy(index[col], buffer, n * sizeof(T));
        for(int k=0; k<n; ++k)
        {
          const double x = log10(EPS + abs2<T>(index[col][k]));
          if(x > mx) { mx = x; };
          if(x < mn) { mn = x; };
        }
        return Status::SUCCESS;
      }

      inline status_t read_col(uint64_t col, T *buffer, size_t n)
      {
        std::lock_guard<std::mutex>(this->lock);
        memcpy(buffer, index[col], n * sizeof(T));
        return Status::SUCCESS;
      }

      inline status_t read(T *buffer, size_t n1, size_t n2)
      {
        std::lock_guard<std::mutex>(this->lock);
        memcpy(buffer, index[0], n1 * n2 * sizeof(T));
        return Status::SUCCESS;
      }

      inline status_t read_mat_remap(unsigned char *buffer, size_t n1, size_t n2)
      {
        std::lock_guard<std::mutex>(this->lock);
        const size_t N = n1*n2;
        const double m = 254/(mx-mn);
        const double b = mn;
        for(uint64_t k=0; k<N; ++k)
        {
          const double x = log10(EPS + abs2<T>(data[k]));
          buffer[k] = (int)ceil(m*(x-b));
        }
        return Status::SUCCESS;
      }

      inline status_t use(T *mat, uint64_t n1, uint64_t n2)
      {
        std::lock_guard<std::mutex>(this->lock);
        dim[0] = n1;
        dim[1] = n2;
        data  = reinterpret_cast<T*>(mat);
        index = reinterpret_cast<T**>(malloc(n2 * sizeof(T**)));
        for(int k=0; k<n2; ++k) index[k] = &data[k * n1];
        const size_t N = n1*n2;
        mx = std::numeric_limits<double>::min();
        mn = std::numeric_limits<double>::max();
        for(int k=0; k<N; ++k)
        {
          const double x = log10(EPS + abs2<T>(data[k]));
          if(x > mx) { mx = x; };
          if(x < mn) { mn = x; };
        }
        return Status::SUCCESS;
      }

      template<typename U>
      inline double abs2(Complex_Double_t x) { return sqrt(x.real*x.real + x.imag*x.imag); };

      template<typename U>
      inline double abs2(double x) { return x; };

    protected:

    private:
      uint64_t dim[2];
      T *data;
      T **index;
      std::mutex lock;
      double mx = std::numeric_limits<double>::min();
      double mn = std::numeric_limits<double>::max();
  };

  template<typename T>
  Atomic_Mat2<T>::Atomic_Mat2()
  {
  }

  template<typename T>
  Atomic_Mat2<T>::Atomic_Mat2(T *mat, uint64_t n1, uint64_t n2)
  {
    use(mat, n1, n2);
  }

  template<typename T>
  Atomic_Mat2<T>::~Atomic_Mat2()
  {
    //free(index);
  }

/*
  void __atomic_mat2__force_IMPL()
  {
    int64_t n = 5;
    Complex_Double_t *mat;
    Atomic_Mat2<Complex_Double_t> m_z(mat, n, n);
  }
*/

#endif
