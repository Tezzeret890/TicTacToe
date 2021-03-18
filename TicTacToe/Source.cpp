/*  September 14, 2020
	David Tebo
	Coding Practice #1: Tic Tac Toe

	First iteration will run a command console text version of the game, should be easy.
	Afterwards going to try to implement a GUI solution ontop of it.
*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>

#include"Header.h"



int main() {

	char playingComputer;
	int win = 0;
	int turns = 0;

	char *** board;
	int r = 3, c = 3;
	int w = 5, h = 5;

	board = (char***)calloc(r, sizeof(char**));
	for (int i = 0; i < c; ++i) {
		board[i] = (char**)calloc(c, sizeof(char*));
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			board[i][j] = (char*)calloc(w * h, sizeof(char));
		}
	}

	int spacesAvailable[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 , -1};

	while (PlayTTT() == 'y') {
		ClearScreen();
		SetBoard(board, r, c, w, h);
		playingComputer = PlayComp();
		win = 0;
		turns = 0;

		if (playingComputer == 'y') {

			while (1) {
				SetScreen(board, w, h);
				Player1Turn(board, r, c, w, h, spacesAvailable);
				++turns;
				win = CheckXWin(spacesAvailable);
				if (win > 0) break;

				if (turns == 9) break;

				SetScreen(board, w, h);
				ComputerTurn(board, r, c, w, h, spacesAvailable, turns);
				++turns;
				win = CheckOWin(spacesAvailable);
				if (win > 0) break;
			}

			SetScreen(board, w, h);
			MatchResult(win, playingComputer);
		}
		else {

			while (1) {
				SetScreen(board, w, h);
				Player1Turn(board, r, c, w, h, spacesAvailable);
				++turns;
				win = CheckXWin(spacesAvailable);
				if (win > 0) break;

				if (turns == 9) break;

				SetScreen(board, w, h);
				Player2Turn(board, r, c, w, h, spacesAvailable);
				++turns;
				win = CheckOWin(spacesAvailable);
				if (win > 0) break;
			}

			SetScreen(board, w, h);
			MatchResult(win, playingComputer);
		}

	}

	std::cout << "\n\n\tThanks for playing!!!\n\n";

	
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			free(board[i][j]);
		}
	}
	for (int i = 0; i < c; ++i) {
		free(board[i]);
	}
	free(board);

	return 0;
}