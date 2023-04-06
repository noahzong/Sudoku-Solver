// Name: Noah Ong
//  Email: noah.z.ong@vanderbilt.edu
//  Date: 2/14/2023
//  Course: CS3270
//  Honor statement: I have neither given nor received unauthorized help on this assignment.

#include "Sudoku.h"

Sudoku::Sudoku()
{
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        for (auto j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = 0;
        }
    }
}

void Sudoku::loadFromFile(std::string filename)
{
    std::ifstream input(filename);
    int value;
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        for (auto j = 0; j < BOARD_SIZE; ++j) {
            input >> value;
            board[i][j] = value;
        }
    }
}

bool Sudoku::equals(const Sudoku& other) const
{
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        for (auto j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != other.board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::solve()
{
    for (auto i = 0; i < BOARD_SIZE; ++i) { // num is the value being inserted
        for (auto j = 0; j < BOARD_SIZE; ++j) { // i and j loop through the board
            if (board[i][j] == 0) {
                for (auto num = 1; num <= BOARD_SIZE; ++num) {
                    if (isValid(i, j, num)) {
                        board[i][j] = num;
                        if (solve()) {
                            return true;
                        }
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku)
{
    for (auto i = 0; i < sudoku.BOARD_SIZE; ++i) {
        for (auto j = 0; j < sudoku.BOARD_SIZE; ++j) {
            if (sudoku.board[i][j] == 0) {
                out << "  ";
            } else {
                out << sudoku.board[i][j] << ' ';
            }
            if (j != 8 && j % 3 == 2) {
                out << "| ";
            }
            if (j == 8) {
                out << "\n";
            }
            if (i % 3 == 2 && i != 8 && j == 8) {
                out << "------+-------+------\n";
            }
        }
    }
    return out;
}

bool Sudoku::isValid(int row, int col, int num)
{
    // check if in row or column
    for (auto i = 0; i < BOARD_SIZE; ++i) {
        if (board[row][i] == num) {
            return false;
        }
        if (board[i][col] == num) {
            return false;
        }
    }
    // check if in box
    int boxRowStart = row / 3 * 3;
    int boxColStart = col / 3 * 3;

    for (auto i = 0; i < 3; ++i) {
        for (auto j = 0; j < 3; ++j) {
            if (board[i + boxRowStart][j + boxColStart] == num) {
                return false;
            }
        }
    }

    return true;
}
