class Solution {
public:
    int dp[1001][1001];
    int fun(string s,string t,int i,int j)
    {
        if(j == t.size())return 1;
        if(i == s.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int ans = 0;
        if(s[i] == t[j])
        {
            int mtch = 0;
            mtch = fun(s,t,i+1,j) + fun(s,t,i+1,j+1);
            ans = mtch;
        }
        else
        {
            int dmtch = fun(s,t,i+1,j);
            ans = dmtch;
        }
        return dp[i][j] = ans;
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return fun(s,t,0,0);
    }
};