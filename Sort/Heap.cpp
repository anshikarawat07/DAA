#include <iostream>
#include <vector>
using namespace std;

// Heapify a subtree rooted with node i, size is n
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;     // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Build max heap (bottom-up heapify)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: One by one extract elements from heap
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]); // Move current root to end
        heapify(arr, i, 0);   // Heapify reduced heap
    }
}

// Utility to print the array
void printArray(vector<int> &arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
