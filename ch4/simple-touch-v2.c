#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#define MAX_LENGTH 100

int main(int argc, char *argv[])
{
    char filename[MAX_LENGTH] = { 0 };
    if (argc != 2)
    {
        fprintf(stderr, "You must supply a filename as "
            "an argument\n");
        return 1;
    }
    strncat(filename, argv[1], MAX_LENGTH-1);
    if ( creat(filename, 00644) == -1 )
    {
        fprintf(stderr, "Can't create file %s\n", filename);
        return 1;
    }
    return 0;
}
