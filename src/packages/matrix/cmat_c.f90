!! cmat_c.f90
!! Copyright 2016 Mac Radigan
!! All Rights Reserved
!! NOTICE:  This source file was automatically generated on 2017-06-25 03:25:54 by dox.

  module cmat_c

    use mat
    use dispmodule
    use iso_c_binding
    implicit none

    type :: CMatrix_c
      type(c_ptr)                                :: data
      type(MatrixInfo)                           :: info
    end type

    public  :: add
    public  :: axby
    public  :: c2f
    public  :: dot
    public  :: eye
    public  :: fill
    public  :: mul
    public  :: pow
    public  :: reshape
    public  :: show_named
    public  :: show_named2
    public  :: trace
    public  :: transpose_in_place

    public  :: svd


  contains

    subroutine add(y,x1,x2)
      
      type(CMatrix_c), intent(inout)        :: y
      type(CMatrix_c), intent(inout)        :: x1
      type(CMatrix_c), intent(inout)        :: x2
      type(complex*8), pointer                 :: b(:)
      type(complex*8), pointer                 :: a1(:)
      type(complex*8), pointer                 :: a2(:)
      type(integer*8)                       :: k
      type(integer*8)                                :: N 
      N = y%info%dims(1)*y%info%dims(2)
      call c_f_pointer(y%data,  b,  [N])
      call c_f_pointer(x1%data, a1, [N])
      call c_f_pointer(x2%data, a2, [N])
      forall(k=1:N) b(k) = a1(k) + a2(k)
      
    end subroutine add

    subroutine axby(y,a1,x1,a2,x2)
      
      type(CMatrix_c), intent(inout)        :: y
      type(complex*8), intent(in)                    :: a1
      type(CMatrix_c), intent(inout)        :: x1
      type(complex*8), intent(in)                    :: a2
      type(CMatrix_c), intent(inout)        :: x2
      type(complex*8), pointer                       :: p(:)
      type(complex*8), pointer                       :: p1(:)
      type(complex*8), pointer                       :: p2(:)
      type(integer*8)                                :: k
      type(integer*8)                                :: N 
      N = y%info%dims(1)*y%info%dims(2)
      call c_f_pointer(y%data,  p,  [N])
      call c_f_pointer(x1%data, p1, [N])
      call c_f_pointer(x2%data, p2, [N])
      forall(k=1:N) p(k) = a1*p1(k) + a2*p2(k)
      
    end subroutine axby

    subroutine c2f(x, p)
      
      type(CMatrix_c), intent(in)           :: x
      type(complex*8), pointer, intent(inout)  :: p(:,:)
      type(integer*8)                       :: k
      call c_f_pointer(x%data, p, [x%info%dims(1), x%info%dims(2)])
      
    end subroutine c2f

    subroutine dot(y,x1,x2)
      
      type(complex*8), intent(out)                   :: y
      type(CMatrix_c), intent(inout)        :: x1
      type(CMatrix_c), intent(inout)        :: x2
      type(complex*8), pointer                       :: p1(:)
      type(complex*8), pointer                       :: p2(:)
      type(integer*8)                                :: N 
      N = x1%info%dims(1)*x1%info%dims(2)
      call c_f_pointer(x1%data, p1, [N])
      call c_f_pointer(x2%data, p2, [N])
      y = dot_product(p1,p2)
      
    end subroutine dot

    subroutine eye(x)
      
      type(CMatrix_c), intent(inout)        :: x
      type(complex*8), pointer                       :: p(:,:)
      type(integer*8)                                :: k
      call c_f_pointer(x%data, p, [x%info%dims(1), x%info%dims(2)])
      forall(k=1:maxval(x%info%dims)) p(k,k) = 1.0
      
    end subroutine eye

    subroutine fill(x, val, r1, r2, c1, c2)
      
      type(CMatrix_c), intent(inout)        :: x
      type(complex*8), pointer                       :: p(:,:)
      type(complex*8), intent(in)                    :: val
      type(integer*8), intent(in)                    :: r1
      type(integer*8), intent(in)                    :: r2
      type(integer*8), intent(in)                    :: c1
      type(integer*8), intent(in)                    :: c2
      type(integer*8)                                :: r
      type(integer*8)                                :: c
      call c_f_pointer(x%data, p, [x%info%dims(1), x%info%dims(2)])
      forall(r=r1:r2, c=c1:c2) p(r+1,c+1) = val
      
    end subroutine fill

    subroutine mul(y,x1,x2)
      
      type(CMatrix_c), intent(inout)        :: y
      type(CMatrix_c), intent(inout)        :: x1
      type(CMatrix_c), intent(inout)        :: x2
      type(complex*8), pointer                       :: p(:,:)
      type(complex*8), pointer                       :: p1(:,:)
      type(complex*8), pointer                       :: p2(:,:)
      call c_f_pointer(y%data,  p,  [y%info%dims(1),  y%info%dims(2)])
      call c_f_pointer(x1%data, p1, [x1%info%dims(1), x1%info%dims(2)])
      call c_f_pointer(x2%data, p2, [x2%info%dims(1), x2%info%dims(2)])
      p = matmul(p1,p2) ! NB. compiling with -fexternal-blas converts this call to DGEMM
      
    end subroutine mul

    subroutine pow(y, x, n)
      
      type(CMatrix_c), intent(inout)        :: y
      type(CMatrix_c), intent(inout)        :: x
      type(complex*8), pointer                       :: a(:,:)
      type(complex*8), pointer                       :: b(:,:)
      type(complex*8), intent(in)                    :: n
      type(integer*8)                                :: k1
      type(integer*8)                                :: k2
      type(integer*8)                                :: k
      type(integer*8)                                :: r
      type(integer*8)                                :: c
      call c_f_pointer(x%data, a, [x%info%dims(1), x%info%dims(2)])
      call c_f_pointer(y%data, b, [y%info%dims(1), y%info%dims(2)])
      if (0 == int(real(n))) then
        forall(r=1:x%info%dims(1), c=1:x%info%dims(2)) b(r,c) = 1.0
        return
      end if
      do k = 1, int(real(n))
        b = matmul(b, a)
      end do
      
    end subroutine pow

    subroutine reshape(x, n1, n2)
      
      type(CMatrix_c), intent(inout)        :: x
      type(integer*8), intent(in)                    :: n1
      type(integer*8), intent(in)                    :: n2
      type(complex*8), pointer                       :: p(:,:)
      call c_f_pointer(x%data,  p,  [x%info%dims(1),  x%info%dims(2)])
      x%info%dims(1) = n1
      x%info%dims(2) = n2
      
    end subroutine reshape

    subroutine show_named(x, sname_length, sname)
      
      type(CMatrix_c), intent(in)             :: x
      type(complex*8), pointer                         :: p(:,:)
      integer(c_size_t), intent(in), value             :: sname_length
      type(c_ptr), intent(in), value                   :: sname
      character(kind=c_char,len=sname_length), pointer :: xname
      type(disp_settings)                              :: ds
      call c_f_pointer(x%data, p, [x%info%dims(1), x%info%dims(2)])
      ds = disp_get()
     !call disp_set_factory
     !call disp_set(unit=8)
      call disp_set(zeroas='*')
      call disp_set(digmax=5)
      call disp_set(style='-pad')
      call disp_set(matsep=' | ')
      call c_f_pointer(sname, xname)

      call disp(xname, p)

      
    end subroutine show_named

    subroutine show_named2(p, sname_length, sname)
      
      type(complex*8), pointer, intent(in)                :: p(:,:)
      integer(c_size_t), intent(in), value             :: sname_length
      type(c_ptr), intent(in), value                   :: sname
      character(kind=c_char,len=sname_length), pointer :: xname
      type(disp_settings)                              :: ds
      ds = disp_get()
     !call disp_set_factory
     !call disp_set(unit=8)
      call disp_set(zeroas='*')
      call disp_set(digmax=5)
      call disp_set(style='-pad')
      call disp_set(matsep=' | ')
      call c_f_pointer(sname, xname)

      call disp(xname, p)


    end subroutine show_named2

    subroutine trace(x, y)
      
      type(CMatrix_c), intent(in)           :: x
      type(complex*8), intent(out)                   :: y
      type(complex*8), pointer                       :: p(:,:)
      type(integer*8)                                :: k
      call c_f_pointer(x%data,  p,  [x%info%dims(1),  x%info%dims(2)])
      y = 0
      do k=1,maxval(x%info%dims) 
        y = y + p(k,k)
      enddo
      
    end subroutine trace

    subroutine transpose_in_place(x)
      
      type(CMatrix_c), intent(inout)        :: x
      type(complex*8), pointer                       :: p(:,:)
      call c_f_pointer(x%data, p, [x%info%dims(1), x%info%dims(2)])
      p = transpose(p)
      
    end subroutine transpose_in_place


    subroutine svd(x, s, vt)
      
      type(integer), parameter                      :: lwork = 0
      type(CMatrix_c), intent(inout)        :: x
      type(complex*8), pointer                       :: p(:,:)
      type(integer)                                  :: rwork
      type(integer)                                  :: info
      type(complex*8), dimension(:,:), allocatable   :: work(:,:)
      type(complex*8), dimension(:,:), allocatable   :: s(:,:)
      type(complex*8), dimension(:,:), allocatable   :: vt(:,:)
      type(complex*8), dimension(:,:), allocatable   :: u(:,:)
      type(integer)                                  :: m
      type(integer)                                  :: n
      call c_f_pointer(x%data,  p,  [x%info%dims(1),  x%info%dims(2)])
      m = x%info%dims(1)
      n = x%info%dims(2)
      rwork = 5 * minval(x%info%dims) 
      call cgesvd('A','A',m,n,p,m,s,u,m,vt,m,work,lwork,rwork,info)
      
    end subroutine svd


  end module cmat_c

!! *EOF*