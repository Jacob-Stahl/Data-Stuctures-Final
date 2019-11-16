#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
/* Function Name: roll
  Function Inputs: Dice array
  Function Purpose: Randomly assigns the dice
  
  Function Name: reroll
  Function Inputs: Dice array and array of boolean corressponding to dice array to determine if dice is to be rerolled
  Function Purpose: Randomly assigns the dice that are to be rerolled t*/

#ifndef ROLL_H
#define ROLL_H

//did not implement enum :(
enum Dice {
    arrow, dynamite, oneShot, twoShot, beer, gatGun
};

Dice diceCup[6];

//initall roll of the dice takes an array of ints and randomly rolls them and displays what was rolled
void roll(Dice *dP) {
    Dice *dice;
    srand(time(NULL));
    string action;
    for (int k = 0; k < 6; k++) {
        dice = dP + k;
        *dice = (Dice) (rand() % 6);
    }
    for (int i = 0; i < 6; i++) {
        switch (*(dice + i)) {
            case 0:
                action = "arrow";
                break;
            case 1:
                action = "dynamite";
                break;
            case 2:
                action = "one shot";
                break;
            case 3:
                action = "two shots";
                break;
            case 4:
                action = "gattling gun";
                break;
            case 5:
                action = "beer";
                break;
        }
        cout << endl << "player rolled a " << action << " on dice " << i + 1;
    }
}

//serperate function to test for reroll easier to implement the displaying of what a person rerolled this way ANDREW >:(
void reroll(Dice *dP, int *test) {
    Dice *dice;
    int *rerollOption;
    srand(time(NULL));
    string action;
    for (int k = 0; k < 6; k++) {
        dice = dP + k;
        rerollOption = test + k;
        if (*rerollOption == 1) {
            *dice = (Dice) (rand() % 6);
            switch (*(diceCup + k)) {
                case 0:
                    action = "arrow";
                    break;
                case 1:
                    action = "dynomite";
                    break;
                case 2:
                    action = "one shot";
                    break;
                case 3:
                    action = "two shots";
                    break;
                case 4:
                    action = "gattling gun";
                    break;
                case 5:
                    action = "beer";
                    break;
            }
            cout << endl << "player rerolled a " << action << " on dice " << k + 1;
        }
    }

}


#endif
