// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #4
#include <iostream>
using namespace std;

/* 
similarity = (number of matching notes / total number of notes) 
            + number of matching notes with matching pitches 
            - number of different notes with different pitches
*/

double tuneSimilarity(string tune1, string tune2)
{
    double similarity = 0;
    double matching_notes = 0;
    double matching_pitches = 0;
    double different_notes = 0;
    double notes = 0;

    if (tune1.length() != tune2.length())
    {
        return 0;
    }

    return similarity;
}

int main()
{
    int x = 10;
    for (int i = 0; i < x; i+= 2)
    {
        cout << "test" << endl;
        cout << i << endl;
    }
}