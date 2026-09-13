class Solution {
public:
    using ll = long long;
    inline static vector<ll> o, e;
    inline static bool fl = false;

    void pre() {
        if (fl)
            return;
        fl = true;

        for (ll i = 1; i < 10; i++) {
            if (i & 1)
                o.push_back(i);
            else
                e.push_back(i);
        }

        vector<string> st = {"","0","1", "2", "3", "4", "5", "6", "7", "8", "9"};

        for (ll i = 1; i < 10000; i++) {
            string l = to_string(i);
            string r = l;
            reverse(r.begin(), r.end());

            for (ll j = 0; j < 11; j++) {
                string s = l + st[j] + r;
                ll x = stoll(s);

                if (x & 1)
                    o.push_back(x);
                else
                    e.push_back(x);
            }
        }

        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
    }

    long long minOperations(vector<int>& nums) {
        pre();

        ll ans = 0;

        for (int x : nums) {
            vector<ll>& v = (x & 1) ? o : e;

            int ind = lower_bound(v.begin(), v.end(), x) - v.begin();

            ll cost = LLONG_MAX;

            if (ind < v.size())
                cost = min(cost, (v[ind] - x) / 2);

            if (ind > 0)
                cost = min(cost, (x - v[ind - 1]) / 2);

            ans += cost;
        }

        return ans;
    }
};