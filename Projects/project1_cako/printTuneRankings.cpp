// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #6
#include <iostream>
#include <string>
using namespace std;

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

void printTuneRankings(string tune1, string tune2, string tune3, string targetTune)
{
    string high_score = "";
    string medium_score = "";
    string low_score = "";

    double input1 = bestSimilarity(tune1, targetTune);
    double input2 = bestSimilarity(tune2, targetTune);
    double input3 = bestSimilarity(tune3, targetTune);

    //cout << input1 << input2 << input3 << endl;

    /* Algorithim
    1. Check input1 against 2 and 3, if greater than both, greatest value.
        If input 2 is greater than input 3, input 2 medium value, 3 is smallest value
        Else if input3 is greater than input2, input 3 is the medium value value and input2 is the smallest value
        Else they are equal, so input2 is medium and input3 is low
    2. Else if input 1 is greater than 2, medium value, the bigger value is the greatest value, other input is always smaller
        if input 2=input1, input2 smallest value, input3 largest value
        if input 3=input1, input3 is smallest value, input2 largest value
        if input 3 > input 2, input 3 is greatest value, input 2 is smallest value
        else input 2 is the greatest value, input 3 is the smallest
    3. Else if input 1 smaller than input 2 and 3, input1 is the smallest value
        If input 2 is greater than input 3, input 2 greatest value, 3 is medium value
        Else input 3 is the greatest value, input 2 is medium value
    4. Else if input3 > input1 and input1 >= input 2
        input 3 is largest, input 1 is medium, input 2 is lowest
    4. Else input1 = input2 = input3 so input1 high, input2 medium, input3 low
    */

   if (input1 > input2 && input1 > input3)
   {
    high_score = "Tune 1";

    if (input2 > input3)
    {
        medium_score = "Tune 2";
        low_score = "Tune 3";
    }
    else if (input3 > input2)
    {
        medium_score = "Tune 3";
        low_score = "Tune 2";
    }
    else
    {
        medium_score = "Tune 2";
        low_score = "Tune 3";
    }
   }
   else if (input1 > input2 || input1 > input3)
   {
    if (input1 == input2)
    {
        high_score = "Tune 1";
        medium_score = "Tune 2";
        low_score = "Tune 3";
    }
    else if (input1 == input3)
    {
        high_score = "Tune 1";
        medium_score = "Tune 3";
        low_score = "Tune 2";
    }
    else if(input3 > input2)
    {
        medium_score = "Tune 1";
        high_score = "Tune 3";
        low_score = "Tune 2";
    }
    else if (input2 > input3)
    {
        medium_score = "Tune 1";
        high_score = "Tune 2";
        low_score = "Tune 3";
    }
   }
   else if (input1 < input2 && input1 < input3)
   {
    low_score = "Tune 1";

    if (input2 > input3 || input2 == input3)
    {
        high_score = "Tune 2";
        medium_score = "Tune 3";
    }
    if (input3 > input2)
    {
        high_score = "Tune 3";
        medium_score = "Tune 2";   
    }
   }
   else if (input3 > input1 && input1 >= input2)
   {
        high_score = "Tune 3";
        medium_score = "Tune 1";
        low_score = "Tune 2";
   }
   else if (input3 == input1 && input2 != input1)
   {
        high_score = "Tune 2";
        medium_score = "Tune 1";
        low_score = "Tune 3";
   }
    else
    {
        high_score = "Tune 1";
        medium_score = "Tune 2";
        low_score = "Tune 3";
    }
   cout << "1) " << high_score<< ", 2) " << medium_score << ", 3) " << low_score << endl;
}

int main()
{
    // Test working tunes
    // Expected 1) Tune 3, 2) Tune 2, 3) Tune 1
    printTuneRankings("F7D8G1D3", "A6B7D9G1E0", "D6B1D9G4", "D6B4D9");

    // Test Tune 1 and Tune 2 Tied
    // Expected 1) Tune 1, 2) Tune 2, 3) Tune 3

    printTuneRankings("C4D6G1A8", "C4D6G1", "G9B7A0", "C4D8A1");

    // Test Tune 2 and Tune 3 Tied
    // ) Tune 1, 2) Tune 2, 3) Tune 3
    printTuneRankings("B6G8D9F1E1", "F5C2D7C0C2E2", "E9G1E7C2E2C2", "B6G8D9F1");

    // Test Tune 1 and Tune 3 Tied
    // 1) Tune 2, 2) Tune 1, 3) Tune 3
    printTuneRankings("F0E1", "A2D4F4G4", "G0E1", "C2D4");
}