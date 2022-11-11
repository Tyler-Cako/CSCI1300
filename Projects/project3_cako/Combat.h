#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Combat
{
private:
    int weapon_strength_ = 0;
    int armor_ = 0;
    int d = 0;
    vector<string> monsters_;
    string enemy_ = "";
public:
    //Constructors
    //Initializes weapon strength accoring to the equation, uses the weapons array
    //Parameters(challenge rating, weapons, armor)
    Combat(int, int[], int);
    ~Combat();
    //Getters
    //Takes in challenge level
    string getEnemy(int);

    //Randomly pick enemy monster that fits with challenge rating
    //and then print out their name
    void printEnemy();
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
    void calcCombat();
    //every member's fullness has a 50% chance to drop by one point
    void combatEnd();
    //If they decide to surrender or cant attack due to lack of weapons
    //One member (not the player) is lost
    void surrender();

};

