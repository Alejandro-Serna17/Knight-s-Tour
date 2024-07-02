/**
 * Knight's Tour Java
 * @author Alejandro Serna
 */

public class Main {

    // Initializing the chessboard 8x8
    int[][] chessBoard = new int[8][8];
    // All 8 possible moves a knight can make
    int[] possibleRows = {-2,-1,1,2,2,1,-1,-2};
    int[] possibleColumns = {1,2,2,1,-1,-2,-2,-1};

    /**
     * Checks if a move is valid
     * @param Row Horizontal position
     * @param Column Vertical position
     * @param board 8x8 Chessboard
     * @return True if input move is valid, false otherwise
     */
    public boolean checkValidMove(int Row, int Column, int[][] board){
        return (Row >= 0 && Row < 8 && Column >=0 && Column < 8 && board[Row][Column] == -1);
    }

    /**
     * Wrapper method for solver
     * @param x Row position
     * @param y Column position
     * @param moveCount Keeps count of current move
     * @param board 8x8 Chessboard
     * @param possibleRows Possible move horizontally
     * @param possibleColumns Possible move vertically
     * @return True if there is a solution, false otherwise
     */
    public boolean solverHelper(int x, int y, int moveCount, int[][] board, int[] possibleRows, int[] possibleColumns) {
        // Base case assuming all 64 spots have been visited
        if(moveCount == 64) {
            return true;
        }

        for (int i = 0; i < 8; i++) {
            int nextX = x + possibleRows[i];
            int nextY = y + possibleColumns[i];
            if (checkValidMove(nextX, nextY, board)) {
                board[nextX][nextY] = moveCount;
                if (solverHelper(nextX, nextY, moveCount + 1, board, possibleRows, possibleColumns))
                    return true;
                else
                    board[nextX][nextY] = -1; // backtracking
            }
        }
        return false;
    }

    /**
     * Sets up initial chessboard
     * Uses helper method to solve
     * Prints out final result
     */
    public void solver() {
        // Fills the chessboard with -1
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                chessBoard[i][j] = -1;
            }
        }

        int startX = 0;
        int startY = 0;
        chessBoard[startX][startY] = 0;

        //If wrapper method returns false, there's no solution
        if (!solverHelper(startX, startY, 1, chessBoard, possibleRows, possibleColumns)) {
            System.out.println("No solution");
        } else {//If there's a solution, print the chessboard
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    System.out.printf("%2d ", chessBoard[i][j]);
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Main knightTour = new Main();
        knightTour.solver();
    }

}
