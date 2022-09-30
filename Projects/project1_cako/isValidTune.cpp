// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #2
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidTune(string tune)
{
    // Initialize variables
    bool is_true = false;

    /* Aglorithm
   We need to test for instances of valid SPN within a string, therefore, we need to loop through the entire string (for loop),
   and then test for a correctly formatted letter, and then a valid number (nested if statement)

   Continue doing this until an incorrectly formatted character is found. In that case, reutne false,  otherwise, return true.

   Testing could've been done with a for loop, but the number of conditions aren't big enough to really require it. Plus, it might be faster than iterating than
   a string of all valid values.
   */

    for (int i = 0; i < tune.length(); i++)
    {
        char character = tune[i];

        // Check if odd
        if (tune.length()%2 != 0)
        {
            is_true = false;
            return is_true;
        }

        // Check if note letter  is valid
        if (character != 'A' && character != 'B' && character != 'C' && character != 'D' && character != 'E' && character != 'F' && character != 'G' && character != '0' && character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' && character != '9')
        {
            is_true = false;
            return is_true;
        }
        else {
            is_true = true;
        }

        // If there is just a number
        if (i == (tune.length() - 1) && character != '1' && character != '2' && character != '3' && character != '4' && character != '5' && character != '6' && character != '7' && character != '8' && character != '9')
        {
            is_true = false;
            return is_true;
        }
        else {
            is_true = true;
        }
    }
    return is_true;
}
  

int main()
{
    // Test valid Tune:
    assert(isValidTune("A2E3") == true);

    // Test Invalid Tune:
    assert(isValidTune("HE") == false);    

    // Test Empty Input
    assert(isValidTune("") == false); 
}
