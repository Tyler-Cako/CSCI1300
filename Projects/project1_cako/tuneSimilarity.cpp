// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #4
#include <iostream>
#include <cassert>
using namespace std;

/* 
similarity = (number of matching notes / total number of notes) 
            + number of matching notes with matching pitches 
            - number of different notes with different pitches
*/


bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

double tuneSimilarity(string tune1, string tune2)
{
    double similarity = 0;
    double matching_notes = 0;
    double matching_pitches = 0;
    double different_pitches = 0;
    double notes = 0;

    if (tune1.length() != tune2.length())
    {
        return 0;
    }

    if (tune1 == "" || tune2 == "")
    {
        return 0;
    }

    // Total number of notes = (tune1+tune2)/4, or just one of the note lengths divided by 2,
    notes = tune1.length()/2;

    /* Algorithm
        Finds the number of tunes that are matching, have matching notes, or matching pitches:

        1. Loop through every full note on tune1, increment by 2 (each 2 letter "note")
        2. Check if similarity is just same note, or same  pitch, increment if condition is met
        3. Count the number of notes with the index.
    */
    for (int i = 0; i < tune1.length(); i += 2)
    {
        if (tune1[i] == tune2[i])
        {

            matching_notes++;
            if (tune1[i+1] == tune2[i+1])
            {
                matching_pitches++;
            }
        }
        else if (tune1[i+1] != tune2[i+1])
        {
            different_pitches++;
        }
    }

    similarity = (matching_notes / notes) + matching_pitches - different_pitches;

    return similarity;
}

int main()
{
    // Test valid Tunes:
    assert(doublesEqual(tuneSimilarity("A2B3E2D1", "A2D1F2D1"), 1.5));

    // Test tunes of different length
    assert(doublesEqual(tuneSimilarity("A2B3", "A2D1F2D1"), 0));

    
    // Test empty tunes
    assert(doublesEqual(tuneSimilarity("", ""), 0));
}