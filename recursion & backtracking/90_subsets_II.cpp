/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/subsets-ii/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13

#include <bits/stdc++.h>
using namespace std;

/*
    number of subsets/combinations are 2^N (nC0 + nC1 + nC2 + ... + nCn = 2^N)
    here if all the subsets are generated then used a set for removing duplicates,
      then the time complexity would have been O(2^n * n) + O(2^nlog(2^n)), which is not optimal 
*/

// approach : recursion [looping] (cannot use pick and not pick because there can't be any duplicates) 
// time complexity : O(2^n * n) (it is 2^n because we are generating these number of subsets and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(2^n * n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsetsWithDup(0, ds, nums, ans);
        return ans;
    }
private:
    void findSubsetsWithDup(int i, vector<int>& ds, vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(ds);
        for(int j=i; j<nums.size(); j++){
            if(j>i and nums[j]==nums[j-1]) continue;
            ds.push_back(nums[j]);
            findSubsetsWithDup(j+1, ds, nums, ans);
            ds.pop_back();
        }
    }
};

int main(){
    Solution solve;
    // Sample input
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solve.subsetsWithDup(nums);
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
