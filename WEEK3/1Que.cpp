/*Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number 
of times the array elements are shifted from their place) required for sorting the array.*/

#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& a, int &cmp, int &shift) {
    int n = a.size();
    cmp = 0, shift = 0;

    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--, cmp++, shift++;
        }
        if (j >= 0) cmp++;  
        a[j + 1] = key;
        shift++;
    }
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> arr(t);  
    vector<int> cmp(t), shift(t);

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n;
        arr[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> x;
            arr[i][j] = x;
        }
        insertionSort(arr[i], cmp[i], shift[i]);
    }

    for (int i = 0; i < t; i++) {
        for (int x : arr[i]) 
            cout << x << " ";
        cout << endl << "cmp = " << cmp[i] << endl << "shift = " << shift[i] << endl;
    }

    return 0;
}
