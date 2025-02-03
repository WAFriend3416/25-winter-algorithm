#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<long long> v(N);
    for(int i=0; i<N; i++){
        long long M;
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int maxC = 0;
    int cnt = 0;
    long long maxV = -(1ll << 62) - 1;;

    for(int i=0; i<N; i++){
        if(i == 0 || v[i-1] == v[i]) cnt++;
        else{
            if(cnt > maxC){
                maxC = cnt;
                maxV = v[i-1];
            }
            cnt = 1;
        }
    }
    if(cnt > maxC){ 
        maxV = v[N-1];
    }
    cout << maxV ;

    //for(auto ch : resultV) cout << ch.first << " " << ch.second << "\n";
    return 0;
}