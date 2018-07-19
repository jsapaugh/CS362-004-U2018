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
* Testing getCost(...); from dominion.c
*/
void testCostCurse();
void testCostEstate();
void testCostDuchy();
void testCostProvince();
void testCostCopper();
void testCostSilver();
void testCostGold();
void testCostAdventurer();
void testCostCouncilRoom();
void testCostFeast();
void testCostGardens();
void testCostMine();
void testCostRemodel();
void testCostSmithy();
void testCostVillage();
void testCostBaron();
void testCostGreatHall();
void testCostMinion();
void testCostSteward();
void testCostTribute();
void testCostAmbassador();
void testCostCutpurse();
void testCostEmbargo(); 
void testCostOutpost();
void testCostSalvager();
void testCostSeaHag();
void testCostTreasureMap();
void testDefault();
void assertEquals(int expected, int actual);


int main(int argc, char *argv[])
{
    char functionUnderTest[] = "int getCost(int cardNumber)";
    printf("__________________________________________________________________\n");
    fflush(stdout);        
    printf("*******Begin testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    testCostCurse();
    testCostEstate();
    testCostDuchy();
    testCostProvince();
    testCostCopper();
    testCostSilver();
    testCostGold();
    testCostAdventurer();
    testCostCouncilRoom();
    testCostFeast();
    testCostGardens();
    testCostMine();
    testCostRemodel();
    testCostSmithy();
    testCostVillage();
    testCostBaron();
    testCostGreatHall();
    testCostMinion();
    testCostSteward();
    testCostTribute();
    testCostAmbassador();
    testCostCutpurse();
    testCostEmbargo(); 
    testCostOutpost();
    testCostSalvager();
    testCostSeaHag();
    testCostTreasureMap();
    testDefault();
    fflush(stdout);        
    printf("*******End testing of %s*******\n",functionUnderTest);
    fflush(stdout);        
    printf("__________________________________________________________________\n");
    fflush(stdout);        
}

void testCostCurse()
{
    assertEquals(getCost(curse),0);
}
void testCostEstate()
{
    assertEquals(getCost(estate),2);
}
void testCostDuchy()
{
    assertEquals(getCost(duchy),5);
}
void testCostProvince()
{
    assertEquals(getCost(province),8);
}
void testCostCopper()
{
    assertEquals(getCost(copper),0);
}
void testCostSilver()
{
    assertEquals(getCost(silver),3);
}
void testCostGold()
{
 assertEquals(getCost(gold),6);   
}
void testCostAdventurer()
{
 assertEquals(getCost(adventurer),6);   
}
void testCostCouncilRoom()
{
    assertEquals(getCost(council_room),5);
}
void testCostFeast()
{
    assertEquals(getCost(feast),4);
}
void testCostGardens()
{
    assertEquals(getCost(gardens),4);    
}
void testCostMine()
{
    assertEquals(getCost(mine),5);    
}
void testCostRemodel()
{
    assertEquals(getCost(remodel),4);    
}
void testCostSmithy()
{
    assertEquals(getCost(smithy),4);    
}
void testCostVillage()
{
    assertEquals(getCost(village),3);    
}
void testCostBaron()
{
    assertEquals(getCost(baron),4);    
}
void testCostGreatHall()
{
    assertEquals(getCost(great_hall),3);    
}
void testCostMinion()
{
    assertEquals(getCost(minion),5);    
}
void testCostSteward()
{
    assertEquals(getCost(steward),3);    
}
void testCostTribute()
{
    assertEquals(getCost(tribute),5);    
}
void testCostAmbassador()
{
    assertEquals(getCost(ambassador),3);    
}
void testCostCutpurse()
{
    assertEquals(getCost(cutpurse),4);    
}
void testCostEmbargo() 
{
    assertEquals(getCost(embargo),2);    
}
void testCostOutpost()
{
    assertEquals(getCost(outpost),5);    
}
void testCostSalvager()
{
    assertEquals(getCost(salvager),4);    
}
void testCostSeaHag()
{
    assertEquals(getCost(sea_hag),4);    
}
void testCostTreasureMap()
{
    assertEquals(getCost(treasure_map),4);    
}
void testDefault()
{
    assertEquals(getCost(27),-1);
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
        printf("\t****************TEST FAILED****************\n");
        fflush(stdout);        
    }
}