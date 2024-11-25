#include <vector>
using namespace std;

class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { 
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) { 
                            board[i][j] = c; 

                            if (solve(board)) {
                                return true; 
                            } else {
                                board[i][j] = '.'; 
                            }
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
            
            if (board[i][col] == c) {
                return false;
            }
            
            int subGridRow = 3 * (row / 3) + i / 3;
            int subGridCol = 3 * (col / 3) + i % 3;
            if (board[subGridRow][subGridCol] == c) {
                return false;
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solution;
    solution.solveSudoku(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
