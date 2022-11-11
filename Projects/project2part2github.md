#### **CSCI 1300 CS1: Starting Computing: Project 2 Part 2**
#### **Naidu/Yeh/Hoefer - Fall 2022**
#### **Due: Monday, October 30th by 5:00 PM MST**

# Table of contents
1. [Project Summary](#summary)
2. [Objectives](#objectives)
3. [Background](#background)
    1. [Classes](#classes)
       1. [Anatomy of a class](#anatomy)
          1. [Class Name](#className)
          2. [Access Specifiers](#accessSpecifiers)
          3. [Data Members and Member Functions](#dataMembers)
          4. [Accessing Data Members](#accessingDataMembers)
          5. [Defining Member Functions](#definingMemberFuncs)
       2. [Header and Source Files](#headerAndSourceFiles)
          1. [Header File](#headerFiles)
          2. [Source File](#sourceFiles)
          3. [How to compile multiple .cpp and .h files](#howToCompile)
4. [Submission Instructions](#submissions)
    1. [Test Cases Instructions](#tests)
        1. [Void functions](#void)
        2. [Non-void functions that return a bool or int](#bool-int)
        3. [Non-void functions that return a double](#double)
        4. [Functions manipulating arrays](#test-function-array)
        5. [Testing class objects](#test-objects)
5. [Questions](#questions)
    1. [Question 0](#question0)
    2. [Question 1](#question1)
    3. [Question 2](#question2)
    4. [Question 3](#question3)
    5. [Question 4](#question4)
    6. [Question 5](#question5)
    7. [Question 6](#question6)
    8. [Question 7](#question7)
    9. [Question 8](#question8)
    10. [Question 9](#question9)
    11. [Question 10](#question10)
6. [Overview](#overview)
    1. [Checklist](#checklist)
    2. [Grading Rubric](#grading)

# Project Summary <a name="summary"></a>
In Project 2, we will be creating an app called **BuffChat** to allow users to like posts. Based on comprehensive market research, we've determined that most social/chatting apps like Twitter, Snapchat, and WhatsApp are going out of style; customers now want a more nostalgic experience where they can only like individual posts with more restrictions than modern chatting apps. Who knows, if **BuffChat** is a success, we could even expand to have a real company!

Project 2 Part 1 was focused on creating `Post` and `User` classes and related functions for reading and manipulating their associated data. Project 2 Part 2 (this part) will use the building blocks from Part 1 to build the overall **Buffchat** app.

# Objectives <a name="objectives"></a>
* Use filestream objects to read data from text files
* Create objects and array of objects
* Using array operations on objects

# Background <a name="background"></a>

## Classes <a name="classes"></a>
When writing complex programs, sometimes the built-in data types (such as `int`, `char`, `string`)
don’t offer developers enough functionality or flexibility to solve their problems. 
A solution is for the developer (you - yes, you!) to create your own custom data types to use, called classes.
Classes are user-defined data types, which hold their own data members and member functions, which can be accessed and used by creating an instance of that class. 
A class is like a blueprint for an object, customized for whatever particular problem the programmer is working on.

String, for example, is a class in C++ which holds data (the characters comprising the string) and supports useful member functions like `substr` which operate on this data.

Below is an example of the basic definition of a class in C++.

![Anatomy of a class](images/pt1/classSkeleton.png)

Let’s break down the main components of this diagram: 

### Anatomy of a Class <a name="anatomy"></a>

#### Class Name <a name="className"></a>
A class is defined in C++ using the keyword `class` followed by the name of the class.
The body of the class is defined inside the curly brackets and terminated by a semicolon at the end.
This class name will be how you reference any _variables_ or _objects_ you create of that type. 
For example:
`ClassName objectName;`

The above line would create a new **object** (variable) with name `objectName` and of type `ClassName`, 
and this object would have all the properties that you have defined within the class ClassName.

#### Access Specifiers <a name="accessSpecifiers"></a>
Access specifiers in a class are used to set the accessibility of the class members.
That is, they restrict access by outside functions to the class members.

Consider the following analogy:

Imagine an intelligence agency like the CIA, that has 10 senior members.
Such an organization holds various sorts of information, and needs some way of determining who has access to any given piece of information.
Some information concerning classified or dangerous operations may only be accessible to the 10 senior members of the agency, and not directly accessible by any other person.
This data would be **private**.

In a class, like in our intelligence agency, these **private** data members are only accessible by a class's member functions and not directly accessible by any object or function outside the class.

Some other information may be available to anyone who wants to know about it.
This is **public** data.
Even people outside the CIA can know about it, and the agency might release this information through press releases or other means.
In terms of our class, this **public** data can be accessed by any member function of the class, as well as outside functions and objects, even other classes. The public members of a class can be accessed from anywhere in the program using the direct member access operator (**.**) with the object of that class.

#### Data Members and Member Functions <a name="dataMembers"></a>
Data members are the data variables and member functions are the functions used to manipulate these variables; together, data members and member functions define the properties and behavior of the objects in a Class.

The data members declared in any class definition can be fundamental data types (like `int`, `char`, `float`, etc.), arrays, or even other classes.

For example, for string objects, the data member is a `char array[]` that holds all of the individual letters of your string.
Some of a string’s member functions that we have used already are functions like `.substr()` and `.length()`.

#### Accessing Data Members <a name="accessingDataMembers"></a>
Keeping with our intelligence agency example, the code below defines a class that holds information for any general agency.
In the `main` function, we then create a new `IntelligenceAgency` object called `CIA`, and we set its `organization_name` to “CIA” by using the access operator (.) and the corresponding data member’s name.
However, we cannot access the `classified_intelligence` data member in the same way.
Not everyone has access to that private data.

Instead, we need to use a member function of the IntelligenceAgency class, `getClassifiedIntelligence()`, in order to see that information.
This allows us to control the release of private information by our IntelligenceAgency.

Additionally, the main function includes four different ways of creating objects with descriptions in the comments next to it.

```c++
class IntelligenceAgency
{
    public:
        IntelligenceAgency();         // Default constructor
        IntelligenceAgency(string classified_intelligence_input); // Parameterized constructor  
        string organization_name;
        string getClassifiedIntelligence();
        void setClassifiedIntelligence(string classified_intelligence_input);

    private:
        string classified_intelligence;
};

int main()
{
    IntelligenceAgency CIA;
    CIA.organization_name = "CIA";
    cout << CIA.classified_intelligence; // gives an error
    cout << CIA.getClassifiedIntelligence();
    
    // four types of constructor calls
    IntelligenceAgency abc; // creating an IntelligenceAgency object with the default constructor 
    IntelligenceAgency xyz = IntelligenceAgency(); // creating an IntelligenceAgency object with the default constructor 
    IntelligenceAgency pqr("PQR"); // creating an IntelligenceAgency object with a paramaterized constructor
    IntelligenceAgency rst = IntelligenceAgency("RST"); // creating an IntelligenceAgency object with a paramaterized constructor
}

```

#### Defining Member Functions <a name="definingMemberFuncs"></a>
You may have noticed that we declared various member functions in our class definition, 
but we did not specify how they will work when called.
The body of the function still needs to be written.
The solution is to define a function, such as `getClassifiedIntelligence()`, corresponding to our class’s functions.
But how does our program know that these functions are the same as the ones we declared in our class?
You as the developer need to explicitly tell the computer that these functions you are defining are the same ones you declared earlier.

```c++
string IntelligenceAgency::getClassifiedIntelligence()
{
    return classified_intelligence;
}
void IntelligenceAgency::setClassifiedIntelligence(string classified_intelligence_input)
{
    classified_intelligence = classified_intelligence_input;
}
```

We start the definition as we do any function, with the return type.
Then, we have to add a specifier `IntelligenceAgency::` that lets our program know that this function and the one we declared inside the class are the same.
We can see that this function returns the class’ `classified_intelligence` to the user.

Functions like `getClassifiedIntelligence()` are called **accessor/getter functions**.
This is because they retrieve or ‘get’ the private data members of a class object and return it to the program so that these values may be used elsewhere.

The second function, `setClassifiedIntelligence(string classified_intelligence_input)`, is called a **mutator/setter function**.
These allow functions from other parts of our program to modify or ‘set’ the private data members of our class objects.
Getters and setters are the functions that our program uses to interact with the private data members of our class objects.

### Header and Source Files <a name="headerAndSourceFiles"></a>
Creating our own classes with various data members and functions increases the complexity of our program.
Putting all of the code for our classes as well as the main functionality of our program into one .cpp file can become confusing for you as a programmer, and we need ways of reducing the visual clutter that this creates.
This is why, as we increase the complexity of a program, 
we might need to create multiple files: header and source files, which capture the *definition* and *implementation* of the class, respectively.

#### Header file <a name="headerFiles"></a>
Header files have `.h` as their filename extensions. 
In a header file, we declare one or more of the complex structures (classes) we want to develop.
In a class, we define member functions and member attributes. These functions and attributes are the building blocks of the class.

**Example file 0:** ClassName.h
```c++
#include <iostream> 
using namespace std; 
class ClassName 
{ 
    public: 
    . 
    . 
    . 
    private: 
    . 
    . 
    . 
};

```

**Example file 1:** IntelligenceAgency.h
```c++
#include <iostream> 
using namespace std; 
class IntelligenceAgency
{
    public:
        IntelligenceAgency();         // Default constructor
        IntelligenceAgency(string classified_intelligence_input); // Parameterized constructor  
        string organization_name;
        string getClassifiedIntelligence(){return classified_intelligence};
        void setClassifiedIntelligence(string classified_intelligence_input){classified_intelligence=classified_intelligence_input};

    private:
        string classified_intelligence;
};
```

#### Source file <a name="sourceFiles"></a>
Source files are recognizable by the `.cpp` extension.
In a source file, we implement the class defined in the header file.
Since we are splitting the development of actual code for the class into a definition (header file) and an implementation (source file), 
we need to link the two somehow.

```c++
//IntelligenceAgency Example
#include "IntelligenceAgency.h"
```
OR
```c++
//General Example
#include "ClassName.h"
```
In the source file, we will include the header file that defines the class so that the source file is “aware” of where we can retrieve the definition of the class.
We must define the class definition in every source that wants to use our user defined data type (our class).
When implementing each member function, our source files must tell the compiler that these functions are actually the methods defined in our class definition using the syntax that we showed earlier.

#### How to compile multiple .cpp and .h files <a name="howToCompile"></a>
In this project, it will be necessary to write multiple files (.h and .cpp) and test them before submitting them.
You need to compile and execute your code using the command line. 
Make sure that you start by changing directories so that you are in the folder where your solution’s files are stored.
In this example, our folder will be called `project2`. To change to this directory, use: 

```
cd project2/
```

**When compiling from the command line, you need to specify every .cpp file in your project.**
This means that when you call the g++ compiler, you need to explicitly name the files you’re compiling:

```
g++ -std=c++17 file1.cpp file2.cpp main.cpp
```

The compiling command results in the creation of an executable file. **Note that header files (`.h`) are NOT included in compilation commands.**
If you did not specify a name for this executable, it will be named `a.out` by default. 
To execute this file, use the command:

```
./a.out
```

You can add the `-o` flag to your compiling command to give the output file a name: 

```
g++ -o myName.out -std=c++17 file1.cpp file2.cpp main.cpp
```

And then run the file with
```
./myName.out
```

**Example 1**

Compiling `User.cpp` and `userClassTest.cpp`.
![basic compiling](images/pt1/terminal1.png)

**Example 2**

Here, we have named the executable `user` rather than use the default `a.out` name
![basic compiling](images/pt1/terminal2.png)


# Submission Instructions <a name="submissions"></a>

* **CodeRunner**. Your programs will be graded in part by CodeRunner. You can modify your code and re-submit (press Check again) as many times as you need up until the assignment due date.
* **C++ files**. When you are finished with all the questions, zip all of your .cpp and .h files together. Submit the single zip file under the assignment **"Project 2 Part 2"** on Canvas.
   * All files should be named as specified in each question, and they should compile and run on Coderunner (pass all test cases) and in VSCode to earn full points.
   * Our TAs will be grading the style of your code and comments. Please see the style guide on Canvas for more details.
   * At the top of each file, write your name in the format shown below.
   * Your C++ program for each question should also contain a main that tests the function you wrote, like below. **You should be sure to include as many test cases as you believe are necessary to ensure that your code works properly.** Deciding on how many test cases to include is an important skill to learn, since the number of necessary test cases can change between programs. Ensure that you'll be able to explain why you believe each main function contains an adequate number of tests.
     * Refer to the [Test Cases](#tests) section for more details.
   * Please be sure to also include function headers (function comments) that contain the algorithm implemented within the function, expressed in pseudocode. You can refer to the example below for more details. Algorithm is not required for constructors, getters and setters.

**Style Example:**

![style example](images/style.jpeg)


<span style="font-size:20px">**YOU ARE NOT ALLOWED TO USE ANY OF THE FOLLOWING. USAGE OF THE FOLLOWING LIST WILL RESULT IN A 0 ON THE PROJECT.**</span>

* Stringstream objects
* Vectors
* Global Variables
* Pointers
* References


### Test Cases Instructions <a name="tests"></a>

Every C++ program you write should include a main function that tests the code you wrote.
There will be 5 different types of test cases you should be expected to write depending on the return type of the function.
Listed below is how we expect you to test different types of functions. The process will be different for
if you are testing a `void` function, non-void functions that return an `int` or `bool`, and non-void functions
that return a `double`.

#### 1. Void Functions with printed output <a name="void"></a>

For **void** functions that have printed output (i.e. functions that use `cout` to print to the terminal), call the testing function in the main function. Your tests should include the expected output in comments.

See the sample code below:
```c++
void checkDiscount(double discount) 
{
    if (discount >= 50) {
        cout << "Great discount!" << endl;
    } else {
        cout << "Not a great discount." << endl;
    }
    return;
}

int main() 
{
    // test 1 for checkDiscount
    // expected output: "Great discount!"
    checkDiscount(82.7);
    
    // test 2 for checkDiscount
    // expected output: "Not a great discount."
    checkDiscount(22);
    
    return 0;
}
```
_* For the purpose of this test code snippet, algorithm comments were not included, but they are still expected in your C++ files._


<br>


#### 2. Functions returning bool or int <a name="bool-int"></a>

For **non-void** functions that return a **bool or int**, use an **assert statement**
from the **cassert** header (`#include <cassert>`) with a conditional expression.

Assert tests contain a conditional expression which will be true unless there is a bug in the program.
If the conditional expression evaluates to false, then your program will terminate and show an error message.

For the purpose of this project, functions that return a `bool` or `int` can be compared to a specific value using the equality operator `==`.

Your test will look something like this:

`assert(<function call> == <value to compare to>);`

* `<function call>` is where you will call the function you want to test with its function parameters.
* `<value to compare to>` is the value you expect the function to return.
* `==` is the equality operator, and it compares the equality of both sides of itself.

See the sample code below:
```c++
#include <iostream>
#include <cassert>
using namespace std;
int add_(int num1, int num2)
{
    // add num1 and num2 before returning
    return num1 + num2;
}
// isDrivingAge returns true if the given age passed as a parameter is greater than 16,
// else it returns false.
bool isDrivingAge(int age)
{
    if (age >= 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // test 1 for add_
    assert(add_(5, 6) == 11);
    // test 2 for add_
    assert(add_(10, 10) == 20);
    // test 3 for drivingAge
    assert(isDrivingAge(17) == true);
    // test 4 for drivingAge
    assert(isDrivingAge(14) == false);
}
```
_* For the purpose of this test code snippet, algorithm comments were not included, but they are still expected in your C++ files._

<br>


#### 3. Functions returning double <a name="double"></a>

For **non-void** functions that return a **double**, use an **assert statement**
from the **cassert** header (`#include <cassert>`) with a conditional expression and include the following function in your program.
```c++
/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
```
Because the `double` type holds so much precision, it will be hard to compare the equality of a function that returns a
double with another double value. To overcome this challenge, we can compare `double` values within a certain range
of precision or decimal places. The function above compares the equality of two values `a` and `b` up to two decimal places.
This function returns `true` if the values `a` and `b` are equal with each other up to two decimal places.

You will be expected to use this function in conjunction with `assert` statements to test functions that return
the type double.

Your test will look something like this:

`assert(doublesEqual(<function call>, <value to compare to>));`

* `<function call>` is where you will call the function you want to test with its function parameters
* `<value to compare to>` is the `double` value you expect the function to return.


See the sample code below:
```c++
#include <iostream>
#include <cassert>
using namespace std;
/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}
/**
 * reciprocal returns the value of 1 divided by the number passed into the function.
 */
double reciprocal(int num)
{
    return 1.0 / num;
}
int main()
{
    // test 1 for reciprocal
    assert(doublesEqual(reciprocal(6), 0.16));
    // test 2 for reciprocal
    assert(doublesEqual(reciprocal(12), 0.083));
}
```
For test 1, `reciprocal(6)` is being called, and we expect the function to return the value `0.16`.
The return value of `reciprocal(6)` and `0.16` is passed in as parameters to the `doublesEqual` function,
which will then return `true` if these two values are equal or `false` if they are not.

_* For the purpose of this test code snippet, algorithm comments were not included, but they are still expected in your C++ files._

<br>

#### 4. Functions manipulating arrays <a name="test-function-array"></a>

Functions which manipulate arrays passed as arguments can be tested by asserting on individual elements of the array after calling the function. This works even for `void` functions because arrays are passed by reference; even if the function doesn't return anything, the array in the function is the same array in memory as the one outside the scope of your function.

Note that if the array is an array of `float` or `double`, the `doublesEqual` function described [here](#non-void-double) should be used to assert on individual array elements.

See the sample code below:
```cpp
#include<iostream>
#include<cassert>
using namespace std;

/**
 * Add one to each element of the array.
 */
void addOneToArrayElements(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = arr[i] + 1;
    }
}

/**
 * doublesEqual will test if two doubles are equal to each other within two decimal places.
 */
bool doublesEqual(double a, double b, const double epsilon = 1e-2)
{
    double c = a - b;
    return c < epsilon && -c < epsilon;
}

/**
 * Add one to each element of the array.
 */
void addOneToArrayElementsDouble(double arr[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = arr[i] + 1.0;
    }
}

int main() 
{
    // test 1 for addOneToArrayElements
    int test1Arr[3] = {1, 2, 3};
    addOneToArrayElements(test1Arr, 3);
    assert(test1Arr[0] == 2);
    assert(test1Arr[1] == 3);
    assert(test1Arr[2] == 4);

    // test 2 for addOneToArrayElements
    int test2Arr[3] = {8, 10};
    addOneToArrayElements(test2Arr, 2);
    assert(test2Arr[0] == 9);
    assert(test2Arr[1] == 11);

    // test 1 for addOneToArrayElementsDouble
    double test3Arr[4] = {1.5, 4.6, 9.7, 16.8};
    addOneToArrayElementsDouble(testArr3, 4);
    assert(doublesEqual(testArr3[0], 2.5));
    assert(doublesEqual(testArr3[1], 5.6));
    assert(doublesEqual(testArr3[2], 10.7));
    assert(doublesEqual(testArr3[3], 17.8));
}
```


_* For the purpose of this test code snippet, algorithm comments were not included, but they are still expected in your C++ files._

<br>

#### 5. Testing class objects <a name="test-objects"></a>
When creating an instance of a class, or an object, the attributes of that object can be tested
by asserting on the individual attributes or data members. 

Note that if the data attribute is a float or double, the doublesEqual function described [here](#double) 
should be used to assert on the value.

Additionally, note that if the data attribute is an array, follow the ["Functions manipulating arrays" section](#test-function-array) 
on how to assert on individual array elements.

See the sample code below:
```c++
class Animal
{
private:
    string sound;
    string name;
    int age;

public:
    Animal();
    Animal(string, string, int);

    string getSound();
    string getName();
    int getAge();
};

Animal::Animal()
{
    sound = "";
    name = "";
    age = 0;
}

Animal::Animal(string sound_, string name_, int age_)
{
    sound = sound_;
    name = name_;
    age = age_;
}

string Animal::getSound()
{
    return sound;
}

string Animal::getName()
{
    return name;
}

int Animal::getAge()
{
    return age;
}

int main()
{
    Animal defaultDog;
    assert(defaultDog.getSound() == "");
    assert(defaultDog.getAge() == 0);
    assert(defaultDog.getName() == "");

    Animal actualDog("Bark bark!", "Pluto", 2);
    assert(actualDog.getSound() == "Bark bark!");
    assert(actualDog.getAge() == 2);
    assert(actualDog.getName() == "Pluto");
}
```
_* For the purpose of this test code snippet, algorithm comments were not included, but they are still expected in your C++ files._



# Questions <a name="questions"></a>

Project 2 Part 2 is focused on developing a `Buffchat` class for managing the tasks and data associated with user posts. This class will contain functions written in Project 2 Part 1 as well as some new functions we'll develop for this part.

Note that the following is broken up into multiple sub-problems for each individual function to make it a bit more digestible, but there are only 4 Coderunner problems for testing your implementations (not including the extra credit question).

## Question 0 (35 points): Buffchat Class <a name="question0"></a>
Create a **Buffchat** class, with separate interface (**Buffchat.h**) and implementation (**Buffchat.cpp**) files, 
comprised of the following attributes:

**Data Members (private)**

| Data Members          | Description                                              |
|-----------------------|----------------------------------------------------------|
| const static int: `posts_size_`       | The capacity of the `posts_` array (50). static constant |
| const static int: `users_size_`       | The capacity of the `users_` array (50). static constant |
| `Post` array: `posts_` | An array of `Post` objects                              |
| `User` array: `users_` | An array of `User` objects                               |
| int: `num_posts_`       | Number of posts stored in the database                         |
| int: `num_users_`       | Number of users stored in the database                          |


**Member Functions (public)**

| Member Functions          | Description                                                            |
|---------------------------|------------------------------------------------------------------------|
| Default constructor       | Sets both `num_posts_` and `num_users_` to value 0                        |  
| `getPostSize()`              | Returns `posts_size_` as an integer                                  |
| `getUserSize()`              | Returns `users_size_` as an integer                                  |
| `getNumPosts()`              | Returns `num_posts_` as an integer                                  |
| `getNumUsers()`              | Returns `num_users_` as an integer                                  |
| `int readPosts(string file_name)`              | Takes a string (the name of the file to be read) and populates the `posts_` array. Returns the total number of posts in `posts_` array as an integer  |
| `void printPostsByYear(string year)`   | Takes a string (the year) and prints the posts posted in the given year  |
| `int readLikes(string file_name)`              | Takes a string (the name of the file to be read) and populates the `users_` array. Returns the total number of users in `users_` array as an integer  |
| `int getLikes(string post_author, string username)`   | Takes two strings (post author and username, respectively) and returns the number of times a given user has liked a post by a given author  |
| `void findTagUser(string username_tag)`   | Takes a string (the username) and prints all the users whose usernames match the given tag |
| `bool addPost(string post_body, string post_author, string date)`  | Takes three strings (post body, post author and date, respectively) and adds a post to the `posts_` array |
| `void printPopularPosts(int count, string year)`    | Takes an integer (the number of posts) and a string (the year) and prints the posts with the highest likes for the given year |
| `User findLeastActiveUser()`    | Returns the user who has viewed the least number of posts |
| `int countUniqueLikes(string post_author)`   | Takes a string (the post author) and returns the number of number of users who liked the posts posted by the author |

*Exact implementation details of these functions are listed in individual questions below.*

The zip submission should have three files for this problem: 
* `Buffchat.h`
* `Buffchat.cpp`
* A driver file called `buffchatDriver.cpp`, with a main() function to test your member functions. 
  * In your main() function, the test cases should include the creation of class objects with the default constructor. You must also test each of the accessors and mutators and other member functions by creating and manipulating class objects and using assert tests to verify that things are working properly.

For Coderunner, paste your Buffchat class and its implementation (the contents of Buffchat.h and Buffchat.cpp). Do not include the main() function in Coderunner.

## Question 1: member function readPosts <a name="question1"></a>
Update the `readPosts` function from Project 2 Part 1 to now be a member function for the Buffchat class. The `readPosts` function populates an array of Post objects with the post_body, post_author, likes, and date from an external file. The array of Post objects is **one** of the data members of the Buffchat class. This function should:

* Accept one parameter:
  * `string` **file_name**: the name of the file to be read
* Use `ifstream` and `getline` to read data from the file, creating a new Post object for each line, and placing the object into the Post array.  
* Empty lines should not be added to the array.
* **Hint**: You can use the `split()` function from Homework 5 with a comma (`,`) as the delimiter.
* The function behavior should match the following scenarios:
  * If `num_posts_` is equal to `posts_size_`, return -2. 
  * If the file is not opened successfully, return -1. 
    * The priority of the return code -2 is higher than -1, i.e., in cases when `num_posts_` is equal to `posts_size_` and the file cannot be opened, the function should return -2. 
  * While `num_posts_` is smaller than `posts_size_`, keep the existing elements in the `posts_` array, then read data from the file and add (append) the data to the array. The number of posts stored in the array cannot exceed the size of the array. **Be sure to update the total number of posts in the system.**
  * Returns the total number of posts in the system, as an integer. 

**Note**: `num_posts_` and `posts_size_` are accessible as data members of the Buffchat class.

**Important**: Since your `posts_` array is private, we cannot directly check objects stored in the array from the main function like you tested in Project 2 Part 1. Let’s make `printPostsByYear` to check if `readPosts` is working correctly...in the next problem!

*Example 1*: General `readPosts` usage.
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21


</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
// print values 
cout << "rv = " << rv << endl; 
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 
// print posts 
myBuffchat.printPostsByYear("20");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 2 
num_posts_ = 2
Here is a list of posts for year 19
Sko buffs!!
Come get involved in robotics @ cu!
```
</td>
</tr>
</table>

*Example 2*: Suppose we call the `readPosts` functions twice. In the `posts` array, all posts from the first file and the second file should be stored in the posts array, and the function returns the total number of the posts stored in the `posts` array.
<table>
<tr>
</tr>
<tr>
    <td> posts1.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21


</tr>
<tr>
    <td> posts2.txt </td>
    <td>
        
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,215,08/24/18
    Friday night lights in Folsom,caseymac,100,10/25/21
        

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object; 
Buffchat myBuffchat;
// call readPosts and check return values 
int rv1 = myBuffchat.readPosts("posts1.txt"); 
cout << "rv1 = " << rv1 << endl; 
int rv2 = myBuffchat.readPosts("posts2.txt"); 
cout << "rv2 = " << rv2 << endl; 
// check value of getNumPosts
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 
// print posts 
myBuffchat.printPostsByYear("21");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv1 = 3 
rv2 = 5 
num_posts_ = 5 
Here is a list of posts for year 21
What are you currently reading?
Friday night lights in Folsom
```
</td>
</tr>
</table>

*Example 3*: File does not exist.
<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts and check return values 
int rv1 = myBuffchat.readPosts("badFile.txt"); 
cout << "rv1 = " << rv1 << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv1 = -1
```
</td>
</tr>
</table>

*Example 4*: `num_posts_` becomes equal to `posts_size_` and the function returns `posts_size_`.

<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21
        

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat

// read more posts data 

// check value of getNumPosts
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl;  

// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;

// check value of getNumPosts again
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
num_posts_ = 48 
rv = 50 
num_posts_ = 50 
```
</td>
</tr>
</table>

*Example 5*: `num_posts_` is equal to `posts_size_`, meaning the array is already full and the function returns -2.

<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// read multiple files full of posts made on same date

// check value of getNumPosts
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 

// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;

// check value of getNumPosts again
cout << "num_posts_ = " << myBuffchat.getNumPosts() << endl; 
        
// call readPosts 
int rv1 = myBuffchat.readPosts("posts.txt"); 
cout << "rv1 = " << rv1 << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
num_posts_ = 48 
rv = 50 
num_posts_ = 50
rv1 = -2
```
</td>
</tr>
</table>

## Question 2: member function printPostsByYear <a name="question2"></a>
As we saw in the `readPosts` example, we can use the `printPostsByYear` function to test your `readPosts` function. This will be useful in displaying the contents of the posts database.

The function specification looks like this:
* Accepts 1 parameter:
  * `string` **year**: the `year` for the posts to be printed
* This function does **not** return anything
* The function should match the following behavior:
  * If the number of posts is 0 (or less than 0), print `"No posts are stored"`
  * If there are one or more posts, print `"Here is a list of posts for year <year>"` followed by each post's content on a new line
  * If there is no post matching the given year, print `"No posts stored for year <year>"`

*Example 1*: There are two posts

<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// read post file 
int rv = myBuffchat.readPosts("posts.txt"); 

// call printPostsByDate
myBuffchat.printPostsByYear("21");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
Here is a list of posts for year 21
What are you currently reading? 
```
</td>
</tr>
</table>

*Example 2*: There are no posts

<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// read post file 
int rv = myBuffchat.readPosts("posts.txt"); 

// call printPostsByDate
myBuffchat.printPostsByYear("22");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
No posts are stored
```
</td>
</tr>
</table>

## Question 3: member function readLikes <a name="question3"></a>
Update the `readLikes` function from Project 2 Part 1 to now be a member function for the Buffchat class. The `readLikes` function populates an array of `User` objects with the username and likes data from an external file. Each username is followed by a list of likes of the user for each posts and then the final integer in this list is the number of posts for the user in posts.txt. The array of `User` objects is **one** of the data members of the Buffchat class.

The `users.txt` may, for example, look as follows:
```
cuisthebest,4,6,7,3,-1,5,2,3,3,8,8,4,5,7,8,1,3,2,9,9,1,1,10,0,3,8,1,3,4,4,0,2,4,2,7,8,6,3,-1,9,5,4,6,-1,-1,-1,7,1,3,7
lovesickSardines,9,9,4,9,-1,4,-1,7,1,8,0,-1,-1,7,7,1,4,2,2,4,9,2,5,4,7,5,1,7,9,3,3,8,2,4,10,3,2,-1,0,5,9,8,2,1,1,5,6,0,3,6
grizzledChowder,8,3,7,2,2,-1,4,7,10,8,7,4,0,4,8,9,2,5,7,4,1,6,9,2,8,1,7,6,9,-1,5,4,6,1,-1,5,2,2,1,2,7,5,6,5,10,4,9,7,8,1
grumpyRat1,1,3,4,-1,1,10,3,-1,9,6,0,3,4,5,7,-1,-1,8,5,-1,1,8,3,2,8,1,2,3,8,2,-1,5,6,6,1,8,4,1,2,2,-1,8,6,1,6,9,6,3,-1,0
```

This function should:

* Accept one parameter:
  * `string` **file_name**: the name of the file to be read
* Use `ifstream` and `getline` to read data from the file, creating a new `User` object for each line, and placing the object into the `users_` array.
* **Hint**: You can use the `split()` function from Homework 5 with a comma (`,`) as the delimiter.
* **Hint**: You can use `stoi` to convert each like value (a string, as read from the text file) into an integer value.
* Empty lines should not be added to the arrays.
* The function behavior should match the following scenarios:
  * If `num_users_` is equal to `users_size_`, return -2. 
  * If the file is not opened successfully, return -1. 
    * The priority of the return code -2 is higher than -1, i.e., in cases when `num_users_` is equal to `users_size_` and the file cannot be opened, the function should return -2. 
  * While `num_users_` is smaller than `users_size_`, keep the existing elements in users, then read data from the file and add (append) the data to the array. The number of users stored in the array cannot exceed the size of the array. **Be sure to update the total number of users in the system.**
  * Return the total number of users in the system, as an integer.

**Note**: `num_users_` and `users_size_` are accessible as data members of the Buffchat class.

**Important**: Since your `users` array is private, we cannot directly check objects stored in the array from the main function like you tested in Project 2 Part 1. Let’s make `getLikes` to check if `readLikes` is working correctly...in the next problem!

*Example 1*: General `readLikes` usage.
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,146,09/10/20
    Come get involved in robotics @ cu!,roboticscu,239,04/20/20
    What are you currently reading?,bookworm43,202,12/12/21
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,215,08/24/18

</tr>
<tr>
    <td> users.txt </td>
    <td>
        
    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3
        
    
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl; 
        
// call readLikes and check return
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl; 

// check value of getNumUsers 
cout << "num_users_ = " << myBuffchat.getNumUsers() << endl;

// print user’s ratings 
string name = "ilovechip";
cout << myBuffchat.getLikes(name, "michelleryan") << endl;
cout << myBuffchat.getLikes(name, "roboticscu") << endl;
cout << myBuffchat.getLikes(name, "bookworm43") << endl;
cout << myBuffchat.getLikes(name, "kate128") << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5 
num_users_ = 5 
4 
-1 
1 
8 
```
</td>
</tr>
</table>

*Example 2*: Suppose we call the `readLikes` functions twice. In the `users_` array, all users from the first file and the second file should be stored in the users array, and the function returns the total number of the users stored in the `users_` array.
<table>
<tr>
</tr>
<tr>
    <td> users1.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> users2.txt </td>
    <td>

    spiritedMues,9,10,8,0
    cuboulderalumni,-1,0,9,7
    buffsfootball,5,-1,2,10

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readLikes and check return values 
int rv1 = myBuffchat.readLikes("users1.txt"); 
cout << "rv1 = " << rv << endl; 
        
int rv2 = myBuffchat.readLikes("users2.txt"); 
cout << "rv2 = " << rv << endl; 
// check value of getNumUsers
cout << "num_users_ = " << readLikes.getNumUsers() << endl; 
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv1 = 5 
rv2 = 8 
num_users_ = 8
```
</td>
</tr>
</table>

*Example 3*: File does not exist.
<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readLikes and check return values 
int rv1 = myBuffchat.readLikes("badFile.txt"); 
cout << "rv1 = " << rv << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv1 = -1
```
</td>
</tr>
</table>

*Example 4*: `num_users_` becomes equal to `users_size_` and the function returns `users_size`.

<table>
<tr>
</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// read more user data

// check value of getNumUsers
cout << "num_users_ = " << myBuffchat.getNumUsers() << endl; 

// call readLikes 
int rv = myBuffchat.readLikes("users.txt"); 
cout << "rv = " << rv << endl;

// check value of getNumUsers again
cout << "num_users_ = " << myBuffchat.getNumUsers() << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
num_users_ = 48 
rv = 50 
num_users_ = 50
```
</td>
</tr>
</table>

*Example 5*: `num_users_` is equal to `users_size_`, meaning the array is already full and the function returns -2.

<table>
<tr>
</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Calls </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// read more user data

// check value of getNumUsers
cout << "num_users_ = " << myBuffchat.getNumUsers() << endl; 

// call readLikes 
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// check value of getNumUsers again
cout << "num_users_ = "<< myBuffchat.getNumUsers() << endl;

// call readLikes again
int rv2 = myBuffchat.readLikes("users.txt"); 
cout << "rv2 = " << rv2 << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
num_users_ = 48 
rv1 = 50 
num_users_ = 50 
rv2 = -2
```
</td>
</tr>
</table>

## Question 4: member function getLikes <a name="question4"></a>
Update the `getLikes` function from Project 2 Part 1 to now be a member function for the Buffchat class. The `getLikes` returns the number of times a given user has liked a post by a given author. This function should find the first post in the posts array by the author

This function should:
* Have two parameters in this order:
  * `string` **post_author**: author of post in question
  * `string` **username**: username in question  
* The username search should be case sensitive. For example, "Ben", "ben" and "BEN" all refer to different users.
* The function behavior should match the following scenarios:
  * Return the value of likes from the user for the post posted by post_author
  * Return -3 if the user or the post_author are not found 
  * Return -2 if the number of users or number of posts stored are 0 (or less than 0)

The following diagram demonstrates the relationship between the Post and User classes: ![Post_User_Relationship](images/pt1/PostsUsersDiagram.png)

*Set up for examples below*
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 

</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td>  </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;

// add posts
int rv = myBuffchat.readPosts("posts.txt");
cout << "rv = " << rv << endl;

// add users
int rv1 = myBuffchat.readLikes("users.txt");
cout << "rv1 = " << rv1 << endl;
        
// Expected Output
rv = 4
rv1 = 5
4
5
```
</tr>
</table>

*Example 1*: Both `username` and `post_author` exist, and the value of likes for the post is non-zero

<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
myBuffchat.getLikes("roboticscu", "amazedOtter4");
```
</tr>
<tr>
    <td> Return Value </td>
    <td>10</td>
</tr>
</table>

*Example 2*: The `username` does not exist

<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
myBuffchat.getLikes("roboticscu", "chipthebuffalo");
```
</tr>
<tr>
    <td> Return Value </td>
    <td>-3</td>
</tr>
</table>

*Example 3*: The `post_author` does not exist

<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
myBuffchat.getLikes("cubouldermusic", "amazedOtter4");
```
</tr>
<tr>
    <td> Return Value </td>
    <td>-3</td>
</tr>
</table>

*Example 4*: The `username` and `post_author` both do not exist

<table>
<tr>
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
myBuffchat.getLikes("susanfrances", "grumpyRat1");
```
</tr>
<tr>
    <td> Return Value </td>
    <td>-3</td>
</tr>
</table>

## Question 5: member function findTagUser <a name="question5"></a>
Update the `findTagUser` function from part 1 to be a member function of the Buffchat class. The function `findTagUser`, prints all users with the given tag included in their username.

This function should:
* Has one parameter:
  * `string` **username_tag**: the substring to search the usernames for 
* The username_tag search should be case sensitive. For example, the tag "xyz" is present in the username "abxyz" but the tag "XYZ" is not present.
* The function should not return anything (i.e. the function is **void**)
* The function behavior should match the following scenarios (in this order of precedence):
  * If the number of users is 0 (or less than 0), print `"No users are stored in the database"`
  * if no user has `username_tag` included in their username, print `"No matching user found"`
  * If there are one or more users matching the given tag, print `"Here are all the usernames that contain <tag>` followed by each username on a new line

*Example 1*: There are users stored with the tag in their username
<table>
<tr>
</tr>
<tr>
    <td> users.txt </td>
    <td>
    
    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
int rv = myBuffchat.readLikes("users.txt"); 
cout << "rv = " << rv << endl;

// call findTagUser
cout << myBuffchat.findTagUser("ed") << endl; 
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 5
Here are all the usernames that contain ed
pacifiedIcecream7
amazedOtter4        
```
</td>
</tr>
</table>

*Example 2*: There are no users stored in the database
<table>
<tr>
</tr>
<tr>
    <td> users1.txt </td>
    <td>


</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
int rv = myBuffchat.readLikes("users1.txt"); 
cout << "rv = " << rv << endl;

// call findTagUser
cout << myBuffchat.findTagUser("cool") << endl; 
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 0;
No users are stored in the database
```
</td>
</tr>
</table>


## Question 6: member function addPost <a name="question6"></a>
Create a member function for the Buffchat class, `addPost`. The `addPost` function adds a new post to the `posts_` array.

This function should:
* Accepts 3 parameters in this order:
  * `string` **post_body**: content of the new post
  * `string` **post_author**: author of the post
  * `string` **date**: date of the post
* Add a new post object (with the parameter values) at the first unused position in the `posts_` array. 
* The number of likes for the new post object should be 0. 
* The values in the likes_ array for this post has to be set to -1.
* The function should match the following behavior:
  * Return false if the posts array is full
  * Return true if the post is successfully added to the array

*Example 1*: Return true if there is space to add a new post in the posts array
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;

// add a new post
cout << myBuffchat.addPost("Snow Day!!!", "spiritedMues", "10/25/22");
// check if num_posts_ was updated to reflect the new addition
cout << "num_posts_: " << myBuffchat.getNumPosts() << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
num_posts_: 4
1
num_posts_: 5
```
</tr>
</table>

*Example 2*: The posts array contains 50 posts. Return false if the posts array is not empty. 
<table>
<tr>
</tr>

<tr>
    <td> Function Call </td>
    <td>

```cpp

// get num_posts_  
cout << "num_posts_: " << myBuffchat.getNumPosts() << endl;

// add a new post
cout << myBuffchat.addPost("Snow Day!!!", "spiritedMues", "10/25/22");
// check if num_posts_ is still 50
cout << "num_posts_: " << myBuffchat.getNumPosts() << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
num_posts_: 50
0
num_posts_: 50
```
</td>
</tr>
</table>


## Question 7: member function printPopularPosts <a name="question7"></a>
Create a member function for the Buffchat class, `printPopularPosts`. The `printPopularPosts` function prints the requested number of posts with the highest likes for the given year. 

This function should:
* Accept 2 parameters in this order:
  * `int` **count**: the number of posts to be printed
  * `string` **year**: the year in question
* The function should match the following behavior:
  * If the number of posts stored in the array is 0 (or less than 0), print `"No posts are stored"`
  * If there is no post matching the given year, print `"No posts stored for year <year>"`
  * If there are at least the requested number(`count`) of posts matching the given year, print `"Top <count> posts for year <year>`" followed by each post (number of likes: content of post) on a new line
  * If there are less than the requested number(`count`) of posts matching the given year, print `"There are fewer than <count> posts for year <year>. Top <actual_number> posts for <year>`" followed by each post (number of likes: content of post) on a new line
  

*Example 1*: The requested number of posts are available for the given year
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18   

</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find the top 2 posts for year 20
cout << myBuffchat.printPopularPosts(2, "20") << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5
Top 2 posts for year 20
22 likes: Sko buffs!!
15 likes: What are you currently reading?
```
</td>
</tr>
</table>

*Example 2*: There are fewer than the requested number of posts for that year
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 

</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,7,3,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find the top 10 posts for year 20
cout << myBuffchat.printPopularPosts(10, "20") << endl;
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5
There are fewer than 10 posts for year 19. Top 3 posts for year 19
22 likes: Sko buffs!!
7 likes: Come get involved in robotics @ cu!
15 likes: Happy 2nd Birthday @cubuffsralphie VI!
```
</td>
</tr>
</table>

## Question 8: member function findLeastActiveUser <a name="question8"></a>
Create a member function for the Buffchat class, `findLeastActiveUser`. The `findLeastActiveUser` function returns the user with the least activity recorded in the database(viewed the least number of posts). An entry of -1 in the likes_ array is an indicator that the user has not viewed the post.

This function:
* Takes no parameters
* The function should match the following behavior:
  * Return an empty User object if there are no users stored in the database
  * Return the user with the least activity recorded in the database
  * Return the first user found if there are multiple users with the same views

*Example 1*: There are no users stored.
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

</tr>
<tr>
    <td> users.txt </td>
    <td>

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// findLeastActiveUser
User u = myBuffchat.findLeastActiveUser();
// check if empty object was returned
cout << "Username: " << u.getUsername() << endl;
// this function prints the likes values for the user
cout << "Likes: " << endl;
printLikesForUser(u);
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 0;
rv1 = 0;
Username: 
Likes: -1 -1 -1 -1 . . .
```
</td>
</tr>
</table>

*Example 2*: User with lowest actvity exists in the users array
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18    

</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,-1,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,-1,-1,10
    amazedOtter4,10,6,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;
        
// findLeastActiveUser
User u = myBuffchat.findLeastActiveUser();
cout << "Username: " << u.getUsername() << endl;
// this function prints the likes values for the user
cout << "Likes: " << endl;
printLikesForUser(u);
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5
Username: pacifiedIcecream7
Likes: 0 -1 -1, 10
```
</td>
</tr>
</table>

*Example 3*: Multiple users with the same views exist in the users array.
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 8   

</tr>
<tr>
    <td> users.txt </td>
    <td>

    ilovechip,4,0,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,-1,7,10
    amazedOtter4,10,-1,0,3
    cuisthebest,4,6,7,3

</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;
        
// findLeastActiveUser
User u = myBuffchat.findLeastActiveUser();
cout << "Username: " << u.getUsername() << endl;
// this function prints the likes values for the user
cout << "Likes: " << endl;
printLikesForUser(u);
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5
Username: vengefulSauce
Likes: 4 1 -1 8
```
</td>
</tr>
</table>


## Question 9: member function countUniqueLikes <a name="question9"></a>
Create a member function for the Buffchat class, `countUniqueLikes`. The `countUniqueLikes` function returns the number of users who liked the posts posted by the author in question. Each user can like the same post a maximum of 10 times.  

This function should:
* Accept one parameter:
  * `string` **post_author**: author of post in question
* If the user has liked multiple posts by the post_author, each post the user has liked should count toward the unique likes
* The function should match the following behavior:
  * Return the number of unique likes received across all the posts posted by the author in question
  * Return 0 if no user has liked their posts
  * Return -1 if no user has viewed their posts
  * Return -2 if the posts array or the users array is empty


*Example 1*: At least one user has liked the post posted by author
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18  

</tr>
<tr>
    <td> users.txt </td>
    <td>
        
    ilovechip,4,0,1,8
    vengefulSauce,4,1,-1,8
    pacifiedIcecream7,0,-1,7,10
    amazedOtter4,10,-1,0,3
    cuisthebest,4,6,7,3
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find unique likes
cout << myBuffchat.countUniqueLikes("michelleryan");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 4
rv1 = 5
4       
```
</td>
</tr>
</table>

*Example 2*: Author in question has posted multiple posts
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,15,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 
    Freshmen meet the Buffs! Welcome to Boulder Class of 2026,michelleryan,13,03/06/20

</tr>
<tr>
    <td> users.txt </td>
    <td>
        
    ilovechip,4,0,1,8,3
    vengefulSauce,4,1,-1,8,0
    pacifiedIcecream7,0,-1,7,10,-1
    amazedOtter4,10,-1,0,3,0
    cuisthebest,4,6,7,3,10
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find unique likes
cout << myBuffchat.countUniqueLikes("michelleryan");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 5
rv1 = 5
6       
```
</td>
</tr>
</table>

*Example 3*: The posts posted by the author has 0 likes
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,7,04/20/20
    What are you currently reading?,bookworm43,0,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 
    Freshmen meet the Buffs! Welcome to Boulder Class of 2026,michelleryan,13,03/06/20

</tr>
<tr>
    <td> users.txt </td>
    <td>
        
    ilovechip,4,0,0,8,3
    vengefulSauce,4,1,0,8,0
    pacifiedIcecream7,0,-1,0,10,-1
    amazedOtter4,10,-1,0,3,0
    cuisthebest,4,6,0,3,10
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find unique likes
cout << myBuffchat.countUniqueLikes("bookworm43");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 5
rv1 = 5
0       
```
</td>
</tr>
</table>

*Example 4*: The posts posted by the author has 0 views
<table>
<tr>
</tr>
<tr>
    <td> posts.txt </td>
    <td>

    Sko buffs!!,michelleryan,22,09/10/20
    Come get involved in robotics @ cu!,roboticscu,0,04/20/20
    What are you currently reading?,bookworm43,0,12/12/20
    Happy 2nd Birthday @cubuffsralphie VI!,kate128,32,08/24/18 
    Freshmen meet the Buffs! Welcome to Boulder Class of 2026,michelleryan,13,03/06/20

</tr>
<tr>
    <td> users.txt </td>
    <td>
        
    ilovechip,4,0,-1,8,3
    vengefulSauce,4,0,-1,8,0
    pacifiedIcecream7,0,-1,-1,10,-1
    amazedOtter4,10,-1,-1,3,0
    cuisthebest,4,0,-1,3,10
</tr>
<tr>
    <td> Function Call </td>
    <td>

```cpp
// make Buffchat object 
Buffchat myBuffchat;
// call readPosts 
int rv = myBuffchat.readPosts("posts.txt"); 
cout << "rv = " << rv << endl;
// call readLikes
int rv1 = myBuffchat.readLikes("users.txt"); 
cout << "rv1 = " << rv1 << endl;

// find unique likes
cout << myBuffchat.countUniqueLikes("bookworm43");
```
</tr>
<tr>
    <td> Output </td>
    <td>
    
```
rv = 5
rv1 = 5
-1      
```
</td>
</tr>
</table>

## Question 10 (10 points): driver <a name="question10"></a>
Now, let's modify our main program from Project 2 Part 1 to use the Post class, User class, and Buffchat class we've created in Part 2. Create a file called project2pt2.cpp. In this file build a program that gives the user a menu with 9 options:

```
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
```

The menu will run on a loop, continually offering the user nine options until they opt to quit. You should make use of the functions you wrote previously, call them with appropriate input, and process the values they return.

**Note**: When writing your solution in VSCode, the Post class definition should be in Post.h and Post.cpp, the User class definition should be in User.h and User.cpp, and the Buffchat class definition should be in Buffchat.h and Buffchat.cpp. project2pt2.cpp should have a main function to manage the menu. Note that project2pt2.cpp should **not** have class definitions in it; these should be contained in their respective files and `#include`'ed in project2pt2.cpp. Remember to only `#include` the header files. The class implementation files will be compiled with `project2pt2.cpp`. 
To compile in the terminal, use the following command:
`g++ -std=c++17 project2pt2.cpp Post.cpp User.cpp Buffchat.cpp`

**For Question 9 on Coderunner, you need to submit the entire program project2pt2.cpp (including Post class, User class, Buffchat class, and the main function) in the answer box.**

You can use the [posts.txt](data_files/posts.txt) and [users.txt](data_files/users.txt) text files.

The behavior of the menu is specified as follows:

**Option 1: Read posts** 
* Prompt the user for a file name. 
  * `Enter a post file name:`
* Pass the file name to your readPosts function. 
* If the function returns -1, then print the following message: 
  * `File failed to open. No posts saved to the database.` 
* If the function returns -2, print 
  * `Database is already full. No posts were added.` 
* If the function returns a value equal to the size of the array of posts print the following message: 
  * `Database is full. Some posts may have not been added.`
* If the function returns a positive (or zero) value that's less than the size of the array (i.e. posts were successfully read and the array is not full), print the total number of posts in the database in the following format:
  * `Total posts in the database: <numberOfPosts>`

**Option 2: Print post by year** 
* Prompt the user to enter the date of the post.
  * `Enter the year(YY):`
* Pass the year to your printPostsByYear function
* Print all the posts posted in that year.

**Option 3: Read users**
* Prompt the user for a file name. 
  * `Enter a user file name:` 
* Pass the file name to your readLikes function. 
* If the function returns -1, then print the following message: 
  * `File failed to open. No users saved to the database.`
* If the function returns -2, print:
  * `Database is already full. No users were added.` 
* If the function returns a value equal to the size of the array of Users print the following message: 
  * `Database is full. Some users may have not been added.`
* If the function returns a positive (or zero) value that's less than the size of the array (i.e. users were successfully read and the array is not full), print the total number of users in the database in the following format:
  * `Total users in the database: <numberOfUsers>`

**Option 4: Get likes** 
* Prompt the user for a post author. 
  * `Enter a post author:` 
* Prompt the user for a user 
  * `Enter a user name:`
* Pass the user name and post author to your getLikes function. 
* Print the result in the following format: 
  * `<name> liked the post posted by <post_author> <num_likes> times` 
* If the function returns 0, print the result in the following format: 
  * `<name> has not liked the post posted by <post_author>`
* If the function returns -1, print the result in the following format: 
  * `<name> has not viewed the post posted by <post_author>`
* If the function returns -2, print the result in the following format: 
  * `Database is empty.`
* * If the function returns -3, print the result in the following format: 
  * `<name> or <post_author> does not exist.`

**Option 5: Find tag user**
* Prompt the user for a tag. 
  * `Enter a tag:` 
* Pass the tag to your findTagUser function.
* Print all the usernames that contain tag 

**Option 6: Add a new post**
* Prompt the user to enter body of post.
  * `Enter a post body:`
* Prompt the user for a post author. 
  * `Enter a post author:`
* Prompt the user to enter the date of the post.
  * `Enter a date(mm/dd/yy):`
* Pass the post body, author and date to your addPost function
* If the post is successfully added (i.e. the function returns 1), print the result in the following format: 
  * `<post_author>'s post added successfully` 
* If the function returns false, print the result in the following format:
  * `Database is already full. <post_author>'s post was not added.`

**Option 7: Print popular posts for a year**
* Prompt the user for number of posts to be found. 
  * `Enter the number of posts:` 
* Prompt the user to enter the date.
  * `Enter the year(YY):` 
* Pass the number and year to your printPopularPosts function
* Print the requested number of posts with the highest likes for the given year.

**Option 8: Find least active user based on likest**
* Call your `findLeastActiveUser` function.
* If the function returns an empty user object print the result in the following format:
  * `Database is empty.`
* If the function returns a user object that isn't empty print the result in the following format:
  * `<username> is the least active user`
  
**Option 9: Find unique likes for a post author**
* Prompt the user for a post author. 
  * `Enter a post author:`
* Pass the author to your findUniqueLikes function
* If the posts posted by the author have been liked by at least one user, print the result in the following format: 
  * `The posts posted by <post_author> have been liked by <count> unique users.`
* If the function returns 0, print the result in the following format: 
  * `The posts posted by <post_author> have received 0 likes so far.`
* If the function returns -1, print the result in the following format: 
  * `The posts posted by <post_author> have not been viewed by anyone.`
* If the function returns -2, print the result in the following format: 
  * `Database is empty.`


**Option 10: Quit**
* Print `Good bye!` and then stop the program.

**Invalid input**

If the user input is not the above values print `Invalid input` before re-prompting the user. Assume menu input will always be numeric.

Below is an example of running the project2pt2 program. Note that the input files used in this example are the [posts.txt](data_files/posts.txt) and [users.txt](data_files/users.txt) text files provided on Github. User input is in **bold**.

<pre><code>
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>1</b>
Enter a post file name:
<b>badFile.txt</b> 
File failed to open. No posts saved to the database. 
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>3</b>
Enter a user file name:
<b>badFile.txt</b>
File failed to open. No users saved to the database.
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>1</b>
Enter a post file name:
<b>posts.txt</b>
Total posts in the database: 5
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>3</b>
Enter a user file name:
<b>users.txt</b>
Total users in the database: 4
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>2</b>
Enter the year(YY):
<b>22</b>
Here is a list of posts for year 22
It's National Live Creative Day! What better way to celebrate than showcasing our creative talented and passionate Buffs!
We had so much fun yesterday at the Be Involved Fair!
Yesterday was such a beautiful start to the new school year
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>4</b>
Enter a post author:
<b>chipthebuffalo</b>
Enter a user name:
<b>michelleryan</b>
Enter a post id:
<b>4</b>
michelleryan liked the post posted by chipthebuffalo 8 times
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>5</b>
Enter a tag:
<b>se</b>
Here are all the usernames that contain se<br>
caseymac
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>6</b>
Enter a post body:
<b>Snow Day!!!</b>
Enter a post author:
<b>spiritedMues</b>
Enter a date(mm/dd/yy):
<b>10/25/22</b>
spiritedMues's post added successfully
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>7</b>
Enter the number of posts:
<b>2</b>
Enter the year(YY):
<b>22</b>
Top 2 posts for year 22
23 likes: We had so much fun yesterday at the Be Involved Fair!
51 likes: Yesterday was such a beautiful start to the new school year
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>8</b>
pacifiedIcecream7 is the least active user
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>9</b>
Enter a post author:
<b>chipthebuffalo</b>
The posts posted by chipthebuffalo have been liked by 3 unique users.
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>99</b>
Invalid input
======Main Menu=====
1. Read Posts 
2. Print Posts By Year 
3. Read Likes
4. Get Likes  
5. Find users with matching tag
6. Add a new post
7. Print popular posts for a year
8. Find least active user
9. Find unique likes for a post author
10. Quit
<b>10</b>
Good bye!
</pre></code>


# Project 2 Part 2 Overview <a name="overview"></a>

## Checklist <a name="checklist"></a>

Here is a checklist for completing the project:
To compile in the terminal, use the following command: `g++ -std=c++17 project2pt2.cpp Post.cpp User.cpp Buffchat.cpp` If your code does not compile with this command, you will lose points on your Canvas submission.
1. Use the solutions you created in VSCode to complete the assignment **Project 2 Part 2 - CodeRunner** on Canvas (modules -> week 10)
2. Submit one zip file to the **Project 2 Part 2** assignment on Canvas. The zip file should be named **project2part2_lastname.zip**. Recall that each `Driver` file contains a `main` function testing the functionality for the corresponding problem. The zip file should contain 10 files:
    * Post.h (from Project 2 Part 1)
    * Post.cpp (from Project 2 Part 1)
    * postDriver.cpp (from Project 2 Part 1)
    * User.h (from Project 2 Part 1)
    * User.cpp (from Project 2 Part 1)
    * userDriver.cpp (from Project 2 Part 1)
    * Buffchat.h
    * Buffchat.cpp
    * buffchatDriver.cpp
    * project2pt2.cpp
3. You may need to create external data files to test your functions. Add any external files that are required for your assertions to pass to the zip submission.


## Grading Rubric <a name = "grading"></a>

Note that Coderunner for Project 2 Part 2 has only four questions--two questions for the Buffchat class and two for the main function driving the menu.

| **Criteria**                    | Points |
|:--------------------------------|-------:|
| Question 0                      |     35 |
| Question 1                      |      0 |
| Question 2                      |      0 |
| Question 3                      |      0 |
| Question 4                      |      0 |
| Question 5                      |      0 |
| Question 6                      |      0 |
| Question 7                      |      0 |
| Question 8                      |      0 |
| Question 9                      |     10 |
| C++ files zip submission        |     15 |
| Recitation attendance (Week 10)* |   -15 |
| **Total**                       | **60** |

*If your attendance is not recorded, you will lose points. Make sure your attendance is recorded correctly on Canvas.