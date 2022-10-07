// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #3
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

/* Algorithim
    1. Check if array is full through basic if statement num_elements = arr_size. Also check if new string would overload the array through another statement, index+1 > arr_size.
    2. Check if index will "override" the array. If so, push all array elements AFTER index one over
    3. Insert the new pokemon at index+1
    4. if num_elements == index+1, no pushing of elements is needed, just add to index+1
*/

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert)
{
    if (num_elements == arr_size || (index + 1) > arr_size)
    {
        return 0;
    }

    if (num_elements - 1 > index)
    {
        for (int i = (num_elements - 1); i > index; i--)
        {
            input_strings[i + 1] = input_strings[i];
        }

        input_strings[index + 1] = string_to_insert;
    }
    else
    {
        input_strings[index + 1] = string_to_insert;
    }

    return 1;
}

int main()
{

    // Test normal case

    int size = 5;
    string inputStrings[5] = {"pikachu", "meowth", "snorlax"};
    int numElements = 3;
    int index = 2;
    string stringToInsert = "clefairy";

    assert(insertAfter(inputStrings, numElements, size, index, stringToInsert) == 1);

    // Test full array
    size = 5;
    string inputStrings_2[5] = {"pikachu", "meowth", "snorlax", "charizard", "caterpie"};
    numElements = 5;
    index = 2;
    stringToInsert = "clefairy";

    assert(insertAfter(inputStrings_2, numElements, size, index, stringToInsert) == 0);

    // Test bad index value
    size = 5;
    numElements = 3;
    index = 6;
    stringToInsert = "clefairy";

    assert(insertAfter(inputStrings, numElements, size, index, stringToInsert) == 0);

    // Test empy array
    size = 0;
    string inputStrings_3[0] = {};
    numElements = 0;
    index = 0;
    stringToInsert = "clefairy";

    assert(insertAfter(inputStrings_3, numElements, size, index, stringToInsert) == 0);
}