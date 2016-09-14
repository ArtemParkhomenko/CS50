#include <cs50.h>
#include <stdio.h>

void draw(int height) // The method/funcition describes a drawing of the pyramid
{
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= height - i; j++)
            printf(" ");
        for(int j = 1; j <= i + 1; j++)
            printf("#");
        printf("\n");
    }
}

void execution() //The process of building a program.
{
    printf("Height: ");
    int height = GetInt(); // inpute
    while(true)
    {   
        if (height >= 0 && height <= 23)
        {
            draw(height);
            break; // Draw a pyramid and exit the program
        }
	   // Checking for errors
        else if (height < 0 || height > 23)
        {
            printf("Height: ");
            height = GetInt();
            continue; // Checks loop again
        } 
    }
}


int main(void)
{
    execution();
    return 0;
}