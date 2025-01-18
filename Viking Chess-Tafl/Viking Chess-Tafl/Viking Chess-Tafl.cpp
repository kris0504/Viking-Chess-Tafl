#include <iostream>
#include "Constants.h"
using namespace std;

char toUpperCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return (c - 'a' + 'A');
	}
	return c;
}
bool compareStrings(const char* str1, const char* str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return false;
		}
		str1++;
		str2++;
	}
	return *str1 == '\0' && *str2 == '\0';
}

bool isValidMove(const char* const* board, int size, int startX, int startY, int endX, int endY, bool isAttackersTurn) {
	int center = size / 2;
	if (endX == center && endY == center && board[startX][startY] != KING) {
		return false;
	}
	if ((isAttackersTurn && board[startX][startY] != ATTACKER) ||
		(!isAttackersTurn && board[startX][startY] != DEFENDER && board[startX][startY] != KING)) {
		return false;
	}

	if (startX < 0 || startX >= size || startY < 0 || startY >= size ||
		endX < 0 || endX >= size || endY < 0 || endY >= size) {
		return false;
	}
	if (board[startX][startY] == EMPTY || board[startX][startY] == CORNER) {
		return false;
	}
	if (board[endX][endY] == DEFENDER || board[endX][endY] == ATTACKER || board[endX][endY] == KING ||
		(board[endX][endY] == CORNER && isAttackersTurn)) {
		return false;
	}
	if (startX != endX && startY != endY) {
		return false;
	}
	if (startX == endX) {
		int step;
		if (endY > startY) step = 1;
		else step = -1;

		for (int y = startY + step; y != endY; y += step) {
			if (board[startX][y] != EMPTY&& board[startX][y] != THRONE) {
				return false;
			}
		}
	}
	else if (startY == endY) {
		int step;
		if (endX > startX) step = 1;
		else step = -1;
		for (int x = startX + step; x != endX; x += step) {
			if (board[x][startY] != EMPTY && board[x][startY] != THRONE) {
				return false;
			}
		}
	}
	return true;
}
bool isValid(const char* const* board, int size, int endx, int endy) {
	return (endx < size && endy < size && endx >= 0 && endy >= 0);//returns if its possible for a piece to be removed
}

void removePeace(char* const* board, int size, int endX, int endY, bool isAttackersTurn) {
	if (isValid(board, size, endX + 2, endY))
	{
		if ((isAttackersTurn && board[endX + 1][endY] == DEFENDER && board[endX + 2][endY] == ATTACKER)
			|| (isAttackersTurn && board[endX + 1][endY] == DEFENDER && board[endX + 2][endY] == CORNER)
			|| (isAttackersTurn && board[endX + 1][endY] == DEFENDER && board[endX + 2][endY] == KING)) {
			board[endX + 1][endY] = EMPTY;
			cout << "One defender is taken!" << endl;

		}
		if ((!isAttackersTurn && board[endX + 1][endY] == ATTACKER && board[endX + 2][endY] == DEFENDER)
			|| (!isAttackersTurn && board[endX + 1][endY] == ATTACKER && board[endX + 2][endY] == CORNER)
			|| (!isAttackersTurn && board[endX + 1][endY] == ATTACKER && board[endX + 2][endY] == KING)) {
			board[endX + 1][endY] = EMPTY;
			cout << "One attacker is taken!" << endl;

		}
	}
	if (isValid(board, size, endX - 2, endY)) {
		if ((isAttackersTurn && board[endX - 1][endY] == DEFENDER && board[endX - 2][endY] == ATTACKER)
			|| (isAttackersTurn && board[endX - 1][endY] == DEFENDER && board[endX - 2][endY] == CORNER)
			|| (isAttackersTurn && board[endX - 1][endY] == DEFENDER && board[endX - 2][endY] == KING)) {
			board[endX - 1][endY] = EMPTY;
			cout << "One defender is taken!" << endl;

		}
		if ((!isAttackersTurn && board[endX - 1][endY] == ATTACKER && board[endX - 2][endY] == DEFENDER)
			|| (!isAttackersTurn && board[endX - 1][endY] == ATTACKER && board[endX - 2][endY] == CORNER)
			|| (!isAttackersTurn && board[endX - 1][endY] == ATTACKER && board[endX - 2][endY] == KING)) {
			board[endX - 1][endY] = EMPTY;
			cout << "One attacker is taken!" << endl;

		}
	}
	if (isValid(board, size, endX, endY + 2))
	{
		if ((isAttackersTurn && board[endX][endY + 1] == DEFENDER && board[endX][endY + 2] == ATTACKER)
			|| (isAttackersTurn && board[endX][endY + 1] == DEFENDER && board[endX][endY + 2] == CORNER)
			|| (isAttackersTurn && board[endX][endY + 1] == DEFENDER && board[endX][endY + 2] == KING)) {
			board[endX][endY + 1] = EMPTY;
			cout << "One defender is taken!" << endl;

		}

		if ((!isAttackersTurn && board[endX][endY + 1] == ATTACKER && board[endX][endY + 2] == DEFENDER)
			|| (!isAttackersTurn && board[endX][endY + 1] == ATTACKER && board[endX][endY + 2] == CORNER)
			|| (!isAttackersTurn && board[endX][endY + 1] == ATTACKER && board[endX][endY + 2] == KING)) {
			board[endX][endY + 1] = EMPTY;
			cout << "One attacker is taken!" << endl;

		}
	}
	if (isValid(board, size, endX, endY - 2)) {
		if ((isAttackersTurn && board[endX][endY - 1] == DEFENDER && board[endX][endY - 2] == ATTACKER)
			|| (isAttackersTurn && board[endX][endY - 1] == DEFENDER && board[endX][endY - 2] == CORNER)
			|| (isAttackersTurn && board[endX][endY - 1] == DEFENDER && board[endX][endY - 2] == KING)) {
			board[endX][endY - 1] = EMPTY;
			cout << "One defender is taken!" << endl;

		}
		if ((!isAttackersTurn && board[endX][endY - 1] == ATTACKER && board[endX][endY - 2] == DEFENDER)
			|| (!isAttackersTurn && board[endX][endY - 1] == ATTACKER && board[endX][endY - 2] == CORNER)
			|| (!isAttackersTurn && board[endX][endY - 1] == ATTACKER && board[endX][endY - 2] == KING)) {
			board[endX][endY - 1] = EMPTY;
			cout << "One attacker is taken!" << endl;

		}
	}



}
void makeMove(char* const* board, int size, int startX, int startY, int endX, int endY, bool isAttackersTurn) {
	board[endX][endY] = board[startX][startY];
	board[startX][startY] = EMPTY;
	removePeace(board, size, endX, endY, isAttackersTurn);
}


