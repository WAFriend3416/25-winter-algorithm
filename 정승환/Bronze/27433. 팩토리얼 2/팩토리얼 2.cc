#include <iostream>

using namespace std;


long long func(long long n){
    if(n == 1 or n == 0){
        return 1;
    }
    return func(n-1) * n;
}


//팩토리얼 구하기
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long N;
    cin >> N;
    cout << func(N) << "\n" ;
    return 0;
}