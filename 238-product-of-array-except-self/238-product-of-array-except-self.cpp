class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> fromBegin(n), fromLast(n), res(n);
        
        fromBegin[0] = 1;
        fromLast[0] = 1;
        
        for(int i=1;i<n;i++) {
            fromBegin[i] = fromBegin[i-1] * nums[i-1];
            fromLast[i] = fromLast[i-1] * nums[n-i];
        }
        
        for(int i=0;i<n;i++) {
            res[i] = fromBegin[i] * fromLast[n-i-1];
        }
        
        return res;
        
    }
};