bool checkVictory(const char* const* board, int size) {

	if ((board[0][size - 1] == KING) || (board[0][0] == KING) ||
		(board[size - 1][size - 1] == KING) || (board[size - 1][0] == KING)) {
		return true;
	}

	int kingX = -1, kingY = -1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == KING) {
				kingX = i;
				kingY = j;
				break;
			}
		}
	}


	if (kingX == -1 || kingY == -1) {
		return true;
	}

	if ((kingX > 0 && board[kingX - 1][kingY] != ATTACKER && board[kingX - 1][kingY] != CORNER) ||
		(kingX < size - 1 && board[kingX + 1][kingY] != ATTACKER && board[kingX + 1][kingY] != CORNER) ||
		(kingY > 0 && board[kingX][kingY - 1] != ATTACKER && board[kingX][kingY - 1] != CORNER) ||
		(kingY < size - 1 && board[kingX][kingY + 1] != ATTACKER && board[kingX][kingY + 1] != CORNER)) {
		return false;
	}

	return true;
}

void initializeFor9(char*const* board, int size, int center) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			board[i][j] = EMPTY;
		}
	}

	// Set corners
	board[0][0] = CORNER;
	board[0][size - 1] = CORNER;
	board[size - 1][0] = CORNER;
	board[size - 1][size - 1] = CORNER;

	// Set king
	board[center][center] = KING;

	// Set defenders around the king
	board[center - 1][center] = DEFENDER;
	board[center + 1][center] = DEFENDER;
	board[center][center - 1] = DEFENDER;
	board[center][center + 1] = DEFENDER;

	// Additional defenders
	board[center - 2][center] = DEFENDER;
	board[center + 2][center] = DEFENDER;
	board[center][center - 2] = DEFENDER;
	board[center][center + 2] = DEFENDER;

	// Set attackers
	for (int i = 1; i < 4; ++i) {
		board[0][center - 2 + i] = ATTACKER;
		board[size - 1][center - 2 + i] = ATTACKER;
		board[center - 2 + i][0] = ATTACKER;
		board[center - 2 + i][size - 1] = ATTACKER;
	}

	board[1][center] = ATTACKER;
	board[size - 2][center] = ATTACKER;
	board[center][1] = ATTACKER;
	board[center][size - 2] = ATTACKER;
}

void initializeFor11(char*const* board, int size, int center) {
	board[0][center - 2] = ATTACKER;
	board[0][center + 2] = ATTACKER;
	board[size - 1][center - 2] = ATTACKER;
	board[size - 1][center + 2] = ATTACKER;
	board[center - 2][0] = ATTACKER;
	board[center + 2][0] = ATTACKER;
	board[center - 2][size - 1] = ATTACKER;
	board[center + 2][size - 1] = ATTACKER;
	board[center - 1][center - 1] = DEFENDER;
	board[center + 1][center - 1] = DEFENDER;
	board[center - 1][center + 1] = DEFENDER;
	board[center + 1][center + 1] = DEFENDER;
}

