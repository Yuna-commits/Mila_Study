#include<iostream>
#include<utility>
#define N_SIZE 1000001
#define INF 987654321
int main()
{
        using namespace std;
        int N; cin >> N;
        int dp[N_SIZE];//N -> 1, dp[i] = N으로 i를 만들기 위한 연산 횟수
        fill(dp, dp+N_SIZE, INF);//0번째부터 (N+1)개를 INF로 초기화
        dp[N] = 0;
        for (int i = N; i > 1; i--) {
                if (i % 3 == 0) {
                        dp[i / 3] = min(dp[i / 3], dp[i] + 1);
                }
                if (i % 2 == 0) {
                        dp[i / 2] = min(dp[i / 2], dp[i] + 1);
                }
                dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        }
        cout << dp[1];
}
