#include<iostream>
#include<queue>
#include<cstring>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
using namespace std;
int graph[MAX_SIZE];
//graph[X] == X까지 오는데 걸린 시간
//graph[X]에서 graph[X-1 || X+1 || 2*X]로 이동할 때
//graph[X-1 || X+1 || 2*X]=graph[X]+1하여 이동 시간 계산
void BFS(int start, int end) {
        queue<int> que;
        que.push(start);
        graph[start] = 0;
        while (graph[end] == 0) {//graph[end]!=0 => end위치에 도달함
                int now = que.front();
                que.pop();
                for (int next : {now + 1, now - 1, 2 * now}) {//for-each로 줄여 쓸 수 있음
                        if (next < 0 || next >= MAX_SIZE) continue;
                        if (graph[next] == 0 || graph[next] > graph[now] + 1) {
                                que.push(next);
                                graph[next] = graph[now] + 1;
                        }
                }
                //아직 방문 안 한 위치거나 이동 시간이 더 짧을 때
                //=> graph[now+1] > graph[now]+1 
                // == 기존 now+1 위치의 이동 시간보다 현재 now 위치에서 now+1로 갔을 때의 이동 시간이 더 짧음 => 최소 시간
               /* if (now + 1 <= 100000) {
                        if (graph[now + 1] == 0 || graph[now + 1] > graph[now] + 1) {
                                que.push(now + 1);
                                graph[now + 1] = graph[now] + 1;
                        }
                }
                if (now - 1 >= 0) {
                        if (graph[now - 1] == 0 || graph[now - 1] > graph[now] + 1) {
                                que.push(now - 1);
                                graph[now - 1] = graph[now] + 1;
                        }
                }
                if (now * 2 <= 100000) {
                        if (graph[now * 2] == 0 || graph[now * 2] > graph[now] + 1) {
                                que.push(now * 2);
                                graph[now * 2] = graph[now] + 1;
                        }
                }*/
        }
}
int main()
{
        fastio;
        int N, K; cin >> N >> K;
        if (N == K) {
                cout << 0;
                return 0;
        }
        memset(graph, 0, sizeof(graph));
        BFS(N, K);
        cout << graph[K];
}
