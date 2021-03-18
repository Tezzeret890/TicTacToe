#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<Windows.h>

#include"Header.h"

double PI = 3.14159265;

char PlayTTT() {

	char answer;

	std::cout << "\n\n\tDo you want to play a game of Tic Tac Toe?\n";
	std::cout << "\t[y] yes\t\t[n] no\n\n\t";

	std::cin >> answer;

	while (answer != 'y' && answer != 'n') {
		std::cout << "\n\n\tPlease input a valid response: 'y' or 'n' then ENTER\n\n\t";
		std::cin >> answer;
	}

	std::cout << "\n\n";

	return answer;

}

void SetBoard(char *** board, int r, int c, int w, int h) {

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			for (int k = 0; k < w * h; ++k) {

				if (k != (int)floor((w * h)/ 2))
					board[i][j][k] = ' ';
				else
					board[i][j][k] = returnChar((i * 3) + j + 1);
			}
		}
	}

}

char PlayComp() {

	char response;
	std::cout << "\n\n\tDo you want to play the computer?[y OR n]: ";
	std::cin >> response;

	while (response != 'y' && response != 'n') {
		std::cout << "\n\n\tPlease make a valid selection: 'y' or 'n' then ENTER: ";
		std::cin >> response;
	}

	return response;
}

void Player1Turn(char *** board, int r, int c, int w, int h, int * spacesAvailable) {

	FindAvailable(board, r, c, w, h, spacesAvailable);

	int choice;

	std::cout << "\n\n\tPlayer 1, please ENTER a number that corresponds with an available space (listed bleow)";
	std::cout << "\n\t";
	for (int i = 1; i <= 9; ++i) {
		if (spacesAvailable[i - 1] <= 9)
			std::cout << i << "  ";
	}
	std::cout << "\n\n\tSelection: ";
	std::cin >> choice;

	if (choice < 1 || choice > 9) {
		std::cout << "\n\tInvalid error prone choice";
		choice = 10;
	}

	while (spacesAvailable[choice - 1] != choice || choice == 10) {
		std::cout << "\n\n\tPlease make a valid choice from the numbers above\n\tPress the number key then ENTER: ";
		std::cin >> choice;

		if (choice < 1 || choice > 9) {
			std::cout << "\n\tInvalid error prone choice";
			choice = 10;
		}
	};

	spacesAvailable[choice - 1] = 88;

	double slope1;
	double slope2;

	slope1 = (-(h - 1) - 0) /(double) (((double)w - 1) - 0);
	slope2 = (0 - -((double)h - 1)) /(double) (((double)w - 1) - 0);

	double targetSlope1, targetSlope2;

	double theta1 = -45.0, theta2 = 45.0;
	double hypotenuse3, hypotenuse4, distanceFromXLine;

	double tolerance = pow(w * h, 0.1) /(double) 2;

	for (int i = 0; i < w * h; ++i) {

		//the .01 makes what would normally be no slope and vertical slopes 0 slope and slope in the factor of hundreds
		targetSlope1 = (-(int)floor(i / w) - 0) /(double) ((i % w) - 0 + 0.01);
		targetSlope2 = (-(double)floor(i / w) - -(h - 1)) /(double) ((i % w) - 0 + 0.01);

		if ((targetSlope1 <= slope1 * 1.1 && targetSlope1 >= slope1 * 0.9) || (targetSlope2 <= slope2 * 1.1 && targetSlope2 >= slope2 * 0.9))
			board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = 'X';			//Occurs along line
		else if (targetSlope1 == 0 && (targetSlope2 >= 100 || targetSlope2 == 0))
			board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = 'X';			//top left starting spot (slope1)
		else if (targetSlope2 == 0 && (targetSlope1 <= -100 || targetSlope1 == 0))
			board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = 'X';			//bottom right starting spot (slope2)


		else {
			//Looking for spaces that are close to the top left to bottom right X diagonal
			if (targetSlope1 < slope1) {

				theta1 = -atan(slope1);
				theta2 = PI /(double) 2 - theta1;

				hypotenuse3 = (i % w) /(double) cos(theta1);
				hypotenuse4 = abs(hypotenuse3 * sin(theta1) - ((int)floor(i /(double) w)));
				distanceFromXLine = hypotenuse4 * cos(theta1);

				if (distanceFromXLine <= tolerance) {
					board[(int)floor(((double)choice - 1) / (double)3)][(choice - 1) % 3][i] = 'X';
					continue;
				}
				else
					board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = ' ';

			}
			if (targetSlope1 >= slope1) {

				theta1 = -atan(slope1);
				theta2 = PI /(double) 2 - theta1;

				hypotenuse3 = (i % w) /(double) cos(theta1);
				hypotenuse4 = hypotenuse3 * sin(theta1) - ((int)floor(i /(double) w));
				distanceFromXLine = hypotenuse4 * cos(theta1);

				if (distanceFromXLine <= tolerance) {
					board[(int)floor(((double)choice - 1) / (double)3)][(choice - 1) % 3][i] = 'X';
					continue;
				}
				else
					board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = ' ';
			}

			//Looking for spaces that are close to the bottom left to top right X diagonal
			if (targetSlope2 < slope2) {

				theta1 = atan(slope2);
				theta2 = PI /(double) 2 - theta1;

				hypotenuse3 = (i % w) /(double) cos(theta1);
				hypotenuse4 = hypotenuse3 * sin(theta1) - (h - ((double)floor(i /(double) w)) - 1);
				distanceFromXLine = hypotenuse4 * cos(theta1);

				if (distanceFromXLine <= tolerance) {
					board[(int)floor(((double)choice - 1) / (double)3)][(choice - 1) % 3][i] = 'X';
					continue;
				}
				else
					board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = ' ';

			}
			if (targetSlope2 >= slope2) {

				theta1 = atan(slope2);
				theta2 = PI / (double)2 - theta1;

				hypotenuse3 = (i % w) /(double) cos(theta1);
				hypotenuse4 = h - hypotenuse3 * sin(theta1) - ((int)floor(i /(double) w)) - 1;
				distanceFromXLine = hypotenuse4 * cos(theta1);

				if (distanceFromXLine <= tolerance) {
					board[(int)floor(((double)choice - 1) / (double)3)][(choice - 1) % 3][i] = 'X';
					continue;
				}
				else
					board[(int)floor(((double)choice - 1) /(double) 3)][(choice - 1) % 3][i] = ' ';
			}
		}
	}

}

