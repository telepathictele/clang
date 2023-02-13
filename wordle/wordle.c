#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);

int main(int argc, string argv[])
{
    string letter = argv[1];
    char wow = letter[0];
    int size = wow - '0';

    if (argc < 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1; 
    }

    int wordsize = 0;

    if(size >= 5 && size <= 9)
    {
        wordsize = size;
    }
    else
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1; 
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];
    printf("%s\n", choice);

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];
         for (int x = 0; x < wordsize; x++)
        {
            status[x] = 0; 
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);
        
        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    if (won == true)
    {
        printf("You win!\n");
    }
    else 
    {
        printf("Word: %s\n", choice);
    }

    return 0;
}

string get_guess(int wordsize)
{
    string guess = get_string("Input a %i-letter word: ", wordsize);
    if (strlen(guess) < wordsize || strlen(guess) > wordsize )
    {
         do
        {
            guess = get_string("Input a %i-letter word: ", wordsize);
        } while (strlen(guess) < wordsize || strlen(guess) > wordsize);
    }

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    int score = 0;
    bool dupe; 
    for (int t = 0; t < wordsize; t++)
    {
        for (int g = t + 1; g < wordsize; g++)
        {
            if (choice[t] == choice[g])
            {
                dupe = true;
            }
        }
    }

    for (int o = 0; o < wordsize; o++)
    {

        for(int p = wordsize; p >= 0; p--)
        {
            if(guess[o] == choice[p] && o == p) 
            {
                if(dupe)
                {
                    score += EXACT;
                    status[p] = 2;
                }
                else
                {
                    status[p] = 2;
                    score += EXACT; 
                    break;
                }    
            }
            else if (guess[o] == choice[p] && o != p)
            {
                status[p] = 1;
                score += CLOSE; 
            }
            else
            {
                status[p] = 0;
                score += WRONG;
                
            } 

        }
    }

    return score;
}

void print_word(string guess, int wordsize, int status[])
{

    for (int z = 0; z < wordsize; z++)
    {
        if (status[z] == EXACT)
        {
            printf(GREEN "%c", guess[z]);
        } 
        else if (status [z] == CLOSE)
        {
            printf(YELLOW "%c", guess[z]);
        }
        else
        {
            printf(RED "%c", guess[z]);
        }
    }

    printf(RESET "\n");
    return;
}
