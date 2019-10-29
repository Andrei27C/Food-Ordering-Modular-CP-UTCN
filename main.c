#include <stdio.h>

int main() {
    asddddddddd
    printf("Welcome to Food Thingies!\n");

    // food data
    int noOfFood = 3;
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
    int noDrinks = 4;
    char drinks[][15] = {"Coca-cola","Fanta","Lipton","Water"};
    double drinksPrices[] = {5,5,5,4};
    //cutlery
    int wantCutlery = 0;
    //additional info
    char additionalInfo[200];
    //user input
    char username[20];
    char password[20];
    int choice, foodChoice, typeChoice;
    int chosendrink;
    int nochosendrink=0;

    int state =0;
    int orderConfirmed = 0;
    while(!orderConfirmed){
        switch (state) {
            case 0: {
                // sign in
                printf("Please sign in to continue!\n");
                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1: {
                // Choose the Food
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOfFood;i++) {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                }
                printf("%c) Go back\n",'a'+noOfFood);
                choice = getchar();
                // consume new line
                getchar();
                if(choice == 'a'+noOfFood) {
                    state--;
                    break;
                }
                foodChoice = choice - 'a';
                state++;
                break;
            }
            case 2: {
                // Choose the food type
                printf("Please choose the type of %s:\n",food[foodChoice]);
                for(int i=0;i<noOfFood;i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n",types[foodChoice][i], prices[foodChoice][i]);
                }
                printf("%c) Go back\n",'a'+noOfFood);
                choice = getchar();
                // consume new line
                getchar();
                if(choice == 'a'+noOfFood) {
                    state--;
                    break;
                }
                typeChoice = choice - 'a';
                state++;
                break;
            }
            case 3: {
                // Choose the drinks
                nochosendrink = 0;
                printf("Please choose a drink to go with your %s:\n",food[foodChoice]);
                for(int i=0;i<noDrinks;i++) {
                    putchar('a'+i);
                    printf(") %s (%.2f)\n", drinks[i], drinksPrices[i]);
                }
                printf("%c) No, thanks!\n",'a'+noDrinks);
                printf("%c) Go back\n",'a'+noDrinks+1);

                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'a'+noDrinks+1) {
                    state--;
                    break;
                }
                else if(choice == 'a' + noDrinks)
                    nochosendrink = 1;
                chosendrink = choice - 'a';
                state++;
                break;
            }
            case 4: {
                // Ask for cutlery
                wantCutlery = 0;
                printf("Do you want cutlery?\n");
                printf("a) Yes\n");
                printf("b) No, thanks!\n");
                printf("c) Go back\n");
                choice = getchar();
                //consume new line
                getchar();
                if(choice == 'c') {
                    state--;
                    break;
                }
                else if(choice == 'a')
                    wantCutlery = 1;
                state++;
                break;
            }
            case 5:{
                // Display order
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name: %s\n", username);
                //Food Items
                printf("Food items:\n");
                printf("---%s %s: (%.2f)\n", food[foodChoice], types[foodChoice][typeChoice], prices[foodChoice][typeChoice]);
                double drinkPrice = 0;
                if(nochosendrink == 0)
                {
                    drinkPrice = drinksPrices[chosendrink];
                    printf("---%s: (%.2f)\n", drinks[chosendrink], drinkPrice);
                }
                //cutlery
                if(wantCutlery == 1)
                    printf("Cutlery: yes\n");
                else
                    printf("Cutlery: no\n");
                //Additional info
                printf("Additional info: ");
                gets(additionalInfo);
                //Payment amount
                printf("Payment amount: %.2f\n", prices[foodChoice][typeChoice] + drinkPrice);
                printf("-------------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                //Confirmation
                choice = getchar();
                if(choice=='a') {
                    orderConfirmed = 1;
                } else {
                    state--;
                }
                printf("Order confirmed! Thank you for buying from us, %s!\n", username);
                // consume new line
                getchar();
                break;
            }
        }
    }
    return 0;
}