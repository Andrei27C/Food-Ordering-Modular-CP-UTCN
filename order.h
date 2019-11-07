//
// Created by csatl on 11/7/2019.
//

#ifndef FOODORDERINGRMODULAR_ORDER_H
#define FOODORDERINGRMODULAR_ORDER_H

//function prototypes
void foodChoosing(int noOfFood, int *choice, char food[][10], int *foodChoice, int *state);
void foodTypeChoosing(int noOfFood, int *choice, char food[][10], int *foodChoice, char types[][4][15], double prices[][4], int *typeChoice, int *state);
void drinkChoosing(int noDrinks, int *choice, char food[][10], int *foodChoice, char drinks[][15], double drinksPrices[], int *nochosendrink, int *chosendrink, int *state);
void askForCutlery(int *wantCutlery, int *choice, int *state);
void additionalInformation(char *additionalInfo, int *state);
void orderDisplay(char username[], int food[][10], int foodChoice, char types[][4][15], int typeChoice, double prices[][4], int nochosendrink, char drinks[][15], double drinksPrices[], int chosendrink, int wantCutlery, char additionalInfo[], int *orderConfirmed, int *choice, int *state);




#endif //FOODORDERINGRMODULAR_ORDER_H
