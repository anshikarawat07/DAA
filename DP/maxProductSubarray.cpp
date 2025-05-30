#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int maxProd = nums[0];
    int currMax = nums[0];
    int currMin = nums[0];
    
    for(int i = 1; i < n; i++) {
        if(nums[i] < 0) swap(currMax, currMin);
        
        currMax = max(nums[i], currMax * nums[i]);
        currMin = min(nums[i], currMin * nums[i]);
        
        maxProd = max(maxProd, currMax);
    }
    
    return maxProd;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements:\n";
    for(int i=0; i<n; i++) cin >> nums[i];
    
    int res = maxProduct(nums);
    cout << "Maximum product subarray: " << res << endl;
    return 0;
}
