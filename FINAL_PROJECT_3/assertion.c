#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#include "player.h"


//score Unit Test, assessing player score every time test player's score is increased
void assertScore(){
    printf("SCORE ASSERTION (UNIT TEST #1): ");
    Player * testPlayer = createPlayer("Test");
    assert(playerScore(testPlayer) == 0);
    scoreAdd(testPlayer, 10);
    assert(playerScore(testPlayer) == 10);
    playerScoreIncrease(testPlayer, 10);
    assert(playerScore(testPlayer) == 20);
    deletePlayer(testPlayer);
    printf("PASSED\n");
}

//movement Unit Test, assessing each player position every time test player is moved
void assertMovement(){
    printf("MOVEMENT ASSERTION (UNIT TEST #2): ");
    Player * testPlayer = createPlayer("Test");
    assert(playerPosition(testPlayer) == 0);
    moveUp(testPlayer);
    assert(playerPosition(testPlayer) == 1);
    moveUp(testPlayer);
    assert(playerPosition(testPlayer) == 2);
    moveBack(testPlayer);
    assert(playerPosition(testPlayer) == 1);
    moveBack(testPlayer);
    assert(playerPosition(testPlayer) == 0);
    deletePlayer(testPlayer);
    printf("PASSED\n");
}