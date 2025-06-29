#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "object.h"

struct _object {
    char* name;
    char* description;
};

Object* newObject(char* name_in, char* description_in){
    Object* a = malloc(sizeof(Object));
    a->name = malloc(strlen(name_in)+1);
    a->description = malloc(strlen(description_in)+1);
    strcpy(a->name, name_in);
    strcpy(a->description, description_in);
    return a;
}

char* getObjName(Object* p){
    return (p->name);
}

void setObjName(char* string, Object* p){
    strcpy(p->name, string);
    return;
}

char* getObjDescription(Object* p){
    return (p->description);
}

void deleteObject(Object* p){
    free(p->name);
    free(p->description);
    free(p);
    return;
}