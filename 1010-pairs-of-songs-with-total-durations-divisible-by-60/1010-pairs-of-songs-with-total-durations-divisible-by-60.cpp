class Solution {
public:
    using ll = long long;
    const int md = 1e9+7;
    int numPairsDivisibleBy60(vector<int>& time) {
        ll n = time.size();
        vector<ll> v(60,0);
        for(ll i = 0;i<n;i++)
        {
            time[i] = time[i] % 60;
            v[time[i]]++;
        }
        ll ans = v[0]*(v[0]-1)/2 + v[30]*(v[30]-1)/2;
        
        for(ll i = 1;i<30;i++)
        {
            if(v[i] && v[60-i])
            {
                ans = (ans + v[i]*v[60-i]);
            }
            //cout<<v[i]<<endl;
        }
        return ans;
    }
};