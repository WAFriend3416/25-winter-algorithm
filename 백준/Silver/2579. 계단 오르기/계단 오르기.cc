#include <iostream>
#include <algorithm>
using namespace std;

int a[305];
int dp[305][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    
    if (n == 1) {
        cout << a[1];
        return 0;
    }
    
    dp[1][1] = a[1];
    dp[1][2] = 0;
    dp[2][1] = a[2];
    dp[2][2] = a[1] + a[2];
    
    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + a[i];
        dp[i][2] = dp[i - 1][1] + a[i];
    }
    
    cout << max(dp[n][1], dp[n][2]);
    return 0;
}
