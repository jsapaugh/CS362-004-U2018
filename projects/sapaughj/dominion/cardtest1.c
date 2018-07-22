/*
* Author : Jacob Sapaugh
*          Oregon State University
*          CS 362
*          07-18-2018
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void assertEquals(int expected, int actual, char message[]);
void testSmithy();

int main(int argc, char* argv[]) 
{
    char functionUnderTest[] = "int cardEffect(...) smithyEffect(...)";

    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    
    testSmithy();
    
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
	
    return 0;
}

void testSmithy()
{
    struct gameState state;
    int players = 2;
    int seed = 100;
    int handPos = 0;
    int bonus = 0;
    
	int k[10] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager};
	
    initializeGame(players, k, seed, &state);

    int handCountBefore = numHandCards(&state);
    int deckCountBefore = state.deckCount[0];
    int totalCardsBefore = state.deckCount[0] + state.discardCount[0] + state.handCount[0];

    int played =  cardEffect(smithy, 0, 0, 0, &state, handPos, &bonus);
    assertEquals(0, state.numActions, "Testing total number of actions after playing smithy");
    assertEquals(0, played, "Testing return code on cardEffect(...)");
    int totalCardsAfter = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
    int handDifference = abs(numHandCards(&state) - handCountBefore);
    int deckDifference = abs(state.deckCount[0] - deckCountBefore);
    
    //determine if hand has the right number of cards
    assertEquals(2, handDifference, "Testing difference in cards in hand");
    //determine if deck has right number of cards
    assertEquals(4, deckDifference, "Testing difference in cards in deck");
    //make sure no cards were trashed
    assertEquals(totalCardsBefore, totalCardsAfter, "Testing difference in total cards");
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