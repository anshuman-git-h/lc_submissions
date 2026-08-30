class Solution {
public:
    using ll = long long;
    vector<vector<ll>> dp;
    const int inf = 1e9;
    const int md = 1e9+7;
    
    ll bpo(ll b,ll e)
    {
        ll res = 1;
        while(e)
        {
            if(e&1)res = (res * b)%md;
            e/=2;
            b = (b*b)%md;
        }
        return res;
    }
    
    int minOperations(vector<int>& nums, int sum) {
        
        
        ll n = nums.size();
        dp.resize(n+1,vector<ll> (sum+1,-1));

        for(ll i = 0;i<=n;i++)dp[i][0] = 0;
        for(ll i = 1;i<=sum;i++)dp[n][i] = inf;

        for(ll ind = n-1;ind>=0;ind--)
        {
            for(ll sm = 0;sm<=sum;sm++){
                ll sk = dp[ind+1][sm];
                ll tk = inf;
                for(ll i = 0;i<10;i++)
                {
                    ll vl = nums[ind]/(1LL<<i);
                    if(vl == 0)break;
                    for(ll j = 0;;j++)
                    {
                        ll val = vl*(1LL<<j);
                        if(val > sm)break;
                        ll nx = dp[ind+1][sm - val];
                        if(nx!=inf)tk = min(tk, nx + i + j);
                        
                    }
                }

                dp[ind][sm] = min(tk,sk);
            }
        }
        ll ans = dp[0][sum];
        return ans == inf?-1:ans;
    }
};