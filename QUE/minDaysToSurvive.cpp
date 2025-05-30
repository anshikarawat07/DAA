#include <iostream>
#include <cmath>
using namespace std;

int minDaysToSurvive(int N, int K, int S) {
    // If you need more chocolates per day than you can buy in a day, it's impossible
    if (K > N)
        return -1;

    // Total Sundays in S days
    int sundays = S / 7;

    // Days shop is open
    int availableDays = S - sundays;

    // Total chocolates needed
    int totalChocolates = K * S;

    // Minimum number of days to buy chocolates (ceil)
    int minBuyDays = (totalChocolates + N - 1) / N;

    if (minBuyDays > availableDays)
        return -1;
    else
        return minBuyDays;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K, S;
        cin >> N >> K >> S;
        cout << minDaysToSurvive(N, K, S) << endl;
    }

    return 0;
}
