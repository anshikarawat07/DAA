#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; // 0 coins needed for amount 0
    
    for (int i = 1; i <= amount; i++) {
        for (auto c : coins) {
            if (c <= i && dp[i - c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    
    return dp[amount] == INT_MAX ? -1 : dp[amount];
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

    int res = minCoins(coins, amount);
    if (res == -1)
        cout << "Not possible to make the amount with given coins.\n";
    else
        cout << "Minimum coins required: " << res << endl;
    return 0;
}
