#include <iostream>
#include <queue>

using namespace std;


struct cmp{
    bool operator()(int a, int b){
            if(abs(a) == abs(b)) return a > b;
            else return abs(a) > abs(b);
        return true;
    }
};

priority_queue<int ,vector<int>, cmp > pq_min;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while(N--){
        int X;
        cin >> X;
        if(pq_min.empty() && !X) cout << 0 << "\n";
        else if (!pq_min.empty() && !X)
        {
            cout << pq_min.top() << "\n";
            pq_min.pop();
        }
        else{
            pq_min.push(X);
        }
    }
    return 0;
}