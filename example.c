#include <stdio.h>
#include <errno.h>
#include <string.h>
#define C_WIDTH 640
#define C_HEIGHT 480
#include "spot.c"

int main()
{
    Pixel color = {255, 0, 25};
    spot_fill(color);
    write_to_ppm("test.ppm");
    printf("Hello World");
    return 0;
}