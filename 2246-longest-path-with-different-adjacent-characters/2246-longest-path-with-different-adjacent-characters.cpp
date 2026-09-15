class Solution {
public:
    vector<vector<int>> adj;
    pair<int,int> fun(int node,int par)
    {
        pair<int,int> ans = {node,0};
        for(auto it: adj[node])
        {
            if(it == par)continue;

            pair<int,int> tmp = fun(it,node);
            if(tmp.second + 1 > ans.second)
            {
                ans = {tmp.first,tmp.second + 1};
            }
        }
        return ans;
    }
    int dia(int node)
    {
        pair<int,int> p1 = fun(node,-1); //node, dia
        pair<int,int> p2 = fun(p1.first,-1);
        return p2.second + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        //diameter on the the connected components after removing edges with the same chars
        int n = parent.size();
        adj.resize(n,{});

        for(int i = 1;i<n;i++)
        {
            int par = parent[i];

            if(s[par] == s[i])continue;
            adj[par].push_back(i);
            adj[i].push_back(par);
        }
        vector<int> vis(n,0);
        int ans = 1;
        for(int i = 0;i<n;i++)
        {
            if(vis[i])continue;

            queue<int> q;
            q.push(i);
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto it: adj[node])
                {
                    if(vis[it])continue;
                    vis[it] = 1;
                    q.push(it);
                }
            }

            ans = max(ans, dia(i));
        }
        return ans;


    }
};