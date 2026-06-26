class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        queue<pair<int,int>> q;
        q.push({src, 0});

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int sz = q.size();
            vector<int> temp = cost;

            while (sz--) {
                auto cur = q.front();
                q.pop();

                int u = cur.first;
                int c = cur.second;

                for (auto &f : flights) {
                    if (f[0] == u) {
                        int v = f[1];
                        int w = f[2];

                        if (c + w < temp[v]) {
                            temp[v] = c + w;
                            q.push({v, temp[v]});
                        }
                    }
                }
            }

            cost = temp;
            stops++;
        }

        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};
