// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #5
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

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

double bestSimilarity(string inputTune, string targetTune)
{
    // Test if inputTune is greater than or equal to targetTune
    if (inputTune.length() < targetTune.length())
    {
        return 0;
    }

    double best_similarity = 0;

    int i = 0;

    /* Alogorithm 
        1. Loop through every inputTune note
        2. Create a substring of inputTune using the index of the loop and the length of targetTune
        3. Increment the starting point of the substring with the index
        4. Compare each substring with targetTune via tuneSimilarity(), if substring > targetTune, set that as the best_similarity value.
    */
    while (i < inputTune.length())
    {
        string subsequence = "";

        subsequence = inputTune.substr(i, targetTune.length());

        if (subsequence.length() != targetTune.length())
        {
            i = inputTune.length();
        }
        else if (tuneSimilarity(subsequence, targetTune) > best_similarity || best_similarity == 0)
        {
            best_similarity = tuneSimilarity(subsequence, targetTune);
        }

        i += 2;
    }

    return best_similarity;
}

int main()
{
    // Test valid Tunes:
    assert(doublesEqual(bestSimilarity("E4D5B7G2E2", "D6G5G2"), 0.666667));

    // Test input tune < target tune
    assert(doublesEqual(bestSimilarity("B6A2", "G9B0E1D6"), 0));

    // Test empy tunes:
    assert(doublesEqual(bestSimilarity("", ""), 0));    
}