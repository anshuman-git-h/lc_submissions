class Solution {
public:
    map<long long,long long> mp;
    long long dp[100005];
    using ll = long long;
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp,-1,sizeof(dp));
        for(auto it: power)mp[it]++;
        vector<int> v;
        for(auto it : mp)v.push_back(it.first);
        int n = v.size();
        dp[n] = 0;

        for(int i = n-1;i>=0;i--)
        {
            ll sk = dp[i+1];
            ll tk = mp[v[i]] * v[i];
            int nxt = lower_bound(v.begin(),v.end(),v[i] + 3) - v.begin();
            if(nxt!=n)tk += dp[nxt];
            dp[i] = max(sk,tk);
        }

        return dp[0];
    }
};