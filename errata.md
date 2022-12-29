# Errata for Linux System Programming Techniques
This is the official errata for Linux System Programming Techniques. If you
find an error in the book, please open an issue here on GitHub and describe the
error. I will then confirm it and add it to this document.

## Missing function code on page 32
In the code listing for `functions_ver2.c` on page 32, the code for the
function `func2()` is missing.

The correct code is found on GitHub. Please see
[functions_ver2.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch2/functions_ver2.c).

## Missing curly braces on page 108
On page 108, where the code for `area.c` ends, the code listing is missing
two curly braces and a `return 0;`. However, the code on GitHub is correct,
please see
[area.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch3/area/area.c).

## Page 162
In point 8,9 and 10 (page 163), the regular Linux `chmod`-command is used to
set permissions, although it should be the self-created `my-chmod`-command.

## Page 169, How it works
The sentence *A file descriptor is just an integer, just as 0, 1, and 3 are
stdin, stdout, and stderr* should be *A file descriptor is just an integer,
just as 0, 1, and 2 are stdin, stdout, and stderr*

## fprintf on page 175
The code i`fprintf(fp, linebuf);` in the recipe works, but is not safe. If the
input text contains a format operator, like `%s` the output will be incorrect.

Instead, the correct code should be `fprintf(fp, "%s", linebuf);`. 

For the corect program, see
[stream-write.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch5/stream-write.c).

## Missing 'else if' on page 213
*This error have been corrected in the e-book, but not yet in the printed
book.*

In the program `create-zombie.c` on page 213, there should be an `else
if`-statement on line 22. That `else if`-statement should check if the
`pid`-variable is greater than 0. The code on GitHub is correct, but not in the
book.

For the correct code, please see
[create-zombie.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch6/create-zombie.c).

## Missing lines on page 227
The code for `my-daemon-v2.c` on page 227 is missing the following lines at
the top of the code: 

```
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
```

The code on GitHub is correct though.

## Page 258, wrong temperature symbol
On page 258, the code uses the wrong temperature symbol. Line 22 should read
`printf("%.1f C = %.1f K\n",` instead of `printf("%.1f C = %.1f F\n",`.

The same goes for the example in step 3 on page 259; it should read `15.0 C =
288.1 K`.

## Page 278, the sending user must also set mesg y
On page 278, in step 7 and 8, the sending user must also allow messages with
`mesg y` before they can send a message using `write`.

## Wrong version of my-daemon-ctl.c in the book
*This error have been corrected in the e-book, but not yet in the printed
book.*

The book contains the wrong version of the program `my-daemon-ctl.c` on pages
295 to 298. The correct, working version is listed here on Github in
chapter 10, filename
[my-daemon-ctl.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch10/my-daemon-ctl.c).

The most important difference between the versions is that the path to
`my-daemon-v2` is hard coded in the book in `const char daemonPath[]`, which it
shouldn't be.

## sleep() only take integer values, page 290
On page 290, in the code listing for `terminal-size.c`, there's a line with
`sleep(0.1)`. It's purpose is to prevent the program from exhausting the system 
resources. However, `sleep()` only take integer values. So in reality this
will be `sleep(0)`, which also work. A sleep of 0 seconds will in fact
prevent system exhaustion. A big thank you to [zhenya4880](https://github.com/zhenya4880)
for pointing this out in [issue 3](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/issues/3).

The code on Github is updated with `sleep(0)`.
