#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"


/*creating an array for the words with the same length,
and returns the frequency of the words with the same length*/
int freq(int length)
{
    FILE *f=fopen("words.txt", "r");
    int size[100]= {0};

    char *s=(char*)malloc(sizeof(char)*(100));
    while (fgets(s,50,f)!=NULL)
    {
        s[strlen(s)-1]='\0'; //delete newline
        size[strlen(s)]+=1;
    }
    fclose(f);
    free(s);
    return size[length];
}


char *chooseword(unsigned int length)
{
    /*opening the file and allocating
    memory for the words of the same length*/
    FILE *f=fopen("words.txt","r");
    int count=0;
    char *s=(char*)malloc(sizeof(char)*100);

    int random;
    int frq=freq(length);
    random=rand()%frq;

    //traversing till the desired word
    while(random > frq)

    {
        random %=(rand()*frq);

        /*randomize the number:
         how many times to skip the word*/
    }

    while(fgets(s,100,f)!=NULL)
    {
        s[strlen(s)-1]='\0'; //delete newline

        if (length == (unsigned int)strlen(s));
        {
            /*if it a word of the same length
                    increment*/
            ++count;
            if (count==random)
            {

                if(length!=(unsigned int)strlen(s))
                {


                    fclose (f);

                    return chooseword(length); //recurse to the function
                }
                else
                {
                    fclose(f);
                    return s; //closing the file and getting the randomized word
                }
            }

        }
    }


}