void Player2Turn(char*** board, int r, int c, int w, int h, int* spacesAvailable) {

	FindAvailable(board, r, c, w, h, spacesAvailable);

	int choice;

	std::cout << "\n\n\tPlayer 2, please ENTER a number that corresponds with an available space (listed bleow)";
	std::cout << "\n\t";
	for (int i = 1; i <= 9; ++i) {
		if (spacesAvailable[i - 1] <= 9)
			std::cout << i << "  ";
	}
	std::cout << "\n\n\tSelection: ";
	std::cin >> choice;

	if (choice < 1 || choice > 9) {
		std::cout << "\n\tInvalid error prone choice";
		choice = 10;
	}

	while (spacesAvailable[choice - 1] != choice || choice == 10) {
		std::cout << "\n\n\tPlease make a valid choice from the numbers above\n\tPress the number key then ENTER: ";
		std::cin >> choice;

		if (choice < 1 || choice > 9) {
			std::cout << "\n\tInvalid error prone choice";
			choice = 10;
		}
	}

	spacesAvailable[choice - 1] = 79;

	int verticalWidth = (int)floor(pow(h, 0.33));
	int horizontalWidth = (int)floor(pow(w, 0.33));

	for (int i = 0; i < w * verticalWidth; ++i) {
		board[(int)floor((choice - 1) / 3)][(choice - 1) % 3][i] = 'O';
	}
	for (int i = w * h - 1; i >= (w * h) - (w * verticalWidth); --i) {
		board[(int)floor((choice - 1) / 3)][(choice - 1) % 3][i] = 'O';
	}

	for (int i = 0; i < w * h; ++i) {
		if ((i % w) < horizontalWidth || (i % w) >= (w - horizontalWidth))
			board[(int)floor((choice - 1) / 3)][(choice - 1) % 3][i] = 'O';
	}

	board[(int)floor((choice - 1) / 3)][(choice - 1) % 3][(int)floor((w * h) / 2)] = ' ';

}


void FindAvailable(char*** board, int r, int c, int w, int h, int * spacesAvailable) {

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (board[i][j][(int)floor((w * h) / 2)] == '1' || board[i][j][(int)floor((w * h) / 2)] == '2' || board[i][j][(int)floor((w * h) / 2)] == '3' || board[i][j][(int)floor((w * h) / 2)] == '4' || board[i][j][(int)floor((w * h) / 2)] == '5' || board[i][j][(int)floor((w * h) / 2)] == '6' || board[i][j][(int)floor((w * h) / 2)] == '7' || board[i][j][(int)floor((w * h) / 2)] == '8' || board[i][j][(int)floor((w * h) / 2)] == '9')
				spacesAvailable[(i * 3) + j] = (i * 3) + j + 1;
			else if (board[i][j][0] == 'X')
				spacesAvailable[(i * 3) + j] = 88;  //ascii for X
			else
				spacesAvailable[(i * 3) + j] = 79;  //ascii for O
		}
	}
	
}

