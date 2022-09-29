#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "";

    cout << "Input a string" << endl;
    getline(cin, word);

    for (int i = 0; i < word.length(); i++){
        char index = word[i];

        if(index != 32 && index >= 97 && index <= 122) {
            word[i] -= 32;
        }
    }

    cout << word << endl;

    return 0;
}