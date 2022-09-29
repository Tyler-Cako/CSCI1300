#include <iostream>
#include <string>
using namespace std;

string concatenate(string a, int b);

int main()
{
    cout << concatenate("csci", 1300) << endl;
    return 0;
}

string concatenate(string a, int b)
{
    string c = a + to_string(b);
	return c;
}
