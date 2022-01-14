class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        s.insert(n);
        while(true) {
            int res = 0;
            while(n > 0) {
                int rem = n % 10;
                res += rem * rem;
                n = n / 10;
            }
            if(res == 1) {
                return true;
            }
            if(s.find(res) != s.end()) {
                return false;
            }
            s.insert(res);
            n = res;
        }
        return false;
    }
};