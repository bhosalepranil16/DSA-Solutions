class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int> > g;
    
    MedianFinder() {
            
    }
    
    void addNum(int num) {
        
        if(s.size() == 0) {
            s.push(num);
            return;
        }
        
        if(s.size() > g.size()) {
            if(s.top() > num) {
                g.push(s.top());
                s.pop();
                s.push(num);
            } else {
                g.push(num);
            } 
        } else {
            if(num <= s.top()) {
                s.push(num);
            } else {
                g.push(num);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    double findMedian() {
        double res;
        if(s.size() > g.size()) {
            res = (double) s.top();
        } else {
            double a = (double) s.top(), b = (double) g.top();
            res = (a + b) / 2;
        }
        return res;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */