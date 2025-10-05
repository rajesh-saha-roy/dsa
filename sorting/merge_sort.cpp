#include <bits/stdc++.h>
using namespace std;

// merge two sorted arrays
void merge(vector<int>& a, int l, int mid, int r){
    vector<int> tmp;
    int i=l, j=mid+1;
    while(i<=mid and j<=r){
        if(a[i]<=a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while(i<=mid) tmp.push_back(a[i++]);
    while(j<=r) tmp.push_back(a[j++]);
    for(int i=l; i<=r; i++) a[i]=tmp[i-l];
}

/*
    we always pass the left boundary and the right boundary of the array in sorting algorithms,
    elsewise the sorting algorithm would take a lot of time for array copying in each recursive call
*/
void mergeSort(vector<int>& a, int l, int r){
    // base case becomes true when array of size less than or equal 1 is found which is sorted already
    if(l>=r) return;
    int mid = (l+r)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, r);
    merge(a, l, mid, r);
}
// time complexity : O(nlog(n))
// space complexity : O(n)[auxiliary space] + O(logn2)[stack space] = O(n)
// the best case, average cose and worst case complexies remain the same
/*
    time complexity is log(n) for dividing the array and O(n) for merging at each division,
    which makes the overall time complexity as O(nlog(n)).
    though there are a bunch of dividing and merging operations, but overall it becomes
    compensated and remains as O(nlog(n)
    
    to avoid repeated allocations of the tmp vector in each merge, we can allocate tmp once in main 
    and pass it by reference to both mergeSort and merge to improve constant factors
*/

int main(){
    vector<int> a = {6, 5, 4, 7, 3, 2, 1};
    mergeSort(a, 0, a.size()-1);
    cout << "Before Sorting:" << '\n';
    for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
    cout << "After Sorting:" << '\n';
    for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
    return 0;
}
