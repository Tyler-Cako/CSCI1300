#include<iostream>
using namespace std;

int main() {
    char character = '0';

    cout << "Please eneter a letter" << endl;
    cin >> character;

    switch(character){
        case 'S':
            cout << "Squidward" << endl;
            break;
        default:
            cout << "You don't get a name" << endl;
    }
}