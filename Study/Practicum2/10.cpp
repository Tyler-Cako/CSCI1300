#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    int j = 1;
    do
    {
        cout << i << ";" << j << endl;
        i++;
        if (i % 3 == 0){
            j--;
        }
    }
    while (j >= 1);
}