#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items and capacity: ";
    cin >> n >> W;
    vector<int> val(n), wt(n);
    cout << "Enter values: ";
    for (int &v : val) cin >> v;
    cout << "Enter weights: ";
    for (int &w : wt) cin >> w;

    cout << "Max value: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
