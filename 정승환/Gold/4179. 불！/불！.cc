#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1002;
string maze[MAX];
int fireTime[MAX][MAX];
int escapeTime[MAX][MAX];

int R, C;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++){
        fill(fireTime[i], fireTime[i] + C, -1);
        fill(escapeTime[i], escapeTime[i] + C, -1);
    }

    for (int i = 0; i < R; i++){
        cin >> maze[i];
    }

    queue<pair<int, int>> fireQueue;
    queue<pair<int, int>> personQueue;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (maze[i][j] == 'F'){
                fireQueue.push({i, j});
                fireTime[i][j] = 0;
            }
            if (maze[i][j] == 'J'){
                personQueue.push({i, j});
                escapeTime[i][j] = 0;
            }
        }
    }

    while (!fireQueue.empty()){
        auto cur = fireQueue.front();
        fireQueue.pop();

        for (int i = 0; i < 4; i++){
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;
            if (fireTime[nr][nc] != -1 || maze[nr][nc] == '#')
                continue;
            fireTime[nr][nc] = fireTime[cur.first][cur.second] + 1;
            fireQueue.push({nr, nc});
        }
    }

    while (!personQueue.empty()){
        auto cur = personQueue.front();
        personQueue.pop();

        for (int i = 0; i < 4; i++){
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C){
                cout << escapeTime[cur.first][cur.second] + 1;
                return 0;
            }
            if (escapeTime[nr][nc] != -1 || maze[nr][nc] == '#')
                continue;
            if (fireTime[nr][nc] != -1 && fireTime[nr][nc] <= escapeTime[cur.first][cur.second] + 1)
                continue;
            
            escapeTime[nr][nc] = escapeTime[cur.first][cur.second] + 1;
            personQueue.push({nr, nc});
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}
