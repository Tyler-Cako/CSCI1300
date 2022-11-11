#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/* Aglorithim
    1. Loop through the vector, starting with start_index and ending with i = end_index
    2. Add the value at that index to the sum integer
    3. Return sum integer

    1. If start_index > end_index, return -1
    2. If start_index and/or end_index exceed bounds of venctor, return -2

*/
int sumElements(vector<int> vect, int start_index, int end_index)
{
    int sum = 0;

    if (start_index > end_index)
    {
        return -1;
    }

    if (start_index >= vect.size() || start_index < 0 || end_index >= vect.size() || end_index < 0)
    {
        return -2;
    }

    for (int i = start_index; i <= end_index; i++)
    {
        sum += vect.at(i);
    }

    return sum;
}

int main()
{
    // Standard case
    vector<int> vect1{10, 20, 30, 40, 50};
    assert(sumElements(vect1, 1, 3) == 90);

    // end_index < start_index
    assert(sumElements(vect1, 2, 1) == -1);

    // start_index negative
    assert(sumElements(vect1, -1, 3) == -2);

    // Start index greater than vector size
    assert(sumElements(vect1, 10, 3) == -2);

    // end index negative
    assert(sumElements(vect1, 1, -3) == -2);

    // End index > vector size
    assert(sumElements(vect1, -1, 10) == -2);
}