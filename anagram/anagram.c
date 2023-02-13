#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char  *test[3] = {"SETT", "sTeT", "test"};

    char *target = "test";

    int *a = malloc(*target);

    int tally = 0; 

    for(int i = 0; i < 3; i++)
    {
        int *p = malloc(*test[i]);
        if (*p == *a)
        {
            tally++;
        }

    }
    printf("%i\n", tally);
}