// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #2
#include<iostream>
#include<cassert>
#include<fstream>
#include<string>
#include"Post.h"

using namespace std;

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

/* Algoriithm
    1. Loop theough every line of text in the .txt document
    2. For each line of the document, seperate the body, author, number of likes and date.
    3. Put these elements into a new post at the lowest index of the posts[] array.
    4. When the end of the text document is reached, or other conditions were met, return the number of posts stored in the posts[] array.
*/
int readPosts(string file_name, Post posts[], int num_posts_stored, int posts_arr_size)
{
    ifstream fin;
    string line = "";
    int index = 0;
    
    fin.open(file_name);

    if (num_posts_stored == posts_arr_size)
    {
        return -2;
    }

    if(fin.fail())
    {
        return -1;
    }

    while(!fin.eof())
    {
        string arr[4];
        int arr_size = 4;
        string body = "";
        string author = "";
        int likes = 0;
        string date = "";

        getline(fin, line);

        int split_return = split(line, ',', arr, arr_size);

        //cout << split_return << endl;

        if (split_return == 4 && num_posts_stored < posts_arr_size)
        {
            body = arr[0];
            author = arr[1];
            likes = stoi(arr[2]);
            date = arr[3];

            Post temp_post = Post(body, author, likes, date);

            posts[num_posts_stored] = temp_post;

            num_posts_stored++;
        }
    }
    return num_posts_stored;
}

int main()
{
    // Test standard case for readPost()
    Post posts[3]; 
    assert(readPosts("testposts.txt",posts,0,3) == 3);

    //Test not found text file
    assert(readPosts("3jqfejf0ajef.txt", posts, 0, 3) == -1);

    // Test full posts[] array
    Post posts1[2];
    Post my_post_1 = Post("new post","Xuefei", 10, "10/02/22");
    posts1[0] = my_post_1;
    Post my_post_2 = Post("Hello!","Morgan", 9, "10/04/22");
    posts1[1] = my_post_2;
    assert(readPosts("testposts.txt", posts1, 2, 2) == -2);

    // Test if array already had element
    Post posts2[2];
    posts1[0] = my_post_1;
    assert(readPosts("testposts.txt", posts2, 1, 2) == 2);

    // Test text with empty lines
    Post posts3[3];
    assert(readPosts("posts.txt", posts3, 0, 3) == 3);
}