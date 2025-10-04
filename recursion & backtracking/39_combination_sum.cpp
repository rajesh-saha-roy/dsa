/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/combination-sum/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=OyZFFqQtu98&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10
//          : https://takeuforward.org/data-structure/combination-sum-1/

#include <bits/stdc++.h>
using namespace std;

// approach : recursion [pick or not pick]
// time complexity : O(2^t * k) where t is the target, k is the average length
// space complexity : O(k*x), k is the average length and x is the no. of combinations
/*
    Reason: Assume if you were not allowed to pick a single element multiple times,
    every element will have a couple of options: pick or not pick which is 2^n different recursion calls,
    also assuming that the average length of every combination generated is k. 
    (to put length k data structure into another data structure)
    Why not (2^n) but (2^t) (where n is the size of an array)?
    Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinationSum(candidates, target, 0, ds, 0, ans);
        return ans;
    }
private:
    void findCombinationSum(vector<int>& c, int tar, int i, vector<int>& ds, int sum, vector<vector<int>>& ans) {
        if(i>=c.size()){
            if(sum==tar) ans.push_back(ds);
            return;
        }
        if(sum+c[i]<=tar){
            sum += c[i];
            ds.push_back(c[i]);
            // picked
            findCombinationSum(c, tar, i, ds, sum, ans);
            sum -= c[i];
            ds.pop_back();
        }
        // not picked
        findCombinationSum(c, tar, i+1, ds, sum, ans);
    }
};

int main(){
    Solution solve;
    // Sample input
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solve.combinationSum(candidates, target);
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if(j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ",";
    }
    cout << "]\n";
    return 0;
}
