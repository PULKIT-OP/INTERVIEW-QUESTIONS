// Question Link : https://leetcode.com/problems/valid-sudoku/description/

// Approach 1 : Traverse rows, then Columns, then boxes
class Solution {
public:
    bool traversal(int sr, int er, int sc, int ec, vector<vector<char>> &board){
        unordered_set<char> s;
        for(int row = sr; row <= er; row++){
            for(int col = sc; col <= ec; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(s.find(board[row][col]) != s.end()){
                    return false;
                }
                s.insert(board[row][col]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // traversing rows
        for(int row = 0; row < 9; row++){
            unordered_set<char> st;
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // traversing cols
        for(int col = 0; col < 9; col++){
            unordered_set<char> st;
            for(int row = 0; row < 9; row++){
                if(board[row][col] == '.'){
                    continue;
                }
                if(st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // traversing squares
        for(int row = 0; row < 9; row += 3){
            int er = row + 2;
            for(int col = 0; col < 9; col += 3){
                int ec = col + 2;
                if(traversal(row, er, col, ec, board) == false){
                    return false;
                }
            }
        }

        return true;

    }
};


// Approach 2 : Store rows entries, col entries and box entries then check for the same
class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                string row = string(1, board[i][j]) + "_ROW_" + to_string(i);
                string col = string(1, board[i][j]) + "_COL_" + to_string(j);
                string box = string(1, board[i][j]) + "_BOX_" + to_string(i/3) + to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end()){
                    return false;
                }
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        return true;
    }
};
