#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int alphabet[26] = {0,};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // N 입력
    int N;
    cin >> N;
    cin.ignore();
    // N 만큼 반복
    while(N--){
        memset(alphabet,0,sizeof(alphabet)); // 배열 요소 0 으로 초기화
        string input_str;
        // 문자열 입력
        getline(cin,input_str);
        // 문자열 알파벳들의 등장 횟수 기록(배열을 이용)
        for(int i=0; i<input_str.length(); i++){
            if(input_str[i] == ' ') continue;
            alphabet[input_str[i]-97]++; // index 0 이 소문자 a
        }
        // 배열에서 가장 큰 값 찾기
        vector<pair<int,char>> vec;
        for(int j=0; j<26; j++){
            vec.push_back(make_pair(alphabet[j],j+97));
        }
        sort(vec.begin(),vec.end(),greater<>());

        if(vec[0].first == vec[1].first){
            cout << "?" << "\n";
        }
        else{
            cout << vec[0].second << "\n";
        }
        
    }
    return 0;
}