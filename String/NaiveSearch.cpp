#include <iostream>
#include <string>
using namespace std;

void naiveSearch(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) 
              break;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    naiveSearch(text, pattern);
    return 0;
}
