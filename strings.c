#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

struct String_t {
    char *data;
    size_t sz, cap;
};

struct String_t *string_assign(char *s) {
    struct String_t *new_string = (struct String_t*)malloc(sizeof(struct String_t));
    new_string->data = (char*)malloc(sizeof(char)*STR_INIT_SZ);
    new_string->cap = STR_INIT_SZ;
    new_string->sz = 0;
    for(int i = 0; *(s+i) != '\0'; i++) {
        if(new_string->sz == new_string->cap)
            if(string_realloc(new_string, new_string->cap) == -1) {
                string_destroy(new_string);
                fprintf(stderr, "string_assign: string_realloc failed\n");
                return NULL;
            }
        *(new_string->data+i) = *(s+i);
        new_string->sz++;
    }
    return new_string;
}

void string_destroy(struct String_t *self) {
    free(self->data);
    free(self);
}

int string_char_concat(struct String_t *self, const char *concat_char) {
    for(int i = 0; *(concat_char+i) != '\0'; i++) {
        if(self->sz == self->cap)
            if(string_realloc(self, self->cap) == -1)
                return -1;
        *(self->data+self->sz) = *(concat_char+i);
        self->sz++;
    }
    return 1;
}

int string_concat(struct String_t *self1, struct String_t *self2) {
    for(size_t i = 0; i < self2->sz; i++) {
        if(self1->sz == self1->cap)
            if(string_realloc(self1, self1->cap) == -1)
                return -1;
        *(self1->data+self1->sz) = *(self2->data+i);
        self1->sz++;
    }
    return 1;
}

int string_realloc(struct String_t *self, const unsigned long new_size) {
    self->cap += new_size;
    if((self->data = (char*)realloc(self->data, sizeof(char*)+self->cap)) == NULL)
        return -1;
    return self->cap;
}

void string_printf(struct String_t *self) {
    for(size_t i = 0; i < self->sz; i++)
        printf("%c", *(self->data+i));
    printf("\n");
}

void string_reverse(struct String_t *self) {
    size_t i, j = self->sz-1;
    char tmp;
    for(i = 0; i < self->sz/2; i++, j--) {
        tmp = *(self->data+i);
        *(self->data+i) = *(self->data+j);
        *(self->data+j) = tmp;
    }
}

size_t string_length(struct String_t *self) {
    return self->sz;
}

size_t string_capacity(struct String_t *self) {
    return self->cap;
}
