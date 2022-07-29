#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"

void game()
{
    printf("choose the difficulty: 1 for Easy, 2 for Medium, 3 for Hard))) 0 to continue (((\n");
    int set;
    int guesses;

    //choosing the difficulty menu
    do
    {
        scanf("%d",&set);
        switch(set)
        {
        case 1:
            guesses=15;
            break;
        case 2:
            guesses=10;
            break;
        case 3:
            guesses=5;
            break;
        case 0:
            break; // to move on the next question
        default:
            printf("please type only selected few numbers\n");
        }
    }
    while (set!=0);

//choosing the length of the word
    printf("type the length of the word (more than 2 less than 12)\n");
    int len;

    scanf("%u",&len);

    char *word;

    //if the statement in the function fails then this loop calls it again
    while((word=chooseword(len))==NULL) {}


//create the dynamic array for the secret word

    int wordsize=strlen(word);
    char*secret=(char*)calloc((wordsize+1), sizeof(char));
    memset(secret, '_', wordsize);
    char letter;
    int error=0;

//printing information to the player
    printf("%s\n", secret);
    printf("the length of the word is %d letters\n", wordsize);
    printf("enter the letter\n");

//conditions to win or lose
    while (strcmp(secret, word)!=0 && error <= guesses)
    {
        scanf(" %c", &letter);


        //this cycle checks the word for the guessed letters
        for (int i = 0; i < wordsize; ++i)
        {

//if the letter exists in the word
            if (word[i]==letter)
                secret[i]=word[i];

        }

        /*if the letter was not repeated and
        nothing is unveiled then it counts as an error*/
        if (strchr(secret, letter)==NULL)
        {

            ++error;
        }

        printf("%s\n", secret);
        printf("Errors(maximum: %d): %d\n", guesses+1,error);
    }


    /* conditions and result */
    if (strcmp(secret, word)==0 && error<=guesses)
    {
        printf("Congratulations!!! you won!!!\n");
    }
    if (error>guesses)
    {

        printf("Regretfully, you lost\n");
        printf("The actual word is %s",word);
    }


    free(secret);

}

int main()
{
//set the seed
    srand(time(NULL));

    game();

    return 0;
}
