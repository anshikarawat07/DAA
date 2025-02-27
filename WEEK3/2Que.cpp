/*Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.*/

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a, int &cmp, int &swaps) {
    int n = a.size();
    cmp = 0, swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            cmp++;
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx !=i)
        {
            swap(a[i], a[minIdx]);
            swaps++;
        }
    }
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> arr(t);  
    vector<int> cmp(t), swaps(t);

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n;
        arr[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> x;
            arr[i][j] = x;
        }
        selectionSort(arr[i], cmp[i], swaps[i]);
    }

    for (int i = 0; i < t; i++) {
        for (int x : arr[i]) 
            cout << x << " ";
        cout << endl << "cmp = " << cmp[i] << endl << "swaps = " << swaps[i] << endl;
    }

    return 0;
}
