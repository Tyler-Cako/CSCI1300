#include<iostream>
#include<string>
#include<cassert>
#include"Merchant.h"
#include"Cook.h"

using namespace std;

int main()
{
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