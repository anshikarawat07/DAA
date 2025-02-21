/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K. */
#include <iostream>
#include <unordered_map>
using namespace std;

int countPairs(int arr[], int n, int k) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    for (int i = 0; i < n; i++) {
        if (freq[arr[i] + k])
            count += freq[arr[i] + k];

        if (k > 0 && freq[arr[i] - k]) 
            count += freq[arr[i] - k];

        freq[arr[i]] = 0;
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cin >> k;
        cout << countPairs(arr, n, k) << endl;
    }

    return 0;
}
