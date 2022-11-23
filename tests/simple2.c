/*
 * Test that keeping a reference to a pointer on stack will not cause it to be GCed.
 */
#include "testutil.h"
#include <stdio.h>
#include "gc.h"

int main (void)
{
  GC_INIT();

  void *ptr = GC_malloc(123);

  size_t heapBefore = GC_get_free_bytes();
  printf("GC heap free before collect: %zu\n", heapBefore);
  GC_gcollect();
  size_t heapAfter = GC_get_free_bytes();
  printf("GC heap free after 1st collect: %zu (should be same as before)\n", heapAfter);
  printf("ptr: %p\n", ptr); // Print the pointer value so -O3 does not optimize it away altogether.

  assert(heapAfter == heapBefore);

  ptr = 0; // let the ptr be reclaimed

  GC_gcollect();
  heapAfter = GC_get_free_bytes();
  printf("GC heap free after 2nd collect: %zu (should be more than before)\n", heapAfter);

  assert(heapAfter > heapBefore);

  return 0;
}
