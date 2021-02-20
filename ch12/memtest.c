#include <stdio.h>
#include <string.h>
int main(void)
{
    char text[20];
    memset(text, 'x', 20);
    strcpy(text, "Hello");
    printf("%s\n", text);
    return 0;
}
