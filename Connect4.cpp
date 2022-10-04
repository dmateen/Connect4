#include<iostream>
#include<iomanip>
using namespace std;

class Connect4Game
{
public:
	//Data Members
	int board[7][7];
	int turn;

public:
	Connect4Game()
	{
		//Initializing Data Members
		turn = 0;
		//Intiailizing Every Index of Borad to 0
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++)
				board[i][j] = 0;
	}

	void switchTurn()
	{
		int player = 1, col;
		if (turn % 2 != 0)
			player = 2;

		//Goto Label
	start:
		//Prompting the user and getting the values
		cout << "Player " << player << " turn: " << "Enter Column Number (Sarting from 0 to 6):  ";
		cin >> col;

		//Checking the empty space and storing the value at last non zero value
		for (int i = 0; i < 7; i++)
		{
			if (((board[i][col] == 0) && (board[i + 1][col] != 0) && ((board[i + 1][col] == 1) || (board[i + 1][col] == 2))) || ((i == 6) && (board[i - 1][col] == 0)))
			{
				board[i][col] = player;
				showBoard();
			}
			//Checking if the Col is completely filled
			else if (((i == 0) && (board[i][col] > 0)) || (col < 0 || col>6))
			{
				cout << endl;
				cout << "******************************************************************************************" << endl;
				cout << "ERROR: Please Choose any other column as this column is completely filled or Not in Range" << endl;
				cout << "******************************************************************************************" << endl;
				cout << endl;
				goto start;
			}
		}



	}


	///IS WON FUNCTIONS 


	bool isHorizontal()
	{

		for (int i = 0; i < 7; i++)
		{
			int check1 = 0, check2 = 0;
			for (int j = 0; j < 7; j++)
			{
				if ((board[i][j] == 1 && board[i][j + 1] == 1) || ((j == 6) && (board[i][j] == 1)) || ((check1 == 3) && (board[i][j] == 1) && (board[i][j - 1] == 1)))
					check1++;
				else
					check1 = 0;

				if ((board[i][j] == 2 && board[i][j + 1] == 2) || ((j == 6) && (board[i][j] == 2)) || ((check2 == 3) && (board[i][j] == 2) && (board[i][j - 1] == 2)))
					check2++;
				else
					check2 = 0;

				if (check1 == 4 || check2 == 4)
					return true;
			}
		}
		return false;
	}

	bool isVertical()
	{

		for (int j = 0; j < 7; j++)
		{
			int check1 = 0, check2 = 0;
			for (int i = 0; i < 7; i++)
			{
				if ((board[i][j] == 1 && board[i + 1][j] == 1) || ((i == 6) && (board[i][j] == 1)) || ((check1 == 3) && (board[i][j] == 1) && (board[i - 1][j] == 1)))
					check1++;
				else
					check1 = 0;

				if ((board[i][j] == 2 && board[i + 1][j] == 2) || ((i == 6) && (board[i][j] == 2)) || ((check2 == 3) && (board[i][j] == 2) && (board[i - 1][j] == 2)))
					check2++;
				else
					check2 = 0;

				if (check1 == 4 || check2 == 4)
					return true;
			}
		}
		return false;
	}

	bool isLR_Diagonal()
	{
		int size = 4;
		for (int i = size - 1; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				int check1 = 0;
				int check2 = 0;
				for (int k = 0; k < size; k++)
				{
					if (board[i - k][j + k] == 1)
						check1++;

					else if (board[i - k][j + k] == 2)
						check2++;

					if (check1 == 4 || check2 == 4)
						return true;
				}
			}
		}

		return false;
	}

	bool isRL_Diagonal()
	{
		int size = 4;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				int check1 = 0;
				int check2 = 0;
				for (int k = 0; k < size; k++)
				{
					if (board[i + k][j + k] == 1)
						check1++;

					else if (board[i + k][j + k] == 2)
						check2++;

					if (check1 == 4 || check2 == 4)
						return true;
				}
			}
		}

		return false;
	}

	bool isWon()
	{
		if (isHorizontal() || isVertical() || isLR_Diagonal() || isRL_Diagonal())
		{
			return true;
		}
		return false;
	}

	/// END OF IS WON FUNCTIONS</summary>
	void showBoard()
	{

		cout << endl << "*****************      GAME BOARD     *******************" << endl << endl;

		cout << "     0      1       2       3       4        5      6  " << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[i][j] != 0)
				{
					if (j == 0)
					{
						cout << "| " << setw(5) << board[i][j] << "\t" << "|";
					}
					else
					{
						cout << setw(5) << board[i][j] << "\t" << "|";
					}
				}
				else
				{
					if (j == 0)
					{
						cout << "| " << setw(5) << "\t" << "|";
					}
					else
					{
						cout << setw(5) << "\t" << "|";
					}
				}

			}
			cout << endl << "---------------------------------------------------------" << endl;

		}
	}
	bool isBoardFull()
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (board[i][j] == 0)
				{
					return true;
				}
			}
		}
		return false;
	}
	void start()
	{

		int option;
		cout << "  ------------------------------------------------------------------------------" << endl;
		cout << "  |   *           *  ******  *        *****   *****    **       **   ******     |" << endl;
		cout << "  |    *    *    *   *       *       *       *     *   * *     * *   *          |" << endl;
		cout << "  |     *   *   *    *****   *       *       *     *   *  *   *  *   *****      |" << endl;
		cout << "  |      * * * *     *       *       *       *     *   *   * *   *   *          |" << endl;
		cout << "  |       *   *      ******  ******   *****   *****    *    *    *   ******     |" << endl;
		cout << "  ------------------------------------------------------------------------------" << endl;

		cout << "Press: \'1\' to START and \'2\' to exit" << endl;
		cin >> option;

		bool noWon = true;
		if (option == 1)
		{
			while (isBoardFull() && (isWon() == false))
			{
				system("cls");
				showBoard();
				switchTurn();

				if (isWon() == true)
				{
					int player = 1;
					if (turn % 2 != 0)
						player = 2;

					cout << endl;
					cout << "----------------------------------------------------------" << endl;
					cout << "|      Congratulations!!! Player " << player << "  Won \t\t |" << endl;
					cout << "----------------------------------------------------------" << endl;

					noWon = false;

				}

				turn++;

			}

			if (noWon)
			{
				system("cls");
				showBoard();
				cout << "----------------------------------------------------------" << endl;
				cout << "|                          MATCH DRAW                    |" << endl;
				cout << "----------------------------------------------------------" << endl;
			}

		}
		else
		{
			system("cls");
			cout << "Thank You :)" << endl;
		}
	}
};

int main()
{
	Connect4Game game;
	game.start();
	return 0;

}