#include <iostream> // 내림차순 정렬
#include <vector>
#include <algorithm>

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
    sort(V.begin(),V.end(), greater<int>()); // less<>() 오름차순
    for(auto ch : V) cout << ch << "\n";

    return 0;
}