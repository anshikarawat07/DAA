#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    // Count frequency of each task
    for (char task : tasks) {
        freq[task - 'A']++;
    }
    // Find the maximum frequency
    int max_freq = *max_element(freq.begin(), freq.end());

    // Count how many tasks have this max frequency
    int max_count = count(freq.begin(), freq.end(), max_freq);

    // Formula: (max_freq - 1) * (n + 1) + max_count
    int result = (max_freq - 1) * (n + 1) + max_count;

    // Return the maximum of either the formula result or total number of tasks
    return max((int)tasks.size(), result);
}

int main() {
    int s;
    cin >> s;
    vector<char> tasks(s);
    for (int i = 0; i < s; i++) {
        cin >> tasks[i];
    }
    int n;
    cin >> n;

    cout << leastInterval(tasks, n) << endl;
    return 0;
}
