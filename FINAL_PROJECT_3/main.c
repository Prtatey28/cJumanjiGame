#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h> //used for printing information reguarding randomizing rooms and for unit test checking

#include "player.h"
#include "location.h"
#include "object.h"
#include "roomCreation.h"
#include "playerManagement.h"
#include "printing.h"
#include "commandInput.h"
#include "objectCreation.h"
#include "assertion.h"

int main(){
    //initialization steps
    system("clear");
    printf("SYSTEM: PROGRAM INITIALIZED\n");
    sleep(1);
    printf("SYSTEM: ASSESSING FUNCTIONALITY, PLEASE WAIT...\n");
    sleep(2);
    assertScore();
    assertMovement();
    printf("COMPLETE\n");
    sleep(1);
    printf("SYSTEM: RANDOMIZING ROOMS, PLEASE WAIT...\n");
    Location** roomsArray = createRooms();
    printf("COMPLETE\n");
    sleep(1);
    system("clear");
    //begin print statements
    printf("--------------------------PROGRAM START--------------------------");
    printJumanji();
    int exitGame = 0;
    printInstructions();
    //enter name function
    printf("\nPlease Enter Your Name: \n");
    printf("NOTE: Name can't be bigger than 50 characters & NO SPACES! (Press ENTER When Done)\n");
    char name[50];
    int err4 = 0;
    err4 = scanf("%50s", name); assert(err4);
    //creating player struct, beginning main while loop
    Player* player1 = createPlayer(name);
    printStatistics(player1, roomsArray);
    printf("\n--------------------------PLAYER TURN BEGIN--------------------------");
    while((exitGame==0)){
        printWhatToDo();
        exitGame = commandAssessment(player1, roomsArray);
    }
    convertHealth(player1); //converts remaining health to points
    printf("\nThank You For Playing %s!\n", playerName(player1)); //note this command was added after the video was made. only added player's name
    printf("Final Score: %d Points\n", playerScore(player1));
    deletePlayer(player1);
    deleteRooms(roomsArray);
    printf("--------------------------PROGRAM EXECUTION COMPLETED--------------------------\n");
    return 0;
}