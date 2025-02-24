#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    unordered_map<string, string> dict;

    for (int i = 0; i < N; ++i) {
        string word, trans;
        cin >> word >> trans;
        dict[word] = trans;
    }

    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;
        cout << dict[query] << "\n";
    }

    return 0;
}
