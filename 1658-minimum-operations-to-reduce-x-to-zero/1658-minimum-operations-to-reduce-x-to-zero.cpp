class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);

        int tar = sum - x;
        if(tar == 0)return n;
        int j = 0;
        int i = 0;
        int len = 0;
        int sm = 0;
        while(j<n)
        {
            sm += nums[j];
            while(sm>tar && i<n){
                sm-=nums[i++];
            }

            if(sm == tar){
                len = max(len, j - i + 1);
            }
            j++;
        }
        int res = n - len;
        if(res == n)res = -1;
        return res;

    }
};