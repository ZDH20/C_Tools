#include <stdlib.h>
#include <stdio.h>
#include "stacks.h"

struct Node_t {
    void *data;
    struct Node_t *next;
};

struct Stack_t {
    struct Node_t *head, *tail;
    size_t sz;
};

struct Stack_t *stack_create() {
    struct Stack_t *new_stack = (struct Stack_t*)malloc(sizeof(struct Stack_t));
    new_stack->head = new_stack->tail = NULL;
    new_stack->sz = 0;
    return new_stack;
}

void stack_push(struct Stack_t *self, void *data) {
    struct Node_t *new_node = (struct Node_t*)malloc(sizeof(struct Node_t));
    new_node->data = data;
    new_node->next = NULL;
    if(!self->head)
        self->head = self->tail = new_node;
    else {
        struct Node_t *tmp = self->tail;
        self->tail = new_node;
        self->tail->next = tmp;
    }
    self->sz++;
}

void stack_pop(struct Stack_t *self) {
    if(!self->head)
        return;
    if(self->sz == 1) {
        free(self->head);
        self->head = self->tail = NULL;
    }
    else {
        struct Node_t *tmp = self->tail;
        self->tail = self->tail->next;
        free(tmp);
    }
    self->sz--;
}

void *stack_peek(struct Stack_t *self) {
    return self->tail->data;
}

int stack_empty(struct Stack_t *self) {
    return !self->head;     
}



