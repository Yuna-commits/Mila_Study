#include<iostream>
#include<utility>
#define STAIRS_SIZE 301
using namespace std;
int N;
int stairs[STAIRS_SIZE];
int dp[STAIRS_SIZE];
int main() {
        cin >> N;
        for (int i = 1; i <= N; i++) cin >> stairs[i];
        dp[1] = stairs[1];
        dp[2] = stairs[1] + stairs[2];
        dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
        for (int i = 4; i <= N; i++) {
                dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
        }
        cout << dp[N];
}
