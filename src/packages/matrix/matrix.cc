/* matrix.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "packages/matrix/matrix.h"

#include <inttypes.h>

  size_t sizeof_type(Type x)
  {
    switch(x)
    {
      case COMPLEX_DOUBLE:
        return 2*sizeof(double);
      case COMPLEX_SINGLE:
        return 2*sizeof(float);
      case REAL_DOUBLE:
        return 1*sizeof(double);
      case REAL_SINGLE:
        return 1*sizeof(float);
      case UNSIGNED_8:
        return 1*sizeof(uint8_t);
      case UNSIGNED_16:
        return 1*sizeof(uint16_t);
    }
  }

/* *EOF* */
