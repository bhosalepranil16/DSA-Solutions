class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, cnt = 0, n = nums.size();
        
        for(int i=1;i<n-1;i++) {
            if(nums[i] - nums[i-1] == nums[i+1] - nums[i]) {
                cnt++;
            } else {
                res += (cnt * (cnt + 1) / 2);
                cnt = 0;
            }
        }
        res += (cnt * (cnt + 1) / 2);
        return res;
    }
};