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



    if (num_elements > (index + 1))
    {
        cout << "numelements > index + 1" << endl;
        for (int i = 0; i < (num_elements-index); i++)
        {
            {
            cout << "test1" << endl;
            input_strings[index] = input_strings[num_elements];
            cout << "test2" << endl;
            cout << "test3" << endl;
            //cout << input_strings[i] << endl;
            //cout << input_strings[i + 1] << endl;
            //cout << input_strings[i + 2] << endl;
            //cout << input_strings[i + 3] << endl;
            }
        input_strings[index] = string_to_insert;
        }
    }

    if (num_elements == (index+1))
    {
        //cout << "numelements = index + 1" << endl;
        input_strings[index + 1] = string_to_insert;
    }

    return 1;
}

int main()
{
    int size = 5;
    string input_strings[5] = {"caterpie", "eevee"};
    // string input_strings[size] = {"caterpie", "eevee"};
    int num_elements = 2;
    int index = 0;
    string string_to_insert = "bulbasaur";
    // result contains the value returned by insertAfter
    bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
    // print result
    //cout << "Function returned value: "<< result << endl;
    // print array contents
    for(int i = 0; i < size; i++)
    {
        cout << input_strings[i] << endl;
    }
}