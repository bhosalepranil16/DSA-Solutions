class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque<int> que {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        while(--n > 0) {
            int sz = que.size();
            for(int i=0;i<sz;i++) {
                int p = que.front();
                que.pop_front();
                for(int j=0;j<10;j++) {
                    if(abs((p%10) - j) == k) {
                        que.push_back(p*10+j);
                    }
                }
            }
        }
        return vector<int> {que.begin(), que.end()};
    }
};