#include <iostream>

using namespace std;

int main()
{
    int count = 0;

    while (count != 9)
    {
        cout << "monster mash" << endl;
        if ((count % 2) == 0)
        {
            count ++;
        }
        else{
            count--;
        }
    }
}