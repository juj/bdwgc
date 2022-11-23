/*
 * Test that a global pointer variable in the global data section
 * will be freed if the global value is cleared.
 */
#include "testutil.h"
#include <stdio.h>
#include <string.h>
#include "gc.h"

char *gc_pointer = (char*)5; // Does not reside in BSS section, since non-zero initialized (to arbitrary data).

void NOINLINE alloc()
{
  gc_pointer = GC_malloc(16);
  printf("%p\n", gc_pointer);
  strcpy(gc_pointer, "Hello!");
}

int main (void)
{
  GC_INIT();

  alloc();
  printf("%s\n", gc_pointer);
  gc_pointer = 0; // Clear the just allocated pointer, so it should be freed.

  size_t heapBefore = GC_get_free_bytes();
  printf("GC heap free before collect: %zu\n", heapBefore);

  GC_gcollect();

  size_t heapAfter = GC_get_free_bytes();
  printf("GC heap free after  collect: %zu (should be more than before)\n", heapAfter);

  assert(heapAfter > heapBefore);

  return 0;
}
