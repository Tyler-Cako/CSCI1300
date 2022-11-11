#include <string>
#include<iostream>
#include "Cook.h"

using namespace std;

Cook::Cook()
{
    ingredients = 0;
    pots = 0;
    pans = 0;
    cauldrons = 0;
}

int Cook::getIngredients()
{
    return ingredients;
}

void Cook::setIngredients(int num_ingredients)
{
    ingredients = num_ingredients;
}

/*

*/
int Cook::getCookware(string cookware)
{
    if (cookware == "pots")
    {
        return pots;
    }
    
    if (cookware == "pans")
    {
        return pans;
    }

    if (cookware == "cauldrons")
    {
        return cauldrons;
    }
}

void Cook::setCookware(string cookware, int num_cookware)
{
    if (cookware == "pots")
    {
        pots += num_cookware;
    }
    
    if (cookware == "pans")
    {
        pans += num_cookware;
    }

    if (cookware == "cauldrons")
    {
        cauldrons += num_cookware;
    }
}

/*
    1. Check which cookware that's being used, change chance of failure dependoning on that
    2. Subtract ingredients
    3. Roll for failure, if fail, no food and destroy cookware, otherwise, keep cookware and add 1 food
    4. Output result msg
*/
string Cook::cookFood(string cookware)
{
    return "Food cooked!";
}