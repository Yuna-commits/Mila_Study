#include<iostream>
#include<algorithm>
#define MAX_SIZE 20
using namespace std;
int N;
int ans[MAX_SIZE] = { 0, }; //ans[i] = i번째 날부터 얻을 수 있는 최대 수익
int Ti[MAX_SIZE], Pi[MAX_SIZE];
int main()
{
        cin >> N;
        for (int i = 1; i <= N; i++) {
                cin >> Ti[i] >> Pi[i];
        }
        for (int i = N; i > 0; i--) {
                if(i+Ti[i]>N+1) ans[i] = ans[i + 1];
                else ans[i] = max(ans[i + 1], ans[i+Ti[i]]+Pi[i]);
        }
        cout << ans[1] << endl;
}
