#include <stdio.h>
#include <cs50.h>
#include <string.h>

int fact(int number);

int main(int argc, string argv[])
{
    int number = get_int("Enter a number: ");
    
    printf("The factorial of %i is %i\n", number, fact(number));
}

int fact(int number)
{
    if (number == 0 || number == 1)
    {
        return 1; 
    }
    else 
    {
        number = number * fact(number - 1);
    }
    return number; 
}