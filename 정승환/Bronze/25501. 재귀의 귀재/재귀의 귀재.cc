#include <iostream>
#include <string>
using namespace std;

int recursion(const string &s, int l, int r, int &cnt) {
    cnt++;
    if(l >= r) return 1;
    if(s[l] != s[r]) return 0;
    return recursion(s, l + 1, r - 1, cnt);
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        string s;
        cin >> s;
        int cnt = 0;
        int result = recursion(s, 0, s.size() - 1, cnt);
        cout << result << " " << cnt << "\n";
    }
    return 0;
}
