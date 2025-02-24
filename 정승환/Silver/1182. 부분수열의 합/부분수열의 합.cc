#include <iostream>
#include <vector>
using namespace std;

int N, S;                // N: 수열의 크기, S: 목표 합
int result = 0;          // 만족하는 부분 수열의 개수
vector<int> arr;         // 입력받은 숫자 배열
vector<bool> isused;     // 각 요소의 사용 여부 체크
vector<int> nums;        // 부분 수열 저장 (크기 M)

void func(int k, int M, int SS, int start) {
    // k: 현재까지 선택한 요소의 개수, M: 선택해야 할 총 개수, SS: 현재까지의 합
    if (k == M) {
        if (SS == S) {
            result++;
        }
        return;
    }
    // start 인덱스부터 선택하여 중복 선택 방지
    for (int i = start; i < N; i++) {
        if (!isused[i]) {
            isused[i] = true;
            nums[k] = arr[i];
            func(k + 1, M, SS + arr[i], i + 1);
            isused[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    arr.resize(N);
    isused.resize(N, false);
    nums.resize(N, 0);
    
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // 부분 수열의 크기를 1부터 N까지 변화시키면서 탐색
    for (int i = 1; i <= N; i++) {
        func(0, i, 0, 0);
    }
    
    cout << result;
    return 0;
}
