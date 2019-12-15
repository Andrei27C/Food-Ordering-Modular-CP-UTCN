//
// Created by csatl on 11/7/2019.
//

#ifndef FOODORDERINGRMODULAR_ORDER_H
#define FOODORDERINGRMODULAR_ORDER_H

//function prototypes
void foodChoosing(int noOfFood, int *choice, char **food, int *foodChoice, int *state);
void foodTypeChoosing(int noOfFood, int *choice, char **food, int *foodChoice, char ***types, double **foodTypePrices, int *typeChoice, int *state);
void drinkChoosing(int noDrinks, int *choice, char **food, int *foodChoice, char **drinks, double *drinksPrices, int *nochosendrink, int *chosendrink, int *state);
void askForCutlery(int *wantCutlery, int *choice, int *state);
void additionalInformation(char *additionalInfo, int *state);
void orderDisplay(char *username, char **food, int foodChoice, char ***types, int typeChoice, double **foodTypePrices, int nochosendrink, char **drinks, double *drinksPrices, int chosendrink, int wantCutlery, char additionalInfo[], int *orderConfirmed, int *choice, int *state);




#endif //FOODORDERINGRMODULAR_ORDER_H
