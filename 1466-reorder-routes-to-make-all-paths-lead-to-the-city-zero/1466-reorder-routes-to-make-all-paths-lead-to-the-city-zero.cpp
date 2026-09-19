class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ad(n);
        map<vector<int>,int> mp;
        for(auto it: connections)
        {
            mp[it]++;
            ad[it[0]].push_back(it[1]);
            //ad1[it[0]].push_back(it[1]);
            ad[it[1]].push_back(it[0]);
        }

        queue<int>q;
        int cnt = 0;
        vector<int> vis(n,0);
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for(auto it: ad[node])
            {
                if(vis[it])continue;
                q.push(it);
                if(mp.find({node,it})!=mp.end())cnt++;
                
            }
        }
        return cnt;
    }
};