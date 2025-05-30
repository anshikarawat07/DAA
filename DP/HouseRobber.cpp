#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// House Robber: Max money without robbing adjacent houses
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
}

int main() {
    cout << "Enter number of houses: ";
    int n;
    cin >> n;
    vector<int> money(n);
    cout << "Enter money in each house separated by space:\n";
    for (int i = 0; i < n; i++) {
        cin >> money[i];
    }
    int maxMoney = rob(money);
    cout << "Maximum money that can be robbed: " << maxMoney << endl;
    return 0;
}
