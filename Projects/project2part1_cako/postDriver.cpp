// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #1

#include<iostream>
#include"Post.h"

using namespace std;

int main()
{
    // Test default initialized Post
    Post post_1 = Post();

    assert(post_1.getPostBody() == "");
    assert(post_1.getPostAuthor() == "");
    assert(post_1.getPostDate() == "");
    assert(post_1.getPostLikes() == 0);   

    // Test paramaterized post

    Post post_2 = Post("Test123123 1231 123 123 ", "Tyler", 16, "October 22nd");

    assert(post_2.getPostBody() == "Test123123 1231 123 123 ");
    assert(post_2.getPostAuthor() == "Tyler");
    assert(post_2.getPostLikes() == 16);
    assert(post_2.getPostDate() == "October 22nd");

    // Test negative # of likes

    Post post_3 = Post("Test123123 1231 123 123 ", "Tyler", -3, "October 22nd");

    assert(post_3.getPostBody() == "Test123123 1231 123 123 ");
    assert(post_3.getPostAuthor() == "Tyler");
    assert(post_3.getPostLikes() == -3);
    assert(post_3.getPostDate() == "October 22nd");

    // Testing getters and setters
    post_3.setPostLikes(10);
    post_2.setPostBody("testing123");
    post_1.setPostAuthor("Tyler Cako");
    post_1.setPostDate("October 21st");

    assert(post_2.getPostBody() == "testing123");
    assert(post_1.getPostAuthor() == "Tyler Cako");
    assert(post_3.getPostLikes() == 10);
    assert(post_1.getPostDate() == "October 21st");
}