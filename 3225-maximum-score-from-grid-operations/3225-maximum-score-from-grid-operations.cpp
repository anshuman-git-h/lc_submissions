class Solution {
public:
    using ll = long long;
    vector<vector<ll>> pre;
    ll dp[101][101][2];

    // Helper to safely get sum of column `col` from row `start` to `end` (0-indexed)
    ll getColSum(int col, int start, int end) {
        if (start > end) return 0;
        if (start == 0) return pre[end][col];
        return pre[end][col] - pre[start - 1][col];
    }

    ll fun(int col, int prev, bool prevTaken, vector<vector<int>> &grid) {
        int n = grid.size();
        if (col == n) return 0;

        if (dp[col][prev][prevTaken] != -1) return dp[col][prev][prevTaken];
        ll ans = 0;

        // cur represents height (0 to n cells colored)
        for (int cur = 0; cur <= n; cur++) {
            ll cursc = 0;
            ll prevsc = 0;

            if (cur < prev) {
                cursc = getColSum(col, cur, prev - 1); 
            }
            if (cur > prev && !prevTaken) {
                if (col > 0) prevsc = getColSum(col - 1, prev, cur - 1);
            }

            ll curtaken = cursc + prevsc + fun(col + 1, cur, true, grid);
            ll curNottaken = prevsc + fun(col + 1, cur, false, grid);
            ans = max({ans, curtaken, curNottaken});
        }

        return dp[col][prev][prevTaken] = ans;
    }

    ll maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        pre.assign(n, vector<ll>(n, 0));
        memset(dp, -1, sizeof(dp));

        // Fixed: Column-wise prefix sum (0-indexed)
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pre[i][j] = grid[i][j] + (i > 0 ? pre[i - 1][j] : 0);
            }
        }

        return fun(0, 0, false, grid);
    }
};