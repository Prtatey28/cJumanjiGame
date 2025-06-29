#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>

typedef struct _player Player;
typedef struct _object Object;

//creates a new player on the heap. Takes in name input. it returns pointer to new object stored on the heap.
Player* createPlayer(char* name_in);

void deletePlayer(Player* player);

//adjusts the value of variable position the inputted player to increase by one, assuming it is less than 2. returns 0 if successful movement occurs, negative 1 if unsuccessful movement occurs.
int moveUp(Player * currentPlayer);

//adjusts the value of variable position the inputted player to decrease by one, assuming it is greater than 0. returns 0 if successful movement occurs, negative 1 if unsuccessful movement occurs.
int moveBack(Player * currentPlayer);

//returns value of position integer stored on inputted player.
int playerPosition(Player * currentPlayer);

//returns value of health integer stored on inputted player.
int playerHealth(Player * currentPlayer);

//returns value of score integer stored on inputted player.
int playerScore(Player * currentPlayer);

//returns value of name string stored on inputted player.
char* playerName(Player * currentPlayer);

//increases player score by the inputted amount integer. returns 0 if successful.
int scoreAdd(Player * currentPlayer, int ammount);

//prints all stored objects inside the inventory variable stored on the inputted player. Note that the inventory of the player is an array of object pointers.
void printInventory(Player* p);

//returns the array of object pointers store within the inventory variable on the inputted player.
Object** getPlayerInventory(Player* p);

//this function is run at the very end of the game, before everything gets freed. It takes the current value of the inputted player's health, and add's it to the score variable of the player, before the final score at the end of the game gets printed.
void convertHealth(Player* p);

//this function assesses the health variable of the inputted player and returns -1 if player health is below or equivalent to zero. It returns zero otherwise.
int healthAssessment(Player * p);

//returns value of swordActive boolean stored on inputted player. if inputted player is NULL, function returns NULL and prints error.
bool playerSwordStatus(Player * currentPlayer);

//lowers the value of health integer on the inputted player by 10 points. returns nothing.
void removePlayerHealth(Player * currentPlayer);

//increases the value of the score integer on the inputted player by the inputted integer score. returns nothing.
void playerScoreIncrease(Player * currentPlayer, int score);

//increases the health on the inputted player by 10 points. returns nothing.
void addPlayerHealth(Player * currentPlayer);

//sets the boolean variable of swordActive on the inputted player to be true. returns nothing.
void playerSetSword(Player * currentPlayer);

//returns the object* at an inputted index i of the inputted player's inventory
Object* getInventoryObject(Player* p, int i);

#endif