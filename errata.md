# Errata for Linux System Programming Techniques
This is the official errata for Linux System Programming Techniques. If you
find an error in the book, please open an issue here on GitHub and describe the
error. I will then confirm it and add it to this document.

## Linked libraries should come after the file
**This issue has been fixed in the book as of June/July 2021!**

The error affects readers using Ubuntu and was reported by [Stan
(who8mypnuts)](https://github.com/who8mypnuts) in [issue
1](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/issues/1).

Ubuntu (and possibly other distributions) has added the flag `--as-needed` as
a default for the linker. The reason for using `--as-needed` is to avoid
linking unneeded libraries in a binary. The downside of this is that the order
of flags now matters. The linked library – for example `-lm` – must now come
*after* the file.

This error shows up on the following pages in the book. Replace the command
line with the correct command line under *should be:*.

### Page 67, Linking against the math library, step 2:

    $> gcc -lm interest.c -o interest

should be:

    $> gcc interest.c -o interest -lm

### Page 70, Linking against a library in your home directory, step 2:
    
    $> gcc -L${PWD} -lprime is-it-a-prime.c \
    > -o is-it-a-prime

should be:
    
    $> gcc -L${PWD} is-it-a-prime.c \
    > -o is-it-a-prime -lprime

### Page 72, How it works

    gcc -lc some-program.c -o some-program

should be:

    gcc some-program.c -o some-program -lc

### Page 121, step 3:

    $> gcc -Wall -Wextra -pedantic -lm huge-test.c \
    > -o huge-test

should be:

    $> gcc -Wall -Wextra -pedantic huge-test.c \
    > -o huge-test -lm

### Page 255, step 5:

    $> gcc -Wall -Wextra -pedantic -std=c99 -lcurl \
    > get-public-ip.c -o get-public-ip

should be:

    $> gcc -Wall -Wextra -pedantic -std=c99 \
    > get-public-ip.c -o get-public-ip -lcurl

### Page 266, step 2:

    $> gcc -Wall -Wextra -pedantic -std=c99 \
    > -lconvert temperature-v2.c -o temperature-v2

should be:

    $> gcc -Wall -Wextra -pedantic -std=c99 \
    > temperature-v2.c -o temperature-v2 -lconvert

### Page 269, step 3:

    $> gcc -Wall -Wextra -pedantic -std=c99 -static \
    > temperature-v2.c -lconvert -o temperature-static

should be:

    $> gcc -Wall -Wextra -pedantic -std=c99 -static \
    > temperature-v2.c -o temperature-static -lconvert

### Page 313, step 4:

    $> gcc -Wall -Wextra -pedantic -std=c99 -lrt \
    > msg-sender.c -o msg-sender

should be:

    $> gcc -Wall -Wextra -pedantic -std=c99 \
    > msg-sender.c -o msg-sender -lrt

### Page 317, step 6:

    $> gcc -Wall -Wextra -pedantic -std=c99 -lrt \
    > msg-reveiver.c -o msg-reveiver

should be:

    $> gcc -Wall -Wextra -pedantic -std=c99 \
    > msg-reveiver.c -o msg-reveiver -lrt

### Page 322, step 5:


    $> gcc -Wall -Wextra -std=gnu11 -lrt \
    > shm-parent-child.c -o shm-parent-child

should be:

    $> gcc -Wall -Wextra -std=gnu11 \
    > shm-parent-child.c -o shm-parent-child -lrt

### Page 325, step 4:

    $> gcc -Wall -Wextra -std=gnu11 -lrt write-memory.c \
    > -o write-memory

should be:

    $> gcc -Wall -Wextra -std=gnu11 write-memory.c \
    > -o write-memory -lrt

### Page 326, step 2:

    $> gcc -Wall -Wextra -std=gnu11 -lrt read-memory.c \
    > -o read-memory

should be:

    $> gcc -Wall -Wextra -std=gnu11 read-memory.c \
    > -o read-memory -lrt

### Page 341, the Makefile for the recipes in chapter 11

    CC=gcc
    CFLAGS=-Wall -Wextra -pedantic -std=c99 -lpthread

should be:

    CC=gcc
    CFLAGS=-Wall -Wextra -pedantic -std=c99
    LDFLAGS=-lpthread
    %: %.c
            $(CC) $< $(CFLAGS) -o $@ $(LDFLAGS)

### Page 389, step 1:

    $> gcc -g -Wall -Wextra -pedantic -std=c99 \
    > -lpthread first-threaded.c -o first-threaded

should be:

    $> gcc -g -Wall -Wextra -pedantic -std=c99 \
    > first-threaded.c -o first-threaded -lpthread
