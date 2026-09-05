class Solution {
public:
    const int md = 1e9+7;
    int dp[1001];
    int fun(int day,int d, int f)
    {
        if(day<=0)return 0;
        if(day == 1)return 1;
        if(dp[day]!=-1)return dp[day];

        int ans = 0;
        int l = min(day-f+1,day-d);
        int r = max(day-f+1,day-d);
        for(int i = max(1,l);i<=r;i++)
        {
            ans = (ans + fun(i,d,f)) % md;
        }
        return dp[day] = ans;
    }
    int peopleAwareOfSecret(int n, int d, int f) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i = n-f+1;i<=n;i++)
        {
            ans = (ans + fun(i,d,f))%md;
        }
        return ans;
    }
};