/*
 * Test that releasing an allocated pointer will cause it to be garbage collected.
 */
#include "testutil.h"
#include <stdio.h>
#include "gc.h"

int main (void)
{
  GC_INIT();

  (void)GC_malloc(123);

  size_t heapBefore = GC_get_free_bytes();
  printf("GC heap free before collect: %zu\n", heapBefore);
  GC_gcollect();
  size_t heapAfter = GC_get_free_bytes();
  printf("GC heap free after  collect: %zu (should be more than before)\n", heapAfter);

  assert(heapAfter > heapBefore);

  return 0;
}
