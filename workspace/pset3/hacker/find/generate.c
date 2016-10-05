/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If it is entered more than 2 arguments then the program displays an error (1 arg it's name of programm)
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // atoi - converts the argument to an integer and and writes in and writes down in type int
    int n = atoi(argv[1]);

    // srand48 - this initialization functions, one of which must be called before using drand48
    // If arguments == 3 then we pass the parameters of type long int with the first argument
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2])); 
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // Loop that outputs a positive number(drand48), from i to n
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}