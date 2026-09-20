class Solution {
public:
    using ll = long long;
    long long fun(vector<ll> &v)
    {
        if(v.size() == 0)return 0;
        ll n = v.size();
        ll cur = v[0];
        ll mn = v[0];

        for(int i = 1; i < n; i++)
        {
            cur = min(v[i], cur + v[i]);
            mn = min(mn, cur);
        }

        return mn;
    }
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        ll  sm = 0;
        for(int i = 0;i<n;i++)
        {
            if(i&1)nums[i] = -nums[i];
            sm += nums[i];
        }
        cout<<sm<<endl;
        vector<ll> o,e;
        for(int i = 0;i<n-1;i+=2)
        {
            e.push_back(nums[i] + nums[i+1]);
        }
        for(int i = 1;i<n-1;i+=2)
        {
            o.push_back(nums[i] + nums[i+1]);
        }

        ll mn = min(fun(o),fun(e));
        return max(sm,sm - 2*mn);

    }
};