class Solution {
public:
    const int inf = 1e9;
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> dis(n,vector<int>(m,inf));
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq; //effort, x, y

        pq.push({0,0,0});
        dis[0][0] = 0;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int ef = it[0];
            int x = it[1];
            int y = it[2];
            if(ef > dis[x][y])continue;
            for(int i = 0;i<4;i++)
            {
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;

                if(nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    int cur = h[x][y];
                    int nxt = h[nx][ny];
                    int df = abs(nxt - cur);

                    int nef = max(ef,df);

                    if(nef < dis[nx][ny])
                    {
                        dis[nx][ny] = nef;
                        pq.push({nef,nx,ny});
                    }
                }
            }
        }
        return dis[n-1][m-1];
    }
};