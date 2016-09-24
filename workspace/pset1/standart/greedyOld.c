#include <cs50.h>
#include <stdio.h>
#include <math.h>

//prototype
void greedy(float money);

int main(void)
{
   printf("O hai! How much change is owed?\n");
    float money = GetFloat(); // inpute
    while(true)
    {   
        if (money >= 0)
        {
            greedy(money);
            break; // Perform the functions and exit from the program
        }
	   // Checking for errors
        else if (money < 0)
        {
            printf("How much change is owed?\n");
            money = GetFloat();
            continue; // Checks loop again
        }
    }
}

void greedy(float money) // The method/funcition
{
    int change = round(money * 100);;                 // convert money to change
    int count = 0;
    
    count += change/25;
    change = change%25;
    
    count += change/10;
    change = change%10;
    
    count += change/5;
    change = change%5;
    
    count += change;                // steps for calculating 
    printf("%d\n",count);           // output

}