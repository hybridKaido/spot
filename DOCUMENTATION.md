C_WIDTH, C_HEIGHT //defines the width and height of the canvas : default value is 1024*768

struct Pixel //basic structure for storing rgb values

spot_fill(Pixel color) //fills whole canvas with given color

spot_setpixel(intx, int y, Pixel color) //set particular pixel in memory to a particular color

Pixel canvas //memory buffer where pixels are saved

int write_to_ppm(char* filePath) // saves the memory buffer to a P3 type ppm file, returns -1 on failure

spot_fillcircle(int posx, int posy, int r, Pixel color) //fills a circle