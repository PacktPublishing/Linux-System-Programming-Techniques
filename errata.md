# Errata for Linux System Programming Techniques
This is the official errata for Linux System Programming Techniques. If you
find an error in the book, please open an issue here on GitHub and describe the
error. I will then confirm it and add it to this document.

## Missing 'else if' on page 213
In the program `create-zombie.c` on page 213, there should be an `else
if`-statement on line 22. That `else if`-statement should check if the
`pid`-variable is greater than 0. The code on GitHub is correct, but not in the
book.

For the correct code, please see
[create-zombie.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch6/create-zombie.c).

## Wrong version of my-daemon-ctl.c in the book
The book contains the wrong version of the program `my-daemon-ctl.c` on pages
295 to 298. The correct, working version is listed here on Github in
chapter 10, filename
[my-daemon-ctl.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch10/my-daemon-ctl.c).

The most important difference between the versions is that the path to
`my-daemon-v2` is hard coded in the book in `const char daemonPath[]`, which it
shouldn't be.


