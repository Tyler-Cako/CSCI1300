// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 1 - Problem #7

/*
--- Menu ---
1. Calculate similarity between two tunes.
2. Calculate best similarity between two tunes of potentially different lengths.
3. Print three input tunes in order from most to least similar to the target tune.
4. Exit.
Please enter your choice (1 - 4):
6Invalid input.
*/
#include <iostream>
#include <string>
#include <iomanip> 
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
    int selection;
    bool continue_running = true;
    bool is_valid = false;

    while (continue_running)
    {
        
        cout << "--- Menu ---" << endl << "1. Calculate similarity between two tunes." << endl << "2. Calculate best similarity between two tunes of potentially different lengths." << endl << "3. Print three input tunes in order from most to least similar to the target tune." << endl << "4. Exit." << endl << "Please enter your choice (1 - 4):" << endl;

        cin >> selection;


        // Selection just a series of if statements depending on the selection

        if (selection == 1)
        {
            string input_tune1;
            string input_tune2;
            cout << "Please enter the first tune:" << endl;
            cin >> input_tune1;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune1) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune1;
                    if ((isValidTune(input_tune1)) == true)
                    {
                        is_valid = true;
                    }
                }
            }
            cout << fixed << setprecision(2) << "Please enter the second tune:" << endl;
            cin >> input_tune2;

            if (isValidTune(input_tune2) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune2;
                    if ((isValidTune(input_tune2)) == true)
                    {
                        is_valid = true;
                    }
                }
            }

            cout << "The similarity score is " << tuneSimilarity(input_tune1, input_tune2) << endl;
        }
        if (selection == 2)
        {
            string input_tune1;
            string input_tune2;
            cout << "Please enter the input tune:" << endl;
            cin >> input_tune1;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune1) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune1;
                    if ((isValidTune(input_tune1)) == true)
                    {
                        is_valid = true;
                    }
                }
            }
            cout << "Please enter the target tune:" << endl;
            cin >> input_tune2;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune2) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune2;
                    if ((isValidTune(input_tune2)) == true)
                    {
                        is_valid = true;
                    }
                }
            }

            cout << "The best similarity score is: " << fixed << setprecision(2) << bestSimilarity(input_tune1, input_tune2) << endl;
        }
        if (selection == 3)
        {
            string input_tune1;
            string input_tune2;
            string input_tune3;
            string input_target;
            cout << "Please enter the first tune:" << endl;
            cin >> input_tune1;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune1) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune1;
                    if ((isValidTune(input_tune1)) == true)
                    {
                        is_valid = true;
                    }
                }
            }
            cout << "Please enter the second tune:" << endl;
            cin >> input_tune2;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune2) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune2;
                    if ((isValidTune(input_tune2)) == true)
                    {
                        is_valid = true;
                    }
                }
            }
            cout << "Please enter the third tune:" << endl;
            cin >> input_tune3;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_tune3) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_tune3;
                    if ((isValidTune(input_tune3)) == true)
                    {
                        is_valid = true;
                    }
                }
            }
            cout << "Please enter the target tune:" << endl;
            cin >> input_target;
            // Check if tune is valid, loop until it is.
            if (isValidTune(input_target) == false)
            {
                is_valid = false;

                while (is_valid == false)
                {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> input_target;
                    if ((isValidTune(input_target)) == true)
                    {
                        is_valid = true;
                    }
                }
            }

            printTuneRankings(input_tune1, input_tune2, input_tune3, input_target);
        }
        if (selection == 4)
        {
            continue_running = false;
            cout << "Goodbye!" << endl;
        }
        if (selection != 1 && selection != 2 && selection != 3 && selection != 4)
        {
            cout << "Invalid Input." << endl;
        }
    }

    
    return 0;
}