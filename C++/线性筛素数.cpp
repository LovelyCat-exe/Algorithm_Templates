#include<bits/stdc++.h>
using namespace std;

const int N = 100000000;
bool vis[N + 5];
int pri[10000005];
int cnt = 0;

void primes(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) pri[++cnt] = i;
        for (int j = 1; j <= cnt; ++j) {
            if (1ll * i * pri[j] > n)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0) 
                break;
        }
    }
}
// pri[i]存储第i个素数
