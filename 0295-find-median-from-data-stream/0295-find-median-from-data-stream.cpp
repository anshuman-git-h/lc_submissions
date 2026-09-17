class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int,vector<int>,greater<int>>minH;
    int mns;
    int mxs;
    MedianFinder() {
        mns = 0;
        mxs = 0;
    }
    
    void addNum(int num) {
       
        if(mns < mxs)
        {
            minH.push(num);
        }
        else
        {
            maxH.push(num);
        }

        if(!minH.empty() && !maxH.empty() && minH.top() < maxH.top())
        {
            int l = minH.top();
            int r = maxH.top();
            minH.pop();
            maxH.pop();
            minH.push(r);
            maxH.push(l);
        }
        mxs = maxH.size();
        mns = minH.size();
    }
    
    double findMedian() {
        if(mns > mxs)
        {
            return (double)minH.top();
        }
        else if(mns<mxs)
        {
            return (double)maxH.top();
        }
        else if(mns == 0)return 0.0;
        else
        {
            int l = minH.top();
            int r = maxH.top();
            return (double)(l+r)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */