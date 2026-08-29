class Solution {
public:
    const int inf = 1e9;
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,inf));

        dp[n-1][m-1] = 0;
        int mx = 0;
        for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)mx = max(grid[i][j],mx);
        vector<int> tel(mx+1,inf);

        for(int t = 0;t<=k;t++)
        {
            for(int i = n-1;i>=0;i--)
            {
                for(int j = m-1;j>=0;j--)
                {
                    if(i+1<n)
                    {
                        dp[i][j] = min(dp[i][j], dp[i+1][j] + grid[i+1][j]);
                    }
                    if(j+1<m)
                    {
                        dp[i][j] = min(dp[i][j], dp[i][j+1] + grid[i][j+1]);
                    }
                    
                    if(t)
                    {
                        dp[i][j] = min(dp[i][j], tel[grid[i][j]]);
                    }
                }
            }

            for(int i = 0;i<n;i++)
            {
                for(int j = 0;j<m;j++)
                {
                    tel[grid[i][j]] = min(tel[grid[i][j]],  dp[i][j]);
                }
            }
            int mn = inf;
            for(int i = 0;i<mx+1;i++)
            {
                mn = min(mn,tel[i]);
                tel[i] = mn;
            }
        }
        return dp[0][0];
    }
};