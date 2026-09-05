class Solution {
public:
    int dp[100005][2];
    int fun(vector<int> &v,int k,int ind,int taken)
    {
        int n = v.size();
        if(ind>= n){
            if(taken)return 0;
            return INT_MIN;
        }
        if(dp[ind][taken]!=INT_MIN)return dp[ind][taken];
        int ans = 0;
        if(!taken)
        {
            ans = max(fun(v,k,ind+1,0),   fun(v,k,ind+k,1) + v[ind]);
        }
        else
        {
            ans = fun(v,k,ind+k,1) + v[ind];
        }
        return dp[ind][taken] = ans;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        for(int i = 0;i<100005;i++)
        {
            for(int j = 0;j<2;j++)dp[i][j] = INT_MIN;
        }
        int ans = fun(energy,k,0,0);
        
        return ans;
    }
};