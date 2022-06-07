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
	s->array = NULL;
}

void arraystack_get(arraystack_t* s, size_t pos, void *elem) {
	assert((void *)s != NULL);
	assert(elem != NULL);
	assert(pos < s->length);
	assert(0 < s->length);

	memcpy(elem, (char *)s->array + (pos * s->elem_size), s->elem_size);
}

void arraystack_set(arraystack_t *s, size_t pos,
						void *elem, void *old_elem) {
	assert((void *)s != NULL);
	assert(elem != NULL);
	assert(0 < s->length);

	if (old_elem != NULL)
		memcpy(old_elem, (char *)s->array + (pos * s->elem_size), s->elem_size);

	memcpy((char *)s->array + (pos * s->elem_size), elem, s->elem_size);
}

static void resize(arraystack_t *s) {
	size_t realloc_size = 1;
	
	if (s->length > 0)
		realloc_size = s->length * 2;

	s->array = realloc(s->array, realloc_size * s->elem_size);
	assert(s->array != NULL);
	s->alloc_length = realloc_size;
}

void arraystack_add(arraystack_t *s, size_t pos, void *elem) {
	assert((void *)s != NULL);
	assert(elem != NULL);
	assert(pos <= s->length);

	if (1+s->length > s->alloc_length)
		resize(s);

	memmove((char *)s->array + ((1+pos) * s->elem_size),
			(char *)s->array + (pos * s->elem_size),
			(s->length - pos) * s->elem_size);

	memcpy((char *)s->array + (pos * s->elem_size),elem,s->elem_size);

	++s->length;
}

void arraystack_remove(arraystack_t *s, size_t pos, void *elem_out) {
	assert((void *)s != NULL);
	assert(0 < s->length);
	assert(pos < s->length);

	if (elem_out != NULL)
		memcpy(elem_out, (char *)s->array + (pos * s->elem_size), s->elem_size);

	memmove((char *)s->array + (pos * s->elem_size),
			(char *)s->array + ((1 + pos) * s->elem_size),
			(s->length - pos - 1) * s->elem_size);

	--s->length;
	if (s->length * 3 < s->alloc_length)
		resize(s);
}
