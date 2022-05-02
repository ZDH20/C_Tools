#ifndef STRINGSDEFS_H
#define STRINGSDEFS_H

#define STR_INIT_SZ 32

typedef struct String_t String;

extern struct String_t *string_assign(char*);
extern void string_destroy(struct String_t*);
extern void string_printf(struct String_t*);
extern int string_char_concat(struct String_t*, const char*);
extern int string_concat(struct String_t*, struct String_t*);
extern int string_realloc(struct String_t*, const unsigned long);
extern void string_reverse(struct String_t*);
extern unsigned long string_length(struct String_t*);
extern unsigned long string_capacity(struct String_t*);

#endif
