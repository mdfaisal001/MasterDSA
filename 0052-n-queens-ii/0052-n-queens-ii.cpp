#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Recursive function to solve N-Queens
    void solveNQueen(int row, int col, vector<string> &board, vector<vector<string>> &result, int n) {
        // Base case: if all rows are filled, add the board to the result
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing the queen in every column of the current row
        for (int i = 0; i < n; i++) {
            // Check if placing a queen at (row, i) is safe
            if (isSafe(row, i, board, n)) {
                board[row][i] = 'Q'; // Place queen
                solveNQueen(row + 1, i, board, result, n); // Recurse for next row
                board[row][i] = '.'; // Backtrack: Remove queen and try next column
            }
        }
    }

    // Helper function to check if it's safe to place a queen
    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check the same column upwards
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') 
                return false;
        }

        // Check top-left diagonal
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') 
                return false;
        }

        // Check top-right diagonal
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') 
                return false;
        }

        return true; // No clashes, it's safe
    }

public:
    // Main function to call and return all solutions
    int totalNQueens(int n) {
        vector<vector<string>> result; // To store all valid boards
        vector<string> board(n, string(n, '.')); // Create an empty board
        solveNQueen(0, 0, board, result, n); // Start solving from row 0
        return result.size();
    }
};
