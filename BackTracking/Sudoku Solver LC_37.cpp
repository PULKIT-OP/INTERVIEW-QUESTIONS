// Question Link : https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == d){
                return false;
            }
            if(board[i][col] == d){
                return false;
            }
        }
        int st_row = row/3 * 3;    // to get the starting row of the box
        int st_col = col/3 * 3;    // to get the starting col of the box
        for(int m = 0; m < 3; m++){
            for(int n = 0; n < 3; n++){
                if(board[st_row + m][st_col + n] == d){
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char d = '1'; d <= '9'; d++){
                        if(isValid(board, i, j, d)){
                            board[i][j] = d;        // take step

                            if(solve(board) == true){       // explore
                                return true;
                            }

                            board[i][j] = '.';      // undo step
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};
