/*
* Author : Jacob Sapaugh
*          Oregon State University
*          CS 362
*          07-18-2018
*/

/*
* testing int* kingdomCards(..)
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void assertEquals(int expected, int actual);
void testKingdomCards();

int main(int argc, char * argv[])
{
    char functionUnderTest[] = "int* kingdomCards(...)";
    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    
    testKingdomCards();
    
    fflush(stdout);        
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
}

void testKingdomCards()
{
    int* k = kingdomCards(0,1,2,3,4,5,6,7,8,9);
    int i = 0;
    int arraySize = (int)(sizeof(k)/sizeof(k[0]));

    for(i = 0; i < 10; i++)
    {
        assertEquals(i,*(k+i));
    }
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