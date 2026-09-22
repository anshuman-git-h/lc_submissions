class Solution {
public:
    vector<int> a,b;
    int dp[501][501];
    int fun(int i,int j)
    {
        int n = a.size();
        int m = b.size();
        if(i >= n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans = max(fun(i,j+1), fun(i+1,j));
        if(a[i] == b[j])ans = max(ans, 1+fun(i+1,j+1));
        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        a = nums1;
        b = nums2;
        memset(dp,-1,sizeof(dp));
        return fun(0,0);
    }
};