#include "arraystack.h"

void arraystack_init(arraystack_t* s, size_t elem_size) {
	assert((void *)s != NULL);
	assert(elem_size > 0);

	s->array = malloc(elem_size);
	assert(s->array != NULL);

	s->length = 0;
	s->alloc_length = 1;
	s->elem_size = elem_size;
}

void arraystack_dispose(arraystack_t* s) {
	assert((void *)s != NULL);

	free(s->array);
}

void arraystack_get(arraystack_t* s, size_t pos, void *elem) {
	assert((void *)s != NULL);
	assert(elem != NULL);
	assert(0 <= pos < s->length);

	memcpy(elem, (char *)s->array + (pos * s->elem_size), s->elem_size);
}
