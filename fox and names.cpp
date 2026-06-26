#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> g[N];
int cat[N];
int m;
int ans = 0;

void dfs(int u, int p, int cnt) {
    if (cat[u])
        cnt++;
    else
        cnt = 0;

    if (cnt > m)
        return;

    bool leaf = true;

    for (int v : g[u]) {
        if (v == p) continue;
        leaf = false;
        dfs(v, u, cnt);
    }

    if (leaf)
        ans++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> cat[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    cout << ans;

    return 0;
}
