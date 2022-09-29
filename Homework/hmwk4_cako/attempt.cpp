#include<iostream>
using namespace std;
int main(){
    int height;
    int start_location = 0;

    cout << "Enter the height:" << endl;
    cin >> height;
    if (height <= 0)
    {
        cout << "Invalid input." << endl;
        return 0;
    }

    for (int i = 1 ; i<=height; i++){
        for(int j=0 ; j< 2 * i -1 ; j++)
        {
            cout << (char((start_location%26 +97)));
            start_location++;
        }
    cout << endl;
    }

    return 0;
}