#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#define fastio ios::sync_with_stdio(false),  cin.tie(0), cout.tie(0)
#define FIELD_SIZE 50
using namespace std;
int T, N, M, K;
//상하좌우 좌표 이동
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int visited[FIELD_SIZE][FIELD_SIZE];
int field[FIELD_SIZE][FIELD_SIZE];
void BFS(int x, int y) {
        queue<pair<int, int>> que;
        que.push(pair<int, int>(x, y));
        visited[x][y] = 1;
        while (!que.empty()) {
                int nx = que.front().first;//현재 x
                int ny = que.front().second;//현재 y
                que.pop();
                //현재 (x, y)에서 4방향 탐색
                for (int i = 0; i < 4; i++) {
                        int mx = nx + dx[i];//dx[i]만큼 이동한 x
                        int my = ny + dy[i];//dy[i]만큼 이동한 y
                        if ((mx >= 0 && mx < M) && (my >= 0 && my < N)) {
                                if (!visited[mx][my] && field[mx][my]) {
                                        que.push(pair<int, int>(mx, my));
                                        visited[mx][my] = 1;
                                }
                        }
                }
        }
}
int main()
{
        fastio;
        cin >> T;
        while (T--) {
                memset(visited, 0, sizeof(visited));
                memset(field, 0, sizeof(field));
                cin >> M >> N >> K;
                while (K--) {
                        int x, y; cin >> x >> y;
                        field[x][y] = 1;
                }
                int cnt = 0;
                //배추밭의 모든 위치에서 상하좌우 4방향 BFS 탐색
                for (int i = 0; i < M; i++) {
                        for (int j = 0; j < N; j++) {
                                if (!visited[i][j] && field[i][j]) {
                                        BFS(i, j);
                                        cnt++;
                                }
                        }
                }
                cout << cnt << "\n";
        }
}
