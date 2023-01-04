//Name: Jeffrey Mitchell
//Student ID: 5746333

#include <iostream>
#include <string>
#include "game.h"
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    string player1, player2;
    bool singlePlayer = false;
    int maxPiles = 15, maxStones = 15;
    vector<int> gameBoard;
    char playing = 'y';
    bool p1Turn = true;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            cout << "Usage: ./take-away [-h] [-c] [-p # piles] [-s # stones]" << endl;
            cout << "\nOptions: " << endl;
            cout << "\t-h Show this text." << endl;
            cout << "\t-c Make player two the computer. Default = false." << endl;
            cout << "\t-p Manually set the starting number of piles in the game." << endl;
            cout << "\t-s Manually set the starting number of stones in each pile." << endl;
            cout << "\n\tMax values for piles and stones: 15" << endl;
            cout << "\tMin values for piles and stones: 1" << endl;
            return 0;
        }
        else if (strcmp(argv[i], "-c") == 0)
        {
            singlePlayer = true;
        }
        else if (strcmp(argv[i], "-p") == 0)
        {
            maxPiles = stoi(argv[i + 1]);
            if (maxPiles < 1)
            {
                cout << "Invalid number of piles, terminating program.";
            }
        }
        else if (strcmp(argv[i], "-s") == 0)
        {
            maxStones = stoi(argv[i + 1]);
            if (maxStones < 1)
            {
                cout << "Invalid number of piles, terminating program.";
            }
        }
    }
    getNames(player1, player2, singlePlayer);
    if (singlePlayer == false)
    {
        while (playing == 'y')
        {
            gameBoard = generateBoard(maxPiles, maxStones);
            printBoard(gameBoard);
            while (takeTurn(gameBoard, p1Turn, player1, player2) == false)
            {
                printBoard(gameBoard);
            }

            cout << "\nGame over keep playing? y/n" << endl;
            cin >> playing;
        }
    }
    else
    {
        while (playing == 'y')
        {
            gameBoard = generateBoard(maxPiles, maxStones);
            printBoard(gameBoard);
            while (takeTurnSP(gameBoard, p1Turn, player1, player2) == false)
            {
                printBoard(gameBoard);
            }

            cout << "\nGame over keep playing? y/n" << endl;
            cin >> playing;
            p1Turn = true;
        }
    }
    
   

}
