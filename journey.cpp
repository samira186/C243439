#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> g[N];

double dfs(int u, int p) {
    int child = 0;
    double ans = 0.0;

    for (int v : g[u]) {
        if (v == p) continue;
        child++;
    }

    if (child == 0)
        return 0.0;

    for (int v : g[u]) {
        if (v == p) continue;
        ans += (dfs(v, u) + 1.0) / child;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    cout << fixed << setprecision(10) << dfs(1, 0);

    return 0;
}
