#include <stdio.h>
#include "buyer.h"
#include "order.h"

#define noOfFood 3
#define noDrinks 4

int main() {
    int wantCutlery = 0,  state =0, orderConfirmed = 0;
    char additionalInfo[200], username[20], password[20];
    int choice, foodChoice, chosendrink, nochosendrink=0, typeChoice;
    char drinks[][15] = {"Coca-cola","Fanta","Lipton","Water"};
    double drinksPrices[] = {5,5,5,4};
    char food[][10] = {"Pizza","Pasta","Salad"};
    int noTypes[] = {3,2,4};
    char types[3][4][15] = {
            {"Carbonara", "Diavola", "Margherita",""},
            {"Chicken alfredo", "Mac&cheese", "",""},
            {"Tuna", "Chicken", "Greek","Cobb"}
    };
    double prices[3][4] = {
            {21, 23, 23, 0},
            {23, 21, 0, 0},
            {23, 22, 19, 21}
    };
    printf("Welcome to Food Thingies!\n");
    while(!orderConfirmed){
        switch (state) {
            case 0: {
                inputLogin(username, password, &state);
                break;
            }
            case 1: {
                foodChoosing(noOfFood, &choice, food, &foodChoice, &state);
                break;
            }
            case 2: {
                foodTypeChoosing(noOfFood, &choice, food, &foodChoice, types, prices, &typeChoice, &state);
                break;
            }
            case 3: {
                drinkChoosing(noDrinks, &choice, food, &foodChoice, drinks, drinksPrices, &nochosendrink, &chosendrink, &state);
                break;
            }
            case 4: {
                askForCutlery(&wantCutlery, &choice, &state);
                break;
            }
            case 5: {
                additionalInformation(additionalInfo, &state);
                break;
            }
            case 6:{
                orderDisplay(username, food, foodChoice, types, typeChoice, prices, nochosendrink, drinks, drinksPrices,
                        chosendrink, wantCutlery, additionalInfo, &orderConfirmed, &choice, &state);
                break;
            }
        }
    }
    return 0;
}