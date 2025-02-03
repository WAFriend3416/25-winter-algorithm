#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(false); // I/O 속도 향상을 위해 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶음을 해제하여 독립적으로 작동

    list<char> mylist;
    string input;
    string command;
    int cmd_count;

    // 초기 문자열 입력
    cin >> input;
    for(char c : input){
        mylist.push_back(c);
    }
    // 커서 초기화 (리스트의 끝)
    auto iter = mylist.end();

    // 명령어 개수 입력
    cin >> cmd_count;

    while(cmd_count--){
        char op;
        cin >> op;
        if(op == 'P'){
            char add;
            cin >> add;
            mylist.insert(iter,add);
        }
        else if(op=='L'){
            if(iter != mylist.begin()) iter--;
        }
        else if(op=='D'){
            if(iter != mylist.end()) iter++;
        }
        else{
            if(iter != mylist.begin()){
                iter--;
                iter = mylist.erase(iter);
            }
        }
    }
    // 명령어 처리 루프
    for(int cnt = 0; cnt < cmd_count; cnt++){
        getline(cin, command);
        if(command.empty()) continue; // 빈 줄은 건너뜀

        stringstream ss(command);
        string cmd;
        ss >> cmd;
        if(cmd.empty()) continue; // 명령어가 없는 경우 건너뜀

        char command1 = cmd[0];

        switch (command1)
        {
            case 'L':
                if(iter != mylist.begin()){
                    iter--;
                }
                break;

            case 'D':
                if(iter != mylist.end()){
                    iter++;
                }
                break;

            case 'B':
                if(iter != mylist.begin()){
                    --iter; // 삭제할 위치는 커서의 왼쪽
                    mylist.erase(iter);
                }
                break;

            case 'P':
            {
                char c;
                ss >> c; // 'P' 명령어의 인자 읽기
                mylist.insert(iter, c);
                break;
            }

            default:
                // 알 수 없는 명령어는 무시하거나 에러 메시지를 출력할 수 있음
                break;
        }
    }

    // 최종 문자열 출력
    for(char c : mylist){
        cout << c;
    }
    cout << "\n";

    return 0;
}
