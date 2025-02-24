#include <iostream>
#include <map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_set<string> s;

    while(N--){
        string name;
        string inout;
        cin >> name;
        cin >> inout;
        if(inout == "enter") s.insert(name);       
        else s.erase(name);
    }
    vector<string> v(s.begin(),s.end());
    sort(v.begin(),v.end(),greater<string>());
    
    for(auto ch : v) cout << ch << "\n";
    return 0;
}