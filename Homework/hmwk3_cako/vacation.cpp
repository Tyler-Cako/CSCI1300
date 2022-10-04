// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 3 - Problem #2
#include <iostream>
using namespace std;

int main() 
{
    // Initialize Variables
    double budget = 0;
    char trans = '0'; //Since the selection input is a single character, use the char dat type

    cout << "What is your budget?" << endl;
    cin >> budget;

    if (budget < 0) // Check that budget is a non-negative number
    {
        cout << "Please enter a valid input. " << endl;
        return 1;
    }

    cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
    cin >> trans;

    if (trans != 'B' && trans != 'T' && trans != 'A') // Check for input character of B, T or A
    {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    // Check budget with mode of transportation
    if ( trans == 'T') 
    {
        if (budget >= 240.66)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
            return 0;
        }

        else {
            cout << "Sorry, this vacation is outside your budget." << endl;
            return 0;
        }
    }

        if ( trans == 'B') 
    {
        if (budget >= 175.25)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
            return 0;
        }

        else {
            cout << "Sorry, this vacation is outside your budget." << endl;
            return 0;
        }
    }

        if ( trans == 'A') 
    {
        if (budget >= 350.93)
        {
            cout << "Yes, this vacation is within your budget!" << endl;
            return 0;
        }

        else {
            cout << "Sorry, this vacation is outside your budget." << endl;
            return 0;
        }
    }

    return 0;
}