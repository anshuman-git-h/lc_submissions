class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sm = 0;
        vector<int> ss(n,0);
        for(int i = 0;i<n;i++)
        {
            ss[i] = gas[i] - cost[i];
            sm+=ss[i];
        }
        if(sm<0)return -1;
        vector<int> s1(2*n);
        for(int i = 0;i<2*n;i++)
        {
            s1[i] = ss[i%n];
        }
        int i = 0;
        int j = 0;
        int csm = INT_MIN;
        int mx = INT_MIN;
        int ind = -1;
        while(j<2*n)
        {
            if(csm < 0)
            {
                csm = s1[j];
                i = j;
            }
            else
            {
                csm += s1[j];
            }

            if(mx < csm)
            {
                mx = csm;
                ind = i;
            }

            j++;
        }
        return ind;
    }
};