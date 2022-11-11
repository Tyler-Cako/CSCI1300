// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #8

#include<iostream>
#include<string>
#include<cassert>
#include<fstream>
#include"Post.h"
#include"User.h"

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
            i = num_posts_stored;
        }
    }

    // Find user
    for (int i = 0; i < num_users_stored; i++)
    {
        if (users[i].getUsername() == username)
        {
            user_pos = i;
            i = num_posts_stored;
        }
    }

    if (post_pos == -1 || user_pos == -1)
    {
        return -3;
    }

    
    num_likes = users[user_pos].getLikesAt(post_pos);

    return num_likes;
}

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
    bool is_true = true;
    int choice = -1;
    Post posts[50];
    User users[50];
    int posts_size = 50;
    int users_size = 50;
    int filled_user_size = 0;
    int filled_post_size = 0;
    string filename;

    while(is_true == true)
    {
        cout << "======Main Menu======\n" << "1. Read Posts\n" << "2. Print Posts By Year\n" << "3. Read Likes\n" << "4. Get Likes\n" << "5. Find users with matching tag\n" << "6. Quit" << endl;
        
        cin >> choice;

        // Read Posts
        if (choice == 1)
        {
            cout << "Enter a post file name:" << endl;
            cin >> filename;

            int read_posts_return = readPosts(filename, posts, filled_post_size, posts_size);

            if (read_posts_return == -1)
            {
                cout << "File failed to open. No posts saved to the database." << endl;
            }
            else if (read_posts_return == -2)
            {
                cout << "Database is already full. No posts were added." << endl;

                filled_post_size = posts_size;
            }
            else if (read_posts_return == posts_size)
            {
                cout << "Database is full. Some posts may have not been added." << endl;

                filled_post_size = read_posts_return;
            }
            else if (read_posts_return < posts_size)
            {
                cout << "Total posts in the database: " <<  read_posts_return << endl;

                filled_post_size = read_posts_return;
            }
        }

        // Print posts by year
        else if(choice == 2)
        {
            string year;
            cout << "Enter the year(YY): " << endl;
            cin >> year;

            printPostsByYear(posts, year, filled_post_size);
        }

        // Read Likes
        else if (choice == 3)
        {
            cout << "Enter a user file name:" << endl;
            cin >> filename;

            int read_likes_return = readLikes(filename, users, filled_user_size, users_size, posts_size);

            if (read_likes_return == -1)
            {
                cout << "File failed to open. No users saved to the database." << endl;
            }

            if (read_likes_return == -2)
            {
                cout << "Database is already full. No users were added." << endl;

                filled_user_size = users_size;
            }

            if (read_likes_return == users_size)
            {
                cout << "Database is full. Some users may have not been added." << endl;

                filled_user_size = read_likes_return;
            }

            if (read_likes_return >= 0 && read_likes_return < users_size)
            {
                cout << "Total users in the database: " << read_likes_return << endl;

                filled_user_size = read_likes_return;
            }
        }

        // Get Likes
        else if (choice == 4)
        {
            string author;
            string username;

            cout << "Enter a post author:" << endl;
            cin >> author;
            cout << "Enter a user name:" << endl;
            cin >> username;

            int get_likes_return = getLikes(author, posts, filled_post_size, username, users, filled_user_size);

            if (get_likes_return == 0)
            {
                cout << username << " has not liked the post posted by " << author << endl;
            }

            if (get_likes_return == -1)
            {
                cout << username << " has not viewed the post posted by " << author << endl;
            }

            if (get_likes_return == -2)
            {
                cout << "Database is empty." << endl;
            }

            if (get_likes_return == -3)
            {
                cout << username << " or " << author << " does not exist." << endl;;
            }

            if (get_likes_return > 0)
            {
                cout << username << " liked the post posted by " << author << " " << get_likes_return << " times" << endl;
            }
        }

        // Find users with matching tag
        else if (choice == 5)
        {
            string tag;

            cout << "Enter a tag:" << endl;
            cin >> tag;

            findTagUser(tag, users, filled_user_size);
        }

        // Quit
        else if (choice == 6)
        {
            cout << "Good bye!" << endl;
            is_true = false;
        }

        else 
        {
            cout << "Invalid input." << endl;
        }
    }
}