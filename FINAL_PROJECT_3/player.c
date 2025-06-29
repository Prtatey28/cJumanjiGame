#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "object.h"
#include "location.h"
#include "objectCreation.h"
#include "player.h"
#include "playerManagement.h"
#include "roomCreation.h"
#include "inventory.h"

struct _player {
    char* name;
    int score;
    int position;
    int health;
    Object** inventory;
    bool swordActive;
};

Player* createPlayer(char* name_in){
    Player* a = malloc(sizeof(Player));
    a->name = malloc(strlen(name_in)+1);
    strcpy(a->name, name_in);
    a->score = 0;
    a->position = 0;
    a->health = 100;
    a->inventory = createInventory();
    a->swordActive = false;
    return a;
}

void deletePlayer(Player* player){
    deleteInventory(player->inventory);
    free(player->name);
    free(player);
    return;
}

int moveUp(Player * currentPlayer){
    if(currentPlayer!=NULL){
        if((currentPlayer->position)<2){
            currentPlayer->position = currentPlayer->position+1;
            return 0;
        }
        else{
            printf("\nERROR. You are already in the final room!\n");
            return -1;
        }
    }
    else{
        printf("\nSYSTEM ERROR. NULL player inserted.\n");
        return -2;
    }
}

int moveBack(Player * currentPlayer){
    if(currentPlayer!=NULL){
        if((currentPlayer->position)>=1){
            currentPlayer->position = currentPlayer->position-1;
            return 0;
        }
        else{
            printf("\nERROR. You are already in the first room!\n");
            return -1;
        }
    }
    else{
        printf("\nSYSTEM ERROR. NULL player inserted.\n");
        return -2;
    }
}

int playerPosition(Player * currentPlayer){
    if(currentPlayer!=NULL){
        return (currentPlayer->position);
    }
    else{
        printf("SYSTEM ERROR. NULL player inserted.\n");
        return -1;
    }
}

int playerHealth(Player * currentPlayer){
    if(currentPlayer!=NULL){
        return (currentPlayer->health);
    }
    else{
        printf("SYSTEM ERROR. NULL player inserted.\n");
        return -1;
    }
}

int playerScore(Player * currentPlayer){
    if(currentPlayer!=NULL){
        return (currentPlayer->score);
    }
    else{
        printf("SYSTEM ERROR. NULL player inserted.\n");
        return -1;
    }
}

char* playerName(Player * currentPlayer){
    if(currentPlayer!=NULL){
        return currentPlayer->name;
    }
    else{
        printf("SYSTEM ERROR. NULL player inserted.\n");
        return NULL;
    }
}

int scoreAdd(Player * currentPlayer, int amount){
    currentPlayer->score = currentPlayer->score + amount;
    return 0;
}

void printInventory(Player* p){
    printf("\nCURRENT INVENTORY: \n");
    for(int i=0; i<2; i++){
        printf("Item Slot %d: %s\n", (i+1), getObjName(p->inventory[i]));
    }
    return;
}

Object** getPlayerInventory(Player* p){
    return p->inventory;
}

void convertHealth(Player* p){
    p->score = p->score + p->health;
    return;
}

int healthAssessment(Player * p){
    if(p->health<=0){
        return -1;
    }
    else{
        return 0;
    }
}

bool playerSwordStatus(Player * currentPlayer){
    if(currentPlayer!=NULL){
        return currentPlayer->swordActive;
    }
    else{
        printf("SYSTEM ERROR. NULL player inserted.\n");
        return NULL;
    }
}

void removePlayerHealth(Player * currentPlayer){
    currentPlayer->health = currentPlayer->health - 10;
    return;
}

void addPlayerHealth(Player * currentPlayer){
    currentPlayer->health = currentPlayer->health + 10;
    return;
}

void playerScoreIncrease(Player * currentPlayer, int score){
    currentPlayer->score = currentPlayer->score + score;
    return;
}

void playerSetSword(Player * currentPlayer){
    currentPlayer->swordActive = true;
    return;
}

Object* getInventoryObject(Player* p, int i){
    return p->inventory[i];
}