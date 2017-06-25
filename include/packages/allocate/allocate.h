/* allocate.h
 * Copyright 2016 Mac Radigan
 * All Rights Reserved
 */

#include "packages/common/status.h"

#include <stdlib.h>

#ifndef allocate_h
#define allocate_h

  #define my_malloc(n)   alloc_malloc(n)
  #define my_calloc(m,n) alloc_cmalloc(m, n)
  #define my_free(p)     alloc_free(p)

  #define gc_malloc(n)   GC_malloc(n)
  #define gc_calloc(m,n) GC_malloc((m)*(n))
  #define gc_free(p)

#ifdef __cplusplus
extern "C" {
#endif

  typedef void* (*fn_alloc_t)(size_t size); 
  typedef void* (*fn_calloc_t)(size_t nmemb, size_t size); 
  typedef void  (*fn_dealloc_t)(void *ptr); 

  void *alloc_malloc(size_t size);
  void *alloc_calloc(size_t nmemb, size_t size);
  void alloc_free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif

/* *EOF* */
