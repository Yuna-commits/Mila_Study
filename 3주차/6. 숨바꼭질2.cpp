#include<iostream>
#include<queue>
#include<cstring>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
using namespace std;
int route[MAX_SIZE];//route[i] == start에서 i로 가는데 걸리는 이동시간
int cnt[MAX_SIZE];//cnt[i] == start에서 i로 가는 방법의 개수
//1. 처음 방문하는 경우 -> cnt[]초기화
//2. 이미 방문했는데 최단시간이 같은 경우 -> cnt값 증가
void BFS(int start, int end) {
        queue<int> que;
        que.push(start);
        route[start] = 0;
        cnt[start] = 1;
        while (!que.empty()) {
                int now = que.front();
                que.pop();
                for (int next : {now + 1, now - 1, now * 2}) {//for-each 반복문
                        if (next<0 || next>=MAX_SIZE) continue;
                        if (route[next] == 0) {//처음 방문하는 경우
                                route[next] = route[now] + 1;
                                cnt[next] = cnt[now];
                                que.push(next);
                        }
                        else {//이미 방문했는데 최단거리가 같은 경우
                                if (route[next] == route[now] + 1) {
                                        cnt[next] += cnt[now];
                                }
                        }
                }
        }
}
int main()
{
        fastio;
        int N, K; cin >> N >> K;
        if (N == K) {
                cout << 0 << "\n" << 1;
                return 0;
        }
        memset(route, 0, sizeof(route));
        memset(cnt, 0, sizeof(cnt));
        BFS(N, K);
        cout << route[K] << "\n" << cnt[K];
}
