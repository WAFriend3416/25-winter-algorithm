#include <iostream> // 내림차순 정렬
#include <vector>
#include <algorithm>

using namespace std;

int main(){
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