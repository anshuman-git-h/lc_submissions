class Solution {
public:
    vector<vector<int>> adj;
    vector<int> sz;
    string s;
    vector<int> dfs(int node,int par)
    {
        vector<int> cnt(26,0);
        for(auto it: adj[node])
        {
            if(it == par)continue;
            vector<int> tm = dfs(it,node);
            for(int i = 0;i<26;i++)
            {
                cnt[i] += tm[i];
            }
        }
        cnt[s[node] - 'a']++;
        sz[node] = cnt[s[node] - 'a'];
        return cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        sz.resize(n,1);
        s = labels;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> a = dfs(0,-1);
        return sz;

    }
};