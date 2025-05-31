#include <iostream>
#include <vector>
using namespace std;

int countWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // one way to make amount 0
    
    for (auto c : coins) {
        for (int i = c; i <= amount; i++) {
            dp[i] += dp[i - c];
        }
    }
    return dp[amount];
}

int main() {
    int n, amount;
    cout << "Number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations:\n";
    for (int i = 0; i < n; i++) cin >> coins[i];
    cout << "Enter amount: ";
    cin >> amount;

    int res = countWays(coins, amount);
    cout << "Number of ways to make the amount: " << res << endl;
    return 0;
}
