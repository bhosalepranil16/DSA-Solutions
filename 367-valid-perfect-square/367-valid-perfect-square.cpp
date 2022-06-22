class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long low = 1, high = num, ans = -1;
        
        while(low <= high) {
            
            long long mid = (low + high) / 2;
            long long mSq = mid * mid;
            
            if(mSq == num) {
                ans = mid;
                break;
            } else if(mSq > num) {
                high = mid - 1;
            } else {
                low = mid + 1;
                ans = mid;
            }
        }
        
        return (ans * ans) == num;
        
    }
};