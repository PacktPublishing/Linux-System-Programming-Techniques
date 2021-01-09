#include <stdio.h>

int triangle(void)
{
    float height, width;
    printf("Enter the height and width of "
        "the triangle: ");
    if (scanf("%f %f", &height, &width))
    {
        printf("%.3f\n", height*width/2);
        return 1;
    }
    else
    {
        return -1;
    }
}