void initializeFor13(char*const* board, int size, int center) {
	board[1][center] = EMPTY;
	board[size - 2][center] = EMPTY;
	board[center][1] = EMPTY;
	board[center][size - 2] = EMPTY;

	board[0][center - 2] = ATTACKER;
	board[0][center + 2] = ATTACKER;
	board[size - 1][center - 2] = ATTACKER;
	board[size - 1][center + 2] = ATTACKER;

	board[size - 2][center + 1] = ATTACKER;
	board[size - 2][center - 1] = ATTACKER;
	board[1][center + 1] = ATTACKER;
	board[1][center - 1] = ATTACKER;
	board[center + 1][1] = ATTACKER;
	board[center - 1][1] = ATTACKER;
	board[size - 2][center + 1] = ATTACKER;
	board[size - 2][center - 1] = ATTACKER;
	board[center + 1][size - 2] = ATTACKER;
	board[center - 1][size - 2] = ATTACKER;
	board[center][size - 3] = ATTACKER;
	board[size - 3][center] = ATTACKER;
	board[2][center] = ATTACKER;
	board[center][2] = ATTACKER;

	board[center - 2][0] = ATTACKER;
	board[center + 2][0] = ATTACKER;
	board[center - 2][size - 1] = ATTACKER;
	board[center + 2][size - 1] = ATTACKER;

	board[center - 1][center - 1] = DEFENDER;
	board[center + 1][center - 1] = DEFENDER;
	board[center - 1][center + 1] = DEFENDER;
	board[center + 1][center + 1] = DEFENDER;
	board[center - 2][center - 2] = DEFENDER;
	board[center + 2][center - 2] = DEFENDER;
	board[center - 2][center + 2] = DEFENDER;
	board[center + 2][center + 2] = DEFENDER;
}

void initializeBoard(char*const* board, int size) {
	int center = size / 2;
	initializeFor9(board, size, center);
	if (size == 11) {
		initializeFor11(board, size, center);
	}
	if (size == 13) {
		initializeFor13(board, size, center);
	}
}

