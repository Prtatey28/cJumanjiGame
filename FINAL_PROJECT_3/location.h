#ifndef LOCATION_H
#define LOCATION_H

typedef struct _location Location;
typedef struct _player Player;
typedef struct _object Object;
typedef struct _monster Monster;

//creates a new location. Takes name input as well as description input, returns pointer to new location stored on the heap. Additionally, this function will automatically call create objects function and create monsters function to ensure that every location that gets built in the game has monsters and objects.
Location* newLocation(char* name_in, char* description_in);

//takes pointer to location, returns name of location variable.
char* getLocName(Location* p);
    
//takes pointer to location, returns description of inputted location.
char* getLocDescription(Location* p);

//takes pointer to location, iterates through all of its components, freeing them, to ensure that nothing of the inputted location is left on the heap. this function returns nothing.
void deleteLocation(Location* p);

//prints the objects associated within a specific room. This function takes input of the player object as well as an array of all of the possible locations created in the map to ensure that it only prints the objects associated with the room that the player is currently located in.
void printObjects(Player* p, Location** rooms2);

//prints the monsters associated within a specific room. This function takes input of the player type as well as an array of all of the possible locations created in the map to ensure that it only prints the monsters associated with the room that the player is currently located in.
void printMonsters(Player* p, Location** rooms2);

//returns the name of a specified room, within the current room that the player is located. input required: pointer to player, index of the object within the room array of specified objects.
char* getRoomObject(Player* p, int i, Location** rooms2);

//returns monster of a specified index value from the array of monsters within a specified room. Input required: pointer to player, index of monster requested, rooms array. Using the player pointer and the rooms array, the exact location of the player is determined. Then using the specified index value, the request monster is returned.
Monster* getMonster(Player* p, int i, Location** rooms2);

//returns room object of a specified index value from the array of room objects within a specified room. Input required: pointer to player, index of room object requested, rooms array. Using the player pointer and the rooms array, the exact location of the player is determined. Then using the specified index value, the request room object is returned.
Object* getObject(Player* p, int i, Location** rooms2);

//changes the value of a specified room object name to contain "Empty" as opposed to the name it was initialized with. Input required: pointer to player, index of room object requested, rooms array. Using the player pointer and the rooms array, the exact location of the player is determined. Then using the specified index value, the request room object's name is changed.
void setObjectEmpty(Player* p, int i, Location** rooms2);

#endif