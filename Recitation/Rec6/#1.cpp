/*
Write a function called reverseArray() which takes two parameters: an int array and the length of that array. The function should not return anything as arrays are passed by reference and the values will get changed in place.

// this function is to reverse all the elements of an array
void reverseArray (int myArray[], int myArrayLength);
*/
#include <iostream>
#include <cassert>
using namespace std;

void reverseArray(int array[], int length)
{
    for (int i = 0; i < length/2; i++)
    {
        int value_1 = array[i];
        int value_2 = array[length - 1 - i];

        array[i] = value_2;
        array[length - 1 - i] = value_1;
    }
}

int main()
{
    int arr[4] = {1, 2, 3};

    reverseArray(arr, 3);

    assert(arr[0] == 3);
    assert(arr[1] == 2);
    assert(arr[2] == 1);

}