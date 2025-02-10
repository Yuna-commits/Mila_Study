#include<iostream>
int M;
int main()
{
        using namespace std;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int ans = 1, x, y;
        cin >> M;
        while (M) {
                cin >> x >> y;
                ans = ((x == ans) ? y : (y == ans) ? x : ans);
                M--;
        }
        cout << ans << "\n";
}
