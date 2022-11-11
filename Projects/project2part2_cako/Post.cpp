// CSCI 1300 Fall 2022
// Author: Tyler Cako
// Recitation: 308 – Baljot Kaur
// Project 2pt1 - Problem #1

#include <iostream>
#include <string>
#include "Post.h"

using namespace std;

Post::Post(){
    body_ = "";
    post_author_ = "";
    date_ = "";
    num_likes_ = 0;
}

Post::Post(string body, string post_author, int num_likes, string date) {
    body_ = body;
    post_author_ = post_author;
    num_likes_ = num_likes;
    date_ = date;
}

string Post::getPostBody(){
    return body_;
}

void Post::setPostBody(string body){
    body_ = body;
}

string Post::getPostAuthor(){
    return post_author_;
}

void Post::setPostAuthor(string post_author){
    post_author_ = post_author;
}

int Post::getPostLikes(){
    return num_likes_;
}

void Post::setPostLikes(int num_likes){
    if(num_likes > 0)
    {
        num_likes_ = num_likes;
    }
}

string Post::getPostDate(){
    return date_;
}

void Post::setPostDate(string date){
    date_ = date;
}