#pragma once

#undef NDEBUG
#include <assert.h>

#if defined(__GNUC__) || defined(__llvm__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE
#endif
