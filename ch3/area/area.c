#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <unistd.h>
#include "area.h"

int main(int argc, char *argv[])
{
    int opt;
    /* Sanity check number of options */
    if (argc != 2)
    {
        printHelp(stderr, argv[0]);
        return 1;
    }
    /* Parse command-line options */    
    while ((opt = getopt(argc, argv, "crth")) != -1)
    {
        switch(opt)
        {
            case 'c':
                if (circle() == -1)
                {
                    printHelp(stderr, argv[0]);
                    return 1;
                }
                break;
            case 'r':
                if (rectangle() == -1)
                {
                    printHelp(stderr, argv[0]);
                    return 1;
                }
                break;
            case 't':
                if (triangle() == -1)
                {
                    printHelp(stderr, argv[0]);
                    return 1;
                }
                break;
           case 'h':
                printHelp(stdout, argv[0]);
                return 0;
            default:
                printHelp(stderr, argv[0]);
                return 1;
        }
    }
    return 0;
}
