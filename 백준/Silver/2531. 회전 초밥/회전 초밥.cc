#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int N, d, k, c;
int flag, cnt, coupon, maxi = 0;
int sushi[300001];
int check[3001];

vector<int> eat;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // N : 접수의 수 , d : 초밥의 가짓수, 
    // k 연속해서 먹는 접시의 수, c : 쿠폰 번호
    cin >> N >> d >> k >> c;

    for(int i=0; i<N; i++){
        cin >> sushi[i];
    }

    // 슬라이딩 윈도우
    for(int i=0; i<N; i++){
        flag = 0; // 중복된 스시 체크
        coupon = 1; // 쿠폰 스시가 있는지 확인
        for(int j=i; j<i+k; j++){
            if(check[sushi[j%N]] == 1) flag++;
            else check[sushi[j%N]] = 1;

            if(sushi[j%N] == c) coupon = 0;
        }
        maxi = max(maxi,k-flag+coupon);
        memset(check,0,sizeof(check));
    }

    cout << maxi;
    return 0;
}