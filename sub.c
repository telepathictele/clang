#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[]) 
{
    string stuff = argv[1];
    printf("%s", stuff);
    char letter = stuff[0];

    if (argc > 2)
    {
        printf("Unexpected input: please only enter one command line argument.\n");
        return 1; 
    }
    else if (strlen(stuff) < 26)
    {
        printf("Please enter a valid key (26 characters). \n");
        return 1; 
    }

    for(int x = 1; x <= 27; x++)
    {
        char letter2 = stuff[x];

        if (tolower(letter) == tolower(letter2))
        {
            printf("Key must not contain repeating characters!\n");
            return 1; 
        }
        else if(/**(toupper(stuff[x - 1]) -  65 < 0) || **/ (toupper(stuff[x - 1]) -  65 >= 26) || (toupper(stuff[x - 1]) -  65 >= 58))
        {
            printf("Key must only contain alphanumeric characters!\n");
            return 1; 
        }

    }

    string input = get_string("Input: ");
    int length = strlen(input);
    char newstring[]= " "; 
    
    for (int i = 0; i < length; i++)
    {
        if (isupper(input[i]))
        {
            input[i] = toupper(stuff[input[i] - 'A']);
        }
        else if (islower(input[i]))
        {
            input[i] = tolower(stuff[input[i] - 'a']);
        }
    }

    printf("Output: %s\n", input);

}