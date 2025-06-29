#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "object.h"
#include "objectCreation.h"
#include "random.h"

Object** createObjects(){
    Object** items = malloc(3*sizeof(Object*));
    int lootSelection = 0;
    lootSelection = random(4);
    //printf("%d\n", lootSelection);
    if(lootSelection == 0){
        items[0] = newObject("Empty","Empty");
        items[1] = newObject("Health Boost", "This item adds 10 health points to your character!");
        items[2] = newObject("Sword","Gives you better damage output against monsters");
    }
    else if(lootSelection == 1){
        items[0] = newObject("Empty","Empty");
        items[1] = newObject("Health Boost", "This item adds 10 health points to your character!");
        items[2] = newObject("Empty","Empty");
    }
    else if(lootSelection == 2){
        items[0] = newObject("Empty","Empty");
        items[1] = newObject("Empty", "Empty");
        items[2] = newObject("Sword","Gives you better damage output against monsters! (Note: You must equip this item, through the USEITEM option, before it will deal extra damage to monsters)");
    }
    else if(lootSelection == 3){
        items[0] = newObject("Score Bonus","This item adds 5 points to your total score!");
        items[1] = newObject("Empty", "Empty");
        items[2] = newObject("Empty","Empty");
    }
    else if(lootSelection == 4){
        items[0] = newObject("Empty","Empty");
        items[1] = newObject("Health Boost", "This item adds 10 health points to your character!");
        items[2] = newObject("Empty","Empty");
    }
    else{
        printf("ERROR\n");
        return NULL;
    }
    return items;
}

void deleteObjects(Object** items){
    for(int i=0; i<3; i++){
        deleteObject(items[i]);
    }
    free(items);
    return;
}