void displayBoard(const char* const * board, int size) {

	cout << "  ";
	if (size == 9) {
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
		for (int i = 0; i < size; ++i) {
			cout << size - i << " ";
			for (int j = 0; j < size; ++j) {

				cout << board[i][j] << " ";
			}
			cout << size - i << endl;
		}
		cout << "  ";
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
	}
	else if (size == 11) {
		cout << " ";
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
		for (int i = 0; i < size; ++i) {
			if (i < 2)cout << size - i << " ";
			else cout << size - i << "  ";
			for (int j = 0; j < size; ++j) {

				cout << board[i][j] << " ";
			}
			cout << size - i << endl;
		}
		cout << "   ";
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
	}
	else if (size == 13) {
		cout << " ";
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
		for (int i = 0; i < size; ++i) {
			if (i < 4)cout << size - i << " ";
			else cout << size - i << "  ";
			for (int j = 0; j < size; ++j) {

				cout << board[i][j] << " ";
			}
			cout << size - i << endl;
		}
		cout << "   ";
		for (int i = 0; i < size; ++i) {
			cout << (char)('a' + i) << " ";
		}
		cout << endl;
	}


	
}
bool invalidCordinates(char startCol, char endCol, char startRow, char endRow, int size) {
	return startCol < 'A' || startCol >= 'A' + size || endCol < 'A' || endCol >= 'A' + size ||
		startRow< 1 || startRow > size || endRow < 1 || endRow > size;
}
int getStartOrEndRow(const char* rowNum) {
	return (rowNum[2] == '\0') ? rowNum[1] - '0' : (rowNum[1] - '0') * 10 + (rowNum[2] - '0');
}
void getInfo(const char* const* board, int size, int& attackerCount, int& defenderCount, int& captured) {
	attackerCount = 0;
	defenderCount = 0;
	captured = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == ATTACKER) {
				attackerCount++;
			}
			if (board[i][j] == DEFENDER || board[i][j] == KING) {
				defenderCount++;
			}

		}
	}

	if (size == 9) {
		captured = 25 - attackerCount - defenderCount;
	}
	else if (size == 11) {
		captured = 37 - attackerCount - defenderCount;
	}
	else if (size == 13) {
		captured = 49 - attackerCount - defenderCount;
	}
}
void printInfo(const char* const* board, int size, bool isAttackersTurn, int turns) {
	int attackerCount = 0;
	int defenderCount = 0;
	int captured = 0;
	getInfo(board, size, attackerCount, defenderCount, captured);
	cout << (isAttackersTurn ? "It is Attacker's turn" : "It is Defender's turn") << endl;
	cout << "There are:" << endl << attackerCount << " attackers" << endl << defenderCount << " defenders" << endl << captured << " captured figures" << endl;
	cout << turns << " moves have passed" << endl;
}
void saveLastState(char** lastBoard, const char* const* board, int size, bool& lastTurn, bool currentTurn) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			lastBoard[i][j] = board[i][j];
		}
	}
	lastTurn = currentTurn;
}
bool restoreLastState(const char* const* lastBoard, char* const* board, int size, bool& currentTurn, bool lastTurn) {
	if (lastBoard == nullptr) {
		cout << "No moves to undo!" << endl;
		return false;
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			board[i][j] = lastBoard[i][j];
		}
	}
	currentTurn = lastTurn;
	return true;
}
void playGame(char** board, int size) {
	int center = size / 2;
	bool isAttackerTurn = true;
	bool gameWon = false;
	int movesPassed = 0;
	bool playerLastTurn = false;
	char** lastBoard = new char* [size];
	for (int i = 0; i < size; ++i) {
		lastBoard[i] = new char[size];
	}
	while (!gameWon) {
		displayBoard(board, size);

		cout << (isAttackerTurn ? "Attacker's turn" : "Defender's turn") << endl;
		cout << "Enter your move (e.g.,move d11 d9): ";

		char command[5], start[4], end[4];
		cin >> command;

		if (compareStrings(command, "move"))
		{
			cin >> start >> end;
			char startCol = toUpperCase(start[0]);
			char endCol = toUpperCase(end[0]);

			int startRow = getStartOrEndRow(start);
			int endRow = getStartOrEndRow(end);

			if (invalidCordinates(startCol, endCol, startRow, endRow, size)) {
				cout << "Invalid coordinates! Please try again." << endl;
				continue;
			}

			int startX = size - startRow;
			int startY = startCol - 'A';
			int endX = size - endRow;
			int endY = endCol - 'A';

			if (isValidMove(board, size, startX, startY, endX, endY, isAttackerTurn)) {
				saveLastState(lastBoard, board, size, playerLastTurn, isAttackerTurn);
				makeMove(board, size, startX, startY, endX, endY, isAttackerTurn);
				if (checkVictory(board, size)) {
					isAttackerTurn = !isAttackerTurn;
					displayBoard(board, size);
					cout << (isAttackerTurn ? "Defenders" : "Attackers") << " win!" << endl;
					return;
				}
				movesPassed++;
				isAttackerTurn = !isAttackerTurn;
				if (board[center][center] == EMPTY) {
					board[center][center] = THRONE;
				}
			}
			else {

				cout << "Invalid move! Try again." << endl;
			}

		}
		else if (compareStrings(command, "back") && movesPassed > 0) {
			if (restoreLastState(lastBoard, board, size, isAttackerTurn, playerLastTurn)) {
				cout << "Move undone. Current turn: " << (isAttackerTurn ? "Attacker" : "Defender") << endl;
			}
			continue;
		}
		else if (compareStrings(command, "help")) {
			cout << "You can use the following commands:" << endl << "Move - moves a figure" << endl << "back - go back one move" << endl << "help - display all commands you can use" << endl << "quit - quit current game" << endl;
			continue;
		}
		else if (compareStrings(command, "quit")) {
			return;
		}
		else if (compareStrings(command, "info")) {
			printInfo(board, size, isAttackerTurn, movesPassed);
		}
		else {
				cin.clear();
				cin.ignore(1000, '\n');
			
			cout << "Invalid command!" << endl;
		}

	}
	for (int i = 0; i < size; ++i) {
		delete[] lastBoard[i];
	}
	delete[] lastBoard;
}

void startGame() {
	int size, startGame;

	do
	{
		cout << "Choose an option:" << endl << "1.Start game" << endl << "2.Quit" << endl;
		cin >> startGame;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (startGame != 1 && startGame != 2);
	if (startGame == 2)return;
	cout << "Choose board size: (9, 11, 13): ";
	cin >> size;

	while (cin.fail() || (size != 9 && size != 11 && size != 13)) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid size! Choose board size: (9, 11, 13): " << endl;
		cin >> size;
	}


	char** board = new char* [size];
	for (int i = 0; i < size; ++i) {
		board[i] = new char[size];
	}

	initializeBoard(board, size);
	playGame(board, size);

	for (int i = 0; i < size; ++i) {
		delete[] board[i];
	}
	delete[] board;

}

int main() {
	startGame();
	return 0;
}