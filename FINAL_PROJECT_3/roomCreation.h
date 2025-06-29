#ifndef ROOMCREATION_H
#define ROOMCREATION_H

typedef struct _location Location;

//creates an array of pointers to rooms, each with a randomized selection of monsters and objects. this function requires no input, and returns a pointer to the array of location pointers.
Location** createRooms();

//this function takes a pointer to an array of location pointers, iterates through each location, freeing all of its associated data from the heap. this function returns nothing. Also, it should be noted that this function calls the respective function to free the array of monster pointers and the respective function to free the array of object pointers.
void deleteRooms(Location** rooms);

#endif