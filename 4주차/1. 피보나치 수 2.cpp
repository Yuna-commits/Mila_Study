#include<iostream>
#define N_SIZE 91
int main() {
        /*signed int -> - 2, 147, 483, 648~2, 147, 483, 647;
        signed long long -> - 9, 223, 372, 036, 854, 775, 808~9, 223, 372, 036, 854, 775, 807
        90번째 피보나치 수 -> 7, 540, 113, 804, 746, 346, 429*/
        using namespace std;
        long long dp[N_SIZE];
        int N;
        cin >> N;
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= N; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
        }
        cout << dp[N];
}
