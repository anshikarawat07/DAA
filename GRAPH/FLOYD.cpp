#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Floyd-Warshall function
void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Replace -1 with "infinity" and 0 on diagonals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9;  // large number as "infinity"
            }
            if (i == j) matrix[i][j] = 0;
        }
    }

    // Step 2: Floyd-Warshall main logic
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j],
                                   matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // Step 3: Convert "infinity" back to -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    cout << "Enter the adjacency matrix (use -1 for no edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    shortest_distance(matrix);

    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
