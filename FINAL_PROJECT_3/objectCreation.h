#ifndef OBJECTCREATION_H
#define OBJECTCREATION_H

typedef struct _object Object;

//creates an array of object pointers, where each element is a pointer to a object. Each array is three elements. The selection of what each of the three elements is equivalent to is determined by a random number output of the random(4) function, where a number between 0 and 4 is returned. The number then, through the use of conditionals, corresponds to a specific loot pool, which will then set the array of object pointers equivalent to the created objects from the loot pool. pointer to the object* array is returned.
Object** createObjects();

//requires a pointer to an object* array, or an array with object pointers. This function will then free all heap data associated with the inputted object* array. this function returns nothing.
void deleteObjects(Object** items);

#endif