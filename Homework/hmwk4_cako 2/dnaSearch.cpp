// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 4 - Problem #4

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    // Variable Initialization 
    string sequence = ""; 
    string search = "";
    int occurrences = 0;

    cout << "Enter the DNA Sequence:" << endl;
    cin >> sequence;

    // Check for valid input
    for (int i = 0; i < sequence.length(); i++)
    {
        char letter = sequence[i];
        if (letter != 'A' && letter != 'T' && letter != 'C' && letter != 'G')
        {
            cout << "This is not a valid DNA sequence." << endl;
            return 1;
        }
    }


    cout << "Enter the DNA fragment to be searched:" << endl;
    cin >> search;

    // Check for valid input
    for (int i = 0; i < search.length(); i++)
    {
        char letter = search[i];
        if (letter != 'A' && letter != 'T' && letter != 'C' && letter != 'G')
        {
            cout << "This is not a valid DNA sequence" << endl;
            return 1;
        }
    }

    // Alogirithm to find matching DNA pairs
    for (int i = 0; i < sequence.length(); i++)
    {
        if (sequence[i] == search[0])
        {
            int j = 0;
            while (j <= search.length() && j != -1)
            {
                if (sequence[i + j] == search[j])
                {
                    j++;
                }
                else
                {
                    j = -1;
                }

                if ( j == search.length())
                {
                    occurrences = occurrences + 1;
                }
            }
        }
    }

    cout << "Number of occurrences: " << occurrences << endl;
}