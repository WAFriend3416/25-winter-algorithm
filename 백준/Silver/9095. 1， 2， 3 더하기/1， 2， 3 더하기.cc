#include <iostream>
using namespace std;

int dp[20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
