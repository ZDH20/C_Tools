#include <stdlib.h>
#include <stdio.h>

#include "stacks.h"
#include "types.h"
#include "castings.h"

int main(void) {

    Stack *s;
    stack_create(&s);

    stack_push(s, STOV("hello"));
    stack_push(s, STOV(" "));
    stack_push(s, STOV("world!"));


    while(!stack_empty(s)) {
        printf("%s\n", VTOS(stack_pop(s)));
    }

    stack_destroy(s);

    return 0;
}