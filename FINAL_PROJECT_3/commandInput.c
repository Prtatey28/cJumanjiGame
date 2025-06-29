#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "player.h" //for all Player* type functions
#include "location.h" //for all Location* type functions
#include "playerManagement.h" //for printStatistics() and printPlayerLocation() functions
#include "commandInput.h"
#include "inventory.h"
#include "printing.h"
#include "monster.h"
#include "monsterCreation.h"

int commandAssessment(Player* player, Location** rooms2){
    char command[9];
    char* inventory = "INV";
    char* statistics = "STATS";
    char* location = "LOC";
    char* roomInfo = "ENTER";
    char* goUp = "GOUP";
    char* goBack = "GOBACK";
    char* quit = "QUIT";
    int inv2 = 0;
    int loc2 = 0;
    int roomInfo2 = 0;
    int stats2 = 0;
    int goUp2 = 0;
    int goBack2 = 0;
    int quit2 = 0;
    int err = 0;
    int length = 0;
    err = scanf("%9s", command); assert(err); //This ensures that if we encounter a string bigger than length 7, it will split it into multiple strings, hopefully, combating stack smashing.
    system("clear");
    printf("INPUTTED COMMAND: %s\n",command);
    int i=0;
    while(command[i]!='\0'){
        length++;
        i++;
    }
    if(length>9){
        printf("INVALID INPUT (STRING BIGGER THAN POSSIBLE COMMAND SIZE) Please Try Again.\n");
        printf("--------------------------TRY AGAIN--------------------------");
        return 0;
    }
    //assessing for each value of the inputted command whether or not it is equivalent to a hardcoded command
    for(int j=0; j<length; j++){
        int runThrough = 0;
        if(command[j]==inventory[j]){
            inv2++;
            runThrough++;
        }
        if(command[j]==statistics[j]){
            stats2++;
            runThrough++;
        }
        if(command[j]==location[j]){
            loc2++;
            runThrough++;
        }
        if(command[j]==roomInfo[j]){
            roomInfo2++;
            runThrough++;
        }
        if(command[j]==goUp[j]){
            goUp2++;
            runThrough++;
        }
        if(command[j]==goBack[j]){
            goBack2++;
            runThrough++;
        }
        if(command[j]==quit[j]){
            quit2++;
            runThrough++;
        }
        if(runThrough==0){
            inv2--;
            loc2--;
            roomInfo2--;
            stats2--;
            goUp2--;
            goBack2--;
            quit2--;
        }
    }
    if(inv2 == 3){
        printf("You Selected To Print Inventory!");
        printf("\n\n--------------------------INVENTORY INFORMATION--------------------------");
        printInventory(player);
        printJumanji();
        printf("\n");
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return 0;
    }
    if(stats2 == 5){
        printf("You Selected To Print Statistics!");
        printf("\n\n--------------------------STATISTICS INFORMATION--------------------------");
        printStatistics(player, rooms2);
        printJumanji();
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return 0;
    }
    if(loc2 == 3){
        printf("You Selected To Print Location!");
        printf("\n\n--------------------------LOCATION INFORMATION--------------------------");
        printPlayerLocation(player, rooms2);
        printPlayerLocationDescription(player, rooms2);
        printJumanji();
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return 0;
    }
    if(roomInfo2 == 5){
        printf("You Selected To Enter The Current Room!");
        printf("\n\n--------------------------ENTERING ROOM--------------------------\n");
        printf("*\n");
        printf("*\n");
        printf("*\n");
        printf("\n--------------------------ROOM INFORMATION--------------------------");
        int roomInteract = 0;
        while(roomInteract == 0){
            roomInteract = commandAssessment2(player, rooms2);
        }
        if(roomInteract == -2){ //immediately exits game if -2 is returned.
            return -1;
        }
        return 0;
    }
    if(goUp2 == 4){
        printf("You Selected To Go Up!");
        printf("\n\n--------------------------MOVING UP--------------------------\n");
        printf("*\n");
        printf("*\n");
        printf("*\n");
        moveUp(player);
        printJumanji();
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return 0;
    }
    if(goBack2 == 6){
        printf("You Selected To Go Back!");
        printf("\n\n--------------------------MOVING BACK--------------------------\n");
        printf("*\n");
        printf("*\n");
        printf("*\n");
        moveBack(player);
        printJumanji();
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return 0;
    }
    if(quit2 == 4){
        printf("You Selected To Exit!");
        printf("\n--------------------------FINAL RESULTS--------------------------");
        return -1;
    }
    else{
        printf("INVALID COMMAND. Please Try Again!\n");
        printf("--------------------------TRY AGAIN--------------------------");
        printJumanji();
        printPlayerLocation(player, rooms2);
        return 0;
    }
    return 0;
}

