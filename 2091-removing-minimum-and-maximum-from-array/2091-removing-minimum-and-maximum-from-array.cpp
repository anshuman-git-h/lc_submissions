class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int x = -1,y = -1;
        int n = nums.size();
        int mn = *min_element(nums.begin(),nums.end());
        int mx = *max_element(nums.begin(),nums.end());

        for(int i = 0;i<n;i++){
            if(nums[i] == mx || nums[i] == mn){
            x = i;
            break;
        }
        }

        for(int i = n-1;i>=0;i--){
            if(nums[i] == mx || nums[i] == mn){
            y = i;
            break;
        }
        }

        x;
        int d = y-x;
        cout<<x<<" "<<y;
        y = n-y;
        return min({x + 1 + d, 1 + x+y,y + d});

    }
};