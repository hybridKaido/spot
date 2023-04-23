#ifndef C_WIDTH
#define C_WIDTH 1024
#endif
#ifndef C_HEIGHT
#define C_HEIGHT 768
#endif
#ifndef SPOT_C
#define SPOT_C

typedef struct Pixel Pixel;
struct Pixel
{
    int r;
    int g;
    int b;
};

Pixel canvas[C_WIDTH*C_HEIGHT] = {0};

int write_to_ppm(char* filePath)
{
    FILE *f = fopen(filePath, "w");
    fprintf(f, "P3\n%d %d\n255\n", C_WIDTH, C_HEIGHT);
    for(int y = 0; y < C_HEIGHT; y++)
    {
        for(int x = 0; x < C_WIDTH; x++)
        {
            fprintf(f, "%d %d %d ", canvas[y*C_WIDTH + x].r, canvas[y*C_WIDTH + x].g, canvas[y*C_WIDTH + x].b);
            
        }
    }

    if(!(f))
    {
        printf("File creation unsuccessful");
        return -1;
    }
    return 0;
}

int spot_fill(Pixel color)
{
    for(int y = 0; y < C_HEIGHT; y++)
    {
        for(int x = 0; x < C_WIDTH; x++)
        {
            canvas[y*C_WIDTH + x].r = color.r;
            canvas[y*C_WIDTH + x].g = color.g;
            canvas[y*C_WIDTH + x].b = color.b;
        }
    }
    return 0;
}


#endif