/*Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays 
based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element.
Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int partition(vector<int> &arr, int l, int h, int &comps, int &swaps) {
    int r = l + rand() % (h - l + 1);
    swap(arr[r], arr[h]);
    swaps++;

    int p = arr[h], i = l - 1;

    for (int j = l; j < h; j++) {
        comps++;
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i + 1], arr[h]);
    swaps++;
    return i + 1;
}

void quickSort(vector<int> &arr, int l, int h, int &comps, int &swaps) {
    if (l < h) {
        int pi = partition(arr, l, h, comps, swaps);
        quickSort(arr, l, pi - 1, comps, swaps);
        quickSort(arr, pi + 1, h, comps, swaps);
    }
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> results;
    vector<int> comparisons(t), swaps(t);

    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int comps = 0, swapCount = 0;

        quickSort(arr, 0, n - 1, comps, swapCount);

        results.push_back(arr);
        comparisons[tc] = comps;
        swaps[tc] = swapCount;
    }

    for (int i = 0; i < t; i++) {
        for (int num : results[i])
            cout << num << " ";
        cout << endl;

        cout << "comparisons = " << comparisons[i] << endl;
        cout << "swaps = " << swaps[i] << endl;
    }
    return 0;
}
