//
// Created by csatl on 12/20/2019.
//

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "type.h"
#include "food.h"
#include "variables.h"
void getNameAndPriceS(int i, char *line, char * s, char *name, double *price);
void getNameS(char *s, char *name);
double getPriceS(char *s);

void loadFoodTypesS(foodS * f)
{
    loadNoOfFoodTypes(f);
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
                cnt++;
            }
        }
    }
    fclose(data_file);
}
void getNameAndPriceS(int i, char *line, char * s, char *name, double *price)
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
    getNameS(s, name);
    *price = getPriceS(s);

}
void getNameS(char *s, char *name)
{
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
double getPriceS(char *s)
{
    char cs[500];
    int i = 0;
    while(!isdigit(s[i]))
        i++;
    strcpy(cs, s+i);
    char *endptr;
    return strtod(cs, &endptr);
}
