#include <cs50.h>
#include <stdio.h>

//prototype
void bottles (int bathingTime);
void execution();

int main(void)
{
    execution();
    return 0;
}

void bottles (int bathingTime)
{
    const int BOTTLEINMINUTES = 12; // 12 bottles (0.5) of water flows out of the shower in a minute.
    printf("bottles: %d", bathingTime * BOTTLEINMINUTES);// Output.
    
}

void execution() //The process of building a program.
{
    printf("minutes: ");
    int bathingTime = GetInt(); // Inpute.
    while(true)
    {   
        if (bathingTime > 0)
        {
            bottles(bathingTime);
            break; // Exit the program.
        }
	   // Checking for errors
        else if (bathingTime <= 0)
        {
            printf("minutes: ");
            bathingTime = GetInt(); // Inpute.
            continue; // Checks loop again.
        } 
    }
}