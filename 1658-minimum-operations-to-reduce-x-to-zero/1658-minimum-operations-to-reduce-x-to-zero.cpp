class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int> mp;//suffix sum and index
        int sm = 0;
        int n = nums.size();
        bool ok = false;
        mp[0] = n;
        for(int i = n-1;i>=0;i--){
            sm += nums[i];
            mp[sm] = i;
        }
        
        int ans = n;
        if(mp.find(x)!=mp.end()){
            ok = true;
            ans = n - mp[x];
        }
        int pre = 0;
        
        for(int i = 0;i<n;i++){
            pre+=nums[i];
            if(mp.find(x - pre)!=mp.end()){
                int r = mp[x - pre];
                if(r <= i)continue;
                ok = true;
                
                r = n - r;
                if(r + i + 1 < ans){
                    ans = r + i + 1;
                }
            }
        }
        if(ok)return ans;
        return -1;
    }
};