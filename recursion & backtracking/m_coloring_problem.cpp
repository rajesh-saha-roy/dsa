/**
 *  author  : Rajesh
 *  problem : https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=wuVwUK25Rfc&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(m^n * n) (it is m^n, because for every node n we have m options and multiplied by n for checking the validity)
// space complexity : O(n) + O(n+e)
class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>>& edges, int m) {
        vector<int> color(v+1);
        vector<vector<int>> g(v);
        for(int i=0; i<edges.size(); i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        return doGraphColoring(0, v, m, color, g);
    }
  private:
    bool doGraphColoring(int node, int v, int m, vector<int>& color, vector<vector<int>>& g){
        if(node==v){
            return true;
        }
        for(int i=1; i<=m; i++){
            if(isValid(node, i, color, g)){
                color[node] = i;
                if(doGraphColoring(node+1, v, m, color, g) == true) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool isValid(int node, int c, vector<int>& color, vector<vector<int>>& g){
        for(int x:g[node]) if(color[x]==c) return false;
        return true;
    }
};

int main(){
    Solution solve;
    // Sample input 1
    int v = 4;
    vector<vector<int>> edges = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    int m = 3;
    bool result = solve.graphColoring(v, edges, m);
    cout << (result==true? "true":"false") << '\n';
    // Sample input 2
    v = 3;
    edges = {{0, 1}, {1, 2}, {0, 2}};
    m = 2;
    result = solve.graphColoring(v, edges, m);
    cout << (result==true? "true":"false") << '\n';
    return 0;
}
