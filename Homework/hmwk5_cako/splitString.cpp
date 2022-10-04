// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #4
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int split(string input_string, char seperator, string arr[], int arr_size)
{
    
}

int main()
{
    string testcase = "ABCDEFG";
    char separator = ' ';
    int arr_size = 3;
    string arr[size];
    // num_splits is the value returned by split
    int num_splits = split(testcase, separator, arr, arr_size);
    cout << "Function returned value: " << num_splits << endl;
    cout << "arr[0]:"<< arr[0] << endl;
}