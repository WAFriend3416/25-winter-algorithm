#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N;
    cin >> N;
    int T;
    cin >> T;
    
    deque<int> dq;
    for(int i=1; i<=N; i++){
        dq.push_back(i);
    }

    int cnt = 0;
    
    while(T--){
        int target = 0;
        cin >> target;
        
        int target_index = 0;
        for(int j=0; j<dq.size(); j++){ // j : target_index
            if(target == dq[j]){
                target_index = j;
                break;
            }
        }
        
        if(target_index <= (dq.size()/2)){
            while(target_index--){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else{
            int rotate_cnt = dq.size() - target_index;
            while(rotate_cnt--){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
        
        dq.pop_front();
    }
    
    cout << cnt << endl;
    return 0;
}