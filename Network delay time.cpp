class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n + 1);
        for (auto &e : times) {
            graph[e[0]].push_back({e[1], e[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int d = cur.first;
            int u = cur.second;
            if (d > dist[u]) continue;
            for (auto &edge : graph[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
