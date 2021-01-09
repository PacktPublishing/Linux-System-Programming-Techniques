#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char mph[10] = { 0 };

    while(fgets(mph, sizeof(mph), stdin) != NULL)
    {
        /* Check if mph is numeric 
         * (and do conversion) */
        if( strspn(mph, "0123456789.-\n") == 
            strlen(mph) )
        {
            printf("%.1f\n", (atof(mph)*1.60934) );
        }
        /* If mph is NOT numeric, print error 
         * and return */
        else
        {
            fprintf(stderr, "Found non-numeric" 
                " value\n");
            return 1;
        }
    }
    return 0;
}
