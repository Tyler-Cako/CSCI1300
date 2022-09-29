// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 3 - Problem #6
#include <iostream>
using namespace std;

int main()
{
    // Category and instrument int initialization, no need for price int because every intrument has 1 price
    int category = 0;
    int instrument = 0;

    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> category;

    switch(category) // Use default cases for error management as if category doesn't fit specific cases, throw error.
    {
        case 1:
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> instrument;

            switch(instrument)
            {
                case 1:
                    cout << "Your instrument will be $350." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $400." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 1;
            }
        case 2:
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> instrument;

            switch(instrument)
            {
                case 1:
                    cout << "Your instrument will be $325." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $425." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 1;
            }
        case 3:
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> instrument;

            switch(instrument)
            {
                case 1:
                    cout << "Your instrument will be $275." << endl;
                    return 0;
                case 2:
                    cout << "Your instrument will be $200." << endl;
                    return 0;
                default:
                    cout << "Please enter a valid input." << endl;
                    return 1;
            }
        default:
            cout << "Please enter a valid input." << endl;
            return 1;
    }
}