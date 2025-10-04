/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/permutation-sequence/description/
 *  updated : 29.09.2025 22:00:40
**/

// tutorial : https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=21

#include <bits/stdc++.h>
using namespace std;

// approach : recursion
// time complexity : O(n! * n) (it is n! because we are generating these number of permutations and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(n)
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        string ds;
        vector<int> map(n+1);
        int cnt = 0;
        doGetPermutation(0, ds, map, n, cnt, k, ans);
        return ans;
    }
private:
    bool doGetPermutation(int t, string& ds, vector<int>& map, int n, int& cnt, int k, string& ans){
        if(t>=n){
            cnt++;
            if(cnt==k){
                ans = ds;
                return true;
            }
            return false;
        }
        for(char i='1'; i<=n+'0'; i++){
            if(map[i-'0']==0){
                map[i-'0'] = 1;
                ds.push_back(i);
                if(doGetPermutation(t+1, ds, map, n, cnt, k, ans) == true) return true;;
                ds.pop_back();
                map[i-'0'] = 0;
            }
        }
        return false;
    }
};

/* there is even an optimal solution to this problem, where the time complexity is O(n^2) and space complexity is O(n)*/

int main(){
    Solution solve;
    // Sample input 1
    int n = 3, k = 3;
    cout << solve.getPermutation(n, k) << '\n';
    // Sample input 1
    n = 4, k = 9;
    cout << solve.getPermutation(n, k) << '\n';
    return 0;
}
