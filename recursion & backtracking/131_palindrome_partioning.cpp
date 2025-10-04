/**
 *  author  : Rajesh
 *  problem : https://leetcode.com/problems/palindrome-partitioning/
 *  updated : 29.09.2025 17:04:04
**/

// tutorial : https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=19

#include <bits/stdc++.h>
using namespace std;

// approach : recursion [pick and not pick] (complicated approach)
// time complexity : O(2^n * n) (it is 2^n because we are generating these number of substrings and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(2^n * n)
class Solution_extra {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        string ds1;
        vector<string> ds2;
        doPartition(0, ds1, ds2, s, ans);
        return ans;
    }
private:
    void doPartition(int i, string& ds1, vector<string>& ds2, string& s, vector<vector<string>>& ans){
        if(i==s.size()){
            if(ds1.size()==0) return;
            if(isPalindrome(ds1)==true){
                ds2.push_back(ds1);
                ans.push_back(ds2);
                ds2.pop_back();
            }
            return;
        }
        ds1.push_back(s[i]);
        // partitioned
        if(isPalindrome(ds1)==true){
            string tmp = ds1;
            ds2.push_back(ds1);
            ds1 = "";
            doPartition(i+1, ds1, ds2, s, ans);
            ds2.pop_back();
            ds1 = tmp;
        }
        // not partitioned
        doPartition(i+1, ds1, ds2, s, ans);
        ds1.pop_back();
    }

    bool isPalindrome(string& s){
        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[s.size()-1-i]) return false;
        }
        return true;
    }
};

// approach : recursion [looping]
// time complexity : O(2^n * n) (it is 2^n because we are generating these number of substrings and multiplied by n bacause we are copying it)
// space complexity : O(n) + O(2^n * n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        doPartition(0, ds, s, ans);
        return ans;
    }
private:
    void doPartition(int ind, vector<string>& ds, string& s, vector<vector<string>>& ans){
        if(ind>=s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                ds.push_back(s.substr(ind, i-ind+1));
                doPartition(i+1, ds, s, ans);
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++; r--;
        }
        return true;
    }
};

int main(){
    // Sample input
    string s = "aab";
    Solution solve;
    vector<vector<string>> result = solve.partition(s);
    cout << '[';
    for(int i = 0; i < result.size(); ++i){
        cout << '[';
        for(int j = 0; j < result[i].size(); ++j){
            cout << "\"" << result[i][j] << "\"";
            if(j + 1 != result[i].size()) cout << ",";
        }
        cout << ']';
        if(i + 1 != result.size()) cout << ",";
    }
    cout << "]\n";

    return 0;
}
