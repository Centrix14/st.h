#ifndef __SIMPLE_TEST_LIBRARY_HEADER_FILE_INCLUDED__
#define __SIMPLE_TEST_LIBRARY_HEADER_FILE_INCLUDED__

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE
} st_colors;

#define st_color(text) printf("\x1b[1;%d;40m", text)
#define st_color_norm() printf("\x1b[m")

#define st_name(tname) char *__st_name = tname

#define st_start() \
	st_color(CYAN); \
	if (__dbs) \
		printf("*** %s start\n", __st_name); \
	st_color_norm()

#define st_end() \
   	st_color(CYAN); \
	printf("*** %s end\n\n", __st_name); \
	st_color_norm()

#define st_step(step) \
   	st_color(GREEN); \
	printf("*** %s %s\n", __st_name, step); \
	st_color_norm()

#define st_err(msg) \
   	st_color(RED); \
	printf("*** %s <%d>: %s\n\n", __func__, __LINE__, msg); \
	st_color_norm(); \
	exit(0)

#define st_descr(msg) \
	st_color(YELLOW); \
	printf("*** %s\n", msg); \
	st_color_norm()

#define st_debug_start(state) \
	static char __dbs = state

#define st_debug \
	if (__dbs)

#define st_log(...) \
	{ FILE *__lstream = fopen(__st_name, "a+"); \
		if (!__lstream) { \
			st_color(RED); \
			printf("*** %s: logging error\n", __st_name); \
			st_color_norm(); \
		} \
		if (__dbs) { \
			fprintf(__lstream, __VA_ARGS__); \
			fclose(__lstream); \
		} \
	}

#define st_logf(msg) \
	st_log("%s <%d>: %s\n", __func__, __LINE__, msg)

#define st_to_str(sym) #sym

#define st_call(func, ...) \
	st_log("%s: <%d> called\n", st_to_str(func), __LINE__); \
	func (__VA_ARGS__);

#define st_alloc(size) \
	malloc(size); \
	st_log("%s: <%d> allocated %d-bit memory\n", "malloc", __LINE__, size);

#define st_free(ptr) \
	free(ptr); \
	st_log("%s: <%d> released memory at the address %p\n", "free", __LINE__, ptr);

#endif
