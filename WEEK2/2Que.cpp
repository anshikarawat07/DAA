/*Given a sorted array of positive integers, design an algorithm and implement it using a program
to find three indices i, j, k such that arr[i] + arr[j] = arr[k].*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) 
{
    while (left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void findIndices(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            int sum = arr[i] + arr[j];
            int k = binarySearch(arr, j + 1, n - 1, sum);
            if (k != -1) {
                cout <<"i : "<< i<<"  j : " << j << " k : " << k << endl;
                return;
            }
        }
    }
    cout << "No sequence found" << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        findIndices(arr, n);
    }

    return 0;
}