int CheckXWin(int * spacesAvailable) {

	//Checking for vertical column wins
	for (int i = 0; i < 3; ++i) {
		if (spacesAvailable[0 + i] == 88 && spacesAvailable[3 + i] == 88 && spacesAvailable[6 + i] == 88)
			return 1;
	}
	//Checking for horizontal row wins
	for (int i = 0; i < 3; ++i) {
		if (spacesAvailable[0 + i*3] == 88 && spacesAvailable[1 + i*3] == 88 && spacesAvailable[2 + i*3] == 88)
			return 1;
	}
	//Checking for diagonal wins
	if (spacesAvailable[0] == 88 && spacesAvailable[4] == 88 && spacesAvailable[8] == 88)
		return 1;
	if (spacesAvailable[2] == 88 && spacesAvailable[4] == 88 && spacesAvailable[6] == 88)
		return 1;

	return 0;
}

int CheckOWin(int * spacesAvailable) {

	//Checking for vertical column wins
	for (int i = 0; i < 3; ++i) {
		if (spacesAvailable[0 + i] == 79 && spacesAvailable[3 + i] == 79 && spacesAvailable[6 + i] == 79)
			return 2;
	}
	//Checking for horizontal row wins
	for (int i = 0; i < 3; ++i) {
		if (spacesAvailable[0 + i * 3] == 79 && spacesAvailable[1 + i * 3] == 79 && spacesAvailable[2 + i * 3] == 79)
			return 2;
	}
	//Checking for diagonal wins
	if (spacesAvailable[0] == 79 && spacesAvailable[4] == 79 && spacesAvailable[8] == 79)
		return 2;
	if (spacesAvailable[2] == 79 && spacesAvailable[4] == 79 && spacesAvailable[6] == 79)
		return 2;

	return 0;
}

void MatchResult(int win, char playingComputer) {

	if (win == 0)
		std::cout << "\n\n\tIt's a tie! Good match!!";
	else if (win == 1)
		std::cout << "\n\n\tCongrats Player 1! You have won this match of Tic Tac Toe!";
	else
		if (playingComputer == 'n')
			std::cout << "\n\n\tCongrats Player 2! You have won this match of Tic Tac Toe!";
		else {
			std::cout << "\n\n\tI have beaten you in Tic Tac Toe you foolish human\n\n";
			Sleep(1000);
			std::cout << "MU";
			for (int i = 0; i < 180; ++i) {
				if (i % 2 == 0) {
					Sleep(17);
					std::cout << "A";
				}
				if (i % 2 == 1) {
					Sleep(17);
					std::cout << "H";
				}
			}
		}
}

char returnChar(int space) {
	return (char)(space + 48);
}

void ClearScreen() {
	system("CLS");
	std::cout << std::flush;
	system("CLS");
	std::cout << "\n";
}

void SetScreen(char*** board, int w, int h) {

	ClearScreen();

	int Space;

	if (w >= 2 && h >= 2)
		Space = 2;
	else 
		Space = 1;

	for (int i = 0; i < (3 * w) + 2 * Space; ++i) {
		
	}

	std::cout << "\n\n";

	for (int k = 0; k < 3; ++k) {

		for (int i = 0; i < h; ++i) {
			std::cout << "\t";
			for (int j = 0; j < w; ++j)
				std::cout << board[k][0][j + i * w];
			for (int j = 0; j < Space; ++j)
				std::cout << "|";
			for (int j = 0; j < w; ++j)
				std::cout << board[k][1][j + i * w];
			for (int j = 0; j < Space; ++j)
				std::cout << "|";
			for (int j = 0; j < w; ++j)
				std::cout << board[k][2][j + i * w];
			std::cout << "\n";
		}
		if (k != 2) {
			std::cout << "\t";
			for (int i = 0; i < (3 * w); ++i) {
				std::cout << "-";
				if ((i+1) % w == 0 && i > 0 && i < (3 * w) - 1) {
					if (Space == 1)
						std::cout << "+";
					else
						std::cout << "++";
				}
			}
			std::cout << "\n";
			if (Space == 2) {
				std::cout << "\t";
				for (int i = 0; i < (3 * w); ++i) {
					std::cout << "-";
					if ((i+1) % w == 0 && i > 0 && i < (3 * w) - 1) {
						if (Space == 1)
							std::cout << "+";
						else
							std::cout << "++";
					}
				}
				std::cout << "\n";
			}
		}


	}

	std::cout << "\n\n\t";
}