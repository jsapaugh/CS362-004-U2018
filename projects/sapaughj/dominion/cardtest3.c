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
void assertTrue(int value);
void testSmithy();

int main(int argc, char* argv[]) 
{
    char functionUnderTest[] = "int cardEffect(...) villageEffect(...)";

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
    int players = 3;
    int seed = 100;
    int handPos = 0;
    int bonus = 0;
    
	int k[10] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager};
	
    initializeGame(players, k, seed, &state);
    
    
    state.whoseTurn = 1;
    int handCountBeforePlayerTwo = numHandCards(&state);

    state.whoseTurn = 2;
    int handCountBeforePlayerThree = numHandCards(&state);
    
    state.whoseTurn = 0;
    int handCountBeforePlayerOne = numHandCards(&state);
    int totalCardsBeforePlayerOne = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
    int played =  cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
    assertEquals(2, state.numActions, "Testing total number of actions after playing smithy");
    assertEquals(0, played, "Testing return code on cardEffect(...)");
    
    int totalCardsAfterPlayerOne = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
    
    //player 0 (player one's turn)
    int handDifferencePlayerOne = abs(numHandCards(&state) - handCountBeforePlayerOne);
    
    state.whoseTurn = 1;
    //check next players hand count, make sure it is 0
    int handDifferencePlayerTwo = abs(numHandCards(&state)-handCountBeforePlayerTwo);
    
    state.whoseTurn = 2;
    //check next players hand count, make sure it is 0
    int handDifferencePlayerThree = abs(numHandCards(&state)-handCountBeforePlayerThree);
    
    //check hands of the active players
    assertEquals(2, handDifferencePlayerOne, "Testing difference of cards in hand for player one");
    assertEquals(0, handDifferencePlayerTwo, "Testing difference of cards in hand for player two");
    assertEquals(0, handDifferencePlayerThree, "Testing difference of cards in hand for player three");
    
    //make sure no cards were trashed
    assertEquals(totalCardsBeforePlayerOne, totalCardsAfterPlayerOne, "Testing total cards for player one");
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