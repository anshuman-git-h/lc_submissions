class Solution {
public:
    using ll = long long;
    ll dp[100005][5];
    const ll NEG = -1e14;
    ll fun(int ind,int rise,vector<int> &nums)
    {
        int n = nums.size();
        if(ind == n-1)
        {
            return (rise == 3?nums[ind]:NEG);
        }

        if(dp[ind][rise]!=NEG)return dp[ind][rise];

        int ans = 0;
        if(rise == 0)
        {
            ll skip = fun(ind+1,0,nums);
            ll take = NEG;
            if(nums[ind] < nums[ind+1])
            {
                take = nums[ind] + fun(ind+1, 1,nums);
            }

            return dp[ind][rise] = max(skip,take);
        }

        if(rise == 1)
        {
            if(ind<n-1) 
            {
                if(nums[ind] < nums[ind+1])return dp[ind][rise] = fun(ind+1,1,nums) + nums[ind];
                else if(nums[ind] > nums[ind+1]) return dp[ind][rise] = fun(ind+1,2,nums) + nums[ind];
            }
        }
        if(rise == 2)
        {
            if(nums[ind] > nums[ind+1])return dp[ind][rise] = nums[ind] + fun(ind+1,2,nums);
             else if(nums[ind] < nums[ind+1]) return dp[ind][rise] = nums[ind]+ fun(ind+1,3,nums);
        }
        if(rise == 3)
        {
            ll ans = nums[ind];
            if(ind + 1 < n && nums[ind] < nums[ind+1])
            {
                ans = max(ans, nums[ind] + fun(ind+1,3, nums));
            }
            return dp[ind][rise] = ans;
        }
        return dp[ind][rise];
    }
    long long maxSumTrionic(vector<int>& nums) {
        for(int i = 0;i<100005;i++)
        {
            for(int j = 0;j<5;j++)
            {
                dp[i][j] = NEG;
            }
        }

        return fun(0,0,nums);
    }
};