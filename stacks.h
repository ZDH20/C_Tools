#ifndef STACKS_H
#define STACKS_H

typedef struct Node_t Node;
typedef struct Stack_t Stack;

extern void *stack_create(struct Stack_t**);
extern void stack_destroy(struct Stack_t*);
extern void stack_push(struct Stack_t*, void*);
extern void *stack_pop(struct Stack_t*);
extern void *stack_peek(struct Stack_t*);
extern unsigned long stack_size(struct Stack_t*);
extern int stack_empty(struct Stack_t*);

#endif
