#include <bits/stdc++.h>
using namespace std;

int jzzh(const int &n, const string &x) {
    int ans = 0;
    for (int i = 0; i < x.length(); ++i) {
        int num;
        char a = x[x.length() - i - 1];
        if (a <= '9') {
            num = a - '0';
        } else {
            num = a - 'A' + 10;
        }
        ans += num * pow(n, i);
    }
    return ans;
}

int main() {
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    string s;

    cin >> x >> s;
    cout << jzzh(x, s);

    cout << "\n";
    return 0;
}
