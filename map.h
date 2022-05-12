#ifndef MAP_H
#define MAP_H
#define MAP_CREATE_INIT 100

typedef struct Map_t Map;
typedef struct Bucket_t Bucket;

int hash(char, unsigned long);
Map *map_create(int);
Bucket *bucket_create(const char, const char);
void iter_bucket(Bucket*, Bucket*);
int map_search_key(Bucket*, char);
void map_put(Map*, char, int);
char map_operator(Map*, const char);
int map_has_key(Map*, const char);
void map_free_mem(Map*);

#endif

