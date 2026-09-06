class Solution {
public:
    int dp[1001][1001];
    const int md = 1e9+7;
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        int m = t.size();
        for(int i = 0;i<=m;i++)dp[n][i] = 0;
        for(int i = 0;i<=n;i++)dp[i][m] = 1;

        for(int i = n-1;i>=0;i--)
        {
            for(int j = m-1;j>=0;j--)
            {
                if(s[i] == t[j])
                {
                    dp[i][j] = (dp[i+1][j] + dp[i+1][j+1])%md;
                }
                else
                {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }

        return dp[0][0];
    }
};