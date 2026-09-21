class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans(n,vector<int>(k,0));
        
        

        for(int i = 0;i<n;i++)
        {
            nums[i] = nums[i]%k;
            ans[i][nums[i] % k]++;
            if(i == 0)continue;
            for(int j = 0;j<k;j++)
            {
                ans[i][(j*nums[i])%k] += ans[i-1][j];
            }
        }
        vector<long long> res;
        for(int i = 0;i<k;i++)
        {
            long long sm = 0;
            for(int j= 0;j<n;j++)sm+=ans[j][i];
            res.push_back(sm);
        }
        return res;
    }
};


