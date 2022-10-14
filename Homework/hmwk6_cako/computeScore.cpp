// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 6 - Problem #4
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <iomanip>

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
        cout << "Could not open file." << endl;
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


/* Algorithim
    1. Iterate through 2d array ratings[][3] with 2 for loops
    2. On a particular index, input formula:
        score = (6.3 * Food Quality Rating) + (4.3 * Cleanliness Rating) + (3.4 * (5 - Wait Time Rating))
        2. Cout the result w/ the restaurant name (has the same index)
*/
void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants)
{
    for (int i = 0; i < num_restaurants; i++)
    {
        float score = ((6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 * (5 - ratings[i][2])));
        cout << fixed << setprecision(1) << restaurants[i] << " overall score: " << score << endl;
    }
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

    if (num_lines == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        calcOverallScore(restaurants, ratings, num_lines);
    }

    // test normal case
    // Return: Wendys overall score: 60.9 Chick-fil-a overall score: 78.2 Snarfburger overall score: 87.0 Cosmo's Pizza overall score: 67.2
    cout << "Test case 1" << endl;
    calcOverallScore(restaurants, ratings, num_lines);

    // Test empty case
    // Nothing happens
    cout << "Test case 2" << endl;    
    int num_restaurants_1 = 3;
    string restaurants_1[num_restaurants];
    int ratings_1[num_restaurants][3];

    num_lines = readRestaurantData("./empty.txt", restaurants_1, ratings_1, num_restaurants_1);
    calcOverallScore(restaurants_1, ratings_1, num_lines);

    // Test txt file that doest exist
    // Could not open file
    cout << "Test case 3" << endl;
    int num_restaurants_2 = 3;
    string restaurants_2[num_restaurants];
    int ratings_2[num_restaurants][3];
    num_lines = 0;
    num_lines = readRestaurantData("./99jsd.txt", restaurants_2, ratings_2, num_restaurants_2);
    calcOverallScore(restaurants_2, ratings_2, num_lines);

    // Test txt file with blank lines
    /*
    Wendys overall score: 60.9
    Chick-fil-a overall score: 78.2
    Snarfburger overall score: 87.0
    */
    cout << "Test case 4" << endl;
    string restaurants_3[num_restaurants];
    int ratings_3[num_restaurants][3];
    num_lines = readRestaurantData("blank_lines_restaurant.txt", restaurants_3, ratings_3, num_restaurants);
    calcOverallScore(restaurants_3, ratings_3, num_lines);  
}