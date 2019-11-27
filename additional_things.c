//
// Created by csatl on 11/7/2019.
//
#include <stdio.h>
#include <string.h>

void askForCutlery(int *wantCutlery, int *choice, int *state)
{
    *wantCutlery = 0;
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No, thanks!\n");
    printf("c) Go back\n");
    *choice = getchar();
    //consume new line
    getchar();
    if(*choice == 'c') {
        *state = *state - 1;
        return;
    }
    else if(*choice == 'a')
        *wantCutlery = 1;
    *state = *state + 1;
}
void additionalInformation(char *additionalInfo, int *state)
{
    printf("Any additional info?\n");
    gets(additionalInfo);
    *state  = *state + 1;
}
void orderDisplay(char *username, char **food, int foodChoice, char ***types, int typeChoice, double **foodTypePrices, int nochosendrink, char **drinks, double *drinksPrices, int chosendrink, int wantCutlery, char additionalInfo[], int *orderConfirmed, int *choice, int *state)
{
    // Display order
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    //Food Items
    printf("Food items:\n");
    printf("---%s %s: (%.2f)\n", food[foodChoice], types[foodChoice][typeChoice], foodTypePrices[foodChoice][typeChoice]);
    double drinkPrice = 0;
    if(nochosendrink == 0)
    {
        drinkPrice = drinksPrices[chosendrink];
        printf("--- %s: (%.2f)\n", drinks[chosendrink], drinkPrice);
    }
    //cutlery
    if(wantCutlery == 1)
        printf("Cutlery: yes\n");
    else
        printf("Cutlery: no\n");
    //Additional info
    if(strcmp(additionalInfo,"") != 0)
        printf("Additional info: %s\n", additionalInfo);
    //Payment amount
    printf("Payment amount: %.2f\n", foodTypePrices[foodChoice][typeChoice] + drinkPrice);
    printf("-------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    //Confirmation
    *choice = getchar();
    if(*choice=='a') {
        *orderConfirmed = 1;
    } else {
        *state = *state - 1;
    }
    printf("Order confirmed! Thank you for buying from us, %s!\n", username);
    // consume new line
    getchar();
}