#include <iostream>
using namespace std;

int main() {
    int x = 8;
    int y = 0;

    cout << ((x++ * y--) - (y++ / x++) + (y++ - x--));
}