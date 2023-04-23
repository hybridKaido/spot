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

void spot_setpixel(int x, int y, Pixel color)
{
    canvas[y*C_WIDTH + x] = color;
}


int spot_fill(Pixel color)
{
    for(int y = 0; y < C_HEIGHT; y++)
    {
        for(int x = 0; x < C_WIDTH; x++)
        {
            spot_setpixel(x, y, color);
        }
    }
    return 0;
}

void spot_fillrect(int posx, int posy, int w, int h, Pixel color)
{
    for(int y = 0; y < C_HEIGHT; y++)
    {
            for(int x = 0;x < C_WIDTH; x++)
            {
                if(x >= posx && x <= posx+w)
                {
                    if(y >= posy && y <= posy+h)
                    {
                        spot_setpixel(x, y, color);
                    }
                }
            }   
    }
}

void spot_fillcircle(int posx, int posy, int r, Pixel color)
{
    for(int y = 0; y < C_HEIGHT; y++)
    {
            for(int x = 0;x < C_WIDTH; x++)
            {
                if(x >= posx-r && x <= posx+r)
                {
                    if(y >= posy-r && y <= posy+r)
                    {
                        if((x-posx)*(x-posx) + (y-posy)*(y-posy) < r*r)
                        {
                            spot_setpixel(x, y, color);
                        }
                    }
                }
            }   
    }
}


#endif