int commandAssessment3(int printStatement, Player* player, Location** rooms2){
    int err3 = 0;
    int check2 = 0;
    char command3[50];
    while(check2==0){ 
        if(printStatement==0){
            printf("\nWhich Room Item Would You Like To Pick Up? (Please Type A Number Below OR Type 0 to cancel)\n");
        }
        else if(printStatement==1){
            printf("\nWhich Monster Would You Like To Fight? (Please Type A Number Below OR Type 0 to cancel)\n");
        }
        else if(printStatement==2){
            printf("\nWhich Item Would You Like To Use? (Please Type A Number Below OR Type 0 to cancel)\n");
        }
        else{
            printf("\nPRINT STATEMENT ERROR\n");
        }
        err3 = scanf("%50s", command3); assert(err3);
        if(!strcmp(command3,"0")){
            check2++;
            return -1;
        }
        if(!strcmp(command3,"1")){
            check2++;
            return 0;
        }
        if(!strcmp(command3,"2")){
            check2++;
            return 1;
        }
        if(!strcmp(command3,"3")){
            check2++;
            return 2;
        }
        else{
            system("clear");
            printf("INPUTTED COMMAND: %s\n",command3);
            printf("INVALID COMMAND. Please Try Again!\n");
            printf("--------------------------TRY AGAIN--------------------------\n");
            if(printStatement==0){
                printf("\nWhich Room Item Would You Like To Pick Up? (Please Type A Number Below OR Type 0 to cancel)\n");
                printObjects(player, rooms2);
            }
            else if(printStatement==1){
                printMonsters(player, rooms2);
            }
            else if(printStatement==2){
                printf("\nWhich Item Would You Like To Use? (Please Type A Number Below OR Type 0 to cancel)\n");
                printObjects(player, rooms2);
            }
            else{
                printf("\nPRINT STATEMENT ERROR\n");
            }
        }
    }
    return -1;
}

int commandAssessment4(int printStatement2, Player* player){
    int err4 = 0;
    int check3 = 0;
    char command4[50];
    while(check3==0){
        if(printStatement2==2){
            printf("\nWhich Item Would You Like To Use? (Please Type A Number Below OR Type 0 to cancel)\n");
        }
        else{
            printf("\nPRINT STATEMENT ERROR\n");
        }
        err4 = scanf("%50s", command4); assert(err4);
        if(!strcmp(command4,"0")){
            check3++;
            return -1;
        }
        if(!strcmp(command4,"1")){
            check3++;
            return 0;
        }
        if(!strcmp(command4,"2")){
            check3++;
            return 1;
        }
        else{
            system("clear");
            printf("INPUTTED COMMAND: %s\n",command4);
            printf("INVALID COMMAND. Please Try Again!\n");
            printf("--------------------------TRY AGAIN--------------------------\n");
            printInventory(player);
        }
    }
    return -1;
}

