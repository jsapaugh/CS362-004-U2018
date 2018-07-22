/*
* Author : Jacob Sapaugh
*          Oregon State University
*          CS 362
*          07-18-2018
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

/*
* Testing int whoseTurn(struct gameState *state)
*/

void assertEquals(int expected, int actual, char message []);
void testWhoseTurn();

int main(int argc, char *argv[])
{
    char functionUnderTest[] = "int whoseTurn(struct gameState *state)";
    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    
    testWhoseTurn();
    
    fflush(stdout);        
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
}

void testWhoseTurn()
{
    struct gameState state;
    int players = 2;
    int seed = 50;
    int k[10] = {adventurer, smithy, gardens, embargo, village, steward, mine, cutpurse, outpost, tribute};
    
    initializeGame(players, k, seed, &state);
    
    state.whoseTurn = 0;
    
    assertEquals(0, whoseTurn(&state), "Testing state for whose turn it is");
    
    state.whoseTurn = 1;
    
    assertEquals(1, whoseTurn(&state), "Testing state for whose turn it is");
}

void assertEquals(int expected, int actual, char message[])
{
    printf("%s\n", message);
    fflush(stdout);
    
    if(expected == actual)
    {
        printf("****************TEST SUCCESSFULLY COMPLETED****************\n");
        fflush(stdout);
    }
    else
    {
        printf("************************TEST FAILED************************\n");
        fflush(stdout);        
    }
}