class Solution {
public:
    int fun(vector<vector<int>>& img1, vector<vector<int>>& img2)
    {
        int n = img1.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(img1[i][j] && img2[i][j])ans++;
            }
        }
        return ans;
    }
    void fun1(vector<vector<int>> &a)
    {
        int n = a.size();
        

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)a[i][j] = 0;
        }
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int m = 0;
        vector<vector<int>> im(n,vector<int> (n,0));
        for(int x = -n+1;x<n;x++)
        {
            for(int y = -n+1;y<n;y++)
            {
                for(int i = 0;i<n;i++)
                {
                    for(int j = 0;j<n;j++)
                    {
                        int nx = i+x;
                        int ny = j+y;
                        if(nx>=0&&nx<n&&ny>=0&&ny<n && img1[i][j]) //move by x and y each of the one bits
                        {
                            im[nx][ny] = 1;
                        }
                    }
                }
                m = max(m,fun(im, img2));
                fun1(im);
            }
        }
        return m;
    }
};