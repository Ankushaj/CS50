#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Error: must be in format ./recover file.raw");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        return 1;
    }

    FILE *image = NULL;

    char filename[8];

    unsigned char bytes[512];

    bool current = false;

    int imageCount = 0;

    while (fread(bytes, 512, 1, file) == 1)
    {
        if ((bytes[0] == 0xff) && (bytes[1] == 0xd8) && (bytes[2] == 0xff) && ((bytes[3] & 0xf0) == 0xe0))
        {
            if (current == true)
            {
                fclose(image);
            }
            else
            {
                current = true;
            }

            sprintf(filename, "%03i.jpg", imageCount);
            image = fopen(filename, "w");
            imageCount++;
    }


        if (current == true)
        {
            fwrite(&bytes, 512, 1, image);
        }
    }

    fclose(file);
    fclose(image);
    return 0;
}
