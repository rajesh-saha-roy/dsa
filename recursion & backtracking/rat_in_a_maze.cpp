/**
 *  author  : Rajesh
 *  problem : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
 *  updated : 29.09.2025 21:03:58
**/

// tutorial : https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=20

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(4^n^2 * n)
// space complexity : O(4^n^2 * n)
class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string ds;
        maze[0][0] = 0;
        doRatInMaze(0, 0, ds, maze, ans);
        return ans;
    }
  private:
    void doRatInMaze(int r, int c, string& ds, vector<vector<int>>& maze, vector<string>& ans){
        int n =  maze.size();
        // base condition
        if(r==n-1 and c==n-1){
            ans.push_back(ds);
            return;
        }
        // go down
        if(r+1<n and maze[r+1][c]==1){
            ds.push_back('D');
            maze[r+1][c] = 0;
            doRatInMaze(r+1, c, ds, maze, ans);
            ds.pop_back();
            maze[r+1][c] = 1;
        }
        // go left
        if(c-1>=0 and maze[r][c-1]==1){
            ds.push_back('L');
            maze[r][c-1] = 0;
            doRatInMaze(r, c-1, ds, maze, ans);
            ds.pop_back();
            maze[r][c-1] = 1;
        }
        // go right
        if(c+1<n and maze[r][c+1]==1){
            ds.push_back('R');
            maze[r][c+1] = 0;
            doRatInMaze(r, c+1, ds, maze, ans);
            ds.pop_back();
            maze[r][c+1] = 1;
        }
        // go up
        if(r-1>=0 and maze[r-1][c]==1){
            ds.push_back('U');
            maze[r-1][c] = 0;
            doRatInMaze(r-1, c, ds, maze, ans);
            ds.pop_back();
            maze[r-1][c] = 1;
        }
    }
};

/*technique to reduce 4 if statements to 1 if statement*/
// approach : recursion
// time complexity : O(4^n^2 * n)
// space complexity : O(4^n^2 * n)
class Solution_extra {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string ds;
        vector<int> dr = {1, 0, 0, -1};
        vector<int> dc = {0, -1, 1, 0};
        string dir = "DLRU";
        maze[0][0] = 0;
        doRatInMaze(0, 0, ds, maze, dir, dr, dc, ans);
        return ans;
    }
  private:
    void doRatInMaze(int r, int c, string& ds, vector<vector<int>>& maze, string& dir, vector<int>& dr, vector<int>& dc, vector<string>& ans){
        int n =  maze.size();
        // base condition
        if(r==n-1 and c==n-1){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<4; i++){
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if(next_r>=0 and next_r<n and next_c>=0 and next_c<n and maze[next_r][next_c]==1){
                maze[next_r][next_c] = 0;
                ds.push_back(dir[i]);
                doRatInMaze(next_r, next_c, ds, maze, dir, dr, dc, ans);
                maze[next_r][next_c] = 1;
                ds.pop_back();
            }
        }
    }
};

int main(){
    Solution_extra solve;
    // Sample input 1
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> result = solve.ratInMaze(maze);
    cout << '[';
    for(int i=0; i<result.size(); i++){
        cout << "\"" << result[i] << "\"";
        if(i!=result.size()-1) cout << ", "; 
    }
    cout << "]\n";
    return 0;
}
