#ifndef STACKS_H
#define STACKS_H

struct Node_t;
struct Stack_t;

extern struct Stack_t *stack_create();
extern void stack_push(struct Stack_t*, void*);
extern void stack_pop(struct Stack_t*);
extern void *stack_peek(struct Stack_t*);
extern unsigned long stack_size(struct Stack_t*);
extern int stack_empty(struct Stack_t*);

#endif
