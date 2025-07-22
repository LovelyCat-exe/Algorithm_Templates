#include<bits/stdc++.h>
using namespace std;

int main()
{
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j) && __builtin_popcount(i) == m) {
                cout << a[j] << " ";
            }
        }
        if (__builtin_popcount(i) == m) {
            cout << "\n";
        }
    }

    return 0;
}