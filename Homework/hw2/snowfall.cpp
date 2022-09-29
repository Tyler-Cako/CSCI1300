// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 2 - Problem #4

#include<iostream>

using namespace std;

int main() 
{
    double future_days = 0;
    double breck = 25;
    double vail = 28;
    double copper = 40;

    cout<<"How many days in the future would you like a prediction for?"<<endl;
    cin>>future_days;

    // To find the snowfall, we have to count both the snow added and snow removed from each mountain every day
    
    breck = breck + (10 * future_days) - (5 * future_days);
    vail = vail + (14 * future_days) - (2 * future_days);
    copper = copper + (5 * future_days) - (3 * future_days);

    cout<<"Breckenridge will have " << breck << " inches, Vail will have " << vail << " inches, and Copper Mountain will have " << copper <<" inches."<<endl;

    return 0;
}


