#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, S, M;
vector<int> V;
vector<vector<int>> DP;
//DP[i][j] == i번째 곡일 때 쓸 수 있는 j볼륨(1 : 사용 가능, 0 : 사용 불가)
int main()
{
        cin >> N >> S >> M;
        V.resize(N + 1, 0);
        DP.resize(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++) cin >> V[i];
        DP[0][S] = 1;//시작 볼륨
        for (int i = 1; i <= N; i++) {
                for (int j = 0; j <= M; j++) {
                        if (DP[i-1][j] == 1) {//i-1번째 곡일 때 j라는 볼륨을 만들 수 있을 때
                                if (j + V[i] <= M) DP[i][j + V[i]] = 1;
                                if (j - V[i] >= 0) DP[i][j - V[i]] = 1;
                        }
                }
        }
        for (int i = M; i >= 0;i--) {
                if (DP[N][i] == 1) {
                        cout << i;
                        return 0;
                }
        }
        cout << -1;
}
