#ifndef MONSTERCREATION_H
#define MONSTERCREATION_H

typedef struct _monster Monster;

//creates an array of monster pointers, where each element is a pointer to a monster. Each array is three elements. The selection of what each of the three elements is equivalent to is determined by a random number output of the random(3) function (from the location() function), where a number between 0 and 3 is returned. The number then, through the use of conditionals, corresponds to a specific loot pool, which will then set the array of monsters equivalent to the created monsters from the loot pool. pointer to the monster* array is returned.
Monster** createMonsters();

//requires a pointer to a monster* array, or an array with monster pointers. This function will then free all heap data associated with the inputted monster* array. this function returns nothing.
void deleteMonsters(Monster** enemies);

#endif