// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 4 - Problem #3

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    //variable initialization
    int potion_category = 0;
    int potions_possible = 0;
    int mana = 0;
    int heal = 0;
    int honey = -1;
    int dand = -1;
    int coal = -1;
    int toad = -1;

    while (potion_category != 1 && potion_category != 2 )
    {
        cout << "Select a potion crafting priority:\n1. Minor Mana\n2. Minor Healing\n";
        cin >> potion_category;

        // input validation
        if (potion_category != 1 && potion_category != 2)
        {
            cout << "Invalid input. " << endl;
        }
    }

    // Input and input validation
    while ( honey < 0)
    {
        cout << "How many Honeycombs do you have?" << endl;
        cin >> honey;

        if (honey < 0)
            {
                cout << "Invalid input. ";
            }
        }

    while ( dand < 0)
        {
            cout << "How many Dandelions do you have?" << endl;
            cin >> dand;

            if (dand < 0)
            {
                cout << "Invalid input. ";
            }
        } 

    while ( coal < 0)
        {
            cout << "How many Coal do you have?" << endl;
            cin >> coal;

            if (coal < 0)
            {
                cout << "Invalid input. ";
            }
        }

    while (toad < 0)
    {

        cout << "How many Toadstools do you have?" << endl;
        cin >> toad;

        if (toad < 0)
        {
            cout << "Invalid input. ";
        }
    }

    // Check between potion types, then check users inventory to calculate the number of potions you can make of each depending on the chosen prioritized type.
    switch (potion_category)
    {
        case 1:
            while (honey/5 > 0 && dand/3 > 0 && coal > 0)
            {
                mana++;
                honey = honey - 5;
                dand = dand - 3;
                coal--;
            }

            while (honey/5 > 0 && coal/2 > 0 && toad/3 > 0)
            {
                heal++;
                honey = honey - 5;
                coal = coal - 2;
                toad = toad - 3;
            }

            cout << "You can make " << mana << " Mana potion(s) and " << heal << " Healing potion(s).";
            break;

        case 2:
        {

            while (honey/5 > 0 && coal/2 > 0 && toad/3 > 0)
            {
                heal++;
                honey = honey - 5;
                coal = coal - 2;
                toad = toad - 3;
            }

            while (honey/5 > 0 && dand/3 > 0 && coal > 0)
            {
                mana++;
                honey = honey - 5;
                dand = dand - 3;
                coal--;
            }

            cout << "You can make " << heal << " Healing potion(s) and " << mana << " Mana potion(s).";
            break;
        }
    }
}