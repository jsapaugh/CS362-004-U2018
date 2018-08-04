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

void assertEquals(int expected, int actual, char message[]);
void testScoreFor();

int main(int argc, char* argv[])
{
    
    char functionUnderTest[] = "int scoreFor (int player, struct gameState *state)";
    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    
    testScoreFor();
    
    fflush(stdout);        
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout); 
}

void testScoreFor()
{
    struct gameState state;
    int players = 4;
    int seed = 50;
    int k[10] = {adventurer, smithy, gardens, embargo, village, steward, mine, cutpurse, outpost, tribute};
    
    initializeGame(players, k, seed, &state);
    //player one hand/deck/discard
    state.hand[1][0] = estate;
    state.hand[1][1] = estate;
    state.hand[1][2] = estate;
    state.handCount[1] = 3;
    
    state.discard[1][0] = curse;
    state.discard[1][1] = gardens;
    state.discard[1][2] = embargo;
    state.discard[1][3] = village;
    state.discard[1][4] = mine;
    state.discard[1][5] = cutpurse;
    state.discardCount[1] = 6;
    
    state.deck[1][1] = embargo;
    state.deck[1][2] = smithy;
    state.deckCount[1] = 2;
    
    //player twos hand/deck/discard
    state.hand[2][0] = estate;
    state.hand[2][1] = estate;
    state.hand[2][2] = estate;
    state.hand[2][3] = estate;
    state.handCount[2] = 4;

    //player three hand/deck/discard
    state.hand[3][0] = estate;
    state.hand[3][1] = estate;
    state.hand[3][2] = estate;
    state.hand[3][3] = estate;
    state.hand[3][4] = estate;
    state.hand[3][5] = gardens;
    state.handCount[3] = 6;
    
    state.discard[3][0] = gardens;
    state.discardCount[3] = 1;
    
    state.deck[3][0] = gardens;
    state.deck[3][1] = gardens;
    state.deck[3][2] = gardens;
    state.deck[3][3] = gardens;
    state.deckCount[3] = 4;
    
    //player four hand/deck/discard
    state.deck[4][0] = estate;
    state.deck[4][1] = estate;
    state.deck[4][2] = estate;
    state.deckCount[4] = 3;
    state.discardCount[4] = 0;
    state.handCount[4] = 0;

    int scoreForPlayerTwo, scoreForPlayerOne, scoreForPlayerThree, scoreForPlayerFour;
    
    //should be 3
    scoreForPlayerOne = scoreFor(1, &state);
    //should be 4
    scoreForPlayerTwo = scoreFor(2, &state);
    //should be 10
    scoreForPlayerThree = scoreFor(3, &state);
    //should be 3
    scoreForPlayerFour = scoreFor(4, &state);
    
    // player one point total 3(estate)-1(curse)+1(gardens 10 cards) = 3
    assertEquals(3, scoreForPlayerOne, "Testing player one point total");
    // player two point total 4(estate) = 4
    assertEquals(4, scoreForPlayerTwo, "Testing player two point total");
    //6pts(6x gardens with 10 cards)+5pts(estates)=10
    assertEquals(11, scoreForPlayerThree, "Testing player three point total");
    //3 estate cards in deck = 3 points
    assertEquals(3, scoreForPlayerFour, "Testing player four point total");
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