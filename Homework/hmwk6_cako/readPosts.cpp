// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 6 - Problem #2
#include <iostream>
#include <fstream>
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


/* Algorithim
    1. Loop through every line of the text file
    2. Split line with split function
    3. If array counted to 3, num_splits++
    4. Otherwise, do nothing
    5. Return num_splits
*/
int readPosts(string filename)
{
    ifstream fin;
    string line;
    int num_splits = 0;

    fin.open(filename);

    // Check if document can be opened
    if (fin.fail())
    {
        return -1;
    }
    
    while (!fin.eof())
    {
        string arr[3];
        int arr_size = 3;
        int num_elements = 0;
        int num_seperator = 0;

        getline(fin, line);

        int split_return = split(line, ',', arr, arr_size);

        // If split returns 1 and or -1, failed test cases in split(), exit function with error value
        if (split_return == 1 || split_return == -1)
        {
            return split_return;
        }

        // Check if array has 3 elements
        if (split_return == 3)
        {
            num_splits++;
        }

    }
   return num_splits;
}

int main()
{
    string filename = "posts.txt";
    int num_posts = readPosts(filename);
    if (num_posts == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "Number of posts: " << num_posts << "." << endl;
    }

    // Test standard case
    assert(readPosts(filename) == 7);

    // Test "broken" post. 1 post with missing component
    assert(readPosts("./posts_test.txt") == 0);

    // Test empty txt document
    assert(readPosts("./empty.txt") == 0);

    // Test txt document that doesn't exist
    assert(readPosts("./asfiahfiawhfgs") == -1);
}