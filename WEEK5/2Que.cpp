/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T; 

    vector<string> res; 

    while (T--) {
        int n, key;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> key;

        sort(arr.begin(), arr.end()); 

        int l = 0, r = n - 1;
        bool found = false;

        while (l < r) {
            int sum = arr[l] + arr[r];

            if (sum == key) {
                res.push_back(to_string(arr[l]) + " " + to_string(arr[r]));
                found = true;
                break;
            } else if (sum < key) {
                l++;
            } else {
                r--;
            }
        }

        if (!found) res.push_back("No Such Element Exist");
    }

    for (const string &s : res) {
        cout << s << endl;
    }

    return 0;
}
