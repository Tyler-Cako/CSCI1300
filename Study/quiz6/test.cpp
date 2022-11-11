#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
    ifstream read_file;
    string name = "";
    int score = 0;
    read_file.open("Scores.txt");
    read_file >> name >> score;
    read_file >> name >> score;
}