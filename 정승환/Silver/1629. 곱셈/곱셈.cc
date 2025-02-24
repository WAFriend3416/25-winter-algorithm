#include <iostream>
#define ll long long
using namespace std;

ll power(ll A, ll B, ll C) {
    if (B == 0) return 1; // A^0 = 1
    ll half = power(A, B / 2, C);
    half = (half * half) % C; // 절반씩 계산 후 제곱

    if (B % 2 == 1) { // B가 홀수이면 한 번 더 곱해야 함
        half = (half * A) % C;
    }
    return half;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll A, B, C;
    cin >> A >> B >> C;
    
    cout << power(A, B, C) << '\n';
    return 0;
}
