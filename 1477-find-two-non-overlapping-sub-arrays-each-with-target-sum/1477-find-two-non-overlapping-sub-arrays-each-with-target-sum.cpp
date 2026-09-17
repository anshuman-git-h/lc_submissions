class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int tar) {
        int n = arr.size();
        vector<int> prevlen(n,n+1);

        int j = 0;
        int i = 0;
        int sm = 0;
        int mn = n;
        int ans = n+1;
        while(j<n)
        {
            sm += arr[j];
            while(sm > tar)sm-=arr[i++];

            if(sm == tar)
            {
                int l = j - i + 1;
                if(i && prevlen[i-1] != n+1)
                {
                    ans = min(ans, l + prevlen[i-1]);
                }
                mn = min(mn,l);
            }

            prevlen[j++] = mn;
        }

        return ans == n+1?-1:ans;
    }
};