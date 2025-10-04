/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/sudoku-solver/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=17

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(9^9^2 * 9)
// space complexity : O(9^2)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        doSolveSudoku(board);        
    }
private:
    bool doSolveSudoku(vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isValid(i, j, k, board)== true){
                            board[i][j] = k;
                            if(doSolveSudoku(board)==true) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, int k, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[row][i]==k) return false;
            if(board[i][col]==k) return false;
        }
        row = row - row%3;
        col = col - col%3;
        for(int i=row; i<row+3; i++){
            for(int j=col; j<col+3; j++){
                if(board[i][j]==k) return false;
            }
        }
        return true;
    }
};

int main(){
    // Sample input
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution solve;
    solve.solveSudoku(board);
    cout << "[\n";
    for(int i = 0; i < board.size(); ++i){
        cout << '[';
        for(int j = 0; j < board[i].size(); ++j){
            cout << "\"" << board[i][j] << "\"";
            if(j + 1 != board[i].size()) cout << ",";
        }
        cout << ']';
        if(i + 1 != board.size()) cout << ",";
        cout << '\n';
    }
    cout << "]\n";
    return 0;
}