int commandAssessment2(Player* player, Location** rooms2){
    int location4 = 0;
    location4 = playerPosition(player);
    if(location4==0){
        printSavanah();
    }
    else if(location4==1){
        printJungle();
    }
    else if(location4==2){
        printTemple();
    }
    printPlayerLocation(player, rooms2);
    printPlayerLocationDescription(player, rooms2);
    printObjects(player, rooms2);
    printMonsters(player, rooms2);
    printf("\n--------------------------PLAYER COMMAND--------------------------");
    printRoomInstructions();
    char command2[8];
    char* stats3 = "STATS";
    char* pickup = "PICKUP";
    char* fight = "FIGHT";
    char* useItem = "USEITEM";
    char* quit3 = "EXIT";
    char* inv3 = "INV";
    int err2 = 0;
    err2 = scanf("%8s", command2); assert(err2);
    system("clear");
    printf("INPUTTED COMMAND: %s\n",command2);
    int stats4 = 0;
    int inv4 = 0;
    int pickup3 = 0;
    int fight3 = 0;
    int useItem3 = 0;
    int quit4 = 0;
    int length2 = 0;
    int i2=0;
    while(command2[i2]!='\0'){
        length2++;
        i2++;
    }
    if(length2>8){
        printf("INVALID INPUT (STRING BIGGER THAN POSSIBLE COMMAND SIZE) Please Try Again.\n");
        printf("--------------------------TRY AGAIN--------------------------");
        return 0;
    }
    for(int j=0; j<length2; j++){
        int runThrough2 = 0;
        if(command2[j]==stats3[j]){
            stats4++;
            runThrough2++;
        }
        if(command2[j]==pickup[j]){
            pickup3++;
            runThrough2++;
        }
        if(command2[j]==inv3[j]){
            inv4++;
            runThrough2++;
        }
        if(command2[j]==fight[j]){
            fight3++;
            runThrough2++;
        }
        if(command2[j]==useItem[j]){
            useItem3++;
            runThrough2++;
        }
        if(command2[j]==quit3[j]){
            quit4++;
            runThrough2++;
        }
        if(runThrough2==0){
            pickup3--;
            fight3--;
            useItem3--;
            quit4--;
            inv4--;
            stats4--;
        }
    }
    if(stats4==5){
        printf("You Selected To Print Statistics! \n");
        printf("\n--------------------------STATISTICS INFORMATION--------------------------");
        printStatistics(player, rooms2);
        printf("\n--------------------------ROOM INFORMATION--------------------------");
        return 0;
    }
    if(pickup3 == 6){
        printf("You Selected To Pickup An Item! \n");
        printf("--------------------------INITIALIZING PICKUP SEQUENCE--------------------------");
        int increment3 = 0;
        while(increment3 == 0){
            printObjects(player, rooms2);
            int i = 0;
            int checkOutput = 0;
            i = commandAssessment3(0, player, rooms2);
            system("clear");
            if(i==-1){
                printf("Moving Back To Room Menu!\n");
                increment3++;
            }
            if(i<-1){
                printf("ERROR! Please Enter A Number 0-3\n");
                printf("--------------------------TRY AGAIN--------------------------\n");
            }
            if(i>=0){
                checkOutput = pickUpItem(getRoomObject(player, i, rooms2), getPlayerInventory(player), player, i, rooms2);
                if(checkOutput==0){
                    setObjectEmpty(player, i, rooms2);
                    increment3++;
                }
            }
        }
        printf("--------------------------ROOM INFORMATION--------------------------");
        return 0;
    }
    if(fight3 == 5){
        system("clear");
        printf("You Selected To Fight A Monster! \n");
        printf("--------------------------INITIALIZING FIGHT SEQUENCE--------------------------");
        int increment2 = 0;
        while(increment2 == 0){
            printMonsters(player, rooms2);
            int j=0;
            int checkOutput2 = 0;
            j = commandAssessment3(1, player, rooms2);
            system("clear");
            if(j==-1){
                    printf("Moving Back To Room Menu!\n");
                    increment2++;
                }
            if(j<-1){
                printf("ERROR! Please Enter A Number 0-3\n");
                printf("--------------------------TRY AGAIN--------------------------\n");
            }
            if(j>=0){
                checkOutput2 = fightMonster(getMonster(player, j, rooms2), player, rooms2);
                if(checkOutput2==-2){
                    return -2;
                }
                if(checkOutput2==0){
                    increment2++;
                }
            }
        }
        printf("--------------------------ROOM INFORMATION--------------------------");
        return 0;
    }
    if(useItem3 == 7){
        printf("You Selected To Use An Item! \n");
        printf("--------------------------INITIALIZING ITEM USE SEQUENCE--------------------------");
        int increment = 0;
        while(increment == 0){
            printInventory(player);
            int i = 0;
            int checkOutput3 = 0;
            i = commandAssessment4(2, player);
            system("clear");
            if(i==-1){
                printf("Moving Back To Room Menu!\n");
                increment++;
            }
            if(i<-1){
                printf("ERROR! Please Enter A Number 0-2\n");
                printf("--------------------------TRY AGAIN--------------------------\n");
            }
            if(i>=0){
                checkOutput3 = useItem2(getInventoryObject(player, i), getPlayerInventory(player), player, i);
                if(checkOutput3==-2){
                    printf("\n SYSTEM ERROR: BAD OUTPUT \n");
                    printf("--------------------------GAME TERMINATING--------------------------\n");
                    return -2;
                }
                if(checkOutput3==0){
                    increment++;
                }
            }
        }
        printf("--------------------------ROOM INFORMATION--------------------------");
        return 0;
    }
    if(quit4 == 4){
        printf("You Selected To Go Back To Main Path! \n");
        printf("\n--------------------------LEAVING ROOM--------------------------\n");
        printf("*\n");
        printf("*\n");
        printf("*");
        printJumanji();
        printPlayerLocation(player, rooms2);
        printf("\n--------------------------PLAYER PATH COMMAND--------------------------");
        return -1;
    }
    if(inv4 == 3){
        printf("You Selected To Print Inventory! \n");
        printf("\n--------------------------INVENTORY INFORMATION--------------------------");
        printInventory(player);
        printf("\n--------------------------ROOM INFORMATION--------------------------");
        return 0;
    }
    else{
        printf("INVALID COMMAND. Please Try Again!\n");
        printf("--------------------------TRY AGAIN--------------------------");
        return 0;
    }
    return 0;
}