class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        map<char,pair<int,int>> mp;
        for(char c = 'a';c<='z';c++)
        {
            int f = -1;
            int l = -1;
            for(int i = 0;i<n;i++)
            {
                if(s[i] == c)
                {
                    if(f == -1)f = i;
                    l = i;
                }
            }
            if(f == -1)continue;
            mp[c] = {f,l};
        }
        //vector<int> vis(26,0);
        for(auto it: mp)
        {
            char ch = it.first;

            int l = it.second.first;
            int r = it.second.second;
            if(l == -1)continue;
            for(int i = l;i<=r;i++)
            {
                char c = s[i];
                r = max(r, mp[c].second);
                if(l > mp[c].first)
                {
                    l = mp[c].first;
                    i = l-1;
                }
            }
            mp[ch] = {l,r};
        }
        vector<pair<int,int>> v;
        for(auto it: mp)
        {
            v.push_back({it.second.first,it.second.second});
        }

        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.second < b.second;
        });

        for(auto it: v)cout<<it.first<<" "<<it.second<<endl;
        vector<string> ans;
        int nn = v.size();
        int i = 0;
        while(i<nn)
        {
            int l = v[i].second - v[i].first + 1;
            string ss = s.substr(v[i].first,l);
            ans.push_back(ss);
            int ind = v[i].second;
            while(i<nn&&v[i].first <= ind)i++;
        }
        return ans;
    }
};