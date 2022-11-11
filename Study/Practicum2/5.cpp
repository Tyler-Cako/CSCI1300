#include <iostream>

using namespace std;

void do_math(int x, int y, int z)
{
    if (x < y)
    {
        x = x * 3;
        y = y + 2;
    }
    else if (x < z)
    {
        x = x + 3;
        z = z/2;
    }
    else{
        x--;
        y++;
        z++;
    }
    if (y > z)
    {
        y--;
        x++;
    }
}

int main()
{
    int x_num = 4, y_num = 8, z_num = 13;
    do_math(x_num, y_num, z_num);
    cout << x_num << endl;
}