#include "arraystack.h"
#include <stdio.h>

void test_arraystack() {
	arraystack_t stack;

	arraystack_init(&stack, sizeof(int));

	for (int i = 0; i < 10; i++) {
		int pos = i;
		arraystack_add(&stack, pos, &i);
	}

	for (int i = 0; i < 10; i++) {
		int *res;

		arraystack_get(&stack, i, res);
		printf("%d\n", *res);
		/* free(res); */
	}
}

int main(void) {
	test_arraystack();
}
