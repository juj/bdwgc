/*
 * Test that keeping a reference to a pointer on stack will not cause it to be GCed.
 */
#include "gc.h"
#include <stdio.h>

int main (void)
{
  GC_INIT();

  void *ptr = GC_malloc(123);

  printf("GC heap free before collect: %zu\n", GC_get_free_bytes());
  GC_gcollect();
  printf("GC heap free before collect: %zu\n", GC_get_free_bytes());
  printf("ptr: %p\n", ptr);

  return 0;
}
