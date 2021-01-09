#include <stdio.h>
#include <stdlib.h>
void printhelp(char progname[]);

int main(int argc, char *argv[])
{
    int i;
    int sum = 0;

    /* Simple sanity check */
    if (argc == 1)
    {
        printhelp(argv[0]);
        return 1;
    }

    for (i=1; i<argc; i++)
    {
        sum = sum + atoi(argv[i]);
    }
    printf("Total sum: %i\n", sum);
    return 0;
}

void printhelp(char progname[])
{
    printf("%s integer ...\n", progname);
    printf("This program takes any number of " 
        "integer values and sums them up\n");
}
