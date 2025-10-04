/**
 *  author  : Rajesh
 *  problem : https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
 *  updated : 05.10.2025 03:56:15
**/

// tutorial : https://www.youtube.com/watch?v=AseUmwVNaoY&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=22

#include <bits/stdc++.h>
using namespace std;

/*
    the whole solution does the merge sort algorithm with some little tweaks to do the inversion count
*/

// time complexity : O(nlog(n))
// space complexity : O(n)[auxiliary space] + O(logn2)[stack space] = O(n)
class Solution {
  public:
    int inversionCount(vector<int> &arr) {
        return doInversionCount(arr, 0, arr.size()-1);
    }
  private:
    // merge two sorted arrays
    int merge(vector<int>& a, int l, int mid, int r){
        int cnt = 0;
        vector<int> tmp;
        int i=l, j=mid+1;
        while(i<=mid and j<=r){
            if(a[i]<=a[j]) tmp.push_back(a[i++]);
            // right is smaller
            else{
                tmp.push_back(a[j++]);
                // inversion count is done here
                cnt += mid-i+1;
            }
        }
        while(i<=mid) tmp.push_back(a[i++]);
        while(j<=r) tmp.push_back(a[j++]);
        for(int i=l; i<=r; i++) a[i]=tmp[i-l];
        return cnt;
    }

    int doInversionCount(vector<int>& a, int l, int r){
        int cnt = 0;
        if(l>=r) return 0;
        int mid = (l+r)/2;
        cnt += doInversionCount(a, l, mid);
        cnt += doInversionCount(a, mid+1, r);
        cnt += merge(a, l, mid, r);
        return cnt;
    }
};

int main(){
    // sample input
    vector<int> arr = {2, 4, 1, 3, 5};
    Solution solve;
    cout << solve.inversionCount(arr) << '\n';
    return 0;
}
