#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    int cnt[26] = {0};

    /* 1) 빈도 세기 */
    for (unsigned char ch : str) {
        int idx = toupper(ch) - 'A';   // 대소문자 무관
        cnt[idx]++;
    }

    /* 2) 최댓값과 다중 최대 여부 판정 */
    int maxCnt = 0, maxIdx = -1;
    bool duplicate = false;

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] > maxCnt) {
            maxCnt = cnt[i];
            maxIdx = i;
            duplicate = false;
        } else if (cnt[i] == maxCnt) {
            duplicate = true;
        }
    }

    /* 3) 출력 */
    if (duplicate) cout << '?';
    else           cout << char(maxIdx + 'A');
    return 0;
}
