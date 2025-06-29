#ifndef OBJECT_H
#define OBJECT_H

typedef struct _object Object;

//creates a new object on the heap. Takes name input and description input. it returns pointer to new object stored on the heap.
Object* newObject(char* name_in, char* description_in);

//returns the name of an inputed pointer to a object.
char* getObjName(Object* p);

//returns the description of an inputed pointer to a object.
char* getObjDescription(Object* p);

//takes pointer to object, iterates through all of its components, freeing them, to ensure that nothing of the inputted object is left on the heap. this function returns nothing.
void deleteObject(Object* p);

//sets the name of an inputed pointer to a object to the value inputted of the inputted string. returns nothing.
void setObjName(char* string, Object* p);

#endif