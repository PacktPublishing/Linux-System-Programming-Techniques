#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *c;
    c = calloc(sizeof(char), 20);
    strcpy(c, "Hello, how are you doing?");
    printf("%s\n", c);
    free(c);
    return 0;
}
