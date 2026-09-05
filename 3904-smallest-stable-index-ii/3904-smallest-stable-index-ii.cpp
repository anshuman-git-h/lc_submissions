class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n,0);
        vector<int> mn(n,INT_MAX);

        for(int i = 0;i<n;i++)
        {
            mx[i] = nums[i];
            if(i)mx[i] = max(mx[i-1],mx[i]);

        }
        for(int i = n-1;i>=0;i--)
        {
            mn[i] = nums[i];
            if(i<n-1)mn[i] = min(mn[i+1],nums[i]);
        }

        for(int i = 0;i<n;i++)
        {
            if(mx[i] - mn[i] <= k)return i;
        }
        return -1;
    }
};