#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
#define DWARF 9
int r1, r2, list[DWARF];
void solve() {
        //중첩 반복문으로 제외할 두 값 결정
        //전체 합에서 두 값을 뺐을 때 100이 되는 경우 찾기
        int sum = accumulate(list, list + DWARF, 0);
        for (int i = 0; i < DWARF; i++) {
                for (int j = 0; j < DWARF; j++) {
                        if (sum - list[i] - list[j] == 100) {
                                r1 = i; r2 = j;
                                return;
                        }
                }
        }
}
int main() {
        for (int i = 0; i < DWARF; i++)
                cin >> list[i];
        sort(list, list + DWARF);
        solve();
        for (int i = 0; i < DWARF; i++) {
                if (i == r1 || i == r2) continue;
                cout << list[i] << endl;
        }
}
