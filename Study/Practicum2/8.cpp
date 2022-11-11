#include <iostream>

using  namespace std;

double area(double r)
{
    double a;
    a = 3.14 * r * r;
    return r*r;
}

int main()
{
    cout << area(3) << endl;
}