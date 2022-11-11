#ifndef MERCHANT
#define MERCHANT

#include <iostream>
#include <string>

using namespace std;

class Merchant
{
    private:
    int ingredient;
    int pot;
    int pan;
    int cauldron;
    int club;
    int spear;
    int rapier;
    int battleaxe;
    int longsword;
    int armor;
    int ring;
    int necklace;
    int bracelet;
    int circlet;
    int goblet;
    
    public:
    Merchant();

    int getPrice(string);
    void setPrice(string, int);

    string buy(string);
    string sell(string);

    void nextRound();
};

#endif