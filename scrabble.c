#include <stdio.h>
#include <cs50.h> 
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char lAlph[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char uAlph[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int compute(string word);
    string compare(int s1, int s2);

int main(void)
{

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = compute(player1);
    int score2 = compute(player2);
    
    printf("%s",compare(score1, score2)); 
   
}

int compute(string word)
{
    int p1score = 0;
    int wordlength = strlen(word);

    for (int i = 0; i < wordlength; i++)
    {
        char letter = word[i];
        if (islower(letter))
        {
            for(int j = 0; j < 26; j++)
            {
                if (letter == lAlph[j])
                {
                    p1score += scores[j];
                }
            }
        } 
        else 
        {
            for(int j = 0; j < 26; j++)
            {
                if (letter == uAlph[j])
                {
                    p1score += scores[j];
                }
            }
        } 
    }
    return p1score; 
}

string compare(int s1, int s2)
{
    if (s1 > s2)
    {
        return "Player 1 wins!\n";
    }
    else if (s2 > s1)
    {
        return "Player 2 wins!\n";
    } 
    else 
    {
        return "Tie!\n";
    }
}