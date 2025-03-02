/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
*/
#include <iostream>
#include <vector>

using namespace std;

void findMaxFreqChar(vector<char> &arr) {
    vector<int> freq(26, 0); 

    for (char ch : arr) {
        freq[ch - 'a']++;
    }

    char maxChar = arr[0];
    int maxFreq = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
    }
    cout << maxChar << " " << maxFreq << endl;
}

int main() {
    int T;
    cin >> T;  

    vector<pair<char, int>> results;  

    while (T--) {
        int n;
        cin >> n;
        vector<char> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }

        vector<int> freq(26, 0);
        for (char ch : arr) freq[ch - 'a']++;

        char maxChar = arr[0];
        int maxFreq = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = 'a' + i;
            }
        }

        results.push_back({maxChar, maxFreq});
    }
    for (auto res : results) 
        cout << res.first << " " << res.second << endl;

    return 0;
}
