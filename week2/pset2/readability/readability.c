#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int calculate_grade(string s);

int main(void)
{
    // Prompt user for the Text.
    string s = get_string("Text: ");
    int grade = calculate_grade(s);
    // Print The result.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 1 && grade <= 15)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}
// calculate Grade.
int calculate_grade(string s)
{
    float word = 0, letter = 0, sentence = 0;
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (isalpha(s[i]))
        {
            letter ++;
        }
        if (isspace(s[i]))
        {
            word ++;
        }
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence ++;
        }
    }
    // + the missing word.
    word++;
    float L = letter /  word * 100;
    float S = sentence /  word * 100;
    // The Coleman-Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    // return result for using.
    return grade;
}

