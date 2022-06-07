#ifndef ARRAY_STACK_H
# define ARRAY_STACK_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
   PARAMETARS
	elem_size    memory size of each element in array.
	length       number of elements in array.
	alloc_length current allocated memory size in array.
	array        pointer to the first content of array.
*/
typedef struct {
	size_t elem_size;
	size_t length;
	size_t alloc_length;
	void *array;
} arraystack_t;

/* FUNCTION
        arraystack_init

   Description
		Initializes an arraystack_t struct with an array size of 1. This
		function must be called before any other arraystack-related functions.

   Parametars
		s			A valid pointer to an arraystack_t struct.
		elem_size	Size of the elements that will be stored in the stack.
*/
void arraystack_init(arraystack_t *s, size_t elem_size);

void arraystack_dispose(arraystack_t *s);

void arraystack_get(arraystack_t *s, size_t pos, void *elem);

void arraystack_set(arraystack_t *s, size_t pos, void *elem, void *old_elem);

void arraystack_add(arraystack_t *s, size_t pos, void *elem);

void arraystack_remove(arraystack_t *s, size_t pos, void *elem_out);

#endif
