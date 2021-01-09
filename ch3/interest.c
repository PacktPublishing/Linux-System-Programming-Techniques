#include <stdio.h>
#include <math.h>

int main(void)
{
    int years = 15; /* The number of years you will 
                     * keep the money in the bank 
                     * account */
    int savings = 99000; /* The inital amount */
    float interest = 1.5; /* The interest in % */

    printf("The total savings after %d years " 
        "is %.2f\n", years, 
        savings * pow(1+(interest/100), years));
    return 0;
}
