#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"

struct Edge_t {
    char data;
    int cost;
    struct Edge_t *next;
};

struct Vertex_t {
    char data;
    struct Edge_t *edges;
    struct Vertex_t *next;
};

struct Graph_t {
    struct Vertex_t *head, *tail;
    int sz;
};

struct Graph_t *graph_create() {
    struct Graph_t *g = (struct Graph_t*)malloc(sizeof(struct Graph_t));
    g->head = g->tail = NULL;
    g->sz = 0;
    return g;
}

void graph_destroy(struct Graph_t *self) {
    while(self->head) {
        struct Edge_t *tmp_edge = self->head->edges;
        while(tmp_edge) {
            struct Edge_t *tmp_edge2 = tmp_edge;
            tmp_edge = tmp_edge->next;
            free(tmp_edge2);
        }
        struct Vertex_t *tmp_vertex = self->head;
        self->head = self->head->next;
        free(tmp_vertex);
    }
    free(self);
}

int graph_add_edge(struct Graph_t *self, const char source, const char destination, int cost) {
    struct Vertex_t *vert_nav = self->head, *save = NULL;
    int found_destination = 0;

    struct Edge_t *new_edge = edge_create(destination, cost);

    while(vert_nav) {
        if(vert_nav->data == source)
            save = vert_nav;
        if(vert_nav->data == destination)
            found_destination = 1;
        vert_nav = vert_nav->next;
    }

    if(!save) {
        graph_add_vertex(self, source);
        save = self->tail;
    }
    if(!found_destination)
        graph_add_vertex(self, destination);

    // Add the edge.
    if(save->edges) {
        struct Edge_t *tmp_edge = save->edges;
        while(tmp_edge->next)
            tmp_edge = tmp_edge->next;
        tmp_edge->next = new_edge;
    }
    else
        save->edges = new_edge;

    return 1;
}

int graph_add_vertex(struct Graph_t *self, const char data) {
    if(graph_contains(self, data))
        return 0;
    struct Vertex_t *new_vert = vertex_create(data);
    if(self->head == NULL)
        self->head = self->tail = new_vert;
    else {
        self->tail->next = new_vert;
        self->tail = self->tail->next;
    }
    self->sz++;
    return 1;
}

struct Edge_t *edge_create(const char destination, const int cost) {
    struct Edge_t *new_edge = (struct Edge_t*)malloc(sizeof(struct Edge_t));
    new_edge->data = destination;
    new_edge->cost = cost;
    new_edge->next = NULL;
    return new_edge;
}

struct Vertex_t *vertex_create(const char data) {
    struct Vertex_t *new_vert = (struct Vertex_t*)malloc(sizeof(struct Vertex_t));
    new_vert->data = data;
    new_vert->next = NULL;
    new_vert->edges = NULL;
    return new_vert;
}

int graph_contains(struct Graph_t *self, const char data) {
    struct Vertex_t *vert_nav = self->head;
    while(vert_nav) {
        if(vert_nav->data == data)
            return 1;
        vert_nav = vert_nav->next;
    }
    return 0;
}

void graph_printf(struct Graph_t *self) {
    struct Vertex_t *vert_nav = self->head;

    while(vert_nav) {
        printf("%c", vert_nav->data);
        struct Edge_t *e = vert_nav->edges;
        while(e) {
            printf(" -> %c(%d)", e->data, e->cost);
            e = e->next;
        }
        printf("\n");
        vert_nav = vert_nav->next;
    }
}
