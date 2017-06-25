## makefile.am
## Copyright 2016 Mac Radigan
## All Rights Reserved

AM_LDFLAGS  = -pthread                                                         \
              -L/usr/lib -ldl -lm                                              \
              /usr/lib/libblas.a                                               \
              /usr/lib/liblapack.a                                             \
              -L/usr/lib/gcc/x86_64-linux-gnu/5 -lquadmath                     \
              -L/usr/lib/gcc/x86_64-linux-gnu/5 -lgfortran                     \
              /usr/lib/gcc/x86_64-linux-gnu/5/libatomic.a                      \
              /usr/lib/x86_64-linux-gnu/libgmp.a                               \
              /usr/lib/x86_64-linux-gnu/libcurses.a                            \
              ./submodules/dispmodule/lib/libdispmodule.a                       

AM_CPPFLAGS = -I$(top_srcdir)/include                                          \
              -std=c++11
AM_FCFLAGS  = -Jmod -fexternal-blas

mat_ldadd                 = libmat.la                                          \
                           /usr/lib/libblas.a                                  \
                           /usr/lib/liblapack.a                                \
                           /usr/lib/gcc/x86_64-linux-gnu/5/libatomic.a         \
                           /usr/lib/x86_64-linux-gnu/libanl.a                  \
                           /usr/lib/x86_64-linux-gnu/libgmp.a                  \
                           /usr/lib/x86_64-linux-gnu/libcurses.a               \
                           ./submodules/dispmodule/lib/libdispmodule.a         \
                           -ldl -lm                                            \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lanl             \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lgmp             \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -latomic          \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lcurses          \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lquadmath        \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lgfortran

bin_PROGRAMS             = test_cmatrix                                        \
                           test_tmatrix

test_cmatrix_SOURCES     = src/tests/test_cmatrix.cc
test_cmatrix_LDADD       = $(mat_ldadd)

test_tmatrix_SOURCES     = src/tests/test_tmatrix.cc
test_tmatrix_LDADD       = $(mat_ldadd)

lib_LTLIBRARIES          = libmat.la
libmat_la_SOURCES        = src/packages/common/status.cc                       \
                           src/packages/matrix/mat.f90                         \
                           src/packages/matrix/matrix.cc                       \
                           src/packages/matrix/cmatrix_d.cc                    \
                           src/packages/matrix/cmatrix_z.cc                    \
                           src/packages/matrix/cmatrix_c.cc                    \
                           src/packages/matrix/cmatrix_s.cc                    \
                           src/packages/matrix/cmatrix_u8.cc                   \
                           src/packages/matrix/cmatrix_u16.cc                  \
                           src/packages/matrix/mat.f90                         \
                           src/packages/matrix/cmat_z.f90                      \
                           src/packages/matrix/cmat_d.f90                      \
                           src/packages/matrix/cmat_c.f90                      \
                           src/packages/matrix/cmat_s.f90                      \
                           src/packages/matrix/cmat_u8.f90                     \
                           src/packages/matrix/cmat_u16.f90      
libmat_la_LIBADD         = -lz                                                 \
                           -lrt                                                \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lquadmath        \
                           -L/usr/lib/gcc/x86_64-linux-gnu/5 -lgfortran        

libmat_la_LDFLAGS        = -export-symbols-regex '^mat_[^_]' -fPIC             \
                           -fexternal-blas                                     \
                           -shared -pthread                                    \
                           /usr/lib/gcc/x86_64-linux-gnu/5/libatomic.a         \
                           /usr/lib/x86_64-linux-gnu/libanl.a                  \
                           /usr/lib/x86_64-linux-gnu/libgmp.a                  \
                           /usr/lib/x86_64-linux-gnu/libcurses.a               \
                           ./submodules/dispmodule/lib/libdispmodule.a         \
                           ./submodules/dispmodule/lib/libdispmodule.a          

pkginclude_HEADERS       = include/packages/common/status.h                    \
                           include/packages/common/thread.h                    \
                           include/packages/matrix/atomic_mat2.h               \
                           include/packages/matrix/matrix.h                    \
                           include/packages/matrix/matrix_z.h                  \
                           include/packages/matrix/matrix_d.h                  \
                           include/packages/matrix/matrix_c.h                  \
                           include/packages/matrix/matrix_s.h                  \
                           include/packages/matrix/matrix_u8.h                 \
                           include/packages/matrix/matrix_u16.h                \
                           include/packages/matrix/cmatrix_z.h                 \
                           include/packages/matrix/cmatrix_d.h                 \
                           include/packages/matrix/cmatrix_c.h                 \
                           include/packages/matrix/cmatrix_s.h                 \
                           include/packages/matrix/cmatrix_u8.h                \
                           include/packages/matrix/cmatrix_u16.h               \
                           include/packages/tmatrix/tmat.h                     \
                           include/packages/tmatrix/tmat_z.h                   \
                           include/packages/tmatrix/tmat_d.h                   \
                           include/packages/tmatrix/tmat_c.h                   \
                           include/packages/tmatrix/tmat_z.h                   \
                           include/packages/tmatrix/tmat_s.h                   \
                           include/packages/tmatrix/tmat_u8.h                  \
                           include/packages/tmatrix/tmat_u16.h                  

## *EOF* 
