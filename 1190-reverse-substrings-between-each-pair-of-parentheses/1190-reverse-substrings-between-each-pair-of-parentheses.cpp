class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int> mp;
        int n = s.size();
        vector<int> v1;
        for(int i = 0;i<n;i++)
        {
            if(s[i] == '(')v1.push_back(i);
            if(s[i] == ')'){
                int l = v1[v1.size() - 1];
                v1.pop_back();
                mp[l] = i;
                mp[i] = l;
            }
        }
        

        int dir = 1;
        n = s.size();
        string st = "";
        //for(auto it: mp)cout<<it.first<<" "<<it.second<<endl;
        for(int i = 0;i<n;i+=dir)
        {
            if(s[i]!=')' && s[i] != '('){
                st+=s[i];
            }
            else
            {
                dir = -dir;
                i = mp[i];
            }
        }
        return st;
    }
};