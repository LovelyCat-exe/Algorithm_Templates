#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> Input(int n, int m) {
    vector<vector<int>> INPUT(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> INPUT[i][j];
    return INPUT;
}

bool check(int x, int y, int n, int m, int oldclr, vector<vector<bool>>& vis, vector<vector<int>>& a) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && a[x][y] == oldclr;
}

void BFS(vector<vector<int>>& a, int pa, int pb, int target, int n, int m) {
    if (a[pa][pb] == target) return;

    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {0, 1, -1, 1, -1, 1, 0, -1};
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    int should_fill_clr = a[pa][pb];
    q.push({pa, pb});
    vis[pa][pb] = true;
    a[pa][pb] = target;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, n, m, should_fill_clr, vis, a)) {
                vis[nx][ny] = true;
                a[nx][ny] = target;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a = Input(n, m);

    int q;
    cin >> q;
    while (q--) {
        int ta, tb, tg;
        cin >> ta >> tb >> tg;
        BFS(a, ta - 1, tb - 1, tg, n, m);  // 修正坐标
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
