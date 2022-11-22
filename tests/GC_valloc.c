/*
 * Test that GC_valloc() function works.
 */
#include "gc.h"
#include <stdio.h>
#include <assert.h>

int main (void)
{
  void *ptr;
  GC_INIT();
  ptr = GC_valloc(1);
  printf("ptr: %p\n", ptr);
  assert(ptr != 0);
  return 0;
}
