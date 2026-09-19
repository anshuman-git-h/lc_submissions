class Solution {
public:
    vector<int> par,sz;
    int find(int node)
    {
        if(node == par[node])return node;
        return par[node] = find(par[node]);
    }
    void merge(int u,int v)
    {
        int p = find(u);
        int q = find(v);
        if(p == q)return;
        if(sz[p] < sz[q])swap(p,q);
        par[q] = p;
        sz[p]+=sz[q];
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        par.resize(n);
        sz.resize(n,1);

        for(int i = 0;i<n;i++)par[i] = i;

        for(auto it: edges)
        {
            int p = find(it[0]);
            int q = find(it[1]);
            merge(p,q);
        }
        int c = 1;
        vector<int> cmp(n,-1);
        for(int i = 0;i<n;i++)
        {
            if(par[i] == i)
            {
                cout<<i<<endl;
                cmp[i] = c++;
            }
        }

        for(int i = 0;i<n;i++)
        {
            cmp[i] = cmp[find(i)];
        }
        long long ans = 0;

        unordered_map<int,int> mp;
        for(int i = 0;i<n;i++)mp[cmp[i]]++;

        //for(int i = 0;i<n;i++)cout<<cmp[i]<<" ";

        for(auto it: mp)
        {
            ans = (ans + (1LL)*it.second * (1LL)*(n-it.second));
        }
        return ans/2LL;
    }
};