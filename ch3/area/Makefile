CC=gcc
CFLAGS=-std=c99 -Wall -pedantic
LIBS=-lm

area: area.c area.h help.c rectangle.c triangle.c circle.c
	$(CC) $(CLAGS) $(LIBS) area.c help.c rectangle.c \
	triangle.c circle.c -o area
