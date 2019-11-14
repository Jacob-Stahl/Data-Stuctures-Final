#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef ROLL_H
#define ROLL_H
/*struct node
{
  int roll;
  int reroll;

};
void Roll(struct node* dice)
{
  int dynoCheck = dice->roll;
  int rerollCheck = dice->reroll;
  if(dynoCheck != 2 && rerollCheck < 3 )
  {
    dice->roll = rand() % 6 + 1;
  }  
}
void turn(struct node* diceCup)
{
  int quote;
  struct node 
  
  for(int k = 0 ; k <= 6 ; k++)
  {
    while(diceCup+k.reroll < 3)
    {
      Roll(diceCup+k);
      quote = (diceCup+k)->roll;
      switch(quote)
      {
        case 1: cout << endl << "Player rolled an arrow"; // show dice with for loop possibly
          break;
        case 2: cout << endl << "Player rolled a dynomite";
          break;
        case 3: cout << endl << "Player rolled one shot";
          break;
        case 4: cout << endl << "Player rolled two shots";
          break;
        case 5: cout << endl << "Player rolled a gatling gun";
          break;
        case 6: cout << endl << "Player rolled a beer";
          break;
      }
    }
  }
}
void Reroll()
{
  int checkRoll;
  checkRoll = rand() % 2;
  if((diceCup+k)->roll != 2 && checkRoll == 0 && (diceCup+k).reroll < 3)
  {
      cout << endl << "Player will reroll this dice"
  }
}*/
void initialRoll(int* diceCup)
{
  int* dice;
  for(int k = 0 ; k < 6 ; k++)
  {
    dice = diceCup + k;
    *dice = rand() %6 + 1;
  }
  for(int i = 0; i < 6 ; i++)
    cout << endl << "player rolled a " << *(diceCup+i) << " on dice " << i+1;
}
void rerolls(int* diceCup)
{
  int* dice;
  int chance;
  for(int j = 0 ; j < 3; j++)
  {
    for(int k = 0 ; k < 6 ; k++)
    {
      dice = diceCup + k;
      chance = rand() %2;
      if(*dice != 2 && chance == 1)
      {
        *dice = rand() %6 + 1;
        cout << endl << "player rerolled a " << *(diceCup+k) << " on dice " << k+1;
      }
      // any code past this point in the function is to apply the dice effects per turn
    }
  }
}
int main()
{
  int endTurn = 0;
  int diceCup[6];
  initialRoll(diceCup);
  // apply the intials rolls i.e. arrows and if they rolled 3 dynomite
  for(int k = 0 ; k < 6 ; k++) // check all dice on the initial roll should probally be implemented in the reroll aswell
  {
    if(*(diceCup+k) == 2 )
      endTurn++;
    if(*(diceCup+k) == 1 )
      //player needs to take an arrow
    if(endturn >= 3)
      //end the players turn implement at end of the roll
  }
  cout << endl;
  rerolls(diceCup);
  //after rerolls apply the other dice accordingly  
}

#endif
