class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        bool ok = true;
        vector<int> pre_o(n,0),pre_e(n,0);
        for(int i = 0;i<n;i++)
        {
            pre_e[i] = (nums1[i]&1?0:1);
            pre_o[i] = (nums1[i]&1?1:0);
            if(i)
            {
                pre_o[i] += pre_o[i-1];
                pre_e[i] += pre_e[i-1];
            }
           // cout<<pre_e[i]<<" "<<pre_o[i]<<endl;
        }

        //all even
        for(int i = 0;i<n;i++)
        {
            if((nums1[i]&1) == 0)continue;
            if(pre_o[i]>1)continue;
            else
            {
                ok = false;
                break;
            }
        }
        if(ok)return true;

        //all odd
        ok = true;
        for(int i = 0;i<n;i++)
        {
            if((nums1[i]&1))continue;
            if(pre_o[i]>=1)continue;
            else
            {
                ok = false;
                break;
            }
        }
        return ok;
    }
};