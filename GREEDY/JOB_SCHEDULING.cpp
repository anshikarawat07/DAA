#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, char>> a, pair<int, pair<int, char>> b) {
    return a.first > b.first; // sort by profit descending
}

void jobScheduling(vector<pair<int, pair<int, char>>> jobs, int n) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find max deadline to determine number of slots
    int max_deadline = 0;
    for (auto job : jobs) {
        max_deadline = max(max_deadline, job.second.first);
    }

    vector<bool> slot(max_deadline + 1, false);  // time slots
    vector<char> result(max_deadline + 1);       // store job ID at time

    int total_profit = 0;

    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].second.first;
        int profit = jobs[i].first;
        char id = jobs[i].second.second;

        // Find a free slot before or on deadline
        for (int j = deadline; j > 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = id;
                total_profit += profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 1; i <= max_deadline; i++) {
        if (slot[i])
            cout << result[i] << " ";
    }
    cout << "\nTotal Profit: " << total_profit << endl;
}

int main() {
    // Format: {profit, {deadline, job_id}}
    vector<pair<int, pair<int, char>>> jobs = {
        {100, {2, 'A'}},
        {19, {1, 'B'}},
        {27, {2, 'C'}},
        {25, {1, 'D'}},
        {15, {3, 'E'}}
    };

    int n = jobs.size();
    jobScheduling(jobs, n);
    return 0;
}
