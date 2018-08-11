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

#define TEST_LOOPS 1000

int assertEquals(int expected, int actual);
void testVillage();
int checkTreasureInDeck(struct gameState *state);
int checkTreasureInHand(struct gameState *state);


int main(int argc, char* argv[]) 
{
    char functionUnderTest[] = "int cardEffect(...) villageEffect(...)";

    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    
    testVillage();
    
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
	
    return 0;
}

void testVillage()
{
	time_t t;
	srand((unsigned) time(&t));
	int i;
	int k[10] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager};
	int kWithGoldSilverCopper[13] = {adventurer, gardens, smithy, village, great_hall, council_room, ambassador, mine, cutpurse, salvager, gold, silver, copper};
	int correctHandDiffPlayerOne = 0;
    int correctHandDiffPlayerTwo = 0;
    int correctHandDiffPlayerThree = 0;
    int correctTotalCardsPlayerOne = 0;
	int playerOneActionsTimes = 0;
	int correctNumberTimesPlayed = 0;
	
    for(i = 0; i < TEST_LOOPS; i++)
    {
        struct gameState state;
        int players = 3;
        int seed = 100;
        int handPos = 0;
        int bonus = 0;
    	
        initializeGame(players, k, seed, &state);
    	int x;
        //used 40 to fill the deck as it will provide plenty of cards to
        //test each piece of the village effect function
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
        int played =  cardEffect(village, 0, 0, 0, &state, handPos, &bonus);
        
        playerOneActionsTimes += assertEquals(2, state.numActions);
        correctNumberTimesPlayed += assertEquals(0, played);
        
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
        correctHandDiffPlayerOne += assertEquals(2, handDifferencePlayerOne);
        correctHandDiffPlayerTwo += assertEquals(0, handDifferencePlayerTwo);
        correctHandDiffPlayerThree += assertEquals(0, handDifferencePlayerThree);
        
        //make sure no cards were trashed
        correctTotalCardsPlayerOne += assertEquals(totalCardsBeforePlayerOne, totalCardsAfterPlayerOne);
    }
    
    printf("Correct number of actions after player one played village card %d of %d times\n", playerOneActionsTimes, TEST_LOOPS);
	printf("cardEffect returned correctly %d of %d times\n", correctNumberTimesPlayed ,TEST_LOOPS);
	printf("Correct number of cards in player one's hand %d of %d times\n", correctHandDiffPlayerOne, TEST_LOOPS);
	printf("Correct number of cards in player two's hand %d of %d times\n", correctHandDiffPlayerTwo, TEST_LOOPS);
	printf("Correct number of cards in player three's hand %d of %d times\n", correctHandDiffPlayerThree, TEST_LOOPS);
	printf("Correct number of cards in player ones's hand+deck+discard %d of %d times\n", correctTotalCardsPlayerOne, TEST_LOOPS);
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