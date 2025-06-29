#ifndef MONSTER_H
#define MONSTER_H

typedef struct _monster Monster;

//creates a new monster on the heap. Takes name input, description input, health input, and score value input. it returns pointer to new monster stored on the heap.
Monster* createMonster(char* name_in, char* description_in, int health_in, int score_in);

//returns the health of an inputed pointer to a monster.
int getMonsterHealth(Monster* m);

//lowers the health of a pointed to monster by 10 points. returns nothing.
void lowerMonsterHealth(Monster* m);

//lowers the health of a pointed to monster by 20 points. returns nothing.
void lowerMonsterHealthSword(Monster* m);

//returns the score of a pointed to monster.
int getMonsterScore(Monster* m);

//returns the name of a pointed to monster.
char* getMonsterName(Monster* m);

//sets the name of a pointed to monster to the equivalent inputted string. returns nothing.
void setMonsterName(char* string, Monster* m);

//returns the description of a pointed to monster.
char* getMonsterDescription(Monster* m);

//takes pointer to monster, iterates through all of its components, freeing them, to ensure that nothing of the inputted monster is left on the heap. this function returns nothing.
void deleteMonster(Monster* p);

#endif