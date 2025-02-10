#include<iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DAYS 15
int arr[DAYS];
int BNP(int cashJ) {//준현이 매매법
        int stocks = 0;
        for (int i = 1; i < DAYS; i++) {
                if (cashJ < arr[i]) continue;
                stocks += cashJ / arr[i];
                cashJ -= (cashJ / arr[i]) * arr[i];
        }
        return (cashJ + arr[14] * stocks);
}
int TIMING(int cashS) {//성민이 매매법
        int stocks = 0;
        int day1 = 1;
        while (day1 < DAYS - 3) {
                //전일 대비 3일 연속 상승 => 3일째 전량 매도
                if (arr[day1] < arr[day1 + 1] && arr[day1 + 1] < arr[day1 + 2] && arr[day1 + 2] < arr[day1 + 3]) {
                        if (stocks > 0) {
                                cashS += stocks * arr[day1 + 3];
                                stocks = 0;
                        }
                }
                //전일 대비 3일 연속 하락 => 3일째 전량 매수
                else if (arr[day1 + 3] < arr[day1 + 2] && arr[day1 + 2] < arr[day1 + 1] && arr[day1 + 1] < arr[day1]) {
                        if (cashS > arr[day1 + 3]) {
                                stocks += cashS / arr[day1 + 3];
                                cashS -= (cashS / arr[day1 + 3]) * arr[day1 + 3];
                        }
                }
                ++day1;
        }
        return (cashS + arr[14] * stocks);
}
int main()
{
        using namespace std;
        fastio;
        int cash;
        cin >> cash;
        for (int i = 1; i < DAYS; i++) cin >> arr[i];
        int cmp = BNP(cash) - TIMING(cash);
        if (cmp > 0) cout << "BNP\n";
        else if (cmp < 0) cout << "TIMING\n";
        else cout << "SAMESAME\n";
}
