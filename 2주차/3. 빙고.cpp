#include<iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int bingo[6][6];
int row, col, line=0, lb = 1, rb = 1;
//사회자가 부른 수의 위치 찾기
void findIndex(int num) {
        for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++) {
                        if (bingo[i][j] == num) {
                                bingo[i][j] = 0; //표시
                                row = i; col = j;
                                return;
                        }
                }
        }
}
//5개의 수가 모두 지워질 때 빙고(누적)
//가로, 세로, 왼오 대각선 빙고인지 확인, 3빙고면 return true
int lineCheck() {
        int rowCnt = 0, colCnt = 0, leftCnt = 0, rightCnt = 0;
        for (int i = 1; i <= 5; i++) {
                if (bingo[row][i] == 0) rowCnt++; //가로
                if (bingo[i][col] == 0) colCnt++; //세로
                if (lb&&bingo[i][i] == 0) leftCnt++; //왼쪽 대각선
                if (rb&&bingo[6 - i][i] == 0)rightCnt++; //오른쪽 대각선
        }
        //대각선은 한번 완성되면 끝
        if (leftCnt == 5) {
                line++;
                lb = 0;
        }
        if (rightCnt == 5) {
                line++;
                rb = 0;
        }
        if (rowCnt == 5) line++;
        if (colCnt == 5) line++;
        if (line >= 3) return 1;
        else return 0;
}
int main(){
        for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++)
                        cin >> bingo[i][j];
        }
        int num;
        for (int i = 1; i <= 5; i++) {
                for (int j = 1; j <= 5; j++) {
                        cin >> num;
                        findIndex(num);
                        if (lineCheck()) {
                                cout << (i - 1) * 5 + j;
                                return 0;
                        }
                }
        }
}
