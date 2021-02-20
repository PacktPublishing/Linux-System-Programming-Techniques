#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *c;
    c = calloc(sizeof(char), 20);
    strcpy(c, "Hello!");
    printf("%s\n", c);
    return 0;
}
