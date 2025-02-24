#include <iostream>

using namespace std;

int zOrder(int N, int r, int c) {
    // 기본 사례: N=0이면 1×1 그리드이므로 순서 0 반환
    if (N == 0) return 0;
    
    // half = 2^{N-1} 계산 (비트 연산 사용)
    int half = 1 << (N - 1);
    
    // 왼쪽 위 사분면
    if (r < half && c < half) {
        return zOrder(N - 1, r, c);
    }
    // 오른쪽 위 사분면
    else if (r < half && c >= half) {
        return half * half + zOrder(N - 1, r, c - half);
    }
    // 왼쪽 아래 사분면
    else if (r >= half && c < half) {
        return 2 * half * half + zOrder(N - 1, r - half, c);
    }
    // 오른쪽 아래 사분면
    else {
        return 3 * half * half + zOrder(N - 1, r - half, c - half);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, r, c;
    // 입력: N, r, c
    cin >> N >> r >> c;
    // 결과 출력
    cout << zOrder(N, r, c) << "\n";
    return 0;
}