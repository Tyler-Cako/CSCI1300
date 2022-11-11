#include <iostream>
#include <vector>

using namespace std;

/*  Algorithim
    1. For loop cin push_back vector 15 times
    2. Add all the vector elements and divide by 15. Set returned value = average
    3. Loop through all vectors again, if vector element < average, remove
*/

vector<float> minusAverage()
{
    vector<float> elements;
    vector<float> return_vec;
    float sum = 0;

    for (int i = 0; i < 15; i++)
    {
        float value;
        cin >> value;
        
        elements.push_back(value);
    }

    for (int i = 0; i < 15; i++)
    {
        sum += elements.at(i);
    }

    float mean = sum/15;

    cout << "testing3" << endl;
    int j = 0;
    for (int i = 0; i < 15; i++)
    {
        if(elements.at(i) < mean)
        {
            cout << "why" << endl;
            return_vec.push_back(elements.at(i));
            j++;
        }
    }

    return return_vec;
}
int main()
{
    vector<float> vect = minusAverage();

    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect.at(i) << " ";
    }
}