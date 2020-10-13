#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
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
    strncat(filename, argv[1], sizeof(filename)-1);
    if ( creat(filename, 00644) == -1 )
    {
        fprintf(stderr, "Can't create file %s\n", filename);
        if (errno == EACCES)
        {
            fprintf(stderr, "Permission denied\n");
        }
        else
        {
            fprintf(stderr, "Unknown error\n");
        }
        return 1;
    }
    return 0;
}
