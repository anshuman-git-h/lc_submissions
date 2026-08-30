class Solution {
public: 
    const int md = 1e9+7;
    
    int countPartitions(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> dp(n+1,-1);
        vector<int> pre(n+1,0);
        dp[0] = 1;
        pre[0] = 1;

        deque<int> mnd,mxd;
        int i = 0,j = 0;
        while(j<n)
        {
            while(!mxd.empty() && nums[j] > nums[mxd.back()])
            {
                mxd.pop_back();
            }
            mxd.push_back(j);
            while(!mnd.empty() && nums[j] < nums[mnd.back()])
            {
                mnd.pop_back();
            }
            mnd.push_back(j);

            while(i<=j && nums[mxd.front()] - nums[mnd.front()] > k)
            {
                i++;

                if(!mxd.empty() && mxd.front() < i)mxd.pop_front();
                if(!mnd.empty() && mnd.front() < i)mnd.pop_front();

            }

            dp[j+1] = (pre[j] - ((i?pre[i-1]:0) + md)) % md;
            pre[j+1] = (pre[j] + dp[j+1]) % md;
            j++;
        }
        return (dp[n]+md) % md;
    }
};