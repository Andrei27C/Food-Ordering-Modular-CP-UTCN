//
// Created by csatl on 11/7/2019.
//

#include <stdio.h>

void inputLogin(char username[], char password[], int *state)
{
    // sign in
    printf("Please sign in to continue!\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
    *state = *state+1;
}