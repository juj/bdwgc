/*
 * Test that releasing an allocated pointer will cause it to be garbage collected.
 */
#include "gc.h"
#include <stdio.h>

int main (void)
{
  GC_INIT();

  (void)GC_malloc(123);

  printf("GC heap free before collect: %zu\n", GC_get_free_bytes());
  GC_gcollect();
  printf("GC heap free before collect: %zu\n", GC_get_free_bytes());

  return 0;
}
