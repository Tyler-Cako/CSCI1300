// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Homework 2 - Problem #5

#include<iostream>

using namespace std;

int main() 
{
    int bolts = 0;
    int gold_coins = 0;
    int gems = 0;

    cout<<"Enter the number of Bolts:"<<endl;
    cin>>bolts;

    // Since 23 bolts in 1 gold coin and 13 gold coins in 1 gem, 299 bolts are in a gem. If there aren't eough bolts to convert to a gem, there is no need to calculate the number of zeros as gems already equal 0
    if (bolts/299 >= 1)  
    {
        gems = (bolts/299);
        bolts = bolts - gems*299;
    }

    // Same idea as with gems, if there aren't enough bolts to conver to a gold coin, there is no need to do the calculation as the correct value is already set (gold_coins=0)
    if (bolts/23 >= 1)
    {
        gold_coins = (bolts/23);
        bolts = bolts - (gold_coins*23);
    }

    cout<<gems<<" Gems(s) "<< gold_coins << " GoldCoin(s) "<< bolts << " Bolt(s)" <<endl;

    return 0;
}