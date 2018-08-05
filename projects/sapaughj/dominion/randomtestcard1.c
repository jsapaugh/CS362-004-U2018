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

#define TEST_LOOPS 750

void assertEquals(int expected, int actual, char message []);
void testSmithy();
int checkTreasureInDeck(struct gameState *state);
int checkTreasureInHand(struct gameState *state);

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

	for(i = 0; i < TEST_LOOPS; i++)
	{    
    	struct gameState state;
        int players = 2;
        int seed = rand();
        int handPos = 0;
        int bonus = 0;
        
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

int checkTreasureInHand(struct gameState *state) 
{
    int count = 0;
	int currentPlayer = state->whoseTurn;
    int i;
    for (i = 0; i < state->handCount[currentPlayer]; i++) 
    {
        if(state->hand[currentPlayer][i] == copper || state->hand[currentPlayer][i] == silver || state->hand[currentPlayer][i] == gold) 
        {
                count++;
        }
    }
    return count;
}

int checkTreasureInDeck(struct gameState *state) 
{
    int count = 0;
	int currentPlayer = state->whoseTurn;
    int i;
    for (i = 0; i < state->deckCount[currentPlayer]; i++) 
    {
        if(state->deck[currentPlayer][i] == copper || state->deck[currentPlayer][i] == silver || state->deck[currentPlayer][i] == gold) 
        {
                count++;
        }
    }
    return count;
}