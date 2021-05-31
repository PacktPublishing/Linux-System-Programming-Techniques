CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDFLAGS=-lpthread
%: %.c
	$(CC) $< $(CFLAGS) -o $@ $(LDFLAGS)
