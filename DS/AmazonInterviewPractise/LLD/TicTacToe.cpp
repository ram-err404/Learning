/*
  Requirements:
  ------------
  1.) Need 1 board.
  2.) Need minimum 2 players to play.
  3.) If can choose zero (0) and other can choose cross (X).
  4.) Declare result.
*/

#include<bits/stdc++.h>
using namespace std;

class TicTacToe {
  Board     board;
  Player    player1, player2;
public:
  Winner playGame();
};

class Board {
  int                     boardId;
  vector<vector<char>>    board(3, vector<char>(3));
  const int               MAX_MOVE=3*3;
  int                     totalMove=0;
public:
  void  makeMove(int row, int col, char val);
  bool  isValidMove(int row, int col);
  bool  hasPlayerWon(char val);
};

class Player {
  int       playerId;
  string    playerName;
  Stats     stats;
  char      piece;  // { either 0 or X }
};

class Stats{
  long  totalMatchesPlayed;
  long  totalMatchesWon;
};

class Winner: public Player{
  Board   boardInfo;
};