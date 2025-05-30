#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& marks, int m, int maxSum) {
    int groupCount = 1;
    int currentSum = 0;
    for (int mark : marks) {
        if (mark > maxSum) 
            return false;  // single element exceeds maxSum -> no solution
        if (currentSum + mark <= maxSum) {
            currentSum += mark;
        } else {
            groupCount++;
            currentSum = mark;
            if (groupCount > m) return false;
        }
    }
    return true;
}

int splitMarks(vector<int>& marks, int m) {
    int left = *max_element(marks.begin(), marks.end());
    int right = accumulate(marks.begin(), marks.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canSplit(marks, m, mid)) {
            result = mid;
            right = mid - 1;  
        } else {
            left = mid + 1;  
        }
    }
    return result;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> marks(n);
    for (int i = 0; i < n; i++) cin >> marks[i];
    cin >> m;

    cout << splitMarks(marks, m) << "\n";

    return 0;
}
