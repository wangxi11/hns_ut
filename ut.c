/**
 * unit testing helper file, use only under linux with glibc
 */
#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>
#include <stdarg.h>
#define ut_assert(cond) ut_assert_func(__FILE__, __LINE__, !!(cond), "")
#define ut_assert_str(cond, fmt, ...) ut_assert_func(__FILE__, __LINE__, !!(cond), fmt, ##__VA_ARGS__)


#ifdef UT_DUMPSTACK
#define ut_dumpstack() dumpstack()
#ifndef DUMP_DEEP
#define DUMP_DEEP 10
#endif
void dumpstack(void) {
	void * arr[DUMP_DEEP];
	int l, i;
	l = backtrace(arr, DUMP_DEEP);
	fprintf(stderr, "dump stack: \n");
	for(i=0; i<l; i++) {
		fprintf(stderr, "0x%lx\n", (unsigned long)arr[i]);
	}
}
#else
#define ut_dumpstack()
#endif

void ut_assert_func(char * f, int line, int cond, const char *fmt, ...) {
	va_list args;
	
	va_start(args, fmt);
	if(!cond) {
		printf("testfail at %s:%i: ", f, line);
		vprintf(fmt, args);
		printf("\n");
		ut_dumpstack();
		abort();
	}
	va_end(args);
}

int testcase = 0;

#define test(tc, test_func) \
	testcase = tc; \
	printf("test %s(%d)...", #test_func, tc); \
	test_func(); \
	printf("done\n");

#define MAX_ERRNO	4095

#define IS_ERR_VALUE(x) ((x) >= (unsigned long)-MAX_ERRNO)

static inline void *  ERR_PTR(long error)
{
	return (void *) error;
}

static inline long  PTR_ERR(const void *ptr)
{
	return (long) ptr;
}

static inline long  IS_ERR(const void *ptr)
{
	return IS_ERR_VALUE((unsigned long)ptr);
}

static inline long  IS_ERR_OR_NULL(const void *ptr)
{
	return !ptr || IS_ERR_VALUE((unsigned long)ptr);
}
