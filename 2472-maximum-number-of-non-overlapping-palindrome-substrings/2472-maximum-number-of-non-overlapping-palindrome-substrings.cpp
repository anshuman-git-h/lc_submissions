class Solution {
public:
    int dp[3001];
    vector<vector<bool>> pal;
    int fun(int ind,int k,string s)
    {
        if(ind == s.size())return 0;

        if(dp[ind]!=-1)return dp[ind];
        int ans = fun(ind+1,k,s);

        for(int j = ind + k-1;j<s.size();j++)
        {
            if(pal[ind][j])
            {
                ans  = max(ans, 1 + fun(j+1,k,s));
            }
        }
        return dp[ind] = ans;
    }
    int maxPalindromes(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n = s.size();
        pal.resize(n+1,vector<bool> (n+1,false));

        for(int i = 0;i<=n;i++)pal[i][i] = 1;
        for(int i = 0;i<n-1;i++)
        {
            if(s[i] == s[i+1])pal[i][i+1] = 1;
        }
        for(int l = 3;l<=n;l++)
        {
            for(int i = 0;i+l<=n;i++)
            {
                int j = i + l - 1;
                if(s[i] == s[j] && pal[i+1][j-1])pal[i][j] = 1;
            }
        }


        dp[n] = 0;
        for(int i = n-1;i>=0;i--)
        {
            int ans = dp[i+1];
            for(int j = i+k-1;j<n;j++)
            {
                if(pal[i][j])ans = max(ans, 1 + dp[j+1]);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};