#ifndef PLAYERMANAGEMENT_H
#define PLAYERMANAGEMENT_H

//prints the location of the current player by assessing the inputted player's position integer and comparing it with the array of created rooms in the game.
void printPlayerLocation(Player * player, Location** rooms);

//prints the associated description of the location of the current player by assessing the inputted player's position integer and comparing it with the array of created rooms in the game.
void printPlayerLocationDescription(Player * player, Location** rooms);

//returns the name of the location of the current player by assessing the inputted player's position integer and comparing it with the array of created rooms in the game.
char* playerLocation(Player * player, Location** rooms);

//prints the statistics of the current player by assessing the many variables associated with the inputted player. (name, location, health, score, swordActive)
void printStatistics(Player * a, Location** daRooms);

//assesses the name variable of the object* that the player has indicated they want to pick up. If this name is equivalent to "Empty", -1 is returned, and the user gets sent back to commandInput3(). if the inventory of the inputted player is full, -2 is returned, and the player is sent back to commandInput3(). if the inventory of the inputted player is not full, and the item that was indicated to be picked up does not have the name "Empty", the name of the object is written over the first inventory slot it can find in the player's inventory that has the name "Empty". then the name value of the object is set to "Empty". after all of this has completed, 0 is returned, and the inputted player is sent back to commandInput2().
int pickUpItem(char* inputtedString, Object** inventory, Player* player, int i, Location** rooms2);

//requires pointer to current monster that is being fought, pointer to current player, and pointer to rooms array, used for determining the current location of the player. First the function assesses the inputted player's swordActive boolean to determine what to print for instructions. The function then prints out the statistics of the monster (by assesing what its name variable is) as well as the statistics of the player. the player is then prompted to enter a corresponding command to determine what it would like to do. if "ATTACK" is selected, random(1) is called, and depending on its output(0 or 1), health is either removed from the monster or the player. depending on variable swordActive on the inputted player, more or less damage is done on the monster, should the random(1) point to removing health from the monster. Additionally, after every attack phase, healthAssessment(player) is called, and will return -2 in the fightMonster() function, if healthAssessment() does not return zero. this will immediately return the player to commandInput2() and subsequently commandInput() to immediately exit the game. Afer healthAssessment(player) is called, getMonsterHealth(monster) is called to assess the health variable of the inputted monster. If monster health is less than or equal to zero, 0 is returned by the fightMonster() function, after adding to inputted player's score. Futhermore, if USEITEM is inputted by the player when initially selecting what to do, the equivalent logic of the USEITEM function below is commenced.
int fightMonster(Monster* monster, Player* player, Location** rooms2);

//assesses the name variable of the object* that is inputted(the item the player has indicated that it wants to use). if the name value of the inputted object* is "Empty", -1 is returned and the user will be sent back to commandInput4(). if the indicated object* name is equivalent to "Sword", "Score Bonus", or "Health Boost", the name of the object* at the index of the player's inventory will be set to "Empty" and the corresponding player.c function will run to adjust the player's statistics. input required: object* to item that is trying to be used, player's inventory array, pointer to player, index i of inventory slot that contains object that is trying to be used. returns 0 if object is successfully consumed/used. returns -2 if object has name that is not of the three object types currently in the game, and immediately terminates the game.
int useItem2(Object* item, Object** inventory, Player* player, int i);

#endif