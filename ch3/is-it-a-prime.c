#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char *argv[])
{
    long int num;
    num = atol(argv[1]);
    if (isprime(num))
    {
        printf("%ld is a prime\n", num);
    }
    else
    {
        printf("%ld is not a prime\n", num);
    }
    
    return 0;
}