#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get the text
    string text = get_string("Text: ");

    float letters = 0;
    float sentences = 0;
    float words = 1;

    // get the num of letters
    for (int i = 0 ; i  < strlen(text) ; i++)
    {
        // Calculate Number Of Letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Calculate Number of Words
        else if (isspace(text[i]))
        {
            words++;
        }

        // Calculate Number of Sentences
        else if (text[i] == '?' || text[i] == '!' ||text[i] == '.')
        {
            sentences++;
        }
    }

    // Get average letters per 100 words
    float L = (letters / words) * 100;

    // Get average sentences per 100 words
    float S = (sentences / words) * 100;

    // get the result from equation
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}