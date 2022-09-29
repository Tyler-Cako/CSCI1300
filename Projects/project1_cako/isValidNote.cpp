// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #1
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

bool isValidNote(string note)
{
    // Initialize Variables
    char letter = note[0];
    char number = note[1];
    bool is_true = false;

    // Check if note legnth is valid
    // Return with false whenever it fails ANY test
    if (note.length() != 2)
    {
        is_true = false;
        return is_true; 
    }

    // Check if note letter  is valid
    if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F' || letter == 'G')
    {
        is_true = true;
    }
    else
    {
        is_true = false;
        return is_true;
    }

    // Test if note number is valid
    if (number == '0' || number == '1' || number == '2' || number == '3' || number == '4' || number == '5' || number == '6' || number == '7' || number == '8' || number == '9')
    {
        is_true = true;
    }
    else
    {
        is_true = false;
        return is_true;
    }

    return is_true;
}

int main()
{
    // Test function in main()
    
    string input;

    cout << "Enter input" << endl;

    cin >> input;

    cout << isValidNote(input) << endl;
}