#ifndef RANDOM_H
#define RANDOM_H

//returns a random number between 0 and a. The function ensures pure randomization each time it is called, by randomizing the seed(the thing that c uses to generate random numbers) according to the computers time.
int random(int a);

#endif