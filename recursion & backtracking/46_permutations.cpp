/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/permutations/
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14
//            https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=15

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(n! * n) (it is n! because we are generating these number of permutations and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(n! * n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> m(nums.size());
        findPermute(ds, m, nums, ans);
        return ans;
    }
private:
    void findPermute(vector<int>& ds, vector<bool>& m, vector<int>& nums, vector<vector<int>>& ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(m[i]==1) continue;
            ds.push_back(nums[i]);
            m[i] = 1;
            findPermute(ds, m, nums, ans);
            ds.pop_back();
            m[i] = 0;
        }
    }
};

// approach : recursion
// time complexity : O(n! * n) (it is n! because we are generating these number of permutations and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(n! * n) [space optimized as ds and map vector are not used]
class Solution_extra {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        findPermute(0, nums, ans);
        return ans;
    }
private:
    void findPermute(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]);
            findPermute(i+1, nums, ans);
            swap(nums[i], nums[j]);
        }
    }
};

int main(){
    Solution solve;
    // Sample input
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solve.permute(nums);
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
