/*Given an array of nonnegative integers, design a linear algorithm and implement it using a
program to find whether given key element is present in the array or not. Also, find total number
of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)*/
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) 
{
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) {
            return i+1;
        }
    }
    return -1;
}

int main() 
{
    int t, n, key;
    cin >> t;
    int res[t];

    for (int i = 0; i < t; i++) 
    {
        cin >> n;
        int arr[n];

        for (int j = 0; j < n; j++) 
            cin >> arr[j];

        cin >> key;
        res[i] = linearSearch(arr, n, key);
    }

    for (int i = 0; i < t; i++) {
        if (res[i] != -1) 
            cout << "Present " << res[i] << endl;
         else 
            cout << "Not Present " << endl;
    }

    return 0;
}
