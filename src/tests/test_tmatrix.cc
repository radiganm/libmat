/* test_tmatrix.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "./packages/tmatrix/tmat_d.h"
#include <stdio.h>
#include <cstdlib>
#include <string.h>

  int main(int argc, char *argv[])
  {
    status_t status = Status::SUCCESS;
    const uint64_t n = 5;
    const char *name = "Matrix X";
    TMat<double> x = TMat<double>::eye(n);
    x.disp(name);

    fflush(stdout);
    fflush(stderr);

    return status;
  }

/* *EOF* */
