!! mat.f90
!! Copyright 2016 Mac Radigan
!! All Rights Reserved
!! {{notice}}

  module mat

    use iso_c_binding
    implicit none
    
    type(integer), parameter                     :: MAT_MAX_DIMS = 7

    type :: MatrixInfo
      type(integer*4)                            :: type
      type(integer*4)                            :: n_dims
      type(integer*8), dimension(MAT_MAX_DIMS)   :: dims
    end type

  contains

  end module mat

!! *EOF*
