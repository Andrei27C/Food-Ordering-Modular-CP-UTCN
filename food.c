//
// Created by csatl on 12/20/2019.
//
#include <stdlib.h>
#include <string.h>
#include "food.h"
#include "variables.h"

foodS createFood()
{
    foodS f;
    f.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    f.types = NULL;
    return f;
}
void loadFoodsS(foodS * f)
{
    char line[500], *p;
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    for(int i = 0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        p = strtok(line,":");
        p[strlen(p)-1] = '\0';
        strcpy(f[i].name,p);
    }
    fclose(data_file);
}
void loadNoOfFoodTypesS(foodS * f)
{
    char line[500];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    for(int i = 0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        f[i].noOfFoodTypes = GetNoOfFoodTypes(line);
    }
    fclose(data_file);
}