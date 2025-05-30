#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // each element starts with LIS of length 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLIS = 0;
    for (int x : dp) {
        maxLIS = max(maxLIS, x);
    }

    return maxLIS;
}

int main() {
    vector<int> arr = {5, 1, 8, 2, 3};
    cout << "Length of LIS = " << LIS(arr) << endl;
    return 0;
}
