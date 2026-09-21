class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k);
        vector<int> cur(k,0),prev(k,0);
        for(int i = 0;i<n;i++)
        {
            cur.assign(k,0);
            nums[i] = nums[i]%k;
            cur[nums[i] % k]++;
            for(int j = 0;j<k;j++)
            {
                int pr = (j*nums[i])%k;
                cur[pr] += prev[j];
                ans[pr] += prev[j];
            }
            ans[nums[i]]++;
            prev = cur;

        }
        return ans;
    }
};


