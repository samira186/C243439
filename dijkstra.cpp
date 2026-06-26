#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> g(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> dist(n + 1, INF);
    vector<int> parent(n + 1);

    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    dist[1] = 0;
    parent[1] = -1;

    pq.push({0, 1});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        ll d = cur.first;
        int u = cur.second;

        if (d > dist[u]) continue;

        for (auto &edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }

    vector<int> path;

    for (int v = n; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    for (int x : path)
        cout << x << " ";

    return 0;
}
