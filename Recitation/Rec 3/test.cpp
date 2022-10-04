#include<iostream>

using namespace std;

int main() {
    double tc = 0;
    double th = 0;
    double t = 0;

    cout << "Enter the cold reservoir temperature" << endl;
    cin >> tc;

    cout << "Enter the hot reservoir temperature" << endl;
    cin >> th;

    tc = ((tc - 32) * 5/9) + 273.15;

    th = ((th - 32) * 5/9) + 273.15;

    t = 1 - (tc/th);

    cout << "Carnot Effeciency: " << t << endl;
}