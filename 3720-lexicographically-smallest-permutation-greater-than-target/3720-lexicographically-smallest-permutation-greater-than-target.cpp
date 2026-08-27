class Solution {
public:
    string lexGreaterPermutation(string s, string target) 
    {
        sort(s.begin(),s.end());
        int n = target.size();
        string ss = "";
        bool ok = true;
        int i;
        if(s[s.size()-1] < target[0])return "";
        for(i = 0;i<n;i++)
        {
            auto it = lower_bound(s.begin(),s.end(),target[i]);
    
            if( it!=s.end() && *it == target[i])
            {
                ss = ss + *it;  
                s.erase(it);
            }
            else if(it!=s.end())
            {
                ss+= *it;
                s.erase(it);
                ss += s;
                return ss;
            }
            else //back track
            {
                string rem = s;
                for(int j = ss.size()-1;j>=0;j--)
                {
                    rem += ss[j];
                    sort(rem.begin(),rem.end());
                    auto itt = upper_bound(rem.begin(),rem.end(),ss[j]);
                    if(itt!=rem.end())
                    {
                        string res = ss.substr(0,j);
                        res+=*itt;
                        rem.erase(itt);
                        res+=rem;
                        return res;                    
                    }
                }
                return "";
            }
        }
        if(target == ss)
        {
            string rem = s;
            for(int j = ss.size()-1;j>=0;j--)
            {
                rem += ss[j];
                sort(rem.begin(),rem.end());
                auto itt = upper_bound(rem.begin(),rem.end(),ss[j]);
                if(itt!=rem.end())
                {
                    string res = ss.substr(0,j);
                    res+=*itt;
                    rem.erase(itt);
                    res+=rem;
                    return res;                    
                }
            }
        }
        return "";
    }
};