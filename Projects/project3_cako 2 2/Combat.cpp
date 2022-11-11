#include <iostream>
#include "Combat.h"
#include "Status.h"
#include <fstream>

using namespace std;

//Constructors
//Initializes weapon strength accoring to the equation, uses the weapons array
//
Combat::Combat(int challenge_level, int weapons[], int armor)
{
    //populate the monsters vector array using split function and file streams
    armor_ = armor;
    //Apply equation for weapons to get weapon strength
    //Check if weapons are unique to get d
}

Combat::~Combat()
{
    
}

//Getters
string Combat::getEnemy(int){
    return enemy_;
};

//Randomly pick enemy monster that fits with challenge rating
//and then print out their name
void Combat::printEnemy(){
    cout << "Enemy" << endl;
};

/*Apply algorithem (r1*w+d) - (r2 *c)/a
Then check if the result is greater than 0 or less than and equal to 0
    If greater than then update party gold and ingredients
    10% chance to add key
    Remove the monster defeated from the vector list of monsters
Else if the number is less than or equal to 0
    Party loses a quarter of their gold, up to 30 ingredients
    Each party member has a 10% chance of being slain (5% with armor)
If a party member dies print member's death
*/
void Combat::calcCombat(){
    cout << "You won" << endl; 

};
//every member's fullness has a 50% chance to drop by one point
void Combat::combatEnd(){
    cout << "your new part stats are" << endl;
};
//If they decide to surrender or cant attack due to lack of weapons
//One member (not the player) is lost
void Combat::surrender(){
    cout << "You lost: " << endl;
};



