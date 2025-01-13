#include <iostream>
using namespace std;

const char KING = 'K';
const char ATTACKER = 'A';
const char DEFENDER = 'D';
const char EMPTY = '-';
const char CORNER = 'X';


void initializeFor9(char** board, int size, int center) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            board[i][j] = EMPTY;

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
    // Print column letters
    cout << "   ";
    for (int i = 0; i < size; ++i)
        cout << (char)('a' + i) << " ";
    cout << endl;

    for (int i = 0; i < size; ++i) {
        cout << size - i << " ";
        for (int j = 0; j < size; ++j)
            cout << board[i][j] << " ";
        cout << size - i << endl;
    }

    cout << "   ";
    for (int i = 0; i < size; ++i)
        cout << (char)('a' + i) << " ";
    cout << endl;
}

int main() {
    int size;
    cout << "Choose board size: (9, 11, 13): ";
    cin >> size;

    if (size != 9 && size != 11 && size != 13) {
        cout << "Invalid size! Standard size is set to 11x11.\n";
        size = 11;
    }

    char** board = new char* [size];
    for (int i = 0; i < size; ++i)
        board[i] = new char[size];
    initializeBoard(board, size);
    displayBoard(board, size);

    for (int i = 0; i < size; ++i)
        delete[] board[i];
    delete[] board;

    return 0;
}
