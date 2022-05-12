#ifndef VECTORS_H
#define VECTORS_H

#define VEC_INIT_CAP 32

struct Vector_t;

extern void *vector_create(struct Vector_t**);
extern void vector_destroy(struct Vector_t*);
extern int vector_pushback(struct Vector_t*, void *);
extern void vector_r_all_elem(struct Vector_t*, void*);
extern void vector_r_first_elm(struct Vector_t*, void*);
extern void vector_clear(struct Vector_t*);
extern unsigned long vector_grow(struct Vector_t*, unsigned long);
extern unsigned long vector_size(struct Vector_t*);
extern unsigned long vector_cap(struct Vector_t*);

#endif

