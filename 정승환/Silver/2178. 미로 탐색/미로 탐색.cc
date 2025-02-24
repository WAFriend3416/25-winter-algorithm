#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// S E N W
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1}; 

int dist[102][102];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    string board[102];
    for(int i=0; i<N; i++){
        cin >> board[i];
    }

    for(int i = 0; i < N; i++) fill(dist[i],dist[i]+M,-1);
    dist[0][0] = 1;
    queue<pair<int,int> > Q;
    Q.push({0,0});
    while(!Q.empty()){
        pair<int ,int> cur = Q.front();
        Q.pop();
        for(int k=0; k<4; k++){
            int nx = cur.first  +dx[k];
            int ny = cur.second +dy[k];
            if(nx<0 || nx>= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }


    cout << dist[N-1][M-1];

    return 0;
}