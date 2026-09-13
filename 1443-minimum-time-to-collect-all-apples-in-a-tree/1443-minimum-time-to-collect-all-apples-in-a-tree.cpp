class Solution {
public:
    vector<int> vis;
    vector<vector<int>> adj;
    vector<bool> vv;
    bool dfs1(int node,int par,vector<bool> &v)
    {
        vis[node] = 1;
        bool apple = v[node];
        for(auto it: adj[node])
        {
            if(it == par)continue;

            if(!vis[it])
            {
                apple|= dfs1(it,node,v);
            }
        }
        vv[node] = apple;
        return apple;
    }
    int dfs(int node,int par,vector<bool> &v)
    {
        
        int ans = 0;
        for(auto it: adj[node])
        {
            if(it == par)continue;

            if(vv[it])
            {
                ans+= 2 + dfs(it,node,v);
                
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        vv.resize(n,0);
        vis.resize(n,0);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs1(0,-1,hasApple);
        
        return dfs(0,-1,hasApple);
    }
};