#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 단어 S string 변수 
    string S;
    // 소문자 알파벳 개수 int 배열
    int arr[1000000];
    // 단어 S 입력 받기
    cin >> S;
    // 단어 S 길아 만큼 반복하면서 96-해당 문자 index 자리에 ++
    for(int i=0; i < S.length(); i++){
        arr[S[i]-97]++;
    }
    for(int j=0; j<26; j++){
        cout << arr[j] << " ";
    }
    return 0;
}