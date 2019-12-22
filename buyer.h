//
// Created by csatl on 11/7/2019.
//

#ifndef FOODORDERINGRMODULAR_BUYER_H
#define FOODORDERINGRMODULAR_BUYER_H

#define MAX_USER_LENGTH 100

typedef struct _buyer{
    char *username;
    char *password;
}buyer;

//function prototypes
buyer CreateBuyer ();
void login(buyer * b);
void SigningIn(buyer * b, int *stateLogin);
int CheckForUsername(buyer * b);
int CheckForPassword(buyer * b);
void SignUp(buyer * b, int *stateLogin);
int PasswordIsValid(buyer * b);
void AskSign(int *stateLogin);
void Encryption (char * pass);
void Decryption (char * pass);
void UpdateNoOfUsers();

#endif //FOODORDERINGRMODULAR_BUYER_H
