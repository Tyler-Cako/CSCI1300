#include <iostream>
#include <string>
#include <cassert>
#include "Buffchat.h"

using namespace std;

int main()
{
    // Testing buffchat initialization & getters
    Buffchat buffchat;

    assert(buffchat.getPostSize() == 50);
    assert(buffchat.getUserSize() == 50);
    assert(buffchat.getNumPosts() == 0);
    assert(buffchat.getNumUsers() == 0);

    
    // readPosts() testing


    // Test standard posts.txt document
    assert(buffchat.readPosts("posts.txt") == 50);
    // Test full posts_ array
    assert(buffchat.readPosts("posts.txt") == -2);  
    // Test not foud text document
    Buffchat b1;
    assert(b1.readPosts("asifhwighegihasf.txt") == -1);
    // Test fill post array w/ 2 function calls
    Buffchat b2;
    b2.readPosts("posts_20.txt");
    assert(b2.readPosts("posts.txt") == 50);
    // Test empty posts file
    Buffchat b3;
    assert(b3.readPosts("empty_post.txt") == 0);


    // pinrtPostsByYear() testing


    // Standard
    /*
        Expected output:
        Here is a list of posts for year 20:
        Sko buffs!!
        Come get involved in robotics @ cu!
    */
    Buffchat b4;
    b4.readPosts("posts1.txt");
    b4.printPostsByYear("20");
    // Year not found
    /*
        Expected output:
        No posts stored for year 17
    */
    b4.printPostsByYear("17");
    // Empty posts file
    /*
        Expected output:
        No posts stored
    */
    b3.printPostsByYear("20");
    // File DNE
    /*
        Expected output:
        No posts stored
    */
    b1.printPostsByYear("20");


    // Testing readLikes()

    // Standard
    assert(buffchat.readLikes("users.txt") == 50);
    // Test full users_ array
    assert(buffchat.readLikes("users.txt") == -2);  
    // Test not foud text document
    assert(b1.readLikes("asifhwighegihasf.txt") == -1);
    // Test fill users_ array w/ 2 function calls
    b2.readLikes("users_10.txt");
    assert(b2.readLikes("users.txt") == 50);
    // Test empty users_ file
    assert(b3.readPosts("empty_users.txt") == 0);


    // Testing getLikes()

    // Standard case
    assert(buffchat.getLikes("kate128", "roboticscu") == 4);
    // User DNE
    assert(buffchat.getLikes("sidhgfisdhg", "roboticscu") == -3);
    // Post author DNE
    assert(buffchat.getLikes("kate128", "asifhofgha") == -3);  
    // Both DNE
    assert(buffchat.getLikes("sidhgfisdhg", "sfihagojaso") == -3);
    // 0 posts
    Buffchat b5;
    b5.readPosts("empty_post.txt");
    b5.readLikes("users.txt");
    assert(b5.getLikes("kate128", "roboticscu") == -2);
    // 0 users
    Buffchat b6;
    b6.readPosts("posts.txt");
    b6.readLikes("empty_post.txt");
    assert(b6.getLikes("kate128", "roboticscu") == -2);
    // Neither
    assert(b3.getLikes("kate128", "roboticscu") == -2);

    // Testing findTagUser()

    // Standard case
    /*
    Expected output:
    Here are all the usernames that contain cu
    cuboulderalumni
    culegislative
    cubuffnews
    roboticscu
    cubouldermusic
    cubuffs
    cuweatherclub678
    cuhikingclub
    cuisthebest
    cucornhole
    MarcusCU
    cuboulder
    cuconstrution
    cualerts
    */
    buffchat.findTagUser("cu");
    // No tag match
    /*
        Expected:
        No matching user found
    */
   buffchat.findTagUser("3957213095uefgi");
   // Empty posts and users arrays
   /*
        Expected:
        "No users are stored in the database"
   */
   b3.findTagUser("CU");

   // Testing addPost()

   // Standard
   Buffchat b7;
   b7.readPosts("posts_20.txt");
   b7.readLikes("users_10.txt");
   assert(b7.getNumPosts() == 20);
   assert(b7.addPost("Test", "Tyler", "01/01/20") == true);
   assert(b7.getNumPosts() == 21);
   // Full posts
   assert(buffchat.addPost("Test", "Tyler", "01/01/20") == false);

   // Testing printPopularPosts()

   // Standard
   /*
        Expected:

        Top 5 posts for year 20
        241 likes: Imagine not having views like this on the way to class!
        258 likes: We love our girl Ralphie! The student section brought the energy for her first run of the season! We can't wait for more!
        258 likes: Overheard at CU: What are your goals for this year?
        239 likes: Come get involved in robotics @ cu!
        229 likes: Overheard at CU: Tell us about your first day of school ‘fit
   */
  buffchat.printPopularPosts(5, "20");
  // Test empty posts
  /*
        Expected:
        No posts are stored
  */

    b3.printPopularPosts(5, "20"); 

    // Test posts in year found:
    /*
        Expected output:
        No posts stored for year 50
    */
    buffchat.printPopularPosts(5, "50");

    // Test fewers posts in year than asked for
    /*
        Expected output:
        There are fewer than 30 posts for year 20. Top 11 posts for year 20
        146 likes: Sko buffs!!
        241 likes: Imagine not having views like this on the way to class!
        191 likes: We’ve arrived at another Monday on the most beautiful campus
        258 likes: We love our girl Ralphie! The student section brought the energy for her first run of the season! We can't wait for more!
        258 likes: Overheard at CU: What are your goals for this year?
        239 likes: Come get involved in robotics @ cu!
        229 likes: Overheard at CU: Tell us about your first day of school ‘fit
        191 likes: Freshmen meet the Buffs! Welcome to Boulder Class of 2026
        202 likes: Summer fun may be here but these recent sky temps are making us miss spring and fall
        226 likes: It’s being debated around BuffsChat whether or not we have the best stadium views…
        209 likes: Chip may not have a lightsaber but we think he’s out of this world!
    */
    buffchat.printPopularPosts(30, "20");

    // Testing leastActiveUser()

    // Standard
    assert(buffchat.findLeastActiveUser().getUsername() == "michelleryan");

    // No users/posts stored
    assert(b3.findLeastActiveUser().getUsername() == "");

    // Multiple users with = # of likes
    Buffchat b8;
    b8.readPosts("posts_test.txt");
    b8.readLikes("users_test.txt");
    assert(b8.findLeastActiveUser().getUsername() == "pacifiedIcecream7");

    // Testing count unique likes()

    // Standard
    //assert(buffchat.countUniqueLikes("roboticscu") == 85);

    // Test empty posts and users array
    assert(b3.countUniqueLikes("roboticscu") == -2);

    // Test post has zero likes
    Buffchat b9;

    b9.readPosts("posts_test2.txt");
    b9.readLikes("users_test2.txt");
    
    assert(b9.countUniqueLikes("bookworm43") == 0);

    // Test post has zero views
    Buffchat b10;

    b10.readPosts("posts_test3.txt");
    b10.readLikes("users_test3.txt");
    assert(b10.countUniqueLikes("bookworm43") == -1);
}