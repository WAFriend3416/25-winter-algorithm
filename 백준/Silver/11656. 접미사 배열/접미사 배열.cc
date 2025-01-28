#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    vector<string> v;
    int size = str.length();

    for(int i=0; i<size; i++){
        v.push_back(str.substr(i,size));
    }    

    sort(v.begin(),v.end());
    for(auto ch : v) cout << ch << "\n";
    

    return 0;
}
