// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #3
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int numValidNotes(string input)
{
    // Initialize variables
    int valid_spn = 0;

    /* Aglorithm
   We need to test for instances of valid SPN within a string, therefore, we need to loop through the entire string (for loop),
   and then test for a correctly formatted letter, and then a valid number (nested if statement)
   */

    for (int i = 0; i < input.length(); i++)
    {
        char letter = input[i];
        char number = input[i + 1];

        // Check if note letter  is valid
        if (letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E' || letter == 'F' || letter == 'G')
        {
            if (number == '0' || number == '1' || number == '2' || number == '3' || number == '4' || number == '5' || number == '6' || number == '7' || number == '8' || number == '9')
            {
                valid_spn++;
            }
        }
    }

    return valid_spn;
}
  

int main()
{
    // String with valid notes
    assert(numValidNotes("ADB3M7G4F") == 2);

    // String with invalid notes only
    assert(numValidNotes("ABCEDEFEGEGA") == 0);    

    // Test Empty Input
    assert(numValidNotes("") == 0); 
}
