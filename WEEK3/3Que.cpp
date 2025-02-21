/*Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Duplicate(vector<int>& a) {
    sort(a.begin(), a.end());
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) 
            return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> arr(t);
    vector<string> results(t);

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        arr[i].resize(n);
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];

        results[i] = Duplicate(arr[i]) ? "YES" : "NO";
    }

    for (const string& res : results) 
        cout << res << endl;

    return 0;
}
