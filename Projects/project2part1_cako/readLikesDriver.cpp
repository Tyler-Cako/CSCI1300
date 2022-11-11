// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #5

#include<iostream>
#include<string>
#include<fstream>
#include<cassert>
#include "User.h"

/*Algoritihm
    1. Iterate through every input_string character
    2. Look for seperator character in input_string
    3. When a seperator is seen, make a substring between the starting elements and the seperator elements
    4. When index reaches the end of the string, put the rest of the string elements in the next array element
    5. return "count", the # of array elements made

    Cases to test for:
    1. If input_string is empty, return 0
    2. If there is only one element. I.e. there is no seperator, put the string in the first array.
*/
int split(string input_string, char seperator, string arr[], int arr_size)
{
    int count = 0;
    int j = -1;
    int state = 0;
    string test = "";
    int test_length = input_string.length() - 1;

    if (input_string == "")
    {
        return 0;
    }

    for (int i = 0; i < input_string.length(); i++)
    {
        if (count == arr_size)
        {
            return - 1;
        }
        if (input_string[i] == seperator)
        {
            j++;
            test = input_string.substr(state, i - state);
            arr[j] = input_string.substr(state, i - state);
            count++;
            state = i + 1;
        }
        if (i == input_string.length() - 1 && state == 0)
        {
            arr[0] = input_string;
            count++;
        }
        else if(i == input_string.length() - 1)
        {
            j++;
            test = input_string.substr(state, i);
            arr[j] = input_string.substr(state, i);
            count++;
            state = i + 1;
        }
    }

    if (count == 0)
    {
        arr[0] = input_string;
        return 1;
    }

    return count;
}

/* Algorithim
    1. Read every line of the text document
    2. For every line of the text document, check for proper size after split funcition = 1 + max_posts
    3. If line can be divided into a correctly formmated post, insert new post at arbitrary users[] index.
    4. Continue until reach the end of the txt document.
    5. Return the size of the users[] array of posts.
*/
using namespace std;

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{
    if (num_users_stored == users_arr_size)
    {
        return -2;
    }

    ifstream fin;
    string line = "";
    int index = 0;

    fin.open(file_name);

    if (fin.fail())
    {
        return -1;
    }

    while(!fin.eof())
    {
        string arr[max_posts + 1];
        string username = "";
        int arr_likes[max_posts];
        int target_value = max_posts + 1;

        getline(fin, line);

        int split_return = split(line, ',', arr, target_value);

        if (split_return <= target_value && num_users_stored < users_arr_size && arr[0] != "")
        {
            username = arr[0];

            int j = 0;
            for (int i = 1; i < split_return; i++)
            {
                arr_likes[j] = stoi(arr[i]);
                j++;
            }

            User temp_user = User(username, arr_likes, split_return - 1);

            users[num_users_stored] = temp_user;

            num_users_stored++;
        }
    }
    fin.close();
    return num_users_stored;
}

int main()
{
    // Test normal case
    User users[10]; 
    int num_users_stored = 0; 
    int users_arr_size = 10; 
    int max_posts = 3;
    assert(readLikes("users_test.txt", users, num_users_stored, users_arr_size, max_posts) == 2);

    // Check users array looks normal from this case:
    /*
    Expected values:
    mchelleryan
    cuboulder
    */

    for (int i = 0; i < 2; i++)
    {
        cout << users[i].getUsername() << endl;
    }

    // And the like values working as intended:
    /*
    -1
    1
    8
    10
    2
    -1 
    */
    cout << users[0].getLikesAt(0) << endl; 
    cout << users[0].getLikesAt(1) << endl; 
    cout << users[0].getLikesAt(2) << endl; 
    cout << users[1].getLikesAt(0) << endl; 
    cout << users[1].getLikesAt(1) << endl; 
    cout << users[1].getLikesAt(2) << endl; 

    // Read unknown file
    assert(readLikes("qwee3rwiejfwoiefjweoifjwefw.txt", users, num_users_stored, users_arr_size, max_posts) == -1);

    // Test num_users stored = users_arr_size
    User users1[2];
    users1[0] = User();
    users1[1] = User();
    num_users_stored = 2;
    users_arr_size = 2;
    assert(readLikes("users_test.txt", users, num_users_stored, users_arr_size, max_posts) == -2);

    // Test partially full user array overflow
    User users2[3];
    users1[0] = User();
    users1[1] = User();
    num_users_stored = 2;
    users_arr_size = 3;
    assert(readLikes("users_test.txt", users, num_users_stored, users_arr_size, max_posts) == 3);


}