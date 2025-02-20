#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#define N_SIZE 25
using namespace std;
int N;
//상하좌우 좌표 이동
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int visited[N_SIZE][N_SIZE] = { 0, };
int apt[N_SIZE][N_SIZE];
int group[N_SIZE];
int BFS(int x, int y) {
        queue<pair<int, int>> que;
        que.push(make_pair(x, y));
        visited[x][y] = 1;
        int cnt = 1;//단지내 집의 수
        while (!que.empty()) {
                int nx = que.front().first;
                int ny = que.front().second;
                que.pop();
                for (int i = 0; i < 4; i++) {
                        int mx = nx + dx[i];
                        int my = ny + dy[i];
                        if (0 <= mx && mx < N && 0 <= my && my < N) {
                                if (visited[mx][my] || apt[mx][my] != 1) continue;
                                que.push(make_pair(mx, my));
                                visited[mx][my] = 1;
                                cnt++;
                        }
                }
        }
        return cnt;
}
int main() {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        scanf("%1d", &apt[i][j]);
                }
        }
        int num = 0; //num==단지번호
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        if (visited[i][j] || apt[i][j] == 0) continue;
                        group[num++]=BFS(i, j);
                }
        }
        sort(group, group + num);//오름차순 정렬
        printf("%d\n", num);
        for (int i = 0; i < num; i++) printf("%d\n", group[i]);
}
