#include<iostream>
using namespace std;
int T;
int triArr[50];
int solve(int X) {
        //삼각수 3개로 X를 만들 수 있는지 확인
        for (int i = 1; i <= 45; i++) {
                for (int j = 1; j <= 45; j++) {
                        for (int k = 1; k <= 45; k++) {
                                if (triArr[i] + triArr[j] + triArr[k] == X) return true;
                        }
                }
        }
        return false;
}
int main()
{
        //Tn == Tn-1 + n
        //1~1000까지의 삼각수 배열, 삼각수 값이 1000을 넘는건 44번째부터
        for (int i = 1; i <= 45; i++) {
                triArr[i] = triArr[i - 1] + i;
        }
        cin >> T;
        while (T > 0) {
                int X;
                cin >> X;
                cout << solve(X) << endl;
                T--;
        }
}
