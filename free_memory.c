//
// Created by csatl on 11/27/2019.
//

#include <stdlib.h>
#include "free_memory.h"
#include "variables.h"
void freeFood()
{
    for(int i=0;i<noOfFoods;i++) {
        for(int j=0; j < noOfFoodTypes[i]; j++) {
            free(types[i][j]);
        }
        free(types[i]);
        free(foodTypePrices[i]);
        free(food[i]);
    }

    free(types);
    free(foodTypePrices);
    free(food);
    free(noOfFoodTypes);
}
void freeDrinks()
{
    for(int i=0;i<noOfDrinks;i++)
    {
        free(drinks[i]);
    }
    free(drinks);
    free(drinkPrices);
}
