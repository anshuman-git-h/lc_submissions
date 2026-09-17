class Solution {
public:
    int trap(vector<int>& height) {
        //max left max right - height
        int n = height.size();
        vector<int> le(n,0),ri(n,0);
        int mxl = 0;
        for(int i = 0;i<n;i++)
        {
            le[i] = mxl;
            mxl = max(mxl,height[i]);
        }
        int mxr = 0;
        for(int i = n-1;i>=0;i--)
        {
            ri[i] = mxr;
            mxr = max(mxr,height[i]);
        }
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans += max(min(le[i] ,ri[i]) - height[i],0);
        }
        return ans;

    }
};