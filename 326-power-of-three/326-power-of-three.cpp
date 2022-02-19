class Solution {
public:
    
    bool solve(int n, int rem) {
        if(n == 0 || rem != 0) {
            return false;
        } else if(n == 1) {
            return true;
        } else {
            return solve(n/3, n%3);
        }
    }
    
    bool isPowerOfThree(int n) {
        return solve(n, 0);
    }
};