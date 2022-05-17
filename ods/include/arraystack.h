#ifndef ARRAY_STACK_H
# define ARRAY_STACK_H

#include <stdlib.h>
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

#endif
