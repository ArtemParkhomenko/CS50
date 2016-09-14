#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int bottleInMinutes = 12; // 12 bottles (0.5) of water flows out of the shower in a minute
        printf("minutes: ");
    int bathingTime = GetInt(); // inpute
    printf("bottles: %d", bathingTime * bottleInMinutes); // output
}