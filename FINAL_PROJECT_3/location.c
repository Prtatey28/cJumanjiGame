#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "object.h"
#include "location.h"
#include "objectCreation.h"
#include "player.h"
#include "roomCreation.h"
#include "monster.h"
#include "monsterCreation.h"
#include "random.h"

struct _location {
    char * name;
    char * description;
    Object** items2;
    Monster** enemies2;
};

Location* newLocation(char* name_in, char* description_in){
    Location* a = malloc(sizeof(Location));
    a->name = malloc(strlen(name_in)+1);
    a->description = malloc(strlen(description_in)+1);
    strcpy(a->name, name_in);
    strcpy(a->description, description_in);
    a->items2 = createObjects();
    a->enemies2 = createMonsters(random(3));
    return a;
}

char* getLocName(Location* p){
    return (p->name);
}

char* getLocDescription(Location* p){
    return (p->description);
}

void deleteLocation(Location* p){
    deleteObjects(p->items2); //frees all objects/items from heap
    deleteMonsters(p->enemies2); //frees all monsters from heap
    free(p->name);
    free(p->description);
    free(p);
    return;
}

void printObjects(Player* p, Location** rooms2){
    printf("\nROOM OBJECTS AVAILABLE: \n");
    for(int i=0; i<3; i++){
        printf("Object %d: %s\n", i+1, getObjName(rooms2[playerPosition(p)]->items2[i]));
    }
    return;
}

void printMonsters(Player* p, Location** rooms2){
    printf("\nROOM MONSTERS SPAWNED: \n");
    for(int i=0; i<3; i++){
        printf("Monster %d: %s\n", i+1, getMonsterName(rooms2[playerPosition(p)]->enemies2[i]));
    }
    return;
}

char* getRoomObject(Player* p, int i, Location** rooms2){
    //printf("%d\n",i);
    return getObjName(rooms2[playerPosition(p)]->items2[i]);
}

Object* getObject(Player* p, int i, Location** rooms2){
    //printf("%d\n",i);
    return rooms2[playerPosition(p)]->items2[i];
}

Monster* getMonster(Player* p, int i, Location** rooms2){
    return rooms2[playerPosition(p)]->enemies2[i];
}

void setObjectEmpty(Player* p, int i, Location** rooms2){
    setObjName("Empty",(rooms2[playerPosition(p)]->items2[i]));
    return;
}