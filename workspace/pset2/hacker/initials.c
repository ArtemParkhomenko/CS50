#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//prototype:
int validationAlpha(int index, string name);
int validationSpace(int index, string name);
void execution(int length, string name);

int main(int argc, string argv[])
{
    string name = get_string();
    execution(strlen(name), name);
}

int validationAlpha(int index, string name) // Checking on the alphabet.
{
    if((name[index] >= 'A' && name[index] <= 'Z') || (name[index] >= 'a' && name[index] <= 'z'))
    {
        return true; 
    }
    else
    {
        return false;
    }
}

int validationSpace(int index, string name) // Checking for space.
{
    if (name[index] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void execution (int length, string name)
{
    for(int i = 0; i<length; i++)
    {
        if(validationAlpha(i,name))
        {
            printf("%c", toupper(name[i])); // Toupper it's - change characters to uppercase.
            for (;i<length;i++) // Loop to the character "space".
            {
                if(validationSpace(i,name))
                {
                   break;
                }
            }
        }
    }
    printf("\n");
}

// All checks in CS50 is accepted. 
// Thanks for the review.