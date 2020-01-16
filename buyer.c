//
// Created by csatl on 12/20/2019.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "login.h"
#include "buyer.h"
buyer CreateBuyer ()
{
    buyer b;
    b.username = (char*)malloc(MAX_USER_LENGTH * sizeof(char));
    b.password = (char*)malloc(MAX_USER_LENGTH * sizeof(char));
    for(int i = 0; i < MAX_USER_LENGTH;i++)
    {
        b.username[i] = '\0';
        b.password[i] = '\0';
    }
    return b;
}
void login(buyer * b)
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
                SigningIn(b, &stateLogin);
                break;
            }
            case 2:{
                printf("%s\n",SIGNING_UP);
                SignUp(b, &stateLogin);
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
void SigningIn(buyer * b, int *stateLogin)
{
    printf("--Username\n");
    scanf("%s",b->username);
    printf("--Password\n");
    scanf("%s",b->password);
    if(CheckForUsername(b) == 0)
    {
        printf("%s\n",USER_NOT_FOUND);
        *stateLogin = 1;
        return;
    }
    else
    {
        if(CheckForPassword(b) == 0)
        {
            printf("%s\n",INCORRECT_PASSWORD);
            *stateLogin = 1;
        }
        else
            *stateLogin = 99;
    }
}
int CheckForUsername(buyer * b)
{
    char user[MAX_USER_LENGTH], *p;
    FILE *users = fopen("users_data.txt","r");
    while(!feof(users))
    {
        fgets(user,MAX_USER_LENGTH,users);
        p = strtok(user," ");
        if(strcmp(p, b->username) == 0)
        {
            fclose(users);
            return 1;
        }
    }
    fclose(users);
    return 0;
}
int CheckForPassword(buyer * b)
{
    char line[2*MAX_USER_LENGTH + 1], *p;
    FILE *users = fopen("users_data.txt","r");
    while(!feof(users))
    {
        fgets(line,MAX_USER_LENGTH,users);
        p = strtok(line," ");
        if(strcmp(p, b->username) == 0)
        {
            p = strtok(NULL, " ");
            p[strlen(p)-1] = '\0';
            Decryption(p);
            if(strcmp(p,b->password) == 0)
            {
                fclose(users);
                return 1;
            }
        }
    }
    fclose(users);
    return 0;
}
void SignUp(buyer * b, int *stateLogin)
{
    printf("--Username\n");
    scanf("%s",b->username);
    printf("--Password\n");
    scanf("%s",b->password);
    if (CheckForUsername(b) == 1)
    {
        printf("%s\n",DUPLICATE_USER);
        *stateLogin = 2;
    }
    else
    {
        if(!PasswordIsValid(b))
        {
            *stateLogin = 2;
        }
        else
        {
            //change nr of users
            UpdateNoOfUsers();
            //save user in file
            FILE * users = fopen("users_data.txt","a");
            Encryption(b->password);
            fprintf(users,"%s %s\n",b->username,b->password);
            *stateLogin = 99;
            fclose(users);
        }
    }
}
int PasswordIsValid(buyer * b)
{
    if(strlen(b->password) < 7)
    {
        printf("%s\n",ERROR_PASSWORD_LONG);
        return 0;
    }
    else if(strstr(b->password,b->username))
    {
        printf("%s\n",ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    else if(!(strchr(b->password,'.') || strchr(b->password,'_') || strchr(b->password,'!')))
    {
        printf("%s\n",ERROR_PASSWORD_SPECIAL_CHAR);
        return 0;
    }
    else
    {
        for(unsigned int i=0; i < strlen(b->password); i++)
        {
            if(strchr("0123456789",b->password[i]))
                return 1;
        }
        printf("%s\n",ERROR_PASSWORD_DIGITS);
        return 0;
    }
    return 1;
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
void Encryption (char * pass)
{
    char encryptedPass [MAX_USER_LENGTH];
    for(int i=0; i < strlen(pass); i++)
    {
        pass[i] = (int)(pass[i]) + 3;
    }
}
void Decryption (char * pass)
{
    char encryptedPass [MAX_USER_LENGTH];
    for(int i=0; i < strlen(pass); i++)
    {
        pass[i] = (int)(pass[i]) - 3;
    }
}
void UpdateNoOfUsers()
{
    FILE * users = fopen("users_data.txt","r+");
    int nrOfUsers = 0;
    char line[255];
    fgets(line,255,users);
    fgets(line,255,users);
    nrOfUsers = atoi(line);
    fseek(users,0,SEEK_SET);
    fprintf(users,"Caesar Code - 3 (Shift by 3)\n%d\n",nrOfUsers + 1);
    fclose(users);
}