#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> V(N);
    for(int i=0; i<N; i++){
        int T;
        cin >> T;
        V[i] = T;
    }
    sort(V.begin(),V.end());

    for(int i=0; i<N; i++){
        cout << V[i] << "\n";
    }
    V.clear();
    return 0;
}