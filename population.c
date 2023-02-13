#include <stdio.h>
#include <cs50.h>
#include <ctype.h> 

int main(void)
{
    int start, end;  
    int year = 0; 

    do
    {
        start = get_int("Starting population: ");
    
    }
    while (start < 9);

    do
    {
        end = get_int("Ending population: ");
    }
    while(end < start);
    

    while(start < end)
    {
        start = start + (start / 3) - (start / 4); 
        year++; 
    }
    printf("Years: %i\n", year);
}