#include <stdio.h>
#define C_WIDTH 600
#define C_HEIGHT 400
#include "spot.c"


int main()
{
    Pixel color = {255, 255, 255};
    Pixel color2 = {255, 2, 255};

    spot_fill(color);
    spot_fillcircle(300, 200, 50, color2);
    write_to_ppm("test.ppm");
    printf("Hello World");
    return 0;
}