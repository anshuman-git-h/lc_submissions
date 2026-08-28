class Solution {
public: 
    using ll = long long;
    const int md = 1e9+7;
    int numOfWays(int n) {
        if(n == 1)return 12;
        ll abc = 6;
        ll aba = 6;

        for(int i = 2;i<=n;i++)
        {
            int nabc = ((2*abc)%md + (2*aba)%md)%md;
            int naba = ((2*abc)%md + (3*aba)%md)%md;

            aba = naba;
            abc = nabc;
        }

        return (abc + aba)%md;
    }
};