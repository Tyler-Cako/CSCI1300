#ifndef COOK
#define COOK

#include <iostream>
#include <string>

using namespace std;

class Cook
{
    private:
    int ingredients;
    int pots;
    int pans;
    int cauldrons;

    public:
    Cook();

    int getIngredients();
    void setIngredients(int);

    int getCookware(string);
    void setCookware(string, int);

    string cookFood(string);
};

#endif