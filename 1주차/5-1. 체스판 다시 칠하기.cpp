#include<iostream>
#include<algorithm>
#include<climits>
#define MAX_SIZE 50
int N, M;
char BOARD[MAX_SIZE][MAX_SIZE];
char WB[8][8] = {
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W'
};
char BW[8][8] = {
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B',
        'B','W','B','W','B','W','B','W',
        'W','B','W','B','W','B','W','B'
};
int WB_cmp(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                        if (WB[i][j] != BOARD[x + i][y + j]) cnt++;
                }
        }
        return cnt;
}
int BW_cmp(int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                        if (BW[i][j] != BOARD[x + i][y + j]) cnt++;
                }
        }
        return cnt;
}
int main() {
        using namespace std;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) cin >> BOARD[i][j];
        }
        int ans = INT_MAX;
        //WB_cmp, BW_cmp 함수
        //> 기존 보드와 WB, BW 배열을 가로세로 8칸씩 잡고 비교
        //> > 둘 중 더 작은 값을 ans에 저장
        for (int i = 0; i + 8 <= N; i++) {
                for (int j = 0; j + 8 <= M; j++) {
                        int tmp = min(WB_cmp(i, j), BW_cmp(i, j));
                        if (ans > tmp) ans = tmp;
                }
        }
        cout << ans << endl;
}
