//
// Created by csatl on 11/26/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "data_loading.h"
#include "variables.h"

void getNameAndPrice(int i, char *line, char * s, char *name, double *price);
void getName(char *s, char *name);
double getPrice(char *s);


void loadFoods()
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
        strcpy(food[i],p);
    }
    fclose(data_file);
}
void loadNoOfFoodTypes()
{
    char line[500];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    for(int i = 0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        noOfFoodTypes[i] = GetNoOfFoodTypes(line);
    }
    fclose(data_file);
}
void loadFoodTypes()
{
    loadNoOfFoodTypes();
    char line[500], s[MAX_LINE_CHARS];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    for(int i = 0; i < noOfFoods; i++)
    {
        fgets(line, MAX_LINE_CHARS, data_file);
        int cnt=0;
        for(int j=0; j < strlen(line); j++)
        {
            if(line[j] == '(')
            {
                getNameAndPrice(j,line,s,types[i][cnt], &foodTypePrices[i][cnt])
                cnt++;
            }
        }
    }
    fclose(data_file);
}
void loadDrinks()
{
    char line[500], s[MAX_LINE_CHARS];
    data_file = fopen("food_data.txt","r");
    if(getConsole == 1)
        data_file = stdin;
    fgets(line, MAX_LINE_CHARS, data_file);
    for(int i=0; i <= noOfFoods; i++)
        fgets(line, MAX_LINE_CHARS, data_file);
    fgets(line, MAX_LINE_CHARS, data_file);
    int cnt = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '(')
        {
            getNameAndPrice(i,line,s,drinks[cnt], &drinkPrices[cnt]);
            cnt++;
        }

    }
    fclose(data_file);
}
void getNameAndPrice(int i, char *line, char * s, char *name, double *price)
{
    i++;
    for(int i=0; i < MAX_LINE_CHARS; i++)
        s[i]='\0';
    int j=0;
    while(line[i] != ')')
    {
        s[j] = line[i];
        i++; j++;
    }
    getName(s, name);
    *price = getPrice(s);

}
void getName(char *s, char *name) {
    char cs[500], p[500];
    for(int i=0; i < 500; i++)
    {
        cs[i] = '\0';
        p[i] = '\0';
    }
    strcpy(cs, s);
    int i = 0;
    while (!isdigit(cs[i])) {
        p[i] = cs[i];
        i++;
    }
    i = strlen(p)-1;
    while (!isalpha(p[i]))
    {
        p[i] = '\0';
        i--;
    }
    strcpy(name,p);
}
double getPrice(char *s)
{
    char cs[500];
    int i = 0;
    while(!isdigit(s[i]))
        i++;
    strcpy(cs, s+i);
    char *endptr;
    return strtod(cs, &endptr);
}