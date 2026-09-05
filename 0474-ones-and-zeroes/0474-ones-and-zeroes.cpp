class Solution 
{
public:
    int dp[601][101][101];
    int ons(string &s)
    {
        int on = 0;
        for(auto it: s)if(it == '1')on++;
        return on;
    }
    int fun(int ind,vector<string> &st,int m,int n)
    {
        if(ind == st.size())return 0;
        if(dp[ind][m][n]!=-1)return dp[ind][m][n];
        int sk = fun(ind+1,st,m,n);
        int tk = 0;
        int ones = ons(st[ind]);
        int zeros = st[ind].size() - ones;
        if(m >= zeros && n >= ones)
        {
            tk = 1 + fun(ind+1,st,m-zeros,n - ones);
        }
        return dp[ind][m][n] = max(tk,sk);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return fun(0,strs,m,n);
    }
};