#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSumIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(arr.begin(), arr.end()); // dp[i] = max sum ending at i
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for(int i=0; i<n; i++) cin >> arr[i];
    
    int res = maxSumIS(arr);
    cout << "Maximum sum increasing subsequence: " << res << endl;
    return 0;
}
