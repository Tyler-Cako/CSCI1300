// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #3
#include <iostream>
#include <cassert>
#include <iomanip>
#include <string>
using namespace std;

/* Algorithim
    1. Loop through all the elements of the array. Look for same string as string_to_find
    2. When found, move all array elements right of the element +1, insert string_to_insert at index+1
*/

int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count)
{
    if (num_elements + count > arr_size)
    {
        return num_elements;
    }
    for (int i = 0; i < num_elements; i++)
    {
        if (input_strings[i] == string_to_find && input_strings[i + 1] != string_to_insert)
        {
            string state = input_strings[i + 1];
            for (int j = (num_elements - 1); j > i; j--)
            {
                input_strings[j + 1] = input_strings[j];
                
            }
        
            num_elements++;
            input_strings[i + 1] = string_to_insert;
        }           
    }

    return num_elements;
}

int main()
{
     // Test normal case

    int size = 5;
    string inputStrings[5] = {"pikachu", "meowth", "snorlax"};
    int numElements = 3;
    int count = 1;
    string stringToFind = "pikachu";
    string stringToInsert = "clefairy";

    assert(secondPlace(inputStrings, stringToInsert, stringToFind, numElements, size, count) == 4);

    // Test 0 found elements
    size = 5;
    string inputStrings_2[5] = {"pikachu", "meowth", "snorlax"};
    numElements = 3;
    count = 0;
    stringToFind = "pichu";
    stringToInsert = "clefairy";

    assert(secondPlace(inputStrings_2, stringToInsert, stringToFind, numElements, size, count) == 3);

    // Test full array

    size = 5;
    string inputStrings_3[5] = {"pikachu", "meowth", "snorlax", "snorlax", "snorlax"};
    numElements = 5;
    count = 0;
    stringToFind = "pichu";
    stringToInsert = "clefairy";

    assert(secondPlace(inputStrings_3, stringToInsert, stringToFind, numElements, size, count) == 5);

    // Test empty array

    size = 0;
    string inputStrings_4[5] = {};
    numElements = 0;
    count = 0;
    stringToFind = "pichu";
    stringToInsert = "clefairy";

    assert(secondPlace(inputStrings_4, stringToInsert, stringToFind, numElements, size, count) == 0);
}
