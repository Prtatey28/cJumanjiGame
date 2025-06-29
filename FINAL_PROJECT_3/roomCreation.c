#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h> //includes sleep function to pause code for a short time to allow for true randomization of each room

#include "location.h" //the inclusion of this initial dependency is necessary for the createRooms function to determine what to do with the "newLocation()" functions
#include "roomCreation.h"

Location** createRooms(){
    Location** rooms = malloc(3*sizeof(Location*));
    //printf("0\n");
    rooms[0] = newLocation("Savanah", "This is baren desert. You have minimal resources, and limited abilities. Find nearby items to increase your score!");
    sleep(1); //delays the creation of rooms by one second, to ensure that each time the computer's time is different. This way each room ensures a different/unique loot pool selection of monsters, and objects.
    rooms[1] = newLocation("Jungle", "This is a lush area of trees. You have much more stamina. Find nearby items to increase your score!");
    sleep(1);//delays the creation of rooms by one second, to ensure that each time the computer's time is different. This way each room ensures a different/unique loot pool selection of monsters, and objects.
    rooms[2] = newLocation("Temple", "This is a stony temple. Lots of stairs! Find nearby items to increase your score!");
    return rooms;
}

void deleteRooms(Location** rooms){
    for(int i=0; i<3; i++){
        deleteLocation(rooms[i]);
    }
    free(rooms);
    return;
}