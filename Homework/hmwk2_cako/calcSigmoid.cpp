// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 2 - Problem #6

#include <iostream>
#include <cmath> //cmath neede for exp() function

using namespace std;

int main() 
{
    double x = 0;
    double sigmoid = 0;

    cout<<"Enter a value for x:"<<endl;
    cin>>x;

    sigmoid = (1)/(1+exp(-x)); //parantheses are used to help order of operations work correctly for 1 over 1 plus e^-x

    cout<<"The sigmoid for x="<< x << " is "<< sigmoid<<endl;

    return 0;
}