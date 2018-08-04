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
void assertEquals(int expected, int actual, char message[]);


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
    assertEquals(getCost(curse),0, "Testing cost of curse");
}
void testCostEstate()
{
    assertEquals(getCost(estate),2, "Testing cost of estate");
}
void testCostDuchy()
{
    assertEquals(getCost(duchy),5, "Testing cost of duchy");
}
void testCostProvince()
{
    assertEquals(getCost(province),8, "Testing cost of province");
}
void testCostCopper()
{
    assertEquals(getCost(copper),0, "Testing cost of copper");
}
void testCostSilver()
{
    assertEquals(getCost(silver),3, "Testing cost of silver");
}
void testCostGold()
{
 assertEquals(getCost(gold),6, "Testing cost of gold");   
}
void testCostAdventurer()
{
 assertEquals(getCost(adventurer),6, "Testing cost of adventurer");   
}
void testCostCouncilRoom()
{
    assertEquals(getCost(council_room),5, "Testing cost of council_room");
}
void testCostFeast()
{
    assertEquals(getCost(feast),4, "Testing cost of feast");
}
void testCostGardens()
{
    assertEquals(getCost(gardens),4, "Testing cost of gardens");    
}
void testCostMine()
{
    assertEquals(getCost(mine),5, "Testing cost of mine");    
}
void testCostRemodel()
{
    assertEquals(getCost(remodel),4, "Testing cost of remodel");    
}
void testCostSmithy()
{
    assertEquals(getCost(smithy),4, "Testing cost of smithy");    
}
void testCostVillage()
{
    assertEquals(getCost(village),3, "Testing cost of village");    
}
void testCostBaron()
{
    assertEquals(getCost(baron),4, "Testing cost of baron");    
}
void testCostGreatHall()
{
    assertEquals(getCost(great_hall),3, "Testing cost of great_hall");    
}
void testCostMinion()
{
    assertEquals(getCost(minion),5, "Testing cost of minion");    
}
void testCostSteward()
{
    assertEquals(getCost(steward),3, "Testing cost of steward");    
}
void testCostTribute()
{
    assertEquals(getCost(tribute),5, "Testing cost of tribute");    
}
void testCostAmbassador()
{
    assertEquals(getCost(ambassador),3, "Testing cost of ambassador");    
}
void testCostCutpurse()
{
    assertEquals(getCost(cutpurse),4, "Testing cost of cutpurse");    
}
void testCostEmbargo() 
{
    assertEquals(getCost(embargo),2, "Testing cost of embargo");    
}
void testCostOutpost()
{
    assertEquals(getCost(outpost),5, "Testing cost of outpost");    
}
void testCostSalvager()
{
    assertEquals(getCost(salvager),4, "Testing cost of salvager");    
}
void testCostSeaHag()
{
    assertEquals(getCost(sea_hag),4, "Testing cost of sea_hag");    
}
void testCostTreasureMap()
{
    assertEquals(getCost(treasure_map),4, "Testing cost of treasure_map");    
}
void testDefault()
{
    assertEquals(getCost(27),-1, "Testing cost of the default value");
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