// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 6 - Problem #3
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
            arr[j] = input_string.substr(state, 1);
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
    1. Loop through each line of the text file
    2. For each line, use the splt function to seperate the line into restaurant array, which has restaurant name and 3 ratins
    3. If the line is a valid line (created array has a length of 4) then:
        1. Add the name to the resaurants[] array
        2. Add the ratings to the ratings[][] array.
    4. Return the number of lines.
*/

int readRestaurantData(string filename, string restaurants[], int ratings[][3], int arr_size)
{
    ifstream fin;
    string line;
    int index = 0;
    int num_lines = 0;

    fin.open(filename);

    if (fin.fail())
    {
        return -1;
    }
    else
    {
        while (!fin.eof() && num_lines < arr_size)
        {
            string arr[10];
            getline(fin, line);

            int split_return = split(line, '~', arr, 10);

            if (split_return == 4)
            {
                restaurants[index] = arr[0];
                num_lines++;

                for (int j = 1; j <= 3; j++)
                {
                    ratings[index][j - 1] = stoi(arr[j]);
                }
                index++;
            }
        }
    }

    fin.close();
    return num_lines;
}

int main()
{
    string filename = "restaurant_samples.txt";

    // max number of restaurants to read
    int num_restaurants = 3;

    // make arrays to store data
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];

    // call read data function
    int num_lines = readRestaurantData(filename, restaurants, ratings, num_restaurants);
    //cout << num_lines << "test" << endl;

    cout << restaurants[0] <<" test " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i << "]" << restaurants[i] << ", ";
    }
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ratings[i][j] << " ";
        }
        cout << endl;
    }

    // Test normal case (with incorrect ratings format in some places.)
    assert(readRestaurantData(filename, restaurants, ratings, num_restaurants) == 3);

    // Test empty txt file
    assert(readRestaurantData("./empty.txt", restaurants, ratings, num_restaurants) == 0);

    // Test a txt file that DNE
    assert(readRestaurantData("./asfajwifjqwifjs.txt", restaurants, ratings, num_restaurants) == -1);

    // Test incorectly formatted txt file
    assert(readRestaurantData("./single_line.txt", restaurants, ratings, num_restaurants) == 0);
}