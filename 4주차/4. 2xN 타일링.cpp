#include<iostream>
#define N_SIZE 1001
using namespace std;
int main() {
        int N;
        int dp[N_SIZE];
        cin >> N;
        dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= N; i++) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
        cout << dp[N];
}
