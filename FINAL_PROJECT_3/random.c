#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h> //used for random number generator

int random(int a){
    srand(time(NULL)); //randomizes seed for random number generator, based on the computer's time
    int randomInt = 0;
    randomInt = rand() % (a+1); //generates a random number between 0 and a
    //printf("Random Number Output %d\n", randomInt);
    return randomInt;
}