#include <iostream>
#include <stack>


using namespace std;

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 1~N 개의 정수로 수열을 만든다.
    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    string ans;
    //
    while(n--){
        int t;
        cin >> t;
        while(cnt <= t){
            S.push(cnt++);
            ans += "+\n";
            //cout << t << endl;
        }
        //cout << S.top() <<" : "<< t << endl;
        if(S.top() != t){
            cout << "NO\n";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
    return 0;
}

// 흠... 좀 더 생각해보자