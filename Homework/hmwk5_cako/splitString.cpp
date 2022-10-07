// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #4
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

/*Algoritihm
    1. Iterate through every input_string character
    2. Look for seperator character in input_string
    3. When a seperator is seen, make a substring between the starting elements and the seperator elements
    4. When index reaches the end of the string, put the rest of the string elements in the next array element
    5. return "count", the # of array elements made

    Cases to test for:
    1. If input_string is empty, return 0
    2. If there is only one element. I.e. there is no seperator, put the string in the first array.
*/

int split(string input_string, char seperator, string arr[], int arr_size)
{
    int count = 0;
    int j = -1;
    int state = 0;
    string test = "";
    int test_length = input_string.length() - 1;

    if (input_string == "")
    {
        return 0;
    }

    for (int i = 0; i < input_string.length(); i++)
    {
        if (count == arr_size)
        {
            return - 1;
        }
        if (input_string[i] == seperator)
        {
            j++;
            test = input_string.substr(state, i - state);
            arr[j] = input_string.substr(state, i - state);
            count++;
            state = i + 1;
        }
        if (i == input_string.length() - 1 && state == 0)
        {
            arr[0] = input_string;
            count++;
        }
        else if(i == input_string.length() - 1)
        {
            j++;
            test = input_string.substr(state, i);
            arr[j] = input_string.substr(state, i);
            count++;
            state = i + 1;
        }
    }

    if (count == 0)
    {
        arr[0] = input_string;
        return 1;
    }

    return count;
}

int main()
{
    // test case 3
    string testcase = "ABCDEFG";
    char separator = ' ';
    int size = 3;
    string arr[3];
    // numSplits is the value returned by split
    int numSplits = split(testcase, separator, arr, size);
    cout << "Function returned value: " << numSplits << endl;
    cout << "arr[0]:"<< arr[0] << endl;

    // test normal case fuck this shit give me my fucking time back

    assert(split(testcase, separator, arr, size) == 1);

    // Empty string
    testcase = "";
    assert(split(testcase, separator, arr, size) == 0);

    // longer string than array
    testcase = "a b c d e f g h i j k l m n o p";
    size = 3;
    assert(split(testcase, separator, arr, size) == -1);
}