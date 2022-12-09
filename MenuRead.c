/*
Author: DumbDuck27
Program: Read a menu from a file and display it to the terminal
Because we don't know how many lines does the file have, each file contains information about 
    + categories, name, what's included (this should be fixed so we can stored them into a defined structure)
    + we don't care about the how many lines(dynamically allocated array of structure)
    + and also how long each line 
Can we use something more efficient than structure?
    +data should ne bounded together? -> struct for readability
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{

    char *categories;
    char *name;
    char *whatisincluded;

} TACOBELL;

int main(int argc, char *argv[])
{

    char FileLine[200] = {};
    char FileName[20] = {};
    char *tok;
    char temp[20];
    FILE *TacoFile;
    TACOBELL *Menu;
    int count = 0;

    if (argc != 2)
    {
        printf("File's must included in command line parameter!\n");
        return (1);
    }
    else
    {
        strcpy(FileName, argv[1]);
        TacoFile = fopen(FileName, "r");
        while (TacoFile == NULL)
        {
            printf("Error opening file name %s\n", FileName);
            printf("File name: ");
            scanf("%s", FileName);
            TacoFile = fopen(FileName, "r");
        }
    }

    Menu = malloc(sizeof(TACOBELL));

    while (fgets(FileLine, sizeof(FileLine), TacoFile))
    {
        tok = strtok(FileLine, "|");
        Menu[count].categories = malloc(strlen(tok)*sizeof(char)+1);
        strcpy(Menu[count].categories, tok);

        tok = strtok(NULL, "|");
        Menu[count].name = malloc(strlen(tok)*sizeof(char)+1);
        strcpy(Menu[count].name, tok);

        tok = strtok(NULL, "|");
        Menu[count].whatisincluded = malloc(strlen(tok)*sizeof(char)+1);
        strcpy(Menu[count].whatisincluded, tok);

        // a little bit confusion-increase count as the same time realloc 
        Menu = realloc(Menu, sizeof(TACOBELL)*(++count+1));
    }


    
    for (int i = 0; i < count; i++)
    {
        printf("Category: %s \nName: %s\nWhat is included: %s\n", Menu[i].categories, Menu[i].name, Menu[i].whatisincluded);
        free(Menu[i].categories);
        free(Menu[i].name);
        free(Menu[i].whatisincluded);
    }
    
    free(Menu);

    fclose(TacoFile);

    return 0;
}