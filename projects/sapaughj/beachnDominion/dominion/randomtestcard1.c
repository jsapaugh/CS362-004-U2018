/*
* Author : Jacob Sapaugh
*          Oregon State University
*          CS 362
*          08-04-2018
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_LOOPS 1500

int assertEquals(int expected, int actual);
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

	time_t t;
	srand((unsigned) time(&t));
	int i;
	int k[10] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager};
	int kWithGoldSilverCopper[13] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager, gold, silver, copper};
    int totalCardCountCorrect = 0;
	int deckCountCorrect = 0;
	int handCountCorrect = 0;
	int playerOneActionsTimes = 0;
	int correctNumberTimesPlayed = 0;
	
	for(i = 0; i < TEST_LOOPS; i++)
	{    
    	struct gameState state;
        int players = 2;
        int seed = rand();
        int handPos = 0;
        int bonus = 0;
        
        initializeGame(players, k, seed, &state);
    
    	int x;
	    //used 40 to fill the deck as it will provide plenty of cards to
	    //test each piece of the smithy effect function
	    for(x = 0; x < 40; x++)
	    {
	    	state.deck[0][x] = kWithGoldSilverCopper[rand() % 13];
	    	state.hand[0][x] = kWithGoldSilverCopper[rand() % 13];
	    }
	    
        int handCountBefore = numHandCards(&state);
        int deckCountBefore = state.deckCount[0];
        int totalCardsBefore = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
    
        int played =  cardEffect(smithy, 0, 0, 0, &state, handPos, &bonus);
        
        playerOneActionsTimes += assertEquals(0, state.numActions);
        correctNumberTimesPlayed += assertEquals(0, played);
        
        int totalCardsAfter = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
        int handDifference = abs(numHandCards(&state) - handCountBefore);
        int deckDifference = abs(state.deckCount[0] - deckCountBefore);
        
        //determine if hand has the right number of cards
        handCountCorrect += assertEquals(2, handDifference);
        //determine if deck has right number of cards
        deckCountCorrect += assertEquals(4, deckDifference);
        //make sure no cards were trashed
        totalCardCountCorrect += assertEquals(totalCardsBefore, totalCardsAfter);
	}
	printf("Correct number of actions after player one played smithy card %d of %d times\n", playerOneActionsTimes, TEST_LOOPS);
	printf("cardEffect returned correctly %d of %d times\n", correctNumberTimesPlayed ,TEST_LOOPS);
	printf("Correct number of cards in player one's hand %d of %d times\n", handCountCorrect, TEST_LOOPS);
	printf("Correct number of cards in player one's deck %d of %d times\n", deckCountCorrect, TEST_LOOPS);
	printf("Correct number of total cards for player one %d of %d times\n", totalCardCountCorrect, TEST_LOOPS);
}

int assertEquals(int expected, int actual)
{
    if(expected == actual)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}