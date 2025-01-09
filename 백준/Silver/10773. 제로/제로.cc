#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    
    int cmd_cnt;
    cin >> cmd_cnt;
    cin.ignore();

    while(cmd_cnt--){
        //cout << "1 while" << endl;
        int cmd;
        cin >> cmd;
        if(cmd) s.push(cmd);
        else s.pop();
    }

    int sum = 0;
    while(!s.empty()){
        //cout << "2 while" << endl;
        int tmp = s.top();
        sum += tmp;
        s.pop();
    }

    cout << sum << endl;

    return 0;
}