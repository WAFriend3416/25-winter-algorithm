#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, E, Q;
    cin >> S >> E >> Q;

    unordered_set<string> st_list;
    unordered_set<string> atd_list;

    while (true) {
        string c_time, name;
        if (!(cin >> c_time >> name)) break;
        if (c_time <= S)
            st_list.insert(name);
        else if (c_time >= E && c_time <= Q)
            if (st_list.find(name) != st_list.end())
                atd_list.insert(name);
    }

    cout << atd_list.size() << "\n";
    return 0;
}
