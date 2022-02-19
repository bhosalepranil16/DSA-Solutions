class Solution {
public:
    bool isPowerOfFour(int n) {
        return solve(n, 0);
    }
    bool solve(int n, int rem) {
        if(n == 0 || rem != 0) {
            return false;
        } else if(n == 1) {
            return true;
        } else {
            return solve(n/4, n%4);
        }
    }
};