class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int res = 0;
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(true) {
            int n = pq.size();
            if(n == 0) {
                return 0;
            } else if(n == 1) {
                return pq.top();
            } else {
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                
                if(a > b) {
                    pq.push(a - b);
                } 
            }
        }
        return 0;
    }
};