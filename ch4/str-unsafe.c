#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char buf[10] = { 0 };
    strcat(buf, argv[1]);
    printf("Test: %s\n", buf);
    return 0;
}
