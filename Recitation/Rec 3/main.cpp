#include<iostream>
using namespace std;

int main() {
    int selection = 0;

    cout << "The following are your options in the jukebox:" << endl;
    cout << "1. As It Was by Harry Styles " << endl;
    cout << "2. I Ain't Worried by OneRepublic" << endl;
    cout << "3. Pink Venon by BlackPink" << endl;
    cout << "4. Vegas by Doja Cat" << endl;
    cout << "5. About Damn Time by Lizzo" << endl;
    cout << "6. Light Switch by Charlie Puth" << endl;
    cout << "Please choose an item" << endl;

    cin >> selection;

    switch(selection) {
        case 1:
            cout << "You selected As It Was by Harry Styles!" << endl;
            break;
        case 2:
            cout << "You selected I Ain’t Worried by OneRepublic!" << endl;
            break;
        case 3:
            cout << "You selected  Pink Venon by BlackPink!" << endl;
            break;
        case 4:
            cout << "You selected Vegas by Doja Cat" << endl;
            break;
        case 5:
            cout << "You selected About Damn Time by Lizzo!" << endl;
            break;
        case 6:
            cout << "You selected Light Switch by Charlie Puth!" << endl;
            break;
    }
}