#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "object.h"
#include "objectCreation.h"

Object** createInventory(){
    Object** emptyInv = malloc(3*sizeof(Object*));
    emptyInv[0] = newObject("Empty", "Nothing Here.");
    emptyInv[1] = newObject("Empty", "Nothing Here.");
    return emptyInv;
}

void deleteInventory(Object** items){
    for(int i=0; i<2; i++){
        deleteObject(items[i]);
    }
    free(items);
    return;
}