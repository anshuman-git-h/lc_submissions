class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> p(n);
        for(int i = 0;i<n;i++)p[i] = {nums[i],i};

        sort(p.begin(),p.end());
        vector<int> ans(n);
        int l = 0;
        while(l<n)
        {
            int r = l;
            while(r+1<n && p[r].first + limit>=p[r+1].first)r++;

            vector<int> ind;
            for(int i = l;i<=r;i++)
            {
                ind.push_back(p[i].second);
            }
            sort(ind.begin(),ind.end());
            for(int i = 0;i<ind.size();i++)
            {
                ans[ind[i]] = p[i+l].first;
            }
            l = r+1;
        }
        return ans;
    }
};