#include <iostream>
#include <vector>
using namespace std;

int matrixChainOrder(vector<int>& dims) {
    int n = dims.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {  // chain length
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<int> dims(n+1);
    cout << "Enter dimensions: ";
    for (int &x : dims) cin >> x;

    cout << "Minimum multiplications: " << matrixChainOrder(dims) << endl;
    return 0;
}
