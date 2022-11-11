#include <iostream>
#include <string>
#include "Merchant.h"

using namespace std;

Merchant::Merchant()
{
    ingredient = 1;
    pot = 5;
    pan = 10;
    cauldron = 20;
    club = 2;
    spear = 2;
    rapier = 5;
    battleaxe = 15;
    longsword = 50;
    armor = 5;
    ring = 10;
    necklace = 20;
    bracelet = 30;
    circlet = 40;
    goblet = 50;
}

int Merchant::getPrice(string item)
{
    if (item == "ingredient")
    {
        return ingredient;
    }

    if (item == "pot")
    {
        return pot;
    }
    
    if (item == "pan")
    {
        return pan;
    }
    if (item == "cauldron")
    {
        return cauldron;
    }
    if (item == "club")
    {
        return club;
    }
    if (item == "spear")
    {
        return spear;
    }
    if (item == "rapier")
    {
        return rapier;
    }
    if (item == "battleaxe")
    {
        return battleaxe;
    }
    if (item == "longsword")
    {
        return longsword;
    }
    if (item == "armor")
    {
        return armor;
    }
    if (item == "ring")
    {
        return ring;
    }
    if (item == "necklace")
    {
        return necklace;
    }
    if (item == "bracelet")
    {
        return bracelet;
    }
    if (item == "circlet")
    {
        return circlet;
    }
    if (item == "goblet")
    {
        return goblet;
    }
}

void Merchant::setPrice(string item, int price)
{
    if (item == "ingredient")
    {
        ingredient = price;
    }

    if (item == "pot")
    {
        pot = price;
    }
    
    if (item == "pan")
    {
        pan = price;
    }
    if (item == "cauldron")
    {
        cauldron = price;
    }
    if (item == "club")
    {
        club = price;
    }
    if (item == "spear")
    {
        spear = price;
    }
    if (item == "rapier")
    {
        rapier = price;
    }
    if (item == "battleaxe")
    {
        battleaxe = price;
    }
    if (item == "longsword")
    {
        longsword = price;
    }
    if (item == "armor")
    {
        armor = price;
    }
    if (item == "ring")
    {
        ring = price;
    }
    if (item == "necklace")
    {
        necklace = price;
    }
    if (item == "bracelet")
    {
        bracelet = price;
    }
    if (item == "circlet")
    {
        circlet = price;
    }
    if (item == "goblet")
    {
        goblet = price;
    }
}

/*
    1. Check if player can afford it
    2. If player can afford item, subtract price and add amount of player inventory
    3. Send a message, Depending if player could afford it or not
*/
string Merchant::buy(string item)
{
    return "Purchase successful";
}

/*
    1. Check if player has the item.
    2. If they do, remove it from their inventory and add the amount of gold to their inventory
    3. Return a message telling if transaction was successfull
*/
string Merchant::sell(string item)
{
    return "Sold the thing!";
}

/*
    1. Increase price of every itme by 25%
    2. Update each item price, round
*/
void Merchant::nextRound()
{
    ingredient = 3;
}