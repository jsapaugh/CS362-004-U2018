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
   
}