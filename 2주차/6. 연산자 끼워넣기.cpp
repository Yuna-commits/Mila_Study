#include<iostream>
#include<algorithm>
#include<climits>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int N, maxAns = INT_MIN, minAns = INT_MAX;
int opr[11], opt[4];//피연산자, 연산자 배열[+, -, *, /]
void solve(int cnt, int calc) {
        if (cnt == N - 1) {
                maxAns = max(maxAns, calc);
                minAns = min(minAns, calc);
                return;
        }
        for (int i = 0; i < 4; i++) {
                if (opt[i] != 0) {
                        opt[i]--;
                        switch (i) {
                        case 0: solve(cnt + 1, calc + opr[cnt+1]); break;
                        case 1: solve(cnt + 1, calc - opr[cnt + 1]); break;
                        case 2: solve(cnt + 1, calc * opr[cnt + 1]); break;
                        case 3: solve(cnt + 1, calc / opr[cnt + 1]); break;
                        }
                        opt[i]++;
                }
        }
}
int main()
{
        fastio;
        cin >> N;
        for (int i = 0; i < N; i++) cin >> opr[i];
        for (int i = 0; i < 4; i++) cin >> opt[i];
        solve(0, opr[0]);
        cout << maxAns << "\n" << minAns << "\n";
}
