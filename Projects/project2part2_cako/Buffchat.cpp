#include <string>
#include <fstream>
#include "Post.h"
#include "User.h"
#include "Buffchat.h"

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

Buffchat::Buffchat()
{
    num_posts_ = 0;
    num_users_ = 0;
}

int Buffchat::getPostSize()
{
    return posts_size_;
}

int Buffchat::getUserSize()
{
    return users_size_;
}

int Buffchat::getNumPosts()
{
    return num_posts_;
}

int Buffchat::getNumUsers()
{
    return num_users_;
}

/* Algoriithm
    1. Loop theough every line of text in the .txt document
    2. For each line of the document, seperate the body, author, number of likes and date.
    3. Put these elements into a new post at the lowest index of the posts[] array.
    4. When the end of the text document is reached, or other conditions were met, return the number of posts stored in the posts[] array.
*/
int Buffchat::readPosts(string file_name)
{
    ifstream fin;
    string line = "";
    int index = 0;
    
    fin.open(file_name);

    if (num_posts_ == posts_size_)
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

        if (split_return == 4 && num_posts_ < posts_size_)
        {
            body = arr[0];
            author = arr[1];
            likes = stoi(arr[2]);
            date = arr[3];

            Post temp_post = Post(body, author, likes, date);

            posts_[num_posts_] = temp_post;

            num_posts_++;
        }
    }

    fin.close();
    return num_posts_;
}


