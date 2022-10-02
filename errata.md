# Errata for Linux System Programming Techniques
This is the official errata for Linux System Programming Techniques. If you
find an error in the book, please open an issue here on GitHub and describe the
error. I will then confirm it and add it to this document.

## Missing 'else if' on page 213
*This error have been corrected in the e-book, but not yet in the printed
book.*

In the program `create-zombie.c` on page 213, there should be an `else
if`-statement on line 22. That `else if`-statement should check if the
`pid`-variable is greater than 0. The code on GitHub is correct, but not in the
book.

For the correct code, please see
[create-zombie.c](https://github.com/PacktPublishing/Linux-System-Programming-Techniques/blob/master/ch6/create-zombie.c).

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
