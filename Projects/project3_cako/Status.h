#include <iostream>

using namespace std;

//Class that keeps track of the party's status and all data that is changed
class Status
{
private:
    int rooms_ = 0;
    int key_ = 0;
    int anger_ = 0;
    int fullness_[5];
    int gold_ = 0;
    int cookware_[3];
    int weapons_[5];
    string party_[5];
    int armor_ = 0;
    int ingredients_ = 0;
    int treasures_[5];
public:
    //Default
    Status();
    //Setters
    void setKey(int);
    void setRooms(int);
    void setAnger(int);
    void setGold(int);
    void setArmor(int);
    void setIngredients(int);
    void setTreasures(int[]);
    void setCookware(int[]);
    void setWeapons(int[]);
    void setParty(string[]);
    void setFullness(int[]);
    //Getters
    int getKey();
    int getRooms();
    int getAnger();
    int getGold();
    int getIngredients();
    int getArmor();
    int getTreasuresAt(int);
    int getCookwareAt(int);
    int getWeaponAt(int);
    string getPartyAt(int);
    int getFullnessAt(int);

    //Display status
    void printFullStatus();
    void printInventory();
    void printParty();

};
