class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int midElement;
        
        if(n % 2 == 1) {
            midElement = nums[n/2];
        } else {
            int sum = nums[n/2] + nums[n/2 - 1];
            midElement = sum / 2;
        }
        
        int res = 0;
        
        for(int i=0;i<n;i++) {
            res += abs(nums[i] - midElement);
        }
        
        return res;
        
    }
};