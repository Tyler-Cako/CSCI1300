// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #4

#include <iostream>
#include <string>
#include <cassert>
#include "User.h"

using namespace std;

int main()
{
    // Test constructor
    User u1 = User();
    assert(u1.getUsername() == "");
    assert(u1.getNumPosts() == 0);
    assert(u1.getSize() == 50);
    for (int i = 0; i < 50; i++)
    {
        assert(u1.getLikesAt(i) == -1);
    }

    // Test paramaterized constructor case
    int testLikes[] = {-1,1,-1,8,8,3,-1,5,10,2,6,-1,6,7,8,4,1,7,1,8,-1,7,8,7,7,4,4,9,10,5,5,5,-1,8,-1,2,9,8,-1,-1,2,0,7,4,10,5,8,3,0,6};
    User u2 = User("bookworm43", testLikes, 50);

    assert(u2.getUsername() == "bookworm43");
    assert(u2.getNumPosts() == 50);
    assert(u2.getSize() == 50);
    for (int i = 0; i < 50; i++)
    {
        assert(u2.getLikesAt(i) == testLikes[i]);
    }

    // Setting wrong # of posts
    u1.setNumPosts(-1);
    assert(u1.getNumPosts() == 0);

    // Setting wrong # of post_id values
    u1.setLikesAt(-1, 9);
    assert(u1.getLikesAt(-1) == -2);

    // Invalid likes
    u1.setLikesAt(1, 11);
    assert(u1.getLikesAt(1) == -1);
}