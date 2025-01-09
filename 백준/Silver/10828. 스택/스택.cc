#include <iostream>
#include <string>

#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int cmd_cnt;
    cin >> cmd_cnt;

    while(cmd_cnt--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int value;
            cin >> value;
            s.push(value);
        }
        else if (cmd == "pop")
        {
            if(s.empty()) cout << "-1" << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
            
        }
        else if (cmd == "size")
        {
            cout << s.size() << endl;
        }
        else if (cmd == "empty")
        {
            if(s.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (cmd == "top")
        {
            if(s.empty()) cout << "-1" << endl;
            else cout << s.top() << endl;
        }
    }

    return 0;
}