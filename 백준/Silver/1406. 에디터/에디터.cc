#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // L : 커서를 왼쪽으로
    // D : 커서를 오른쪽으로
    // B : 커서 왼쪽에 있는 문자 삭제 , 커서가 맨앞이면 무시
    // P $ : $ 라는 문자를 커서 왼쪽에 추가

    list<char> arr;
    
    // 입력 문자열 리스트에 입력
    string input_str;
    cin >> input_str;
    for(auto i : input_str) arr.push_back(i);

    // 명령어 횟수 입력
    int cmd_cnt;
    cin >> cmd_cnt;

    list<char>::iterator ite = arr.end();

    // 명령어 횟수 만큼 명령어 실행
    while(cmd_cnt--){
        char cmd;
        char input;
        cin >> cmd;
        if(cmd == 'P'){
            cin >> input;
            arr.insert(ite,input);
        }
        else if (cmd == 'L')
        {
            if(ite !=arr.begin()){ite--;}
        }
        else if(cmd == 'D'){
            if(ite!=arr.end()){ite++;}
        }
        else{ // cmd == 'B'
            if(ite!=arr.begin()){
                ite--; 
                ite = arr.erase(ite);}

                // 1 2 3 "4" 5 <- 4의 왼쪽을 삭제
                // 1 2 "3" 4 5 <- 커서 이동
                // 1 2 "4" 5 <- 삭제 후 커서 다시 제자리
        }
    }
    for(auto i : arr) cout << i;
    return 0;
}