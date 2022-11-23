/*
 * Test that pointers in global data section can store GC pointers.
 */
#include "gc.h"
#include <stdio.h>
#include <string.h>

char *gc_pointer;

void alloc()
{
  gc_pointer = GC_malloc(4096);
  printf("%p\n", gc_pointer);
  strcpy(gc_pointer, "Hello!");
}

int main (void)
{
  GC_set_all_interior_pointers(0);
  GC_INIT();
  alloc();

  printf("%p is heap ptr: %d\n", gc_pointer, GC_is_heap_ptr(gc_pointer));

  printf("------Before collect\n");
  GC_dump();

  gc_pointer = 0;

  GC_gcollect();

  printf("------After collect\n");
  GC_dump();

  return 0;
}
