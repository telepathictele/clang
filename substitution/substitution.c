#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    string newstring; 
    string stuff = argv[0]; 

    if (argc > 1)
    {
        printf("Unexpected input: please only enter one command line argument.\n");
        return 1; 
    }
    else if (strlen(argv) < 26)
    {
        printf("Please enter a valid key (26 characters). \n");
    }

    string input = get_string("Input: ");
    int length = strlen(input);

    //for the size of the input, change the character to the repsective index in the ciper
    // for example, if a = 0 but the cipher 0 = z, then the input 0 = z 
    
    for (int i = 0; i < length; i++)
    {
        if (isupper(input[i]))
        {
            newstring += stuff[input[i] - 'A'];
        }
        else
        {
            newstring += stuff[input[i] - 'a'];
        }
    }
    printf("%s", newstring);

}