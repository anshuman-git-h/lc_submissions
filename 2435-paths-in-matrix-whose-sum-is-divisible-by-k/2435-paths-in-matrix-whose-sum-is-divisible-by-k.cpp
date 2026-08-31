class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int md = 1e9+7;
    int fun(int r,int c,vector<vector<int>> &gr, int k,int sm)
    {
        int n = gr.size();
        int m = gr[0].size();
        if(r == n-1 && c == m-1)return (sm + gr[r][c])%k == 0;

        if(r>=n || c >= m)return 0;
        if(dp[r][c][sm]!=-1)return dp[r][c][sm];

        int ans = 0;
        int ri = fun(r,c+1,gr,k,(sm+gr[r][c])%k);
        int dow = fun(r+1,c,gr,k,(sm+gr[r][c])%k);

        return dp[r][c][sm] = (ri + dow)%md;;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n+1,vector<vector<int>> (m+1,vector<int>(k+1,-1)));
        return fun(0,0,grid,k,0);
    }
};