//
// Created by csatl on 11/7/2019.
//

#include <stdio.h>

void foodChoosing(int noOfFood, int *choice, char **food, int *foodChoice, int *state)
{
    // Choose the Food
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFood;i++) {
        putchar('a'+i);
        printf(") %s\n",food[i]);
    }
    printf("%c) Go back\n",'a'+noOfFood);
    *choice = getchar();
    // consume new line
    getchar();
    if(*choice == 'a'+noOfFood) {
        *state = *state - 1;
        return;
    }
    *foodChoice = *choice - 'a';
    *state = *state + 1;
}
void foodTypeChoosing(int noOfFood, int *choice, char **food, int *foodChoice, char ***types, double **foodTypePrices, int *typeChoice, int *state)
{
    // Choose the food type
    printf("Please choose the type of %s:\n",food[*foodChoice]);
    for(int i=0;i<noOfFood;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n",types[*foodChoice][i], foodTypePrices[*foodChoice][i]);
    }

    printf("%c) Go back\n",'a'+noOfFood);
    *choice = getchar();
    getchar();
    if(*choice == 'a'+noOfFood) {
        *state = *state - 1;
        return;
    }
    *typeChoice = *choice - 'a';
    *state = *state + 1;
}
void drinkChoosing(int noDrinks, int *choice, char **food, int *foodChoice, char **drinks, double *drinksPrices, int *nochosendrink, int *chosendrink, int *state)
{
    printf("Please choose a drink to go with your %s:\n",food[*foodChoice]);
    for(int i=0;i<noDrinks;i++) {
        putchar('a'+i);
        printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
    }
    printf("%c) No, thanks!\n",'a'+noDrinks);
    printf("%c) Go back\n",'a'+noDrinks+1);

    *choice = getchar();
    //consume new line
    getchar();
    if(*choice == 'a'+noDrinks+1) {
        *state = *state - 1;
        return;
    }
    else if(*choice == 'a' + noDrinks)
        *nochosendrink = 1;
    *chosendrink = *choice - 'a';
    *state = *state + 1;
}