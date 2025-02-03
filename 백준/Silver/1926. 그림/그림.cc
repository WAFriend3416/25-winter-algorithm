#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int board[502][502] = {0};
bool vis[502][502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 도화지 크기 입력
    int n,m; // 행 , 열
    cin >> n >> m;

    // 그림 입력
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    // 그림 찾기(가장 큰 그림 찾기, 도화지 내 그림 개수 세기)
    // 0,0 부터 끝까지 탐색해서 1을 만나면 BFS 실행해서 그림 크기 측정 및 그림 개수 카운팅
    int maxSize = 0; // 최대그림 크기
    int cnt = 0; // 도화지내 그림 개수
    
    // S E N W
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1}; 

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue; 
            else{
                int size = 0;
                cnt++;
                queue<pair<int,int> > Q;
                vis[i][j] = 1;
                Q.push({i,j});
                // BFS 시작
                while(!Q.empty()){
                    pair<int,int> cur = Q.front();
                    Q.pop();
                    size++;
                    for(int k=0; k<4; k++){
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                if(size > maxSize) maxSize = size;
            }
        }
    }

    cout << cnt << "\n";
    cout << maxSize << "\n";
    return 0;
}