#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // open file
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }
    // store data.
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    // use fprintf
    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
}