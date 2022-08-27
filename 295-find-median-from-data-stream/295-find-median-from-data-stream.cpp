class MedianFinder {
public:
   priority_queue<int> minh;
    priority_queue<int, vector<int> , greater<int>> maxh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(minh.size() > maxh.size())
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size() == maxh.size()) return (double)(minh.top() + maxh.top())/2;
        return (double)maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */