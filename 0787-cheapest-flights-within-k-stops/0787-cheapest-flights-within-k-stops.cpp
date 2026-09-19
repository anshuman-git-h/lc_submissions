class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: flights)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }

        vector<int> dis(n,1e9);

        queue<vector<int>> pq;

        pq.push({0,0,src});//stops,cost,node
        dis[src] = 0;
        while(!pq.empty())
        {
            auto it = pq.front();
            pq.pop();
            int cost = it[0];
            int stops = it[1];
            int u = it[2];
            if(stops > k)continue;
            for(auto [v,w]: adj[u])
            {
                if(dis[v] > cost + w)
                { 
                    dis[v] = cost + w;
                    pq.push({cost + w,stops + 1,v});
                }
            }
        }

        return dis[dst] == 1e9?-1:dis[dst];
    }
};