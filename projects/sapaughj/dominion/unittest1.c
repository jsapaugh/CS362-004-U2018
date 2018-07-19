/*
* Author : Jacob Sapaugh
*          Oregon State University
*          CS 362
*          07-18-2018
*/

/*
function under test
int whoseTurn(struct gameState *state) {
  return state->whoseTurn;
}
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void assertEquals(int expected, int actual);
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
    
    assertEquals(0, whoseTurn(&state));
    
    state.whoseTurn = 1;
    
    assertEquals(1, whoseTurn(&state));
}

void assertEquals(int expected, int actual)
{
    if(expected == actual)
    {
        printf("\t****************TEST SUCCESSFULLY COMPLETED****************\n");
        fflush(stdout);
    }
    else
    {
        printf("\t****************TEST FAILED****************\n");
        fflush(stdout);        
    }
}