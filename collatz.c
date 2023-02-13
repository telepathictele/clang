#include <stdio.h>
#include <cs50.h>


int collatz(int);

int main(void)
{
    int n = get_int("Please enter a non-negative integer (do not enter 0): ");
    printf("Steps to 1: %i \n", collatz(n));
}

int collatz(int number)
{
    int steps = 0;
    int divided = number; 

    if (number == 1 || number == 0)
    {
        return 0; 
    }
     if (divided % 2 == 0)
    {
        return 1 + collatz((number / 2));
        steps++;
    }
     if (divided % 2 != 0)
    {
       return 1 + collatz(((3*number) + 1));
    } 

    return steps; 
}
