// Name: Noah Ong
//  Email: noah.z.ong@vanderbilt.edu
//  Date: 2/14/2023
//  Course: CS3270
//  Honor statement: I have neither given nor received unauthorized help on this assignment.

#ifndef SUDOKU_H
#define SUDOKU_H

#include <fstream>
#include <iostream>
#include <string>

class Sudoku {

public:
    /**
     * Default Constructor
     */
    Sudoku();

    /**
     * Loads the sudoku board from the file into the array
     * @param filename a string, the name of the text file
     */
    void loadFromFile(std::string filename);

    /**
     * Checks if two sudoku boards are equal
     * @param other a sudoku, the one to be compared against
     * @return true if the two sudoku boards are equal
     */
    bool equals(const Sudoku& other) const;

    /**
     * Solves the sudoku puzzle
     * @return true if the puzzle is able to be solved
     */
    bool solve();

    /**
     * Overloads the ostream operator to print out the board
     * @param out the ostream to be written to
     * @param sudoku the board being printed
     */
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);

private:
    /**
     * Helper method for the solver, checks if a number is valid in the specified location
     * @param row the row number to be checked
     * @param col the column number to be checked
     * @param num the value to be checked
     * @return true if the num is able to be placed there
     */
    bool isValid(int row, int col, int num);

    static const int BOARD_SIZE = 9;

    int board[BOARD_SIZE][BOARD_SIZE];
};

#endif