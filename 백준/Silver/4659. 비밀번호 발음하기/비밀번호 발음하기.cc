#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while (cin >> s, s != "end") {
        bool hasVowel = false;
        bool badTriple = false;
        bool badDouble = false;

        int vowelStreak = 0, consStreak = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            if (isVowel(s[i])) {
                hasVowel = true;
                ++vowelStreak;   consStreak = 0;
            } else {
                ++consStreak;    vowelStreak = 0;
            }
            if (vowelStreak == 3 || consStreak == 3)
                badTriple = true;

            if (i+1 < s.size() && s[i] == s[i+1]) {
                if (!(s[i]=='e' && s[i+1]=='e') &&
                    !(s[i]=='o' && s[i+1]=='o'))
                    badDouble = true;
            }
        }

        cout << '<' << s << "> "
             << (hasVowel && !badTriple && !badDouble ?
                 "is acceptable.\n" : "is not acceptable.\n");
    }
    return 0;
}
