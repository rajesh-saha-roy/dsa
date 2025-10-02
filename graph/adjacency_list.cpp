#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1);
    // for weighted graph, use vector<vector<pair<int,int>> (see the code of dijkstra)
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << "adjacency list of the given graph is:" << '\n';
    for(int i=1; i<=n; i++){
        cout << i << " -> ";
        for(int x:g[i]) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
// time complexity : O(n+e)
// space complexity : O(n+e)
// time complexity to see if 2 nodes are connected : O(n)


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
adjacency list of the given graph is:
1 -> 2 3
2 -> 1 4 5 6 7
3 -> 1 7
4 -> 2
5 -> 2
6 -> 2
7 -> 2 3
*/
