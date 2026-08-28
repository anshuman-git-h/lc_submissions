class Solution {
public:
    vector<pair<int,int>> a,r;
    vector<int> w;
    int dp[100005][3];
    int getn(int ll,int rr)
    {
        return (upper_bound(w.begin(),w.end(),rr) - w.begin()) - (lower_bound(w.begin(),w.end(),ll) - w.begin());
    }
    int fun(int ind,int prev)
    {
        if(ind == a.size())return 0;

        if(dp[ind][prev]!=-1)return dp[ind][prev];
        int ans = 0;
        if(ind == 0)
        {
            //shoot left
            int nl = getn(r[ind].first,a[ind].first);

            //shoot right
            int nr = getn(a[ind].first,r[ind].second);

            ans = max(nl + fun(ind+1,0), nr + fun(ind+1,1));
        }

        else
        {
            if(prev == 1)//right shot
            {
                int lr = max(r[ind-1].second+1,r[ind].first);
                int rr = r[ind].second;
                int nl = getn(lr,a[ind].first),nr = getn(a[ind].first,rr);
                ans= max(nl + fun(ind+1,0), nr + fun(ind+1,1));
            }
            else
            {
                int nl = getn(r[ind].first,a[ind].first);

                //shoot right
                int nr = getn(a[ind].first,r[ind].second);

                ans = max(nl + fun(ind+1,0), nr + fun(ind+1,1));
            }
        }

        return dp[ind][prev] = ans;
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        a.resize(n);
        for(int i = 0;i<n;i++)
        {
            a[i] = {robots[i], distance[i]};
        }

        sort(a.begin(),a.end());
        w = walls;
        sort(w.begin(),w.end());

        r.resize(n);

        for(int i = 0;i<n;i++)
        {
            int lp = (i == 0?1: a[i-1].first + 1);
            int rp = (i == n-1?1e9: a[i+1].first-1);
            r[i] = {max(lp,a[i].first - a[i].second), min(rp,a[i].first + a[i].second)};
        }
        memset(dp,-1,sizeof(dp));

        return fun(0,0);
    }
};