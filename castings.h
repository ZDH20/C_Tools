#ifndef CASTINGS_H
#define CASTINGS_H

// Casting.
#define ITOV(x) ((void*)(long int)(x))
#define VTOI(x) ((int)(long int)(x))
#define CTOV(x) ((void*)(x))
#define VTOC(x) (*(char*)&x)
#define STOV(x) ((void*)(x))
#define VTOS(x) ((char*)x)
// Must pass a variable, not just a value for doubles and floats.
#define DTOV(x) ((void*)(&x))
#define FTOV(x) ((void*)(&x))
#define VTOD(x) (*(double*)x)
#define VTOF(x) (*(float*)x)

#endif
