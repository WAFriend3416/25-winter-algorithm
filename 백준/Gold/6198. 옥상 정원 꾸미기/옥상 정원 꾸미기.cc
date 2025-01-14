#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    stack<long long> b;
    long long cnt = 0; // 오버플로 방지를 위해 long long이 안전
    while(N--){
        long long B;
        cin >> B;

        // 새로 들어온 건물 높이 B보다 작거나 같은 건물들은
        // B 때문에 가려지므로, 스택에서 빼버린다.
        while(!b.empty() && b.top() <= B)
            b.pop();

        // 그 뒤, 스택에 남아있는 건물의 수가
        // 현재 건물이 볼 수 있는 '이전 건물'의 개수.
        cnt += b.size();   

        // 새 건물을 스택에 넣는다.
        b.push(B);
    }
    
    cout << cnt << "\n";
    return 0;
}