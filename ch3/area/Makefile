CC=gcc
CFLAGS=-std=c99 -Wall -pedantic
LIBS=-lm
OBJS=area.o help.o rectangle.o triangle.o circle.o
DEPS=area.h
bindir=/usr/local/bin

area: $(OBJS)
	$(CC) -o area $(OBJS) $(LIBS)

area.o: $(DEPS)

clean:
	rm area $(OBJS)

install: area
	install -g root -o root area /usr/local/bin/area

uninstall: $(bindir)/area
	rm $(bindir)/area
