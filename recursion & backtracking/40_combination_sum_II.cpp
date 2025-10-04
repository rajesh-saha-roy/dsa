/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/combination-sum-ii/description/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11
//          : https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

#include <bits/stdc++.h>
using namespace std;

/*
    number of combinations are 2^N (nC0 + nC1 + nC2 + ... + nCn = 2^N)
    here if all the combinations are generated then used a set for removing duplicates,
      then the time complexity would have been O(2^n * n) + O(2^nlog(2^n)), which is not optimal 
*/

// approach : recursion [looping] (cannot use pick and not pick because there can't be any duplicates) 
// time complexity : O(2^n * n) (it is 2^n because we are generating these number of combinations and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(2^n * n)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinationSum2(0, ds, 0, target, candidates, ans);
        return ans;
    }
private:
    void findCombinationSum2(int i, vector<int>& ds, int sum, int tar, vector<int>& c, vector<vector<int>>& ans){
        if(sum==tar){
            ans.push_back(ds);
            return;
        }
        for(int j=i; j<c.size(); j++){
            if(j>i and c[j]==c[j-1]) continue;
            if(sum+c[j]>tar) break;
            ds.push_back(c[j]);
            findCombinationSum2(j+1, ds, sum+c[j], tar, c, ans);
            ds.pop_back();
        }
    }
};

int main(){
    Solution solve;
    // Sample input
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = solve.combinationSum2(candidates, target);
    cout << "[\n";
    for(int i = 0; i < result.size(); i++) {
        cout << "[";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if(j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ",";
        cout << '\n';
    }
    cout << "]\n";
    return 0;
}
