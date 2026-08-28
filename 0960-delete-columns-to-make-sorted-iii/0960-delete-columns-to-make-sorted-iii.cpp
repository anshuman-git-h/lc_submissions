class Solution {
public:
    int dp[101][103];
    int fun(int cur,int pre,vector<string> &strs)
    {

        if(cur == strs[0].size())return 0;
        
        if(dp[cur][pre+1]!=-1)return dp[cur][pre+1];
        int ans = 0;
        if(pre == -1)
        {
            return dp[cur][pre+1] = max(fun(cur+1,pre,strs) , 1 + fun(cur+1,cur,strs));
        }
        int n = strs.size();
        bool ok = true;
        for(int i = 0;i<n;i++)
        {
            string s = strs[i];
            if(s[pre]>s[cur])
            {
                ok = false;
                break;
            }
        }
        
        if(!ok)
        {
            ans = fun(cur+1,pre,strs);
        }
        else
        {
            ans = max(fun(cur+1,pre,strs) , fun(cur+1,cur,strs) + 1);
        }
        return dp[cur][pre+1] = ans;
    }
    int minDeletionSize(vector<string>& strs) {

        memset(dp,-1,sizeof(dp));
        int ans = fun(0,-1,strs);

        return strs[0].size() - ans;
    }
};