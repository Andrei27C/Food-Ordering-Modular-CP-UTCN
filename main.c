#include <stdio.h>
#include <stdlib.h>
#include "buyer.h"
#include "order.h"
#include "data_loading.h"
#include "variables.h"
#include "free_memory.h"

#define LOAD_DATA "Please load the data"
#define MAX_DRINK_NAME 30
void afisTypes();
void afisDrinks();
void loadData();

int main() {
    /*
    puts("");
    char line[500];
    data_file = fopen("food_data.txt","r");
    data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    puts(line);
    fclose(data_file);
    puts("");
*/
    int wantCutlery = 0,  state =0, orderConfirmed = 0;
    char additionalInfo[200], username[20], password[20];
    int choice, foodChoice, chosendrink, nochosendrink=0, typeChoice;
    // todo
    loadData(getConsole);
    printf("Welcome to Food Thingies!\n");
    while(!orderConfirmed){
        switch (state) {
            case 0: {
                inputLogin(username, password, &state);
                break;
            }
            case 1: {
                foodChoosing(noOfFoods, &choice, food, &foodChoice, &state);
                break;
            }
            case 2: {
                foodTypeChoosing(noOfFoods, &choice, food, &foodChoice, types, foodTypePrices, &typeChoice, &state);
                break;
            }
            case 3: {
                drinkChoosing(noOfDrinks, &choice, food, &foodChoice, drinks, drinkPrices, &nochosendrink, &chosendrink, &state);
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
                orderDisplay(username, food, foodChoice, types, typeChoice, foodTypePrices, nochosendrink, drinks, drinkPrices,
                             chosendrink, wantCutlery, additionalInfo, &orderConfirmed, &choice, &state);
                break;
            }
        }
    }
    freeFood();
    freeDrinks();
    return 0;
}

void afisTypes()
{
    puts("\n----Foods:");
    for(int i=0;i<noOfFoods;i++)
    {
        printf(" --%s\n", food[i]);
        for(int j=0;j<noOfFoodTypes[i];j++)
            printf(" %s - %.2f\n", types[i][j], foodTypePrices[i][j]);
        printf("\n");
    }
}
void afisDrinks()
{
    puts("\n----Drinks:");
    for(int i=0;i<noOfDrinks;i++)
    {
        printf(" %s - %.2f\n",drinks[i],drinkPrices[i]);
    }
}
void loadData(int getConsole)
{
    if(getConsole == 1)
        puts(LOAD_DATA);
    puts("");
    initNoOfFoods();
    initFoods();
    initNoOfFoodTypes();
    initFoodTypes();
    initFoodTypesPrices();
    initNoOfDrinks();
    initDrinks();
    initDrinkPrices();

    loadFoods();
    loadFoodTypes();
    afisTypes();

    loadDrinks();
    afisDrinks();
    puts("");
}