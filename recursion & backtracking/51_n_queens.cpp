/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/n-queens/description/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=16

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(n! * n)
// space complexity : O(n) + O(n! * n^2)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ds(n, string(n,'.'));
        findSolveNQueens(0, ds, ans, n);
        return ans;
    }

private:
    void findSolveNQueens(int col, vector<string>& ds, vector<vector<string>>& ans, int n){
        if(col>=n){
            ans.push_back(ds);
            return;
        }
        for(int r=0; r<n; r++){
            if(isSafe(r, col, ds, n)){
                ds[r][col] = 'Q';
                findSolveNQueens(col+1, ds, ans, n);
                ds[r][col] = '.';
            }
        }
    }

    // here the 3 loops can be optimized to 1 loop with some technique
    bool isSafe(int row, int col, vector<string>& ds, int n){
        for(int c = col; c>=0; c--){
            if(ds[row][c]=='Q') return false;
        }
        for(int r=row, c=col; r>=0 and c>=0; r--,c--){
            if(ds[r][c]=='Q') return false;    
        }
        for(int r=row, c=col; r<n and c>=0; r++,c--){
            if(ds[r][c]=='Q') return false;
        }
        return true;
    }
};

int main(){
    // Sample input
    int n = 4;
    Solution solve;
    vector<vector<string>> result = solve.solveNQueens(n);
    cout << '[';
    for(int i = 0; i < result.size(); ++i){
        cout << '[';
        for(int j = 0; j < result[i].size(); ++j){
            cout << "\"" << result[i][j] << "\"";
            if(j + 1 != result[i].size()) cout << ",";
        }
        cout << ']';
        if(i + 1 != result.size()) cout << ",";
    }
    cout << "]\n";
    return 0;
}
