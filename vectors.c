#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"

struct Vector_t {
    void *data;
    size_t sz, cap;
};

void *vector_create(struct Vector_t **self) {
    *self = (struct Vector_t*)malloc(sizeof(struct Vector_t));
    (*self)->data = (void*)malloc(sizeof(void)*VEC_INIT_CAP);
    (*self)->sz = 0;
    (*self)->cap = VEC_INIT_CAP;
    return NULL;
}

int vector_pushback(struct Vector_t *self, void *data) {
    if(self->sz == self->cap) {
        self->cap *= 2;
        vector_grow(self, self->cap);
    }

    self->data = data;

    return 1;
}

size_t vector_grow(struct Vector_t *self, unsigned long grow_sz) {
    self->cap += grow_sz;
    if((self->data = (char*)realloc(self->data, sizeof(char*)+self->cap)) == NULL)
        return -1;
    return self->cap;
}

void vector_destroy(struct Vector_t *self) {
    free(self->data);
    free(self);
}


