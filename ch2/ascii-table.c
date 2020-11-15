#include <stdio.h>

int main(void)
{
    char c;
    for (c = 65; c<=90; c++)
    {
        printf("%c = %d    ", c, c); /* upper case */
        printf("%c = %d\n", c+32, c+32); /* lower case */
    }
    return 0;
}
