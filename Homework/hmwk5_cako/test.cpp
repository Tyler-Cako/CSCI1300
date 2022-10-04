// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #1
#include <iostream>
#include <cassert>
using namespace std;


int main()
{
    // Initialize arrays with the correct type
    int integer_array[10];
    string cities_array[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};
    int sequence_array[100];
    char letters_array[50];

    // Initialize indexes
    int i = 0;
    int j = 0;

    // Iterate 10 times starting at 5, set each integer of index[i] = i
    for (i = 5; i < 15; i++)
    {
        integer_array[j] = i;
        cout << integer_array[j] << endl;
        j++;
    }

    // Simple for loop iterating through each city in cities_array
    for (i = 0; i < 5; i++)
    {
        cout << cities_array[i] << endl;
    }

    /* Iterate 100 times, check if divisible by two. If it is divisible by 2, there will be no remainder, henco i modulo 6 will be 0
    // Need two indexes. One to count how many elements of the array have been filled, one to keep counting to find the next number divisible by 6.
    */
    i = 0;
    j = 1;

    while (i < 100)
    {
        if (j%6 != 0)
        {
            j++;
        }
        if (j%6 == 0)
        {
            sequence_array[i] = j;
            cout << sequence_array[i] << endl;
            i++;
            j++;
        }
    }

    // Abcs are between asci decimal values of 65 and 122, so increase i by that value. Index automatically is displayed as a character. Remove values 91 to 96.
    i = 65;
    j = 0;
    while (i < 91)
    {
        letters_array[j] = i;
        cout << letters_array[j] << endl;
        j++;
        letters_array[j] = (i + 32);
        cout << letters_array[j] << endl;
        j++;
        i++;
    }
    return 0;
}