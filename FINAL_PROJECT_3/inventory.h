#ifndef INVENTORY_H
#define INVENTORY_H

typedef struct _object Object;

//instantiates an array of 2 inventory objects. Each object in the array is given the "Empty" alias to begin with and is placed on the heap. function returns a pointer to the array. The function requires no inputs.
Object** createInventory();

//requires a pointer to an inventory array, or an array with object pointers. This function will then free all heap data associated with the inputted inventory. this function returns nothing.
void deleteInventory(Object** items);

#endif