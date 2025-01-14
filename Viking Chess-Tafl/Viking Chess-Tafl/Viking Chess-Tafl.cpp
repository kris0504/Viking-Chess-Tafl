#include <iostream>
using namespace std;

const char KING = 'K';
const char ATTACKER = 'A';
const char DEFENDER = 'D';
const char EMPTY = '-';
const char CORNER = 'X';

char toUpperCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return (c - 'a' + 'A');
	}
	return c;
}

bool isValidMove(char** board, int size, int startX, int startY, int endX, int endY) {
	if (startX < 0 || startX >= size || startY < 0 || startY >= size ||
		endX < 0 || endX >= size || endY < 0 || endY >= size) {
		return false;
	}
	if (board[startX][startY] == EMPTY || board[startX][startY] == CORNER) {
		return false;
	}
	if (board[endX][endY] != EMPTY) {
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
			if (board[startX][y] != EMPTY) {
				return false;
			}
		}
	}
	else if (startY == endY) {
		int step;
		if (endX > startX) step = 1;
		else step = -1;
		for (int x = startX + step; x != endX; x += step) {
			if (board[x][startY] != EMPTY) {
				return false;
			}
		}
	}
	return true;
}

void makeMove(char** board, int startX, int startY, int endX, int endY) {
	board[endX][endY] = board[startX][startY];
	board[startX][startY] = EMPTY;
}

bool checkVictory(char** board, int size) {

	if ((board[0][size - 1] == KING) || (board[0][0] == KING) || (board[size - 1][size - 1] == KING) || (board[size - 1][0] == KING)) {
		return true;
	}
	int kingX, kingY;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == KING) {
				kingX = i;
				kingY = j;
				break;
			}
		}
	}
	if ((kingX > 0 && board[kingX - 1][kingY] != ATTACKER && board[kingX - 1][kingY] != CORNER) ||
		(kingX < size - 1 && board[kingX + 1][kingY] != ATTACKER && board[kingX + 1][kingY] != CORNER) ||
		(kingY > 0 && board[kingX][kingY - 1] != ATTACKER && board[kingX][kingY - 1] != CORNER) ||
		(kingY < size - 1 && board[kingX][kingY + 1] != ATTACKER && board[kingX][kingY + 1] != CORNER)) {
		return false;
	}
	return true;
}

void initializeFor9(char** board, int size, int center) {
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

void initializeFor11(char** board, int size, int center) {
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

void initializeFor13(char** board, int size, int center) {
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

void initializeBoard(char** board, int size) {
	int center = size / 2;
	initializeFor9(board, size, center);
	if (size == 11) {
		initializeFor11(board, size, center);
	}
	if (size == 13) {
		initializeFor13(board, size, center);
	}
}

void displayBoard(char** board, int size) {

	cout << "   ";
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

	cout << "   ";
	for (int i = 0; i < size; ++i) {
		cout << (char)('a' + i) << " ";
	}
	cout << endl;
}
bool invalidCordinates(char startCol, char endCol, char startRow, char endRow, int size) {
	return startCol < 'A' || startCol >= 'A' + size || endCol < 'A' || endCol >= 'A' + size ||
		startRow < 1 || startRow > size || endRow < 1 || endRow > size;
}
int getStartOrEndRow(const char* rowNum) {
	return (rowNum[2] == '\0') ? rowNum[1] - '0' : (rowNum[1] - '0') * 10 + (rowNum[2] - '0');
}
void playGame(char** board, int size) {
	bool isAttackerTurn = true;
	bool gameWon = false;

	while (!gameWon) {
		displayBoard(board, size);

		cout << (isAttackerTurn ? "Attacker's turn" : "Defender's turn") << endl;
		cout << "Enter your move (e.g., d11 d9): ";

		char start[4], end[4];
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

		if (isValidMove(board, size, startX, startY, endX, endY)) {
			makeMove(board, startX, startY, endX, endY);
			gameWon = checkVictory(board, size);
			isAttackerTurn = !isAttackerTurn;
		}
		else {
			cout << "Invalid move! Try again." << endl;
		}
	}

	cout << (isAttackerTurn ? "Defenders" : "Attackers") << " win!" << endl;
}



int main() {
	int size;
	cout << "Choose board size: (9, 11, 13): ";
	cin >> size;

	if (size != 9 && size != 11 && size != 13) {
		cout << "Invalid size! Standard size is set to 11x11." << endl;
		size = 11;
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

	return 0;
}