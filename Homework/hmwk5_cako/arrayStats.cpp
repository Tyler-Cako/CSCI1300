// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #2
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

/* Algorithim
Takes the input array and the size, iterates through ever size and checks if any element is less than the first array. If so, least_value becomes that value and the loop continues
*/
double min(double arr[], int arr_size)
{
    double least_value = arr[0];
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] < least_value)
        {
            least_value = arr[i];
        }
    }
    
    return least_value;
}

/* Algorithim
Iterate through every arr element w/ arr_size and add them together to sum.
*/
double sum(double arr[], int arr_size)
{
    double sum = 0;
    
    for (int i = 0; i < arr_size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

/* Algorithim
Iterate through every arr element w/ arr_size and add them together to sum. Then divide the sum by the arr_size to get the mean.
*/
double average(double arr[], int arr_size)
{
    double sum = 0;
    
    for (int i = 0; i < arr_size; i++)
    {
        sum += arr[i];
    }

    double mean = sum/arr_size;

    return mean;
}

int main()
{
    double arr[] = {1.24, 5.68, 3.456};
    int arr_size = 3;

    cout << "Min: " << fixed << setprecision(3)<< min(arr, arr_size) << endl;
    cout << "Sum: " << fixed << setprecision(3) << sum(arr, arr_size) << endl;
    cout << "Avg: " << fixed << setprecision(3) << average(arr, arr_size) << endl;

    // Test standard input:

    assert(doublesEqual(min(arr, arr_size), 1.240));
    assert(doublesEqual(sum(arr, arr_size), 10.376));
    assert(doublesEqual(average(arr, arr_size), 3.459));

    // Test single element array
    double arr_2[] = {0};
    arr_size = 1;

    assert(doublesEqual(min(arr_2, arr_size), 0));
    assert(doublesEqual(sum(arr_2, arr_size), 0));
    assert(doublesEqual(average(arr_2, arr_size), 0));

    // Test decimals
    double arr_3[] = {32.2821, 0.2987};
    arr_size = 2;

    assert(doublesEqual(min(arr_3, arr_size), 0.2987));
    assert(doublesEqual(sum(arr_3, arr_size), 32.581));
    assert(doublesEqual(average(arr_3, arr_size), 16.290));
}