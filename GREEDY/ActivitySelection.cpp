#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int asa(vector<pair<int, int>> array) {
    sort(array.begin(), array.end(), compare);
    int count = 1;
    int end_time = array[0].second;

    for (int i = 1; i < array.size(); i++) {
        if (array[i].first >= end_time) {
            count++;
            end_time = array[i].second;
        }
    }

    return count;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    
    vector<pair<int, int>> activities;
    cout << "Enter start and end time of each activity:\n";
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        activities.push_back({start, end});
    }

    int maxActivities = asa(activities);
    cout << "Maximum number of non-overlapping activities: " << maxActivities << endl;

    return 0;
}
