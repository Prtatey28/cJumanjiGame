#ifndef COMMANDINPUT_H
#define COMMANDINPUT_H

typedef struct _location Location;
typedef struct _object Object;

//reads in player command from path location, and runs respective commands based on inputted results. Note this command assessment does not use the string library, and is a lot less efficient, only comparing each of the inputted characters that the user typed out. Returning 0, ensures that the while loop of the main program continues. Returning -1, exits while loop, and ends game.
int commandAssessment(Player* player, Location** rooms2);

//reads in player command of player giving a number between 0-3. if zero is inputted, -1 is returned, sending player immidiately back to command assessment #2. the player can still move around and play the game.
int commandAssessment3(int printStatement, Player* player, Location** rooms2);

//reads in player command from path location, and runs respective commands based on inputted results. Returning 0, ensures that the while loop of this command assessment continues. Note this command assessment does not use the string library, and is a lot less efficient, only comparing each of the inputted characters that the user typed out. Returning -1, exits while loop, and sends player back to commandAssessment input. This would be the path command input. If -2 is returned, player is send back to commandAssessment input, which will then immediately return -1 and exit the game.
int commandAssessment2(Player* player, Location** rooms2);

//reads in player command of player giving a number between 0-2. if zero is inputted, -1 is returned, sending player immidiately back to command assessment #2. the player can still move around and play the game.
int commandAssessment4(int printStatement2, Player* player);

#endif