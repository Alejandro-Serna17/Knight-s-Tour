#include <iostream>
#include <iomanip>

/**
 * Knight's Tour C++
 * @author Alejandro Serna
 */

// Initializing the chessboard 8x8
int chessBoard[8][8];
// All 8 possible moves a knight can do
int possibleRows[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int possibleColumns[] = {1, 2, 2, 1, -1, -2, -2, -1};

/**
 * Checks if a move is valid
 * @param row Horizontal position
 * @param column Vertical position
 * @param board 8x8 Chessboard
 * @return True if input is valid, false otherwise
 * The board is populated with -1 at first
 * A spot that has -1 means it hasn't been visited
 */
bool checkValidMove(int row, int column, int board[8][8]) {
    return (row >= 0 && row < 8 && column >= 0 && column < 8 && board[row][column] == -1);
}

/**
 * Wrapper method for solver
 * @param row Row position
 * @param column Column position
 * @param moveCount Keeps count of current move
 * @param board 8x8 Chessboard
 * @param possible_Rows Possible move horizontally
 * @param possible_Columns Possible move vertically
 * @return True if there is a solution, false otherwise
 */
bool solverHelper(int row, int column, int moveCount, int board[8][8], int possible_Rows[], int possible_Columns[]) {
    // Base case assuming all 64 spots have been visited
    if (moveCount == 64) {
        return true;
    }

    for (int i = 0; i < 8; i++) {
        int nextRow = row + possible_Rows[i];
        int nextColumn = column + possible_Columns[i];
        if (checkValidMove(nextRow, nextColumn, board)) {
            board[nextRow][nextColumn] = moveCount;
            if (solverHelper(nextRow, nextColumn, moveCount + 1, board, possible_Rows, possible_Columns)) {
                return true; // If we can find a solution with the current move, return true
            } else { // If the current move didn't find a solution, set spot back to -1 and try next possible move
                board[nextRow][nextColumn] = -1;
            }
        }
    }
    return false;
}

/**
 * Sets up initial chessboard
 * Uses wrapper method to solve
 * Prints out final result
 */
void solver() {
    using std::cout;
    using std::endl;
    // Fills the chessboard with -1
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            chessBoard[i][j] = -1;
        }
    }

    // Starting spot [row][column]
    int startingRow = 0;
    int startingColumn = 0;
    chessBoard[startingRow][startingColumn] = 0;

    if (!solverHelper(startingRow, startingColumn, 1, chessBoard, possibleRows, possibleColumns)) {
        cout << "No solution" << endl;
    } else {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << std::setw(2) << chessBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    solver();
    return 0;
}
