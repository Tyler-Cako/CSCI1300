/*
Write a function called swap() which takes three parameters: an array, startIndex, and endIndex. This function will swap the values present at the startIndex and endIndex in the given array

// this function is to swap two elements in an array
void swap(int myArray[], int startIndex, int endIndex);

*/

#include <iostream>
using namespace std;

void swap(int myArray[], int startIndex, int endIndex)
{
    int value_1 = myArray[startIndex];
    int value_2 = myArray[endIndex];

    myArray[startIndex] = value_2;
    myArray[endIndex]= value_1;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    swap(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
}