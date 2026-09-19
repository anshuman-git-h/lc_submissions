class Solution {
public:
    vector<vector<int>> ad,rev;
    vector<int> vis,sc;
    void dfs(int node,stack<int> &st)
    {
        vis[node] = 1;
        

        for(auto it : ad[node])
        {
            if(!vis[it])
            {
                dfs(it,st);
            }
        }
        st.push(node);
    }
    void dfs1(int node,int scc)
    {
        vis[node] = 0;
        
        sc[node] = scc;

        for(auto it : rev[node])
        {
            if(vis[it])
            {
                dfs1(it,scc);
            }
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        ad.resize(n);
        rev.resize(n);
        for(int i = 0;i<n;i++)
        {
            if(edges[i] == -1)continue;
            ad[i].push_back(edges[i]);
            rev[edges[i]].push_back(i);
        }
        vis.resize(n,0);
        sc.resize(n);
        stack<int> st;
        
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])dfs(i,st);
        }

        int scc = 1;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(!vis[node])continue;
            dfs1(node,scc);
            scc++;
        }

        //for(int i = 0;i<n;i++)cout<<sc[i]<<" ";
        int cn = 0;
        unordered_map<int,int> mp;
        for(auto it: sc)mp[it]++;
        for(auto it: mp)cn = max(cn, it.second);
        return cn == 1?-1:cn;


    }
};