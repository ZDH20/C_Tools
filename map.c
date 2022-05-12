#include <stdio.h>
#include <stdlib.h>
#include "map.h"

struct Bucket_t {
    char key;
    int value;
    struct Bucket_t *next;
};

struct Map_t {
    struct Bucket_t **table;
    size_t size;
};

int hash(char key, size_t max) {
    return (key+17) % max;
}

struct Map_t *map_create(int n) {
    struct Map_t *map = (struct Map_t*)malloc(sizeof(struct Map_t));
    map->table = (struct Bucket_t**)malloc(sizeof(struct Bucket_t*)*n);
    for(int i = 0; i < n; i++)
        *(map->table+i) = NULL;
    map->size = n;
    return map;
}

struct Bucket_t *bucket_create(const char key, const char value) {
    struct Bucket_t *bucket = (struct Bucket_t*)malloc(sizeof(struct Bucket_t));
    bucket->key = key;
    bucket->value = value;
    bucket->next = NULL;
    return bucket;
}

void iter_bucket(struct Bucket_t *bucket, struct Bucket_t *b) {
    if(b->key == bucket->key) {
        bucket->value = b->value;
        free(b);
        return;
    }
    if(bucket->next)
        iter_bucket(bucket->next, b);
    else
        bucket->next = b;
}

int map_search_key(struct Bucket_t *bucket, char key) {
    if(bucket->key == key)
        return 1;
    if(bucket->next)
        return map_search_key(bucket->next, key);
    return 0;
}

void map_put(struct Map_t *this, char key, int val) {
    int index = hash(key, this->size);
    struct Bucket_t *bucket = bucket_create(key, val);
    if(*(this->table+index)) {
        iter_bucket(*(this->table+index), bucket);
        return;
    }
    *(this->table+index) = bucket;
}

char map_operator(struct Map_t *this, const char key) {
    int index = hash(key, this->size);
    if(this->table[index]->key == key)
        return this->table[index]->value;
    struct Bucket_t *b = *(this->table+index);
    while(b->next) {
        b = b->next;
        if(b->key == key)
            break;
    }
    return b->value;
}

int map_has_key(struct Map_t *this, const char key) {
    int index = hash(key, this->size);
    if(*(this->table+index))
        return map_search_key(*(this->table+index), key);
    return 0;
}

void map_free_mem(struct Map_t *this) {
    for(size_t i = 0; i < this->size; i++) {
        if(*(this->table+i)) {
            if(!this->table[i]->next)
                free(*(this->table+i));
            else {
                struct Bucket_t *p = *(this->table+i);
                while(p) {
                    struct Bucket_t *tmp = p;
                    p = p->next;
                    free(tmp);
                }
            }
        }
    }
    free(this->table);
    free(this);
}