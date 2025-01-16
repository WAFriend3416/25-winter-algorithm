#include <iostream>
#include <deque>;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N;
    cin >> N;
    
    deque<int> dq;
    for(int i=1; i<=N; i++){
        dq.push_back(i);
    }
    
    while(dq.size() != 1){
        int tmp;
        dq.pop_front();
        tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front() << endl;

    return 0;
}