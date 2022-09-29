// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 3 - Problem #4
#include<iostream>
using namespace std;

int main() 
{
    double speed1, speed2, speed3 = 0; // Initialize speed variables

    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> speed1 >> speed2 >> speed3; // Set space-divided input into 3 doubles

    // Checking if inputs are sorted correctly, if no clear change, throw the user an error.
    // Otherwise, tell user that speeds is increasing, decreasing or constant.
    if (speed1 < 0 || speed2 < 0 || speed3 < 0) 
    {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    if ((speed2 - speed1) <= 0 )
    {
        if (speed3 == (speed2 - speed1) || (speed3 - speed2) >= 0)
        {
            cout << "The wifi speed is changing unpredictably."<<endl;
            return 0;
        }
        if ((speed3 - speed2) <= 0)
        {
            cout << "The wifi is getting slower!" << endl;
            return 0;
        }
    }

    if ((speed2 - speed1) >= 0 )
    {
        if (speed3 == (speed2 - speed1) || (speed3 - speed2) <= 0)
        {
            cout << "The wifi speed is changing unpredictably."<<endl;
            return 0;
        }
        if ((speed3 - speed2) >= 0)
        {
            cout << "The wifi is getting faster!" << endl;
            return 0;
        }
    }
}