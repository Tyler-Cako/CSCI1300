// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 6 - Problem #2
#include <iostream>
#include <string>
#include <fstream>
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
1. Iterate through every line of the text document. Increase line_count by 1
2. Set the first mountain as the tallest
3. If the next mountain is taller, set that to the tallest mountain, first mountain as smallest
4. Otherwise, make second ountain the shortest mountain
5. For the rest of the loop. Check if mountain is tallter than the tallest mountain. If it is, set that as new tallest mountain
6. Else if checked mountain is shorter than shortest mountain, set that mountain equal to shortest mountain
*/

void printMountainStats(string filename)
{
    // Initialize Variables
    ifstream fin;
    string line;

    int line_count = 0;
    int tallest_height = 0;
    int shortest_height = 0;
    string tallest_mtn;
    string shortest_mtn;
    bool result = false;


    fin.open(filename);

    if (fin.fail())
    {
        cout << "Could not open file." << endl;
        result = false;
    }
    else
    {
        while (!fin.eof())
        {
            string arr[10];
            int arr_size = 10;
            int state;

            getline(fin, line);

            split(line, '|', arr, arr_size);

            if (arr[0] != "")
            {
                if (stoi(arr[1]) > tallest_height || tallest_height == 0)
                {
                    tallest_mtn = arr[0];
                    tallest_height = stoi(arr[1]);
                }
                else if (stoi(arr[1]) <  shortest_height || shortest_height == 0)
                {
                    shortest_mtn = arr[0];
                    shortest_height = stoi(arr[1]);
                }

                line_count++;
            }

        }

        cout << "Number of lines read: " << line_count << "." << endl;
        cout << "Tallest Mountain: " << tallest_mtn << " at " << tallest_height << " feet." << endl;
        cout << "Shortest Mountain: " << shortest_mtn << " at " << shortest_height << " feet." << endl;
        fin.close();
    }
}

int main()
{
    // Test standard case:
    // Expected outcome: #lines read: 3, Highest pikes peak at 14114, shortest at vermilion peak at 13894
    printMountainStats("./mountain_data.txt");

    // Test empty txt document
    // Expected outcome : 0 lines read, 0 tall 0 short
    printMountainStats("./empty.txt");

    // Test non-existent text document
    // Output: cannot open file
    printMountainStats("test.txt");

    // Test text document with space in the document
    // Should work normally as first test
    printMountainStats("./mountain_data_with_space.txt");
}