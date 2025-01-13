#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    stack<pair<int,int> > S;

    for(int i=1; i<=n; i++){
        int input;
        cin >> input;

        while(!S.empty()){
            if(S.top().second > input){
                cout << S.top().first << " ";
                break;
            }
            S.pop();
        }
        if(S.empty()){
            cout << "0" << " ";
        }
        S.push(make_pair(i,input));
    }
    return 0;
}