
// tic.cpp -- a tic tac toe console game implemented in C++

#include <iostream>
#include "stdlib.h"

using namespace std;

#define MAXGAMEMOVES 9

// struct representing the board
typedef struct {
  
  char spaces[9];
  int moves;
  int turn;
  bool win;

} board;

// map to help print out the board


// function prototypes
void printboard(board b);
bool checkmove(board b, int move);
int getmove(board b);
bool checkwin(board b);

int main(void)
{
  
  board play_board;
  
  play_board.spaces[0] = '1';
  play_board.spaces[1] = '2';
  play_board.spaces[2] = '3';
  play_board.spaces[3] = '4';
  play_board.spaces[4] = '5';
  play_board.spaces[5] = '6';
  play_board.spaces[6] = '7';
  play_board.spaces[7] = '8';
  play_board.spaces[8] = '9';

  play_board.moves = 0;
  play_board.turn = 0;
  play_board.win = false;
  
  char player;
  int move;
  while (play_board.moves < MAXGAMEMOVES) {
    
    if (checkwin(play_board)) { play_board.win = true; break; }
    
    if (play_board.turn == 0) { player = 'X'; }
    else { player = 'O'; }
    
    printboard(play_board);
    move = getmove(play_board);
    
    play_board.spaces[move] = player;
    play_board.moves++;
    
    play_board.turn ^= 1;
    
  }
  
  printboard(play_board);
  
  if (play_board.win == true) {
    cout << "Congratulations " << player << "!" << endl;
  }
  else { cout << "draw game" << endl; }
  
  return 0;
}

void printboard(board b)
{
 
  system("clear");
  
  cout << "+---+---+---+\n";
  int counter = 0;
  for (int i = 0; i < 3; i++) {
   cout << "| ";
   cout << b.spaces[counter];
   counter++;
   cout << " | ";
   cout << b.spaces[counter];
   counter++;
   cout << " | ";
   cout << b.spaces[counter];
   counter++;
   cout << " |\n";
   cout << "+---+---+---+\n";
  }
  
}

int getmove(board b)
{
 
  int move;
  do {
    cout << "input move: ";
    cin >> move;
    move -= 1;
  } while (checkmove(b, move) != true);
  
  return move;
  
}

bool checkmove(board b, int move)
{
 
  if (move > 8 || move < 0) { return false; }
  if (b.spaces[move] == 'X' || b.spaces[move] == 'O') { return false; }
  return true;
  
}

bool checkwin(board b)
{
  
  if (b.spaces[0] == b.spaces[1] && b.spaces[1] == b.spaces[2]) { return true; }
  if (b.spaces[3] == b.spaces[4] && b.spaces[4] == b.spaces[5]) { return true; }
  if (b.spaces[6] == b.spaces[7] && b.spaces[7] == b.spaces[8]) { return true; }
  if (b.spaces[0] == b.spaces[3] && b.spaces[3] == b.spaces[6]) { return true; }
  if (b.spaces[1] == b.spaces[4] && b.spaces[4] == b.spaces[7]) { return true; }
  if (b.spaces[2] == b.spaces[5] && b.spaces[5] == b.spaces[8]) { return true; }
  if (b.spaces[0] == b.spaces[4] && b.spaces[4] == b.spaces[8]) { return true; }
  if (b.spaces[2] == b.spaces[4] && b.spaces[4] == b.spaces[6]) { return true; }
  return false;
 
  
}

