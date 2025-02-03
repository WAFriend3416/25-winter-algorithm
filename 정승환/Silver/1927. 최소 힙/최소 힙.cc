#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int , vector<int>, greater<int> > pq;
    int N;
    cin >> N;   
    while(N--){
        int T;
        cin >> T;
        if(!T && pq.empty()){
            cout << 0 << "\n";
        }
        else if (!T)
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else{
            pq.push(T);
        }   
    }
    return 0;
}