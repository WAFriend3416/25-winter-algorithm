#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n, m;
int arr[100005];
int ans = INF;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && arr[j] - arr[i] < m)
            j++;
        if (j == n) break;
        ans = min(ans, arr[j] - arr[i]);
    }
    
    cout << ans;
    return 0;
}
