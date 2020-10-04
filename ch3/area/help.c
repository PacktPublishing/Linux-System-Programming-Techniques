#include <stdio.h>

void printHelp(char progname[])
{
    printf("\nUsage: %s [-c] [-t] [-r] [-h]\n"
        "-c calculates the area of a circle\n"
        "-t calculates the area of a triangle\n"
        "-r calculates the area of a rectangle\n"
        "-h shows this help\n"
        "Example: %s -t\n"
        "Enter the height and width of the triangle: 5 9\n"
        "22.500\n", progname, progname);
}
