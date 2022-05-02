#include <stdlib.h>
#include <stdio.h>
#include "queues.h"

struct Node_t {
    void *data;
    struct Node_t *next;
};

struct Queue_t {
    struct Node_t *head, *tail;
    size_t sz;
};

void *queue_create(struct Queue_t **new_queue) {
    *new_queue = (struct Queue_t*)malloc(sizeof(struct Queue_t));
    (*new_queue)->head = NULL;
    (*new_queue)->tail = NULL;
    (*new_queue)->sz = 0;
    return NULL;
}

void queue_destroy(struct Queue_t *self) {
    struct Node_t *curr = self->head;
    while(curr != NULL) {
        struct Node_t *tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(self);
}

void queue_push(struct Queue_t *self, void *data) {
    struct Node_t *new_node = (struct Node_t*)malloc(sizeof(struct Node_t));
    new_node->data = data;
    new_node->next = NULL;
    if(!self->head)
        self->head = self->tail = new_node;
    else {
        self->tail->next = new_node;
        self->tail = self->tail->next;
    }
    self->sz++;
}

void queue_pop(struct Queue_t *self) {
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

void *queue_peek(struct Queue_t *self) {
    return self->tail->data;
}

int queue_empty(struct Queue_t *self) {
    return !self->head;
}

size_t queue_size(struct Queue_t *self) {
    return self->sz;
}
