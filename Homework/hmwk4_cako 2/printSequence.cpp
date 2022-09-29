// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 4 - Problem #2

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int value = 0;

    while (value == 0)
    {
        int temp = 0;
        cout << "Enter  a value between 1 and 1000:" << endl;
        cin >> temp;

        if (temp <= 1 || temp >= 1000) // Input validation
        {
            cout << "Invalid input." << endl;
        }
        else
        {
            value = temp;
        }
    }

    cout << value << endl;
    
    while (value != 1) // While loop to iterature between odd and even values
    {
        if ( value % 2 == 0)
        {
            value = floor(value / 2);
        }
        else if ( value % 2 != 0)
        {
            value = (value * 3) + 1;
        }

        cout << value << endl;
    }
}