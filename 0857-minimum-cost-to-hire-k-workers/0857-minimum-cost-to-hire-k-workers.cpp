class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        vector<double> pre(n,0);
        vector<vector<double>> v(n);


        for(int i = 0;i<n;i++)
        {
            v[i] = {(double)quality[i]/wage[i],(double)quality[i],(double)wage[i]};
        }

        sort(v.begin(),v.end(),[&](vector<double> &a, vector<double> &b){
            return a[0]<b[0];
        });

        for(int i = 0;i<n;i++)
        {
            pre[i] = v[i][1];
            if(i)pre[i]+=pre[i-1];
            //cout<<pre[i]<<" ";
        }
        //double ans = INT_MAX;
        priority_queue<double> pq;
        double sm = 0;
        for(int i = n - k;i<n;i++){
            pq.push(v[i][1]);
            sm+=v[i][1];
        }
        double ans = 1000000000000;
        ans = min(ans, sm/v[n-k][1]*v[n-k][2]);
        for(int i = n-k-1;i>=0;i--)
        {
            pq.push(v[i][1]);
            
            sm+=v[i][1] - 
            pq.top();
            pq.pop();
            ans = min(ans, sm/v[i][1]*v[i][2]);
        }
        return ans;
    }
};