#ifndef GRAPHS_H 
#define GRAPHS_H

typedef struct Graph_t Graph;
typedef struct Edge_t Edge;
typedef struct Vertex_t Vertex;

extern struct Graph_t *graph_create();
extern void graph_destroy(struct Graph_t*);
extern struct Vertex_t *vertex_create(const char);
extern struct Edge_t *edge_create(const char, const int);
extern int graph_add_vertex(struct Graph_t*, const char);
extern int graph_add_edge(struct Graph_t*, const char, const char, int);
extern int graph_contains(struct Graph_t*, const char);
extern void graph_printf(struct Graph_t*);

#endif
