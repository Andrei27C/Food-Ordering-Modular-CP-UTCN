//
// Created by csatl on 11/28/2019.
//

#include <stdio.h>
#include <io.h>
#include <string.h>
#include "login.h"
void login(char *username, char *password)
{
    int stateLogin = 0;
    int isOK = 0;
    while(!isOK)
    {
        switch (stateLogin)
        {
            case 0 :{
                AskSign(&stateLogin);
                break;
            }
            case 1:{
                printf("%s\n",SIGNING_IN);
                SigningIn(username, password, &stateLogin);
                break;
            }
            case 2:{
                printf("%s\n",SIGNING_UP);
                SignUp(username,password, &stateLogin);
                break;
            }
            case 99:{
                isOK = 1;
                getchar();
                break;
            }
        }
    }
}



void AskSign(int *stateLogin)
{
    char choice;
    printf("%s\n",SIGN_IN_UP);
    printf("a) %s\n", SIGN_IN);
    printf("b) %s\n", SIGN_UP);
    scanf("%c",&choice);
    if(choice == 'a') *stateLogin = 1;
    else if (choice == 'b') *stateLogin = 2;
}
void SigningIn(char *username, char *password, int *stateLogin)
{
    printf("--Username\n");
    scanf("%s",username);
    printf("--Password\n");
    scanf("%s",password);
    if(CheckForUsername(username) == 0)
    {
        printf("%s\n",USER_NOT_FOUND);
        *stateLogin = 1;
        return;
    }
    else
    {
        if(CheckForPassword(username,password) == 0)
        {
            printf("%s\n",INCORRECT_PASSWORD);
            *stateLogin = 1;
        }
        else
            *stateLogin = 99;
    }
}
int CheckForUsername(char *username)
{
    char user[MAX_USER_LENGTH], *p;
    FILE *users = fopen("users_data.txt","r");
    while(!feof(users))
    {
        fgets(user,MAX_USER_LENGTH,users);
        p = strtok(user," ");
        if(strcmp(p, username) == 0)
        {
            fclose(users);
            return 1;
        }
    }
    fclose(users);
    return 0;
}
int CheckForPassword(char *username, char * password)
{
    char line[2*MAX_USER_LENGTH + 1], *p;
    FILE *users = fopen("users_data.txt","r");
    while(!feof(users))
    {
        fgets(line,MAX_USER_LENGTH,users);
        p = strtok(line," ");
        if(strcmp(p, username) == 0)
        {
            p = strtok(NULL, " ");
            p[strlen(p)-1] = '\0';
            if(strcmp(p,password) == 0)
            {
                fclose(users);
                return 1;
            }
        }
    }
    fclose(users);
    return 0;
}
void SignUp(char *username, char *password, int *stateLogin)
{
    printf("--Username\n");
    scanf("%s",username);
    printf("--Password\n");
    scanf("%s",password);
    if (CheckForUsername(username) == 1)
    {
        printf("%s\n",DUPLICATE_USER);
        *stateLogin = 2;
    }
    else
    {
        if(!PasswordIsValid(username,password))
        {
            *stateLogin = 2;
        }
        else
        {
            //save user in file
            FILE * users = fopen("users_data.txt","a");
            fprintf(users,"%s %s\n",username,password);
            *stateLogin = 99;
            fclose(users);
        }
    }
}
int PasswordIsValid(char *username, char *password)
{
    if(strlen(password) < 7)
    {
        printf("%s\n",ERROR_PASSWORD_LONG);
        return 0;
    }
    else if(strstr(password,username))
    {
        printf("%s\n",ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    else if(!(strchr(password,'.') || strchr(password,'_') || strchr(password,'!')))
    {
        printf("%s\n",ERROR_PASSWORD_SPECIAL_CHAR);
        return 0;
    }
    else
    {
        for(int i=0; i < strlen(password); i++)
        {
            if(strchr("0123456789",password[i]))
                return 1;
        }
        printf("%s\n",ERROR_PASSWORD_DIGITS);
        return 0;
    }
    return 1;
}