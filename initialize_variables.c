//
// Created by csatl on 11/26/2019.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "variables.h"

void initNoOfFoods()
{
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    char line[500];
    fgets(line, MAX_LINE_CHARS, data_file);
    char *endptr;
    noOfFoods = strtol(line,&endptr,10);
    fclose(data_file);
}
void initNoOfFoodTypes()
{
    noOfFoodTypes = (int*)malloc(noOfFoods * sizeof(int));
}
void initNoOfDrinks()
{
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    char line[500];
    fgets(line, MAX_LINE_CHARS, data_file);
    char *endptr;
    int x = strtol(line,&endptr,10);
    for(int i=0; i <= x; i++){
        fgets(line, MAX_LINE_CHARS, data_file);
    }
    noOfDrinks = strtol(line,&endptr,10);
    fclose(data_file);
}
void initFoods()
{
    food = (char**)malloc(noOfFoods * sizeof(char*));
    for(int i = 0; i < noOfFoods; i++)
        food[i] = (char*) malloc(MAX_FOOD_NAME * sizeof(char));
}
void initFoodTypes()
{
    char line[500];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    types = (char***)malloc(noOfFoods * sizeof(char**));
    for(int i=0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        int noOfTypes = GetNoOfFoodTypes(line);
        types[i] = (char **) malloc(noOfTypes * sizeof(char*));
        for(int j = 0; j < noOfTypes; j++)
            types[i][j] = (char*) malloc (MAX_FOOD_TYPE_NAME * sizeof(char));
    }
    fclose(data_file);
}
void initFoodTypesPrices()
{
    char line[500];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);

    foodTypePrices = (double**)malloc(noOfFoods * sizeof(double*));
    for(int i=0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        foodTypePrices[i] = (double*) malloc (GetNoOfFoodTypes(line) * sizeof(double));
    }

    fclose(data_file);
}
void initDrinks()
{
    drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    for(int i = 0; i < noOfDrinks; i++)
        drinks[i] = (char*) malloc(MAX_DRINK_NAME * sizeof(char));
}
void initDrinkPrices()
{
    drinkPrices = (double*)malloc(noOfDrinks * sizeof(double));
}
int GetNoOfFoodTypes(char *line)
{
    int nr=0;
    for(int i=0; i < strlen(line); i++)
    {
        if(line[i] == '(')
            nr++;
    }
    return nr++;
}