/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] <key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the elementkey. (Complexity < O(n), where n is the number of elements need to be scanned for searching):Jump Search*/
#include <iostream>
#include <cmath>
using namespace std;

int JumpSearch(int arr[], int n, int key, int &cmp) {
    cmp = 0;
    int step = 1, k = 0;

    while (step < n && arr[step - 1] < key) {
        cmp++; 
        step += pow(2, k++);
    }

    int prev = step / 2;
    for (int i = prev; i < min(step, n); i++) {
        cmp++; 
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    int T, n, key;
    cin >> T;

    while (T--) {
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cin >> key;
        int cmp;
        int result =JumpSearch(arr, n, key, cmp);

        if (result != -1) {
            cout << "Present " <<endl<<"Comparisons :" <<cmp << endl;
        } else {
            cout << "Not Present " <<endl<<"Comparisons : " << cmp << endl;
        }
    }

    return 0;
}
