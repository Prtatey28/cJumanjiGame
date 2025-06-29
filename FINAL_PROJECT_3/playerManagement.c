#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "player.h"
#include "object.h"
#include "location.h"
#include "roomCreation.h"
#include "playerManagement.h"
#include "monster.h"
#include "random.h"
#include "printing.h"
#include "commandInput.h"

void printPlayerLocation(Player * player, Location** rooms){
    printf("\nCurrent Location is: %s \n", getLocName(rooms[playerPosition(player)]));
    return;
}

void printPlayerLocationDescription(Player * player, Location** rooms){
    printf("%s\n", getLocDescription(rooms[playerPosition(player)]));
    return;
}

char* playerLocation(Player * player, Location** rooms){
    return getLocName(rooms[playerPosition(player)]);
}

void printStatistics(Player * a, Location** daRooms){
    printf("\nCURRENT STATISTICS:\n");
    printf("Name: %s\n", playerName(a));
    printf("Location: %s\n", playerLocation(a,daRooms));
    printf("Health: %d\n", playerHealth(a));
    printf("Score: %d\n", playerScore(a));
    printf("Sword Status: %d (<--- 1 Indicates Sword Active, 0 is deactive)\n", playerSwordStatus(a));
    return;
}

int pickUpItem(char* inputtedString, Object** inventory, Player* player, int i, Location** rooms2){
    //note that inputtedString is the inputted item that we are trying to pickup
    if(strcmp(inputtedString,"Empty")){ //if equal, exits and throws error
        int fullCheck = 0;
        for(int i=0; i<2; i++){
            if(strcmp((getObjName(inventory[i])),"Empty")){
                fullCheck++;
            }
        }
        if(fullCheck>=2){
            printf("ERROR! Inventory Full!\n");
            return -2; //inventory slot full
        }
        if(fullCheck<2){
            int itemPlaced = 0;
            while(itemPlaced == 0){
                for(int j=0; j<2; j++){
                    if(!strcmp((getObjName(inventory[j])),"Empty")){
                        printCheckMark();
                        printf("%s placed in inventory!\n", inputtedString);
                        printf("%s\n",getObjDescription(getObject(player, i, rooms2)));
                        setObjName(inputtedString, inventory[j]);
                        itemPlaced++;
                    }
                    if(!(itemPlaced == 0)){
                        return 0;
                    }
                }
            }
        }
        return 0;
    }
    if(!strcmp(inputtedString,"Empty")){
        printf("ERROR! There is nothing in this floor tile to pickup! (Look on a different one)\n");
        printf("--------------------------TRY AGAIN--------------------------\n");
        return -1; //empty object that you are trying to add to inventory
    }
    return 0;
}

int fightMonster(Monster* monster, Player* player, Location** rooms2){
    int monsterDefeated = 0;
    if(strcmp(getMonsterName(monster),"Empty")){
        char* sword;
        if(playerSwordStatus(player)==true){
            sword = "SWORD";
        }
        else if(playerSwordStatus(player)==false){
            sword = "PUNCH";
        }
        printf("You have decided to test you fate with the %s!\n", getMonsterName(monster));
        printf("%s\n",getMonsterDescription(monster));
        printf("You will fight using swift %s attacks.\nDepending on your luck, you will lose a certain amount of health,\nbefore the %s dies!\n", sword, getMonsterName(monster));
        printf("--------------------------FIGHT SEQUENCE--------------------------\n");
        char command[8];
        int err = 0;
        while(monsterDefeated==0){
            char* monster4 = getMonsterName(monster);
            if(!strcmp(monster4, "Snake")){
                printSnake();
            }
            else if(!strcmp(monster4, "Goliath")){
                printGoliath();
            }
            else if(!strcmp(monster4, "Monkey")){
                printMonkey();
            }
            printf("%s Health: %d\n",getMonsterName(monster),getMonsterHealth(monster));
            printStatistics(player, rooms2);
            printf("\n--------------------------PLAYER COMMAND--------------------------");
            printFightInstructions();
            err = scanf("%8s", command); assert(err);
            system("clear");
            if(!strcmp(command, "ATTACK")){
                printf("You selected to attack!\n");
                int roll = 0;
                roll = random(1);
                if(roll==1){
                    if(playerSwordStatus(player)==true){
                        lowerMonsterHealthSword(monster);
                        printf("THE ATTACK WAS SUPER EFFECTIVE!(-20 from %s's health)\n", getMonsterName(monster));
                    }
                    else{
                        lowerMonsterHealth(monster);
                        printf("THE ATTACK WAS SUCCESSFUL!(-10 from %s's health)\n", getMonsterName(monster));
                    }
                }
                else if(roll!=3){
                    removePlayerHealth(player);
                    printf("SHOOT! THE ATTACK WAS UNSUCCESSFUL!(-10 from %s's health)\n", playerName(player));
                }
                if(healthAssessment(player)!=0){
                    printf("\nOh no! You were bested by the %s!!\n", getMonsterName(monster));
                    printf("\n--------------------------PLAYER DIED--------------------------");
                    return -2;
                }
                if(getMonsterHealth(monster)<=0){
                    printCheckMark();
                    printf("\nGreat Work! Monster Extinquished. (+%d to %s's score)\n", getMonsterScore(monster), playerName(player));
                    playerScoreIncrease(player, getMonsterScore(monster));
                    monsterDefeated++;
                    setMonsterName("Empty", monster);
                }
                printf("--------------------------END OF ATTACK PHASE--------------------------\n\n");
            }
            else if(!strcmp(command, "USEITEM")){
                printf("You selected to use an item!\n");
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
                printf("--------------------------RETURN TO FIGHT--------------------------\n");
            }
            else if(!strcmp(command, "EXIT")){
                printf("You selected to quit the fight!\n");
                return -1;
            }
            else{
                printf("ERROR! Please Enter A Listed Command\n");
                printf("--------------------------TRY AGAIN--------------------------\n");
            }
        }
    }
    if((!strcmp(getMonsterName(monster),"Empty"))&&(monsterDefeated==0)){
        printf("ERROR! There is nothing in this floor tile to fight! (Find a different one)\n");
        printf("--------------------------TRY AGAIN--------------------------\n");
        return -1; //empty object that you are trying to add to inventory
    }
    return 0;
}

int useItem2(Object* item, Object** inventory, Player* player, int i){
    if(!strcmp(getObjName(item), "Empty")){
        printf("ERROR! There is no item in this slot to use! (Select a different one)\n");
        printf("--------------------------TRY AGAIN--------------------------\n");
        return -1;
    }
    else if(strcmp(getObjName(item), "Empty")){
        if(!strcmp(getObjName(item), "Health Boost")){
            printMedPack();
            addPlayerHealth(player);
            printf("+10 added to %s's health!\n", playerName(player));
            printf("--------------------------END OF ITEM PHASE--------------------------\n");
            setObjName("Empty", inventory[i]);
            return 0;
        }
        else if(!strcmp(getObjName(item), "Score Bonus")){
            printScoreMeter();
            playerScoreIncrease(player, 10);
            printf("+10 added to %s's score!\n", playerName(player));
            printf("--------------------------END OF ITEM PHASE--------------------------\n");
            setObjName("Empty", inventory[i]);
            return 0;
        }
        else if(!strcmp(getObjName(item), "Sword")){
            printSword();
            playerSetSword(player);
            setObjName("Empty", inventory[i]);
            printf("Sword now equipped to %s!\n", playerName(player));
            printf("--------------------------END OF ITEM PHASE--------------------------\n");
            return 0;
        }
        else{
            return -2;
        }
    }
    return -2;
}