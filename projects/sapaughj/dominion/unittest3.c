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
* Testing int* kingdomCards(..)
*/

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

    for(i = 0; i < 10; i++)
    {
        assertEquals(i,*(k+i));
    }
    
    int* k2 = kingdomCards(3,4,5,8,1,15,2,6,7,25);
    int testAgainst[10] = {3,4,5,8,1,15,2,6,7,25};
    
    for(i = 0; i < 10; i++)
    {
        assertEquals(testAgainst[i],*(k2+i));
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