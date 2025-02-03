#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> v(N,-1);
    stack<pair<int,int> > s; // index,value
    
    for(int i=0; i<N; i++){
        int item;
        cin >> item;
        if(s.empty()) s.push(make_pair(i,item));
        else{
            while(!s.empty() && s.top().second < item){
                int index = int(s.top().first);
                v[index] = item;
                s.pop();
            }
            s.push(make_pair(i,item));
        }
    }

    for(auto ch : v) cout << ch << " ";
    cout << endl;
    return 0;
}