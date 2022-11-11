// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #6

#include<iostream>
#include<string>
#include<cassert>
#include"Post.h"
#include"User.h"

using namespace std;

/* Algorithim
    1. Find location of the author's post, set that location to post_pos.
    2. Find the location of the user in the User users[] array, set that index to user_pos
    3. Select said user, and set num_likes equal to user[post_pos]
    4. return value
*/
int getLikes(string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    if (num_posts_stored <= 0 || num_users_stored <= 0)
    {
        return -2;
    }

    int post_pos = -1;
    int user_pos = -1;
    int num_likes = 0;

    // Find author
    for (int i = 0; i < num_posts_stored; i++)
    {
        if (posts[i].getPostAuthor() == post_author)
        {
            post_pos = i;
        }
    }

    // Find user
    for (int i = 0; i < num_users_stored; i++)
    {
        if (users[i].getUsername() == username)
        {
            user_pos = i;
        }
    }

    if (post_pos == -1 || user_pos == -1)
    {
        return -3;
    }

    
    num_likes = users[user_pos].getLikesAt(post_pos);

    return num_likes;
}

int main()
{
    //Test standard case
    Post posts[3]; 
    Post my_post_1 = Post("Hello!","Xuefei", 10, "10/02/22");
    posts[0] = my_post_1;
    Post my_post_2 = Post("new post","Morgan", 9, "10/04/22");
    posts[1] = my_post_2;
    Post my_post_3 = Post("Hey!","Jot", 10, "10/05/22");
    posts[2] = my_post_3;

    User users[2];
    int likes1[3] = {1, 3, 2};
    User u1 = User("bookworm43", likes1, 3);
    users[0] = u1; // insert first object at index 0
    users[1].setUsername("roboticscu");
    users[1].setLikesAt(0,-1); 
    users[1].setLikesAt(1,2); 
    users[1].setLikesAt(2,4);


    // Test standard case
    assert(getLikes("Xuefei", posts, 3, "bookworm43", users, 2) == 1);

    // Test no username found
    assert(getLikes("Xuefei", posts, 3, "1212fefef", users, 2) == -3);

    // Test no author found
    assert(getLikes("aifdfiajsfias", posts, 3, "bookworm43", users, 2) == -3);

    // Test empty post num and user num
    assert(getLikes("Xuefei", posts, 0, "bookworm43", users, 0) == -2);

    // Test default post array
    Post posts1[2];

    posts1[0] = Post();
    posts1[1] = Post();
    assert(getLikes("Xuefei", posts1, 2, "bookworm43", users, 2) == -3);

    // Test default user array
    User users1[2];

    users1[0] = User();
    users1[1] = User();

    assert(getLikes("Xuefei", posts, 3, "bookworm43", users1, 2) == -3);
    
}