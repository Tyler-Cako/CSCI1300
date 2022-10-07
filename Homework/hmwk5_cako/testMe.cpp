// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 5 - Problem #6
#include <iostream>
using namespace std;

int zeroesToFives(int arr[], int arr_size)
{
	int count = 0;
	//loops through input array
	for(int i = 0; i < arr_size; i++) 
	{ 
		if(arr[i] == 0) //if an element is zero, set it to five
		{ 
    		arr[i] = 5;
			count++;
		}
	}
    cout << count << endl;
	return count;
}

int main()
{
    // Test baisc function:
    int arr[5] = {0, 1, 0, 2, 3};
    
    assert(zeroesToFives(arr, 5) == 2);
    assert(arr[0] = 5);
    assert(arr[1] = 1);
    assert(arr[3] = 5);
    assert(arr[4] = 2);

    // Test no 0s present:

    int arr_2[5] = {1, 1, 4, 5, 3};

    assert(zeroesToFives(arr_2, 5) == 0);
    assert(arr_2[0] = 1);
    assert(arr_2[0] = 1);  
    assert(arr_2[0] = 4); 
    assert(arr_2[0] = 5);  
    assert(arr_2[0] = 3);

    // Test empty array

    int arr_3[5] = {};

    assert(zeroesToFives(arr_3, 5) == 0);

    // Test all zeros
    
    int arr_4[5] = {0, 0, 0, 0, 0};

    assert(zeroesToFives(arr_4, 5) == 5);
    assert(arr_2[0] = 5);
    assert(arr_2[0] = 5);  
    assert(arr_2[0] = 5); 
    assert(arr_2[0] = 5);  
    assert(arr_2[0] = 5);
}