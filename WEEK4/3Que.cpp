/*Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n)
QUICKSELECT ALGO*/
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[r]; 
    int i = l; 

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]); 
    return i; 
}
int quickSelect(vector<int> &arr, int l, int r, int k) {
    if (l <= r) {
        int pivotIndex = partition(arr, l, r);

        if (pivotIndex == k) 
            return arr[pivotIndex]; 
        else if (pivotIndex > k) 
            return quickSelect(arr, l, pivotIndex - 1, k);
        else 
            return quickSelect(arr, pivotIndex + 1, r, k);
    }
    return -1; 
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n ;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        cin>>k;

        cout << "Kth smallest: " << quickSelect(arr, 0, n - 1, k - 1) << endl;
        cout << "Kth largest: " << quickSelect(arr, 0, n - 1, n - k) << endl;
    }

    return 0;
}
