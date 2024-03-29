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

void printDice(Dice (&die)[6]);

//initall roll of the dice takes an array of ints and randomly rolls them and displays what was rolled
void roll(Dice (&die)[6]) {//Changed from traversal by pointer to array index because this makes debugging easier
    Dice *dice;

    string action;
    for (int k = 0; k < 6; k++) {
        die[k] = (Dice) (rand() % 6);
    }
    for (int i = 5; i >= 0; i--) {
        switch (die[i]) {
            case arrow:
                action = "arrow  ";
                break;
            case dynamite:
                action = "dynamite";
                break;
            case oneShot:
                action = "one shot";
                break;
            case twoShot:
                action = "two shots";
                break;
            case gatGun:
                action = "gattling gun";
                break;
            case beer:
                action = "beer   ";
                break;
        }
        cout << endl << "player rolled a  " << action << "\t on dice " << i + 1;
    }
}

void printDice(Dice (&die)[6]) {
    string action;
    cout << "\n[";
    for (int i = 0; i < 6; i++) {
        switch (die[i]) {
            case arrow:
                action = "arrow  ";
                break;
            case dynamite:
                action = "dynamite";
                break;
            case oneShot:
                action = "one shot";
                break;
            case twoShot:
                action = "two shots";
                break;
            case gatGun:
                action = "gattling gun";
                break;
            case beer:
                action = "beer   ";
                break;
        }
        cout << i + 1 << ": " << action << "   ";
    }
    cout << "]\n";
}

//serperate function to test for reroll easier to implement the displaying of what a person rerolled this way ANDREW >:(
void reroll(Dice *dP, int *test) {
    Dice *dice;
    int *rerollOption;
    //srand(time(NULL));
    string action;
    for (int k = 0; k < 6; k++) {
        dice = dP + k;
        rerollOption = test + k;
        if (*rerollOption == 0) {
            *dice = (Dice) (rand() % 6);
            switch (*(dice)) {
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
        // cout << endl << "player has a " << action << " on dice " << k + 1;
    }
    cout << endl;

}


#endif
