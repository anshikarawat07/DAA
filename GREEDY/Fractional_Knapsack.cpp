#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to perform fractional knapsack
double fractionalKnapsack(int W, vector<pair<int, int>>& items) {
    // Sort items by value/weight ratio in descending order
    sort(items.begin(), items.end(), [](pair<int, int>& a, pair<int, int>& b) {
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        return r1 > r2;
    });

    double totalValue = 0.0;

    for (auto item : items) {
        int value = item.first;
        int weight = item.second;

        if (W >= weight) {
            // Take full item
            W -= weight;
            totalValue += value;
        } else {
            // Take fractional part
            totalValue += value * ((double)W / weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<pair<int, int>> items(n); // {value, weight}

    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in knapsack = " << maxValue << endl;

    return 0;
}
