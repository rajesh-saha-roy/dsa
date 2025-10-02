#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1, vector<int>(n+1));

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        // for weighted graph, store the weight in g[x][y]
        // for unweighted graph, store the weight as 1 in g[x][y]
        g[x][y] = 1;
        g[y][x] = 1;
    }

    cout << "adjacency matrix of the given graph is:" << '\n';
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++) cout << g[i][j] << ' ';
        cout << '\n';
    }

    if(g[3][7]!=0) cout << "there is an edge between node 3 and node 7" << '\n';
    else cout << "there is no edge between node 3 and node 7" << '\n';

    return 0;
}
// time complexity : O(n²)
// space complexity : O(n²)
// time complexity to see if 2 nodes are connected : O(1)


/*
sample input:
7 7
1 2
1 3
2 4
2 5
2 6
2 7
3 7

expected output:
adjacency matrix of the given graph is:
0 1 1 0 0 0 0
1 0 0 1 1 1 1
1 0 0 0 0 0 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 1 0 0 0 0
there is an edge between node 3 and node 7
*/
