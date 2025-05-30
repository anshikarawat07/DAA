#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
    sort(coins.begin(), coins.end());

    int currentChangeCreated = 0;
    for (int coin : coins) {
        if (coin > currentChangeCreated + 1) {
            return currentChangeCreated + 1;
        }
        currentChangeCreated += coin;
    }
    return currentChangeCreated + 1;
}

int main() {
    vector<int> coins = {5, 7, 1, 1, 2, 3, 22};
    cout << "Minimum non-constructible change: " << nonConstructibleChange(coins) << endl;
    return 0;
}
