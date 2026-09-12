class Solution {
public:
    vector<vector<int>> v;

    long long dp[50004][5];
    vector<int> path[50004][5];

    vector<int> addPath(vector<int> p, int val) {
        p.push_back(val);
        sort(p.begin(), p.end());
        return p;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        v = intervals;
        int n = v.size();
        for (int i = 0; i < n; i++)
            v[i].push_back(i);
        sort(v.begin(), v.end());

        for (int k = 0; k <= 4; k++) {
            dp[n][k] = 0;
            path[n][k].clear();
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int chosen = 3; chosen >= 0; chosen--) {
                long long sk = dp[ind + 1][chosen];

                vector<int> sk_pth = path[ind + 1][chosen];

                vector<int> a = {v[ind][1], INT_MAX};

                int nxt = upper_bound(v.begin(), v.end(), a) - v.begin();

                long long tk = v[ind][2] + dp[nxt][chosen + 1];

                vector<int> tk_pth = path[nxt][chosen + 1];

                tk_pth.push_back(v[ind][3]);
                sort(tk_pth.begin(), tk_pth.end());

                if (tk > sk || (tk == sk && tk_pth < sk_pth)) {
                    dp[ind][chosen] = tk;
                    path[ind][chosen] = tk_pth;
                } else {
                    dp[ind][chosen] = sk;
                    path[ind][chosen] = sk_pth;
                }
            }
        }

        return path[0][0];
    }
};