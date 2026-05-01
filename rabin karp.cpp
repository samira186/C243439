#include <iostream>
#include <string>
using namespace std;
int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    int n = text.length();
    int m = pattern.length();

    for(int i = 0; i <= n - m; i++) {
        string sub = text.substr(i, m);

        if(sub == pattern) {
            cout << "Pattern found at position " << i + 1 << endl;
        }
    }

    return 0;
}
