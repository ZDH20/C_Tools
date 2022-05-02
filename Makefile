CFLAGS = -Wall -Wextra -g -O2 -std=c99

OBJ = graphs.o 	\
	  strings.o \
	  stacks.o  \
	  queues.o  \
	  main.o

SRCS = $(OBJ:%.o=%.c)

main: $(SRCS)
	gcc -o $@ $(CFLAGS) $(SRCS)
