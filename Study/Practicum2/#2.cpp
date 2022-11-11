#include <iostream>

using namespace std;

void modify(int arr[], int size, int random)
{
    for (int i = 0; i < size/2; i++)
    {
        int temp = arr[size-i-1];
        arr[size-i-1] = 2 * arr[size/2-i-1];
        arr[size/2-i-1] = temp/random;
    }
}

int main()
{
    int arr[5] = {2, 9, 5, 13, 6};
    int random_num = 3;
    modify(arr, 5, random_num);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}