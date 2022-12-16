 #include <stdio.h>

int main (int argc, char *argv[])
{
    // cheack for argc.
    if (argc != 2)
    {
        printf("IT should be ---> ./jpg***\n");
        return 1;
    }
    FILE *file = fopen (argv[1], "r");
    if (!file)
    {
        return 1;
    }
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
    {
        printf("MAYBE\n");
    }
    else
    {
        printf("NO\n");
    }
    fclose(file);
}