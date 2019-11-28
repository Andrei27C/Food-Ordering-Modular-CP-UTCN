//
// Created by csatl on 11/28/2019.
//

#ifndef FOODORDERINGRMODULAR_LOGIN_H
#define FOODORDERINGRMODULAR_LOGIN_H
//constants
#define ERROR_PASSWORD_LONG	 "The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS "The password must contain digits"
#define SIGN_IN_UP "Do you want to sign in or sign up?"
#define SIGN_IN "Sign in"
#define SIGN_UP "Sign up"
#define SIGNING_IN "Signing in!"
#define SIGNING_UP "Signing up!"
#define USER_NOT_FOUND "Username doesn't exist"
#define DUPLICATE_USER "Please choose another username!"
#define INCORRECT_PASSWORD "Incorrect password"
#define MAX_USER_LENGTH 100
//function prototypes
void login(char *username, char *password);
void AskSign(int *stateLogin);
void SigningIn(char *username, char *password, int *stateLogin);
int CheckForUsername(char *username);
int CheckForPassword(char *username, char * password);
void SignUp(char *username, char *password, int *stateLogin);
int PasswordIsValid(char *username, char *password);
#endif //FOODORDERINGRMODULAR_LOGIN_H
