#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define MAX_SIZE 21
using namespace std;
int N, ans=INT_MAX;
int S[MAX_SIZE][MAX_SIZE];
int team[MAX_SIZE] = { 0, };
//team[i]==1 스타트팀, team[i]==0 링크팀으로 구분
//mem==N/2일 때 각각 계산
void setTeam(int idx, int mem) {
        if (mem == N / 2) {
                vector<int> start;
                vector<int> link;
                int sSum = 0, lSum = 0;
                for (int i = 1; i <= N; i++) {
                        if (team[i]) start.push_back(i);
                        else link.push_back(i);
                }
                for (int i = 0; i < N / 2; i++) {
                        for (int j = 0; j < N / 2; j++) {
                                sSum += S[start[i]][start[j]];
                                lSum += S[link[i]][link[j]];
                        }
                }
                if (abs(sSum - lSum) < ans) ans = abs(sSum - lSum);
                return;
        }
        for (int i = idx; i <= N; i++) {
                if (!team[i]) {
                        team[i] = 1;
                        setTeam(i, mem + 1);
                        team[i] = 0;
                }
        }
}
int main()
{
        fastio;
        cin >> N;
        for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) cin >> S[i][j];
        }
        setTeam(1, 0);
        cout << ans;
}
