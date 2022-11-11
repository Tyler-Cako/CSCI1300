#include <iostream>

using namespace std;

int main()
{
    int ctr = 0;
    int myarray[3];
    for (int i = 0; i < 3; i++)
    {
        myarray[i] = ctr;
        ctr = ctr + i;
    }
    cout << myarray[2];

}

