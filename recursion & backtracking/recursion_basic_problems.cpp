#include <bits/stdc++.h>
using namespace std;


void problem1(int i, int n){
    if(i>n) return;
    cout << "Sarah" << '\n';
    problem1(i+1, n);
}
// tc : O(n)
// sc : O(n)

void problem2(int i, int n){
    if(i>n) return;
    cout << i << '\n';
    problem2(i+1, n);
}
// tc : O(n)
// sc : O(n)

void problem3(int i, int n){
    if(i<=0) return;
    cout << i << '\n';
    problem3(i-1, n);
}
// tc : O(n)
// sc : O(n)

void problem4(int n){
    if(n<=0) return;
    problem4(n-1);
    cout << n << '\n';
}
// tc : O(n)
// sc : O(n)

void problem5(int n){
    if(n<=0) return;
    cout << n << '\n';
    problem5(n-1);
}
// tc : O(n)
// sc : O(n)

// parameterized recursion
void problem6(int n, int sum){
    if(n<=0){
        cout << sum << '\n';
        return;
    }
    problem6(n-1, sum+n);
}
// tc : O(n)
// sc : O(n)

// functional recursion
int problem7(int n){
    if(n<=0) return 0;
    return n + problem7(n-1);
}
// tc : O(n)
// sc : O(n)

// functional recursion
int problem8(int n){
    if(n==0) return 1;
    return n*problem8(n-1);
}
// tc : O(n)
// sc : O(n)

void problem9(int i, int j, vector<int> &a){
    if(i>=j) return;
    swap(a[i], a[j]);
    problem9(i+1, j-1, a);
}
// tc : O(n)
// sc : O(n)

bool problem10(int i, int j, string s){
    if(i>=j) return true;
    if(i<j and s[i]!=s[j]) return false;
    return problem10(i+1, j-1, s);
}
// tc : O(n)
// sc : O(n)

// multiple recursion calls
int problem11(int n){
    if(n<=1) return n;
    return problem11(n-1) + problem11(n-2);
}
// tc : O(2^n)
// sc : O(n)

void problem12(int i, vector<int>& ds ,vector<int>& a, int n){
    if(i>=n){
        cout<<"{ "; for(auto x:ds) cout << x << ' '; cout<<"}\n";
        return;
    }
    // picked 
    ds.push_back(a[i]);
    problem12(i+1, ds, a, n);
    ds.pop_back();
    // not picked
    problem12(i+1, ds, a, n);
}
// tc: O(n*2^n)
// sc: O(n)
// for array of size n, number of subsequences is 2^n

void problem13(int i, vector<int>& ds, int sum, int k, vector<int>& a, int n){
    if(i>=n){
        if(sum==k){
            cout<<"{ "; for(auto x:ds) cout << x << ' '; cout<<"}\n";
        }
        return;
    }
    // picked
    ds.push_back(a[i]);
    sum += a[i];
    problem13(i+1, ds, sum, k, a, n);
    ds.pop_back();
    sum -= a[i];
    // not picked
    problem13(i+1, ds, sum, k, a, n);
}
// tc : O(n*2^n)
// sc: O(n)

bool problem14(int i, vector<int> &ds, int sum, int k, vector<int> &a, int n){
    if(i>=n){
        // condition satisfied
        if(sum==k){
            cout<<"{ "; for(auto x:ds) cout << x << " "; cout << "}\n";
            return true;
        }
        // condition not satisfied
        else return false;
    }
    // picked
    ds.push_back(a[i]);
    sum += a[i];
    if(problem14(i+1, ds, sum, k, a, n) == true) return true;
    ds.pop_back();
    sum -= a[i];
    // not picked
    if(problem14(i+1, ds, sum, k, a, n) == true) return true;
    return false;
}
// tc : O(n*2^n)
// sc: O(n)

int problem15(int i, int sum, int k, vector<int> &a, int n){
    if(i>=n){
        // condition satisfied
        if(sum==k) return 1;
        // condition not satisfied
        else return 0;
    }
    // picked
    sum += a[i];
    int l  = problem15(i+1, sum, k, a, n);
    sum -= a[i];
    // not picked
    int r  = problem15(i+1, sum, k, a, n);
    return l+r;
}
// tc : O(2^n)
// sc : O(n)

int main(){
    // print name 5 times
    cout << "Problem 1:" << '\n'; 
    problem1(1, 5);
    
    // print linearly from 1 to n
    cout << "Problem 2:" << '\n'; 
    problem2(1, 5);
    
    // print linearly from n to 1
    cout << "Problem 3:" << '\n'; 
    problem3(5, 5);
    
    // print linearly from 1 to n using backtracking
    cout << "Problem 4:" << '\n'; 
    problem4(5);
    
    // print linearly from n to 1 using backtracking
    cout << "Problem 5:" << '\n'; 
    problem5(5);
    
    // sum from 1 to n using parameterized recursion
    cout << "Problem 6:" << '\n'; 
    problem6(5, 0);
    
    // sum from 1 to n using functional recursion
    cout << "Problem 7:" <<'\n';
    cout << problem7(5) << '\n';
    
    // factorial from 1 to n
    cout << "Problem 8:" <<'\n';
    cout << problem8(5) << '\n';
    
    // reverse an array
    vector<int> a = {1, 2, 3, 4, 5};
    problem9(0, a.size()-1, a);
    cout << "Problem 9:" <<'\n';
    for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
    
    // check if it is palindrome
    string s = "racecar";
    cout << "Problem 10:" <<'\n';
    cout << problem10(0, s.size()-1, s) << '\n';
    
    // n th fibonacci
    cout << "Problem 11:" <<'\n';
    cout << problem11(5) << '\n';
    
    // print all subsequences
    cout << "Problem 12:" <<'\n';
    a = {1, 2, 3, 4};
    vector<int> ds = {};
    problem12(0, ds, a, a.size());
    
    // print all subsequences whose sum is k
    cout << "Problem 13:" <<'\n';
    a = {1, 2, 3, 4};
    ds = {};
    problem13(0, ds, 0, 6, a, a.size());
    
    // print only one subsequence whose sum is k
    cout << "Problem 14:" <<'\n';
    a = {1, 2, 3, 4};
    ds = {};
    problem14(0, ds, 0, 6, a, a.size());
    
    // print number of subsequences whose sum is k
    cout << "Problem 15:" <<'\n';
    a = {1, 2, 3, 4};
    ds = {};
    cout << problem15(0, 0, 6, a, a.size()) << '\n';
    
    return 0;
}