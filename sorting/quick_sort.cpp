#include <bits/stdc++.h>
using namespace std;

// places the pivot in partition index after partitioning the array and returns the partition index
int partition(vector<int>& a, int l, int r){
    int pivot = a[r];
    int i=l;
    for(int j=l; j<r; j++){
        if(a[j]<=pivot) swap(a[i++], a[j]);
    }
    swap(a[i], a[r]);
    return i;
}

/*
    we always pass the left boundary and the right boundary of the array in sorting algorithms,
    elsewise the sorting algorithm would take a lot of time for array copying in each recursive call
*/
void quickSort(vector<int>& a, int l, int r){
    // base case becomes true when array of size less than or equal 1 is found which is in right position already
    if(l>=r) return;
    int p = partition(a, l, r);
    quickSort(a, l, p-1);
    quickSort(a, p+1, r);
}
/*
    best case / average case complexity : 
    time complexity : O(nlog(n))
    space complexity : O(1)[auxiliary space] + O(log(n))[stack space] = O(log(n))
*/
/*
    worst case complexity : 
    time complexity : O(n^2)
    space complexity : O(1)[auxiliary space] + O(n)[stack space] = O(n)
*/

int main(){
    vector<int> a = {6, 5, 4, 7, 3, 2, 1};
    quickSort(a, 0, a.size()-1);
    cout << "Before Sorting:" << '\n';
    for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
    cout << "After Sorting:" << '\n';
    for(int i=0; i<a.size(); i++) cout << a[i] << ' '; cout << '\n';
    return 0;
}
