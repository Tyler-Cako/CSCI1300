// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 2 - Problem #3

#include<iostream>
#include <iomanip> //Need to use setprecision() method and fixed, so iomanip needs to be imported

using namespace std;

int main() 
{
    double length = 0;
    double height = 0;
    double ounces = 0;

    cout<<"What is the side length of the base of the carton in inches?"<<endl;
    cin>>length;
    cout<<"What is the height of the carton in inches?"<<endl;
    cin>>height;

    //Length x length necessary because volume is base times height and the are of a square is its side length squared
    ounces = (length * length * height)* 0.55;

    //setprecision(1) and fixed used to have the program round to the first decimal
    cout<<"The carton has a volume of " << setprecision(1) << fixed << ounces << " ounces."<<endl; 

    return 0;
}