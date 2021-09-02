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
