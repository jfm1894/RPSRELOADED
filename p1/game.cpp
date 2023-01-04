#include "game.h"
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

void getNames(string& name1, string& name2, bool gameState)
{
    cout << "First player name: " << endl;
    getline(cin, name1);
    if (gameState == false)
    {
        cout << "Second player name: " << endl;
        getline(cin, name2);
    }
    else
    {
        name2 = "Noob Smasher 9001";
    }
}

vector<int> generateBoard(int mPiles, int mStones)
{
    srand(time(0));
    vector<int> gameBoard((rand() % mPiles)+2);
    for (int i = 0; i < gameBoard.size(); i++)
    {
        gameBoard.at(i) = (rand() % mStones) + 1;
    }
    return gameBoard;
}

void printStones(int numStones)
{
    for (int i = 0; i < numStones; i++)
    {
        cout << "*";
    }
}

void printBoard(vector<int>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        cout << "\nPile: " << i << " [" << board.at(i) << "]: ";
        printStones(board.at(i));
    }
}

bool takeTurn(vector<int>& board, bool& turn, string p1, string p2)
{
    int pile, stones;
    bool gameover = false;
    
    if (turn == true)
    {
        cout << "\n" << p1 << "'s turn" << endl;
    }
    else
    {
        cout << "\n" << p2 << "'s turn" << endl;
    }
    cout << "Enter a pile to take from:" << endl;
    cin >> pile;
    while (pile <0 or pile > board.size() - 1)
    {
        cout << "Invalid pile, please select a pile that actually exists." << endl;
        cin >> pile;
    }
    cout << "Enter how many stones to take" << endl;
    cin >> stones;
    while (stones <1 or stones > board.at(pile))
    {
        cout << "Invalid number of stones, please enter a number of stones that actually exists." << endl;
        cin >> stones;
    }
    board.at(pile) = board.at(pile) - stones;
    for (int i = 0; i < board.size(); i++)
    {
        if (board.at(i) == 0)
        {
            board.erase(board.begin()+i);
        }
    }
    if (board.empty() == true)
    {
        gameover = true;
        if (turn == true)
        {
            cout << p1 << " has won the game!" << endl;
        }
        else
        {
            cout << p2 << " has won the game!" << endl;
        }
    }
    turn = !turn;
    return gameover;

}

bool takeTurnSP(vector<int>& board, bool& turn, string p1, string p2)
{
    int pile, stones;
    bool gameover = false;

    if (turn == true)
    {
        cout << "\n" << p1 << "'s turn" << endl;
        cout << "Enter a pile to take from:" << endl;
        cin >> pile;
        while (pile <0 or pile > board.size() - 1)
        {
            cout << "Invalid pile, please select a pile that actually exists." << endl;
            cin >> pile;
        }
        cout << "Enter how many stones to take" << endl;
        cin >> stones;
        while (stones <1 or stones > board.at(pile))
        {
            cout << "Invalid number of stones, please enter a number of stones that actually exists." << endl;
            cin >> stones;
        }
        board.at(pile) = board.at(pile) - stones;
        for (int i = 0; i < board.size(); i++)
        {
            if (board.at(i) == 0)
            {
                board.erase(board.begin() + i);
            }
        }
    }
    else
    {
        cout << "\n" << p2 << "'s turn" << endl;
        int rPile, rStone, nim;
        nim = evaluateBoard(board);
        if (nim == 0)
        {
            rPile = whichPile(board, nim);
            rStone = howMany(board, nim, rPile);
        }
        else
        {
            srand(time(0));
            rPile = rand() % board.size();
            rStone = rand() % board.at(rPile) + 1;
        }
        board.at(rPile) = board.at(rPile) - rStone;
        cout << p2 << " removed " << rStone << " stones from pile " << rPile << endl;
        for (int i = 0; i < board.size(); i++)
        {
            if (board.at(i) == 0)
            {
                board.erase(board.begin() + i);
            }
        }
    }

    if (board.empty() == true)
    {
        gameover = true;
        if (turn == true)
        {
            cout << p1 << " has won the game!" << endl;
        }
        else
        {
            cout << p2 << " has won the game!" << endl;
        }
    }
    turn = !turn;
    return gameover;
}

int evaluateBoard(vector<int> board)
{
    int nim_sum=0;
    if (board.size() == 1)
    {
        nim_sum = 0;
    }
    else
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (i == 0)
            {
                nim_sum = board.at(i);
            }
            else
            {
                nim_sum = nim_sum ^ board.at(i);
            }
        }
    }
    return nim_sum;
}

int howMany(vector<int>board, int nim, int pile)
{
    int stoneAmount = 0;
    if (board.size() == 1)
    {
        stoneAmount = board.at(0);
    }
    else
    {
        stoneAmount = board.at(pile) - (board.at(pile) ^ nim);
    }
    return stoneAmount;
}

int whichPile(vector<int>board, int nim)
{
    int pile = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if ((board.at(i) ^ nim) < board.at(i))
        {
            pile = i;
        }
    }
    return pile;
}
