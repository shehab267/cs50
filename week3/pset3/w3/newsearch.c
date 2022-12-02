#include <cs50.h>
#include <stdio.h>
#include <string.h>


    // intailisation Person.
    typedef struct
    {
        string name;
        string number;
    }
    person;

    int main(void)
{
    int MEMBERS = get_int("MEMBERS: ");

    // intailisation people.
    person people[MEMBERS];
    for (int i = 0; i < MEMBERS; i++)
    {
        people[i].name = get_string("Name %d: ", i + 1);
        people[i].number = get_string("Number %i: ", i + 1);


    }

    for (int i = 0; i < MEMBERS; i++)
    {
        if(strcmp("Ah", people[i].name) == 0)
        {
            printf("FOUND! NUM: %s\n", people[i].number);
            return 0;
        }
    }
    printf("NOT FOUND!\n");
}