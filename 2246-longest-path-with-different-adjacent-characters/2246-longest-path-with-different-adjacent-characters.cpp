class Solution {
public:
    int ans = 0;
    string ss;
    vector<vector<int>> adj;
    int fun(int node,int par)
    {
        int mx = 0;
        int smx = 0;
        for(auto it: adj[node])
        {
            if(it == par)continue;
            int chl = fun(it,node);
            if(ss[it] == ss[node])continue;

            if(chl > mx)
            {
                smx = mx;
                mx = chl;
            }

            else if(chl > smx)
            {
                smx = chl;
            }
        }
        ans = max({ans, 1 + mx + smx, 1 + mx});
        return 1 + mx;

    }
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        adj.resize(n,{});
        for(int i = 1;i<n;i++)
        {
            adj[i].push_back(parent[i]);
             adj[parent[i]].push_back(i);
        }
        ss = s;
        int a = fun(0,-1);
        return ans;
    }
};