/* Algorithim
    1. Loop through every post in the posts[] array
    2. Check the date on every post.
    3. If the year matches in paramater year, add post to temp Post arr[]
    4. Output body of every post in the temp Post arr[]
*/
void Buffchat::printPostsByYear(string year)
{
    if (num_posts_ <= 0)
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        Post arr[num_posts_];
        int count = 0;

        for (int i = 0; i < num_posts_; i++)
        {
            string post_year = posts_[i].getPostDate().substr(6, 2);

            if (post_year == year)
            {
                arr[count] = posts_[i];
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

/* Algorithim
    1. Read every line of the text document
    2. For every line of the text document, check for proper size after split funcition = 1 + max_posts
    3. If line can be divided into a correctly formmated post, insert new post at arbitrary users[] index.
    4. Continue until reach the end of the txt document.
    5. Return the size of the users[] array of posts.
*/
int Buffchat::readLikes(string file_name)
{
    if (num_users_ == users_size_)
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
        string arr[num_posts_ + 1];
        string username = "";
        int arr_likes[num_posts_];
        int target_value = num_posts_ + 1;

        getline(fin, line);

        int split_return = split(line, ',', arr, target_value);

        //cout << split_return << "testingg" << endl;

        if (split_return <= target_value && num_users_ < users_size_ && arr[0] != "")
        {
            username = arr[0];

            int j = 0;
            for (int i = 1; i < split_return; i++)
            {
                arr_likes[j] = stoi(arr[i]);
                j++;
            }

            User temp_user = User(username, arr_likes, split_return - 1);

            users_[num_users_] = temp_user;

            num_users_++;
        }
    }
    fin.close();
    return num_users_;
}

int Buffchat::getLikes(string username, string post_author)
{
    if (num_posts_ <= 0 || num_users_ <= 0)
    {
        return -2;
    }

    int post_pos = -1;
    int user_pos = -1;
    int num_likes = 0;

    // Find author
    for (int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostAuthor() == post_author)
        {
            post_pos = i;
            i = num_posts_;
        }
    }

    // Find user
    for (int i = 0; i < num_users_; i++)
    {
        if (users_[i].getUsername() == username)
        {
            user_pos = i;
            i = num_users_;
        }
    }

    if (post_pos == -1 || user_pos == -1)
    {
        return -3;
    }

    
    num_likes = users_[user_pos].getLikesAt(post_pos);

    return num_likes;
}

/* Algorithim
    1. Iterate through ever User users[] element. Also find length of tag
    2. Compare username_tag to every possible substring of users[i].getUsername()
    3. If a substring has been found, add that index to array of indexes that work, add arr_size++ as well.
    4. Print every user with the found tag
*/
void Buffchat::findTagUser(string username_tag)
{
    if (num_users_ == 0)
    {
        cout << "No users are stored in the database" << endl;
    }
    else
    {
        int arr[num_users_];
        int arr_size = 0;
        int tag_length = username_tag.length();

        for (int i = 0; i < num_users_; i++)
        {
            int j = 0;
            int exit = -1;
            while (users_[i].getUsername().substr(j, tag_length).length() == tag_length && exit != 0)
            {
                string temp_str = users_[i].getUsername().substr(j, tag_length);

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
                cout << users_[arr[i]].getUsername() << endl;
            }        
        }
    }

}

/* Algorithim
    1. Check if posts array is full
    2. If full, return false, otherwise:
    3. Make a new post with the parameters
    4. Insert that post to the next index in posts array
    5. Increase size of likes array by 1, set that new value for -1 for every use
    6. Num_posts++
    7. Return true
*/
bool Buffchat::addPost(string post_body, string post_author, string date)
{
    if (num_posts_ == posts_size_)
    {
        return false;
    }
    else
    {
        Post temp_post = Post(post_body, post_author, 0, date);

        posts_[num_posts_] = temp_post;

        for (int i = 0; i < num_users_; i++)
        {
            users_[i].setLikesAt(num_posts_, -1);
        }

        num_posts_++;

        return true;
    }
}

/* Algorithim
    1.Fill a post array with every element in a specified year. Size of array is num_posts_
    2. For next element of the year not put in the array, if one exists, compare # of likes with each element of the post array
    3. If # of likes is greater than one of the elements, store the previous element into a state and place new element at that index
    4. Now, compare state with every other element of the array, continue this process untill state is smaller than every element.
    5. Continue until last element is found.
    6. Then, do conditionals to test various possible return values.
*/
void Buffchat::printPopularPosts(int count, string year)
{
    if (num_posts_ == 0)
    {
        cout << "No posts are stored" << endl;
    }
    else
    {
        int num_elements = 0;
        int year_count;
        Post year_arr[num_posts_];
        for (int i = 0; i < num_posts_; i++)
        {
            if (posts_[i].getPostDate().substr(6,2) == year)
            {
                year_arr[num_elements] = posts_[i];
                num_elements++;
            }
        }

        if (num_elements == 0)
        {
            cout << "No posts stored for year " << year << endl;
        }
        else
        {
            if (num_elements < count)
            {
                year_count = num_elements;
            }
            else
            {
                year_count = count;
            }

            Post popular_arr[num_elements];
            for (int i = 0; i < year_count; i++)
            {
                popular_arr[i] = year_arr[i];
                //cout << year_arr[i].getPostLikes() << endl;
            }

            for (int i = year_count; i < num_elements; i++)
            {
                bool is_true = false;
                int j = 0;
                int least_index = 0;
                int like_diff_max = 0;
                int diff_state = 0;
                Post state = year_arr[i];
                while (is_true == false)
                {
                    if (state.getPostLikes() > popular_arr[j].getPostLikes())
                    {
                        diff_state = state.getPostLikes() - popular_arr[j].getPostLikes();
                        if (diff_state > like_diff_max)
                        {
                            like_diff_max = diff_state;
                            least_index = j;
                        }
                    }
                    if (j == year_count - 1)
                    {
                        if (like_diff_max > 0)
                        {
                            for (int k = least_index; k < year_count - 1; k++)
                            {
                                popular_arr[k] = popular_arr[k + 1];
                            }
                            popular_arr[year_count - 1] = state;
                        }
                        is_true = true;
                    }
                    j++;
                }
            }


            if (num_elements < count)
            {
                cout << "There are fewer than " << count << " posts for year " << year <<  ". Top " << num_elements << " posts for year " << year << endl;
    
                for (int i = 0; i < num_elements; i++)
                {
                    cout << popular_arr[i].getPostLikes() << " likes: " << popular_arr[i].getPostBody() << endl;
                }
            }
            else
            {
                cout << "Top " << count << " posts for year " << year << endl;
                for (int i = 0; i < count; i++)
                {
                    cout << popular_arr[i].getPostLikes() << " likes: " << popular_arr[i].getPostBody() << endl;
                }
            }
        }

    }
}

/* Algorithim
    1. Loop through every user in the user array.
    2. Count every instance of -1 in each user's likes array
    3. Compare each user array element with the previous one, if more "-1s", then that user is now the least active
    4. Continue until end of user array is reached
*/
User Buffchat::findLeastActiveUser()
{
    /*
    for (int i = 0; i < 6; i++)
    {
        cout << users_[i].getUsername() << " Username" << endl;

        for (int j = 0; j < 4; j++)
        {
            cout << users_[i].getLikesAt(j) << endl;
        }
    }
    */
    if (num_users_ == 0)
    {
        return User();
    }
    else
    {
        User least_active;
        int least_active_num = 0;

        for (int i = 0; i < num_users_; i++)
        {
            int inactive_count = 0;
            for (int j = 0; j < num_posts_; j++)
            {
                if(users_[i].getLikesAt(j) == -1)
                {
                    inactive_count++;
                }
            }
        
            if (inactive_count > least_active_num)
            {
                least_active_num = inactive_count;
                least_active = users_[i];
            }
        }

        return least_active;
    }

}

/* Algorithim
    1. Check if posts or users array are empty, if so return -2
    2. Make an array containing the index of every post from the post author
    3. if index(s) are not -1 or 0, increase # of unique likes by one.
    4. Also count # of -1s (not vied) and 0s (view but not likes)
    5. If # of unique likes > 0, return that number. Otherwise:
        1. If num of -1s is 0, return -1
        2. If num of 0s is 0, return 0;
*/
int Buffchat::countUniqueLikes(string post_author)
{
    if (num_users_  == 0 || num_posts_ == 0)
    {
        return -2;
    }
    
    int author_index = 0;
    int author_arr[num_posts_];
    int not_viewed = 0;
    int not_liked = 0;
    int liked = 0;

    for (int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostAuthor() == post_author)
        {
            author_arr[author_index] = i;
            author_index++;
        }
    }
/*
    cout << "like array\n\n";
    for (int i = 0; i < num_users_; i++)
    {
        for (int j = 0; j < num_posts_; j++)
        {
            cout << users_[i].getLikesAt(j) << " ";
        }
        cout << "\n";
    }
*/
    int author_arr_size = author_index++;

/*
    cout << "\n";

    cout << "arrrrrr" << author_arr[0] << endl;
*/
    // Find users likes for authors posts
    for (int i = 0; i < num_users_; i++)
    {
        for (int j = 0; j < author_arr_size; j++)
        {
            int likes = users_[i].getLikesAt(author_arr[j]);
            //cout << "Likes: " << likes << endl;

            if (likes == 0)
            {
                not_liked++;
                //cout << post_author<< endl;
                //cout << not_liked << "not liked" << endl;
            }

            if (likes == -1)
            {
                not_viewed++;

                //cout << post_author<< endl;
                //cout << not_viewed << "not viewed" << endl;
            }

            if (likes > 0)
            {
                liked++;
                //cout << post_author<< endl;
                //cout << liked << "liked" << endl;
            }
        }
    }

    if (liked > 0)
    {
        return liked;
    }
    else if (not_viewed > 0)
    {
        return  -1;
    }
    else if (not_liked > 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}