CC=gcc
CFLAGS=-std=c99 -Wall -pedantic
LIBS=-lm
OBJS=area.o help.o rectangle.o triangle.o circle.o
DEPS=area.h

area: $(OBJS)
	$(CC) -o area $(OBJS) $(LIBS)

area.o: $(DEPS)

clean:
	rm area $(OBJS)
