#include <iostream>
#include <string>
#include <vector>

using namespace std;


/* Algorithim
    1. Initialize variables
    2. Continuously ask for user input until the user enters 14 (joker)
    3. For every input, check if valid input.
    4. If valid, check if card is ace, royal card or joker.
        1. If ace, 
            1. if at least 2 elements in hand
                1. Remove first 2 elements
                2. counter += 2
            2. if 1 elements
                1. Remove first element
                2. counter++
        2. If royal,
            1. Two elements
                1. Remove last 2 elements
                2. counter += 2
            2. one elements
                1. remove last element
                2. counter++
        3. if joker
            1. remove joker from hand
            2. Exit loop
    5. Finally print all necessary text and compare counter to hand vector size to determine who wins
*/
void cardGame()
{
    vector<int> hand;
    int counter = 0;
    bool input_done = false;

    // Remove number abstraction
    int ace = 1;
    int jack = 11;
    int queen = 12;
    int king = 13;
    int joker = 14;

    while(input_done == false)
    {
        int card;
        cout << "Please enter a number:" << endl;
        cin >> card;
        if (card == 1 || card == 2 || card == 3 || card == 4 || card == 5 || card == 6 || card == 7 || card == 8 || card == 9 || card == 10 || card == 11 || card == 12 || card == 13 || card == 14)
        {
            hand.push_back(card);  

            if (card == ace)
            {
                //cout << "ace" << hand.size();
                if (hand.size() >= 2)
                {
                    hand.erase(hand.begin(), hand.begin() + 2);
                    counter += 2;
                }
                else 
                {
                    hand.erase(hand.begin());
                    counter++;
                }

            } 

            if (card == jack || card == queen || card == king)
            {
                if (hand.size() >= 2)
                {
                    hand.pop_back();
                    hand.pop_back();
                    counter += 2;
                }
                else
                {
                    hand.pop_back();
                    counter++;
                }
            }
            if (card == joker)
            {
                hand.pop_back();
                input_done = true;
            }
        }
        else
        {
            cout << "The number should be an integer between 1 and 14." << endl;
        }
    }

    cout << "Your cards remaining are: ";
    for (int i = 0; i < hand.size(); i++)
    {
        cout << hand.at(i) << " ";
    }
    cout << endl;

    cout << "I have " << counter << " card(s)." << endl;

    if (counter > hand.size())
    {
        cout << "I win!" << endl;
    }
    if (counter < hand.size())
    {
        cout << "You win!" << endl;
    }
    if (counter == hand.size())
    {
        cout << "Tie!" << endl;
    }
}

int main()
{
    /* Standard case
    Inputs: 11 8 7 3 12 4 5 13 14
    Expected output:
        Your cards remaining are: 8 7 4
        I have 5 card(s).
        I win!
    */
    cardGame();

    /* Enter just joker
    Inputs: 14
    Expected output:
    Your remaining cards are: 
    I have 0 card(s).
    Tie!    
    */

    cardGame();

   /* Opponent wins:
    Inputs: 1 14
    Expected results: 
    Your remaining cards are:
    I have 1 card(s)
    I win!
   */
    cardGame();

    /* Enter wrong input, but everything else the same as another test should output the same output.
        Inputs: 11 8 7 3 12 4 5 -1 13 14
        Expected output:
        The number should be an integer between 1 and 14.
        Your cards remaining are: 8 7 4
        I have 5 card(s).
        I win!
    */
}