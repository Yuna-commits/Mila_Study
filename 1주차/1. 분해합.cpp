#include<iostream>
int N;
int solve() {
        //자연수 1~(N-1)의 분해합을 구했을 때 N이 나오는 경우
        for (int i = 1; i < N; i++) {
                int sum = i;
                int tmp = i;
                while (tmp > 0) {
                        sum += (tmp % 10);
                        tmp /= 10;
                }
                if (sum == N) return i;
        }
        return 0;
}
int main()
{
        using namespace std;
        cin >> N;
        cout << solve();
}
