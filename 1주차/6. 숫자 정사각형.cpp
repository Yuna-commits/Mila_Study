#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<climits>
#define MAX_SIZE 50//직사각형 사이즈
using namespace std;
int N, M;
int MATRIX[MAX_SIZE][MAX_SIZE];
int getArea(int x, int y, int len) {
        //정사각형 꼭짓점의 숫자가 모두 같은지 판단
        int standard = MATRIX[x][y];
        int hor = y + len - 1;
        int ver = x + len - 1;
        if (standard == MATRIX[x][hor]
                && standard == MATRIX[ver][y]
                && standard == MATRIX[ver][hor]) return len * len;
        return 0;
}
int main()
{
        using namespace std;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                        scanf("%1d", &MATRIX[i][j]);
        }
        /*limits == 정사각형이 가질 수 있는 최대 길이
        len == 정사각형 한 변의 길이*/
        //len일 때 조건에 맞는 정사각형인지 모든 경우의 수 탐색
        int ans = INT_MIN;
        for (int len = 1; len <= (N < M ? N : M); len++) {
                for (int i = 0; i + len <= N; i++) {
                        for (int j = 0; j + len <= M; j++) {
                                ans = max(ans, getArea(i, j, len));
                        }
                }
        }
        cout << ans << endl;
}
