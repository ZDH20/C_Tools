#ifndef QUEUES_H
#define QUEUES_H

typedef struct Node_t Node;
typedef struct Queue_t Queue;

extern void *queue_create(struct Queue_t**);
extern void queue_destroy(struct Queue_t*);
extern void queue_push(struct Queue_t*, void*);
extern void *queue_pop(struct Queue_t*);
extern void *queue_peek(struct Queue_t*);
extern unsigned long queue_size(struct Queue_t*);
extern int queue_empty(struct Queue_t*);

#endif
