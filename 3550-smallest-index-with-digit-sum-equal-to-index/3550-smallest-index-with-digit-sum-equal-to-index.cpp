class Solution {
    int fun(int a)
    {
        int s = 0;
        while(a>0)
            {
                s +=  a%10;
                a/=10;
            }
        return s;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
            {
                if(fun(nums[i]) == i)return i;
            }
        return -1;
    }
};