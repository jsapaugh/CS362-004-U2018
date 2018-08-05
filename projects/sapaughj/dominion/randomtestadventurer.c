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

#define TEST_LOOPS 2000

void assertEquals(int expected, int actual, char message []);
void testAdventurer();
int checkTreasureInDeck(struct gameState *state);
int checkTreasureInHand(struct gameState *state);

int main(int argc, char* argv[])
{
    char functionUnderTest[] = "int cardEffect(...) adventurerEffect(...)";

    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    
    testAdventurer();
    
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
	
    return 0;
}

void testAdventurer()
{
		//seeding random number generator
	time_t t;
	srand((unsigned) time(&t));
	int i;
	int k[10] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager};
	int kWithGoldSilverCopper[13] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager, gold, silver, copper};
	
	for(i = 0; i < TEST_LOOPS; i++)
	{
	    struct gameState state;
	    int players = 3;
	    int seed = rand();
	    int handPos = 0;
	    int bonus = 0;
	    
		
	    initializeGame(players, k, seed, &state);
	    //fill the players hand with some cards that are in the game, including gold, silver, copper.
	    int x;
	    for(x = 0; x < 40; x++)
	    {
	    	state.deck[0][x] = kWithGoldSilverCopper[rand() % 13];
	    	state.hand[0][x] = kWithGoldSilverCopper[rand() % 13];
	    }
	    
	    state.whoseTurn = 1;
	    int handCountBeforePlayerTwo = numHandCards(&state);
	
	    state.whoseTurn = 2;
	    int handCountBeforePlayerThree = numHandCards(&state);
	    
	    state.whoseTurn = 0;
	    int handCountBeforePlayerOne = numHandCards(&state);
	    int totalCardsBeforePlayerOne = state.deckCount[0] + state.discardCount[0] + state.handCount[0];
	    int treasureInDeckBeforePlayerOne = checkTreasureInDeck(&state);
	    int treasureInHandBeforePlayerOne = checkTreasureInHand(&state);
	    
	    int played =  cardEffect(adventurer, 0, 0, 0, &state, handPos, &bonus);
	    
	    assertEquals(0, state.numActions, "Testing total number of actions after playing adventurer for player one");
	    assertEquals(0, played, "Testing return code on cardEffect(...)");

		int treasureInDeckAfterPlayerOne = checkTreasureInDeck(&state);
		int treasureInHandAfterPlayerOne = checkTreasureInHand(&state);
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
	    assertEquals(2, handDifferencePlayerOne, "Testing difference in cards in hand for player one");
	    assertEquals(0, handDifferencePlayerTwo, "Testing difference in cards in hand for player two");
	    assertEquals(0, handDifferencePlayerThree, "Testing difference in cards in hand for player three");
	    
	    //make sure no cards were trashed for player one
	    assertEquals(totalCardsBeforePlayerOne, totalCardsAfterPlayerOne, "Confirming no cards were trashed for player one");
	    //secondary check to make sure only treasures were removed and added to hand
	    assertEquals(treasureInDeckBeforePlayerOne - 2, treasureInDeckAfterPlayerOne, "Checking treasure count in deck for player one.");
	    assertEquals(treasureInHandBeforePlayerOne + 2, treasureInHandAfterPlayerOne, "Checking treasure count in hand for player one.");
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