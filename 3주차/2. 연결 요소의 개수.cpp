#include<iostream>
#include<queue>
#define N_SIZE 1001
using namespace std;
int N, M;
int visited[N_SIZE] = { 0, };
int graph[N_SIZE][N_SIZE];
void BFS(int start) {
        queue<int> que;
        que.push(start);
        visited[start] = 1;
        while (!que.empty()) {
                int now = que.front();
                que.pop();
                for (int i = 1; i <= N; i++) {
                        if (!visited[i] && graph[now][i]) {
                                que.push(i);
                                visited[i] = 1;
                        }
                }
        }
}
int main()
{
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
                int x, y;
                cin >> x >> y;
                graph[x][y] = 1;
                graph[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
                if (!visited[i]) {
                        BFS(i);
                        cnt++;
                }
        }
        cout << cnt;
}
