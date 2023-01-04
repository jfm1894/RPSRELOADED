#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void getNames(string& name1,string& name2, bool gameState);
vector<int> generateBoard(int mPiles, int mStones);
void printStones(int numStones);
void printBoard(vector<int>& board);
bool takeTurn(vector<int>& board, bool& turn, string p1, string p2);
bool takeTurnSP(vector<int>& board, bool& turn, string p1, string p2);
int evaluateBoard(vector<int> board);
int howMany(vector<int>board, int num, int pile);
int whichPile(vector<int>board, int nim);





#endif
