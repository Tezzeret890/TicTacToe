#pragma once

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

char PlayTTT();
void SetBoard(char *** board, int r, int c, int w, int h);
char PlayComp();
void FindAvailable(char*** board, int r, int c, int w, int h, int * spacesAvailable);
void Player1Turn(char *** board, int r, int c, int w, int h, int * spacesAvailable);
void Player2Turn(char *** board, int r, int c, int w, int h, int * spacesAvailable);
void ComputerTurn(char*** board, int r, int c, int w, int h, int* spacesAvailable, int turn);
void ComputerTurn1(char*** board, int r, int c, int w, int h, int* spacesAvailable, int turn);
int  CheckXWin(int * spacesAvailable);
int  CheckOWin(int * spacesAvailable);
void MatchResult(int win, char playingComputer);
char returnChar(int space);
void ClearScreen();
void SetScreen(char *** board, int w, int h);