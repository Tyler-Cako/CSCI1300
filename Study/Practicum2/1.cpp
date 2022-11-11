#include <iostream>

using namespace std;

int main()
{
    string animals[6] = {"hamster", "zebra", "goat", "lion", "penguin"};

    for (int i = 0; i < 6; i++)
    {
        if(animals[i+2] == "lion")
        {
            animals[i+1] = "giraffe";
        }
        else if (animals[i/2] == "hamster")
        {
            animals[i+4] = "fruitbat";
        }
        else
        {
            i++;
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        cout << animals[i] << " ";
    }
    cout << endl;
    return 0;
}