#include <iostream>
using namespace std;

double restock(double stock, double amount)
{
    if (amount < 0 || stock < 0)
    {
        return 0;
    }

    amount += stock;

    return amount;
}

double fertilizer(double stock, double amount)
{
    if (amount < 0 || stock < 0)
    {
        return 0;
    }

    amount -= stock;

    return amount;
}

int main()
{
    cout << "test";
}