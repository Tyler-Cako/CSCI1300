// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #1
#include <string>
using namespace std;

class Post
{
    private:
    string body_;
    string post_author_;
    int num_likes_;
    string date_;

    public:
    Post();
    Post(string, string, int, string);

    string getPostBody();
    void setPostBody(string);

    string getPostAuthor();
    void setPostAuthor(string);

    int getPostLikes();
    void setPostLikes(int);

    string getPostDate();
    void setPostDate(string);
};