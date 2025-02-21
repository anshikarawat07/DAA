/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))*/
#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) 
        {
            result = mid;
            high = mid - 1;
        } 
        else if (arr[mid] < key) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key)
{
    int low = 0, high = n - 1, result = -1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) 
        {
            result = mid;
            low = mid + 1;  
        } 
        else if (arr[mid] < key) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    return result;
}

int main() {
    int T, n, key;
    cin >> T; 
    while (T--) {
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];  

        cin >> key;  

        int first = firstOccurrence(arr, n, key);
        if (first == -1) 
            cout << key << " Not Present" << endl;
        else {
            int last = lastOccurrence(arr, n, key);
            int count = last - first + 1;
            cout << key << " Present " << count <<"times"<<3 endl;
        }
    }
    return 0;
}
