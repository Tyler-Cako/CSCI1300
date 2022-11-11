// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #7

#include<iostream>
#include<string>
#include"Post.h"
#include"User.h"

using namespace std;

/* Algorithim
    1. Iterate through ever User users[] element. Also find length of tag
    2. Compare username_tag to every possible substring of users[i].getUsername()
    3. If a substring has been found, add that index to array of indexes that work, add arr_size++ as well.
    4. Print every user with the found tag
*/
void findTagUser(string username_tag, User users[], int num_users_stored)
{
    if (num_users_stored == 0)
    {
        cout << "No users are stored in the database" << endl;
    }
    else
    {
        int arr[num_users_stored];
        int arr_size = 0;
        int tag_length = username_tag.length();

        for (int i = 0; i < num_users_stored; i++)
        {
            int j = 0;
            int exit = -1;
            while (users[i].getUsername().substr(j, tag_length).length() == tag_length && exit != 0)
            {
                string temp_str = users[i].getUsername().substr(j, tag_length);

                if (temp_str == username_tag)
                {
                    arr[arr_size] = i;
                    arr_size++;
                    exit = 0;
                }
                else
                {
                    j++;
                }
            }
        }

        if (arr_size == 0)
        {
            cout << "No matching user found" << endl;
        }
        else
        {
            cout << "Here are all the usernames that contain " << username_tag << endl;

            for (int i = 0; i < arr_size; i++)
            {
                cout << users[arr[i]].getUsername() << endl;
            }        
        }
    }

}

int main()
{
    // creating 5 users
    User user_array[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array[0] = User("foliwn22", likes1, 3);
    user_array[1] = User("joh23k", likes2, 3);
    user_array[2] = User("harry02", likes2, 3);
    user_array[3] = User("luwkml1", likes2, 3);
    user_array[4] = User("fwollow3", likes1, 3);
    findTagUser("ol", user_array, 5);
}