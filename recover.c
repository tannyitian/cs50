#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define N_BYTES 512
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }

    //Creating a pointer to the file we want to recover
    char * infile = argv[1];

    //Open memory card
    FILE *ptr1 = fopen(infile, "r");
    if (ptr1 == NULL)
    {
        return 2;
    }

    //looking at beginning of a jpeg
    typedef uint8_t BYTE;
    BYTE buffer[N_BYTES];
    int count = 0;
    size_t readin; // to record how many jpegs we have iterated through
    char filename[10];
    bool found = false;
    FILE *img;



    while (true)
    {
        readin = fread(buffer, sizeof(BYTE), N_BYTES, ptr1); //Writing from img to buffer (each time read in 512 bytes)
        if (readin == 0) //means we have reached the end of the file.
        {
            break;
        }
        //check whether if it is the start of jpeg
        // if it is the first jpeg of the file we will open and write to it
        //if it is no longer the first jpeg which means its the start of next jpeg, we will have to close the previous jpeg before writing to it
        // else if not the start of a new jpeg which means we have to continue writing to it because a jpeg may have several blocks of 512 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (found == false)
            {
                found = true;
            }
            else
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count++);
            img = fopen(filename, "w");

            if (img == NULL) //check if memory is successfully allocated
            {
                return 3;
            }

            fwrite(buffer, sizeof(BYTE), N_BYTES, img); //WRITING FROM BUFFER TO IMG

        }
        else if (found == true)
        {
            fwrite(buffer, sizeof(BYTE), N_BYTES, img);
        }

    }

    fclose(img);
    fclose(ptr1);

}