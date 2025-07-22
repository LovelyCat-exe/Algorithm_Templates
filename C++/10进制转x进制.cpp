#include <bits/stdc++.h>
using namespace std;

string ans = "";
char trans(int x)
{
    if (x < 10)
        return x + '0';
    else
        return x - 10 + 'A';
}
void jinzhi_zhuanhuan(int n, int x) {
    while (n != 0) {
        ans += trans(n % x);
        n /= x;
    }
}

int main()
{
    int n, x;
    cin >> n >> x;
    jinzhi_zhuanhuan(n, x);
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}
