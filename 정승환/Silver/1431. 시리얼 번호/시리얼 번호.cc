#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(const string &a, const string &b) {
        // 1) 길이가 다르면 짧은 게 앞으로
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }

        // 2) 길이가 같으면, 숫자(0~9)의 합 비교
        int sumA = 0, sumB = 0;
        for (char c : a) {
            if (isdigit(c)) { // 또는 if (c >= '0' && c <= '9')
                sumA += (c - '0');
            }
        }
        for (char c : b) {
            if (isdigit(c)) {
                sumB += (c - '0');
            }
        }
        if (sumA != sumB) {
            return sumA < sumB;
        }

        // 3) 길이도 같고 숫자 합도 같다면 사전순 비교
        // 문제에서 "숫자가 알파벳보다 사전순으로 작다" -> 
        //   실제 ASCII 순서로도 '0'~'9' < 'A'~'Z' 이므로 그냥 a < b 사용
        return a < b;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> vs;
    vs.reserve(N); // (선택) N개 만큼 공간 미리 확보

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        vs.push_back(str);
    }

    // 정렬
    sort(vs.begin(), vs.end(), cmp());

    // 출력
    for(const auto &s : vs) {
        cout << s << "\n";
    }

    return 0;
}
