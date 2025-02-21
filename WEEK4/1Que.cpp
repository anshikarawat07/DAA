#include <iostream>
#include <vector>
using namespace std;

int cmp, inv;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) 
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) 
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        cmp++;
        if (L[i] <= R[j]) 
            arr[k++] = L[i++];
         else 
         {
            arr[k++] = R[j++];
            inv += (n1 - i);
        }
    }
    while (i < n1) 
        arr[k++] = L[i++];
    while (j < n2) 
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int t;
    cin >> t;
    vector<vector<int>> arr(t);
    vector<int> comps(t), inverts(t);

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        arr[i].resize(n);
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];

        cmp = inv = 0;
        mergeSort(arr[i], 0, n - 1);
        comps[i] = cmp;
        inverts[i] = inv;
    }

    for (int i = 0; i < t; i++) {
        for (int x : arr[i]) 
            cout << x << " ";
        cout << endl << "comparisons = " << comps[i] << endl << "inversion = " << inverts[i] << endl;
    }

    return 0;
}
