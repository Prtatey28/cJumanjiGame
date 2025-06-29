#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "monster.h"

struct _monster {
    char* name;
    char* description;
    int health;
    int score;
};

Monster* createMonster(char* name_in, char* description_in, int health_in, int score_in){
    Monster* m = malloc(sizeof(Monster));
    m->name = malloc(strlen(name_in)+1);
    m->description = malloc(strlen(description_in)+1);
    m->health = health_in;
    m->score = score_in;
    strcpy(m->name, name_in);
    strcpy(m->description, description_in);
    return m;
}

char* getMonsterName(Monster* m){
    return (m->name);
}

int getMonsterHealth(Monster* m){
    return (m->health);
}

void lowerMonsterHealth(Monster* m){
    m->health = m->health -10;
    return;
}

void lowerMonsterHealthSword(Monster* m){
    m->health = m->health -20;
    return;
}

int getMonsterScore(Monster* m){
    return m->score;
}

void setMonsterName(char* string, Monster* m){
    strcpy(m->name, string);
    return;
}

char* getMonsterDescription(Monster* m){
    return (m->description); 
}

void deleteMonster(Monster* p){
    free(p->name);
    free(p->description);
    free(p);
    return;
}