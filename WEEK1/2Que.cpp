/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).*/

#include <iostream>
using namespace std;

bool binarySearch(int arr[], int n, int key, int &cmp) {
    int l = 0, r = n - 1;
    cmp = 0;

    while (l <= r) {
        int m = l + (r - l) / 2;
        cmp++;

        if (arr[m] == key) return true;
        else if (arr[m] < key) l = m + 1;
        else r = m - 1;
    }
    return false;
}

int main() {
    int n, key, cmp;
    cout << "Enter n: ";
    cin >> n;
    int arr[n];

    cout << "Enter sorted arr: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter key: ";
    cin >> key;

    if (binarySearch(arr, n, key, cmp))
        cout << "Found in " << cmp << " comparisons\n";
    else
        cout << "Not found in " << cmp << " comparisons\n";

    return 0;
}
