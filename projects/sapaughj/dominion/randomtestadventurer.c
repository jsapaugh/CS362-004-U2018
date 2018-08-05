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
//using 2000 loops to ensure every line gets hit every time
#define TEST_LOOPS 2000

int assertEquals(int expected, int actual);
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
	int playerOneHandTimes = 0;
	int playerTwoHandTimes = 0;
	int playerThreeHandTimes = 0;
	int playerOneTotalTimes = 0;
	int playerOneTreasureHandTimes = 0;
	int playerOneTreasureDeckTimes = 0;
	int playerOneActionsTimes = 0;
	int correctNumberTimesPlayed = 0;
	
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
	    //used 40 to fill the deck as it will provide plenty of cards to
	    //test each piece of the adventurer effect function
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
	    
	    playerOneActionsTimes += assertEquals(0, state.numActions);
	    correctNumberTimesPlayed += assertEquals(0, played);

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
	    playerOneHandTimes += assertEquals(2, handDifferencePlayerOne);
	    playerTwoHandTimes += assertEquals(0, handDifferencePlayerTwo);
	    playerThreeHandTimes += assertEquals(0, handDifferencePlayerThree);
	    
	    //make sure no cards were trashed for player one
	    playerOneTotalTimes += assertEquals(totalCardsBeforePlayerOne, totalCardsAfterPlayerOne);
	    //secondary check to make sure only treasures were removed and added to hand
	    playerOneTreasureDeckTimes += assertEquals(treasureInDeckBeforePlayerOne - 2, treasureInDeckAfterPlayerOne);
	    playerOneTreasureHandTimes += assertEquals(treasureInHandBeforePlayerOne + 2, treasureInHandAfterPlayerOne);
	}
	printf("Correct number of cards in player one's hand %d of %d times\n", playerOneHandTimes, TEST_LOOPS);
	printf("Correct number of cards in player two's hand %d of %d times\n", playerTwoHandTimes, TEST_LOOPS);
	printf("Correct number of cards in player three's hand %d of %d times\n", playerThreeHandTimes, TEST_LOOPS);
	printf("Correct number of total cards in player one's hand+deck+discard %d of %d times\n", playerOneTotalTimes, TEST_LOOPS);
	printf("Correct number of treasure cards in player ones's hand %d of %d times\n", playerOneTreasureHandTimes, TEST_LOOPS);
	printf("Correct number of treasure cards in player ones's deck %d of %d times\n", playerOneTreasureDeckTimes, TEST_LOOPS);
	printf("Correct number of actions after player one played adventurer card %d of %d times\n", playerOneActionsTimes, TEST_LOOPS);
	printf("cardEffect returned correctly %d of %d times\n",correctNumberTimesPlayed ,TEST_LOOPS);
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