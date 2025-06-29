#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "monster.h"
#include "monsterCreation.h"
#include "random.h"

Monster** createMonsters(int random){
    Monster** enemies = malloc(3*sizeof(Monster*));
    int monsterSelection = 0;
    monsterSelection = random;
    if(monsterSelection == 0){
        enemies[0] = createMonster("Empty","Empty",0,0);
        enemies[1] = createMonster("Goliath","This is a ravenous beast, worth 50 points!", 40, 50);
        enemies[2] = createMonster("Monkey","This is a somewhat smaller beast, worth 25 points!", 20, 25);
    }
    else if(monsterSelection == 1){
        enemies[0] = createMonster("Snake","This is a slithering silent monster, worth 30 points", 25, 30);
        enemies[1] = createMonster("Empty","Empty",0,0);
        enemies[2] = createMonster("Empty","Empty",0,0);
    }
    else if(monsterSelection == 2){
        enemies[0] = createMonster("Snake","This is a slithering silent monster, worth 30 points", 25, 30);
        enemies[1] = createMonster("Empty","Empty",0,0);
        enemies[2] = createMonster("Monkey","This is a somewhat smaller beast, worth 25 points!", 20, 25);
    }
    else if(monsterSelection == 3){
        enemies[0] = createMonster("Empty","Empty",0,0);
        enemies[1] = createMonster("Goliath","This is a ravenous beast, worth 50 points!", 40, 50);
        enemies[2] = createMonster("Empty","Empty",0,0);
    }
    else{
        printf("ERROR\n");
        return NULL;
    }
    return enemies;
}

void deleteMonsters(Monster** enemies){
    for(int i=0; i<3; i++){
        deleteMonster(enemies[i]);
    }
    free(enemies);
    return;
}