#include <stdio.h>

int rectangle(void)
{
    float length, width;
    printf("Enter the length and width of "
        "the rectangle: ");
    if (scanf("%f %f", &length, &width))
    {
        printf("%.3f\n", length*width);
        return 1;
    }
    else
    {
        return -1;
    }
}
