class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> vis(n, vector<int>(n,0));

        pq.push({grid[0][0],{0,0}});

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();

            int t=cur.first;
            int x=cur.second.first;
            int y=cur.second.second;

            if(vis[x][y]) continue;
            vis[x][y]=1;

            if(x==n-1 && y==n-1)
                return t;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]){
                    pq.push({max(t,grid[nx][ny]),{nx,ny}});
                }
            }
        }

        return -1;
    }
};
