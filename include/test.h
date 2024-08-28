#ifndef TEST_H
#define TEST_H
#include <assert.h>
#include <stdio.h>

#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#define DO_WHILE(content) do { content; } while(0)

#define FT_ASSERT(test, msg) DO_WHILE(assert(test); printf(GRN msg RESET"\n"))
#endif
