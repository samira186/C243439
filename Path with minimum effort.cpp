class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int effort = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            if (x == m - 1 && y == n - 1)
                return effort;
            if (effort > dist[x][y])
                continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newEffort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.push({newEffort, {nx, ny}});
                    }
                }
            }
        }
        return 0;
    }
};
