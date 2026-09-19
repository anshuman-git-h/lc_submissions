class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if(x1 <= xc && xc <= x2)//within left and right
        {
            if(y1 <= yc && yc <= y2)return 1;//withing top and bottom
            else //outside top and bottom
            {
                
                int d = min(abs(yc - y1),abs(y2 - yc));
                if(d <= r)return 1;
                //cout<<"y"<<endl;
                return 0;
            }
        }
        else
        {
            int x = min(abs(x1 - xc), abs(x2 - xc));
            if(y1 <= yc && yc <= y2)return x <= r;
            int y = min(abs(y1 - yc),abs(y2 - yc));
            return x*x + y*y <= r*r;
        }
    }
};