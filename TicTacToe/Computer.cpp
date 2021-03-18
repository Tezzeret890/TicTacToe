#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<Windows.h>

#include"Header.h"


void ComputerTurn(char*** board, int r, int c, int w, int h, int* spacesAvailable, int turn) {

	FindAvailable(board, r, c, w, h, spacesAvailable);

	int choice, chance;

	choice = -1;

	//COMPUTER TURN ONE
	if (turn == 1 && (spacesAvailable[1] == 88 || spacesAvailable[3] == 88 || spacesAvailable[5] == 88 || spacesAvailable[7] == 88))
		choice = 5;
	else if (turn == 1 && (spacesAvailable[0] == 88 || spacesAvailable[2] == 88 || spacesAvailable[6] == 88 || spacesAvailable[8] == 88)) {
		choice = 5;
	}
	else if (turn == 1 && spacesAvailable[4] == 88) {
		chance = rand() % 4;
		if (chance == 0)
			choice = 1;
		if (chance == 1)
			choice = 3;
		if (chance == 2)
			choice = 7;
		if (chance == 3)
			choice = 9;
	}

	//COMPUTER TURN TWO
	else if (turn == 3) {

		choice = -1;

		//Defensive Actions
		if (spacesAvailable[4] == 88) {
			if (spacesAvailable[0] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			else if (spacesAvailable[1] == 88 && spacesAvailable[7] == 8)
				choice = 8;
			else if (spacesAvailable[2] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			else if (spacesAvailable[3] == 88 && spacesAvailable[5] == 6)
				choice = 6;
			else if (spacesAvailable[5] == 88 && spacesAvailable[3] == 4)
				choice = 4;
			else if (spacesAvailable[6] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			else if (spacesAvailable[7] == 88 && spacesAvailable[1] == 2)
				choice = 2;
			else if (spacesAvailable[8] == 88 && spacesAvailable[0] == 1)
				choice = 1;
		}
		if (spacesAvailable[0] == 88) {
			if (spacesAvailable[1] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[3] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[2] == 88 && spacesAvailable[1] == 2)
				choice = 2;
			if (spacesAvailable[6] == 88 && spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[8] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[2] == 88) {
			if (spacesAvailable[1] == 88 && spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[5] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 88 && spacesAvailable[5] == 6)
				choice = 6;
			if (spacesAvailable[6] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[6] == 88) {
			if (spacesAvailable[7] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 88 && spacesAvailable[7] == 8)
				choice = 8;
			if (spacesAvailable[3] == 88 && spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[2] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[8] == 88) {
			if (spacesAvailable[7] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[5] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[0] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}

		else if (choice == -1) {

			//Started Middle possibilities
		if (spacesAvailable[4] == 79) {
			//Possibilities 1 and 2
			if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88) {
				chance = rand() % 3;
				if (chance == 0)
					choice = 1;
				if (chance == 1)
					choice = 3;
				if (chance == 2)
					choice = 7;
			}
			if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88) {
				chance = rand() % 3;
				if (chance == 0)
					choice = 1;
				if (chance == 1)
					choice = 3;
				if (chance == 2)
					choice = 9;
			}
			if (spacesAvailable[5] == 88 && spacesAvailable[7] == 88) {
				chance = rand() % 3;
				if (chance == 0)
					choice = 3;
				if (chance == 1)
					choice = 7;
				if (chance == 2)
					choice = 9;
			}
			if (spacesAvailable[3] == 88 && spacesAvailable[7] == 88) {
				chance = rand() % 3;
				if (chance == 0)
					choice = 1;
				if (chance == 1)
					choice = 7;
				if (chance == 2)
					choice = 9;
			}
			//Possibility 3
			if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 1;
				if (chance == 1)
					choice = 4;
			}
			if (spacesAvailable[5] == 88 && spacesAvailable[0] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 2;
				if (chance == 1)
					choice = 3;
			}
			if (spacesAvailable[7] == 88 && spacesAvailable[2] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 6;
				if (chance == 1)
					choice = 9;
			}
			if (spacesAvailable[3] == 88 && spacesAvailable[8] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 7;
				if (chance == 1)
					choice = 8;
			}
			//Possibility 4
			if (spacesAvailable[1] == 88 && spacesAvailable[8] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 3;
				if (chance == 1)
					choice = 6;
			}
			if (spacesAvailable[5] == 88 && spacesAvailable[6] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 8;
				if (chance == 1)
					choice = 9;
			}
			if (spacesAvailable[7] == 88 && spacesAvailable[0] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 4;
				if (chance == 1)
					choice = 7;
			}
			if (spacesAvailable[3] == 88 && spacesAvailable[2] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 1;
				if (chance == 1)
					choice = 2;
			}
			//Possibility 5    W I N
			if (spacesAvailable[1] == 88 && spacesAvailable[7] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 4;
				if (chance == 1)
					choice = 6;
			}
			if (spacesAvailable[3] == 88 && spacesAvailable[5] == 88) {
				chance = rand() % 2;
				if (chance == 0)
					choice = 2;
				if (chance == 1)
					choice = 8;
			}
		}
		//They started Diagonal
		if ((spacesAvailable[0] == 88 && spacesAvailable[8] == 88) || (spacesAvailable[2] == 88 && spacesAvailable[6] == 88)) {
			chance = rand() % 4;
			if (chance == 0)
				choice = 2;
			if (chance == 1)
				choice = 4;
			if (chance == 2)
				choice = 6;
			if (chance == 3)
				choice = 8;
		}

		//They started in the middle and picked across from me
		if (spacesAvailable[4] == 88 && spacesAvailable[0] == 79 && spacesAvailable[8] == 88) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[4] == 88 && spacesAvailable[2] == 79 && spacesAvailable[6] == 88) {
			chance = rand() % 4;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[4] == 88 && spacesAvailable[8] == 79 && spacesAvailable[0] == 88) {
			chance = rand() % 4;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[4] == 88 && spacesAvailable[6] == 79 && spacesAvailable[2] == 88) {
			chance = rand() % 4;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
	}


		if (choice == -1) {

			std::cout << "\n\n\t\tI MISSED A MOVE ON TURN TWO UGH\n\n";
			Sleep(2000);

			if (spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[1] == 2)
				choice = 2;
			if (spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[4] == 5)
				choice = 5;
			if (spacesAvailable[5] == 6)
				choice = 6;
			if (spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[7] == 8)
				choice = 8;
			if (spacesAvailable[8] == 9)
				choice = 9;

		}

	}

	//COMPUTER TURN THREE
	else if (turn == 5) {

		choice = -1;

		//Look for a win
		if (spacesAvailable[4] == 79) {
			if (spacesAvailable[0] == 79 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[1] == 79 && spacesAvailable[7] == 8)
				choice = 8;
			if (spacesAvailable[2] == 79 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[3] == 79 && spacesAvailable[5] == 6)
				choice = 6;
			if (spacesAvailable[5] == 79 && spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[6] == 79 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[7] == 79 && spacesAvailable[1] == 2)
				choice = 2;
			if (spacesAvailable[8] == 79 && spacesAvailable[0] == 1)
				choice = 1;
		}
		if (spacesAvailable[0] == 79) {
			if (spacesAvailable[3] == 79 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[6] == 79 && spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[1] == 79 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[2] == 79 && spacesAvailable[1] == 2)
				choice = 2;
		}
		if (spacesAvailable[1] == 79) {
			if (spacesAvailable[7] == 79 && spacesAvailable[4] == 5)
				choice = 7;
			if (spacesAvailable[2] == 79 && spacesAvailable[0] == 1)
				choice = 1;
		}
		if (spacesAvailable[2] == 79) {
			if (spacesAvailable[5] == 79 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 79 && spacesAvailable[5] == 6)
				choice = 6;
		}
		if (spacesAvailable[3] == 79) {
			if (spacesAvailable[6] == 79 && spacesAvailable[0] == 1)
				choice = 1;
		}
		if (spacesAvailable[5] == 79) {
			if (spacesAvailable[8] == 79 && spacesAvailable[2] == 3)
				choice = 3;
		}
		if (spacesAvailable[6] == 79) {
			if (spacesAvailable[7] == 79 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 79 && spacesAvailable[7] == 8)
				choice = 8;
		}


		if (choice == -1) {
			//Defensive Actions
			if (spacesAvailable[4] == 88) {
				if (spacesAvailable[0] == 88 && spacesAvailable[8] == 9)
					choice = 9;
				else if (spacesAvailable[1] == 88 && spacesAvailable[7] == 8)
					choice = 8;
				else if (spacesAvailable[2] == 88 && spacesAvailable[6] == 7)
					choice = 7;
				else if (spacesAvailable[3] == 88 && spacesAvailable[5] == 6)
					choice = 6;
				else if (spacesAvailable[5] == 88 && spacesAvailable[3] == 4)
					choice = 4;
				else if (spacesAvailable[6] == 88 && spacesAvailable[2] == 3)
					choice = 3;
				else if (spacesAvailable[7] == 88 && spacesAvailable[1] == 2)
					choice = 2;
				else if (spacesAvailable[8] == 88 && spacesAvailable[0] == 1)
					choice = 1;
			}
			if (spacesAvailable[0] == 88) {
				if (spacesAvailable[1] == 88 && spacesAvailable[2] == 3)
					choice = 3;
				if (spacesAvailable[3] == 88 && spacesAvailable[6] == 7)
					choice = 7;
				if (spacesAvailable[2] == 88 && spacesAvailable[1] == 2)
					choice = 2;
				if (spacesAvailable[6] == 88 && spacesAvailable[3] == 4)
					choice = 4;
				if (spacesAvailable[8] == 88 && spacesAvailable[4] == 5)
					choice = 5;
			}
			if (spacesAvailable[2] == 88) {
				if (spacesAvailable[1] == 88 && spacesAvailable[0] == 1)
					choice = 1;
				if (spacesAvailable[5] == 88 && spacesAvailable[8] == 9)
					choice = 9;
				if (spacesAvailable[8] == 88 && spacesAvailable[5] == 6)
					choice = 6;
				if (spacesAvailable[6] == 88 && spacesAvailable[4] == 5)
					choice = 5;
			}
			if (spacesAvailable[6] == 88) {
				if (spacesAvailable[7] == 88 && spacesAvailable[8] == 9)
					choice = 9;
				if (spacesAvailable[8] == 88 && spacesAvailable[7] == 8)
					choice = 8;
				if (spacesAvailable[3] == 88 && spacesAvailable[0] == 1)
					choice = 1;
				if (spacesAvailable[2] == 88 && spacesAvailable[4] == 5)
					choice = 5;
			}
			if (spacesAvailable[8] == 88) {
				if (spacesAvailable[7] == 88 && spacesAvailable[6] == 7)
					choice = 7;
				if (spacesAvailable[5] == 88 && spacesAvailable[2] == 3)
					choice = 3;
				if (spacesAvailable[0] == 88 && spacesAvailable[4] == 5)
					choice = 5;
			}
		}


		if (choice == -1) {

			//Case by case

				//Case A

					//Possibiliy 1
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[8] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[6] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}


		//Possibility 2 is a rotation of Possibility 1, already covered

		//Possibiliy 3
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}

		//Possibiliy 3
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[3] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[5] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}

		//Possibiliy 4

		std::cout << "\n\n\tWE MADE IT TO POSSIBILITY FOUR\n\n";
		Sleep(4000);

		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[5] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[3] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}

		//Possibiliy 5
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 9;
		}


		//Case B

			//Possiblity 1
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}

		//Possibility 2
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			choice = 1;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			choice = 3;
		}

		//Possibility 3

			//Part 1a
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[5] == 79) {
			choice = 5;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[7] == 79) {
			choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[3] == 79 && spacesAvailable[7] == 79) {
			choice = 5;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[1] == 79 && spacesAvailable[3] == 79) {
			choice = 5;
		}

		//Part 1b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[3] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}

		//Part 2a
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 3;
			if (chance == 0)
				choice = 4;
			if (chance == 1)
				choice = 5;
			if (chance == 2)
				choice = 7;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			chance = rand() % 3;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 2;
			if (chance == 2)
				choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 3;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 5;
			if (chance == 2)
				choice = 6;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			chance = rand() % 3;
			if (chance == 0)
				choice = 5;
			if (chance == 1)
				choice = 7;
			if (chance == 2)
				choice = 8;
		}

		//Part 2b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[8] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 5;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 5;
			if (chance == 1)
				choice = 4;
		}

		//Part 2c
		if (spacesAvailable[2] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[8] == 79) {
			choice = 5;
		}
		if (spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[6] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			choice = 5;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			choice = 5;
		}


		//Part 3a
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 9;
		}
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 1;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 3;
		}

		//Part 3b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 6;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 8;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 4;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 2;
		}

		//Part 3c
		if (spacesAvailable[2] == 88 && spacesAvailable[4] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 1;
		}
		if (spacesAvailable[3] == 88 && spacesAvailable[4] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 3;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[4] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[4] == 88 && spacesAvailable[5] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 7;
		}


		//Possibiliy 4

			//Part 1a
		if (spacesAvailable[1] == 88 && spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[8] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 5;
		}
		if (spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[7] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 5;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 5;
		}

		//Part 1b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 5;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 5;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 5;
		}

		//Part 1c
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[5] == 79) {
			choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[2] == 79 && spacesAvailable[7] == 79) {
			choice = 1;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[8] == 79) {
			choice = 3;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[6] == 79) {
			choice = 9;
		}

		//Part 2a
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[5] == 79) {
			choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[7] == 79) {
			choice = 1;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[7] == 79) {
			choice = 3;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[3] == 79) {
			choice = 9;
		}

		//Part 2b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[1] == 79 && spacesAvailable[5] == 79) {
			choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[7] == 79) {
			choice = 1;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[7] == 79) {
			choice = 3;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[3] == 79) {
			choice = 9;
		}

		//Part 3a
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[4] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			choice = 9;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[4] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			choice = 7;
		}
		if (spacesAvailable[4] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			choice = 1;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[4] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[8] == 79) {
			choice = 3;
		}

		//Part 3b
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			choice = 2;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			choice = 6;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			choice = 8;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[8] == 79) {
			choice = 4;
		}

		//Part 3c
		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[5] == 79 && spacesAvailable[6] == 79) {
			choice = 1;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[0] == 79 && spacesAvailable[7] == 79) {
			choice = 3;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[2] == 79 && spacesAvailable[3] == 79) {
			choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[0] == 79 && spacesAvailable[8] == 79) {
			choice = 7;
		}


		//Possibility 5

		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[7] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}


		//Possibility 6

		if (spacesAvailable[2] == 88 && spacesAvailable[3] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[5] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 7;
		}
		if (spacesAvailable[1] == 88 && spacesAvailable[6] == 88 && spacesAvailable[8] == 88 && spacesAvailable[4] == 79 && spacesAvailable[7] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 1;
			if (chance == 1)
				choice = 3;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[5] == 88 && spacesAvailable[6] == 88 && spacesAvailable[3] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 3;
			if (chance == 1)
				choice = 9;
		}
		if (spacesAvailable[0] == 88 && spacesAvailable[2] == 88 && spacesAvailable[7] == 88 && spacesAvailable[1] == 79 && spacesAvailable[4] == 79) {
			chance = rand() % 2;
			if (chance == 0)
				choice = 7;
			if (chance == 1)
				choice = 9;
		}



			//Case C

				//All possibilities covered by defense

		}


		if (choice == -1) {

			std::cout << "\n\n\t\tI MISSED A MOVE ON TURN THREE UGH\n\n";
			Sleep(4000);

			if (spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[1] == 2)
				choice = 2;
			if (spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[4] == 5)
				choice = 5;
			if (spacesAvailable[5] == 6)
				choice = 6;
			if (spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[7] == 8)
				choice = 8;
			if (spacesAvailable[8] == 9)
				choice = 9;

		}




	}

	else if (turn == 7) {

	choice = -1;

	//Look for a win
	if (spacesAvailable[4] == 79) {
		if (spacesAvailable[0] == 79 && spacesAvailable[8] == 9)
			choice = 9;
		if (spacesAvailable[1] == 79 && spacesAvailable[7] == 8)
			choice = 8;
		if (spacesAvailable[2] == 79 && spacesAvailable[6] == 7)
			choice = 7;
		if (spacesAvailable[3] == 79 && spacesAvailable[5] == 6)
			choice = 6;
		if (spacesAvailable[5] == 79 && spacesAvailable[3] == 4)
			choice = 4;
		if (spacesAvailable[6] == 79 && spacesAvailable[2] == 3)
			choice = 3;
		if (spacesAvailable[7] == 79 && spacesAvailable[1] == 2)
			choice = 2;
		if (spacesAvailable[8] == 79 && spacesAvailable[0] == 1)
			choice = 1;
	}
	if (spacesAvailable[0] == 79) {
		if (spacesAvailable[3] == 79 && spacesAvailable[6] == 7)
			choice = 7;
		if (spacesAvailable[6] == 79 && spacesAvailable[3] == 4)
			choice = 4;
		if (spacesAvailable[1] == 79 && spacesAvailable[2] == 3)
			choice = 3;
		if (spacesAvailable[2] == 79 && spacesAvailable[1] == 2)
			choice = 2;
	}
	if (spacesAvailable[1] == 79) {
		if (spacesAvailable[7] == 79 && spacesAvailable[4] == 5)
			choice = 7;
		if (spacesAvailable[2] == 79 && spacesAvailable[0] == 1)
			choice = 1;
	}
	if (spacesAvailable[2] == 79) {
		if (spacesAvailable[5] == 79 && spacesAvailable[8] == 9)
			choice = 9;
		if (spacesAvailable[8] == 79 && spacesAvailable[5] == 6)
			choice = 6;
	}
	if (spacesAvailable[3] == 79) {
		if (spacesAvailable[6] == 79 && spacesAvailable[0] == 1)
			choice = 1;
	}
	if (spacesAvailable[5] == 79) {
		if (spacesAvailable[8] == 79 && spacesAvailable[2] == 3)
			choice = 3;
	}
	if (spacesAvailable[6] == 79) {
		if (spacesAvailable[7] == 79 && spacesAvailable[8] == 9)
			choice = 9;
		if (spacesAvailable[8] == 79 && spacesAvailable[7] == 8)
			choice = 8;
	}

	else if (choice == -1) {
		std::cout << "DEFENSIVE ACTION PROCCED";
		Sleep(2000);
		//Defensive Actions
		if (spacesAvailable[4] == 88) {
			if (spacesAvailable[0] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			else if (spacesAvailable[1] == 88 && spacesAvailable[7] == 8)
				choice = 8;
			else if (spacesAvailable[2] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			else if (spacesAvailable[3] == 88 && spacesAvailable[5] == 6)
				choice = 6;
			else if (spacesAvailable[5] == 88 && spacesAvailable[3] == 4)
				choice = 4;
			else if (spacesAvailable[6] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			else if (spacesAvailable[7] == 88 && spacesAvailable[1] == 2)
				choice = 2;
			else if (spacesAvailable[8] == 88 && spacesAvailable[0] == 1)
				choice = 1;
		}
		if (spacesAvailable[0] == 88) {
			if (spacesAvailable[1] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[3] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[2] == 88 && spacesAvailable[1] == 2)
				choice = 2;
			if (spacesAvailable[6] == 88 && spacesAvailable[3] == 4)
				choice = 4;
			if (spacesAvailable[8] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[2] == 88) {
			if (spacesAvailable[1] == 88 && spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[5] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 88 && spacesAvailable[5] == 6)
				choice = 6;
			if (spacesAvailable[6] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[6] == 88) {
			if (spacesAvailable[7] == 88 && spacesAvailable[8] == 9)
				choice = 9;
			if (spacesAvailable[8] == 88 && spacesAvailable[7] == 8)
				choice = 8;
			if (spacesAvailable[3] == 88 && spacesAvailable[0] == 1)
				choice = 1;
			if (spacesAvailable[2] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
		if (spacesAvailable[8] == 88) {
			if (spacesAvailable[7] == 88 && spacesAvailable[6] == 7)
				choice = 7;
			if (spacesAvailable[5] == 88 && spacesAvailable[2] == 3)
				choice = 3;
			if (spacesAvailable[0] == 88 && spacesAvailable[4] == 5)
				choice = 5;
		}
	}





	if (choice == -1) {

		std::cout << "\n\n\t\tI MISSED A MOVE UGH (maybe)\n\n";
		

		if (spacesAvailable[0] == 1)
			choice = 1;
		if (spacesAvailable[1] == 2)
			choice = 2;
		if (spacesAvailable[2] == 3)
			choice = 3;
		if (spacesAvailable[3] == 4)
			choice = 4;
		if (spacesAvailable[4] == 5)
			choice = 5;
		if (spacesAvailable[5] == 6)
			choice = 6;
		if (spacesAvailable[6] == 7)
			choice = 7;
		if (spacesAvailable[7] == 8)
			choice = 8;
		if (spacesAvailable[8] == 9)
			choice = 9;

	}

	}

	if (choice == -1) {

		std::cout << "\n\n\t\tI MISSED A MOVE AFTER ALL THAT UGH\n\n";
		Sleep(4000);

		if (spacesAvailable[0] == 1)
			choice = 1;
		if (spacesAvailable[1] == 2)
			choice = 2;
		if (spacesAvailable[2] == 3)
			choice = 3;
		if (spacesAvailable[3] == 4)
			choice = 4;
		if (spacesAvailable[4] == 5)
			choice = 5;
		if (spacesAvailable[5] == 6)
			choice = 6;
		if (spacesAvailable[6] == 7)
			choice = 7;
		if (spacesAvailable[7] == 8)
			choice = 8;
		if (spacesAvailable[8] == 9)
			choice = 9;

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