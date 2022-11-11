#include <iostream>
using namespace std;

int main()
{
    int x = 4;
    int y = 7;

    cout << ((x++ - y--) * (x + y++)) << endl;
}