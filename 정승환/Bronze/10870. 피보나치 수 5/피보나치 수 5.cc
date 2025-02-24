#include <iostream>
#define ll long long


using namespace std;

ll func(ll N){
    if(N <= 2) return 1;
    return func(N-1) + func(N-2);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    ll result;
    cin >> N;
    if(N == 0) cout << "0";
    else cout << func(N) << "\n";
    return 0;
}