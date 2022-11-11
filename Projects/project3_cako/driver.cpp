//Code skeleton driver for project 3
//Robin Luo and Tyler Cako

#include <iostream>
#include "Status.h"
#include "Combat.h"
#include "Merchant.h"
#include "Cook.h"
#include <cassert>
using namespace std;

int main(){
    int weapons[5] = {1,2,3,4,5};
    Status status1;

    Combat combat1(5, weapons, 5);
    string party[5] = {"Joe", "John", "Kate", "Anna", "James"};
    status1.setParty(party);
    // test default constructor
    assert(status1.getFullnessAt(0) == 50);
    status1.printFullStatus();
    /* Expected output
    +-------------+
    | STATUS      |
    +-------------+
    | Rooms Cleared: 0 | Keys: 0 | Anger Level: 0
    +-------------+
    | INVENTORY   |
    +-------------+
    | Gold        | 0
    | Ingredients | 0 kg
    | Cookware    | P: 0 | F: 0 | C: 0
    | Weapons     | C: 0 | S: 0 | R: 0 | B: 0 | L: 0
    | Armor       | 0
    | Treasures   | R: 0 | N: 0 | B: 0 | C: 0 | G: 0
    +-------------+
    | PARTY       |
    +-------------+
    | Joe | Fullness: 50
    | John | Fullness: 50
    | Kate | Fullness: 50
    | Anna | Fullness: 50
    | James | Fullness: 50
    +-------------+
    */
   //Test for setter and getter
   status1.setArmor(5);
   assert(status1.getArmor() == 5);
   status1.setAnger(50);
   assert(status1.getAnger() == 50);
   int treasures[5] = {0,4,3,2,1};
   status1.setTreasures(treasures);
   assert(status1.getTreasuresAt(1) == 4);
   //Test for printing inventory
   status1.printInventory();
   /*Expected
    +-------------+
    | INVENTORY   |
    +-------------+
    | Gold        | 0
    | Ingredients | 0 kg
    | Cookware    | P: 0 | F: 0 | C: 0
    | Weapons     | C: 0 | S: 0 | R: 0 | B: 0 | L: 0
    | Armor       | 5
    | Treasures   | R: 0 | N: 4 | B: 3 | C: 2 | G: 1
    +-------------+
   */
    //Test to call get enemy
    assert(combat1.getEnemy(1) == "");
    //Test to call print functions in combat
    combat1.printEnemy();
    combat1.surrender();
    combat1.calcCombat();
    /*Expected
    Enemy
    You lost:
    You won
    */

    // Test constructors
    Merchant merchant1 = Merchant();
    Cook cook1 = Cook();

    // Check if Merchant getter works
    assert(merchant1.getPrice("ingredient") == 1);
    assert(merchant1.getPrice("rapier") == 5);
    assert(merchant1.getPrice("circlet") == 40);

    // Check if Merchant Setter works
    merchant1.setPrice("ingredient", 2);
    assert(merchant1.getPrice("ingredient") == 2);

    merchant1.setPrice("pan", 5);
    assert(merchant1.getPrice("pan") == 5);

    // Check if buy() can be called
    assert(merchant1.buy("test") == "Purchase successful");
    
    // Check if sell() can be called
    assert(merchant1.sell("test") == "Sold the thing!");

    // Test if nextRound() can be called
    merchant1.nextRound();
    assert(merchant1.getPrice("ingredient") == 3);

    // Test cook getters
    assert(cook1.getIngredients() == 0);
    assert(cook1.getCookware("pots") == 0);
    assert(cook1.getCookware("pans") == 0);
    assert(cook1.getCookware("cauldrons") == 0);
    
    // Test cook setters
    cook1.setIngredients(5);
    assert(cook1.getIngredients() == 5);

    cook1.setCookware("pots", 4);
    cook1.setCookware("pans", 3);
    cook1.setCookware("cauldrons", 1);

    assert(cook1.getCookware("pots") == 4);
    assert(cook1.getCookware("pans") == 3);
    assert(cook1.getCookware("cauldrons") == 1);
}