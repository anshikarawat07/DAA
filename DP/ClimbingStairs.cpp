#include <iostream>
using namespace std;

// Climbing Stairs: Number of distinct ways to climb to nth step
int climbStairs(int n) {
    if (n <= 1) return 1;
    int prev = 1, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = curr + prev;
        prev = temp;
    }
    return curr;
}

int main() {
    cout << "Enter number of steps: ";
    int n;
    cin >> n;
    int ways = climbStairs(n);
    cout << "Number of ways to climb " << n << " steps: " << ways << endl;
    return 0;
}
