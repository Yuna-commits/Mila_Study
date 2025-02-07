#include<iostream>
#include<algorithm>
#include<climits>
#define MAX_SIZE 50
int N, M;
char BOARD[MAX_SIZE][MAX_SIZE];
char NOT(char now) {//다음 칸의 색 결정
        return now == 'B' ? 'W' : 'B';
}
//(0, 0)이 start = W로 시작하는 경우, start = B로 시작하는 경우의 다시 칠해야 하는 칸 개수
//기존 보드의 가로세로 8칸씩 잡아서 "모든 경우의 수 탐색"
int get_cnt(int x, int y, char start) {
        int cnt = 0;
        char row_start = start;
        for (int i = 0; i < 8; i++) {
                char next = row_start;
                for (int j = 0; j < 8; j++) {
                        if (BOARD[x + i][y + j] != next) cnt++;
                        next = NOT(next);
                }
                //배열의 한 행이 끝나면 다음 행의 시작 색 결정
                row_start = NOT(row_start);
        }
        return cnt;
}
int main()
{
        using namespace std;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) cin >> BOARD[i][j];
        }
        int ans = INT_MAX;
        for (int i = 0; i + 8 <= N; i++) {
                for (int j = 0; j + 8 <= M; j++) {
                        int tmp = min(get_cnt(i, j, 'W'), get_cnt(i, j, 'B'));
                        if (ans > tmp) ans = tmp;
                }
        }
        cout << ans << endl;
}
