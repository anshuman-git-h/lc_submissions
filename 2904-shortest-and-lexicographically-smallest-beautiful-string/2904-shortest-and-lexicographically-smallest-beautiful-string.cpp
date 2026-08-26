class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> pre(s.size(),0);
        for(int i = 0;i<s.size();i++)
        {
            pre[i] = s[i] == '1'?1:0;
            if(i)pre[i]+=pre[i-1];
        }
        int n = pre.size();
        vector<string> ans;
        for(int i = 0;i<n;i++)
        {
            for(int j = i;j<n;j++)
            {
                if(s[i] == '1' && s[i] == s[j])
                {
                    int no = pre[j] - (i?pre[i-1]:0);
                    if(no == k)ans.push_back(s.substr(i,j-i+1));
                }
            } 
        }

        if(ans.size() == 0)return "";
        sort(ans.begin(),ans.end(),[&](string a, string b){
            if(a.size()!=b.size())return a.size() < b.size();
            else return a<b;
        });
        return ans[0];
    }
};