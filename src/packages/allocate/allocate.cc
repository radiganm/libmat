/* allocate.cc
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "./packages/allocate/allocate.h"

#include <stdlib.h>

  void *alloc_malloc(size_t size)
  {
    return malloc(size);
  }

  void *alloc_calloc(size_t nmemb, size_t size)
  {
    return calloc(nmemb, size);
  }

  void alloc_free(void *ptr)
  {
    free(ptr);
  }

/* *EOF* */
