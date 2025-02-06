#include<iostream>
#define ALL_CASE 153 //18C2
int A, B;
double solve() {
        double ans = 0;
        for (int i = 1; i <= 10; i++) {
                for (int j = i+1; j <= 10; j++) {
                        if (i == j) continue;
                        if ((A + B) % 10 > (i + j) % 10) {
                                if (A == i || A == j || B == i || B == j)
                                        ans += 2;
                                else 
                                        ans += 4;
                        }
                }
        }
        return ans / 153;
}
int main()
{
        using namespace std;
        cout << fixed;
        cout.precision(3);
        cin >> A >> B;
        //상대가 무조건 지는 확률 구하기
        if (A == B) //영학이의 패가 X땡인 경우
                cout << ((double)(153 - 10 + A) / 153) << endl;
        else //영학이의 패가 X끗인 경우
                cout << solve() << endl;
}
