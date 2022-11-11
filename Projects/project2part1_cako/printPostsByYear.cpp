// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #3
#include<iostream>
#include<string>
#include<cassert>
#include"Post.h"
#include"User.h"

using namespace std;

/* Algorithim
    1. Loop through every post in the posts[] array
    2. Check the date on every post.
    3. If the year matches in paramater year, add post to temp Post arr[]
    4. Output body of every post in the temp Post arr[]
*/
void printPostsByYear(Post posts[], string year, int num_posts)
{
    if (num_posts <= 0)
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        Post arr[num_posts];
        int count = 0;

        for (int i = 0; i < num_posts; i++)
        {
            string post_year = "";
            post_year = posts[i].getPostDate().substr(6, 2);

            if (post_year == year)
            {
                arr[count] = posts[i];
                count++;
            }
        }

        if (arr[0].getPostBody() != "")
        {
            cout << "Here is a list of posts for year " << year << endl;
            for (int i = 0; i < count; i++)
            {
                cout << arr[i].getPostBody() << endl;
            }
        }
        else{
            cout << "No posts stored for year " << year << endl;
        }
    }
}

int main()
{
    // Test empty case
    // Expected output: "No posts are stored"
    Post list_Posts[] = {};
    int number_Posts = 0;
    string year = "20";
    printPostsByYear(list_Posts, year, number_Posts);

    /*
    Test standard case
    Expected output: 
    Here is a list of posts for year 22
    new post1
    new post2
    */
    Post p_1 = Post("new post1","Lisa1", 10, "10/02/22");
    Post p_2 = Post("new post2","Lisa2", 11, "10/02/22");
    Post p_3 = Post("new post3","Lisa3", 8, "10/02/19");
            
    Post list_of_posts[] = {p_1, p_2, p_3};
    int number_of_posts = 3;
    year = "22";
    printPostsByYear(list_of_posts, year, number_of_posts);

    /*
    Test no post w/ the needed year
    Expected output:
    "No posts stored for year 20"
    */
    year = "20";
    printPostsByYear(list_of_posts, year, number_of_posts);
}