#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        return 1;
    }
    // open memory card
    typedef uint8_t BYTE;
    BYTE buffer[BLOCK_SIZE];
    size_t bytes_read;
    bool is_first_jpeg = false;
    FILE *current_file;
    char current_filename[100];
    int current_filenumber = 0;
    bool found_jpeg = false;

    while (true)
    {
        // repeat till end of card
        // read 512 bytes into a buffer
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (bytes_read == 0)
        {
            break; // End of CARD.
        }

        // Found JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpeg = true;
             //if first jpeg
            if (!is_first_jpeg)
            {
                is_first_jpeg = true;
            }
             else
            {
                 // Close the current file being written to, open new file
                fclose(current_file); // previous file was 000.jpg
            }
            sprintf(current_filename, "%03i.jpg", current_filenumber);
            current_file = fopen(current_filename, "w");
            fwrite(buffer, sizeof (BYTE), bytes_read, current_file);
            current_filenumber++; // filenumber
        }
        else
        {
            //else
            // if already found jpeg, keep writing to it
            if (found_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            }
        }
    }
    fclose(file);//close raw file
    fclose(current_file); //close my current file
    return 0;
}
