// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #4

#include<iostream>
#include<string>
#include"User.h"

using namespace std;

User::User()
{
    username_ = "";
    for (int i = 0; i < size_; i++)
    {
        likes_[i] = -1;
    }
    num_posts_ = 0;
}

User::User(string username, int likes[], int num_posts)
{
    if (num_posts <= size_)
    {
        for (int i = 0; i < size_; i++)
        {
            if (num_posts - i > 0)
            {
                likes_[i] = likes[i];
            }
            else
            {
                likes_[i] = -1;
            }
        }
    }
    username_ = username;
    num_posts_ = num_posts;
}

string User::getUsername()
{
    return username_;
}

void User::setUsername(string username)
{
    username_ = username;
}

int User::getLikesAt(int post_id)
{
    if (post_id < size_ && post_id >= 0)
    {
        return likes_[post_id];
    }
    else{
        return -2;
    }
}

bool User::setLikesAt(int post_id, int num_likes)
{
    if (post_id < num_posts_ && post_id >= 0 && num_likes >= -1 && num_likes <= 10)
    {
        likes_[post_id] = num_likes;
        return true;
    }
    else
    {
        return false;
    }
}

int User::getNumPosts()
{
    return num_posts_;
}

void User::setNumPosts(int posts)
{
    if (posts >= 0 && posts < size_)
    {
        num_posts_ = posts;
    }
}

int User::getSize()
{
    return size_;
}
