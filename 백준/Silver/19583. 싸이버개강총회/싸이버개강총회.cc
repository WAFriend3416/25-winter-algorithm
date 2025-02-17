#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/**
 *  "HH:MM" 형태의 문자열을 분(minutes) 단위 정수로 변환
 *  예) "12:34" -> 12*60 + 34 = 720 + 34 = 754
 */
int ttoi(const string& time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 개강총회 시작 시간(S), 끝 시간(E), 스트리밍 종료 시간(Q)
    string S, E, Q;
    cin >> S >> E >> Q;

    // 각 시간을 분(minutes) 단위 정수로 변환
    int st_t    = ttoi(S);
    int end_t   = ttoi(E);
    int stream_t = ttoi(Q);

    // 시작 전 입장 명단과 최종 출석 인원 명단
    unordered_set<string> st_list;
    unordered_set<string> atd_list;

    // EOF까지 반복
    while (true) {
        string c_time, name;
        if (!(cin >> c_time >> name)) break;  // EOF 검사

        int currentTime = ttoi(c_time);

        // 시작 시각 이하로 채팅 치면 출석 가능 대상
        if (currentTime <= st_t) {
            st_list.insert(name);
        }
        // 끝 시각 ~ 스트리밍 종료 시각 사이에 채팅 친 인원 중
        // 시작 전에 입장했던 사람이면 최종 출석 인정
        else if (currentTime >= end_t && currentTime <= stream_t) {
            if (st_list.find(name) != st_list.end()) {
                atd_list.insert(name);
            }
        }
    }

    // 최종 출석 인원 수
    cout << atd_list.size() << "\n";
    return 0;
}
