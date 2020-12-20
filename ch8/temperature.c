#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

void printUsage(FILE *stream, char progname[]);

int main(int argc, char *argv[])
{
    if ( argc != 3 )
    {
        printUsage(stderr, argv[0]);
        return 1;
    }
    if ( strcmp(argv[1], "-f") == 0 )
    {
        printf("%.1f C = %.1f F\n", 
            atof(argv[2]), c_to_f(atof(argv[2])));
    }
    else if ( strcmp(argv[1], "-k") == 0  )
    {
        printf("%.1f C = %.1f F\n", 
            atof(argv[2]), c_to_k(atof(argv[2])));
    }
    else
    {
        printUsage(stderr, argv[0]);
        return 1;
    }
    
    return 0;
}

void printUsage(FILE *stream, char progname[])
{
    fprintf(stream, "%s [-f] [-k] [temperature]\n"
        "Example: %s -f 25\n", progname, progname);
}
