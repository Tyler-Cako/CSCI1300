// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #8

#include<iostream>
#include<string>
#include<cassert>
#include<fstream>
#include"Buffchat.h"
#include"Post.h"
#include"User.h"

using namespace std;

int main()
{
    Buffchat buff = Buffchat();
    bool is_true = true;
    int choice = -1;
    string filename;

    while(is_true == true)
    {
        cout << "======Main Menu=====\n" << "1. Read posts\n" << "2. Print Posts By Year\n" << "3. Read Likes\n" << "4. Get Likes\n" << "5. Find users with matching tag\n" << "6. Add a new post\n" << "7. Print popular posts for a year\n" << "8. Find least active user\n" << "9. Find unique likes for a post author\n" << "10. Quit" << endl;
        
        cin >> choice;

        // Read Posts
        if (choice == 1)
        {
            cout << "Enter a post file name:" << endl;
            cin >> filename;

            int read_posts_return = buff.readPosts(filename);

            if (read_posts_return == -1)
            {
                cout << "File failed to open. No posts saved to the database." << endl;
            }
            else if (read_posts_return == -2)
            {
                cout << "Database is already full. No posts were added." << endl;
            }
            else if (read_posts_return == buff.getPostSize())
            {
                cout << "Database is full. Some posts may have not been added." << endl;
            }
            else if (read_posts_return < buff.getPostSize())
            {
                cout << "Total posts in the database: " <<  read_posts_return << endl;
            }
        }

        // Print posts by year
        else if(choice == 2)
        {
            string year;
            cout << "Enter the year(YY): " << endl;
            cin >> year;

            buff.printPostsByYear(year);
        }

        // Read Likes
        else if (choice == 3)
        {
            cout << "Enter a user file name:" << endl;
            cin >> filename;

            int read_likes_return = buff.readLikes(filename);

            if (read_likes_return == -1)
            {
                cout << "File failed to open. No users saved to the database." << endl;
            }

            if (read_likes_return == -2)
            {
                cout << "Database is already full. No users were added." << endl;
            }

            if (read_likes_return == buff.getUserSize())
            {
                cout << "Database is full. Some users may have not been added." << endl;
            }

            if (read_likes_return >= 0 && read_likes_return < buff.getUserSize())
            {
                cout << "Total users in the database: " << read_likes_return << endl;
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

            int get_likes_return = buff.getLikes(username, author);

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

            buff.findTagUser(tag);
        }

        // Add a new post
        else if (choice == 6)
        {
            string body;
            string author;
            string date;
            cout << "Enter a post body:" << endl;
            cin >> body;   
            cout << "Enter a post author:" << endl;
            cin >> author;
            cout << "Enter a date(mm/dd/yy):" << endl;
            cin >> date;

            bool add_post_return = buff.addPost(body, author, date);

            if (add_post_return == true)
            {
                cout << author << "'s post added successfully" << endl;
            }

            if (add_post_return == false)
            {
                cout << "Database is already full. " << author << "'s post was not added" << endl;
            }
        }
        
        // Print popular posts by year
        else if (choice == 7)
        {  
            string count;
            string year;
            cout << "Enter the number of posts:" << endl;
            cin >> count;
            cout << "Enter the year(YY):" << endl;
            cin >> year;

            buff.printPopularPosts(stoi(count), year);

        }

        // Find least active user
        else if (choice == 8)
        {
            User least_active_return = buff.findLeastActiveUser();

            if (least_active_return.getUsername() == "")
            {
                cout << "There are no users stored" << endl;
            }   
            else if (least_active_return.getUsername() != "")
            {
                cout << least_active_return.getUsername() << " is the least active user" << endl;
            }
        }

        // Count unique likes
        else if (choice == 9)
        {
            string author;

            cout << "Enter a post author:" << endl;
            cin >> author;

            int unique_likes_return = buff.countUniqueLikes(author);

            if (unique_likes_return > 0)
            {
                cout << "The posts posted by <post_author> have been liked by " << unique_likes_return << " unique users." << endl;
            }
            else if (unique_likes_return == 0)
            {
                cout << "The posts posted by " << author << " have received 0 likes so far." << endl;
            }
            else if (unique_likes_return == -1)
            {
                cout << "The posts posted by " << author << " have not been viewed by anyone." << endl;
            }
            else if (unique_likes_return == -2)
            {
                cout << "Database is empty.";
            }
        }
        
        // Exit
        else if (choice == 10)
        {
            cout << "Good bye!" << endl;
            is_true = false;
        }

        else 
        {
            cout << "Invalid input" << endl;
        }
    }
}
