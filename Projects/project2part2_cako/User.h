#ifndef USER
#define USER
// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #4

#include<iostream>
#include<string>

using namespace std;

class User
{
    private:
    static const int size_ = 50;
    string username_;
    int likes_[size_];
    int num_posts_;

    public:
    User();
    User(string, int[], int);

    string getUsername();
    void setUsername(string);

    int getLikesAt(int);
    bool setLikesAt(int, int);
    
    int getNumPosts();
    void setNumPosts(int);

    int getSize();
};

#endif