class Solution {
public:
    vector<int> par,sz;
    int fin(int node)
    {
        if(node == par[node])return node;
        return par[node] = fin(par[node]);
    }
    void merge(int p,int q)
    {
        int u = fin(p);
        int v = fin(q);
        if(u == v)return;
        if(v < u)swap(u,v);

        sz[u] += sz[v];
        par[v] = u;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n = vals.size();
        par.resize(n);
        sz.resize(n,1);
        for(int i = 0;i<n;i++)par[i] = i;

        map<int,vector<int>> v2n;
        for(int i = 0;i<n;i++)
        {
            v2n[vals[i]].push_back(i);
        }

        map<int,vector<int>> adj;
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = n;
        vector<int> active(n,0);

        for(auto it: v2n){
            vector<int> nodes = it.second;
            for(auto &u: nodes)
            {
                active[u] = 1;
                for(auto &v: adj[u])
                {
                    if(active[v])
                    {
                        merge(u,v);
                    }
                }
            }


            vector<int> parents_of_these_nodes;
            for(auto &it: nodes)
            {
                parents_of_these_nodes.push_back(fin(it));
            }

            map<int,int> par2nm;
            for(auto it: parents_of_these_nodes)
            {
                par2nm[it]++;
            }   

            for(auto it: par2nm)
            {
                if(it.second > 1)
                {
                    ans += (it.second*(it.second - 1))/2;
                }
            }
        }
        return ans;
    }
};