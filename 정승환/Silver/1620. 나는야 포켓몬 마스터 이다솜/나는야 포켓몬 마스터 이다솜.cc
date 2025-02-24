#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M; // 포켓몬 수 , 문제 수
    unordered_map<string, int> m_name; // 키 : 포켓몬 이름, 값 : 번호
    string i2s[1000005]; // 키 : 번호, 값 : 포켓몬 이름
    int num = 0; 
    for(int i=1; i<=N; i++){
        cin >> i2s[i];
        m_name[i2s[i]] = i;
    }

    while(M--){
        string query;
        cin >> query;
        if(isdigit(query[0])) cout << i2s[stoi(query)] << "\n";
        else cout << m_name[query] << "\n";
    }
    return 0;
}