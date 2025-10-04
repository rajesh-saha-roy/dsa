/**
 *  author  : Rajesh
 *  problem : https://takeuforward.org/plus/dsa/problems/subsets-i
 *  updated : 27.09.2025 16:23:37
**/

// tutorial : https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12

#include <bits/stdc++.h>
using namespace std;

/*
    number of subsets/combinations are 2^N (nC0 + nC1 + nC2 + ... + nCn = 2^N)
    time complexity is O(2^n) because for every index we have 2 options, either to pick it or not to pick it
*/

// approach : recursion [pick and not pick]
// time complexity : O(2^n)
// space complexity : O(n) + O(2^n)
class Solution {
  public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        findSubsetSums(0, 0, nums, ans);
        return ans;
    }
  private:
    void findSubsetSums(int ind, int sum, vector<int>& nums, vector<int>& ans){
        if(ind>=nums.size()){
            ans.push_back(sum);
            return;
        }
        // picked
        findSubsetSums(ind+1, sum+nums[ind], nums, ans);
        // not picked
        findSubsetSums(ind+1, sum, nums, ans);
    }
};

// approach : recursion [looping]
// time complexity : O(2^n) (it is 2^n because we are generating these number of subsets)
// space complexity : O(n) + O(2^n)
class Solution_extra{
  public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        findSubsetSums(0, 0, nums, ans);
        return ans;
    }
  private:
    void findSubsetSums(int ind, int sum, vector<int>& nums, vector<int>& ans){
        ans.push_back(sum);
        for(int i=ind; i<nums.size(); i++){
            findSubsetSums(i+1, sum+nums[i], nums, ans);
        }
    }
};

int main(){
    Solution solve;
    // Sample input
    vector<int> nums = {5, 2, 1};
    vector<int> result = solve.subsetSums(nums);
    sort(result.begin(), result.end());
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i != result.size() - 1) cout << ",";
    }
    cout << "]\n";
    return 0;
}
