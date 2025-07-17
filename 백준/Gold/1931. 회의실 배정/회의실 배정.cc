#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
pair<int,int>arr[100001];
int main(){
    int n,a,b,cnt=1; // b : 시작시간, a : 끝나는 시간
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> b >> a; // 순서 주의!
        arr[i] = {a,b}; // 순서 주의! - 별다른 비교함수 없
    }
    sort(arr,arr+n); // 끝나는 시간을 기준으로 오름차순 정렬
    int end = arr[0].first; // 최초로 끝나는 회의를 end에 저장해둠.
    for(int i=1; i<n; i++){
        if(end<=arr[i].second){ // second는 현재 탐색중인 회의 시작시간인데
                                // 가장 먼저 조건이 참이 될 때가 가장 텀이 짧을 때.
            cnt++;
            end=arr[i].first;
        }
    }
    cout << cnt;
    return 0;
}