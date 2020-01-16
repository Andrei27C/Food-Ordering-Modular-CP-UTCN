//
// Created by csatl on 12/20/2019.
//

#ifndef FOODORDERINGRMODULAR_FOOD_H
#define FOODORDERINGRMODULAR_FOOD_H

#include "type.h"

typedef struct _food{
    type * types;
    char * name;
    int noOfFoodTypes;
}foodS;

void loadFoods(foodS * f);
void loadNoOfFoodTypes(foodS * f);

#endif //FOODORDERINGRMODULAR_FOOD_H
