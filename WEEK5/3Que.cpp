/*I. You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCommonElements(vector<int> &arr1, vector<int> &arr2) {
    sort(arr1.begin(), arr1.end()); 
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;
    vector<int> common;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            common.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    if (common.empty()) {
        cout << "No Common Elements" << endl;
    } else {
        for (int num : common) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0; i < m; i++) 
    cin >> arr1[i];

    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; i++) cin >> arr2[i];

    findCommonElements(arr1, arr2);
    
    return 0;
}
