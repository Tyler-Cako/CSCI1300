// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 3 - Problem #3
#include<iostream>
#include<iomanip>
using namespace std;

int main() 
{
    char size = '0'; // Size is a single character, so use the char data type
    int toppings = 0;
    double total = 0;

    cout << "What size pizza would you like to order?" << endl;
    cin >> size;

    if (size != 'S' && size != 'M' && size != 'L') // Check for a valid size character S, M or L
    {
        cout << "Please enter a valid input." << endl;
        return 1;
    }

    cout << "How many toppings do you want?" << endl;
    cin >> toppings;

    if (toppings < 0) // Check for positive # of toppings
    {
        cout << "Please enter a valid input." << endl;
        return 1; 
    }

    // Calculate price based on # of toppings and size
    if (size == 'S')
    {
        total = 4.99 + (0.75 * toppings);
    }
    
    if (size == 'M')
    {
        total = 5.99 + (1.50 * toppings);
    }
    
    if (size == 'L')
    {
        total = 6.99 + (2.25 * toppings);
    }


    // Use setprecision() to make output to 2 decimal places.
    cout << fixed << setprecision(2);

    cout << "Your total is $" << total << endl;
}