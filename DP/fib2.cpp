#include <iostream>
#include <vector>
using namespace std;

// Memoization function
int fib(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n]; // already computed
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp); // store and return
}

int main() {
    int n;
    cout << "Enter number of terms: ";
    cin >> n;

    vector<int> dp(n + 1, -1); // initialize memo table

    cout << "Fibonacci Series up to " << n << " terms:\n";
    for (int i = 0; i < n; i++) {
        cout << fib(i, dp) << " ";
    }
    cout << endl;

    return 0;
}
