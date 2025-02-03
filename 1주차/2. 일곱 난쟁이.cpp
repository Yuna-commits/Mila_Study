#include<iostream>
#include<algorithm>
#define DWARF 9
int list[DWARF];
int r1, r2;
void solve() {
        //정렬한 리스트에서 두 값을 제외한 합이 100이 되는 경우 찾기
        //중첩 반복문으로 제외할 두 값 결정
        for (int i = 0; i < DWARF; i++) {
                for (int j = 0; j < DWARF && j != i; j++) {
                        int sum = 0;
                        for (int k = 0; k < DWARF; k++) {
                                if (k != i && k != j) sum += list[k];
                        }
                        if (sum == 100) {
                                r1 = i; r2 = j;
                                return;
                        }
                }
        }
}
int main() {
        using namespace std;
        for (int i = 0; i < DWARF; i++)
                cin >> list[i];
        sort(list, list + DWARF);
        solve();
        for (int i = 0; i < DWARF; i++) {
                if (i == r1 || i == r2) continue;
                cout << list[i] << endl;
        }
}
