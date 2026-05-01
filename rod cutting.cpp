#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter length of rod: ";
    cin >> n;
    int price[100];
    cout << "Enter prices for each length (1 to n): ";
    for(int i = 1; i <= n; i++) {
        cin >> price[i];
    }
    int dp[100];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int max_val = 0;
        for(int j = 1; j <= i; j++) {
            max_val = max(max_val, price[j] + dp[i - j]);
        }
        dp[i] = max_val;
    }
    cout << "Maximum obtainable value: " << dp[n];
    return 0;
}
