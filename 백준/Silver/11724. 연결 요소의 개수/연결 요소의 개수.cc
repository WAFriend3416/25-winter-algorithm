#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> adj_mtx[1005];
    bool visit[1005];
    int n,m;

    // 그래프 만들기 : 인접 리스트 방식
    cin >> n >> m;
    while(m--){
        int u,v;
        cin >> u >> v;
        adj_mtx[u].push_back(v);
        adj_mtx[v].push_back(u);
    }

    int num = 0;
    for(int i=1; i<=n; i++){
        if(visit[i]) continue;
        num++;
        queue<int> q;
        q.push(i);
        visit[i] = true;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto next : adj_mtx[cur]){
                if(visit[next]) continue;
                q.push(next);
                visit[next] = true;
            }
        }
    }
    cout << num;
    return 0;
}