#include <iostream>

using namespace std;

double score(int arr[], int size)
{
    int sum = 0;
    int divisor = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];

        if (i == 0)
        {
            divisor += arr[i];
        }
        if (i == size - 1)
        {
            divisor += arr[i];
        }
    }

    if (divisor == 0)
    {
        return -1;
    }
    else
    {
        return (sum/divisor);
    }
}

int main()
{
    int nums[5] = {1,4,3,11,8};
    int size = 5;
    cout << score (nums, size);
}