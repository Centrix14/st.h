#include "st.h"

st_name("sample.txt");
st_debug_start(1);

void f1() {
	st_step("in f1");
	st_log("in f1 function\n");
}

void f2() {
	st_logf("in f2");

	st_debug {
		st_log("This will be written only in debug mode\n");
		st_err("This is error");
	}
}

void f3() {
	void *ptr = NULL;

	ptr = st_alloc(8);
	st_free(ptr);
}

int main() {
	st_start();
	st_descr("This is sample usage of st.h");

	char *mem = NULL;

	// call f1 with autologging
	st_call(f1);

	// call f3 with autologging
	st_call(f3);

	// allocate memory with autologging
	mem = st_alloc(1);
	st_log("%s: <%d> mem=%p\n", __func__, __LINE__, mem);
	st_free(mem);

	// call f2 with autologging
	st_call(f2);

	st_call(f3);

	st_end();
	return 0;
}
