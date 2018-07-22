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
int scoreFor (int player, struct gameState *state) {

  int i;
  int score = 0;
  //score from hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == curse) { score = score - 1; };
      if (state->hand[player][i] == estate) { score = score + 1; };
      if (state->hand[player][i] == duchy) { score = score + 3; };
      if (state->hand[player][i] == province) { score = score + 6; };
      if (state->hand[player][i] == great_hall) { score = score + 1; };
      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  //score from discard
  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->discard[player][i] == curse) { score = score - 1; };
      if (state->discard[player][i] == estate) { score = score + 1; };
      if (state->discard[player][i] == duchy) { score = score + 3; };
      if (state->discard[player][i] == province) { score = score + 6; };
      if (state->discard[player][i] == great_hall) { score = score + 1; };
      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  //score from deck
  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->deck[player][i] == curse) { score = score - 1; };
      if (state->deck[player][i] == estate) { score = score + 1; };
      if (state->deck[player][i] == duchy) { score = score + 3; };
      if (state->deck[player][i] == province) { score = score + 6; };
      if (state->deck[player][i] == great_hall) { score = score + 1; };
      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  return score;
}
*/

void assertEquals(int expected, int actual);
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
    state.hand[3][4] = gardens;
    state.handCount[3] = 5;
    
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
    
    scoreForPlayerOne = scoreFor(1, &state);
    scoreForPlayerTwo = scoreFor(2, &state);
    scoreForPlayerThree = scoreFor(3, &state);
    scoreForPlayerFour = scoreFor(4, &state);
    
    // player one point total 3(estate)-1(curse)+1(gardens) = 3
    assertEquals(3, scoreForPlayerOne);
    // player two point total 4(estate) = 4
    assertEquals(4, scoreForPlayerTwo);
    //6x gardens with 10 cards = 6pts+4pts(estates)=10
    assertEquals(10, scoreForPlayerThree);
    //3 estate cards in deck = 3 points
    assertEquals(3, scoreForPlayerFour);
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
        printf("\t************************TEST FAILED************************\n");
        fflush(stdout);        
    }
}