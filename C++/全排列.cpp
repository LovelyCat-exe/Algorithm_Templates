#include<bits/stdc++.h>
using namespace std;

vector<int> a;
vector<int> num;
vector<bool> flag;
int n;

void f(int cnt) {
    if (cnt == n) {
        for (int i = 1; i <= n; ++i) {
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!flag[i]) {
            flag[i] = 1;
            num[cnt + 1] = a[i];
            f(cnt + 1);
            flag[i] = 0;
        }
    }
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    a.resize(n + 1);
    num.resize(n + 1);
    flag.resize(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    f(0);

    cout << "\n";
    return 0;
}
