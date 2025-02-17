#include<iostream>
#include<queue>
#include<memory.h>
#define N_SIZE 1001
using namespace std;
int graph[N_SIZE][N_SIZE];
int visited[N_SIZE];
void DFS(int ver, int N) {//재귀
        visited[ver] = 1;
        cout << ver << " ";
        for (int i = 1; i <= N; i++) {
                if (!visited[i] && graph[ver][i]) DFS(i, N);
        }
}
void BFS(int start, int N) {
        queue<int> que;
        que.push(start);
        visited[start] = 1;
        while (!que.empty()) {
                int now = que.front();
                que.pop();
                cout << now << " ";
                //now와 연결됐지만 방문 X인 정점
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
        int N, M, start;
        cin >> N >> M >> start;
        for (int i = 0; i < M; i++) {
                int x, y; cin >> x >> y;
                graph[x][y] = 1; graph[y][x] = 1;
        }
        memset(visited, 0, sizeof(int) * (N + 1));
        DFS(start, N); cout << "\n";
        memset(visited, 0, sizeof(int) * (N + 1));
        BFS(start, N);
}
