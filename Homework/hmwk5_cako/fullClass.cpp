// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #5
#include <iostream>
#include <cassert>
using namespace std;

/*
    1. Iterate through 2D array through 2 for loops. Index i loops through rows, index j loops through every element of a row
    2. Check if each 2d array element is a 0. If so, check if waitlist has more students.
    3. If students available, make element 1, subtract 1 from waitlist.
*/
int fullClass(bool classroom[][4], int rows, int waitlist)
{
    int seats_available = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (classroom[i][j] == 0)
            {
                if (waitlist - 1 != -1)
                {
                    classroom[i][j] = 1;
                    waitlist--;
                }
            }
        }
    }

    // Print 2D array by printing out a row, and then coutting a endl after the row has been looped through.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << classroom[i][j];
        }
        cout << endl;
    }
    
    cout << "Remaining Students: " << waitlist << endl;

    return waitlist;
}

int main()
{
    bool classroom[4][4] = {{0, 1, 1, 1},
                {0, 0, 0, 0},
                {1, 1, 0, 0},
                {0, 1, 0, 1}};
    int waitlist = 6;

    // Test normal case
    assert(fullClass(classroom, 4, waitlist) == 0);

    // Test empty set
    bool classroom_2[0][4] = {};

    assert(fullClass(classroom_2, 0, waitlist) == 6);

    // Test full class
    bool classroom_3[4][4] = {{1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 1, 1}};
    
    assert(fullClass(classroom_3, 4, waitlist) == 6);

    // Test empy class
    bool classroom_4[4][4] = {{0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}};
    assert(fullClass(classroom_4, 4, waitlist) == 0);

    // Test empty waitlist
    waitlist = 0;
    assert(fullClass(classroom, 4, waitlist) == 0);
}